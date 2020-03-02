/*test 1*/
#include "mbed.h"
#include <stdio.h>

#define BUFFER_SIZE 5
char DataB[BUFFER_SIZE];


//#define BUFFER_SIZE 2

typedef struct
{
  int readIndex;
  int writeIndex;
  bool isEmpty;
  bool isFull;
  //char data[BUFFER_SIZE];
}sCircularBuffer;

void init(sCircularBuffer *apArray)
{
  apArray->readIndex  = 0;
  apArray->writeIndex = 0;
  apArray->isEmpty    = 1;
  apArray->isFull     = 0;
}
//------------------------------------------------------------------------------
int put(sCircularBuffer *apArray, char* ptrDataB, int aValue)
{
  if(apArray->isFull){return -1;} /*если буффер полон*/
  
  if(apArray->writeIndex >= BUFFER_SIZE){apArray->writeIndex = 0;} /*переместиться в самое начало*/
    
  if(apArray->isEmpty) /*если буффер пуст*/
  {
    apArray->isEmpty = 0;
    // apArray->data[apArray->writeIndex++] = aValue;
    ptrDataB[apArray->writeIndex++] = aValue;

    if (apArray->writeIndex == apArray->readIndex)/*один индекс догнал другой, буффер полон*/
      apArray->isFull  = 1;
    return 1;
  }

  ptrDataB[apArray->writeIndex++] = aValue; /*если буффер не пуст*/

  if (apArray->writeIndex == apArray->readIndex){apArray->isFull  = 1;}
    

  return 1;
}
//------------------------------------------------------------------------------
int get(sCircularBuffer *apArray, char* ptrDataB)
{
  if(apArray->isEmpty){return -1;}  /*если буффер пуст*/
  
  apArray->isFull = 0;  /*если буффер не пуст*/

  if(apArray->readIndex >= BUFFER_SIZE){apArray->readIndex = 0;} 
 
  int res = ptrDataB[apArray->readIndex++];

  if(apArray->readIndex == apArray->writeIndex){apArray->isEmpty = 1;}
  
  return  res;
}
//------------------------------------------------------------------------------
void clear(sCircularBuffer *apArray)
{
  apArray->isEmpty    = 1;
  apArray->isFull     = 0;
  apArray->writeIndex = 0;
  apArray->readIndex  = 0;
}
//------------------------------------------------------------------------------
int isEmpty(sCircularBuffer *apArray)
{
  return apArray->isEmpty;
}
//------------------------------------------------------------------------------
int isFull(sCircularBuffer *apArray)
{
  return apArray->isFull;
}

//------------------------------------------------------------------------------
int main()
{
  printf("\nstep 11\n");
  sCircularBuffer buff;
  int r;
  int res_put;

  init(&buff); 

  res_put=put(&buff, DataB, 1);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n"); 
  
  res_put=put(&buff, DataB, 2);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n"); 
  
  res_put=put(&buff, DataB, 3);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n"); 
  
  res_put=put(&buff, DataB, 4);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");
  
  res_put=put(&buff, DataB, 5);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");
  
  res_put=put(&buff, DataB, 6);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");
    res_put=put(&buff, DataB, 7);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n"); 
  
  res_put=put(&buff, DataB, 8);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");
  
  res_put=put(&buff, DataB, 9);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");
  
  res_put=put(&buff, DataB, 10);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");

  res_put=put(&buff, DataB, 11);
  r = get(&buff, DataB); printf("r = %d\n", r);
  for(int i=0; i<BUFFER_SIZE; ++i){printf("DataB[%d] = %d\n", i, DataB[i]);fflush(stdout);}
  printf("res_put = %d\n", res_put);
  printf("=================================================\n\n");
/*


  put(&buff, 2);
  r = get(&buff);

  put(&buff, 3);
  r = get(&buff);

  put(&buff, 4);
  r = get(&buff);

  put(&buff, 5);
  r = get(&buff);

  clear(&buff);

  r = get(&buff);
  r = get(&buff);
  r = get(&buff);

  put(&buff, 1);
  put(&buff, 2);
  put(&buff, 3);

  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);

  put(&buff, 4);
  put(&buff, 5);
  put(&buff, 6);
  put(&buff, 7);
  put(&buff, 8);
  put(&buff, 9);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  */
  return 0;
}
