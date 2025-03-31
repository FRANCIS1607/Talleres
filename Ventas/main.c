#include <stdio.h>

int main() {
    int id, stock, cantidad, opcion;
    float precio, precio_final, total_venta, total_ganancias = 0, descuento;
    char nombre[30];

    // Registro del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);
    getchar();
    printf("Ingrese el nombre del producto: ");
    fgets(nombre, 30, stdin);

    printf("Ingrese la cantidad inicial en stock: ");
    scanf("%d", &stock);
    while (stock < 0) {
        printf("Cantidad invalida. Ingrese un valor positivo: ");
        scanf("%d", &stock);
    }

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    while (precio <= 0) {
        printf("Precio inválido. Ingrese un valor positivo: ");
        scanf("%f", &precio);
    }

    do {
        printf("\n\tMenu de Opciones:\n");
        printf("\t1. Vender producto\n");
        printf("\t2. Reabastecer producto\n");
        printf("\t3. Mostrar informacion del producto\n");
        printf("\t4. Mostrar total de ganancias\n");
        printf("\t5. Salir\n");
        printf("\tSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                do {
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad <= 0) {
                        printf("Cantidad invalida. Intente nuevamente.\n");
                    } else if (cantidad > stock) {
                        printf("Stock insuficiente. Disponible: %d unidades. Intente nuevamente.\n", stock);
                    }
                } while (cantidad <= 0 || cantidad > stock);

                    printf("Ingrese el descuento en porcentaje: ");
                    scanf("%f", &descuento);
                    if (descuento < 0 || descuento > 100) {
                        printf("Descuento invalido. Se aplicara 0%.\n");
                        descuento = 0;
                    }

                    precio_final = precio * (1 - descuento / 100);
                    total_venta = cantidad * precio_final;
                    total_ganancias += total_venta;
                    stock -= cantidad;
                    printf("La venta se ha completado. Total: $ %f\n", total_venta);

                break;

            case 2:
                printf("Ingrese la cantidad que desea agregar al stock: ");
                scanf("%d", &cantidad);
                while (cantidad <= 0) {
                    printf("Cantidad invalida. Intente nuevamente: ");
                    scanf("%d", &cantidad);
                }
                stock += cantidad;
                printf("El stock se ha actualizado. Nuevo stock: %d\n", stock);
                break;

            case 3:
                printf("\n\tInformacion del producto:\n");
                printf("\tID: %d\n", id);
                printf("\tNombre: %s", nombre);
                printf("\tStock disponible: %d\n", stock);
                printf("\tPrecio unitario: $ %f\n", precio);
                break;

            case 4:
                printf("Total de ganancias: $ %f\n", total_ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
