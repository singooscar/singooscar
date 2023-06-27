#ifndef FUNCIONES_H
#define FUNCIONES_H

void imprimirListaProductos(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int numProductos);
void ingresarProductos(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int* numProductos);
void modificarProducto(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int numProductos);
void eliminarProducto(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int* numProductos);

#endif  // FUNCIONES_H
