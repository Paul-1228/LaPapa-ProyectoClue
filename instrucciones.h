#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int instrucciones(){
    char opcion;    
        // Imprimir menu.
        puts("======Instrucciones de CLUE======");
        printf("Aquí iran las instrucciones (se va a enumerar con letras).\n a). El número de pasos que puede caminar dentro del mapa, es el número que salga de los dos dados.\n b)Para culpar o sospechar de un jugador, solo puede hacerlo dentro de un cuarto.\n c)Si usted tiene una de las cartas que otro jugador sospecha, aunque sea una sola, tiene que enseñarla obligatoriamente. de no hacerlo, el juego insistirá en que lo haga.\n d)Si pone algo diferente a las opciones disponibles en el momento de culpar o sospechar, automaticamente queda descalificado (muere en el juego).\n e)Si solo queda un jugador o un jugador culpa al asesino correcto, el juego tomará este jugador como el ganador.\n");
        puts("1-Regresar al menu principal.\n");
        printf(">> ");
        scanf("%s", &opcion);        
        if (opcion == '1'){
        }
        else{
          puts("Entrada invalida.\n"); 
          return (instrucciones());          
        }
    return 0;
}
