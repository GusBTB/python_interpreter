#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "listaDuplamenteEncadeada.h"
// #include "pilha.h"
// #include "listaGen.h"

// struct que segura todas os tokens em caixas separadas;

// struct para ler o arquivo.py talvez nao seja necessario depois buguei aqui :(
struct lerArquivo
{
    char linha[30];
};

// PROTOTIPO DE FUNCÕES
void executar();
void lerArquivo(char nomeDoArquivo[50]);

// EXECUÇÕES
void executar()
{
    printf("Executar");
}

void lerArquivo(char nomeDoArquivo[50])
{
    char linha[256];
    Descritor desc;
    initDescritor(&desc);
    FILE *arq = fopen(nomeDoArquivo, "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    else
    {
        while (fgets(linha, sizeof(linha), arq))
        {
            inserirNoFim(linha, &desc);
            // printf("%s", linha);
        }
        fclose(arq);
        imprimirLista(&desc);
    }
}

int main()
{
    lerArquivo("exemplo.py");
    return 0;
}

// tadpilha nao finalizado lista gen ta quase precisamos dar nomes melhores para estrutura
// pensar em oque usar para guardar string com id para demarcar linha como falado na imagem
// acho interesante uma fila
