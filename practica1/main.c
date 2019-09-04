#include <stdio.h>
#include <time.h>
#include "libs.h"

int main()
{
    int tam,rango,i;
    int *arreglo;
    char **lista_bin;
    int hora = time(NULL);  

    srand(hora);  
    printf("Ingresa tamano de la poblacion POBLACION: ");
    scanf("%d",&tam);
    printf("Ingresa rango de valores: ");
    scanf("%d",&rango);

    arreglo = (int *)malloc(tam*sizeof(int));
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
        binario(arreglo[i]);
        printf(" ");
    }
    
    return 0;
}

