//
// Created by mauri on 11/09/22.
//

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

typedef struct nodo{

    char presente[50];
    char pasado[50];
    char perfecto[50];
    char definicion[50];
    int bandera;

    struct nodo * sig;
    struct nodo * ant;

}nodo;

typedef struct lista{

    int cant;
    nodo * pri;
    nodo * ult;

}lista;

nodo * newnodo(char * presente, char * pasado,char * perfecto,char * definicion);
void newfile();
void readfile();
void cargar();
char * plustxt(char*);
void extraer(lista*);
lista * newlist();
void apilar (lista *, nodo *);
void imprimir(lista*);
#endif //FILE_HELPER_H
