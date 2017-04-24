#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include<stdio.h>
#include<termios.h>
#include<sys/types.h>
#include<sys/time.h>
#include<stdlib.h>
#include<unistd.h> 
#include<time.h>
#include<string.h>

#include "grill.h"
#include "fichier.h"

void test_creat(){
    CU_ASSERT( creat(5).size == 5);
    CU_ASSERT( creat(0).size == 0);
    CU_ASSERT( creat(5).now_color == ' ');
}

void test_init(){
  colorgrill g = creat(5);
  init(&g);
  CU_ASSERT(g.now_color != ' ');
}

void test_change_color(){
  colorgrill g = creat(5);
  get_grill("text.txt", &g);
  change_color( &g, 'V', 2, 2);
  CU_ASSERT(g.grill[1][1]=='V');
  change_color( &g, 'R', 2, 2);
  CU_ASSERT(g.grill[1][1]=='R');
}

void test_change(){
  colorgrill g = creat(5);
  get_grill("grill1.txt", &g);
  change(&g, 'B', 1, 1);
  CU_ASSERT(g.grill[0][0]=='B');
  CU_ASSERT(g.grill[3][3]=='B');
}


int main() {
	CU_pSuite pSuite = NULL;
	
	if (CU_initialize_registry() != CUE_SUCCESS) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Suite",NULL,NULL);

	if (pSuite==NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

    if (CU_add_test (pSuite, "test of creat()",test_creat)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test (pSuite, "test of init()",test_init)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test (pSuite, "test of change_color()",test_change_color)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test (pSuite, "test of change()",test_change)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
	return 0;
}


