#include <stdlib.h>
#include <stdio.h>

#define MAX 20

typedef struct
{
    char itens[MAX];
    int topo;
}pilha;

void inicializar(pilha *p)
{
    p->topo = -1;
}

int isFull(pilha *p)
{
    return p->topo == MAX - 1;
}

int isEmpty(pilha *p)
{
    return p->topo == -1;
}

void empilhar(pilha *p, char c)
{
    if(isFull(p))
    {
        printf("A fila esta cheia");
        return;
    }

    p->topo++;
    p->itens[p->topo] = c;
}

char desempilhar(pilha*p)
{
    if(isEmpty(p))
    {
        printf("A fila esta vazia");
        return 0;
    }

    char x = p->itens[p->topo];
    p->topo--;

    return x;
}

int igual(char abrir, char fechar)
{
    if(abrir == '(' && fechar == ')') return 1;
    if(abrir == '[' && fechar == ']') return 1;
    if(abrir == '{' && fechar == '}') return 1;

    return 0;
}


int verificar(pilha *p, char expressao[])
{
    for(int i=0; expressao[i] != '\0'; i++)
    {
        char c = expressao[i];
        if(c == '(' || c == '[' || c == '{')
        {
            empilhar(p, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if(isEmpty(p))
            {
                return 0;
            }
            int topo = desempilhar(p);
            if (!(igual(topo, c)))
            {
                return 0;
            }
        }
    }

    return isEmpty(p);
}






int main (void)
{
    pilha p;
    char expressao[MAX];
    inicializar(&p);

    printf("Digite a expressao e descubra se é valida:  ");
    scanf("%s", expressao);

    if(verificar(&p, expressao))
    {
        printf("Expressao valida");
    }
    else printf("Expressao invalida");
}