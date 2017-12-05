/*
1)	Considere um vetor ordenado formado apenas por valores 0 e 1, por exemplo V = [ 0, 0, 0, 0, 0, 1, 1, 1]. Implemente um método em O(lg N),
 onde N é o número de elementos do vetor, de se determinar a posição i do vetor de forma que V[i] = 0 e V[i+1] = 1. Considere na implementação do seu método o seguinte protótipo: (2,5 pontos)
*/

#include <stdio.h>


int degrau(int vetor[], int inicio, int final){
  int meio=(inicio+final)/2;
  if((vetor[meio]==1)&&(vetor[meio-1]==0)){
    return meio-1;
  }
  else if(vetor[meio]==0){
    return(degrau(vetor, meio+1, final));
  }
  return degrau(vetor, inicio, meio-1);
}


int main(){
  int vetor[]={0,0,0,0,0,1,1,1,1,1};
  int vetor2[]={0,0,0,1,1,1,1,1,1};
  int vetor3[]={0,0,0,0,0,0,1,1};
  
  int temp;
  
  temp=degrau(vetor, 0, 9);
  printf("%d \n", temp);
  temp=degrau(vetor2, 0, 8);
  printf("%d \n", temp);
  temp=degrau(vetor3,0, 7);
  printf("%d \n", temp);
}