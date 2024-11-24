// Incluindo bibliotecas
#include "cache.h"

int main() {
    struct Cache cache;
    int m, n, p, b;
    printf("Total de blocos da cache: ");
    scanf("%d", &m);

    printf("Associativdade da cache: ");
    scanf("%d", &n);

    printf("Total de palavras por bloco: ");
    scanf("%d", &p);

    printf("Total de bytes por palavra: ");
    scanf("%d", &b);

    cache = iniciarCache(m, n, p, b);
    printCache(cache);

    return 0;
}