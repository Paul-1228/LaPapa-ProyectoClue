#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "puntos.h"
#include "2jugadores.h"
#include "3jugadores.h"
#include "4jugadores.h"
#include "5jugadores.h"
#include "6jugadores.h"
#include "union_jugadores.h"
#include "juego.h"
#include "instrucciones.h"
#include "dado.h"
#include "mapa.h"
#include "cantidad_jugadores.h"
#include "pedir_nombre.h"

/*Esta es la función principal de nuestro juego. Es el menú que se va a utilizar para poder iniciar el juego, leer
instrucciones, ver las puntuaciones y salir del juego.
Como se observa todo está dentro de un do whiel, entonces se ejecutan todas las opciones, con el scanf y opción se
elige la opción del menú a la que se quiere acceder y luego entra al while que se utiliza para que cuando termine 
de digitar opción no tome en cuenta el enter dado para que ejecute el valor ingersado.
*/
int main(){
    char opcion;// Variable donde se va a ingresar el valor del Usuario.
    do{
        // Imprimir menu.
        puts("======Bienvenidos a CLUE======");
        puts("===Menu de opciones===");
        puts("1-Iniciar nueva partida.\n");
        puts("2-Ver puntuaciones mas altas.\n");
        puts("3-Instrucciones.\n");
        puts("4-Iniciar version sin mapa.\n");
        puts("5-Salir del juego.\n");
        printf(">> ");
        
        scanf("%s", &opcion);//El usuario puede  digitar el valor de la opción del menú a la que quiere entrar.  
        
        if (opcion=='1'){
          cantidad_jugadores(); 
        }
          
           
        else if (opcion=='2'){
            imprimir_puntuaciones();
            //printf("Se abrira el archivo con las puntuaciones\n");
        }
        else if (opcion=='3'){
            instrucciones();
        }
        else if (opcion=='4'){
          main_juego();
        }
        else if (opcion=='5'){
          break;
        }
        else{
          puts("Entrada invalida.\n"); 
          return (main());
        }
    } while((opcion = getchar()) == '\n' && opcion != EOF);//Evita que se lea el entre como dígito.
      return 0;
}