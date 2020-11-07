#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "consumos.h"
#include "archivoClientes.h"
#include "archivoConsumos.h"
#include "crudClientes.h"
#include "crudConsumos.h"
#include "ordenamientosYestadisticas.h"
#include "utilidades.h"


int main()
{
    printf("Hello world2\n");
    return 0;
}

void menuPrincipal()
{
    system("color F");

    centrar_Texto("Seleccione:",5);
    centrar_Texto("1-Clientes",8);
    centrar_Texto("2-Consumos",11);

    centrar_Texto("Presione ESC para Salir",15);

}

///Primer pantalla

void centrar_Texto(const char *texto, int y)
{
    int size_texto=strlen(texto);
    gotoxy(45-(size_texto/2),y);
    printf("%s",texto);
}
///
void Menu()
{
    system("color A");

    printf("\n\t\tCLIENTES\n");

    printf("\n1-Cargar clientes\n");
    printf("\n2-Mostrar un distintos archivos clientes\n");
    printf("\n3-Contar numero de Registros\n");
    printf("\n4-Buscar Clientes por DNI\n");
    printf("\n5-Buscar Clientes por Apellido\n");
    printf("\n6-Ordenar Clientes por DNI (ACTIVOS)\n");
    printf("\n7-Ordenar Clientes por apellidos (ACTIVOS)\n");
    printf("\n8-Ordenar Clientes por E-Mails (INACTIVOS)\n");
    printf("\n9-Cargar Clientes Random.\n");

    printf("\nPresione ESC para Salir\n");


}
void consumoMenu()
{
    system("color E");

    printf("\n\t\tCONSUMOS\n");

    printf("\n1-Cargar consumos Por Teclado\n");
    printf("\n2-Cargar Consumos Aleatorios\n");
    printf("\n3-Mostrar todos los consumos\n");
    printf("\n4-Buscar Un Cliente por Fecha\n");
    printf("\n5-Cuenta Consumos\n");
    printf("\n6-Modificar Consumos\n");
    printf("\n7-Mostrar consumos por mes\n");
    printf("\n8-Estadisticas Consumos\n");
    printf("\n9-Ordenar Consumos por dia\n");
    printf("\na-Matriz muestra consumo activos y inactivos\n");
    printf("\nPresione ESC para Salir\n");


}
void Submenu()
{

    system("color B");
    printf("\n\t\tSubMenu\n");
    printf("\n1-Mostrar todos los Clientes\n");
    printf("\n2-Mostrar Clientes Activos \n");
    printf("\n3-Mostrar Clientes Inactivos\n");
    printf("\n4-Dar de baja un cliente\n");
    printf("\n5-Dar de alta un cliente\n");
    printf("\n6-Modificar Cliente\n");


    printf("\nPresione ESC para Volver al menu General\n");


}


