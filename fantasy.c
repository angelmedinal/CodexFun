#include <stdio.h>
#include <stdlib.h>
#define n 4

struct player {
  char nombre [50];
  int puntos[3];
}jugador[n], temp;

char salida[15];
FILE *out;

int main(){
    //Variables para el ordenamiento
    int i,j;
    //INGRESO DE DATOS
    printf("INGRESE INFORMACION DE %d JUGADORES: \n", n);
    for(i=0;i<n;i++){
        printf("Ingrese nombre y puntos: ");
        scanf("%s %d", jugador[i].nombre, jugador[i].puntos);
        printf("\n");
    }

    //BUBBLE SORT
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(*jugador[j].puntos>*jugador[j+1].puntos)
            {
                temp=jugador[j];
                jugador[j]=jugador[j+1];
                jugador[j+1] = temp;
            }
        }
    }

    //IMPRESION DE LA CLASIFICACIÓN
    printf("CLASIFICACIÓN JUGADORES DEL TRONCOS F.C: \n");
    for(i=n-1;i>=0;i--){
        printf("|%s %d\n",jugador[i].nombre,*jugador[i].puntos);
    }

    //GUARDAR EN EL ARCHIVO
    printf("\nDeme el nombre del archivo de salida \n");
    scanf("%s",salida);

    out = fopen(salida,"w");
    if(out == NULL)
    {
        printf("ERROR EN LA APERTURA \n");
        exit(1);
    }
    else
    {
      //IMPRIMIR LA CLASIFICACIÓN
      fprintf(out, "CLASIFICACIÓN JUGADORES DEL TRONCOS F.C: \n");
      for(i=n-1;i>=0;i--){
          fprintf(out, "|%s %d\n",jugador[i].nombre,*jugador[i].puntos);
      }

      fflush(out);
      fclose(out);
    }
    printf("Se ha guardado correctamente en el archivo\n");
}
