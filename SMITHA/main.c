#include<stdio.h>
#include<stdlib.h>
//#include"main.h"
#include"help.h"
#include"headers.h"

struct function_map {
    int opcode;
    char const* str;
};

<<<<<<< HEAD
=======
struct funcinvoke func[]={ /*** Arrange all in ascending order ***/
{'H' , help},
{'A' , allocate},
{'W' , write_memory},
{'F' , free_memory},
{'D' , display_memory},
{'I' , invertbits},
{'P' , write_pattern},
{'V' , verify_pattern}
};
>>>>>>> dcb039673a5b1737bbc8c8d642aa7dad658a0f8f

int comp_id_string( const void* key, const void* element)
{
    int key_id     = ((struct function_map*) key)->opcode;
    int element_id = ((struct function_map*) element)->opcode;

    if (key_id < element_id) return -1;
    if (key_id > element_id) return  1;
    return 0;
}

static struct function_map func[] = {
    {'A', allocate} ,
    {'D', display_memory},
    {'F', free_memory},
    {'H', help},
    {'I' , invertbits},
    {'P' , write_pattern},
    {'V' , verify_pattern},
    {'W' , write_memory}
    
     };

<<<<<<< HEAD
#define ELEMENTS_OF(x) (sizeof(x) / sizeof((x)[0]))
=======
f=(char *) bsearch(&entry,func,sizeof(struct funcinvoke func[]),sizeof(char),func_comp);
struct funcinvoke a={entry,f}; /*** Try to run and see if its calling a function ***/
>>>>>>> dcb039673a5b1737bbc8c8d642aa7dad658a0f8f

char const* get_func(int x)
{
    struct function_map key = {x};
    struct function_map* fs = bsearch(&key, func , ELEMENTS_OF(func), sizeof(func[0]), comp_id_string);

    if (!fs) return "invalid opcode";

    return fs->str;
}

void test_func(char x)
{
    get_func(x);
}


