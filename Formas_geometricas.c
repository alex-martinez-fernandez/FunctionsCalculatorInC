#include <stdio.h>
#include <math.h>
#include "formas_geometricas.h"
#include "EntradadelUsuraio.h"

Forma memoria[MAX_FORMAS];
int num_formas = 0;

double areacirculo (double radio){
    double area = PI * radio * radio;
    return area;
}

double perimetrocirculo(double radio){
    double perimetro = 2 * PI * radio;
    return perimetro;
}

double arearectangulo(double ancho,double alto){
    double area = ancho * alto;
    return area;
}

double perimetrorectangulo(double ancho,double alto){
    double perimetro = 2 * (ancho + alto);
    return perimetro;
}

double distancia_entre_coordenadas(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double resultado = sqrt(dx * dx + dy * dy);

    return resultado;
}

int colisionCirculos(Circulo c1, Circulo c2) {
    double distancia = distancia_entre_coordenadas(c1.centro.x, c1.centro.y, c2.centro.x, c2.centro.y);
    double sumaRadio = c1.radio + c2.radio;
    return distancia <= sumaRadio;
}

int colisionCirculoRectangulo(Circulo c, Rectangulo r) {
    double distanciaX = c.centro.x - MAX(r.vertice_superior_izquierdo.y, MIN(c.centro.x, r.vertice_superior_izquierdo.x + r.ancho));
    double distanciaY = c.centro.y - MAX(r.vertice_superior_izquierdo.y, MIN(c.centro.x, r.vertice_superior_izquierdo.y + r.alto));
    return (distanciaX * distanciaX + distanciaY * distanciaY) < (c.radio * c.radio);
}

int colisionRectangulos(Rectangulo r1, Rectangulo r2) {
    return !  ( r1.vertice_superior_izquierdo.x+ r1.ancho <= r2.vertice_superior_izquierdo.x
          || r2.vertice_superior_izquierdo.x + r2.ancho <= r1.vertice_superior_izquierdo.x
          || r2.vertice_superior_izquierdo.y + r2.alto <= r1.vertice_superior_izquierdo.y
          || r1.vertice_superior_izquierdo.y + r1.alto <= r2.vertice_superior_izquierdo.y);
}




