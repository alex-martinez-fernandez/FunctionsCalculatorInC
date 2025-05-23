#ifndef FORMAS_GEOMETRICAS_H
#define FORMAS_GEOMETRICAS_H

#define MAX_FORMAS 10
#define PI 3.141592653589793

typedef struct {
    float x;
    float y;
} Punto;

typedef struct {
    Punto centro;
    float radio;
} Circulo;

typedef struct {
    Punto vertice_inferior_izquierdo;
    float ancho;
    float alto;
} Rectangulo;

typedef struct {
    int tipo;
    union {
        Circulo circulo;
        Rectangulo rectangulo;
    } datos;
} Forma;

extern Forma memoria[MAX_FORMAS];
extern int num_formas;

void areaPerimetrocirculo(float radio, float *perimetro, float *area);
void areaPerimetrorectangulo(float ancho, float alto, float *area, float *perimetro);
void distancia_entre_coordenadas(double x1, double y1, double x2, double y2);
void introducir_forma();
void eliminar_forma();

#endif



