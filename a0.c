#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0

typedef struct Elemento {
    int sondado;
    int dominado;
}Elemento;


Elemento verificaVizinho (Elemento vetor, int linha, int  coluna) {

        Elemento result;
    if ( matriz[linha - 1][coluna - 1].dominado ) 
        result = matriz[linha - 1][coluna - 1];

    else if ( matriz[linha + 1][coluna - 1].dominado )
        matriz[linha + 1][coluna - 1];

    else if ( matriz[linha - 1][coluna + 1].dominado )
        matriz[linha - 1][coluna + 1];

    else if ( matriz[linha + 1][coluna + 1].dominado )
        result = matriz[linha + 1][coluna + 1];

    else if ( matriz[linha - 1][coluna].dominado )
        result = matriz[linha - 1][coluna];

    else if ( matriz[linha + 1][coluna].dominado )
        result = matriz[linha + 1][coluna];

    else if ( matriz[linha][coluna - 1].dominado )
        result = matriz[linha][coluna - 1];

    else if ( matriz[linha][coluna + 1].dominado )
        result = matriz[linha][coluna + 1];

    else
        result

     return result;
}

int tamanhoInt(int entrada) {
    int divisor = entrada;
    int casasDecimais = 0;
    for (int dividendo = divisor / 10; dividendo > 1 ; divisor = divisor / 10) casasDecimais++;

<<<<<<< HEAD
    return casasDecimais;
}

int transformaParaVetor(int linha, int coluna) {

    int expoenteLinha =  tamanhoInt(linha);
    int expoenteColuna = tamanhoInt(coluna);

    int qtdCasasDecimais = expoenteLinha + expoenteColuna;

    int index = pow(10, qtdCasasDecimais) * linha;

    return index;
}
=======
void fazSonda (long int L, long int C, long int EDAzinhos) {
>>>>>>> 4eef5ceaefca5ef7f3a2142fd6b3c54f0d6f4fe0

void fazSonda (long int L, long int C, Elemento matriz ) {
    verificaVizinho(matriz, L, C);
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
            fazSonda ( L, C, matriz );
        }

        if ( strcmp ( opcao, "dominar" ) == false ) {
            dominar()
            break;
        }

        else {

        }
    }

    return 0;
}