#include<stdio.h>
#include<stdlib.h>
#include"/home/smitha/PES_Project1/main.h"
#include"/home/smitha/PES_Project1/help.h"

char  func_comp(const void *a, const void *b);

struct funcinvoke {
char opcode;
void (*func) ();
};

struct funcinvoke func[]={
{'H' , help},
{'A' , allocate},
{'W' , write_memory},
{'F' , free_memory},
{'D' , display_memory},
{'I' , invertbits},
{'P' , write_pattern},
{'V' , verify_pattern}
};

//struct funcinvoke *fi =bsearch(func,6,sizeof(struct), func_compare);

char  func_comp(const void *a , const void *b){
const struct funcinvoke *p1=a , *p2=b ;
return ((p1->opcode)-(p2->opcode));
};

int main() {
char   entry;
char *f;
printf("Enter the opcode to invoke the appropriate function");
scanf("%c",&entry);

f=(char *) bsearch(&entry,func,6,sizeof(char),func_comp);
struct funcinvoke a={entry,f};

return 0;



}


