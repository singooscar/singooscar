#include <stdio.h>
#include "funciones.h"

int main() {
    Producto productos[MAX_PRODUCTOS];
    int numProductos = 0;
    
    printf("Bienvenido al sistema de gestión de productos.\n");
    
    while (1) {
        printf("\n¿Qué acción desea realizar?\n");
        printf("1. Ingresar productos\n");
        printf("2. Ver productos\n");
        printf("3. Modificar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Ingrese el número de la opción: ");
        int opcion;
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ingresarProductos(productos, &numProductos);
                break;
            case 2:
                imprimirListaProductos(productos, numProductos);
                break;
            case 3:
                modificarProducto(productos, numProductos);
                break;
            case 4:
                eliminarProducto(productos, &numProductos);
                break;
            case 5:
                printf("¡Hasta luego!\n");
                return 0;
            default:
                printf("¡Opción inválida!\n");
                break;
        }
    }
    
    return 0;
}
