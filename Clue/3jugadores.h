#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int tres_jugadores(int valorUsuario, char nombre[valorUsuario][2048]){
  const char *cartas[21]={"Puñal","Candelabro","Pistola","Cuerda","Tubería de plomo","Llave inglesa","Biblioteca","Sala de Billar","Estudio","Dormitorio","Terraza","Sala","Comedor","Cocina","Salon de Baile","Escarlata","Moradillo","Mostaza","Verdi","Azulino","Blanco"}; 
  const char *estado_jugador1[2];
  const char *estado_jugador2[2];
  const char *estado_jugador3[2];
  const char *estado_jugador4[2];
  const char *estado_jugador5[2];
  const char *estado_jugador6[2];
  int guardar_cartas[21]; //Para esta parte hay que hacer un for que vaya ingresando las cartas repartidas de los jugadores.
  const char *jugador_1[9];
  const char *jugador_2[9];
  const char *jugador_3[9];
  const char *jugador_4[9];
  const char *jugador_5[9];
  const char *jugador_6[9];
  const char *asesinato[3];
  int k_1=0, k_2=0, k_3=0, k_4=0, k_5=0, k_6=0, jugador, complete;
  char ch, cool;
  const char *loser[1] = {"Perdedor"};
  const char *supos[3];
  int i, j, s=-1, w;
  int contador_1=0;
  int contador_2=0;
  int contador_3=0;
  int contador_4=0;
  int contador_5=0;
  int contador_6=0;    

  srand(time(NULL));

// Sección de elementos para ganar el juego

guardar_cartas[0] = rand() % 6;
asesinato[0] = cartas[guardar_cartas[0]];

guardar_cartas[1] = rand() % 9+6;
asesinato[1] = cartas[guardar_cartas[1]];

guardar_cartas[2] = rand() % 6+15;
asesinato[2] = cartas[guardar_cartas[2]];

for(i=0; i<3; i++){
  printf("%s\n", asesinato[i]);
}

printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

for(i=3; i<9; i++){
    complete = 0;
    //jugador = rand() % 6+1;
    //printf("Elemento a jugador: %d \n", jugador);

    //if(jugador == 1){
	    while (!complete) {
	      guardar_cartas[i] = rand() % 21;
        jugador_1[k_1] = cartas[guardar_cartas[i]];
	      complete = 1;

		    for (j = 0; j < i; j++) {
        		if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      		}
	    } 
  
      
      //printf("Valor de k_1 %d\n",k_1);
	    //printf("%s\n", jugador_1[k_1]);
      k_1++;
    //}
  }

/* printf("\n Jugador 1:");

for(i=0; i<6; i++){
  printf("%s\n", jugador_1[i]);
} */

  for(i=9; i<15; i++){
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
      
      //printf("Valor de k_2 %d\n",k_2);
	    //printf("%s\n", jugador_2[k_2]);
      k_2++;
  }

 /*  printf("\n Jugador 2:");

for(i=0; i<6; i++){
  printf("%s\n", jugador_2[i]);
}
   */
  for(i=15; i<21; i++){
    complete = 0;
    //else if(jugador == 3){
	    while (!complete) {
	    guardar_cartas[i] = rand() % 21;
      jugador_3[k_3] = cartas[guardar_cartas[i]];
	    complete = 1;

		  for (j = 0; j < i; j++) {
        	if (guardar_cartas[i] == guardar_cartas[j]) complete = 0;
      	}
	    }
      
      //printf("Valor de k_3 %d\n",k_3); 
	    //printf("%s\n", jugador_3[k_3]);
      k_3++;
  }

  /* printf("\n Jugador 3:");

for(i=0; i<6; i++){
  printf("%s\n", jugador_3[i]);
} */

for(j=1; j<4; j++){

  jugador = j;

  for(w=0;w<1;w++){
      if(jugador == 1){contador_1++;}
      else if(jugador == 2){contador_2++;}
      else{contador_3++;}
    }

  printf("Turno del jugador %d >> %s. \n", jugador, nombre[j]);

  if (jugador == 1 && estado_jugador1[1] == loser[0]){
    if (estado_jugador1[1] == loser[0] && estado_jugador2[1] == loser[0] && estado_jugador3[1] == loser[0]){
    printf("Todos los jugadores han perdido!!! Buena suerte para la próxima!!!");
    j=7;
    }
    else{
    printf("El jugador %s ya ha perdido.\n", estado_jugador1[0]);
    }

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
  }

  else if (jugador == 2 && estado_jugador2[1] == loser[0]){
    if (estado_jugador1[1] == loser[0] && estado_jugador2[1] == loser[0] && estado_jugador3[1] == loser[0]){
    printf("Todos los jugadores han perdido!!! Buena suerte para la próxima!!!");
    j=7;
    }
    else{
    printf("El jugador %s ya ha perdido.\n", estado_jugador2[0]);
    }

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
  }

  else if (jugador == 3 && estado_jugador3[1] == loser[0]){
    if (estado_jugador1[1] == loser[0] && estado_jugador2[1] == loser[0] && estado_jugador3[1] == loser[0]){
    printf("Todos los jugadores han perdido!!! Buena suerte para la próxima!!!");
    j=7;
    }
    else{
    printf("El jugador %s ya ha perdido.\n", estado_jugador3[0]);
    j=0;
    }

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
  }

  else{
  printf("Decisiones a tomar: digite (c) para visualizar sus cartas, digite (r) para adivinar el asesinato, digite (x) para terminar el juego o digite cualquier otra tecla para hacer una suposición.\n");
  printf("Digite la decisión a tomar:\n>>");
	scanf("%s", &ch);
  system("clear");

  if (ch == 'r'){

    printf("Ingrese los elementos del asesinato.\n");

		printf("A continuación se listan las armas:\n");
    
		for(i=0; i<6; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}

    while(s<0 || s>5){
    printf("Seleccione el número de la arma deseada:\n>>");
    scanf("%d", &s);
    }
		supos[0] = cartas[s];
		printf("%s\n", supos[0]);

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

		printf("A continuación se listan los lugares:\n");
		for(i=6; i<15; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}
    while(s<6 || s>14){
    printf("Seleccione el número del lugar deseado:\n>>");
		scanf("%d", &s);
    }
		supos[1] = cartas[s];
		printf("%s\n", supos[1]);

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

    
    printf("A continuación se listan los personajes:\n");
		for(i=15; i<21; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}

    while(s<15 || s>20){
    printf("Seleccione el número del personaje deseado:\n>>");
		scanf("%d", &s);
    }
		supos[2] = cartas[s];
		printf("%s\n", supos[2]);

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

    if (asesinato[0] == supos[0] && asesinato[1] == supos [1] && asesinato[2] == supos[2]){
      //if(asesinato[1] == supos [1]){
        //if(asesinato[2] == supos[2]){
      printf("Enhorabuena!!! Has averiguado el misterio!!!\n");
      printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

      if(jugador == 1){
        guardar_puntuaciones(contador_1, nombre[jugador]);
        j=7;
      }
      else if(jugador == 2){
        guardar_puntuaciones(contador_2, nombre[jugador]);
        j=7;
      }
      else if(jugador == 3){
        guardar_puntuaciones(contador_3, nombre[jugador]);
        j=7;
      }
      else if(jugador == 4){
        guardar_puntuaciones(contador_4, nombre[jugador]);
        j=7;
      }
      else if(jugador == 5){
        guardar_puntuaciones(contador_5, nombre[jugador]);
        j=7;
      }
      else{
        guardar_puntuaciones(contador_6, nombre[jugador]);
        j=7;
      }

    }
    else{
    printf("El jugador %d >> %s ha perdido.\n", jugador, nombre[jugador]);
      if(jugador == 1){
        estado_jugador1[0] = nombre[jugador];
        estado_jugador1[1] = "Perdedor";
      }
      else if(jugador == 2){
        estado_jugador2[0] = nombre[jugador];
        estado_jugador2[1] = "Perdedor";
      }
      else{
        estado_jugador3[0] = nombre[jugador];
        estado_jugador3[1] = "Perdedor";
	j=0;
      }

      printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
    }
  }

  else if(ch == 'c'){
    printf("Sus cartas son:\n");
    if(jugador == 1){
      for (i=0; i<6; i++){
        printf("%s\n", jugador_1[i]);
      }
      j=0;
    }
    else if(jugador == 2){
      for (i=0; i<6; i++){
        printf("%s\n", jugador_2[i]);
      }
      j=1;
    }
    else{
      for (i=0; i<6; i++){
        printf("%s\n", jugador_3[i]);
      }
      j=2;
    }

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
  }

  else if(ch == 'x'){
  printf("Se terminó el juego.\n");
  j=7;
  printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
  }

	else {
		printf("Ingrese la suposición. Los elementos saldrán en el siguiente orden: Arma, lugar y persona.\n");
		printf("A continuación se listan las armas:\n");
		for(i=0; i<6; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}
		    while(s<0 || s>5){
    printf("Seleccione el número de la arma deseada:\n>>");
    scanf("%d", &s);
    }
		supos[0] = cartas[s];
		printf("%s\n", supos[0]);

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

		printf("A continuación se listan los lugares:\n");
		for(i=6; i<15; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}
    while(s<6 || s>14){
    printf("Seleccione el número del lugar deseado:\n>>");
		scanf("%d", &s);
    }
		supos[1] = cartas[s];
		printf("%s\n", supos[1]);

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");

    
    printf("A continuación se listan los personajes:\n");
		for(i=15; i<21; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}

    while(s<15 || s>20){
    printf("Seleccione el número del personaje deseado:\n>>");
		scanf("%d", &s);
    }
		supos[2] = cartas[s];
		printf("%s\n", supos[2]);

    printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
  
    printf("Objetos mostrados por los otros jugadores:\n");

  if (jugador == 1){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_2[i] || supos[2]==jugador_3[i]) 
    printf("%s\n", supos[2]);
  }
  }
  
  else if (jugador == 2){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_3[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_3[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_3[i]) 
    printf("%s\n", supos[2]);
  }
  }

  else{
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i]) 
    printf("%s\n", supos[2]);
  }
	j=0;
  }

  printf("\nContinuar?");
      scanf("%s", &cool);
      system("clear");
	}
  }
}
return 0;
}

