/* Assignment1
 * by Yizhe Qu, section 1
 *    Ruihao Zhu, section 2
 *
 * This program reads integers from a binary file of integers, 
 * and computes the integer average of those integers
 * The file name is provided as the single command line argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

#define NUMINTS 10

int main(int argc, char *argv[])
{	
    int fd;
    int numSize = 0;
    int numCount = 0;
    int sum = 0;
    int check,readint;
    struct stat buf;
    int *numberArray;

    /*chech status*/
    if(argc != 2){
        printf("Invalid argument, exit!\n");
        exit(1);
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        printf("can not open the file!\n");
        exit(1);
    }

    check = fstat(fd,&buf);
    numSize = buf.st_size;
    numberArray = (int*)malloc(numSize);
    /*print the number in the file and calculate the average*/
    printf("Number values averaged are:\n");
    while(read(fd,&readint,sizeof(int)) != 0){
        numberArray[numCount] = readint;
        printf("%d\n",readint);
        sum = sum + readint;
        numCount ++;
    }
    printf("the average is: %d \n",sum / numCount);

    close(fd);
    return 0;
}

