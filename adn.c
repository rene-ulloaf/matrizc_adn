#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "adn.h"
#include "menu.h"
#include "recursos.h"

void VolverMenu(char *msg, char *fx){
    char vm;

    InicioPrograma();
    printf("\n\n");
    printf("%s\n\n %cDesea volver al Menu Principal? [S/N]. " ,msg ,168);
    scanf("%s", &vm);

    if(vm == 'S' || vm == 's'){
        main();
    }else{
        if(strcmp(fx,"archivo") == 0){
            ADNArchivo();
        }else{
            ADNPantalla();
        }
    }
}

void ImprimirADN(char **a1, char **a2, int dim, char *fx){
    char vm;
    int i,j,k;

    LimpiaPantalla();
    InicioPrograma();

    printf("1%c ADN",248);
    for(k=0;k<(dim+2);k++){
        printf(" ");
    }
    printf("2%c ADN\n",248);

    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("%c ",a1[i][j]);
        }

        for(k=0;k<(dim+2);k++){
            printf(" ");
        }

        for(j=0;j<dim;j++){
            printf("%c ",a2[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");

    if(ComparaADN(pasoVec(a1,dim), pasoVec(a2,dim), dim)){
        printf("Adn's son iguales");
    }else{
        printf("Adn's no son iguales");
    }

    printf("\n\n %cDesea volver al Menu Principal? [S/N]. ",168);
    scanf("%s", &vm);

    if(vm == 'S' || vm == 's'){
        main();
    }else{
        if(strcmp(fx,"archivo") == 0){
            ADNArchivo();
        }else{
            ADNPantalla();
        }
    }
}


void ADNPantalla(){
    char **mADN1=NULL,**mADN2=NULL,*dimen;
    int dim;

    dimen = (char *) malloc(_DIMEN_INT * sizeof(char));

    InicioPrograma();

    printf("Ingrese la dimension de la matriz (m%cximo %i): ",160 ,_MAX_TAM_MAT);
    scanf("%s", dimen);

    if(IsEnTero(dimen)){
        dim = atoi(dimen);

        if(dim > 1 && dim <= _MAX_TAM_MAT){
            mADN1 = LlenaMTRX(dim);

            if(mADN1 != NULL){
                mADN2 = LlenaMTRX(dim);

                if(mADN2 != NULL){
                    ImprimirADN(mADN1,mADN2,dim,"pantalla");
                }
            }
        }else{
            VolverMenu("la dimension de la matriz debe ser mayor a 1 y hasta 20","pantalla");
        }
    }else{
        VolverMenu("Debe ingresar solo numeros.","pantalla");
    }

    mADN1=NULL;
    mADN2=NULL;
    dimen=NULL;

    free(mADN1);
    free(mADN2);
    free(dimen);
}

char ** LlenaMTRX(int d){
    int i,f=0,c=0;
    char **m=NULL,el;
    int x,y;
    short intentos=3,err=_FALSE;

    m = (char **) malloc(d * sizeof(char *));
    for(i=0;i<d;i++){
        m[i] = (char *) malloc(d * sizeof(char));
    }

    for(x=0;x<d;x++){
        for(y=0;y<d;y++){
            m[x][y] = _NADA;
        }
    }

    while(f < d){
        if((f == 0) || (f == (d-1)) || (c == 0) || (c = (d-1))){
            if(intentos < 1){
                VolverMenu("Ha excedido los intentos, vuelva a intentarlo despues.","pantalla");
                m=NULL;
                break;
            }

            fflush(stdin);

            LimpiaPantalla();
            InicioPrograma();

            if(err){
                printf("\nElemento desconocido. le quedan %d intentos\n\n", intentos);
                err=_FALSE;
            }

            for(x=0;x<d;x++){
                for(y=0;y<d;y++){
                    if(f == x && c == y){
                        printf(" _ ");
                    }else{
                        printf(" %c ",m[x][y]);
                    }
                }

                printf("\n");
            }

            printf("\n[A]denina - [T]imina - [G]uanina - [C]itocina");
            printf("\nIngrese elemento: ");
            scanf("%c", &el);

            el = toupper(el);

            if(el == _ADENINA || el == _TIMINA || el == _CITOSINA || el == _GUANINA){
                m[f][c] = el;

                c++;
                if(c >= d){
                    f++;
                    c=0;
                }
            }else{
                intentos--;
                err =_TRUE;
            }
        }else{
            c++;
            if(c >= d){
                f++;
                c=0;
            }
        }
    }

    return m;
}

void ADNArchivo(){
    char *arch=NULL, *msgResp=NULL;
    char direccion1[_MAX_RUTA + _MAX_NOMBRE_ARCHIVO]={""},direccion2[_MAX_RUTA + _MAX_NOMBRE_ARCHIVO]={""};
    char **mtrxADN1=NULL, **mtrxADN2;
    int dimen1=0,dimen2=0;

    arch = (char *) malloc(sizeof(char) * _MAX_NOMBRE_ARCHIVO);
    msgResp = (char *) malloc(sizeof(char) * 50);
    msgResp = "";

    InicioPrograma();

    printf("Ingrese nombre del 1%c archivo (maximo 250 caracteres).\n", 96);
    scanf("%s", arch);

    strcat(direccion1,"");
    strcat(direccion1,_RUTA);
    strcat(direccion1,arch);
    strcpy(arch,"");

    if(ValidaArch(direccion1)){
        printf("\nIngrese nombre del 2%c archivo (maximo 250 caracteres).\n", 96);
        scanf("%s", arch);

        strcat(direccion2,"");
        strcat(direccion2,_RUTA);
        strcat(direccion2,arch);

        if(ValidaArch(direccion2)){
            mtrxADN1 = BuscaArchivo(direccion1, &dimen1, msgResp);

            if(strlen(msgResp) != 0){
                VolverMenu(msgResp,"archivo");
            }else{
                mtrxADN2 = BuscaArchivo(direccion2, &dimen2, msgResp);

                if(strlen(msgResp) != 0){
                    VolverMenu(msgResp,"archivo");
                }else{
                    if(dimen1 == dimen2){
                        ImprimirADN(mtrxADN1,mtrxADN2,dimen1,"archivo");
                    }else{
                        VolverMenu("Adn tienen distintas dimensiones","archivo");
                    }
                }
            }
        }else{
            arch = NULL;
            free(arch);
            strcat(direccion1,"");
            strcat(direccion2,"");
            VolverMenu("Archivo 2 no existe","archivo");
        }
    }else{
        arch = NULL;
        free(arch);
        strcat(direccion1,"");
        strcat(direccion2,"");
        VolverMenu("Archivo 1 no existe","archivo");
    }

    msgResp = NULL;
    free(msgResp);
}

short ValidaArch(char *dir){
    int ret = _TRUE;

    if((strlen(dir)-_MAX_RUTA) > _MAX_NOMBRE_ARCHIVO){
        VolverMenu("Nombre de Archivo muy extenso.","archivo");
    }

    if(!ExisteArchivo(dir)){
        VolverMenu("Archivo no existe","archivo");
    }

    if(TamArch(dir) > 1024){
        VolverMenu("el tamano del archivo no debe ser superior a 1 KB.","archivo");
    }

    return ret;
}

char ** BuscaArchivo(char *dir, int *dim, char *msg){
    char sl,aux[1], ADN[1], **mADN=NULL;
    int col=0,fil=0,x=1,y=1;
    FILE *archivo;

    archivo = fopen(dir,"r");

    if(archivo != NULL){
        while(!feof(archivo) && fread(aux,1,1,archivo)){
            fseek(archivo,-1, SEEK_CUR);

            sl = fgetc(archivo);

            if(sl == '\t'){
                y++;
            }

            if(sl == '\n'){
                x++;

                if(col == 0){
                    col = y;
                }else{
                    if(col != y){
                        msg = "Error de formato";
                        break;
                    }
                }

                y=1;
            }
        }

        fil = x;

        if(col != fil){
            msg = "Formato no valido";
        }else{
            *dim = fil;
            rewind(archivo);

            mADN = (char **) malloc(fil * sizeof(char *));
            for(x=0;x<fil;x++){
                mADN[x] = (char *) malloc(col * sizeof(char));
            }

            x=0;
            y=0;

            while(!feof(archivo) && fread(aux,1,1,archivo)){
                fseek(archivo,-1, SEEK_CUR);
                fscanf(archivo,"%s",ADN);

                if(!strcmp(ADN,_STR_ADENINA)){
                    mADN[x][y] = _ADENINA;
                }else if(!strcmp(ADN,_STR_TIMINA)){
                    mADN[x][y] = _TIMINA;
                }else if(!strcmp(ADN,_STR_CITOSINA)){
                    mADN[x][y] = _CITOSINA;
                }else if(!strcmp(ADN,_STR_GUANINA)){
                    mADN[x][y] = _GUANINA;
                }else if(!strcmp(ADN,_STR_NADA)){
                    mADN[x][y] = _NADA;
                }else{
                    msg = "Existen Datos erroneos en el archivo.";
                    break;
                }

                y++;

                if(y == col){
                    y=0;
                    x++;
                }
            }

            fflush(archivo);
            fclose(archivo);
        }
    }else{
        msg = "Error de lectura del Archivo";
    }

    return mADN;
}

short ComparaADN(char *vADN1, char *vADN2, int dim){
    short ret=_FALSE;
    int i,cur=0,dimTot = ((dim*dim)-((dim-2)*(dim-2)));
    char *vADN=NULL,*vAUX=NULL;

    vADN = (char *) malloc(dimTot * sizeof(char));
    vAUX = (char *) malloc(dimTot * sizeof(char));

    strcpy(vADN,vADN2);

    while(cur < dimTot){
         if(ComparaStr(vADN,vADN1,0,dimTot)){
            ret = _TRUE;
            break;
        }else{
            vAUX[0] = vADN[(dimTot-1)];

            for(i=1;i<dimTot;i++){
                vAUX[i] = vADN[(i-1)];
            }

            strcpy(vADN,vAUX);
        }

        cur++;
    }

    vADN = NULL;
    vAUX = NULL;

    free(vADN);
    free(vAUX);

    return ret;
}

char * pasoVec(char **mtrx, int dim){
    short i,j=0;
    int dimTot = ((dim*dim)-((dim-2)*(dim-2)));
    char *vec=NULL;

    vec = (char *) malloc(dimTot * sizeof(char));

    for(i=0;i<dim;i++){
        vec[j] = mtrx[0][i];
        j++;
    }

    for(i=1;i<dim;i++){
        vec[j] = mtrx[i][(dim-1)];
        j++;
    }

    for(i=(dim-2);i>=0;i--){
        vec[j] = mtrx[(dim-1)][i];
        j++;
    }

    for(i=(dim-2);i>0;i--){
        vec[j] = mtrx[i][0];
        j++;
    }

    return vec;
}
