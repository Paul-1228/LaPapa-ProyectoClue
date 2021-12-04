#include <stdio.h>
#include <stdlib.h>

// La funcion guardar_puntuaciones() se encarga de tomar el nombre del ganador de una partida, junto con su puntuacion y lo guarda en la lista de las 10 puntuaciones mas altas, solo si dicha puntuacion supera al menos la puntuacion en el puesto 10
void guardar_puntuaciones(int contador, char* ganador){
    FILE *fp; // el puntero FILE apunta al archivo al que se accede 
    int i, j; // variables auxiliares para ciclos
    int cont = 0; // variable auxiliar
    char nueva_puntuacion[10]; // cadena de caracteres que guarda la nueva puntuacion a ingresar
    sprintf(nueva_puntuacion, "%d", (contador*10)); // funcion que guarda en nueva_puntuacion, como una cadena de caracteres, el puntaje ingresado a traves de contador 
    char buff[20][255]; // buffer que servira para almacenar el contenido de las listas de nombre.txt y puntos.txt
    char* lista[11][2]; // array que guarda la lista de jugadores junto con sus puntuaciones

    // Se inicializan todos los campos en la lista como vacios
    for(i=0;i<11;i++){
      for(j=0;j<2;j++){
        lista[i][j] = "";
      }
    }

    fp = fopen("nombres.txt","r"); // Se abre el archivo con la lista de los nombres de los jugadores para lectura

    // Se lee el nombre del primer lugar y se guarda en la primera posicion de la lista
    fscanf(fp, "%s", buff[0]);
    lista[0][0] = buff[0];

    // Se lee el nombre del segundo lugar y se guarda en la segunda posicion de la lista
    fscanf(fp, "%s", buff[1]);
    lista[1][0] = buff[1];

    // Se lee el nombre del tercer lugar y se guarda en la tercera posicion de la lista
    fscanf(fp, "%s", buff[2]);
    lista[2][0] = buff[2];

    // Se lee el nombre del cuarto lugar y se guarda en la cuarta posicion de la lista
    fscanf(fp, "%s", buff[3]);
    lista[3][0] = buff[3];

    // Se lee el nombre del quinto lugar y se guarda en la quinta posicion de la lista
    fscanf(fp, "%s", buff[4]);
    lista[4][0] = buff[4];

    // Se lee el nombre del sexto lugar y se guarda en la sexta posicion de la lista
    fscanf(fp, "%s", buff[5]);
    lista[5][0] = buff[5];

    // Se lee el nombre del setimo lugar y se guarda en la setima posicion de la lista
    fscanf(fp, "%s", buff[6]);
    lista[6][0] = buff[6];

    // Se lee el nombre del octavo lugar y se guarda en la octava posicion de la lista
    fscanf(fp, "%s", buff[7]);
    lista[7][0] = buff[7];

    // Se lee el nombre del noveno lugar y se guarda en la novena posicion de la lista
    fscanf(fp, "%s", buff[8]);
    lista[8][0] = buff[8];

    // Se lee el nombre del decimo lugar y se guarda en la decima posicion de la lista
    fscanf(fp, "%s", buff[9]);
    lista[9][0] = buff[9];

    // Se guarda en la undecima posicion de la lista el nombre del ganador de la partida recien jugada
    lista[10][0] = ganador;
    
    fclose(fp); // Se cierra el archivo nombres.txt

    fp = fopen("puntos.txt","r"); // Se abre el archivo con la lista de los puntos de los jugadores para lectura

    // Se lee el puntaje del primer lugar y se guarda en la primera posicion de la lista
    fscanf(fp, "%s", buff[10]);
    lista[0][1] = buff[10];   

    // Se lee el puntaje del segundo lugar y se guarda en la segunda posicion de la lista
    fscanf(fp, "%s", buff[11]);
    lista[1][1] = buff[11];

    // Se lee el puntaje del tercer lugar y se guarda en la tercera posicion de la lista
    fscanf(fp, "%s", buff[12]);
    lista[2][1] = buff[12];

    // Se lee el puntaje del cuarto lugar y se guarda en la cuarta posicion de la lista
    fscanf(fp, "%s", buff[13]);
    lista[3][1] = buff[13];

    // Se lee el puntaje del quinto lugar y se guarda en la quinta posicion de la lista
    fscanf(fp, "%s", buff[14]);
    lista[4][1] = buff[14];

    // Se lee el puntaje del sexto lugar y se guarda en la sexta posicion de la lista
    fscanf(fp, "%s", buff[15]);
    lista[5][1] = buff[15];

    // Se lee el puntaje del setimo lugar y se guarda en la setima posicion de la lista
    fscanf(fp, "%s", buff[16]);
    lista[6][1] = buff[16];

    // Se lee el puntaje del octavo lugar y se guarda en la octava posicion de la lista
    fscanf(fp, "%s", buff[17]);
    lista[7][1] = buff[17];

    // Se lee el puntaje del noveno lugar y se guarda en la novena posicion de la lista
    fscanf(fp, "%s", buff[18]);
    lista[8][1] = buff[18];

    // Se lee el puntaje del decimo lugar y se guarda en la decima posicion de la lista
    fscanf(fp, "%s", buff[19]);
    lista[9][1] = buff[19];

    // Se guarda en la undecima posicion de la lista el puntaje del ganador de la partida recien jugada
    lista[10][1] = nueva_puntuacion; 

    fclose(fp); // Se cierra el archivo puntos.txt

    // Se abre el archivo puntuaciones.txt para escritura
    fp = fopen("puntuaciones.txt","w");

    // Se escribe la primera linea del texto junto con un salto de linea
    fputs("Las 10 puntuaciones más altas!\n", fp);
    fputs("\n",fp);

    // Se implementa el algoritmo de ordenamiento bubble sort para acomodar de menor a mayor los puntajes de la lista

    // Como hay 11 puntuaciones en la lista el primer for del bubble sort se ejecuta 11 veces, uno por cada puntuacion
    for (i = 0; i < 11; i++){ 
        
        // El segundo for compara una puntuacion a la vez con todas las demas y la mueve de ser necesario a la posicion que le corresponde en la lista
        for (j = 0; j < 10-i; j++){

            // Si la puntuacion analizada es mayor a una de las demas puntuaciones, ambas cambian de lugar
            if (atoi(lista[j][1]) > atoi(lista[j+1][1])){

                // Suponiendo que uno de los puntajes es x y el otro es y
                
                // Se crea una variable auxiliar temp que guarda el valor de x
                char* temp = lista[j][1];

                // Se sobreescribe x con el valor de y
                lista[j][1] = lista[j+1][1];

                // Se sobreescribe y con el valor de temp, que es el valor que tenía x antes de ser sobreescrito
                lista[j+1][1] = temp;

                // Tambien se tienen que cambiar los nombres correspondientes a dichos puntajes. Así que, suponiendo que uno de los nombres es x y el otro es y

                // La variable auxiliar temp guarda el valor de x
                temp = lista[j][0];

                // Se sobreescribe x con el valor de y
                lista[j][0] = lista[j+1][0];

                // Se sobreescribe y con el valor de temp, que es el valor que tenía x antes de ser sobreescrito
                lista[j+1][0] = temp;
                }
            }
    }

    // Se escribe el contenido de las listas ordenadas en el archivo de texto abierto: puntuaciones.txt

    // Como solo pueden haber 10 puntaciones en la lista final se ejecuta un ciclo for 10 veces, dejando por fuera la puntuacion mas baja
    for(i=0;i<10;i++){
        
        // Como cada puntuación tiene 2 elementos (nombre, puntos), se ejecuta un for 2 veces para escribir cada uno
        for(j=0;j<2;j++){
            // Si la variable auxiliar cont es par se escribe un nombre
            if(cont%2 == 0){
                fputs(lista[i][j],fp);
                fputs(": ",fp);
            }
            // Si la variable auxiliar cont es impar se escriben los puntos
            else{
                fputs(lista[i][j],fp);
                fputs("\n",fp);
            }
            cont++; // Se incrementa cont por cada elemento que se escribe
        }
    }

    fclose(fp); // Se cierra el archivo de texto puntaciones.txt

    // Se abre de nuevo el archivo puntos.txt para actualizarlo con la nueva lista de puntajes
    fp = fopen("puntos.txt","w");

    // Se escriben en puntos.txt todos los puntos guardados en orden en la lista
    fputs(lista[0][1],fp);
    fputs("\n",fp);
    fputs(lista[1][1],fp);
    fputs("\n",fp);
    fputs(lista[2][1],fp);
    fputs("\n",fp);
    fputs(lista[3][1],fp);
    fputs("\n",fp);
    fputs(lista[4][1],fp);
    fputs("\n",fp);
    fputs(lista[5][1],fp);
    fputs("\n",fp);
    fputs(lista[6][1],fp);
    fputs("\n",fp);
    fputs(lista[7][1],fp);
    fputs("\n",fp);
    fputs(lista[8][1],fp);
    fputs("\n",fp);
    fputs(lista[9][1],fp);

    fclose(fp); // Se cierra el archivo puntos.txt

    // Se abre de nuevo el archivo nombres.txt para actualizarlo con la nueva lista de nombres
    fp = fopen("nombres.txt","w");

    // Se escriben en nombres.txt todos los nombres guardados en orden en la lista
    fputs(lista[0][0],fp);
    fputs("\n",fp);
    fputs(lista[1][0],fp);
    fputs("\n",fp);
    fputs(lista[2][0],fp);
    fputs("\n",fp);
    fputs(lista[3][0],fp);
    fputs("\n",fp);
    fputs(lista[4][0],fp);
    fputs("\n",fp);
    fputs(lista[5][0],fp);
    fputs("\n",fp);
    fputs(lista[6][0],fp);
    fputs("\n",fp);
    fputs(lista[7][0],fp);
    fputs("\n",fp);
    fputs(lista[8][0],fp);
    fputs("\n",fp);
    fputs(lista[9][0],fp);

    fclose(fp); // Se cierra el archivo nombres.txt
}

// La funcion imprimir_puntuaciones() se encarga de imprimir en pantalla la lista de las 10 puntuaciones mas altas
void imprimir_puntuaciones(){
    FILE *fp; // el puntero FILE apunta al archivo al que se accede 
    char buff[255]; // buffer que servira para almacenar el contenido del archivo
    int i; // variable auxiliar para ciclos
    
    // Se abre el archivo puntaciones.txt para lectura
    fp = fopen("puntuaciones.txt","r");

    // Se recorre el contenido del archivo y al mismo tiempo se escribe en la consola su contenido, es decir, las 10 mejores puntuaciones
    for(i=0;i<12;i++){
        fgets(buff, 255, (FILE*)fp);
        printf("%s", buff);
    }
    
    fclose(fp); // Se cierra el archivo de puntaciones.txt
}