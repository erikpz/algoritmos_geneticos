#include <stdio.h>
#include <time.h>
#include "libs.h"

int main()
{
    int tam,rango,i,j,pot;
    int *arreglo;
    char **lista_bin;
    char *bin;
    int hora = time(NULL);  

    srand(hora);  
    printf("Programa para generar una poblacion ");
    printf("de N numeros aleatorios\ny ordenarlos ");
    printf("ascendentemente para posteriormente convertirlos a ");
    printf("binario.");
    printf("\n\nIngresa tamano de la poblacion POBLACION: ");
    scanf("%d",&tam);
    printf("Ingresa rango de valores: ");
    scanf("%d",&rango);

    arreglo = (int *)malloc(tam*sizeof(int));
    lista_bin = (char **)malloc(tam*sizeof(char *));

    for(i=0;i<tam;i++){
        *(arreglo+i) = rand()%(rango+1);
    }

    printf("Lista Desordenada \n");
    for(i=0;i<tam;i++){
        printf("%d ",*(arreglo+i));
    }

    quicksort(arreglo,tam);

    printf("\nLista Ordenada \n");
    for(i=0;i<tam;i++){
        printf("%d ",*(arreglo+i));
    }

    printf("\nBinarios\n");
    for(i=0;i<tam;i++){
        j=0;
        pot = 1;
        if(arreglo[i]==0){
            j = 1;
        }else{
            while(pot<=arreglo[i]){
            j++;
            pot = pow(2,j);
            }
        }
        lista_bin[i] = (char *)malloc((j)*sizeof(char));
        bin = binario(arreglo[i]);
        strncpy(lista_bin[i],bin,j);
        lista_bin[i][j] = '\0';
    }

    for(i=0;i<tam;i++){
        printf("%s ",lista_bin[i]);
    }
    return 0;
}

