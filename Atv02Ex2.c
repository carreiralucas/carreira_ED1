    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX 20

    typedef struct
    {
        int itens[MAX];
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

    void empilhar(pilha *p, int elem)
    {
        if(isFull(p))
        {
            printf("Erro, a pilha esta cheia");
            return;
        }

        p->topo++;
        p->itens[p->topo] = elem;
    }

    int desempilhar(pilha *p)
    {
        if(isEmpty(p))
        {
            printf("Erro, a pilha esta vazia");
            return -1;
        }

        int v = p->itens[p->topo];
        p->topo--;

        return v;
    }


    void analise(pilha *p, char string[])
    {
        int v1, v2;

        for(int i=0; string[i] != '\0'; i++)
        {
            char c = string[i];

            switch (c)
            {
                case '+':
                v1 = desempilhar(p);
                v2 = desempilhar(p);
                empilhar(p, v2+v1);
                break;
            
            case '-':
                v1 = desempilhar(p);
                v2 = desempilhar(p);
                empilhar(p, v2-v1);
                break;

            case '*':
                v1 = desempilhar(p);
                v2 = desempilhar(p);
                empilhar(p, v2*v1);
                break;

            case '/':
                v1 = desempilhar(p);
                v2 = desempilhar(p);
                empilhar(p, v2/v1);
                break;
            default:
                empilhar(p, c - '0');
                break;
            }
        }
    }


    int main(void)
    {
        pilha p;
        char string[MAX];

        inicializar(&p);

        printf("\nInsira a string(sem espaços):  ");
        scanf("%s", string);

        analise(&p, string);

        printf("O resultado é %d", desempilhar(&p));
        
    }