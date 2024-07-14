#include <stdio.h>
#include <stdlib.h>

struct no {
    char data;
    struct no* esq;
    struct no* dir;
    struct no* prox;
};
struct no *topo=NULL;
struct no* novo(char data)
{
    struct no* no
        = (struct no*)malloc(sizeof(struct no));
    no->data = data;
    no->esq = NULL;
    no->dir = NULL;
    no->prox = NULL;
   
    return (no);
}
void printInordem(struct no* no)
{
    if (no == NULL)
        return;
    else{
        printInordem(no->esq);
        printf("%c ", no->data);
        printInordem(no->dir);
    }
}

void push(struct no* x)
{
    if(topo==NULL)
    topo = x;
    else
    {
        (x)->prox = topo;
        topo  = x;
    }
}
struct no* pop()
{
    struct no* p = topo;
    topo = topo->prox;
    return p;
}
int main()
{
    char s[] = {'A','B','+','C','D','-','*'};
    int l = sizeof(s) / sizeof(s[0]) ;
    struct no *x, *y, *z;
    for (int i = 0; i < l; i++) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            z = novo(s[i]);
            x = pop();
            y = pop();
            z->esq = y;
            z->dir = x;
            push(z);
        }else {
            z = novo(s[i]);
            push(z);
        }
    }
    printf(" arvore in-ordem: ");
    printInordem(z);
    return 0;
}
