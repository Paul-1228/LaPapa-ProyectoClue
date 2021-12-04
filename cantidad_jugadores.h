#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
/*
  Descripción del código:
  Se crea una variable llamada "valorUsuario" que guarda la cantidad de jugadores asignados por el usuario, esta cantidad
  se define con el char valorUsuarioAux que este valor se escribe 
  en valorUsuario y entra a la función pedir_nombre().  
*/

 int cantidad_jugadores()
{
	char valorUsuarioAux;// Es la variable que recibe la cantidad de jugadores  
    printf("Introduzca el número de jugadores (minimo 2, maximo 6):" );
    scanf("%s", &valorUsuarioAux);//Se pide al usuario digitar el valor de jugadores
    fflush(stdin);//Se limpian los datos
    int valorUsuario = valorUsuarioAux - '0';//Se guarda valorUsuarioAux en valorUsuario
    pedir_nombre(valorUsuario);// Se llama a pedir nombre.
    return 0;
}