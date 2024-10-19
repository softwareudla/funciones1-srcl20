#include <stdio.h>
#include <math.h>
#include <string.h>
#include "funciones.h"

#define NumProduct 10  

int menu() {
    int opcion;
    printf("1.Ver resultados\n");
    printf("2.Buscar producto\n");
    printf("3.Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    getchar(); 
    return opcion;
}


int ingresarProductos(char productos[NumProduct][30], float precios[NumProduct]) {
    int num_ingresados = 0;
    int continuar;

    printf("Ingreso de Productos\n");
    while (num_ingresados < NumProduct) {
        printf("Ingrese el nombre del producto %d: ", num_ingresados + 1);
        fgets(productos[num_ingresados], 30, stdin);

        printf("Ingrese el precio del producto %d: ", num_ingresados + 1);
        scanf("%f", &precios[num_ingresados]);  
        getchar(); 

        num_ingresados++;

        if (num_ingresados < NumProduct) {
            printf("¿Desea ingresar otro producto? (1.Si 2.No): ");
            scanf("%d", &continuar);
            getchar(); 
            if (continuar == 2) {
                break;
            }
        }
    }

    return num_ingresados;  // Devuelve cuántos productos se ingresaron
}

void mostrarResultados(float precios[NumProduct], int num_ingresados) {
    if (num_ingresados == 0) {
        printf("No hay productos ingresados\n");
        return;
    }

    float total= 0, maximo= precios[0], minimo= precios[0];

    for (int i = 0; i < num_ingresados; i++) {
        total += precios[i];
        if (precios[i] > maximo) maximo = precios[i];
        if (precios[i] < minimo) minimo = precios[i];
    }

    float promedio= total / num_ingresados;

    printf("El precio total de los productos es: %.2f\n", total);
    printf("El producto mas caro es: %.2f\n", maximo);
    printf("El producto mas barato es: %.2f\n", minimo);
    printf("El promedio de los precios es: %.2f\n", promedio);
}


void buscarProducto(char productos[NumProduct][30], float precios[NumProduct], int num_ingresados) {
    if (num_ingresados == 0) {
        printf("No hay productos ingresados\n");
        return;
    }

    char producto_buscado[30];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a buscar: ");
    fgets(producto_buscado, 30, stdin);

    for (int i = 0; i < num_ingresados; i++) {
        if (strcmp(producto_buscado, productos[i]) == 0) {
            printf("El precio del producto %s es: %.2f\n", productos[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado o inexistente\n");
    }
}