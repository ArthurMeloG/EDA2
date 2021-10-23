#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0


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


void primeiraSonda ( int jogo[300][300], int L, int C ) {

    jogo[L][C] = 3;

    jogo [L-1] [C-1] = 1; // 1
    jogo [L-1] [C]   = 1; // 2
    jogo [L]   [C-1] = 1; // 3
    jogo [L+1] [C-1] = 1; // 4
    jogo [L+1] [C]   = 1; // 5
    jogo [L-1] [C+1] = 1; // 6
    jogo [L]   [C+1] = 1; // 7
    jogo [L+1] [C+1] = 1; // 8
}


int verificaSondar ( int jogo[300][300], int mapa[300][300], int L, int C ) {
    // retorna a pontuação se estiver tudo ok
    // retorna 1 se deu zica

    if ( jogo[L][C] == 1) return mapa[L][C];
    else return -1;
}


int verificaDominar (int jogo[300][300], int mapa[300][300], int L, int C) {

    if ( jogo[L][C] == 2) {
        jogo[L][C] = 3;
        // colocar as posições adjacentes == 1
        return mapa[L][C];
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
    int jogo[300][300];
    char opcao[20];

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

            if ( opcao[0] == 's' ) {
                // verifica se já não foi sondada
                // verifica se é possível sondar
                // retorna a pontuação da casa sondada

                printf ( "  JOGADOR: sondar %d %d\n", L, C );
                printf ( "sondagem %d %d %d\n", L, C, mapa[L][C] );

                int sonda = verificaSondar ( jogo, mapa, L, C );
                if ( sonda == -1 ) {
                    printf ( "Posicao %d, %d nao pode ser sondada. GAME OVER\n", L, C );
                    break;
                    // fflush (stdout): 
                } 
                else {
                    printf ( "  ARBITRO: sondagem %d %d %d\n", L, C, mapa[L][C] );

                }

                jogo [L][C] = 2;
            }

            if ( opcao[0] == 'd' ) {
                // verifica se já não foi dominada
                // verifica se é possível dominar
                // retorna os pontos ganhos

                printf ( "  JOGADOR: dominar %d %d\n", L, C );

                int domina = verificaDominar ( jogo, mapa, L, C );
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