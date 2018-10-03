#include<stdint.h>

volatile /*extern*/ uint32_t *st_addr; //Base address
/*extern*/ uint32_t st_index; // gives index of first allocated memory location,should be always 1
/*extern*/ uint32_t n_bits; // number of 32bits memory locations
volatile /*extern*/ uint32_t *en_addr; //end address
/*extern*/ uint32_t en_index; // gives index of last allocated memory location
volatile /*extern*/ uint32_t user_index; // used to store information of where user-input value is stored
//extern uint64_t output_write //
