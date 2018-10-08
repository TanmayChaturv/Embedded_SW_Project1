/*** Code developed by Tanmay Chaturvedi and Smitha Bhaskar for ECEN5813- Principles of Embedded Software, University of Colorado Boulder
     Dated:10/07/2018
     The code describes lookup table usef for mapping the opcodes to their rfunction calls.
     Reference for implementing lookup table : https://stackoverflow.com/questions/30364984/c-lookup-string-by-value 
     It was taken as a reference template code and was improvised to implement a lookup table with function pointers and call by value 
     bsearch() is the functionality we have implemented to search the lookup table for the user specified op-code.

***/

int comp_id_string( const void* key, const void* element);
const char * get_func(char x);
void test_func(char x);
