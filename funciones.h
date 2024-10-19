#define NumProduct 10  

int ingresarProductos(char productos[NumProduct][30], float precios[NumProduct]);
void mostrarResultados(float precios[NumProduct], int num_ingresados);
void buscarProducto(char productos[NumProduct][30], float precios[NumProduct], int num_ingresados);
int menu();