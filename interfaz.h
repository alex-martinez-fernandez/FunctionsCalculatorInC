#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "formas_geometricas.h"
#include "EntradadelUsuraio.h"

int printmenu();
void solicitarDatosCirculo(Circulo * c);
void solicitarDatosRectangulo(Rectangulo*r );
void solicitarPuntosCoordenadas(double* x1, double* y1, double* x2, double* y2);

Forma* solicitarNumeroForma (int i);
int forma_correcta_indice_circulo(int i);
int forma_correcta_indice_rectangulo(int i);
int solicitar_entero();

void mostrar_forma();
void mostrar_forma_por_indice(int i);
void mostrar_todas_formas();

#endif



