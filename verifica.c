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


