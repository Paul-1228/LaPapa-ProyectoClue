#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
/*
  Descripción del código:
  Se crea un "if" que verifica que el número de jugadores asignado por el usuario sea de acuerdo a la cantidad aceptada por el programa ( entre 2 a 6 jugadores). En caso de digitar un número incorrecto se le pide al usuario que proceda a digitar una cantidad de jugadores válida. Se crea un array de tipo "char" llamado "nombre" que presenta la cantidad de filas de acuerdo al numero de jugadores y con un total de 10 columnas que representa el máximo número de caracteres por nombre de jugador. 
*/
int pedir_nombre(int valorUsuario){

    int x=1;// Variable auxiliar para obtener digito del jugador
    char temp;// Variable que ingresa nombres de los jugadores

//Si se marca una opción menor a 2 y mayor a 6:
     if(valorUsuario > 6 || valorUsuario < 2){
      printf( "El valor no es el indicado.\n");
      cantidad_jugadores();
      }
// Se crea una matriz donde ingresa valorUsuario y el tamaño que puede tener el nombre.
    char nombre[valorUsuario][2048];//valorUsuario define las filas y 2048 las columnas.
    
    //Si valorUsuario es mayor o igual a 2 y menor o igual a 6. valorUsuario-(valorUsuario-x)
    //es básicamente para que se vaya guardando los datos del jugador 1 al último.
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
   int i;  
    valorUsuario = valorUsuario+(x-valorUsuario);// Se tiene el último jugador
    printf("Lista de jugadores:\n");
    //Recorre toda la matriz para imprimir todos los nombres de los jugadores.
    for (i=1;i<=valorUsuario;i++){
      printf("%d >> %s \n", i, nombre[i]);
    }
  printf("");
  //////////////////////////////////////////////////////////////////////////////////////////////////Termina pedir nombre
  mapa(valorUsuario,nombre);
  
  return 0;

  }