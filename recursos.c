#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursos.h"

void LimpiaPantalla(){
    /*int i=0;

    for(i=1;i<40;i++){
        printf("\n");
    }*/
    system("cls");
}

void Salir(){
    LimpiaPantalla();
}

short ExisteArchivo(char *direccion){
    int ret;
    FILE *archivo;

    archivo = fopen(direccion,"r");

    if(archivo == NULL){
        ret = _FALSE;
    }else{
        ret = _TRUE;
    }

    fflush(archivo);
    if(ret){
        fclose(archivo);
    }

    return ret;
}

int TamArch(char *direccion){
    int tam;
    FILE *fich;

    fich = fopen(direccion,"r");

    fseek(fich, 0L, SEEK_END);
    tam = ftell(fich);
    fclose(fich);

    return tam;
}

short IsEnTero(char *n){
    int i,cant = strlen(n);
    short ret=_TRUE;

    for(i=0;i<cant;i++){
        if(n[i]<48 || n[i]>57){
            ret = _FALSE;
            break;
        }
    }

    return ret;
}

short ComparaStr(char *str1, char *str2, int desde, int hasta){
    short ret=_TRUE;
    int i;

    for(i=desde;i<hasta;i++){
        if(str1[i] != str2[i]){
            ret = _FALSE;
            break;
        }
    }

    return ret;
}
