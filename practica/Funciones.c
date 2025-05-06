
// esta parte del codigo consiste en implementar de todas las funciones que voy a usar en mo calculadora declaradas en el archivo de cabecera

#include <stdio.h>
#include <math.h>
#include "funciones.h"

#define PI 3.14159265  // Definimos PI (por si acaso, a veces en math.h no viene definido en numero PI, depende del compilador)

Forma memoria[MAX_FORMAS];
int num_formas = 0;         // Contador de formas almacenadas

int printmenu() {
    int opcion = 0;

    printf("\nPor favor introducir una opcion:\n");
    printf("1) Calculo del area y perimetro de un Circulo\n");
    printf("2) Calculo del area y perimetro de un Rectangulo\n");
    printf("3) Distancia entre dos puntos\n");
    printf("4) Introducir nueva forma\n");
    printf("5) Eliminar forma\n");
    printf("6) Mostrar forma\n");
    printf("7) Mostrar todas las formas\n");
    printf("8) Salir\n");

    do {
        printf("La opcion tiene que estar entre 1 y 8: ");
        scanf("%i", &opcion);
    } while (opcion < 1 || opcion > 8);

    return opcion;
}

// Calcula y muestra el area y perimetro de un circulo
void circulo(double radio) {
    printf("\nPor favor introduzca el radio del circulo: ");
    scanf("%lf", &radio);

    if (radio < 0) {
        printf("\n[ERROR] El radio no puede ser negativo.\n");
    } else {
        double area = PI * radio * radio;
        double perimetro = 2 * PI * radio;

        printf("\nRadio: %.2f", radio);
        printf("\nArea: %.2f", area);
        printf("\nPerimetro: %.2f\n", perimetro);
    }
}

// Calcula y muestra el area y perimetro de un rectangulo
void rectangulo(double ancho, double alto) {
    printf("\nPor favor introduzca el ancho del rectangulo: ");
    scanf("%lf", &ancho);
    printf("\nPor favor introduzca el alto del rectangulo: ");
    scanf("%lf", &alto);

    if (ancho < 0 || alto < 0) {
        printf("\n[ERROR] Las dimensiones no pueden ser negativas.\n");
        return;
    }

    double area = ancho * alto;
    double perimetro = 2 * (ancho + alto);

    printf("\nAncho: %.2f, Alto: %.2f", ancho, alto);
    printf("\nArea: %.2f", area);
    printf("\nPerimetro: %.2f\n", perimetro);
}

// Calcula y muestra la distancia entre dos puntos (x1, y1) y (x2, y2)
void distancia_entre_coordenadas(double x1, double y1, double x2, double y2) {
    printf("\nPor favor introduzca el valor x de la primera coordenada: ");
    scanf("%lf", &x1);

    printf("\nPor favor introduzca el valor y de la primera coordenada: ");
    scanf("%lf", &y1);

    printf("\nPor favor introduzca el valor x de la segunda coordenada: ");
    scanf("%lf", &x2);

    printf("\nPor favor introduzca el valor y de la segunda coordenada: ");
    scanf("%lf", &y2);

    double dx = x2 - x1;
    double dy = y2 - y1;
    double resultado = sqrt(pow(dx, 2) + pow(dy, 2));

    printf("La distancia entre los dos puntos es: %.2f\n", resultado);
}

// Permite introducir una nueva forma (circulo o rectangulo) y almacenarla
void introducir_forma() {
    if (num_formas >= MAX_FORMAS) {
        printf("Memoria llena.\n");
        return;
    }

    int tipo;
    printf("\nTipo de forma (1: Circulo, 2: Rectangulo): ");
    scanf("%d", &tipo);

    Forma nueva;
    if (tipo == 1) {
        nueva.tipo = CIRCULO;
        printf("Centro (x y): ");
        scanf("%lf %lf", &nueva.datos.circulo.x, &nueva.datos.circulo.y);
        printf("Radio: ");
        scanf("%lf", &nueva.datos.circulo.radio);

        if (nueva.datos.circulo.radio <= 0) {
            printf("[ERROR] Radio no valido.\n");
            return;
        }
    } else if (tipo == 2) {
        nueva.tipo = RECTANGULO;
        printf("Vertice inf izq (x y): ");
        scanf("%lf %lf", &nueva.datos.rectangulo.x, &nueva.datos.rectangulo.y);
        printf("Ancho y alto: ");
        scanf("%lf %lf", &nueva.datos.rectangulo.ancho, &nueva.datos.rectangulo.alto);

        if (nueva.datos.rectangulo.ancho <= 0 || nueva.datos.rectangulo.alto <= 0) {
            printf("[ERROR] Dimensiones no validas.\n");
            return;
        }
    } else {
        printf("[ERROR] Tipo no valido.\n");
        return;
    }

    memoria[num_formas] = nueva;
    printf("Forma guardada en posicion %d\n", num_formas);
    num_formas++;
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
        printf("[ERROR] numero introducido incorrecto.\n");
        return;
    }

    // Desplazar las formas posteriores una posición hacia atrás
    for (int j = i; j < num_formas - 1; j++) {
        memoria[j] = memoria[j + 1];
    }

    num_formas--;  // Reducimos el contador de formas
    printf("Forma eliminada correctamente.\n");
}



// Solicita un indice y muestra la forma correspondiente
void mostrar_forma() {
    int i;
    printf("Introduce numero de forma (0 a %d): ", num_formas - 1);
    scanf("%d", &i);

    mostrar_forma_por_indice(i);
}

// Muestra la forma en la posicion i
void mostrar_forma_por_indice(int i) {
    if (i < 0 || i >= num_formas) {
        printf("[ERROR] Indice fuera de rango\n");
        return;
    }

    if (memoria[i].tipo == CIRCULO) {
        printf("CIRCULO (Centro: (%.2f, %.2f), Radio: %.2f)\n",
               memoria[i].datos.circulo.x, memoria[i].datos.circulo.y, memoria[i].datos.circulo.radio);
    } else {
        printf("RECTANGULO (Vertice inf izq: (%.2f, %.2f), Ancho: %.2f, Alto: %.2f)\n",
               memoria[i].datos.rectangulo.x, memoria[i].datos.rectangulo.y,
               memoria[i].datos.rectangulo.ancho, memoria[i].datos.rectangulo.alto);
    }
}

// Muestra todas las formas almacenadas
void mostrar_todas_formas() {
    if (num_formas == 0) {
        printf("No hay formas almacenadas.\n");
        return;
    }

    for (int i = 0; i < num_formas; i++) {
        mostrar_forma_por_indice(i);
    }
}
