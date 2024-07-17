/*
    This is a program that takes an already existing, non-empty file and copies its contents to another file that has already been created. 
*/

#include <stdio.h>  //for inputs and outputs
#include <stdlib.h> //for exit() 
#include <errno.h> //for displaying error numbers 

int main(){
    //Declaring Varriables
    FILE *fileptr1, *fileptr2; //both pointers that point to the: 1- file with contents, 2- file being copied to
    char filename[100]; //this will hold the first filename then be rewritten to hold the second filename
    char c; //temp varraible that will be used to copy the contents of the file 

    //Getting the filename from the user
    printf("Enter the original file name: "); 
    scanf("%s", filename); 

    //Opening the first file, throwing error if it cannot be opened
    fileptr1 = fopen(filename, "r"); 
    if(fileptr1 == NULL){
        printf("Cannot open file %s", filename); 
        exit(1); 
    }
    else{
        printf("File %s has been opened \n", filename); 
    }

    //Getting the destination file name
    printf("Enter the destination file name: "); 
    scanf("%s", filename); 

    //Opening destination file, checking if it opens correctly
    fileptr2 = fopen(filename, "w"); 
    if(fileptr2 == NULL){
        printf("Cannot open file %s", filename); 
        exit(1); 
    }
    else{
        printf("File %s has been opened \n", filename);
    }


    //copying the contents of the first file to the destination file, giving an error number if an error occurs 
    while((c = fgetc(fileptr1)) != EOF){
        if(fputc(c, fileptr2) == EOF){
            printf("Failed to copy!\n");
            printf("Errno Value: %d \n", errno);  
            exit(1); 
        } 
    }

    //If we get here, then copy was successful
    printf("File was copied successfully!\n");  

    //closeing files
    fclose(fileptr1); 
    fclose(fileptr2); 

    return 0; 

}