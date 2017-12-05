#include <stdio.h>
#include <stdlib.h>

typedef struct N{
  int valor;
  struct N *next, *previous;
} celula;

typedef struct{
  celula *first;
  celula *last;
  int size;
}lista;

void inicializaLista(lista *lst)
{
  lst->first = NULL;
  lst->last = NULL;
  lst->size = 0;
}

int listaVazia(lista *lst)
{
  if(lst->size == 0){
    return 1;
  }
  return 0;
}

void inserirLista(lista *lst, int valor)
{
  celula *no, *temp;
  no=(celula *)malloc(sizeof(celula));
  no->valor = valor;
  no->next = NULL;
  no->previous = NULL;
  if(listaVazia(lst))
  {
    lst->last = no;
    lst->first = no;
  }
  else if(valor%2==0)
  {
    lst->first->previous = no;
    no->next = lst->first;
    lst->first = no;
  }
  else
  {
    lst->last->next = no;
    no->previous = lst->last;
    lst->last = no;
  }
  lst->size++;
}


void removerLista(lista *lst, int valor)
{
  if(listaVazia(lst) == 1)
  {
    printf("ERRO 404: lista vazia\n");
    return;
  }
  int flag = 0;
  celula *temp;
  temp=lst->first;
  if(temp->valor == valor)
  {
    lst->first = temp->next;
    lst->first->previous = NULL;
    lst->size --;
  }
  else
  {
    while((temp->next!= NULL)&&(flag == 0))
    {
      if(temp->next->valor==valor)
      {
        flag=1;
      }
      else{
        temp=temp->next;
      }
    }
    if(flag==1)
    {
      temp->next=temp->next->next;
      temp->next->previous=temp->next;
      lst->size--;
    }
    else
    {
      printf("O valor pedido nao esta na lista\n");
    }
  }
}


void imprimeLista(lista *lst)
{
  celula *temp;
  temp=lst->last;
  while(temp!= NULL){
    printf("%d ", temp->valor);
    temp = temp->previous;
  }
  printf("\n");
}
