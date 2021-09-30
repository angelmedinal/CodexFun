#include <stdio.h>
#include <stdlib.h>
#define n 4

struct player {
  char name [50];
  int points[3];
}player[n], temp;

char output[15];
FILE *out;

int main(){
    //Sorting variables
    int i,j;
    //DATA ENTRY
    printf("WRITE %d PLAYERS INFORMATION: \n", n);
    for(i=0;i<n;i++){
        printf("Write name and points: ");
        scanf("%s %d", player[i].name, player[i].points);
        printf("\n");
    }

    //BUBBLE SORT
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(*player[j].points>*player[j+1].points)
            {
                temp=player[j];
                player[j]=player[j+1];
                player[j+1] = temp;
            }
        }
    }

    //PRINTING STANDINGS
    printf("CRACKS F.C PLAYER STANDINGS: \n");
    for(i=n-1;i>=0;i--){
        printf("|%s %d\n",player[i].name,*player[i].points);
    }

    //SAVING FILE
    printf("\nWrite output file: \n");
    scanf("%s",output);

    out = fopen(output,"w");
    if(out == NULL)
    {
        printf("ERROR OPENING FILE \n");
        exit(1);
    }
    else
    {
      //PRINTING STANDINGS ON FILE
      fprintf(out, "CRACKS F.C PLAYER STANDINGS: \n");
      for(i=n-1;i>=0;i--){
          fprintf(out, "|%s %d\n",player[i].name,*player[i].points);
      }

      fflush(out);
      fclose(out);
    }
    printf("Successfully saved to file\n");
}
