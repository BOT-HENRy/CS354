/* Assignment3
 * by Yizhe Qu, section 1
 *    Ruihao Zhu, section 2
 *
 * This program will print the current time after every 3 seconds
 * and the program only exits after the user types Control-c 5 times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

/* printTime prints the current time
 */
void printTime(){
    time_t currTime;
    if(time (&currTime) < 0){
        printf("can not get current time, Exiting.");
        exit(1);
    }
    printf("current time is %s", ctime(&currTime));	
    alarm(3);
}

int count = 5;    /*use to keep track of the number of Control-c user types*/

/* quit counts the number of Control-c user types
   if less then 5, continue;
   if user types Control-c 5 times, program exits.
 */
void quit(int sign){
    count--;
        if(count > 0){
            printf("Control-c caught. %d more before program is ended. \n", count);
        }
        if(count == 0){
            printf("Final Control-c caught. Exiting. \n");
	    exit(1);
        }
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

    printf("Date will be printed every 3 seconds.\n");
    printf("Enter ^C to end the program:\n");
    signal(SIGALRM, printTime);
    alarm(3);
    /*an infinite loop does nothing*/
    while(1){
        pause();
    }
}

