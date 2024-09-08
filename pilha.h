//talvez tera mais um tipo de uso com outras definicoes podemos criar outro arquivo depois se precisar
//pilha para controle de linha
struct PilhaLinha {
    pilha *ponteiroLinha;
    pilha *prox;
    linha *info;
    
} typedef struct PilhaLinha pilha;

struct Linha {
    float valor;
    char identificador[15]; //variavel ou endereco por isso char, nao sei se 15 e suficiente
} typedef struct Linha linha;

void init (pilha **P) {
    *P = NULL;
}

void push (pilha **P, float valor, pilha *endereco,char identificador[15]) {
    pilhaLinha *nova;

    nova = (pilha *) malloc(sizeof(pilha));
    nova->valor = valor;
    nova->ponteiroLinha = endereco;
    strcpy(nova->identificador,identificador);

    nova->prox = *pilha;
    *P = nova;
}

char isEmpty (pilha *P) {
    return P == NULL;
}