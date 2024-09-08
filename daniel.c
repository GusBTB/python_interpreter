#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pilha.h"
#include "listaGen.h"
// STRUCTS E UNIONS
//struct principal que contem a cabeca da outra lista que segura os tokens da linha atual
struct tpPrograma {
    Progama *ant,*prox;
    Tokens *TokenLinha;
} typedef struct tpProgama Progama;

//struct que segura todas os tokens em caixas separadas;
struct tpTokens {
    char linha[20];
    Tokens *prox;
} typedef struct tpTokens Tokens;
//struct para ler o arquivo.py talvez nao seja necessario depois buguei aqui :(
struct lerArquivo {
    char linha[30];
}

// PROTOTIPO DE FUNCÕES
void executar();

// EXECUÇÕES
void executar() {

}
int main()
{	
    return 0;
}

//tadpilha nao finalizado lista gen ta quase precisamos dar nomes melhores para estrutura
//pensar em oque usar para guardar string com id para demarcar linha como falado na imagem
//acho interesante uma fila