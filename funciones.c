#include <stdio.h>
#include "funciones.h"

void imprimirListaProductos(Producto* productos, int numProductos) {
    printf("Lista de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("ID: %d, Nombre: %s, Descripcion: %s, Precio: $%.2f, Cantidad: %d\n",
               productos[i].id, productos[i].nombre, productos[i].descripcion,
               productos[i].precio, productos[i].cantidad);
    }
}

void ingresarProductos(Producto* productos, int* numProductos) {
    int cantidad;
    
    printf("Ingrese los productos:\n");
    printf("¿Cuántos productos desea ingresar? ");
    scanf("%d", &cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        Producto producto;
        producto.id = *numProductos + 1;
        
        printf("Producto %d:\n", i + 1);
        
        printf("Nombre: ");
        scanf("%s", producto.nombre);
        
        printf("Descripcion: ");
        scanf("%s", producto.descripcion);
        
        printf("Precio: ");
        scanf("%f", &producto.precio);
        
        printf("Cantidad: ");
        scanf("%d", &producto.cantidad);
        
        productos[*numProductos] = producto;
        (*numProductos)++;
        
        printf("Producto ingresado con exito.\n");
    }
    
    imprimirListaProductos(productos, *numProductos);
}

void modificarProducto(Producto* productos, int numProductos) {
    int id;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &id);
    
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].id == id) {
            printf("Producto encontrado. Ingrese los nuevos datos:\n");
            
            printf("Nuevo nombre: ");
            scanf("%s", productos[i].nombre);
            
            printf("Nueva descripcion: ");
            scanf("%s", productos[i].descripcion);
            
            printf("Nuevo precio: ");
            scanf("%f", &productos[i].precio);
            
            printf("Nueva cantidad: ");
            scanf("%d", &productos[i].cantidad);
            
            printf("Producto modificado con exito.\n");
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(Producto* productos, int* numProductos) {
    int id;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);
    
    int indice = -1;
    for (int i = 0; i < *numProductos; i++) {
        if (productos[i].id == id) {
            indice = i;
            break;
        }
    }
    
    if (indice != -1) {
        for (int i = indice; i < *numProductos - 1; i++) {
            productos[i] = productos[i + 1];
        }
        (*numProductos)--;
        printf("Producto eliminado con exito.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}
