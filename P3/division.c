/* Assignment3
 * by Yizhe Qu, section 1
 *    Ruihao Zhu, section 2
 *
 * This program will 
 * prompt for and read in one integer value (followed by the newline)
 * prompt for and read in a second integer value (followed by the newline)
 * calculate the quotient and remainder of doing the integer division operation: int1 / int2
 * printing these results, and keeping track of how many division operations were successfully completed.
 * The program only exits if the second integer is 0 or after the user types Control-c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_DIGITS 100
char input[MAX_DIGITS];
int firstInput;
int secondInput;
int counts;

/* quit will let program exists if user types Control-c
   it will also displays the number of successfully completed division
 */
void quit(int sign){
    printf("\nControl-c caught. Program exit. \n");
    printf("The number of successfully completed division operations is %d \n", counts);
    exit(1);
}

/* dividByZero will let program exists if the second integer user types is 0
   it will also displays the error and number of successfully completed division
 */
void dividByZero(){
    printf("The divisor can not be zero! Program exit. \n");
    printf("The number of successfully completed division operations is %d \n", counts);
    exit(1);
}

int main(){
    /*set up an interrupt handler, track if user types Control-c*/
    struct sigaction act;
    act.sa_handler = quit;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if(sigaction(SIGINT, &act, 0) < 0){
        printf("Error when setting up interrupts, Exiting.");
        exit(1);
    }

    /*set up an interrupt handler, track if the second integer user types is 0*/
    struct sigaction act2;
    act2.sa_handler = dividByZero;
    sigemptyset(&act2.sa_mask);
    act2.sa_flags = 0;
    if(sigaction(SIGFPE, &act2, 0) < 0){
        printf("Error when setting up interrupts, Exiting.");
        exit(1);
    }

    /*an infinite loop doing divisions*/
    while(1){
        printf("Enter first integer: ");
        if(fgets(input,MAX_DIGITS,stdin) != NULL){
            firstInput = atoi(input);
        }
        printf("Enter second integer: ");
        if(fgets(input,MAX_DIGITS,stdin) != NULL){
            secondInput = atoi(input);
        }
        int result = firstInput / secondInput;
        counts++;

        printf("%d / %d is %d with", firstInput, secondInput, (firstInput/secondInput));
        printf(" a remainder of %d \n", (firstInput - secondInput * result));
    }
}
