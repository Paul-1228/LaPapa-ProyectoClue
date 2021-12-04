#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int dado(){
  int dado[11]={2,3,4,5,6,7,8,9,10,11,12};
  int guardar_dado[1];
  int valor_dado[1];

  srand(time(NULL));

guardar_dado[0] = rand() %11;
valor_dado[0]=dado[guardar_dado[0]];
printf("Para mover a la derecha digite (d), para mover a la izquierda (a), para mover arriba (w) y para mover abajo(s).\n Usted se puede mover estos espacios:");printf("%d\n", valor_dado[0]);  
return valor_dado[0];
}