#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


typedef struct Posicao {
    int linha;
    int coluna;
}Posicao;


int verifica (Posicao posicaoAtual, int entradaLinha, int entradaColuna ) {
    if ( entradaLinha == posicaoAtual.linha && entradaColuna == posicaoAtual.coluna )
        return true;

    return false; 
}


void fazSonda (long int L, long int C, long int EDAzinhos) {

}


int main () {

    long int L, C, P, T, EDAzinhos = 1, pontos;
    char opcao[100];

    scanf ( "%ld %ld %ld %ld", &L, &C, &P, &T );
    pontos = P;

    for (int i = 0; i < T; i++) {

        scanf ( "%s", opcao );
        scanf ( "%ld %ld", &L, &C );

        if ( strcmp ( opcao, "sondar") == false ) {
            fazSonda ( L, C, EDAzinhos );
        }

        if ( strcmp ( opcao, "dominar" ) == false ) {
            break;
        }

        else {

        }
    }

    return 0;
}