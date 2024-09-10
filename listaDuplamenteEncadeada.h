struct tpTokens
{
    char linha[256];
    // struct tpTokens *prox;
};
typedef struct tpTokens Tokens;

struct tpPrograma
{
    struct tpPrograma *ant, *prox;
    Tokens *TokenLinha;
};
typedef struct tpPrograma Programa;

struct descritor
{
    Programa *inicio, *fim;
};
typedef struct descritor Descritor;

void initDescritor(Descritor *desc)
{
    (*desc).inicio = (*desc).fim = NULL;
}

void inserirNoFim(char linha[256], Descritor *desc)
{
    Programa *novo = (Programa *)malloc(sizeof(Programa));
    Tokens *novaLinha = (Tokens *)malloc(sizeof(Tokens));
    novo->prox = NULL;
    novo->ant = NULL;
    strcpy(novaLinha->linha, linha);
    novo->TokenLinha = novaLinha;
    if (desc->inicio == NULL)
    {
        desc->inicio = desc->fim = novo;
    }
    else
    {
        desc->fim->prox = novo;
        novo->ant = desc->fim;
        desc->fim = novo;
    }
}

void imprimirLista(Descritor *desc)
{
    Programa *atual = desc->inicio;

    while (atual != NULL)
    {
        printf("END: %p, CONT: %s", (void *)atual, atual->TokenLinha->linha);
        atual = atual->prox;
    }
}
