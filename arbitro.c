#include <stdio.h>
#include <stdlib.h>

int mapa [1000] [1000];

void imprimeEntorno (int L, int C) {

    for ( int i = L-1; i <= L+1; i++) {
        for ( int j = C-1; j <= C; j++)
            printf ( " %d ", mapa[i][j]);
        printf ( "\n" );
    }
}


int main ( int argc, char **argv ) {

    // força entrar na posição 5,5
    srand (atoi (argv[1]));

    int Li, Ci, Turnos;
    Li = atoi ( argv[2] );
    Ci = atoi ( argv[3] );
    Turnos = atoi  ( argv[4] );

    for ( int i = 0; i < 1000; i++ ) 
        for ( int j = 0; j < 1000; j++) 
            mapa[i][j] = rand () % 300;
        
    printf ( "==Entorno inicial\n" );
    imprimeEntorno (Li, Ci);
    printf ( "\n" );

    // informações para o jogador vão na saída padrão
    // informações recebidas pela entrada padrão
    // informações de debug e acompanhamento via stderr
    printf ( "%d %d %d %d", Li, Ci, mapa[Li][Ci], Turnos );
    fflush ( stdout );

    for ( int t = 0; t < Turnos; t++ ) {
        // jogador pode executar as seguintes operações
        // sondar L C
        // dominar L C
        // fimturno

        char buf[100];

        while ( scanf ( "%s", buf ) == 1 && buf[0] != 'f') {

            int l, c;

            scanf ( "%d %d", &l, &c );

            if ( buf[0] == 's' ) printf ( "sondagem %d %d %d\n", l, c, mapa[l][c] );
            else printf ( "dominacao %d\n", mapa[l][c] );
            fflush ( stdout );
            
        }
    }
}
