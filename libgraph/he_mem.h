#ifndef __HE_MEM_H__
#define __HE_MEM_H__


#include "xcl.h"

#define ATTR_HOST_ONLY              (0)
#define ATTR_PL_DEFAULT             (1)
#define ATTR_PL_DDR0                (2)
#define ATTR_PL_DDR1                (3)
#define ATTR_PL_DDR2                (4)
#define ATTR_PL_DDR3                (5)
#define ATTR_ERROR                  (6)

#define SIZE_IN_EDGE                (0)
#define SIZE_IN_VERTEX              (1)
#define SIZE_USER_DEFINE            (2)



typedef struct
{
    const unsigned int  size_attr;
    unsigned int        scale;

} size_attr_ctrl_t;



#define clSVMAlloc(context,flag,size,alignment)  memalign(alignment,size)


typedef struct
{
    unsigned int        id;
    const char          *name;
    unsigned int        attr;
    unsigned int        unit_size;
    unsigned int        size_attr;

    unsigned int        size;
    void                *data;
    cl_mem              device;
    cl_mem_ext_ptr_t    ext_attr;
} he_mem_t;

typedef struct 
{
    unsigned int    id;
    he_mem_t        *p_mem;   
} he_mem_lookup_t;


int register_size_attribute(unsigned int attr_id,int value);

unsigned int get_size_attribute(unsigned int attr_id);

int he_mem_init(cl_context &dev_context, he_mem_t * item);

cl_mem* get_cl_mem_pointer(int id);

void* get_host_mem_pointer(int id);

he_mem_t* get_he_mem(unsigned int id);

void clear_host_mem(int id);

void hardware_init(const char * name);

int transfer_data_from_pl(cl_context &dev_context, cl_device_id device_id, int mem_id);

int transfer_data_to_pl(cl_context &dev_context, cl_device_id device_id, int* id_array, int size);



#endif /* __HE_MEM_H__ */
