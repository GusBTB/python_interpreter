//definindo estrutura que sera usada para calcular expressoes matematicas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct reg_lista
{
    struct listagen *cabeca;
    struct listagen *cauda;
}; typedef struct reg_lista ListaMatematica;

union info_lista
{
    char info[5];
    struct reg_lista lista;
};

struct listagen
{
    char terminal;
    union info_lista no;
}; typedef struct listagen ListaGen;

//funcoes para manipular a lista Generalizada

ListaGen *criarAtomo(char *info)
{
    ListaGen *lista = (ListaGen*)malloc(sizeof(ListaGen));
    lista->terminal = 1;
    strcpy(lista->no.info, info);
    return lista;
}

char nulo(ListaGen *lista)
{
    return lista==NULL;
}

char atomo(ListaGen *lista)
{
    return !nulo(L) && lista->terminal;
}

ListaGen *Cons(ListaGen *head, ListaGen *tail)
{
    if (atomo(tail))
    {
        return NULL;
    }
    else
    {
        ListaGen *lista = (ListaGen*)malloc(sizeof(ListaGen));
        lista->terminal = 0;
        lista->no.lista.cabeca = H;
        lista->no.lista.cauda = T;
        return lista;
    }
}

ListaGen *head(ListaGen *lista)
{
    return nulo(lista) || atomo(lista) ? NULL : lista->no.lista.cabeca
}

ListaGen *tail(ListaGen *lista)
{
    return nulo(lista) || atomo(lista) ? NULL : lista->no.lista.cauda;
}