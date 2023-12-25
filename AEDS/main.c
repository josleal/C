#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int main(){
    TFila Fila1, Fila2;

    FFVazia(&Fila1);
    FFVazia(&Fila2);


    MENU(&Fila1, &Fila2);

    LiberarFila(&Fila1);
    LiberarFila(&Fila2);

    return 0;
}
