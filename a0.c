#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


typedef struct Posicao {
    int linha;
    int coluna;
}Posicao;


int ehDiagonal (Posicao atual, Posicao desejada) {

    if ( desejada.linha == atual.linha - 1 && desejada.coluna == atual.coluna - 1 ) return true;
    if ( desejada.linha == atual.linha + 1 && desejada.coluna == atual.coluna - 1 ) return true;
    if ( desejada.linha == atual.linha - 1 && desejada.coluna == atual.coluna + 1 ) return true;
    if ( desejada.linha == atual.linha + 1 && desejada.coluna == atual.coluna + 1 ) return true;

    return false;
}
int ehLateral (Posicao atual, Posicao desejada) {

    if ( desejada.linha == atual.linha - 1 && desejada.coluna == atual.coluna ) return true;
    if ( desejada.linha == atual.linha + 1 && desejada.coluna == atual.coluna ) return true;
    if ( desejada.linha == atual.linha && desejada.coluna == atual.coluna + 1 ) return true;
    if ( desejada.linha == atual.linha && desejada.coluna == atual.coluna + 1 ) return true;
 
    return false;
}

int verificaVizinho (Posicao atual, Posicao desejada) {

    if (ehDiagonal(atual, desejada)) return true;

    if (ehLateral(atual, desejada)) return true;

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