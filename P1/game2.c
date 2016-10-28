/* Assignment1
 * by Yizhe Qu, section 1
 *    Ruihao Zhu, section 2
 *
 * This program reads the integers from a file of ASCII characters and builds a singly linked with them. 
 * Then, the program repetitively asks the user to guess an integer that might be in the list. 
 * The user enters a guess, and the program searches the linked list to either find the integer or not. 
 * It prints a message as to whether it found the integer or not.
 * The file name is provided as the single command line argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#define LEN sizeof(struct Node)
#define MAX_DIGITS 10

    struct Node{
        int theInt;
        struct Node *next;
    };	

/*
 Adds a integer to the linked list
 PARAMETER: head, the head of a linked list
            intforlist, the new integer that needs to be insert to the front of the linked list
 RETURN: the new node of the linked list
 */
    struct Node *listadd(struct Node *head, int intforlist)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->theInt = intforlist; 
        newNode->next = head;
        return newNode;
    }

/*
 Reads the file
 creates a linked list of file's contents

 PARAMETER: fd, the file
 RETURN: the head of the linked list. NULL if error occurred.
 */
    struct Node *createlist(FILE *fd)  
    {  
        int numSize = 0;
        int numCount = 0;
        char input[MAX_DIGITS];
        int i;
        int check;
        struct stat buf;
        struct Node *hNode = NULL;
        /*status of file*/
        if(fd == NULL){
            printf("can not open the file!\n");
            exit(1);
        }
	/*read inputs and create the linked list*/	
        while(fgets(input,MAX_DIGITS,fd) != NULL){
            hNode=listadd(hNode,atoi(input));
        }
        return hNode;
    } 

/*
 Checks if a number is in the linked list
 PARAMETER: hNode, the head of the linked list
            theInput, the integer to check
 RETURN: 1 if the integer is in the list
         0 if the integer is not in the list
 */
    int inlist(struct Node *hNode, int theInput){
        struct Node *p;
        p = hNode;
        if(hNode != NULL){
            do
            {
                if(p->theInt == theInput){
                    return 1;
                    break;
                }    
                p = p->next;
            }while(p != NULL);			
        }
        return 0;
    }

/*
 The guessing game
 enter guess or enter 'q' to exit
 PARAMETER: listhead, the head node of a linked list for the game
 */
    void playgame(struct Node *listhead){
        char input[1000];
        int guess;

        printf("This game has you guess which integers are in the list.\n");
        printf("Enter an integer or q to quit.\n");
	/*loop for the game*/
        do{
            printf("Integer guess: ");
            if(fgets(input,1000,stdin)){
                if(input[0] == 'q'){
                    return;
                }
                guess = atoi(input);
                if(inlist(listhead, guess)){
                    printf("%d is in the list.\n", guess);
                }else{
                    printf("%d is not in the list.\n", guess);
                }	
            }
        }while(1);		
    }

    int main(int argc, char *argv[]){
        FILE *fd;
        /*chech status*/
        if(argc != 2){
            printf("Invalid argument, exit!\n");
            exit(1);
        }
		
        fd = fopen(argv[1],"r");
        if(fd == NULL){
            printf("can not open the file!\n");
            exit(1);
        }

        playgame(createlist(fd));
        fclose(fd);
    }

	

