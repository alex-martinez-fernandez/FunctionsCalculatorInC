
// funciones.h archivo de cabecera

#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_FORMAS 10  // Maximo de formas que se pueden almacenar que son 10

typedef enum {CIRCULO, RECTANGULO} TipoForma;

// Estructura para representar una forma (circulo o rectangulo)
typedef struct {
    TipoForma tipo;
    union {
        struct { double x, y; double radio; } circulo;
        struct { double x, y; double ancho, alto; } rectangulo;
    } datos;
} Forma;

// Declaracion de variables globales (array de formas + contador)
extern Forma memoria[MAX_FORMAS];
extern int num_formas;



// Funciones de menu y calculo
int printmenu();
void circulo(double radio);
void rectangulo(double ancho, double alto);
void distancia_entre_coordenadas(double x1, double y1, double x2, double y2);

// Funciones de gestion de formas
void introducir_forma();
void eliminar_forma();
void mostrar_forma();
void mostrar_forma_por_indice(int i);
void mostrar_todas_formas();

#endif
