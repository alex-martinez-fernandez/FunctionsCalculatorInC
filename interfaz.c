
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

extern void solicitarDatosCirculo (float *radio, float * datos.circulo.x, float * datos.circulo.y){

printf("\n Por favor, introduzca el radio del circulo:")
scanf ("%f", &radio)
printf("Centro (x y): ");
        scanf("%lf %lf", &datos.circulo.x, &datos.circulo.y);
        }

extern void solicitarDatosRectangulo (float * largo, float * ancho, float * datos.rectangulo.x, float * datos.rectangulo.y){
printf ("Por favor, introduzca el largo del rectangulo:";
scanf ("%f", &largo)
printf ("Por favor, introduzca el ancho del rectangulo:";
scanf ("%f", &ancho)

printf("Vertice inf izq (x y): ");
        scanf("%lf %lf", &datos.rectangulo.x, &datos.rectangulo.y);
}


extern void solicitarPuntosCoordenadas (double x1, double y1, double x2, double y2){
printf("\nPor favor introduzca el valor x de la primera coordenada: ");
    scanf("%lf", &x1);

    printf("\nPor favor introduzca el valor y de la primera coordenada: ");
    scanf("%lf", &y1);

    printf("\nPor favor introduzca el valor x de la segunda coordenada: ");
    scanf("%lf", &x2);

    printf("\nPor favor introduzca el valor y de la segunda coordenada: ");
    scanf("%lf", &y2);}


void mostrar_forma() {
    int i;
    printf("Introduce numero de forma (0 a %d): ", num_formas - 1);
    scanf("%d", &i);
    mostrar_forma_por_indice(i);
}

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

void mostrar_todas_formas() {
    if (num_formas == 0) {
        printf("No hay formas almacenadas.\n");
        return;
    }

    for (int i = 0; i < num_formas; i++) {
        mostrar_forma_por_indice(i);
    }
}
