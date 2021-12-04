#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


int main_juego(){
  system("clear");

  char valorUsuarioAux;
  char cool;

    printf("Introduzca el número de jugadores (minimo 2, maximo 6):" );
    scanf("%s", &valorUsuarioAux);
    fflush(stdin);
    int valorUsuario = valorUsuarioAux - '0';
    int x=1;
    char temp;
    //pedir_nombre(valorUsuario);

     if(valorUsuario > 6 || valorUsuario < 2){
      printf( "El valor no es el indicado.\n");
      printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
      return main_juego();
      }
    char nombre[valorUsuario][2048];
    
    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
    //int cucaracha = valorUsuario;
    while(valorUsuario>=2 && valorUsuario<=6){
      printf("Introduzca nombre del jugador (No usar espacios) %d: ", valorUsuario-(valorUsuario-x));
      scanf("%c",&temp);
      scanf("%s", nombre[valorUsuario-(valorUsuario-x)]);
      x++;
      valorUsuario--;

      if (valorUsuario==1){
      printf("Introduzca nombre del jugador (No usar espacios) %d: ", valorUsuario-(valorUsuario-x));  
      scanf("%c",&temp);
	    scanf("%s", nombre[valorUsuario-(valorUsuario-x)]);
      } 
    }

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
   int i;  
   int j;  
    valorUsuario = valorUsuario+(x-valorUsuario);
    printf("Lista de jugadores:\n");
    for (i=1;i<=valorUsuario;i++){
      printf("%d >> %s \n", i, nombre[i]);
    }

  //int k = strlen(nombre[i]);

  printf("");

  printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

  
if(valorUsuario == 2){
  dos_jugadores(valorUsuario, nombre);
}

else if(valorUsuario == 3){
  tres_jugadores(valorUsuario, nombre);
}

else if(valorUsuario == 4){
  cuatro_jugadores(valorUsuario, nombre);
}

else if(valorUsuario == 5){
  cinco_jugadores(valorUsuario, nombre);
}

else{
  seis_jugadores(valorUsuario, nombre);
}
return 0;
}

