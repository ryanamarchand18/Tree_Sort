#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "sorts.h"

void _insert(int value, BSTNode** a_root){
	if(*a_root == NULL){
		BSTNode* new_node = malloc(sizeof(*new_node));
		*new_node = (BSTNode) { .value = value, .left = NULL, .right = NULL};
		*a_root = new_node;
	}	
	else if(value < (*a_root) -> value){
		_insert(value, &((*a_root) -> left));
	}
	else{
		_insert(value, &((*a_root) -> right));
	}
}

void _destroy(BSTNode* root){
	if(root != NULL){
		if((root -> left) != NULL){
			_destroy(root -> left);
		}
		if((root -> right) != NULL){
			_destroy(root -> right);
		}
			free(root);
	}
}

int _fill_array_from_bst(BSTNode* root, int* array, int i){
	if(root != NULL){
		i = _fill_array_from_bst(root -> left, array, i);
		array[i] = (root -> value);
		i++;
		i = _fill_array_from_bst(root -> right, array, i);
	}
	return i;
}

BST create_bst(const int* array, int size) {
	BST new_bst = {.size = size, .root = NULL};
	for(int i = 0; i < size; i++) {	
		_insert(array[i], &new_bst.root);
	}
	return new_bst; 
}


void empty_bst(BST* bst) {
	_destroy(bst -> root);
}


void tree_sort_array(int* array, size_t size){
	BST new_bst = create_bst(array, size);
	_fill_array_from_bst(new_bst.root, array, 0);
	empty_bst(&new_bst);
}
