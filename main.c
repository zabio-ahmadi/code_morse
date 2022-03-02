#include "morse.h"
#define MAX_SIZE 10










int main(){


    char *path = "code-morse.txt"; 
    tree _tree = tree_create(); 

    _tree = create_morse_tree(_tree, path, MAX_SIZE); 

    printf("========================================================\n");
    printf("TREE:\n");
    print_tree(_tree, 0);
    printf("========================================================\n");



    char *encoded_message_path = "texte.morse.txt"; 
    char *decoded_message_path = "decode.txt";
    decode(_tree, encoded_message_path, decoded_message_path);
    
    
    printf("\n========================================================\n");
    printf("MESSAGE:\n");
    printf("========================================================\n");
    
    print_file_to_console(decoded_message_path);
    printf("\n");
    printf("========================================================\n");


    free_tree(_tree);

    
}