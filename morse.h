#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#ifndef _MORSE_

#define _MORSE_

typedef struct _node {

    struct _node * left; 
    struct _node * right; 
    char data; 

} node; 

typedef char type; 
typedef node * tree; 

tree tree_create(); 

tree create_node(type letter);

bool is_empty(tree t); 

void print_tree(tree t, int n); 

// counts total lines of a file 
int count_file_line(char *path); 

// count index of end of the line 
int count(char *str);

tree tree_insert(tree t,int start, int end, char *path);


tree create_morse_tree(tree tr, char *path, int size);


void decode(tree tr, char *encoded_message_path, char *decoded_message_path);

//writes to file 
void write_to_file(char *path, char message);

void print_file_to_console(char *path);
void free_tree(tree t); 
#endif