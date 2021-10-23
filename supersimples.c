#include <stdio.h>
#include <stdlib.h>

// (Vai ganhar accepted nos casos de exemplo, mas vai perder para o supersimples no ranking)

int main(void)
{

  long Linhainicial,Colunainicial,Pontosinicial,Turnos;

  scanf("%ld %ld %ld %ld",&Linhainicial,&Colunainicial,&Pontosinicial,&Turnos);
  printf("sondar %ld %ld\n",Linhainicial,++Colunainicial);
  printf("fimturno\n");
  fflush(stdout);
  scanf(" %*s %*ld %*ld %*ld");

  for ( long t=1;t<Turnos;t++ ) {
    printf ( "dominar %ld %ld\n",Linhainicial,Colunainicial );
    printf ( "sondar %ld %ld\n",Linhainicial,++Colunainicial );
    printf ( "fimturno\n" );
    fflush ( stdout );
    scanf ( " %*s %*ld" );
    scanf ( " %*s %*ld %*ld %*ld" );
  }


  return 0;
}