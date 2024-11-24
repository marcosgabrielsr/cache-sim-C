// Incluindo bibliotecas
#include "cache.h"

// Função para iniciar um vetor de conjuntos para cache
struct Conjunto* iniciarConjuntos(int x, int y) {
    // Aloca dinamicamente um vetor de conjuntos de tamanho x
    struct Conjunto *novosConjuntos = (struct Conjunto*) calloc (x, sizeof(struct Conjunto));

    // Aloca para conjunto um vetor de blocos de tamanho y
    for(int i = 0; i < x; i++)
        novosConjuntos[i].blocos = iniciarBlocos(y);
    
    return novosConjuntos;
}

// Função para iniciar um vetor de blocos para os conjuntos
struct Bloco* iniciarBlocos(int y) {
    // Aloca dinamicamente um vetor de blocos de tamanho y
    struct Bloco *novosBlocos = (struct Bloco*) calloc (y, sizeof(struct Bloco));

    // Inicializando bits de validade como zero
    for(int i = 0; i < y; i++)
        novosBlocos[i].v = 0;

    return novosBlocos;
}

// Função para iniciar a cache
struct Cache iniciarCache(int m, int n, int p, int b) {
    struct Cache novaCache;
    novaCache.m = m;
    novaCache.n = n;
    novaCache.p = p;
    novaCache.b = b;
    novaCache.conjuntos = iniciarConjuntos(m/n, n);

    return novaCache;
}

// Função para imprimir informações sobre a cache
void printCache(struct Cache cache) {
    printf("\n====== Visualizar Cache ======\n");
    printf("Total de blocos da cache: %d\n", cache.m);
    printf("Associatividade da cache: %d\n", cache.n);
    printf("Total de palavras por bloco: %d\n", cache.p);
    printf("Total de bytes por palavra: %d\n", cache.b);

    printf("\nÍndice | bit de Validade | tag\n");
    for(int i = 0; i < (cache.m/cache.n); i++)
        for(int j = 0; j < cache.n; j++)
            printf("% 6d | % 15d | % 4d\n", i, j, cache.conjuntos[i].blocos[j].v, cache.conjuntos[i].blocos[j].tag);
}