#include <stdio.h>
#include "funciones.h"

#define NumProduct 10  

int main (int argc, char *argv[]) {
    char productos[NumProduct][30];
    float precios[NumProduct];
    int num_ingresados = 0;
    int opcion;
    int continuar;
    
    printf("Sistema de Gestion de Inventario de una Tienda\n");
    do {
        num_ingresados = ingresarProductos(productos, precios);

        //Menú de opciones
        do {
            opcion = menu();  

            switch(opcion) {
                case 1:
                    mostrarResultados(precios, num_ingresados);
                    break;
                case 2:
                    buscarProducto(productos, precios, num_ingresados);
                    break;
                case 3:
                    printf("Saliendo del programa\n");
                    break;
                default:
                    printf("Error. Escoja una opcion valida\n");
            }

        } while(opcion != 3);

        printf("¿Desea ingresar nuevos productos y repetir el proceso? (1.Si 2.No): ");
        scanf("%d", &continuar);
        getchar(); 

    } while(continuar == 1 ); 
    return 0;
}