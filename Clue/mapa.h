#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int mapa(int valorUsuario,char nombre[valorUsuario][2048]){
  //Se ingresa el mapa original.
  char a[50][50]={"#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#######################################",
  "#HHHHHHHH## ##IIIIIIIIIIII##2##AAAAAAA#",
  "#HHHHHHHH#   #IIIIIIIIIIII#   #AAAAAAA#",
  "#HHHHHHHH#   #IIIIIIIIIIII#   #AAAAAAA#",
  "#HHHHHHHH#   #IIIIIIIIIIII#   #AAAAAAA#",
  "#######  #   #IIIIIIIIIIII#   #AAAAAAA#",
  "##           #IIIIIIIIIIII#   #AAAAAAA#",
  "#1           #IIIIIIIIIIII#   ###  ####",
  "##           #IIIIIIIIIIII#          ##",
  "#########    #####    #####          3#",
  "#GGGGGGG##                           ##",
  "#GGGGGGGG#             #  #############",
  "#GGGGGGGG              #BBBBBBBBBBBBBB#",
  "#GGGGGGGG#             #BBBBBBBBBBBBBB#",
  "#GGGGGGG##             #BBBBBBBBBBBBBB#",
  "####  ###               BBBBBBBBBBBBBB#",
  "#                      #BBBBBBBBBBBBBB#",
  "###########            ########BBBBBBB#",
  "#FFFFFFFFF#                   #########",
  "#FFFFFFFFF                           ##",
  "#FFFFFFFFF#                           #",
  "###########      #  ######  #        ##",
  "##               #DDDDDDDDDD#   ##  ###",
  "#6               #DDDDDDDDDD#   #CCCCC#",
  "##               #DDDDDDDDDD#   #CCCCC#",
  "###########  #   #DDDDDDDDDD#   #CCCCC#",
  "#EEEEEEEEEEEE#   #DDDDDDDDDD#   #CCCCC#",
  "#EEEEEEEEEEEE#   #DDDDDDDDDD#   #CCCCC#",
  "#EEEEEEEEEEEE#   #DDDDDDDDDD#   #CCCCC#",
  "#EEEEEEEEEEEE##5##DDDDDDDDDD##4##CCCCC#",
  "#######################################",
  "#######################################",};

////////////////////////////////////////////////////////////////////////////////////
//Se definen las posiciones iniciales:
int x=20;int y=1;int x2=14;int y2=28;int x3=22;int y3=37;int x4=42;int y4=30;int x5=42;int y5=15;
int x6=36;int y6=1;int p=45;int q=44;int i;int d=0;char c;
//Imprime mapa:
for(i=0;i<=p;i++){
    puts(a[i]);}    
int n=dado();
////////////////////////////////////////////////////////////////////////////////////Repartir cartas:
int j, w, l;
  //  Comienzan a repartir cartas.
  const char *cartas[21]={"Puñal","Candelabro","Pistola","Cuerda","Tubería de plomo","Llave inglesa","Biblioteca","Sala de Billar","Estudio","Dormitorio","Terraza","Sala","Comedor","Cocina","Salon de Baile","Escarlata","Moradillo","Mostaza","Verdi","Azulino","Blanco"}; 
  //Se definen estados de los jugadores.
  const char *estado_jugador1[2];
  const char *estado_jugador2[2];
  const char *estado_jugador3[2];
  const char *estado_jugador4[2];
  const char *estado_jugador5[2];
  const char *estado_jugador6[2];
  // Se crea un array que va a guardar el numero de la carta.
  int guardar_cartas[21]; 
  // Se definen los arrays de los jugadores con los espacios máximos que se pueden tener
  const char *jugador_1[9];
  const char *jugador_2[9];
  const char *jugador_3[9];
  const char *jugador_4[9];
  const char *jugador_5[9];
  const char *jugador_6[9];
  const char *asesinato[3];
  //Se inicializan los contadores para mover la posición de los arrays de jugadores.
  int k_1=0, k_2=0, k_3=0, k_4=0, k_5=0, k_6=0, jugador, complete;
  //Se realiza un array para indicar cuando un jugador pierde
  const char *loser[1] = {"Perdedor"};
  char cool;

  srand(time(NULL));
// Sección de elementos para ganar el juego, se guardan en matriz asesinato.

guardar_cartas[0] = rand() % 6;
asesinato[0] = cartas[guardar_cartas[0]];

guardar_cartas[1] = rand() % 9+6;
asesinato[1] = cartas[guardar_cartas[1]];

guardar_cartas[2] = rand() % 6+15;
asesinato[2] = cartas[guardar_cartas[2]];
// Se recorre el array del asesinato y se imprime.
for(i=0; i<3; i++){
  printf("%s\n", asesinato[i]);
}
// Se realiza esta print para evitar que se borre la infromación imnediatamente.
printf("\nContinuar?"); 
scanf("%s", &cool);
////////////////////////////////////////////////////////////////////////////////////////2 jugadores
//Función para cuando la cantidad de jugadores es de 2
if(valorUsuario == 2){
  //Esta parte corresponde al jugador 1.
  for(i=3; i<12; i++){
    complete = 0;
    // El while se realiza con esta condicion por si la carta asignada a jugador uno es igual a una carta que ya estaba siendo utilizada se regresa al while para repetir el proceso, cuando ya son diferentes sale del while se le suma uno al contador del jugador y sigue con el for hasta cumplir la condición. 
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_1[k_1] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        		if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    } 
      k_1++;}
  for(i=12; i<21; i++){
    complete = 0;
    // El while se realiza con esta condicion por si la carta asignada a jugador uno es igual a una carta que ya estaba siendo utilizada se regresa al while para repetir el proceso, cuando ya son diferentes sale del while se le suma uno al contador del jugador y sigue con el for hasta cumplir la condición.
    	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_2[k_2] = cartas[guardar_cartas[i]];
	      complete = 1;
  
		    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    } 
      k_2++;}}

// De esta parte se utiliza la mima logica del juego por lo que no se va a comentar hasta estar en la línea 428 que comienza la lógica del mapa. 
////////////////////////////////////////////////////////////////////////////////////////3 jugadores:
else if(valorUsuario == 3){
  for(i=3; i<9; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_1[k_1] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        		if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    } 
      k_1++;}
  for(i=9; i<15; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_2[k_2] = cartas[guardar_cartas[i]];
	      complete = 1;
  
		    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    } 
      k_2++;}

  for(i=15; i<21; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_3[k_3] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_3++;}}

////////////////////////////////////////////////////////////////////////////////////////4 jugadores:
else if(valorUsuario == 4){
  for(i=3; i<8; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_1[k_1] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        		if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    }
      k_1++;}

  for(i=8; i<13; i++){
    complete = 0;
    //else if(jugador == 2){
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_2[k_2] = cartas[guardar_cartas[i]];
	      complete = 1;
  
		    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    }
      k_2++;}

  for(i=13; i<17; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_3[k_3] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_3++;
  }

  for(i=17; i<21; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_4[k_4] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_4++;}}
////////////////////////////////////////////////////////////////////////////////////////5 jugadores:
else if(valorUsuario == 5){
  for(i=3; i<7; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_1[k_1] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        		if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    }
      k_1++;}

  printf("\n Jugador 1:");

  for(i=0; i<4; i++){
    printf("%s\n", jugador_1[i]);
  }

  for(i=7; i<11; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_2[k_2] = cartas[guardar_cartas[i]];
	      complete = 1;
  
		    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    }
      k_2++;}

  printf("\n Jugador 2:");

  for(i=0; i<4; i++){
    printf("%s\n", jugador_2[i]);
  }
  
  for(i=11; i<15; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_3[k_3] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_3++;}

  printf("\n Jugador 3:");

  for(i=0; i<4; i++){
    printf("%s\n", jugador_3[i]);
  }

  for(i=15; i<18; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_4[k_4] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_4++;}

  printf("\n Jugador 4:");

  for(i=0; i<3; i++){
    printf("%s\n", jugador_4[i]);
  }
  for(i=18; i<21; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_5[k_5] = cartas[guardar_cartas[i]];
	    complete = 1;

	    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_5++;}}
////////////////////////////////////////////////////////////////////////////////////////6 jugadores:

else{
  for(i=3; i<6; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_1[k_1] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        		if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    } 
      k_1++;}

  printf("\n Jugador 1:");

  for(i=0; i<3; i++){
    printf("%s\n", jugador_1[i]);
  }
  

  for(i=6; i<9; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_2[k_2] = cartas[guardar_cartas[i]];
	      complete = 1;
  
		    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    }
      k_2++;}

  printf("\n Jugador 2:");

  for(i=0; i<3; i++){
    printf("%s\n", jugador_2[i]);
  }
  
  for(i=9; i<12; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_3[k_3] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_3++;}

  printf("\n Jugador 3:");

  for(i=0; i<3; i++){
    printf("%s\n", jugador_3[i]);
  }

  for(i=12; i<15; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_4[k_4] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_4++;}

  printf("\n Jugador 4:");

  for(i=0; i<3; i++){
    printf("%s\n", jugador_4[i]);
  }

  for(i=15; i<18; i++){
    complete = 0;
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_5[k_5] = cartas[guardar_cartas[i]];
	    complete = 1;

	    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_5++;}
  for(i=18; i<21; i++){
    complete = 0;
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_6[k_6] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      k_6++;}}
////////////////////////////////////////////////////////////////////////////////////////Lógica mapa:
jugador=1;//Se define que se va a iniciar con jugador 1
// Al terminar de repartir cartas se va a entrar a un while del cual nunca va a salir debido a nunca se va a cumplir la condición 
//Definiendo contadores de jugadores:
  int contador_1=0;
  int contador_2=0;
  int contador_3=0;
  int contador_4=0;
  int contador_5=0;
  int contador_6=0;
// Se define el while que tiene como función evitar que el mapa vuelva a ser el original en esta parte se mantienen los valores actualizados de los jugadores. Cabe destacar que de este while el jugador no va a salir.
while(x != p && y != q){
  c = getchar();// Se define para que el usuario pueda decidir 

// Esta sección se va a implementar para cada jugador.
  if (jugador==1){
   //En esta parte se revisa si todos los jugadores perdieron para acabar el juego
   if(estado_jugador1[1] == "Perdedor"){
      if(estado_jugador2[1] == "Perdedor"){
        if(valorUsuario>=3){
          if(estado_jugador3[1] == "Perdedor"){
            if(valorUsuario>=4){
              if(estado_jugador4[1] == "Perdedor"){
                if(valorUsuario>=5){
                  if(estado_jugador5 == "Perdedor"){
                    if(valorUsuario == 6){
                      if(estado_jugador6 == "Perdedor"){
                            printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                            printf("\n Continuar?");
                            scanf("%s", &cool);
                            return main();
                            }
                          else{
                            printf("El jugador %s ya ha perdido.", estado_jugador1[0]);
                            jugador = 2;
                          }
                        }
                      else{
                        printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                        printf("\n Continuar?");
                        scanf("%s", &cool);
                        return main();
                      }
                    }

                    else{
                      printf("El jugador %s ya ha perdido.", estado_jugador1[0]);
                      jugador = 2;
                    }

                  }
                  else{
                    printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                      printf("\n Continuar?");
                      scanf("%s", &cool);
                      return main();
                  }
                  
                }
                else{
                    printf("El jugador %s ya ha perdido.", estado_jugador1[0]);
                    jugador = 2;
                  }
              }

            else{
                    printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                    printf("\n Continuar?");
                    scanf("%s", &cool);
                    return main();
                  }
          }

          else{
                printf("El jugador %s ya ha perdido.", estado_jugador1[0]);
                    jugador = 2;
              }
        }
        else{
      printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
      printf("\n Continuar?");
      scanf("%s", &cool);
      return main();
        }
      }
    else{
      printf("El jugador %s ya ha perdido.", estado_jugador1[0]);
      jugador = 2;
    }}
 // Como el valor de jugador uno no es cero se procede a ejecutar el siguiente código   
   else{ 
  // Cuando c=='s' se mueve a hacia abajo, en el if estan todas las codiciones donde no se va a permitir el movimiento.   
  if(c=='s'){
    if(a[x+1][y] != '#' & a[x+1][y]  != '2' & a[x+1][y] != '3' & a[x+1][y] != '4' & a[x+1][y] != '5' & a[x+1][y] != '6' & a[x+1][y] != '/'&a[x+1][y] != 'H'&a[x+1][y] != 'I'&a[x+1][y] != 'A'&a[x+1][y] != 'G'&a[x+1][y] != 'B'&a[x+1][y] != 'F'&&a[x+1][y] != 'E'&a[x+1][y] != 'D'&a[x+1][y] != 'C'){
      a[x][y] = ' ';
      x++;
      a[x][y]='1';      
      d++;
      }
    }
  // Cuando c=='w' se mueve a hacia arriba, en el if estan todas las codiciones donde no se va a permitir el movimiento.
  if(c=='w'){
    if(a[x-1][y] != '#' & a[x-1][y] != '2' & a[x-1][y] != '3' & a[x-1][y] != '4' & a[x-1][y] != '5' & a[x-1][y] != '6' & a[x-1][y] != '/'&a[x-1][y] != 'H'&a[x-1][y] != 'I'&a[x-1][y] != 'A'&a[x-1][y] != 'G'&a[x-1][y] != 'B'&a[x-1][y] != 'F'&&a[x-1][y] != 'E'&a[x-1][y] != 'D'&a[x-1][y] != 'C'){
      a[x][y] = ' ';
      x--;
      a[x][y]='1';      
      d++;
      }            
    }
  // Cuando c=='a' se mueve a hacia izquierda, en el if estan todas las codiciones donde no se va a permitir el movimiento.
   if(c=='a'){
     if(a[x][y-1] != '#' & a[x][y-1] != '2' & a[x][y-1] != '3' & a[x][y-1] != '4' & a[x][y-1] != '5' & a[x][y-1] != '6' & a[x][y-1] != '/'&a[x][y-1] != 'H'&a[x][y-1] != 'I'&a[x][y-1] != 'A'&a[x][y-1] != 'G'&a[x][y-1] != 'B'&a[x][y-1] != 'F'&&a[x][y-1] != 'E'&a[x][y-1] != 'D'&a[x][y-1] != 'C'){
       a[x][y] = ' ';
       y--;
       a[x][y]='1';      
       d++;
     }
   }
   // Cuando c=='d' se mueve a hacia derecha, en el if estan todas las codiciones donde no se va a permitir el movimiento.
   if(c=='d'){
     if(a[x][y+1] != '#' & a[x][y+1] != '2' & a[x][y+1] != '3' & a[x][y+1] != '4' & a[x][y+1] != '5' & a[x][y+1] != '6' & a[x][y+1] != '/'&a[x][y+1] != 'H'&a[x][y+1] != 'I'&a[x][y+1] != 'A'&a[x][y+1] != 'G'&a[x][y+1] != 'B'&a[x][y+1] != 'F'&&a[x][y+1] != 'E'&a[x][y+1] != 'D'&a[x][y+1] != 'C'){
       a[x][y] = ' ';
       y++;
       a[x][y]='1';      
       d++;
   }}
   //En este if se toman el cuenta todas las condiciones cuando el jugador 1 entra a una habitación.
   if(a[x-1][y]=='H'||a[x-1][y]=='I'||a[x-1][y]=='A'||a[x-1][y]=='G'||a[x+1][y]=='E'||a[x+1][y]=='D'||a[x+1][y]=='C'||a[x+1][y]=='B'||a[x][y+1]=='B'||a[x][y-1]=='G'||a[x][y-1]=='F'){
     contador_1++;
    if(a[x-1][y]=='H'||a[x-1][y]=='I'||a[x-1][y]=='A'||a[x-1][y]=='G'){
     printf("Está dentro de una habitación así que puede sospechar.\n");
     l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x][y] = ' ';
     x++;
     a[x][y]='1';
     d=n;}
    if(a[x+1][y]=='E'||a[x+1][y]=='D'||a[x+1][y]=='B'||a[x+1][y]=='C'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x][y] = ' ';
     x--;
     a[x][y]='1';
     d=n;}
    if(a[x][y-1]=='G'||a[x][y-1]=='F'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x][y] = ' ';
     y++;
     a[x][y]='1';
     d=n;
    }    
    if(a[x][y+1]=='B') {
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x][y] = ' ';
     y--;
     a[x][y]='1';
     d=n;
    }
    }
    }
    } 
 // Se limpia las variables
 fflush(stdin);
   system("clear");
   // Se imprime el mapa
   for(i=0;i<=p;i++){     
     puts(a[i]);}
     // Si el valor del dados es igual al valor del contador d, se pasa al siguiente jugador.
     if(d==n){
       jugador=2;
       d=0;
       n= dado();        
     }
// Se implementa la misma lógica explicada para el jugador uno, hasta la linea 1325.
///////////////////////////////////////////////////////////////////////////////////////////Jugador 2
  if (jugador==2){

    if(estado_jugador2[1] == "Perdedor"){
      if(estado_jugador1[1] == "Perdedor"){
        if(valorUsuario>=3){
          if(estado_jugador3[1] == "Perdedor"){
            if(valorUsuario>=4){
              if(estado_jugador4[1] == "Perdedor"){
                if(valorUsuario>=5){
                  if(estado_jugador5 == "Perdedor"){
                    if(valorUsuario == 6){
                      if(estado_jugador6 == "Perdedor"){
                        printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                        printf("\n Continuar?");
                        scanf("%s", &cool);
                        return main();
                      }
                      else{
                        printf("El jugador %s ya ha perdido.", estado_jugador2[0]);
                        jugador = 3;
                      }
                    }

                    else{
                      printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                      printf("\n Continuar?");
                      scanf("%s", &cool);
                      return main();
                    }

                  }
                  else{
                    printf("El jugador %s ya ha perdido.", estado_jugador2[0]);
                    jugador = 3;
                  }
                  
                }
                else{
                    printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                    printf("\n Continuar?");
                    scanf("%s", &cool);
                    return main();
                  }
              }

            else{
                  printf("El jugador %s ya ha perdido.", estado_jugador2[0]);
                  printf("\n Continuar?");
                  scanf("%s", &cool);
                  jugador = 3;
            }
            
          }

          else{
                printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                printf("\n Continuar?");
                scanf("%s", &cool);
                return main();
              }
        }
        else{
      printf("El jugador %s ya ha perdido.", estado_jugador2[0]);
      printf("\n Continuar?");
      scanf("%s", &cool);
      jugador = 3;
        }
    }

      else{
      printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
      printf("\n Continuar?");
      scanf("%s", &cool);
      return main();   
      }
    }

    else{
          printf("El jugador %s ya ha perdido.", estado_jugador2[0]);
          printf("\n Continuar?");
          scanf("%s", &cool);
          jugador = 1;
          
      }  
    }

    else{
  if(c=='s'){
    if(a[x2+1][y2] != '#' & a[x2+1][y2]  != '2' & a[x2+1][y2] != '3' & a[x2+1][y2] != '4' & a[x2+1][y2] != '5' & a[x2+1][y2] != '6' & a[x2+1][y2] != '/'&a[x2+1][y2] != 'H'&a[x2+1][y2] != 'I'&a[x2+1][y2] != 'A'&a[x2+1][y2] != 'G'&a[x2+1][y2] != 'B'&a[x2+1][y2] != 'F'&&a[x2+1][y2] != 'E'&a[x2+1][y2] != 'D'&a[x2+1][y2] != 'C'){
      a[x2][y2] = ' ';
      x2++;
      a[x2][y2]='2';      
      d++;
      }
    }
  if(c=='w'){
    if(a[x2-1][y2] != '#' & a[x2-1][y2] != '2' & a[x2-1][y2] != '3' & a[x2-1][y2] != '4' & a[x2-1][y2] != '5' & a[x2-1][y2] != '6' & a[x2-1][y2] != '/'&a[x2-1][y2] != 'H'&a[x2-1][y2] != 'I'&a[x2-1][y2] != 'A'&a[x2-1][y2] != 'G'&a[x2-1][y2] != 'B'&a[x2-1][y2] != 'F'&&a[x2-1][y2] != 'E'&a[x2-1][y2] != 'D'&a[x2-1][y2] != 'C'){
      a[x2][y2] = ' ';
      x2--;
      a[x2][y2]='2';      
      d++;
      }            
    }
   if(c=='a'){
     if(a[x2][y2-1] != '#' & a[x2][y2-1] != '2' & a[x2][y2-1] != '3' & a[x2][y2-1] != '4' & a[x2][y2-1] != '5' & a[x2][y2-1] != '6' & a[x2][y2-1] != '/'&a[x2][y2-1] != 'H'&a[x2][y2-1] != 'I'&a[x2][y2-1] != 'A'&a[x2][y2-1] != 'G'&a[x2][y2-1] != 'B'&a[x2][y2-1] != 'F'&&a[x2][y2-1] != 'E'&a[x2][y2-1] != 'D'&a[x2][y2-1] != 'C'){
       a[x2][y2] = ' ';
       y2--;
       a[x2][y2]='2';      
       d++;
     }
   }
   if(c=='d'){
     if(a[x2][y2+1] != '#' & a[x2][y2+1] != '2' & a[x2][y2+1] != '3' & a[x2][y2+1] != '4' & a[x2][y2+1] != '5' & a[x2][y2+1] != '6' & a[x2][y2+1] != '/'&a[x2][y2+1] != 'H'&a[x2][y2+1] != 'I'&a[x2][y2+1] != 'A'&a[x2][y2+1] != 'G'&a[x2][y2+1] != 'B'&a[x2][y2+1] != 'F'&&a[x2][y2+1] != 'E'&a[x2][y2+1] != 'D'&a[x2][y2+1] != 'C'){
       a[x2][y2] = ' ';
       y2++;
       a[x2][y2]='2';      
       d++;
   }}
   if(a[x2-1][y2]=='H'||a[x2-1][y2]=='I'||a[x2-1][y2]=='A'||a[x2-1][y2]=='G'||a[x2+1][y2]=='E'||a[x2+1][y2]=='D'||a[x2+1][y2]=='C'||a[x2+1][y2]=='B'||a[x2][y2+1]=='B'||a[x2][y2-1]=='G'||a[x2][y2-1]=='F'){ 
     contador_2++;   
    if(a[x2-1][y2]=='H'||a[x2-1][y2]=='I'||a[x2-1][y2]=='A'||a[x2-1][y2]=='G'){
     printf("Está dentro de una habitación 2 así que puede sospechar.\n");
     l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x2][y2] = ' ';
     printf("Valor de antes es x es %d", x2);
     printf("\nContinuar?");
    scanf("%s", &cool);
     x2++;
     printf("Valor de despues es x es %d", x2);     
     printf("\nContinuar?");
    scanf("%s", &cool);
     a[x2][y2]='2';
     d=n;}
    if(a[x2+1][y2]=='E'||a[x2+1][y2]=='D'||a[x2+1][y2]=='B'||a[x2+1][y2]=='C'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x2][y2] = ' ';
     x2--;
     a[x2][y2]='2';
     d=n;}
    if(a[x2][y2-1]=='G'||a[x2][y2-1]=='F'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x2][y2] = ' ';
     y2++;
     a[x2][y2]='2';
     d=n;
    }    
    if(a[x2][y2+1]=='B') {
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x2][y2] = ' ';
     y2--;
     a[x2][y2]='2';
     d=n;
    }
    }
    }
    } 
 
 fflush(stdin);
   system("clear");
   for(i=0;i<=p;i++){     
     puts(a[i]);}
     if(d==n){
        if(valorUsuario==2){jugador=1;}
        else{jugador=3;}
        d=0;
        n=dado();
        //contador = nombre[3];
     }
///////////////////////////////////////////////////////////////////////////////////////////Jugador 3
  if (jugador==3){

    if(estado_jugador3[1] == "Perdedor"){
      if(estado_jugador1[1] == "Perdedor"){
          if(estado_jugador2[1] == "Perdedor"){
            if(valorUsuario>=4){
              if(estado_jugador4[1] == "Perdedor"){
                if(valorUsuario>=5){
                  if(estado_jugador5 == "Perdedor"){
                    if(valorUsuario == 6){
                      if(estado_jugador6 == "Perdedor"){
                        printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                        printf("\n Continuar?");
                        scanf("%s", &cool);
                        return main();
                      }
                      else{
                        printf("El jugador %s ya ha perdido.", estado_jugador3[0]);
                        jugador = 4;
                      }
                    }

                    else{
                      printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                      printf("\n Continuar?");
                      scanf("%s", &cool);
                      return main();
                    }

                  }
                  else{
                    printf("El jugador %s ya ha perdido.", estado_jugador3[0]);
                    jugador = 4;
                  }
                  
                }
                else{
                    printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                    printf("\n Continuar?");
                    scanf("%s", &cool);
                    return main();
                  }
              }

            else{
                    printf("El jugador %s ya ha perdido.", estado_jugador3[0]);
                    jugador = 4;
                  }

            }
            
          

          else{
                printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                printf("\n Continuar?");
                scanf("%s", &cool);
                return main();
              }
            }
        
        else{
      printf("El jugador %s ya ha perdido.", estado_jugador3[0]);
      jugador = 1;
        }
      }
    else{
      printf("El jugador %s ya ha perdido.", estado_jugador3[0]);
      jugador = 1;
    }
    }

  else{
  if(c=='s'){
    if(a[x3+1][y3] != '#' & a[x3+1][y3]  != '2' & a[x3+1][y3] != '3' & a[x3+1][y3] != '4' & a[x3+1][y3] != '5' & a[x3+1][y3] != '6' & a[x3+1][y3] != '/'&a[x3+1][y3] != 'H'&a[x3+1][y3] != 'I'&a[x3+1][y3] != 'A'&a[x3+1][y3] != 'G'&a[x3+1][y3] != 'B'&a[x3+1][y3] != 'F'&&a[x3+1][y3] != 'E'&a[x3+1][y3] != 'D'&a[x3+1][y3] != 'C'){
      a[x3][y3] = ' ';
      x3++;
      a[x3][y3]='3';      
      d++;
      }
    }
  if(c=='w'){
    if(a[x3-1][y3] != '#' & a[x3-1][y3] != '2' & a[x3-1][y3] != '3' & a[x3-1][y3] != '4' & a[x3-1][y3] != '5' & a[x3-1][y3] != '6' & a[x3-1][y3] != '/'&a[x3-1][y3] != 'H'&a[x3-1][y3] != 'I'&a[x3-1][y3] != 'A'&a[x3-1][y3] != 'G'&a[x3-1][y3] != 'B'&a[x3-1][y3] != 'F'&&a[x3-1][y3] != 'E'&a[x3-1][y3] != 'D'&a[x3-1][y3] != 'C'){
      a[x3][y3] = ' ';
      x3--;
      a[x3][y3]='3';      
      d++;
      }            
    }
   if(c=='a'){
     if(a[x3][y3-1] != '#' & a[x3][y3-1] != '2' & a[x3][y3-1] != '3' & a[x3][y3-1] != '4' & a[x3][y3-1] != '5' & a[x3][y3-1] != '6' & a[x3][y3-1] != '/'&a[x3][y3-1] != 'H'&a[x3][y3-1] != 'I'&a[x3][y3-1] != 'A'&a[x3][y3-1] != 'G'&a[x3][y3-1] != 'B'&a[x3][y3-1] != 'F'&&a[x3][y3-1] != 'E'&a[x3][y3-1] != 'D'&a[x3][y3-1] != 'C'){
       a[x3][y3] = ' ';
       y3--;
       a[x3][y3]='3';      
       d++;
     }
   }
   if(c=='d'){
     if(a[x3][y3+1] != '#' & a[x3][y3+1] != '2' & a[x3][y3+1] != '3' & a[x3][y3+1] != '4' & a[x3][y3+1] != '5' & a[x3][y3+1] != '6' & a[x3][y3+1] != '/'&a[x3][y3+1] != 'H'&a[x3][y3+1] != 'I'&a[x3][y3+1] != 'A'&a[x3][y3+1] != 'G'&a[x3][y3+1] != 'B'&a[x3][y3+1] != 'F'&&a[x3][y3+1] != 'E'&a[x3][y3+1] != 'D'&a[x3][y3+1] != 'C'){
       a[x3][y3] = ' ';
       y3++;
       a[x3][y3]='4';      
       d++;
   if(a[x3-1][y3]=='H'||a[x3-1][y3]=='I'||a[x3-1][y3]=='A'||a[x3-1][y3]=='G'||a[x3+1][y3]=='E'||a[x3+1][y3]=='D'||a[x3+1][y3]=='C'||a[x3+1][y3]=='B'||a[x3][y3+1]=='B'||a[x3][y3-1]=='G'||a[x3][y3-1]=='F'){
     contador_3++;
     if(a[x3-1][y3]=='H'||a[x3-1][y3]=='I'||a[x3-1][y3]=='A'||a[x3-1][y3]=='G'){
       contador_3++;
     printf("Está dentro de una habitación así que puede sospechar.\n");
     //l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x3][y3] = ' ';
     x3++;
     a[x3][y3]='3';
     d=n;}
    if(a[x3+1][y3]=='E'||a[x3+1][y3]=='D'||a[x3+1][y3]=='B'||a[x3+1][y3]=='C'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x3][y3] = ' ';
     x3--;
     a[x3][y3]='3';
     d=n;}
    if(a[x3][y3-1]=='G'||a[x3][y3-1]=='F'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x3][y3] = ' ';
     y3++;
     a[x3][y3]='3';
     d=n;
    }    
    if(a[x3][y3+1]=='B') {
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x3][y3] = ' ';
     y3--;
     a[x3][y3]='3';
     d=n;
    }
  }
  }
  }
  }
  }
 
 
 fflush(stdin);
   system("clear");
   for(i=0;i<=p;i++){     
     puts(a[i]);}
     if(d==n){
      if(valorUsuario==3){jugador=1;}
      else{valorUsuario=4;}
      d=0;
      n=dado();
     }
//////////////////////////////////////////////////////////////////////////////////Jugador 4
if (jugador==4){
  
  if(estado_jugador4[1] == "Perdedor"){
      if(estado_jugador1[1] == "Perdedor"){
          if(estado_jugador2[1] == "Perdedor"){
              if(estado_jugador3[1] == "Perdedor"){
                if(valorUsuario>=5){
                  if(estado_jugador5 == "Perdedor"){
                    if(valorUsuario == 6){
                      if(estado_jugador6 == "Perdedor"){
                        printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                        printf("\n Continuar?");
                        scanf("%s", &cool);
                        return main();
                      }
                      else{
                        printf("El jugador %s ya ha perdido.", estado_jugador4[0]);
                        jugador = 5;
                      }
                    }

                    else{
                      printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                      printf("\n Continuar?");
                      scanf("%s", &cool);
                      return main();
                    }

                  }
                  else{
                    printf("El jugador %s ya ha perdido.", estado_jugador4[0]);
                    jugador = 5;
                  }
                  
                }
                else{
                    printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                    printf("\n Continuar?");
                    scanf("%s", &cool);
                    return main();
                  }
              }

            else{
                    printf("El jugador %s ya ha perdido.", estado_jugador4[0]);
                    jugador = 1;
                  }

            }
            
          

          else{
                printf("El jugador %s ya ha perdido.", estado_jugador4[0]);
                jugador = 1;
              }
            }
        
        else{
      printf("El jugador %s ya ha perdido.", estado_jugador4[0]);
      jugador = 1;
        }
      }

  else{
  if(c=='s'){
    if(a[x4+1][y4] != '#' & a[x4+1][y4]  != '2' & a[x4+1][y4] != '3' & a[x4+1][y4] != '4' & a[x4+1][y4] != '5' & a[x4+1][y4] != '6' & a[x4+1][y4] != '/'&a[x4+1][y4] != 'H'&a[x4+1][y4] != 'I'&a[x4+1][y4] != 'A'&a[x4+1][y4] != 'G'&a[x4+1][y4] != 'B'&a[x4+1][y4] != 'F'&&a[x4+1][y4] != 'E'&a[x4+1][y4] != 'D'&a[x4+1][y4] != 'C'){
      a[x4][y4] = ' ';
      x4++;
      a[x4][y4]='4';      
      d++;
      }
    }
  if(c=='w'){
    if(a[x4-1][y4] != '#' & a[x4-1][y4] != '2' & a[x4-1][y4] != '3' & a[x4-1][y4] != '4' & a[x4-1][y4] != '5' & a[x4-1][y4] != '6' & a[x4-1][y4] != '/'&a[x4-1][y4] != 'H'&a[x4-1][y4] != 'I'&a[x4-1][y4] != 'A'&a[x4-1][y4] != 'G'&a[x4-1][y4] != 'B'&a[x4-1][y4] != 'F'&&a[x4-1][y4] != 'E'&a[x4-1][y4] != 'D'&a[x4-1][y4] != 'C'){
      a[x4][y4] = ' ';
      x4--;
      a[x4][y4]='4';      
      d++;
      }            
    }
   if(c=='a'){
     if(a[x4][y4-1] != '#' & a[x4][y4-1] != '2' & a[x4][y4-1] != '3' & a[x4][y4-1] != '4' & a[x4][y4-1] != '5' & a[x4][y4-1] != '6' & a[x4][y4-1] != '/'&a[x4][y4-1] != 'H'&a[x4][y4-1] != 'I'&a[x4][y4-1] != 'A'&a[x4][y4-1] != 'G'&a[x4][y4-1] != 'B'&a[x4][y4-1] != 'F'&&a[x4][y4-1] != 'E'&a[x4][y4-1] != 'D'&a[x4][y4-1] != 'C'){
       a[x4][y4] = ' ';
       y4--;
       a[x4][y4]='4';      
       d++;
     }
   }
   if(c=='d'){
     if(a[x4][y4+1] != '#' & a[x4][y4+1] != '2' & a[x4][y4+1] != '3' & a[x4][y4+1] != '4' & a[x4][y4+1] != '5' & a[x4][y4+1] != '6' & a[x4][y4+1] != '/'&a[x4][y4+1] != 'H'&a[x4][y4+1] != 'I'&a[x4][y4+1] != 'A'&a[x4][y4+1] != 'G'&a[x4][y4+1] != 'B'&a[x4][y4+1] != 'F'&&a[x4][y4+1] != 'E'&a[x4][y4+1] != 'D'&a[x4][y4+1] != 'C'){
       a[x4][y4] = ' ';
       y4++;
       a[x4][y4]='4';      
       d++;
   }}
   if(a[x4-1][y4]=='H'||a[x4-1][y4]=='I'||a[x4-1][y4]=='A'||a[x4-1][y4]=='G'||a[x4+1][y4]=='E'||a[x4+1][y4]=='D'||a[x4+1][y4]=='C'||a[x4+1][y4]=='B'||a[x4][y4+1]=='B'||a[x4][y4-1]=='G'||a[x4][y4-1]=='F'){
     contador_4++;
    if(a[x4-1][y4]=='H'||a[x4-1][y4]=='I'||a[x4-1][y4]=='A'||a[x4-1][y4]=='G'){
     printf("Está dentro de una habitación así que puede sospechar.\n");
     l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x4][y4] = ' ';
     x4++;
     a[x4][y4]='4';
     d=n;}
    if(a[x4+1][y4]=='E'||a[x4+1][y4]=='D'||a[x4+1][y4]=='B'||a[x4+1][y4]=='C'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x4][y4] = ' ';
     x4--;
     a[x4][y4]='4';
     d=n;}
    if(a[x4][y4-1]=='G'||a[x4][y4-1]=='F'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x4][y4] = ' ';
     y++;
     a[x4][y4]='4';
     d=n;
    }    
    if(a[x4][y4+1]=='B') {
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x4][y4] = ' ';
     y4--;
     a[x4][y4]='4';
     d=n;
    }}}} 
 
 fflush(stdin);
   system("clear");
   for(i=0;i<=p;i++){     
     puts(a[i]);}
     if(d==n){
       if(valorUsuario==4){jugador=1;}
       else{jugador=5;} 
       d=0;
       n=dado();  
     }
//////////////////////////////////////////////////////////////////////Jugador 5
if (jugador==5){

  if(estado_jugador5[1] == "Perdedor"){
      if(estado_jugador1[1] == "Perdedor"){
          if(estado_jugador2[1] == "Perdedor"){
              if(estado_jugador3[1] == "Perdedor"){
                  if(estado_jugador4[1] == "Perdedor"){
                    if(valorUsuario == 6){
                      if(estado_jugador6[1] == "Perdedor"){
                        printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                        printf("\n Continuar?");
                        scanf("%s", &cool);
                        return main();
                      }
                      else{
                        printf("El jugador %s ya ha perdido.", estado_jugador5[0]);
                        jugador = 6;
                      }
                    }

                    else{
                      printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                      printf("\n Continuar?");
                      scanf("%s", &cool);
                      return main();
                    }

                  }
                  else{
                    printf("El jugador %s ya ha perdido.", estado_jugador5[0]);
                    jugador = 1;
                  }
                  
                }
                else{
                    printf("El jugador %s ya ha perdido.", estado_jugador5[0]);
                    jugador = 1;
                  }
              }

            else{
                    printf("El jugador %s ya ha perdido.", estado_jugador5[0]);
                    jugador = 1;
                  }

            }
            
          

          else{
                printf("El jugador %s ya ha perdido.", estado_jugador5[0]);
                jugador = 1;
              }
            }

      
  else{
  if(c=='s'){
    if(a[x5+1][y5] != '#' & a[x5+1][y5]  != '2' & a[x5+1][y5] != '3' & a[x5+1][y5] != '4' & a[x5+1][y5] != '5' & a[x5+1][y5] != '6' & a[x5+1][y5] != '/'&a[x5+1][y5] != 'H'&a[x5+1][y5] != 'I'&a[x5+1][y5] != 'A'&a[x5+1][y5] != 'G'&a[x5+1][y5] != 'B'&a[x5+1][y5] != 'F'&&a[x5+1][y5] != 'E'&a[x5+1][y5] != 'D'&a[x5+1][y5] != 'C'){
      a[x5][y5] = ' ';
      x5++;
      a[x5][y5]='5';      
      d++;
      }
    }
  if(c=='w'){
    if(a[x5-1][y5] != '#' & a[x5-1][y5] != '2' & a[x5-1][y5] != '3' & a[x5-1][y5] != '4' & a[x5-1][y5] != '5' & a[x5-1][y5] != '6' & a[x5-1][y5] != '/'&a[x5-1][y5] != 'H'&a[x5-1][y5] != 'I'&a[x5-1][y5] != 'A'&a[x5-1][y5] != 'G'&a[x5-1][y5] != 'B'&a[x5-1][y5] != 'F'&&a[x5-1][y5] != 'E'&a[x5-1][y5] != 'D'&a[x5-1][y5] != 'C'){
      a[x5][y5] = ' ';
      x5--;
      a[x5][y5]='5';      
      d++;
      }            
    }
   if(c=='a'){
     if(a[x5][y5-1] != '#' & a[x5][y5-1] != '2' & a[x5][y5-1] != '3' & a[x5][y5-1] != '4' & a[x5][y5-1] != '5' & a[x5][y5-1] != '6' & a[x5][y5-1] != '/'&a[x5][y5-1] != 'H'&a[x5][y5-1] != 'I'&a[x5][y5-1] != 'A'&a[x5][y5-1] != 'G'&a[x5][y5-1] != 'B'&a[x5][y5-1] != 'F'&&a[x5][y5-1] != 'E'&a[x5][y5-1] != 'D'&a[x5][y5-1] != 'C'){
       a[x5][y5] = ' ';
       y5--;
       a[x5][y5]='5';      
       d++;
     }
   }
   if(c=='d'){
     if(a[x5][y5+1] != '#' & a[x5][y5+1] != '2' & a[x5][y5+1] != '3' & a[x5][y5+1] != '4' & a[x5][y5+1] != '5' & a[x5][y5+1] != '6' & a[x5][y5+1] != '/'&a[x5][y5+1] != 'H'&a[x5][y5+1] != 'I'&a[x5][y5+1] != 'A'&a[x5][y5+1] != 'G'&a[x5][y5+1] != 'B'&a[x5][y5+1] != 'F'&&a[x5][y5+1] != 'E'&a[x5][y5+1] != 'D'&a[x5][y5+1] != 'C'){
       a[x5][y5] = ' ';
       y5++;
       a[x5][y5]='5';      
       d++;
   }}
   if(a[x5-1][y5]=='H'||a[x5-1][y5]=='I'||a[x5-1][y5]=='A'||a[x5-1][y5]=='G'||a[x5+1][y5]=='E'||a[x5+1][y5]=='D'||a[x5+1][y5]=='C'||a[x5+1][y5]=='B'||a[x5][y5+1]=='B'||a[x5][y5-1]=='G'||a[x5][y5-1]=='F'){
     contador_5++;
    if(a[x5-1][y5]=='H'||a[x5-1][y5]=='I'||a[x5-1][y5]=='A'||a[x5-1][y5]=='G'){
     printf("Está dentro de una habitación así que puede sospechar.\n");
     l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x5][y5] = ' ';
     x5++;
     a[x5][y5]='5';
     d=n;}
    if(a[x5+1][y5]=='E'||a[x5+1][y5]=='D'||a[x5+1][y5]=='B'||a[x5+1][y5]=='C'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x5][y5] = ' ';
     x5--;
     a[x5][y5]='5';
     d=n;}
    if(a[x5][y5-1]=='G'||a[x5][y5-1]=='F'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x5][y5] = ' ';
     y5++;
     a[x5][y5]='5';
     d=n;
    }    
    if(a[x5][y5+1]=='B') {
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x5][y5] = ' ';
     y5--;
     a[x5][y5]='5';
     d=n;
    }}}} 
 
 fflush(stdin);
   system("clear");
   for(i=0;i<=p;i++){     
     puts(a[i]);}
     if(d==n){
       if(valorUsuario==5){jugador=1;}
       else{jugador=6;}
       d=0;
       n=dado();
     }
      
     printf("Para mover a la derecha digite (d), para mover a la izquierda (a), para mover arriba (w) y5 para mover abajo(s).\nUsted se puede mover estos espacios:");printf("%d", (n-d)); 


//////////////////////////////////////////////////////////////////////Jugador 6
if (jugador==6){

  if(estado_jugador6[1] == "Perdedor"){
      if(estado_jugador1[1] == "Perdedor"){
          if(estado_jugador2[1] == "Perdedor"){
              if(estado_jugador3[1] == "Perdedor"){
                  if(estado_jugador4[1] == "Perdedor"){
                      if(estado_jugador5[1] == "Perdedor"){
                        printf("¡TODOS PERDIERON! Suerte para la próxima ;)");
                        printf("\n Continuar?");
                        scanf("%s", &cool);
                        return main();
                      }
                      else{
                        printf("El jugador %s ya ha perdido.", estado_jugador6[0]);
                        jugador = 1;
                      }
                    }

                    else{
                      printf("El jugador %s ya ha perdido.", estado_jugador6[0]);
                    jugador = 1;
                    }

                  }
                  else{
                    printf("El jugador %s ya ha perdido.", estado_jugador6[0]);
                    jugador = 1;
                  }
                  
                }
                else{
                    printf("El jugador %s ya ha perdido.", estado_jugador6[0]);
                    jugador = 1;
                  }
              }

            else{
                    printf("El jugador %s ya ha perdido.", estado_jugador6[0]);
                    jugador = 1;
                  }

            }
  else{
  if(c=='s'){
    if(a[x6+1][y6] != '#' & a[x6+1][y6]  != '2' & a[x6+1][y6] != '3' & a[x6+1][y6] != '4' & a[x6+1][y6] != '5' & a[x6+1][y6] != '6' & a[x6+1][y6] != '/'&a[x6+1][y6] != 'H'&a[x6+1][y6] != 'I'&a[x6+1][y6] != 'A'&a[x6+1][y6] != 'G'&a[x6+1][y6] != 'B'&a[x6+1][y6] != 'F'&&a[x6+1][y6] != 'E'&a[x6+1][y6] != 'D'&a[x6+1][y6] != 'C'){
      a[x6][y6] = ' ';
      x6++;
      a[x6][y6]='6';      
      d++;
      }
    }
  if(c=='w'){
    if(a[x6-1][y6] != '#' & a[x6-1][y6] != '2' & a[x6-1][y6] != '3' & a[x6-1][y6] != '4' & a[x6-1][y6] != '5' & a[x6-1][y6] != '6' & a[x6-1][y6] != '/'&a[x6-1][y6] != 'H'&a[x6-1][y6] != 'I'&a[x6-1][y6] != 'A'&a[x6-1][y6] != 'G'&a[x6-1][y6] != 'B'&a[x6-1][y6] != 'F'&&a[x6-1][y6] != 'E'&a[x6-1][y6] != 'D'&a[x6-1][y6] != 'C'){
      a[x6][y6] = ' ';
      x6--;
      a[x6][y6]='6';      
      d++;
      }            
    }
   if(c=='a'){
     if(a[x6][y6-1] != '#' & a[x6][y6-1] != '2' & a[x6][y6-1] != '3' & a[x6][y6-1] != '4' & a[x6][y6-1] != '5' & a[x6][y6-1] != '6' & a[x6][y6-1] != '/'&a[x6][y6-1] != 'H'&a[x6][y6-1] != 'I'&a[x6][y6-1] != 'A'&a[x6][y6-1] != 'G'&a[x6][y6-1] != 'B'&a[x6][y6-1] != 'F'&&a[x6][y6-1] != 'E'&a[x6][y6-1] != 'D'&a[x6][y6-1] != 'C'){
       a[x6][y6] = ' ';
       y6--;
       a[x6][y6]='6';      
       d++;
     }
   }
   if(c=='d'){
     if(a[x6][y6+1] != '#' & a[x6][y6+1] != '2' & a[x6][y6+1] != '3' & a[x6][y6+1] != '4' & a[x6][y6+1] != '5' & a[x6][y6+1] != '6' & a[x6][y6+1] != '/'&a[x6][y6+1] != 'H'&a[x6][y6+1] != 'I'&a[x6][y6+1] != 'A'&a[x6][y6+1] != 'G'&a[x6][y6+1] != 'B'&a[x6][y6+1] != 'F'&&a[x6][y6+1] != 'E'&a[x6][y6+1] != 'D'&a[x6][y6+1] != 'C'){
       a[x6][y6] = ' ';
       y6++;
       a[x6][y6]='6';      
       d++;
   }}
   if(a[x6-1][y6]=='H'||a[x6-1][y6]=='I'||a[x6-1][y6]=='A'||a[x6-1][y6]=='G'||a[x6+1][y6]=='E'||a[x6+1][y6]=='D'||a[x6+1][y6]=='C'||a[x6+1][y6]=='B'||a[x6][y6+1]=='B'||a[x6][y6-1]=='G'||a[x6][y6-1]=='F'){
     contador_6++;
    if(a[x6-1][y6]=='H'||a[x6-1][y6]=='I'||a[x6-1][y6]=='A'||a[x6-1][y6]=='G'){
     printf("Está dentro de una habitación así que puede sospechar.\n");
     l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x6][y6] = ' ';
     x6++;
     a[x6][y6]='6';
     d=n;}
    if(a[x6+1][y6]=='E'||a[x6+1][y6]=='D'||a[x6+1][y6]=='B'||a[x6+1][y6]=='C'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x6][y6] = ' ';
     x6--;
     a[x6][y6]='6';
     d=n;}
    if(a[x6][y6-1]=='G'||a[x6][y6-1]=='F'){
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x6][y6] = ' ';
     y6++;
     a[x6][y6]='6';
     d=n;
    }    
    if(a[x6][y6+1]=='B') {
      printf("Está dentro de una habitación así que puede sospechar.\n");
      l=juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );// Se iguala juego a l para poder tener el valor de jugador 1.
     a[x6][y6] = ' ';
     y6--;
     a[x6][y6]='6';
     d=n;
    }}}} 
 
 fflush(stdin);
   system("clear");
   for(i=0;i<=p;i++){     
     puts(a[i]);}
     if(d==n){
       jugador=1 ;
       //contador = nombre[1]; 
       d=0;
       n=dado();  
     }

      // Se realiza un for para conocer el estado actual de los jugadores.
     for(w=0;w<1;w++){
       if(l==1){
         estado_jugador1[0] = nombre[l];
        estado_jugador1[1] = "Perdedor";
        }
       else if(l==2){
         estado_jugador2[0] = nombre[l];
        estado_jugador2[1] = "Perdedor";
       }
       else if(l==3){
         estado_jugador3[0] = nombre[l];
        estado_jugador3[1] = "Perdedor";
       }
       else if(l==4){
         estado_jugador4[0] = nombre[l];
        estado_jugador4[1] = "Perdedor";
       }
       else if(l==5){
         estado_jugador5[0] = nombre[l];
        estado_jugador5[1] = "Perdedor";
       }
       else{
         estado_jugador6[0] = nombre[l];
        estado_jugador6[1] = "Perdedor";
       }
     }


      
     printf("Es el turno de %s. Para mover a la derecha digite (d), para mover a la izquierda (a), para mover arriba (w) y6 para mover abajo(s).\nUsted se puede mover estos espacios: %d.\n",nombre[jugador], (n-d));
}return 0;}