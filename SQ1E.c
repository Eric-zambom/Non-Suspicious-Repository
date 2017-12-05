#include <stdio.h>

int conta(int v[], int start, int end){
  
  int metade;
  metade = (start + end)/2;

  if(v[metade] == 0){
    return conta(v, metade+1, end);
  }

  else if((v[metade] == 1) && (v[metade-1] == 0)){
    return metade-1;
  }
  return conta(v, start, metade-1);
}


int main(){
  int v[] = {0,0,0,0,0,1,1,1,1,1};
  int v2[] = {0,0,0,1,1,1,1,1,1};
  int v3[] = {0,0,0,0,0,0,1,1};
  
  int temp;
  
  temp = conta(v, 0, 9);
  printf("%d \n", temp);
  temp = conta(v2, 0, 8);
  printf("%d \n", temp);
  temp = conta(v3,0, 7);
  printf("%d \n", temp);
}