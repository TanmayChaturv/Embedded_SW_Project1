/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes lookup table usef for mapping the opcodes to their rfunction calls.
     Reference for implementing lookup table : https://stackoverflow.com/questions/30364984/c-lookup-string-by-value 
     It was taken as a reference template code and was improvised to implement a lookup table with function pointers and call by value 
     bsearch() is the functionality we have implemented to search the lookup table for the user specified op-code.

***/

//HEADER FILES

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"../INC/headers.h"
#include"../INC/main.h"


//FUNCTION PROTOTYPES
int comp_id_string( const void* key, const void* element);
const char * get_func(char x);
void test_func(char x);


typedef void (*handler_t)(void);

struct function_map {
    char opcode;
    handler_t str;
};


//LOOKUP TABLE IMPLEMENTED THROUGH STRUCTURES

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

//FUNCTION TO COMPARE THE USER SPECIFIED OPCODE AND THE OPCODES IN THE LOOKUP TABLE
int comp_id_string( const void* key, const void* element)
{
    char key_id     = ((struct function_map*) key)->opcode;
    char element_id = ((struct function_map*) element)->opcode;

    if (key_id < element_id) return -1;
    if (key_id > element_id) return  1;
    return 0;
}

//bsearch() IMPLEMENTATION
const char * get_func(char x)
{
    
    struct function_map key = {x, NULL};

     
    struct function_map  *fs = bsearch(&key, func , 9, sizeof(func[0]), comp_id_string);
    
    if (!fs) printf( "invalid opcode \n");
     

    return fs->str;
}

//FUNCTION TO TEST THE USER INPUT
void test_func(char x)
{
 
 handler_t func_ptr = get_func(x);
 func_ptr();

}

int main(){

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
