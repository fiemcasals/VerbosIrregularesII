#include "helper.h"

int main() {

    lista *listaTrabajo = newlist();

    listaTrabajo->cant=0;

    extraer(listaTrabajo);

    imprimir(listaTrabajo);

    return 0;
}
