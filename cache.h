// Incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Struct para representar os blocos
struct Bloco {
    int v;                                          // Campo para armazenar bit de validade
    int contLRU;                                    // Campo para 
    int tag;                                        // Campo para armazenar a tag de um endereço
    int *palavras;                                  // Campo para armazenar as palavras de um bloco
};

// Struct para representar os conjuntos
struct Conjunto {
    struct Bloco *blocos;                           // Campo para o conjunto de blocos de um conjunto
};

// Struct para representar a cache
struct Cache {
    int m;                                          // Campo para armazenar o total de blocos da cache
    int n;                                          // Campo para armazenar a associatividade da cache
    int p;                                          // Campo para armazenar o total de palavras por bloco
    int b;                                          // Campo para armazenar o número de bytes por palavra
    struct Conjunto *conjuntos;                     // Campo para armazenar os conjuntos da cache
};

// Declarando protótipos das funções
// Função para iniciar um vetor de blocos para os conjuntos
struct Bloco* iniciarBlocos(int y);

// Função para iniciar um vetor de conjuntos para cache
struct Conjunto* iniciarConjuntos(int x, int y);

// Protótipos das funções
// Função para iniciar a cache segundo seu:
// - total de blocos(m);
// - associatividade(n);
// - n° de palavras por bloco(p);
// - n° de bytes por palavra;
struct Cache iniciarCache(int m, int n, int p, int b);

// Função para imprimir informações sobre a cache
void printCache(struct Cache cache);