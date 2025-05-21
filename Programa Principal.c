#include <stdio.h>
#include "interfaz.h"
#include "formas_geometricas.h"

int main() {
    int opcion = 0;
    double radio, ancho, alto, x1, x2, y1, y2;

    do {
        opcion = printmenu();

        switch (opcion) {
            case 1:
                extern void solicitarDatosCirculo (float *radio, float * datos.circulo.x, float * datos.circulo.y);
                extern void areaPerimetrocirculo(float radio, float * perimetrocirculo, float*  areacirculo;
                break;
            case 2:
                extern void solicitarDatosRectangulo(float *largo, float *ancho);
                void areaPerimetrorectangulo(float ancho, float alto, float * arearectangulo, float * perimetrorectangulo);
                break;
            case 3:
                extern void solicitarPuntosCoordenadas (double x1, double y1, double x2, double y2);
                void distancia_entre_coordenadas(double x1, double y1, double x2, double y2);
                break;
            case 4:
                introducir_forma();
                break;
            case 5:
                eliminar_forma();
                break;
            case 6:
                mostrar_forma();
                break;
            case 7:
                mostrar_todas_formas();
                break;
            case 8:
                printf("Saliendo del programa\n");
                break;
        }

    } while (opcion != 8);

    return 0;
}

