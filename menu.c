#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "recursos.h"

void InicioPrograma(){
    LimpiaPantalla();
    printf("%s version: %s", _TITULO, _VERSION);
    printf("\n\n\n");
}

void Titulo(char *texto, char simbolo, int cantSimbolo){
    int i;

    for(i=0;i<cantSimbolo;i++){
        printf("%c", simbolo);
    }

    printf("\t%s\t",texto);

    for(i=0;i<cantSimbolo;i++){
        printf("%c", simbolo);
    }

    printf("\n\n");
}

void Menu(char *numeracion, char *nombre){
    printf("[%s] %s", numeracion, nombre);
    printf("\n");
}
