#ifndef __GRAPH_FPGA_H__
#define __GRAPH_FPGA_H__

#define AP_INT_MAX_W 4096
#include <ap_int.h>

#include "config.h"

#define DATA_WIDTH              (512)
#define INT_WIDTH               (32)
#define INT_WIDTH_SHIFT         (5)

#define SIZE_BY_INT             (DATA_WIDTH/INT_WIDTH)
#define LOG2_SIZE_BY_INT        (4)                         //change manual
#define SIZE_BY_INT_MASK        (SIZE_BY_INT - 1)

#define BURST_READ_SIZE         (4)
#define LOG2_BURST_READ_SIZE    (2)                         //change manual


#define BURST_BUFFER_SIZE       (SIZE_BY_INT)
#define BURST_BUFFER_MASK       (BURST_BUFFER_SIZE  - 1)

#define BURST_ALL_BITS          (DATA_WIDTH)


typedef ap_uint<8>                 ushort_raw;


typedef ap_uint<32>                 uint_raw;

typedef ap_uint<DATA_WIDTH>         uint16;

typedef ap_uint<128>                uint4_raw;

typedef ap_uint<BURST_ALL_BITS>     burst_raw;

typedef ap_uint<64>                 uint_uram;

#define BITMAP_SLICE_SIZE           (16)
#define BITMAP_SLICE_SHIFT          (4)


#define EDGE_MAX        (2*1024*1024)//5610680////163840 // (1024*1024)
#define BRAM_BANK       16
#define LOG2_BRAM_BANK  4
#define PAD_TYPE        int16
#define PAD_WITH        16



#define uchar unsigned char


typedef struct __int2__
{
    int x;
    int y;
} int2;



typedef struct __int4__
{
    int s0;
    int s1;
    int s2;
    int s3;
} int4;


typedef struct EdgeInfo {
    int2 data[EDGE_NUM];
} edge_tuples_t;

typedef struct shuffledData {
    uint_raw num;
    uint_raw idx;
} shuffled_type;

typedef struct filterData {
    bool end;
    uchar num;
    int2 data[EDGE_NUM];
} filter_type;

typedef struct processinfo {
    uint_raw outDeg;
    uint_raw data;
} process_type;



//#define SW_DEBUG

#ifdef SW_DEBUG

#include "stdio.h"

#define DEBUG_PRINTF(fmt,...)   printf(fmt,##__VA_ARGS__); fflush(stdout);

#else

#define DEBUG_PRINTF(fmt,...)   ;

#endif




#ifdef CACHE_DEBUG

#include "stdio.h"

#define C_PRINTF(fmt,...)   printf(fmt,##__VA_ARGS__); fflush(stdout);

#else

#define C_PRINTF(fmt,...)   ;

#endif



#define CLEAR_CYCLE (256)


template <typename T>
inline int clear_stream (hls::stream<T> &stream)
{
#pragma HLS INLINE
    int end_counter = 0;
clear_stream: while (true)
    {
        T clear_data;

        if ( read_from_stream_nb(stream, clear_data) == 0)
        {
            end_counter ++;
        }
        if (end_counter > CLEAR_CYCLE)
        {
            break;
        }
    }
    return 0;
}



template <typename T>
inline int empty_stream (hls::stream<T> &stream)
{
#pragma HLS INLINE
    int end_counter = 0;
empty_stream: while (true)
    {
        T clear_data;

        if ( read_from_stream_nb(stream, clear_data) == 0)
        {
            end_counter ++;
        }
        else
        {
            end_counter = 0;
        }
        if (end_counter > 4096)
        {
            break;
        }
    }
    return 0;
}



template <typename T>
inline int write_to_stream (hls::stream<T> &stream, T const& value)
{
#pragma HLS INLINE
    int count = 0;
    stream << value;
    return 0;
}


template <typename T>
inline int read_from_stream (hls::stream<T> &stream, T & value)
{
#pragma HLS INLINE
    value = stream.read();
    return 0;
#if 0
    if (stream.read_nb(value))
    {
        return 0;
    }
    else
    {
        return -1;
    }
#endif
}


template <typename T>
inline int read_from_stream_nb (hls::stream<T> &stream, T & value)
{
#pragma HLS INLINE
    if (stream.empty())
    {
        return 0;
    }
    else
    {
        value = stream.read();
        return 1;
    }
}




#endif /* __GRAPH_FPGA_H__ */
