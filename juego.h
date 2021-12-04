#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
//#include <pedir_nombre.h>
int juego(int valorUsuario, int jugador, char nombre[valorUsuario][2048], const char *loser[1], const char *cartas[21],const char *estado_jugador1[2], const char *estado_jugador2[2], const char *estado_jugador3[2], const char *estado_jugador4[2], const char *estado_jugador5[2], const char *estado_jugador6[2], const char *jugador_1[9], const char *jugador_2[9], const char *jugador_3[9], const char *jugador_4[9], const char *jugador_5[9], const char *jugador_6[9], const char *asesinato[3], int contador_1, int contador_2, int contador_3, int contador_4, int contador_5, int contador_6 ){
  int j, i, s=-1;
  char ch;
  const char *supos[3];
  int l=0;
  j=1;
  char cool;
/////////////////////////////////////////////////////////////////////Caso para 2 jugadores
if(valorUsuario == 2){
  //jugador = j;

  printf("Turno del jugador %d >> %s. \n", jugador, nombre[jugador]);
  
//Se verifica si los jugadores ya perdieron:
  if (jugador == 1 && estado_jugador1[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador1[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;} 

  else if (jugador == 2 && estado_jugador2[1] == "Perdedor"){

    printf("El jugador %s ya ha perdido.\n", estado_jugador2[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

//Aquí comienza la dinámica de las cartas
  else{
  printf("Decisiones a tomar: digite (c) para visualizar sus cartas, digite (r) para adivinar el asesinato, digite (x) para terminar el juego o digite cualquier otra tecla para hacer una suposición.\n");
  printf("Digite la decisión a tomar:\n>>");
	scanf("%s", &ch);

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

    if (asesinato[0] == supos[0] && asesinato[1] == supos [1] && asesinato[2] == supos[2]){
      //if(asesinato[1] == supos [1]){
        //if(asesinato[2] == supos[2]){
      printf("Enhorabuena!!! Has averiguado el misterio!!!\n");
      printf("\nContinuar?");
      scanf("%s", &cool);

      if(jugador == 1){
        guardar_puntuaciones(contador_1, nombre[jugador]);
      }
      else if(jugador == 2){
        guardar_puntuaciones(contador_2, nombre[jugador]);
      }
      else if(jugador == 3){
        guardar_puntuaciones(contador_3, nombre[jugador]);
      }
      else if(jugador == 4){
        guardar_puntuaciones(contador_4, nombre[jugador]);
      }
      else if(jugador == 5){
        guardar_puntuaciones(contador_5, nombre[jugador]);
      }
      else{
        guardar_puntuaciones(contador_6, nombre[jugador]);
      }
        //}
      //}
    }
    else{
    printf("El jugador %d >> %s ha perdido.\n", jugador, nombre[jugador]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    
      if(jugador == 1){
        l=1;
        return l;
      }

      else{
        l=2;// Edita estado de jugador 2 
        return l;
	    //j=0;
      }
      }
    }
  


  else if(ch == 'c'){
    printf("Sus cartas son:\n");

    if(jugador == 1){
      for (i=0; i<9; i++){
        printf("%s\n", jugador_1[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
    }
    else{
      for (i=0; i<9; i++){
        printf("%s\n", jugador_2[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
    }
    juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );//Para no regresar a mapa
  }

  else if(ch == 'x'){
  printf("Se terminó el juego.\n");
  return main();
  }

	else {
		printf("Ingrese la suposición. Los elementos saldrán en el siguiente orden: Arma, lugar y persona.\n");
		printf("A continuación se listan las armas:\n");
		for(i=0; i<6; i++){
			printf("%d >> %s\n", i, cartas[i]);
		}
    //printf("El valor de s es: %d\n",s);

		while(s<0 || s>5){
    printf("Seleccione el número de la arma deseada:\n>>");
    scanf("%d", &s);
    }
		supos[0] = cartas[s];
		printf("%s\n", supos[0]);

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
  
    printf("Objetos mostrados por los otros jugadores:\n");

  if (jugador == 1){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_2[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
  scanf("%s", &cool);
  }
  
  else {
  for(i=0; i<9;i++){
    if(supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
  scanf("%s", &cool);
	//j=0;
  }
  return 0;
  }}}

/////////////////////////////////////////////////////////////////////Caso para 3 jugadores

else if(valorUsuario == 3){


  printf("Turno del jugador %d >> %s. \n", jugador, nombre[jugador]);

  if (jugador == 1 && estado_jugador1[1] == "Perdedor"){
     printf("El jugador %s ya ha perdido.\n", estado_jugador1[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
    
  }

  else if (jugador == 2 && estado_jugador2[1] == "Perdedor"){
     printf("El jugador %s ya ha perdido.\n", estado_jugador2[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
    
  }

  else if (jugador == 3 && estado_jugador3[1] == "Perdedor"){
     printf("El jugador %s ya ha perdido.\n", estado_jugador3[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }



  else{
  printf("Decisiones a tomar: digite (c) para visualizar sus cartas, digite (r) para adivinar el asesinato, digite (x) para terminar el juego o digite cualquier otra tecla para hacer una suposición.\n");
  printf("Digite la decisión a tomar:\n>>");
	scanf("%s", &ch);

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

    if (asesinato[0] == supos[0] && asesinato[1] == supos [1] && asesinato[2] == supos[2]){
      printf("Enhorabuena!!! Has averiguado el misterio!!!\n");
      printf("\nContinuar?");
      scanf("%s", &cool);
      return main();
    }
    else{
    printf("El jugador %d >> %s ha perdido.\n", jugador, nombre[jugador]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    

      if(jugador == 1){
        l=1;
        return l;
      }
      else if(jugador == 2){
        l=2;
        return l;
      }
      else{
        l=3;
        return l;
	j=0;
      }
    }
  }

  else if(ch == 'c'){
    printf("Sus cartas son:\n");
    if(jugador == 1){
      for (i=0; i<6; i++){
        printf("%s\n", jugador_1[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=0;
    }
    else if(jugador == 2){
      for (i=0; i<6; i++){
        printf("%s\n", jugador_2[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=1;
    }
    else{
      for (i=0; i<6; i++){
        printf("%s\n", jugador_3[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=2;
    }
    juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );
  }

  else if(ch == 'x'){
  printf("Se terminó el juego.\n");
  return main();
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
  printf("\nContinuar?");
    scanf("%s", &cool);
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
  printf("\nContinuar?");
    scanf("%s", &cool);
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
	printf("\nContinuar?");
    scanf("%s", &cool);
  }
	}
  }
}

/////////////////////////////////////////////////////////////////////Caso para 4 jugadores

else if(valorUsuario == 4){
  

  printf("Turno del jugador %d >> %s. \n", jugador, nombre[jugador]);

  if (jugador == 1 && estado_jugador1[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador1[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 2 && estado_jugador2[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador2[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 3 && estado_jugador3[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador3[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 4 && estado_jugador4[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador4[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }


  else{
  printf("Decisiones a tomar: digite (c) para visualizar sus cartas, digite (r) para adivinar el asesinato, digite (x) para terminar el juego o digite cualquier otra tecla para hacer una suposición.\n");
  printf("Digite la decisión a tomar:\n>>");
	scanf("%s", &ch);

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

    if (asesinato[0] == supos[0] && asesinato[1] == supos [1] && asesinato[2] == supos[2]){
      printf("Enhorabuena!!! Has averiguado el misterio!!!\n");
      printf("\nContinuar?");
      scanf("%s", &cool);
      return main();
    }
    else{
    printf("El jugador %d >> %s ha perdido.\n", jugador, nombre[jugador]);
    printf("\nContinuar?");
    scanf("%s", &cool);
      if(jugador == 1){
        l=1;
        return l;
      }
      else if(jugador == 2){
        l=2;
        return l;
      }
      else if(jugador == 3){
        l=3;
        return l;
      }
      else{
        l=4;
        return l;
	j=0;
      }
    }
  }

  else if(ch == 'c'){
    printf("Sus cartas son:\n");
    if(jugador == 1){
      for (i=0; i<5; i++){
        printf("%s\n", jugador_1[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=0;
    }
    else if(jugador == 2){
      for (i=0; i<5; i++){
        printf("%s\n", jugador_2[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=1;
    }
    else if(jugador == 3){
      for (i=0; i<4; i++){
        printf("%s\n", jugador_3[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=2;
    }
    else{
      for (i=0; i<4; i++){
        printf("%s\n", jugador_4[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=3;
    }
    juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );
  }

  else if(ch == 'x'){
  printf("Se terminó el juego.\n");
  return main();
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
  
    printf("Objetos mostrados por los otros jugadores:\n");

  if (jugador == 1){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_4[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_4[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_2[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }
  
  else if (jugador == 2){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_3[i] || supos[0]==jugador_4[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_3[i] || supos[1]==jugador_4[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else if (jugador == 3){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_4[i] ||	supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_4[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_4[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else{
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] ||	supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] ||	supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_3[i]) 
    printf("%s\n", supos[2]);
  }
	printf("\nContinuar?");
    scanf("%s", &cool);
  }
	}
  }
}

////////////////////////////////////////////////////////////////////Caso para 5 jugadores
else if(valorUsuario == 5){


  printf("Turno del jugador %d >> %s. \n", jugador, nombre[jugador]);

  if (jugador == 1 && estado_jugador1[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador1[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 2 && estado_jugador2[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador2[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 3 && estado_jugador3[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador3[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 4 && estado_jugador4[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador4[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 5 && estado_jugador5[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador5[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }


  else{
  printf("Decisiones a tomar: digite (c) para visualizar sus cartas, digite (r) para adivinar el asesinato, digite (x) para terminar el juego o digite cualquier otra tecla para hacer una suposición.\n");
  printf("Digite la decisión a tomar:\n>>");
	scanf("%s", &ch);

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

    if (asesinato[0] == supos[0] && asesinato[1] == supos [1] && asesinato[2] == supos[2]){
      printf("Enhorabuena!!! Has averiguado el misterio!!!\n");
      printf("\nContinuar?");
      scanf("%s", &cool);
      return main();
    }
    else{
    printf("El jugador %d >> %s ha perdido.\n", jugador, nombre[jugador]);
    printf("\nContinuar?");
    scanf("%s", &cool);

      if(jugador == 1){
       l=1;
        return l;
      }
      else if(jugador == 2){
        l=2;
        return l;
      }
      else if(jugador == 3){
        l=3;
        return l;
      }
      else if(jugador == 4){
        l=4;
        return l;
      }
      else{
        l=5;
        return l;
	//j=0;
      }
    }
  }

  else if(ch == 'c'){
    printf("Sus cartas son:\n");
    if(jugador == 1){
      for (i=0; i<4; i++){
        printf("%s\n", jugador_1[i]);
        printf("\nContinuar?");
        scanf("%s", &cool);
      }
      j=0;
    }
    else if(jugador == 2){
      for (i=0; i<4; i++){
        printf("%s\n", jugador_2[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=1;
    }
    else if(jugador == 3){
      for (i=0; i<4; i++){
        printf("%s\n", jugador_3[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=2;
    }
    else if(jugador == 4){
      for (i=0; i<3; i++){
        printf("%s\n", jugador_4[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=3;
    }
    else{
      for (i=0; i<3; i++){
        printf("%s\n", jugador_5[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=4;
    }
    juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );
  }

  else if(ch == 'x'){
  printf("Se terminó el juego.\n");
  return main();
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
  
    printf("Objetos mostrados por los otros jugadores:\n");

  if (jugador == 1){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_4[i] || supos[0]==jugador_5[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_4[i] || supos[1]==jugador_5[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_2[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i] || supos[2]==jugador_5[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }
  
  else if (jugador == 2){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_3[i] || supos[0]==jugador_4[i] || supos[0]==jugador_5[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_3[i] || supos[1]==jugador_4[i] || supos[1]==jugador_5[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i] || supos[2]==jugador_5[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else if (jugador == 3){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_4[i] || supos[0]==jugador_5[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_4[i] || supos[1]==jugador_5[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_4[i] || supos[2]==jugador_5[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else if (jugador == 4){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_5[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_5[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_3[i] || supos[2]==jugador_5[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else{
    for(i=0; i<9;i++){
      if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_4[i] || supos[0]==jugador_1[i]) 
        printf("%s\n", supos[0]);
    }
    for(i=0; i<9;i++){
      if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_4[i] || supos[1]==jugador_1[i]) 
        printf("%s\n", supos[1]);
    }
    for(i=0; i<9;i++){
      if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i]) 
        printf("%s\n", supos[2]);
    }
	printf("\nContinuar?");
    scanf("%s", &cool);
  }
	}
  }
}


////////////////////////////////////////////////////////////////////Caso para 6 jugadores

else{
// Sección de división de cartas a los jugadores

  printf("Turno del jugador %d >> %s. \n", jugador, nombre[jugador]);

  if (jugador == 1 && estado_jugador1[1] == "Perdedor"){
   printf("El jugador %s ya ha perdido.\n", estado_jugador1[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 2 && estado_jugador2[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador2[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 3 && estado_jugador3[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador3[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 4 && estado_jugador4[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador4[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 5 && estado_jugador5[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador5[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else if (jugador == 6 && estado_jugador6[1] == "Perdedor"){
    printf("El jugador %s ya ha perdido.\n", estado_jugador6[0]);
    printf("\nContinuar?");
    scanf("%s", &cool);
    return 0;
  }

  else{
  printf("Decisiones a tomar: digite (c) para visualizar sus cartas, digite (r) para adivinar el asesinato, digite (x) para terminar el juego o digite cualquier otra tecla para hacer una suposición.\n");
  printf("Digite la decisión a tomar:\n>>");
	scanf("%s", &ch);

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

    if (asesinato[0] == supos[0] && asesinato[1] == supos [1] && asesinato[2] == supos[2]){
      printf("Enhorabuena!!! Has averiguado el misterio!!!\n");
      printf("\nContinuar?");
      scanf("%s", &cool);
      return main();
    }
    else{
    printf("El jugador %d >> %s ha perdido.\n", jugador, nombre[jugador]);
    printf("\nContinuar?");
    scanf("%s", &cool);
      if(jugador == 1){
        l=1;
        return l;
      }
      else if(jugador == 2){
        l=2;
        return l;
      }
      else if(jugador == 3){
        l=3;
        return l;
      }
      else if(jugador == 4){
        l=4;
        return l;
      }
      else if(jugador == 5){
        l=5;
        return l;
      }
      else{
        l=6;
        return l;
      }
    }
    
  }

  else if(ch == 'c'){
    printf("Sus cartas son:\n");
    if(jugador == 1){
      for (i=0; i<3; i++){
        printf("%s\n", jugador_1[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=0;
    }
    else if(jugador == 2){
      for (i=0; i<3; i++){
        printf("%s\n", jugador_2[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=1;
    }
    else if(jugador == 3){
      for (i=0; i<3; i++){
        printf("%s\n", jugador_3[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=2;
    }
    else if(jugador == 4){
      for (i=0; i<3; i++){
        printf("%s\n", jugador_4[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=3;
    }
    else if(jugador == 5){
      for (i=0; i<3; i++){
        printf("%s\n", jugador_5[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=4;
    }
    else{
      for (i=0; i<3; i++){
        printf("%s\n", jugador_6[i]);
      }
      printf("\nContinuar?");
      scanf("%s", &cool);
      j=5;
    }
    juego(valorUsuario,jugador, nombre, loser, cartas, estado_jugador1,estado_jugador2, estado_jugador3, estado_jugador4, estado_jugador5,estado_jugador6, jugador_1, jugador_2, jugador_3,jugador_4,jugador_5,jugador_6,asesinato, contador_1, contador_2, contador_3, contador_4, contador_5, contador_6 );
  }

  else if(ch == 'x'){
    printf("Se terminó el juego.\n");
    return main();
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
  
    printf("Objetos mostrados por los otros jugadores:\n");

  if (jugador == 1){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_4[i] || supos[0]==jugador_5[i] || supos[0]==jugador_6[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_4[i] || supos[1]==jugador_5[i] || supos[1]==jugador_6[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_2[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i] || supos[2]==jugador_5[i] || supos[2]==jugador_6[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }
  
  else if (jugador == 2){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_3[i] || supos[0]==jugador_4[i] || supos[0]==jugador_5[i] || supos[0]==jugador_6[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_3[i] || supos[1]==jugador_4[i] || supos[1]==jugador_5[i] || supos[1]==jugador_6[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_3[i] || supos[2]==jugador_4[i] || supos[2]==jugador_5[i] || supos[2]==jugador_6[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else if (jugador == 3){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_4[i] || supos[0]==jugador_5[i] || supos[0]==jugador_6[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_4[i] || supos[1]==jugador_5[i] || supos[1]==jugador_6[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_4[i] || supos[2]==jugador_5[i] || supos[2]==jugador_6[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else if (jugador == 4){
  for(i=0; i<9;i++){
    if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_5[i] || supos[0]==jugador_6[i] || supos[0]==jugador_1[i]) 
    printf("%s\n", supos[0]);
  }
  for(i=0; i<9;i++){
    if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_5[i] || supos[1]==jugador_6[i] || supos[1]==jugador_1[i]) 
    printf("%s\n", supos[1]);
  }
  for(i=0; i<9;i++){
    if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_3[i] || supos[2]==jugador_5[i] || supos[2]==jugador_6[i]) 
    printf("%s\n", supos[2]);
  }
  printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else if (jugador == 5){
    for(i=0; i<9;i++){
      if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_4[i] ||    supos[0]==jugador_6[i] || supos[0]==jugador_1[i]) 
        printf("%s\n", supos[0]);
    }
    for(i=0; i<9;i++){
      if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_4[i] ||     supos[1]==jugador_6[i] || supos[1]==jugador_1[i]) 
        printf("%s\n", supos[1]);
    }
    for(i=0; i<9;i++){
      if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_3[i] ||    supos[2]==jugador_4[i] || supos[2]==jugador_6[i]) 
        printf("%s\n", supos[2]);
    }
    printf("\nContinuar?");
    scanf("%s", &cool);
  }

  else{
    for(i=0; i<9;i++){
      if(supos[0]==jugador_2[i] || supos[0]==jugador_3[i] || supos[0]==jugador_4[i] ||      supos[0]==jugador_5[i] || supos[0]==jugador_1[i]) 
          printf("%s\n", supos[0]);
    }
    for(i=0; i<9;i++){
      if(supos[1]==jugador_2[i] || supos[1]==jugador_3[i] || supos[1]==jugador_4[i] ||    supos[1]==jugador_5[i] || supos[1]==jugador_1[i]) 
        printf("%s\n", supos[1]);
    }
    for(i=0; i<9;i++){
      if(supos[2]==jugador_1[i] || supos[2]==jugador_2[i] || supos[2]==jugador_3[i] ||    supos[2]==jugador_4[i] || supos[2]==jugador_5[i]) 
        printf("%s\n", supos[2]);
    }
    printf("\nContinuar?");
    scanf("%s", &cool);
  }
	}
  }
}
//l=0;
return 0;}