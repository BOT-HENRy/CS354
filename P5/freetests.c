/******************************************************************************
 * FILENAME: freetests.c
 * DATE:     4 May 2015
 * MODIFIED BY: Yizhe Qu, section1; Ruihao Zhu, section2
 * *****************************************************************************/

#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main() {
  assert(Mem_Init(400) == 0);
  void* ptr[4];
  /*check if the size round works */
  ptr[0] = Mem_Alloc(10); 
  Mem_Dump();
  ptr[1] = Mem_Alloc(12);
  ptr[2] = Mem_Alloc(24);
  ptr[3] = Mem_Alloc(48);
  
 
  /*check if the NULL pointer check works*/
  assert(Mem_Free(NULL) == -1);

  /*check if the free works*/
  assert(Mem_Free(ptr[1]) == 0);
  Mem_Dump();
  /*check if the coalesce works*/
  assert(Mem_Free(ptr[2]) == 0);
  Mem_Dump();

  assert(Mem_Free(ptr[5]) == -1);

  exit(0);
}
