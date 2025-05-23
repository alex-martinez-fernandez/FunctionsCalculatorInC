#include <stdio.h>
#include <math.h>
#include "formas_geometricas.h"
#define MAX_FORMAS 10
#define PI 3.14159

Forma memoria[MAX_FORMAS];
int num_formas = 0;

extern void areaPerimetrocirculo(float radio, float *perimetro, float *area) {
    if (radio < 0) {
        printf("\n[ERROR] El radio no puede ser negativo.\n");
    } else {
        *area = PI * radio * radio;
        *perimetro = 2 * PI * radio;

        printf("\nRadio: %.2f", radio);
        printf("\nArea: %.2f", *area);
        printf("\nPerimetro: %.2f\n", *perimetro);
    }
}

extern void areaPerimetrorectangulo(float ancho, float alto, float *arearectangulo, float *perimetrorectangulo) {
    if (ancho < 0 || alto < 0) {
        printf("\n[ERROR] Las dimensiones no pueden ser negativas.\n");
        return;
    }

    *arearectangulo = ancho * alto;
    *perimetrorectangulo = 2 * (ancho + alto);

    printf("\nAncho: %.2f, Alto: %.2f", ancho, alto);
    printf("\nArea: %.2f", *arearectangulo);
    printf("\nPerimetro: %.2f\n", *perimetrorectangulo);
}

void distancia_entre_coordenadas(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double resultado = sqrt(dx * dx + dy * dy);

    printf("La distancia entre los dos puntos es: %.2f\n", resultado);
}

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
        printf("Introduce x, y y radio: ");
        scanf("%lf %lf %lf", &nueva.datos.circulo.centro.x, &nueva.datos.circulo.centro.y, &nueva.datos.circulo.radio);

        if (nueva.datos.circulo.radio <= 0) {
            printf("[ERROR] Radio no válido.\n");
            return;
        }
    } else if (tipo == 2) {
        nueva.tipo = RECTANGULO;
        printf("Introduce x, y, ancho y alto: ");
        scanf("%lf %lf %lf %lf", &nueva.datos.rectangulo.vertice_inferior_izquierdo.x, &nueva.datos.rectangulo.vertice_inferior_izquierdo.y,
              &nueva.datos.rectangulo.ancho, &nueva.datos.rectangulo.alto);

        if (nueva.datos.rectangulo.ancho <= 0 || nueva.datos.rectangulo.alto <= 0) {
            printf("[ERROR] Dimensiones no válidas.\n");
            return;
        }
    } else {
        printf("[ERROR] Tipo no válido.\n");
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
        printf("[ERROR] Número introducido incorrecto.\n");
        return;
    }

    for (int j = i; j < num_formas - 1; j++) {
        memoria[j] = memoria[j + 1];
    }

    num_formas--;
    printf("Forma eliminada correctamente.\n");
}
