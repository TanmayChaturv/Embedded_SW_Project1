

/** Reference for implementing lookup table : https://stackoverflow.com/questions/30364984/c-lookup-string-by-value **/
/** It was taken as a reference template code and was improvised to implement a lookup table with function pointers and call by value **/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/headers.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/main.h"


int comp_id_string( const void* key, const void* element);
const char * get_func(char x);
void test_func(char x);


typedef void (*handler_t)(void);

struct function_map {
    char opcode;
    handler_t str;
};



static struct function_map func[9] = {
     {'A' , allocate},
     {'D' , display_memory},
     {'E' , exit},
     {'F' , free_memory},
     {'H' , help},
     {'I' , invertbits},
     {'P' , write_pattern},
     {'V' , verify_pattern},
     {'W' , write_memory}

     };

int comp_id_string( const void* key, const void* element)
{
    char key_id     = ((struct function_map*) key)->opcode;
    char element_id = ((struct function_map*) element)->opcode;

    if (key_id < element_id) return -1;
    if (key_id > element_id) return  1;
    return 0;
}

const char * get_func(char x)
{
    
    struct function_map key = {x, NULL};

     
    struct function_map  *fs = bsearch(&key, func , 9, sizeof(func[0]), comp_id_string);
    
    if (!fs) printf( "invalid opcode \n");
     

    return fs->str;
}

void test_func(char x)
{
 
 handler_t func_ptr = get_func(x);
 func_ptr();

}

void main(){
char user1, user2;
 printf("Enter 'H' for the list of available commands.\n");
 printf(">>");

do{
 scanf("%c",&user1);
 test_func(user1);
 printf("Enter the next opcode you wish to execute:\n");
 printf("\n>>");
 scanf("%c",&user2);
}while ((user2) != 'E'); 

printf("Exit!");
}
