#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "formas_geometricas.h"
#include "EntradadelUsuraio.h"


int printmenu() {
    int opcion = 0;

    printf("\nPor favor introducir una opcion:\n");
    printf("1) Calculo del area y perimetro de un circulo cuyos datos entra\n");
    printf("2) Calculo del area y perimetro de un rectangulo cuyos datos entra\n");
    printf("3) Calculo del area y perimetro de una circulo introducido en memoria\n");
    printf("4) Calculo del area y perimetro de un rectangulo introducido por memoria\n");
    printf("5) Distancia entre dos puntos\n");
    printf("6) Colision entre dos formas\n");
    printf("7) Introducir nueva forma\n");
    printf("8) Eliminar forma\n");
    printf("9) Mostrar forma\n");
    printf("10) Mostrar todas las formas\n");
    printf("11) Salir\n");

    do {
        printf("La opcion tiene que estar entre 1 y 11: ");
        scanf("%i", &opcion);
    } while (opcion < 1 || opcion > 11);

    return opcion;
}

 void solicitarDatosCirculo(Circulo * c) {

    double r= entrada_radio_usuario();
    if (r!= -1){
        double x= entrada_centrox_usuario();
        if(x!=-1){
           double y= entrada_centroy_usuario();
           if (y!=-1){
                c->centro = (Punto){x,y};
                c->radio = r;
           }
        }

    }
}

void solicitarDatosRectangulo(Rectangulo*r ) {

    double h= entrada_altura_usuario();
    if (h!= -1){
        double a= entrada_ancho_usuario();
        if (h!=-1){
            double x= entrada_verticex_usuario();
            if(x!=-1){
                double y= entrada_verticey_usuario();
                if(y!=-1){
                    r->alto=h;
                    r-> ancho=a;
                    r->vertice_superior_izquierdo=(Punto){x,y};
                }
            }
        }
    }
}


void solicitarPuntosCoordenadas(double *x1, double *y1, double *x2, double *y2) {
    printf("\nPor favor introduzca el valor x de la primera coordenada: ");
    scanf("%lf", x1);
    printf("\nPor favor introduzca el valor y de la primera coordenada: ");
    scanf("%lf", y1);
    printf("\nPor favor introduzca el valor x de la segunda coordenada: ");
    scanf("%lf", x2);
    printf("\nPor favor introduzca el valor y de la segunda coordenada: ");
    scanf("%lf", y2);
}


void mostrar_forma() {
    int i;
        printf("Introduce numero de forma (0 a %d): ", num_formas - 1);
            scanf("%d", &i);
                mostrar_forma_por_indice(i);
}

Forma* solicitarNumeroForma (int i){
    if (i < 0 || i >= num_formas) {
        printf("[ERROR] Indice fuera de rango\n");
            return NULL;
    }
    return &memoria[i];
}

int forma_correcta_indice_circulo(int i){
    return solicitarNumeroForma(i)->tipo == CIRCULO;
}

int forma_correcta_indice_rectangulo(int i){
    return solicitarNumeroForma(i)->tipo == RECTANGULO;
}

int solicitar_entero(){
    printf("Introduzca un entero:\n");
    int i;
    scanf("%d",&i);
    return i;
}

void mostrar_forma_por_indice(int i) {
    if (i < 0 || i >= num_formas) {
        printf("[ERROR] Indice fuera de rango\n");
        return;
    }
    if (memoria[i].tipo == CIRCULO) {
        printf("CIRCULO (Centro: (%f, %f), Radio: %f)\n",
               memoria[i].datos.circulo.centro.x, memoria[i].datos.circulo.centro.y, memoria[i].datos.circulo.radio);
    } else {
        printf("RECTANGULO (Vertice inf izq: (%f, %f), Ancho: %f, Alto: %f)\n",
               memoria[i].datos.rectangulo.vertice_superior_izquierdo.x, memoria[i].datos.rectangulo.vertice_superior_izquierdo.y,
               memoria[i].datos.rectangulo.ancho, memoria[i].datos.rectangulo.alto);
    }
}

void mostrar_todas_formas() {
    if (num_formas == 0) {
        printf("No hay formas almacenadas.\n");
        return;
    }

    for (int i = 0; i < num_formas; i++) {
        mostrar_forma_por_indice(i);
    }
}

void introducir_forma() {
    if (num_formas >= MAX_FORMAS) {
        printf("Memoria llena.\n");
        return;
    }
    int tipo = entrada_numero_usuario("Tipo de forma (1: Circulo, 2: Rectangulo): ");
    Forma nuevo;
    if (tipo == 1) {
        nuevo.tipo = CIRCULO;
        nuevo.datos.circulo.centro.x = entrada_centrox_usuario();
        nuevo.datos.circulo.centro.y = entrada_centroy_usuario();
        nuevo.datos.circulo.radio = entrada_radio_usuario();

    } else if (tipo == 2) {
        nuevo.tipo = RECTANGULO;
        nuevo.datos.rectangulo.vertice_superior_izquierdo.x = entrada_verticex_usuario();
        nuevo.datos.rectangulo.vertice_superior_izquierdo.y = entrada_verticey_usuario();
        nuevo.datos.rectangulo.ancho = entrada_ancho_usuario();
        nuevo.datos.rectangulo.alto = entrada_altura_usuario();

    } else {
        printf("[ERROR] Tipo no valido.\n");
        return;
    }
    memoria[num_formas] = nuevo;
    printf("Forma guardada en posicion %d\n", num_formas);
    num_formas++;
}

void casoColision() {

    int i= solicitar_entero();
    Forma* forma1=solicitarNumeroForma(i);
    i= solicitar_entero();
    Forma* forma2=solicitarNumeroForma(i);

    if (forma1->tipo == CIRCULO && forma2->tipo == CIRCULO) {
        if (colisionCirculos(forma1->datos.circulo, forma2->datos.circulo)) {
            printf("Los circulos colisionan.\n");
        } else {
            printf("Los circulos no colisionan.\n");
        }
    } else if (forma1->tipo == CIRCULO && forma2->tipo == RECTANGULO) {
        if (colisionCirculoRectangulo(forma1->datos.circulo, forma2->datos.rectangulo)) {
            printf("El circulo y el rectangulo colisionan.\n");
        } else {
            printf("El circulo y el rectangulo no colisionan.\n");
        }
   } else if (forma1->tipo == RECTANGULO && forma2->tipo == CIRCULO) {
        if (colisionCirculoRectangulo(forma2->datos.circulo, forma1->datos.rectangulo)) {
            printf("El circulo y el rectangulo colisionan.\n");
        } else {
            printf("El circulo y el rectangulo no colisionan.\n");
        }
    } else if (forma1->tipo == RECTANGULO && forma2->tipo == RECTANGULO) {
        if (colisionRectangulos(forma1->datos.rectangulo, forma2->datos.rectangulo)) {
            printf("Los rectangulos colisionan.\n");
        } else {
            printf("Los rectangulos no colisionan.\n");
        }
    } else {
        printf("[ERROR] Tipos de formas no validos.\n");
    }
}

void eliminar_forma() {
    if (num_formas == 0) {
        printf("No hay formas para eliminar.\n");
        return;
    }

    int i;
    printf("Introduce la forma que quieres eliminar (0 a %d): ", num_formas - 1);
    scanf("%d", &i);

    if (i < 0 || i >= num_formas) {
        printf("[ERROR] Numero introducido incorrecto.\n");
        return;
    }

    for (int j = i; j < num_formas - 1; j++) {
        memoria[j] = memoria[j + 1];
    }

    num_formas--;
    printf("Forma eliminada correctamente.\n");
}

