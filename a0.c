#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct Posicao {
    int linha;
    int coluna;
}Posicao;

int verifica (Posicao posicaoAtual, int entradaLinha, int entradaColuna) {
    if(entradaLinha == posicaoAtual.linha && entradaColuna == posicaoAtual.coluna )
        return true;

    return false; 
}

int main () {

    long int L, C, P, T;

    scanf(" %ld %ld %ld %ld", &L, &C, &P, &T);
    
    for (int i = 0; i < T; i++) {
        
    }

    return 0;
}