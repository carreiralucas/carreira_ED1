#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int itens[MAX];
    int top;
}PILHA;

void inicializar(PILHA *p)
{
    p->top = -1;
}

int isEmpty(PILHA *p)
{
    return p->top == -1;
}

int isFull(PILHA *p)
{
    return p->top == MAX - 1;
}

void push(PILHA *p, int elem)
{
    if (isFull(p))
    {
        printf("\nA pilha esta cheia.\n");
        return;
    }

    p->top++;
    p->itens[p->top] = elem;

}

int pop(PILHA *p)
{
    if(isEmpty(p))
    {
        printf("\nA pilha esta vazia");
        return -1;
    }
    else
    {
         int valor = p->itens[p->top];
        p->top--;
        return valor;
    }
   
}

int top(PILHA *p)
{
    if(isEmpty(p))
    {
        printf("\nA pilha esta vazia");
        return -1;
    }
    else
    {
        return p->itens[p->top];
    }
}



int main (void)
{
    PILHA p;

    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Elemento removido: %d\n", pop(&p)); // Remove o 30
    printf("Topo atual: %d\n", top(&p));        // Mostra o 20

    return 0;
}
