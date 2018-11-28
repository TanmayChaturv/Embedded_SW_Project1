#include <stdio.h>
#include <stdlib.h>
#include <time.h> //For the pseudo random number generator
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/CUnit.h>
#include "../inc/circ_buf.h"

circbuf_t *ptr ,*new_ptr;
uint8_t value;
int new_value;
int add_test_suite();
int cu_init_func();
int cu_clean_func();
void circbuff_init_test();
void circbuff_insert_test();
void circbuff_remove_test();

int main()
{
	//uint8_t rand_seed = srand(time(0));
	srand(time(0));

	value=(rand()%250)+1;
//	printf("\n\r Rand=%d", value);
	new_value=value+10; //For realloc()
	if( CU_initialize_registry() == CUE_NOMEMORY )
	return CU_get_error();

	if( add_test_suite() == 0 )
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode( CU_BRM_VERBOSE );
	CU_basic_run_tests();

	//CU_set_output_filename("testfile");
	CU_automated_run_tests();

	CU_cleanup_registry();
	return CU_get_error();
}

int add_test_suite(void)
{
	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite( "Unit testing Implementation", cu_init_func, cu_clean_func );

	if( pSuite == NULL )
	{
		return 0;
	}

	if( ( CU_add_test(pSuite, "Circular Buffer Init Test", circbuff_init_test) == NULL ) ||
	( CU_add_test(pSuite, "Circular Buffer Element Insert Test", circbuff_insert_test ) == NULL ) ||
	( CU_add_test(pSuite, "Circular Buffer Element Remove Test", circbuff_remove_test ) == NULL ))
	{
		return 0;
	}
	return 1;
}

int cu_init_func(void)
{
	
	ptr = (circbuf_t *)malloc(abs(sizeof(circbuf_t)));
//	printf("\n\r ptr is %p",ptr);
	return 0;
}

int cu_clean_func(void)
{
	free(ptr);
	return 0;
}


void circbuff_init_test(void)
{	
	/*Checking if pointer not null*/
	CU_ASSERT_PTR_NOT_NULL(ptr);	
	/*Checking if circbuf init not working with buf len = 0*/
	//CU_ASSERT_NOT_EQUAL(buff_init(ptr,0),2);
	
	//for(int i=0;i<value;i++){	

	/*Checking if circbuf init working*/
//	printf(" Value mow is:%d", value);
	CU_ASSERT_EQUAL(buff_init(ptr,value),2);
	
	/*Checking if circbuf init not working with buf len = -1*/
	//CU_ASSERT_EQUAL(buff_init(ptr,(i-254)),3);
	//}
}


void circbuff_insert_test(void)
{
		/*Checking if circbuf element insert working with element's min value, ie 0
		CU_ASSERT_EQUAL(buff_insert(ptr,0),4);
		Checking if circbuf element insert working with element's max value, ie 255*/
		//CU_ASSERT_EQUAL(buff_insert(ptr,255),4);

		for(int i=0;i<value;i++){
		/*Checking if circbuf element insert working*/
		CU_ASSERT_EQUAL(buff_insert(ptr,i),4);
		
		/*Checking if circbuf element insert working with non-zero element value, ie -100*/
        	//CU_ASSERT_EQUAL(buff_insert(ptr,i-255),4);
		}
//		printf("\nNumber of Elements in the Circ Buffer is %d",ptr->counter);

		/*Checking if circbuf element insert NOT working for more than 4 elements*/
       	 	CU_ASSERT_EQUAL(buff_insert(ptr,255),5);
        	CU_ASSERT_EQUAL(buff_insert(ptr,255),5);
	
		/*Realloc to a new buff length size*/
		
		//ptr = (circbuf_t *)realloc(ptr,sizeof(circbuf_t)*new_value); //Allocated to a new size
		
		/*Checking if circbuf element insert working with element's min value, ie 0*/
		//CU_ASSERT_EQUAL(buff_insert(new_ptr,0),4);
		//*Checking if circbuf element insert working with element's max value, ie 255*/
//		CU_ASSERT_EQUAL(buff_insert(new_ptr,255),4);

		///*for(int i=0;i<11;i++){
		///*Checking if circbuf element insert working
		//CU_ASSERT_EQUAL(buff_insert(ptr,i),4);
		
		///*Checking if circbuf element insert working with non-zero element value, ie -100*/
        	////CU_ASSERT_EQUAL(buff_insert(new_ptr,i-255),4);
		//

}

void circbuff_remove_test(void)
{
	for(int i=0;i<value;i++){
	CU_ASSERT_EQUAL(buff_remove(ptr),6);
	//CU_ASSERT_EQUAL(buff_remove(ptr),6);
	//CU_ASSERT_EQUAL(buff_remove(ptr),6);
      //  CU_ASSERT_EQUAL(buff_remove(ptr),6);
	}
	/*Checking if circbuf element remove NOT working for more than 4 elements*/
	CU_ASSERT_EQUAL(buff_remove(ptr),7);

}
