#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursos.h"
#include "menu.h"
#include "adn.h"

void MenuPrincipal(int);

int main(){
    MenuPrincipal(_FALSE);

    return 0;
}

void MenuPrincipal(int op){
    char sel;

    InicioPrograma();
    Titulo("Menu Principal", '*', 5);

    if(op){
        printf("\nOpcion no permitida\n\n");
    }

    Menu("1", "Ingresar ADN");
    Menu("2", "Buscar ADN en archivo");
    Menu("3", "Salir");

    printf("Opcion: ");
    scanf("%s", &sel);

    if(sel == '1'){
        LimpiaPantalla();
        ADNPantalla();
    }else if(sel == '2'){
        LimpiaPantalla();
        ADNArchivo();
    }else if(sel == '3'){
        Salir();
    }else{
        LimpiaPantalla();
        MenuPrincipal(_TRUE);
    }
}
