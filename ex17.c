#include <stdio.h>
#include <stdlib.h>
typedef struct st_pilha
{
    float x;
    struct st_pilha *prox;

}pilha;
int checarvazio(pilha *CABECA);
int menu(pilha *CABECA);
int tamanhopilha(pilha *CABECA);
void adicionar(pilha *CABECA);
void exibir(pilha *CABECA);
void retiraultimo(pilha *CABECA);
void zerapilha(pilha *CABECA);
void opera(pilha *CABECA, char a);
void exibeultimo(pilha *CABECA);
void operaespecial(pilha *CABECA);

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

int checarvazio(pilha *CABECA)
{
    if(CABECA->prox==NULL)
        return 1;
    else
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

void opera(pilha *CABECA, char a)
{
    float c, b, resposta;
    pilha *ultimo, *anterior;
    ultimo=CABECA->prox;
    anterior=CABECA;
    while(ultimo->prox!=NULL)
    {
        anterior=ultimo;
        ultimo=ultimo->prox;
    }
    b=anterior->x;
    c=ultimo->x;
    switch(a)
    {
        case '-':
            resposta= b-c;
            break;
        case '+':
            resposta= b+c;
            break;
        case '/':
            resposta= b/c;
            break;
        case '*':
            resposta= b*c;
            break;
        default:
            printf("\nOperador Invalido\n");
            break;
    }
    anterior->x = resposta;
    retiraultimo(CABECA);
    return;
}

void adicionar(pilha *CABECA)
{
    pilha *novono = malloc(sizeof(pilha));
    pilha *ponteiro;
    novono->prox = NULL;

    if(CABECA->prox==NULL)
        CABECA->prox = novono;
    else
    {
        ponteiro = CABECA->prox;
        while(ponteiro->prox!=NULL)
            ponteiro = ponteiro->prox;
        ponteiro->prox = novono;
    }
    printf("\nDigite um numeor:\n");
    scanf("%f", &novono->);
    return;
}

void exibir(pilha *CABECA)
{
    pilha *percorre;
    percorre = CABECA->prox;
    printf("\nNumeros da lista:\n");
    while(percorre != NULL)
    {
        printf("\n%f\n", percorre->x);
        percorre = percorre->prox;
    }
    return;
}

void retiraultimo(pilha *CABECA)
{
    pilha *ultimo, *anterior;
    ultimo = CABECA -> prox;
    anterior = CABECA;

    if(ultimo == NULL)
    {
        printf("\nNao tem nada para retirar\n");
        return;
    }
    while(ultimo -> prox != NULL)
    {
        anterior = ultimo;
        ultimo = ultimo -> prox;
    }
    anterior -> prox = NULL;
    free(ultimo);

    return;
}

void zerapilha(pilha *CABECA)
{
    pilha *percorre, *atual;
    atual = CABECA->prox;
    if(atual==NULL)
    {
        printf("\nCalculadora ja zerada!\n");
        return;
    }
    while(atual!=NULL)
    {
        percorre = atual->prox;
        free(atual);
        atual = percorre;
    }
    CABECA->prox = NULL;
    prinf("\nCalculadora zerada\n");
    return;
}

int tamanhopilha(pilha *CABECA)
{
    pilha *checar;
    checar = CABECA->prox;
    if(checar==NULL)
        return 0;
    if(checar->prox==NULL)
        return 1;

        return 2;
}

void exibeultimo(pilha *CABECA)
{
    pilha *ponteiro;
    ponteiro= CABECA->prox;
    if(ponteiro==NULL)
        return;
    while(ponteiro->prox!=NULL)
        ponteiro = ponteiro->prox;
    printf("\n%f\n", ponteiro->x);
    return;
}

void operaespecial(pilha *CABECA)
{
    pilha *ponteiro;
    ponteiro = CABECA->;
    ponteiro->x = ponteiro->x * 1;
}
