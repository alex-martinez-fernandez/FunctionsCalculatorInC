#ifndef FORMAS_GEOMETRICAS_H
#define FORMAS_GEOMETRICAS_H

#define MAX_FORMAS 10

typedef enum {CIRCULO, RECTANGULO} TipoForma;

typedef struct {
    TipoForma tipo;
    union {
        struct { double x, y; double radio; } circulo;
        struct { double x, y; double ancho, alto; } rectangulo;
    } datos;
} Forma;

extern Forma memoria[MAX_FORMAS];
extern int num_formas;

// Funciones de calculo
extern void areaPerimetrocirculo(float radio, float * perimetrocirculo, float*  areacirculo);
void areaPerimetrorectangulo(float ancho, float alto, float * arearectangulo, float * perimetrorectangulo);
void distancia_entre_coordenadas(double x1, double y1, double x2, double y2);

// Funciones de gestion
void introducir_forma();
void eliminar_forma();  //
#endif

