#include "libs.h"

char binario(int num){
    int numero,pot,i,j,res,coc;
    char *binario;
    i = 0;
    pot = pow(2,i);
    numero = num;
    if(numero==0){
        binario = (char *)malloc(sizeof(char));
        binario[0]='0';
        printf("%c ", binario[0]);
    }else{
        while(pot<=numero){
            i++;
            pot = pow(2,i);
        }
        j=i-1;
        binario = (char *)malloc(i*sizeof(char));
        do{
            coc = numero/2;
            res = numero%2;
            if(res==1){
                binario[j] = '1';
            }else{
                binario[j] = '0';
            }
            j--;
            numero = coc;
        }while(coc>=2);
        binario[0] = '1';
        for(j=0;j<i;j++){
        printf("%c", binario[j]);
        }
    }
    return binario;
}

void quicksort(int lista[],int n){
    qs(lista,0,n-1);
}

void qs(int lista[],int limite_izq,int limite_der){
    int izq,der,temporal,pivote;

    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2];

    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;

        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}

}

/*
char binario(int numero){
    int numero,pot,i,j,res,coc;
    char *binario;
    i = 0;
    pot = pow(2,i);
    printf("Ingresa numero: ");
    scanf("%d",&numero);
    if(numero==0){
        binario = (char *)malloc(sizeof(char));
        binario[0]='0';
        printf("%c ", binario[0]);
    }else{
        while(pot<=numero){
            i++;
            pot = pow(2,i);
        }
        j=i-1;
        binario = (char *)malloc(i*sizeof(char));
        do{
            coc = numero/2;
            res = numero%2;
            if(res==1){
                binario[j] = '1';
            }else{
                binario[j] = '0';
            }
            j--;
            numero = coc;
        }while(coc>=2);
        binario[0] = '1';
        for(j=0;j<i;j++){
        printf("%c", binario[j]);
        }
    }
    return binario;
}
*/