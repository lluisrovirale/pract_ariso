/* ----------------------------------------------------------------------- */

/* partida.c: Juego del 7 y medio			                                   */

/* ----------------------------------------------------------------------- */

/* El juego consiste en ir pidiendo cartas intentando sumar 7.5 puntos     */
/* sin pasarse. Gana el jugador que más se acerca a 7.5.		   */
/* Se utiliza una baraja española. Sota, caballo y rey valen medio punto.  */
/* Las demás cartas puntúan según su valor numérico (de 1 a 7).            */

/* ----------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define PALOS    4
#define NUMEROS 10
#define CARTAS  (NUMEROS*PALOS)

#define TRUE 1
#define FALSE 0

typedef struct
{
    char *palo;
    char *nombre;
    int  valor;
}carta;

/* Baraja ordenada: primero las 10 cartas de Oros, luego las 10 	  */
/* de Copas, las 10 de Espadas y finalmente las 10 de Bastos.		  */
/* Para no gestionar valores decimales, el valor de cada carta se guarda  */
/* multiplicado por 2 							  */

carta baraja[CARTAS]={ 
 { "Oros", "as", 2 }, { "Oros", "2", 4 },
 { "Oros", "3", 6 }, { "Oros", "4", 8 },
 { "Oros", "5", 10 }, { "Oros", "6", 12 },
 { "Oros", "7", 14 }, { "Oros", "sota", 1 },
 { "Oros", "caballo", 1 }, { "Oros", "rey", 1 },

 { "Copas", "as", 2 }, { "Copas", "2", 4 },
 { "Copas", "3", 6 }, { "Copas", "4", 8 },
 { "Copas", "5", 10 }, { "Copas", "6", 12 },
 { "Copas", "7", 14 }, { "Copas", "sota", 1 },
 { "Copas", "caballo", 1 }, { "Copas", "rey", 1 },

 { "Espadas", "as", 2 }, { "Espadas", "2", 4 },
 { "Espadas", "3", 6 }, { "Espadas", "4", 8 },
 { "Espadas", "5", 10 }, { "Espadas", "6", 12 },
 { "Espadas", "7", 14 }, { "Espadas", "sota", 1 },
 { "Espadas", "caballo", 1 }, { "Espadas", "rey", 1 },

 { "Bastos", "as", 2 }, { "Bastos", "2", 4 },
 { "Bastos", "3", 6 }, { "Bastos", "4", 8 },
 { "Bastos", "5", 10 }, { "Bastos", "6", 12 },
 { "Bastos", "7", 14 }, { "Bastos", "sota", 1 },
 { "Bastos", "caballo", 1 }, { "Bastos", "rey", 1 }, };

void intercambiar(carta *c1, carta *c2);
void barajar(carta baraja[CARTAS]);

int main()
{
    int actual, prev, pts_j, pts_c, sigue_j, sigue_c;

    actual = 0;
    prev = 0;
    pts_j = 0;
    pts_c = 0;
    sigue_j = TRUE;
    sigue_c = TRUE;

    barajar(baraja);
    do {
 	  /* Jugador */
	  if(sigue_j){	
	   if((pts_c <= 15) && ((pts_j < pts_c)||(pts_j < 10))){
	      prev=pts_j;
	      pts_j += baraja[actual].valor;
	      printf("\n-Jugador- carta: \"%s de %s\", prev:%2.1f actual:%2.1f\n",baraja[actual].nombre,baraja[actual].palo,prev/2.0,pts_j/2.0);
              if (pts_j > 15){
                    printf("Jugador, te has pasado !!!\n");
                    sigue_j = FALSE;
              }
	      else if (pts_j == 15){
                    printf("Jugador, se planta con 7.5\n");
                    sigue_j = FALSE;
	      }	
	      else  actual++;
            }
	    else{
                    printf("Jugador, decide plantarse.\n");
		    sigue_j = FALSE;
	        } 
	    }
 	  /* Croupier */
	  if(sigue_c){	
           if((pts_j <= 15) && ((pts_c < pts_j)||(pts_c < 10))){
	      prev=pts_c;
	      pts_c += baraja[actual].valor;
	      printf("\n-Croupier- carta: \"%s de %s\", prev:%2.1f actual:%2.1f\n",baraja[actual].nombre,baraja[actual].palo,prev/2.0,pts_c/2.0);
              if (pts_c > 15){
                    printf("Croupier se pasa.\n");
                    sigue_c = FALSE;
              }
	      else  actual++;
	    }
	    else{
                     printf("Croupier, se planta.\n");
		     sigue_c = FALSE;
		} 
	  }
          printf("\n- Jugador: %2.1f puntos\n", pts_j/2.0);
          printf("- Croupier: %2.1f puntos\n", pts_c/2.0);
    } while(sigue_j || sigue_c);

    /* Resultado de la partida */
    if((pts_j <= 15) && ((pts_j > pts_c) || (pts_c > 15))) {
	printf("\n\033[36mEnhorabuena Jugador: has ganado la partida !!!\n\033[0m");
	exit(0);
    }
    else{
	printf("\n\033[31mJugador: otra vez sera...\n\033[0m");
	exit(1);
    }
    exit(0);
}

void intercambiar (carta *c1, carta *c2)
{
    carta aux;

    aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}

void barajar(carta baraja[CARTAS])
{
  int veces,i,c1,c2;

  srand(getpid()); //Establecemos la semilla del Random. Dicha semilla es el valor del PID de nuestro programa
  veces=rand() % 100; //Nos devuelve un numero aleatorio entre 0 y 99
  for (i=0; i<veces; i++) {
      c1=rand() % CARTAS; //Nos devuelve un numero aleatorio entre 0 y CARTAS-1
      c2=rand() % CARTAS; //Nos devuelve un numero aleatorio entre 0 y CARTAS-1
      intercambiar( &(baraja[c1]), &(baraja[c2]) );
  }
}
