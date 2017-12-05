/*

3)  Implemente uma TAD com lista duplamente encadeada com o nome dupla.h que contenha valores inteiros e implemente os seguintes métodos: 
a.  inicializaLista(lista *l); listaVazia(lista *l); inseriLista(lista *l, int valor). (2,0 pontos). Os métodos inicializaLista e listaVazia fazem o que é esperado deles. O método inseriLista inseri um valor na frente da lista se o valor for par e no final da lista se o valor for impar.
b.  removeLista(lista *l, int valor). (1,5 pontos). O método removeLista remove o item indicado por valor caso ele esteja na lista ou imprime uma mensagem de erro se o item não estiver na lista.
c.  imprimeLista(lista *l). (1,5 pontos). O método imprimeLista imprime a lista de traz para frente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct N{
  int valor;
  struct N *proximo, *anterior;
} node;

typedef struct{
  node *primeiro;
  node *ultimo;
  int tamanho;
}lista;

void inicializaLista(lista *lst){
  lst->primeiro=NULL;
  lst->ultimo=NULL;
  lst->tamanho=0;
}

int listaVazia(lista *lst){
  if(lst->tamanho==0){
    return 1;
  }
  return 0;
}

void inserirLista(lista *lst, int valor){
  node *no, *temp;
  no=(node *)malloc(sizeof(node));
  no->valor=valor;
  no->proximo=NULL;
  no->anterior=NULL;
  if(listaVazia(lst)){
    lst->ultimo=no;
    lst->primeiro=no;
  }
  else if(valor%2==0){
    lst->primeiro->anterior=no;
    no->proximo=lst->primeiro;
    lst->primeiro=no;
  }
  else{
    lst->ultimo->proximo=no;
    no->anterior=lst->ultimo;
    lst->ultimo=no;
  }
  lst->tamanho++;
}


void removerLista(lista *lst, int valor){
  if(listaVazia(lst)==1){
    printf("ERRO: lista vazia\n");
    return;
  }
  int flag=0;
  node *temp;
  temp=lst->primeiro;
  if(temp->valor==valor){
    lst->primeiro=temp->proximo;
    lst->primeiro->anterior=NULL;
    lst->tamanho--;
  }
  else{
    while((temp->proximo!=NULL)&&(flag==0)){
      if(temp->proximo->valor==valor){
        flag=1;
      }
      else{
        temp=temp->proximo;
      }
    }
    if(flag==1){
      temp->proximo=temp->proximo->proximo;
      temp->proximo->anterior=temp->proximo;
      lst->tamanho--;
    }
    else{
      printf("O valor a ser removido nao esta na lista\n");
    }
  }
}


void imprimeLista(lista *lst){
  node *temp;
  temp=lst->ultimo;
  while(temp!=NULL){
    printf("%d ", temp->valor);
    temp=temp->anterior;
  }
  printf("\n");
}
