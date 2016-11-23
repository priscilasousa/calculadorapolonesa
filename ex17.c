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

int menu(pilha *CABECA)
{
    char a, operador, negativo;
    int tamanho;

    printf("\nDigite a letra da opcao que deseja\n(n) - Selecionar numero\n(0) - Selecionar operador\n(z) - Zerar a calculadora\n(r) - Retirar ultimo elemento\n(e) - Exibir elementos\n(s) - Sair\n");
    scanf("%C", &a);
    switch(a)
    {
        case 'n':
            adicionar(CABECA);
            break;
        case 'o':
            tamanho = tamanhopilha(CABECA);
            switch(tamanho)
            {
                caso 0:
                    printf("\nImpossivel, lista esta vazia\n");
                break;
                case 1:
                printf("\nA lista possui apenas um elementos, o unico operador que pode ser inserido eh -, quer inserir?\n(s) - Sim\n(n) - Nao\n"):
                    scanf(" %c", &negativo);
                if(negativo == 's' || negativo == 'S')
                {
                    operaespecial(cabeca);
                    exibeultimo(CABECA);
                }
                break;

                case 2:
                do
                {
                    printf("\nDigite o operador\n");
                    scanf("%c", &operador);
                }while(operador != '*' && operador != '+' && operador != '/' && operador != '-');
                opera(CABECA, operador);
                exibeultimo(CABECA);
                break;
            }
            break;
        case 'z':
            zerapilha(CABECA);
            break;
        case 's':
            printf("\nSaindo...\n\n");
            return 1;
            break;
        case 'r':
            retiraultimo(CABECA);
            break;
        case 'e':
            exibir(CABECA);
        default:
            printf("\nLetra invalida\n");
    }
    return 0;
}

