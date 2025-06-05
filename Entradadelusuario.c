#include "EntradadelUsuraio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

double convertir_entrada_numero(char* cdc){

    char* end = NULL;
    errno = 0;

    double x = strtod(cdc, &end);

    if(cdc == end)
    {
    printf( "[ERROR], la conversion no se pudo realizar\n");
        return -1;
    }
    else if(errno == ERANGE)
    {
        printf( "[ERROR], el numero es demasiado grande\n");
        return -1;
    }
    else
        return x;
}

double convertir_entrada_distancia(char* cdc)
{
    double longitud = entrada_numero_usuario(cdc);
    if (longitud <= 0)
    {
        printf( "[ERROR] El radio no puede ser negativo.\n");
        return -1;
    }
  else
    return longitud;

}
double entrada_numero_usuario(char* mensage)
{
    char entrada[100];

    printf("%s\n", mensage);
    scanf("%s", entrada);

    return entrada_numero_usuario(entrada);
}

double entrada_tamano_usuario(char* mensage)
{
    char entrada[100];

    printf("%s\n", mensage);
    scanf("%s", entrada);

    return convertir_entrada_distancia(entrada);
}

double entrada_radio_usuario()
{
    return convertir_entrada_distancia("Por favor introduzca el radio del circulo: \n");
}

double entrada_centrox_usuario(){
    return entrada_numero_usuario("Por favor introduzca la coordenada x del centro\n");
}

double entrada_centroy_usuario(){
    return entrada_centroy_usuario("Por favor introduzca la coordenada y del centro\n");
}

double entrada_altura_usuario(){
    return convertir_entrada_distancia("Por favor introduzca la altura del rectangulo: \n");
}

double entrada_ancho_usuario(){
    return convertir_entrada_distancia("Por favor introduzca la anchura del rectangulo: \n");
}

double entrada_verticex_usuario(){
    return entrada_numero_usuario("Por favor introduzca la coordenada x del vertice superior izquierdo:\n");
}

double entrada_verticey_usuario(){
    return entrada_numero_usuario("Por favor introduzca la coordenada x del vertice superior izquierdo:\n");
}



