#ifndef ADN_H_INCLUDED
#define ADN_H_INCLUDED

#define _STR_ADENINA "A"
#define _STR_TIMINA "T"
#define _STR_CITOSINA "C"
#define _STR_GUANINA "G"
#define _STR_NADA "X"

#define _ADENINA 'A'
#define _TIMINA 'T'
#define _CITOSINA 'C'
#define _GUANINA 'G'
#define _NADA 'X'

#define _RUTA "C:\\adn\\"
//#define _RUTA "archivos/"
#define _MAX_RUTA 7
//#define _MAX_RUTA 9
#define _MAX_NOMBRE_ARCHIVO 220
#define _MAX_TAM_MAT 20

void VolverMenu(char *, char *);
void ImprimirADN(char **, char **, int, char *);
void ADNPantalla();
char ** LlenaMTRX(int);
void ADNArchivo();
short ValidaArch(char *);
char ** BuscaArchivo(char *, int *, char *);
short ComparaADN(char *vADN, char *vADN2, int);
char * pasoVec(char **, int);

#endif // ADN_H_INCLUDED
