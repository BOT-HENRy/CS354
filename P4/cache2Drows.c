/* Assignment4 cache2Drows.c
 * Yizhe Qu, section 1
 * Ruihao Zhu, section 2
 *
 * This program sets each element of a 3000 row by 500 column array
 * of integers to the sum of the row index and the column index.
 */

#include <stdio.h>
#include <stdlib.h>

int arr2d[3000][500];   /*declare a 3000 row by 500 column array*/

/*
 * using a for loop to sets each element in the array
 * to the sum of the row index and the column index.
 */
int main(){
    int i,j;
    /*
     * the inner loop works its way through a single row of the array, 
     * and the outer loop iterates through the rows.
     */
    for(i = 0; i < 3000; i++){
        for(j = 0; j < 500; j++){
            arr2d[i][j] = i + j;
        }
    }
    return 0;
}
