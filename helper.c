//
// Created by mauri on 11/09/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helper.h"

char * plustxt(char * titulo) {

    strcat(titulo, ".txt");
    return titulo;
}

void extraer(lista* lista) {

    char titulo[30];
    char presente[30];
    char pasado[30];
    char perfecto[30];
    char definicion[30];

    printf("ingrese el nombre del archivo a extraer\n");
    scanf("%s", titulo);

    FILE * archivo=fopen(plustxt(titulo),"r");

    int cantidad;
    printf("cuantas palabras desea repasar?\n");
    scanf("%d", &cantidad);
    for (int i = 0; i < cantidad; ++i) {
        fscanf(archivo, "%s %s %s %s", presente, pasado, perfecto, definicion);

        apilar(lista, newnodo(presente, pasado, perfecto, definicion));
    }

    fclose(archivo);

}

lista * newlist(){

    lista * nueva = (lista *) malloc(sizeof (lista));

    if(nueva==NULL){
        printf("\nNo se ha podido asignar memoria a la nueva lista\n");
        exit(-1);
    }
    nueva->pri=NULL;
    nueva->cant=0;
    nueva->ult=NULL;

    return nueva;
}


nodo * newnodo(char * presente, char * pasado,char * perfecto,char * definicion){

    nodo * nuevo= (nodo *) malloc(sizeof (nodo));

    if(nuevo==NULL){
        printf("\nNo posee memoria suficiente, para crear un nuevo nodo\n");
        exit(-1);
    }

    strcpy(nuevo->presente,presente);
    strcpy(nuevo->pasado,pasado);
    strcpy(nuevo->perfecto,perfecto);
    strcpy(nuevo->definicion,definicion);
    nuevo->bandera=0;
    nuevo->sig=NULL;
    nuevo->ant=NULL;

    return nuevo;
}
void apilar (lista * listaTrabajo, nodo * nodoActual){

    nodo * auxiliar = listaTrabajo->pri;

    if(auxiliar==NULL){
        listaTrabajo->pri=nodoActual;
        listaTrabajo->cant++;
        listaTrabajo->ult=nodoActual;
        return;
    }

    nodoActual->sig=auxiliar;
    listaTrabajo->pri=nodoActual;
    listaTrabajo->cant++;
    auxiliar->ant=nodoActual;

}

void imprimir(lista * listaTrabajo) {

    nodo * aux= listaTrabajo->pri;

    if(aux==NULL){
        printf("la lista esta vacia\n");
    }

    printf("presente\t\tpasado\t\tperfecto\t\t hay 72 verbos\n");

    int columna=1;
    int pasadas=0;
    char respuesta[50];
    do {
        for (; aux != NULL; aux = aux->sig) {
            pasadas++;
            if(columna==1 && aux->bandera<columna){
                pasadas=0;
                printf("ingrese el presente de verbo %s\n", aux->definicion);
                scanf("%s", respuesta);
                for (int indice = 0; respuesta[indice] != '\0'; ++indice){
                    respuesta[indice] = toupper(respuesta[indice]);
                }
                if(strcmp(respuesta,aux->presente)==0){
                    printf("PERFECTO\n");
                    aux->bandera++;}else{                       //porque desp de esta linea salta a la 113?
                    printf("la respuesta correcta era: %s\n", aux->presente);}
            }else if(columna==2 && aux->bandera<columna){
                pasadas=0;
                printf("Ingrese el pasado de %s\n", aux->definicion);
                scanf("%s", respuesta);
                for (int indice = 0; respuesta[indice] != '\0'; ++indice){
                    respuesta[indice] = toupper(respuesta[indice]);
                }
                if(strcmp(respuesta,aux->pasado)==0){
                    printf("PERFECTO\n");
                    aux->bandera++;
                }else{
                    printf("la respuesta correcta era: %s\n", aux->pasado);}
            }else  if(columna==3 && aux->bandera<columna){
                pasadas=0;
                printf("Ingrese el presente perfecto de %s\n", aux->definicion);
                scanf("%s", respuesta);
                for (int indice = 0; respuesta[indice] != '\0'; ++indice){
                    respuesta[indice] = toupper(respuesta[indice]);
                }
                if(strcmp(respuesta,aux->perfecto)==0){
                    printf("PERFECTO\n");
                    aux->bandera++;
                    ;}else{//despues de imprimir "PERFECTO", y aumentar la bandera en una posicion, salta una vez mas al if del reglon 128. pq?
                    printf("la respuesta correcta era: %s\n", aux->perfecto);}
            }
            if(aux->sig==NULL && columna<4){aux= listaTrabajo->pri;}
            if(listaTrabajo->cant==pasadas){columna++;pasadas=0;}}
    }while(columna<4);
    printf("salio del programa");
}