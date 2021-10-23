#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0

typedef struct Elem {
    int vetor[9];
}Elem;

int tamanhoNum(int entrada) {
    int divisor = entrada;
    int casasDecimais = 0;

    while(divisor >= 1){
        divisor = divisor / 10;
        casasDecimais++;
    }

    return casasDecimais;
}

int pot (base, expoente) {
    int i = 0;
    int result = base;
    while (i < expoente - 1){
        result = base * result;
        i++;
    }
    return result;
}

int concatena(int linha, int coluna) {

    int expoente = tamanhoNum(coluna);

    int  produto = pot(10, expoente) * linha;

    int concatenado = produto + coluna;

    return concatenado;
}

int hashFunction (Elem vetor[], int codigo, int linha, int coluna) {

    int hashCode = concatena (linha, coluna);
    int index;
    if(hashCode > 100)
        vetor[hashCode].vetor[0] = codigo;

    else
        index = hashCode % 9;
        vetor[hashCode].vetor[index] = codigo;

}


void randTest ( int mapa[300][300] ) {    
    for ( int i = 0; i < 20; i++ ) 
        for ( int j = 0; j < 20; j++) 
            mapa[i][j] = rand () % 9;
}


void imprimeMapa ( int mapa[300][300] ) {
    for (int i = 0; i < 20; i++) {
        for ( int j = 0; j < 20; j++ ) printf( "%d ", mapa[i][j] );
        printf ( "\n" );
    }
}


void primeiraSonda ( Elem jogo[], int L, int C ) {

    hashFunction ( jogo, 3, L, C );
    hashFunction ( jogo, 1, L, C + 1 );
    hashFunction ( jogo, 1, L, C - 1 );
    hashFunction ( jogo, 1, L + 1, C );
    hashFunction ( jogo, 1, L + 1, C - 1 );
    hashFunction ( jogo, 1, L + 1, C + 1 );
    hashFunction ( jogo, 1, L - 1, C );
    hashFunction ( jogo, 1, L - 1, C + 1 );
    hashFunction ( jogo, 1, L - 1, C - 1 );

}


int verificaSondar ( int jogo[300][300], int mapa, int L, int C ) {
    // retorna a pontuação se estiver tudo ok
    // retorna -1 se deu zica
    if ( jogo[L][C] == 1) return mapa;
    else return -1;
}


int verificaDominar (int jogo[300][300], int mapa, int L, int C) {

    if ( jogo[L][C] == 2) {
        jogo[L][C] = 3;
        // colocar as posições adjacentes == 1

        if( jogo [L-1] [C-1] == 0 ) jogo [L-1] [C-1] = 1; // 1
        if( jogo [L-1] [C]   == 0 ) jogo [L-1] [C]   = 1; // 2
        if( jogo [L]   [C-1] == 0 ) jogo [L]   [C-1] = 1; // 3
        if( jogo [L+1] [C-1] == 0 ) jogo [L+1] [C-1] = 1; // 4
        if( jogo [L+1] [C]   == 0 ) jogo [L+1] [C]   = 1; // 5
        if( jogo [L-1] [C+1] == 0 ) jogo [L-1] [C+1] = 1; // 6
        if( jogo [L]   [C+1] == 0 ) jogo [L]   [C+1] = 1; // 7
        if( jogo [L+1] [C+1] == 0 ) jogo [L+1] [C+1] = 1; // 8
        return mapa;
    }
    else {
        return -1;
    }
}


int main () {

    // Manipulação na matriz:
    // 0 -> posições que não foram sondadas nem dominadas
    // 1 -> posições possíveis de sondar
    // 2 -> posições já sondadas
    // 3 -> posições já dominadas
    // Precisa adicionar uma pontuação para posições sondadas na partida?

    int L, C, P, T, EDAzinhos = 1, pontos;
    int mapa[300][300];
    int jogo[3000];
    char opcao[20];
    int pontuacaoTotal = 0;
    randTest ( mapa );
    // imprimeMapa ( mapa );

    scanf ( "%d %d %d %d", &L, &C, &P, &T );
    pontos = P;

    // adiciona L e C como dominada, e coloca posições adjacentes como possíveis sondas
    primeiraSonda (jogo, L, C);
    // imprimeMapa (jogo);

    for ( int i = 0; i < T; i++ ) {

        printf ("==== TURNO %d\n", i);

        for ( int j = 0; j < EDAzinhos; j++ ) {

            scanf ( "%s", opcao ); // sondar, dominar ou fimturno
            scanf ( "%d %d", &L, &C );

            if ( !strcmp( "sondar", opcao )) {
                // verifica se já não foi sondada
                // verifica se é possível sondar
                // retorna a pontuação da casa sondada

                printf ( "  JOGADOR: sondar %d %d\n", L, C );
                printf ( "sondagem %d %d %d\n", L, C, mapa[L][C] );

                int sonda = verificaSondar ( jogo, mapa[L][C], L, C );
                if ( sonda == -1 ) {
                    printf ( "Posicao %d, %d nao pode ser sondada. GAME OVER\n", L, C );
                    return;
                    // fflush (stdout): 
                } 
                else {
                    printf ( "  ARBITRO: sondagem %d %d %d\n", L, C, mapa[L][C] );

                }

                jogo [L][C] = 2;
            }

            else if ( !strcmp( "dominar", opcao ) ) {
                // verifica se já não foi dominada
                // verifica se é possível dominar
                // retorna os pontos ganhos

                printf ( "  JOGADOR: dominar %d %d\n", L, C );

                int domina = verificaDominar ( jogo, mapa[L][C], L, C );
                if ( domina == -1) {
                    printf ( "Posicao %d, %d nao pode ser dominada. GAME OVER\n", L, C );
                    break;
                }
                else {
                    printf ( "  ARBITRO: dominacao %d %d %d\n", L, C, mapa[L][C] );
                }
            }

            else {
                printf ( "fim de turno\n" );
                break;
            }

            
        }

    }

    return 0;
}