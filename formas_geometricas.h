#ifndef FORMAS_GEOMETRICAS_H
#define FORMAS_GEOMETRICAS_H

#define MAX_FORMAS 10
#define PI 3.141592653589793

#define MAX_FORMAS 10

#define MIN(a,b) (((a)<(b))?(a):(b)) //stackoverflow
#define MAX(a,b) (((a)>(b))?(a):(b)) //stackoverflow

typedef struct {
    double x;
    double y;
} Punto;

typedef struct {
    Punto centro;
    double radio;
} Circulo;

typedef struct {
    Punto vertice_superior_izquierdo;
    double ancho;
    double alto;
} Rectangulo;

typedef enum {
    CIRCULO, RECTANGULO
} TIPO;

typedef struct {
    TIPO tipo;
    union {
        Circulo circulo;
        Rectangulo rectangulo;
    } datos;
} Forma;

extern Forma memoria[MAX_FORMAS];
extern int num_formas;

double areacirculo (double radio);
double perimetrocirculo(double radio);
double arearectangulo(double ancho,double alto);
double perimetrorectangulo(double ancho,double alto);
double distancia_entre_coordenadas(double x1, double y1, double x2, double y2);

int colisionCirculos(Circulo c1, Circulo c2);
int colisionCirculoRectangulo(Circulo c, Rectangulo r);
int colisionRectangulos(Rectangulo r1, Rectangulo r2);
void casoColision();


void introducir_forma();
void eliminar_forma();

#endif





