/*Global variables used in various memory allocation functions*/

#include<stdint.h>

uint32_t *st_addr; //Base address
uint32_t st_index; // gives index of first allocated memory location,should be always 1
uint32_t n_bits; // number of 32bits memory locations
uint32_t *en_addr; //end address
uint32_t en_index; // gives index of last allocated memory location
uint32_t user_index; // used to store information of where user-input value is stored
uint32_t output_write; //
uint32_t output_write;
