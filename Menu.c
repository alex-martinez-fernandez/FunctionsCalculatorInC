
// el menu muestra y gestiona las opciones del usuario
#include <stdio.h>
#include "funciones.h"

int main() {

    int opcion = 0;
    double radio = 0, ancho = 0, alto = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    do {
        opcion = printmenu();

        switch (opcion) {
            case 1:
                circulo(radio);  // Calcular area y perimetro del circulo
                break;
            case 2:
                rectangulo(ancho, alto);  // Calcular area y perimetro del rectangulo
                break;
            case 3:
                distancia_entre_coordenadas(x1, y1, x2, y2);  // Calcular distancia entre dos puntos
                break;
            case 4:
                introducir_forma();  // Introducir nueva forma en memoria
                break;
            case 5:
                eliminar_forma();  // Eliminar forma (pendiente de implementacion)
                break;
            case 6:
                mostrar_forma();  // Mostrar una forma concreta
                break;
            case 7:
                mostrar_todas_formas();  // Mostrar todas las formas almacenadas
                break;
            case 8:
                printf("Saliendo del programa\n");  // Salida del programa
                break;
        }

    } while (opcion != 8);

    return 0;
}
