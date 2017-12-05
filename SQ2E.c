#include <stdio.h>

void separate(int v[], int start, int end)
{
  int par;
  int imp;
  int temp;
  par = start;
  imp = end;
  
  while(imp > par)
  {
    while((v[par]) %2 == 0)
    {
      par++;
    }
    while((v[imp]) %2 == 1)
    {
      imp --;
    }
    if(par < imp)
    {
      temp = v[par];
      v[par] = v[imp];
      v[imp] = temp;
      imp --;
      par ++;
    }
  }
}

void imprimeVetor(int v[], int start, int end)
{
  int i;
  for(i = start; i <= end; i ++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main()
{
  int v[]={17, 32, 45, 27, 8, 30, 51, 57, 81, 4, 23};
  int v2[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int v3[]={1,3,5,7,9,2,4,6,8,10};
  int v4[]={2,4,6,1,3,5};
  imprimeVetor(v, 0, 10);
  separate(v, 0, 10);
  imprimeVetor(v, 0, 10);
  
  imprimeVetor(v2, 0, 15);
  separate(v2, 0, 15);
  imprimeVetor(v2, 0, 15);
  
  imprimeVetor(v3, 0, 9);
  separate(v3, 0, 9);
  imprimeVetor(v3, 0, 9);
  
  imprimeVetor(v4, 0, 5);
  separate(v4, 0, 5);
  imprimeVetor(v4, 0, 5);
  
  
}
