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


