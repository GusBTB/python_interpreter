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

int eh_letra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int eh_digito(char c)
{
    return c >= '0' && c <= '9';
}

int eh_espaco(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
void meu_strncpy(char *dest, char *src, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    dest[n] = '\0';
}
int meu_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

Tokens *tokenizarLinha(char *linha)
{
    int i = 0;
    int tamanho = meu_strlen(linha);
    Token *inicio = NULL;
    Token *atual = NULL;

    while (i < tamanho)
    {
        if (eh_espaco(linha[i]))
        {
            i++;
            continue;
        }
        if (linha[i] == '#')
        {
            break;
        }

        Token *novo_token = (Token *)malloc(sizeof(Token));
        novo_token->proximo = NULL;
        if (linha[i] == '"' || linha[i] == '\'')
        {
            char delimitador = linha[i];
            i++;
            int inicio_str = i;
            while (linha[i] != delimitador && linha[i] != '\0')
            {
                i++;
            }
            int comprimento = i - inicio_str;
            meu_strncpy(novo_token->valor, &linha[inicio_str], comprimento);
            strcpy(novo_token->tipo, "STRING");
            i++;
        }
        else if (eh_letra(linha[i]) || linha[i] == '_')
        {
            int inicio_id = i;
            while (eh_letra(linha[i]) || eh_digito(linha[i]) || linha[i] == '_')
            {
                i++;
            }
            int comprimento = i - inicio_id;
            meu_strncpy(novo_token->valor, &linha[inicio_id], comprimento);

            if (!strcmp(novo_token->valor, "def") || !strcmp(novo_token->valor, "if") ||
                !strcmp(novo_token->valor, "else") || !strcmp(novo_token->valor, "for") ||
                !strcmp(novo_token->valor, "while") || !strcmp(novo_token->valor, "return") ||
                !strcmp(novo_token->valor, "in") || !strcmp(novo_token->valor, "range"))
            {
                strcpy(novo_token->tipo, "PALAVRA_CHAVE");
            }
            else
            {
                strcpy(novo_token->tipo, "IDENTIFICADOR");
            }
        }
        else if (eh_digito(linha[i]))
        {
            int inicio_num = i;
            while (eh_digito(linha[i]))
            {
                i++;
            }
            if (linha[i] == '.')
            {
                i++;
                while (eh_digito(linha[i]))
                {
                    i++;
                }
            }
            int comprimento = i - inicio_num;
            meu_strncpy(novo_token->valor, &linha[inicio_num], comprimento);
            strcpy(novo_token->tipo, "NUMERO");
            else
            {
                char simbolo_atual = linha[i];
                char proximo_simbolo = linha[i + 1];
                int dois_caracteres = 0;
                char operadores_duplos[][3] = {"==", "!=", "<=", ">=", "**", "//", "+=", "-=", "*=", "/="};

                for (int j = 0; j < 10; j++)
                {
                    if (simbolo_atual == operadores_duplos[j][0] && proximo_simbolo == operadores_duplos[j][1])
                    {
                        novo_token->valor[0] = simbolo_atual;
                        novo_token->valor[1] = proximo_simbolo;
                        novo_token->valor[2] = '\0';
                        strcpy(novo_token->tipo, "OPERADOR");
                        i += 2;
                        dois_caracteres = 1;
                        break;
                    }
                }

                if (!dois_caracteres)
                {
                    novo_token->valor[0] = simbolo_atual;
                    novo_token->valor[1] = '\0';
                    strcpy(novo_token->tipo, "OPERADOR");
                    i++;
                }
            }
            if (inicio == NULL)
            {
                inicio = novo_token;
                atual = novo_token;
            }
            else
            {
                atual->proximo = novo_token;
                atual = novo_token;
            }
        }

        return inicio;
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
