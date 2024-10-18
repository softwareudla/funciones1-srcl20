#include <stdio.h>
#include "funciones.h"

#define NumProduct 10  

int menu() {
    int opcion;
    printf("1. Ver resultados\n");
    printf("2. Buscar producto\n");
    printf("3. Salir\n");
    printf("Elija una opcion:");
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
        for (int j = 0; productos[num_ingresados][j] != '\0'; j++) {
            if (productos[num_ingresados][j] == '\n') {
                productos[num_ingresados][j] = '\0';
                break;
            }
        }

        printf("Ingrese el precio del producto %d: ", num_ingresados + 1);
        scanf("%f", &precios[num_ingresados]);  
        getchar(); 

        num_ingresados++;

        if (num_ingresados < NumProduct) {
            printf("¿Desea ingresar otro producto? (1. Si 2. No):");
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
        printf("No hay productos ingresados.\n");
        return;
    }

    float total = 0, maximo = precios[0], minimo = precios[0];

    for (int i = 0; i < num_ingresados; i++) {
        total += precios[i];
        if (precios[i] > maximo) maximo = precios[i];
        if (precios[i] < minimo) minimo = precios[i];
    }

    float promedio = total / num_ingresados;

    printf("El precio total de los productos: %.2f\n", total);
    printf("El producto mas caro: %.2f\n", maximo);
    printf("El producto mas barato: %.2f\n", minimo);
    printf("El promedio de precios: %.2f\n", promedio);
}


void buscarProducto(char productos[NumProduct][30], float precios[NumProduct], int num_ingresados) {
    if (num_ingresados == 0) {
        printf("No hay productos ingresados\n");
        return;
    }

    char producto_buscado[30];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a buscar:");
    fgets(producto_buscado, 30, stdin);

    for (int j = 0; producto_buscado[j] != '\0'; j++) {
        if (producto_buscado[j] == '\n') {
            producto_buscado[j] = '\0';
            break;
        }
    }

    for (int i = 0; i < num_ingresados; i++) {
        int Buscador = 1; // Suponemos que son iguales con el producto actual que se va a comparar
        for (int j = 0; producto_buscado[j] != '\0' && productos[i][j] != '\0'; j++) {
            if (producto_buscado[j] != productos[i][j]) {
                Buscador = 0; // Si algún carácter no coincide, no son iguales
                break;
            }
        }
        // Si son iguales, mostrar el precio
        if (Buscador) {
            printf("El precio del producto '%s' es: %.2f\n", productos[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado o inexistente\n");
    }
}