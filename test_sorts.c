#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "sorts.h"
#include "miniunit.h"
#include "clog.h"

int _test_no_digit_bst(){
	mu_start();
	//----------
	int* input = NULL;
	int size = 0;
	tree_sort_array(input, size);
	mu_check(input == NULL);
	//----------
	mu_end();
}

int _test_single_digit_bst(){
	mu_start();
	//----------
	int input[1] = {5};
	int size = 1;
	tree_sort_array(input, size);
	mu_check(input[0] == 5);
	//----------
	mu_end();
}
int _test_two_digits_bst(){
	mu_start();
	//----------
	int input[2] = {4, 2};
	int size = 2;
	tree_sort_array(input, size);
	mu_check((input[0] == 2) && (input[1] == 4));
	//----------
	mu_end();
}

int _test_three_digits_bst(){
	mu_start();
	//----------
	int input[3] = {4, 2,7};
	int size = 3;
	tree_sort_array(input, size);
	mu_check((input[0] == 2) && (input[1] == 4) && (input[2] == 7));
	//----------
	mu_end();
}

int _test_five_digits_bst(){
	mu_start();
	//----------
	int input[5] = {4,2,3,5,7};
	int size = 5;
	tree_sort_array(input, size);
	mu_check((input[0] == 2) && (input[1] == 3) && (input[2] == 4) && (input[3] == 5)&& (input[4] == 7));
	//----------
	mu_end();
}

int main(int argc, char* argv[]) {
	mu_run(_test_no_digit_bst);
	mu_run(_test_single_digit_bst);
	mu_run(_test_two_digits_bst);
	mu_run(_test_three_digits_bst);
	mu_run(_test_five_digits_bst);
	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
