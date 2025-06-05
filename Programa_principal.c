#include <stdio.h>
#include "interfaz.h"
#include "formas_geometricas.h"
#include "EntradadelUsuraio.h"


int main() {
    int opcion = 0;

    do {
        opcion = printmenu();

        switch (opcion) {
     case 1:{

         double r=entrada_radio_usuario();

         double area= areacirculo (r);
         double perimetro=perimetrocirculo(r);

            printf("Area: %f\n", area);
            printf("Perimetro: %f\n", perimetro);
         break;

         }
    case 2:{
        double h=entrada_altura_usuario();
        double a=entrada_ancho_usuario();
        double area= arearectangulo(h,a);
        double perimetro= perimetrorectangulo(h,a);

            printf("Area: %f\n", area);
            printf("Perimetro: %f\n", perimetro);

        break;
}

    case 3: {
        int i= solicitar_entero();


        if(forma_correcta_indice_circulo(i)){
            Forma* f = solicitarNumeroForma(i);
            Circulo c = f->datos.circulo;
            double r = c.radio;

            double area= areacirculo (r);
            double perimetro=perimetrocirculo(r);

            printf("Area: %f\n", area);
            printf("Perimetro: %f\n", perimetro);
        }else{
            printf("[ERROR]");
        }

        break;
}
    case 4: {

        int i= solicitar_entero();


        if(forma_correcta_indice_rectangulo(i)){
            Forma* f=solicitarNumeroForma(i);
            Rectangulo r= f->datos.rectangulo;
            double a= r.ancho;
            double h= r.alto;

            double area= arearectangulo(a,h);
            double perimetro= perimetrorectangulo(a,h);

            printf("Area: %f\n", area);
            printf("Perimetro: %f\n", perimetro);
        } else{
            printf("[ERROR]");
    }

        break;
}
    case 5: {
        double x1,x2,y1,y2;
        solicitarPuntosCoordenadas(&x1,&y1,&x2,&y2);
        double d=distancia_entre_coordenadas(x1, y1, x2, y2);

            printf("La distancia entre coordenandas es: %f",d);

        break;
            }
    case 6:{

        void casoColision();

        break;
            }
    case 7:{
        void introducir_forma();

        break;
            }
    case 8:{
        void eliminar_forma();

        break;
            }
    case 9:{
        void mostrar_forma();

        break;
            }
    case 10:{
        void mostrar_todas_formas();

        break;
            }
    case 11:{
        printf("Saliendo del programa\n");

        break;
            }
        default:{
            printf("[ERROR] Opcin no valida.\n");

        break;
            }
        }

    } while (opcion != 11);

    return 0;
}

