#include <stdio.h>
#include <stdlib.h>
typedef struct st_pilha
{
    float x;
    struct st_pilha *prox;

}pilha;
int menu(pilha *CABECA);

int main(void)
{
    int x = 0;
    pilha *CABECA = malloc(sizeof(pilha));
    CABECA->prox = NULL;
    printf("\nBem vindo a Calculadora Polonesa!\n");
    while(x == 0){
        x = menu(CABECA);
    }
    return 0;
}


