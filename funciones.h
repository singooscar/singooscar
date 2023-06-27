#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 10

typedef struct {
    int id;
    char nombre[20];
    char descripcion[50];
    float precio;
    int cantidad;
} Producto;

void imprimirListaProductos(Producto* productos, int numProductos);
void ingresarProductos(Producto* productos, int* numProductos);
void modificarProducto(Producto* productos, int numProductos);
void eliminarProducto(Producto* productos, int* numProductos);

#endif  // FUNCIONES_H
