/*
2)	Considere um vetor com valores inteiros positivos e não ordenado, V = [ 17, 32, 45, 27, 8, 30, 51, 57, 81, 4, 23]. Implemente um método que separe o vetor de forma que os valores pares fiquem na frente do vetor e os valores impares fiquem atrás no vetor, por exemplo V = [ 4, 32, 30, 8, 27, 45, 51, 57, 81, 17, 23]. Na sua implementação você não pode utilizar um vetor auxiliar para resolver este problema. Considere na implementação do seu método o seguinte protótipo: (2,5 pontos)
*/
#include <stdio.h>

void separa(int vetor[], int inicio, int final){
  int esq, dir, temp;
  esq=inicio;
  dir=final;
  
  while(dir>esq){
    while((vetor[esq])%2==0){
      esq++;
    }
    while((vetor[dir])%2==1){
      dir--;
    }
    if(esq<dir){
      temp=vetor[esq];
      vetor[esq]=vetor[dir];
      vetor[dir]=temp;
      dir--;
      esq++;
    }
  }
}

void imprimeVetor(int vetor[], int inicio, int final){
  int i;
  for(i=inicio; i <=final; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(){
  int vetor[]={17, 32, 45, 27, 8, 30, 51, 57, 81, 4, 23};
  int vetor2[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int vetor3[]={1,3,5,7,9,2,4,6,8,10};
  int vetor4[]={2,4,6,1,3,5};
  imprimeVetor(vetor, 0, 10);
  separa(vetor, 0, 10);
  imprimeVetor(vetor, 0, 10);
  
  imprimeVetor(vetor2, 0, 15);
  separa(vetor2, 0, 15);
  imprimeVetor(vetor2, 0, 15);
  
  imprimeVetor(vetor3, 0, 9);
  separa(vetor3, 0, 9);
  imprimeVetor(vetor3, 0, 9);
  
  imprimeVetor(vetor4, 0, 5);
  separa(vetor4, 0, 5);
  imprimeVetor(vetor4, 0, 5);
  
  
}
