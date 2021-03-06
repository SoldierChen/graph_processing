#ifndef __FPGA_FILTER_H__
#define __FPGA_FILTER_H__

#include "graph_fpga.h"


void filterFunction(
    filter_type                 &filter,
    uint_raw                    &filter_num,
    hls::stream<filter_type>    &toFilterItem,
    hls::stream<int2>           &buildArray
)
{
#pragma HLS function_instantiate variable=filter_num

    uint_raw filter_end;
    while (true) {
#pragma HLS PIPELINE II=1
#pragma HLS dependence variable=filter inter false
#pragma HLS dependence variable=buildArray inter false
#pragma HLS dependence variable=filter_end inter false

        read_from_stream(toFilterItem, filter);
        filter_end = filter.end;
        filter_num = filter.num;


        for (int j = 0; j < filter_num; j ++) {
#pragma HLS PIPELINE II=1 rewind
            /*
            if (j >=  filter_num)
            {
                continue;
            }
            else
            */
            {
                write_to_stream(buildArray, filter.data[j]);
            }
        }
        if (filter_end)
        {
            break;
        }

    }
    clear_stream(toFilterItem);
    return;
}


#endif /* __FPGA_FILTER_H__ */

