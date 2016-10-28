/* Assignment4 cache1D.c
 * Yizhe Qu, section 1
 * Ruihao Zhu, section 2
 *
 * This program sets each element of an array of 
 * 100,000 integers to the value of its index.
 */

#include <stdio.h>
#include <stdlib.h>

int arr[100000];   /*declare an array of 100,000 integers*/

/*
 * using a for loop to sets each element in the array
 * to the value of its index.
 */
int main(){
    int i;
    for(i = 0; i < 100000; i++){
        arr[i] = i;
    }
    return 0;
}
