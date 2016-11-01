#include <stdio.h>
#include <stdlib.h>
typedef struct st_pilha
{
    float x;
    struct st_pilha *prox;

}pilha;

int main(void)
{
    pilha *CABECA = malloc(sizeof(pilha));
    CABECA->prox = NULL;
    printf("\nBem vindo a Calculadora Polonesa!\n");
    return 0;
}


