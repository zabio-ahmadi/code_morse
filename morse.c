#include "morse.h"


tree tree_create(){
    return NULL; 
}


bool is_empty(tree t){

    return t == NULL; 
}


void print_tree(tree t, int n){

    if (NULL != t) {
        print_tree(t->right, n+1); 
        for (int i = 0; i < n; i++) { 
            printf("\t"); 
        } 
        printf("%c\n", t->data); 
        print_tree(t->left, n+1); 
    }

}







int count_file_line(char *path){
    int line_number = 0; 
    FILE *file = fopen(path, "r"); 

    char ch; 
    ch = fgetc(file);
    while(ch != EOF){
        ch = fgetc(file);
        if(ch == '\n'){
            line_number++;
        }
    }
    fclose(file); 
    return line_number; 
}






tree create_node(type letter){

        tree new_node = malloc(sizeof(node));
        new_node->data = letter; 
        new_node->left = NULL; 
        new_node->right = NULL; 
        return new_node; 
}

tree tree_insert(tree t,int start, int end, char *path){

    if(is_empty(t)){
         
        t = create_node('?');

    } 


    if(start  <= end){

        if(path[start] == '.'){
            
    
            if(is_empty(t->left)){

                tree new_node = create_node('?');
                t->left = new_node;
            }
            tree_insert(t->left, ++start, end, path);
            
        }
        else if (path[start] == '-'){

            if(is_empty(t->right)){
                tree new_node = create_node('?');
                t->right = new_node;
            }
            tree_insert(t->right, ++start, end, path);
        }
    }
    else {

        
        t->data = path[0];
        // printf("data : %c\n", t->data);
    }



    return t;
}



int count(char *str){

    int i = 0; 
    int count = 0; 

    while(str[i] != '\n'){
        count++;
        i++;
    }

    return --count;

}


tree create_morse_tree(tree tr, char *path, int size){


    int line_number = count_file_line(path); 

    FILE *file = fopen(path, "r");
    char buffer[size];

    
    for (int i = 0; i <= line_number; i++){
        
        fgets(buffer, size, file); 
        int start = 1; 
        int end = count(buffer) - 1; 
        tr = tree_insert(tr,start, end, buffer);
    
    }
    fclose(file); 

    return tr; 
}


void write_to_file(char *path, char message){

    FILE *file = fopen(path, "a"); 

    fprintf(file, "%c",message); 

    fclose(file); 
}




void decode(tree tr, char *encoded_message_path, char *decoded_message_path){

    FILE *src_file = fopen(encoded_message_path, "r");
    
    // remove existing file 
    remove(decoded_message_path);
    char ch; 
    tree root = tr; 
    tree tmp = tr; 



    while( (ch = fgetc(src_file)) != EOF){
        
        if(ch != 32 && ch != '/'){

            if(!is_empty(tmp)){
                if(ch == '.'){
                    tmp = tmp->left;
                }

                else if(ch == '-'){
                    tmp = tmp->right;
                }
            }
        }

        if(ch == 32){

            if(!is_empty(tmp) && tmp->data != '?'){
                write_to_file(decoded_message_path, tmp->data);
            }
            tmp = root; // return to the root

        } 

        if( ch == '/'){
            write_to_file(decoded_message_path, ' ');
        }

       

        

    } 


    fclose(src_file);


}



void print_file_to_console(char *path){
    
    FILE *src_file = fopen(path, "r");
    char ch; 

    while((ch = fgetc(src_file)) != EOF){
        printf("%c", ch);
    }
    
    fclose(src_file);
}

void free_tree(tree t){

     if(!is_empty(t)){

        if(!is_empty(t->left)){

            free_tree(t->left); 
        }
        if(!is_empty(t->right)){

            free_tree(t->right); 
        }

        free(t); 
        t = NULL; 
    }
}

