#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#define _TRUE 1
#define _FALSE 0
#define _DIMEN_INT 5

void LimpiaPantalla();
void Salir();
short ExisteArchivo(char *);
int TamArch(char *);
short IsEnTero(char *);
short ComparaStr(char *, char *, int, int);

#endif // RECURSOS_H_INCLUDED
