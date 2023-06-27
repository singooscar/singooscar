#include <stdio.h>
#include <string.h>
#include "funciones.h"

void imprimirListaProductos(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int numProductos) {
    printf("Lista de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("ID: %d, Nombre: %s, Descripcion: %s, Precio: $%.2f, Cantidad: %d\n",
               id[i], nombre[i], descripcion[i], precio[i], cantidad[i]);
    }
}

void ingresarProductos(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int* numProductos) {
    int cantidadProductos;
    
    printf("Ingrese los productos:\n");
    printf("¿Cuántos productos desea ingresar? ");
    scanf("%d", &cantidadProductos);
    
    for (int i = 0; i < cantidadProductos; i++) {
        id[*numProductos] = *numProductos + 1;
        
        printf("Producto %d:\n", i + 1);
        
        printf("Nombre: ");
        scanf("%s", nombre[*numProductos]);
        
        printf("Descripcion: ");
        scanf("%s", descripcion[*numProductos]);
        
        printf("Precio: ");
        scanf("%f", &precio[*numProductos]);
        
        printf("Cantidad: ");
        scanf("%d", &cantidad[*numProductos]);
        
        (*numProductos)++;
        
        printf("Producto ingresado con éxito.\n");
    }
    
    imprimirListaProductos(id, nombre, descripcion, precio, cantidad, *numProductos);
}

void modificarProducto(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int numProductos) {
    int productoID;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &productoID);
    
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (id[i] == productoID) {
            printf("Producto encontrado. Ingrese los nuevos datos:\n");
            
            printf("Nuevo nombre: ");
            scanf("%s", nombre[i]);
            
            printf("Nueva descripción: ");
            scanf("%s", descripcion[i]);
            
            printf("Nuevo precio: ");
            scanf("%f", &precio[i]);
            
            printf("Nueva cantidad: ");
            scanf("%d", &cantidad[i]);
            
            printf("Producto modificado con éxito.\n");
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(int* id, char nombre[][20], char descripcion[][50], float* precio, int* cantidad, int* numProductos) {
    int productoID;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &productoID);
    
    int indice = -1;
    for (int i = 0; i < *numProductos; i++) {
        if (id[i] == productoID) {
            indice = i;
            break;
        }
    }
    
    if (indice != -1) {
        for (int i = indice; i < *numProductos - 1; i++) {
            id[i] = id[i + 1];
            strcpy(nombre[i], nombre[i + 1]);
            strcpy(descripcion[i], descripcion[i + 1]);
            precio[i] = precio[i + 1];
            cantidad[i] = cantidad[i + 1];
        }
        (*numProductos)--;
        printf("Producto eliminado con éxito.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}
