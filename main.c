#include <stdio.h>
#include <stdlib.h>
#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"

#include "clientes.h"
#include "consumos.h"
#include "archivoClientes.h"
#include "archivoConsumos.h"
#include "crudClientes.h"
#include "crudConsumos.h"
#include "ordenamientosYestadisticas.h"
#include "utilidades.h"

///funciones de menu
void menuPrincipal();
void Menu();
void Submenu();
void consumoMenu();

int main()
{
    float promedio;
    int cantRegistros;
    int dato;
    int dniBuscado;
    char apellidoBuscado[30];
    stCliente a;
    stConsumo g;



    stConsumo consumoArray[DIM_CLI];
    stConsumo arregloDeDias[DIM_CLI];
    int validosConsumo=0;
    int validosDias=0;
    int arregloSumas[10];


    int validosSuma=0;
    char arregloMeses[][DIM_CLI]={"Enero","Febrero","Marzo","Abril","Mayo","Junio"};

    int dia;
    int mes;
    int veces;
    int cantConsumo;
    float porcentajemesx=0;
    int sumatotaldatos=0;
    int posMenor;
    int posMayor;

    char opcionPricipal;
    char opcion;
    char opcion2;
    char opcionConsumo;

    stCliente clientes[DIM_CLI];
    int vClientes=0;
    int clientesrandom=0;

     gotoxy(15,10);

     system("color 70");
     centrar_Texto("UTMOVIL\n\n\n\n\n\n\n\n\n\n\n\n\n\n",8);
     system("pause");



    do
    {
        system("cls");
        menuPrincipal();
        opcionPricipal=getch();
        system("cls");
        switch(opcionPricipal)
        {
        case '1':
            do
            {
                system("cls");
                Menu();
                opcion=getch();
                system("cls");
                switch(opcion)
                {
                case '1':
                    cargaCLientes();
                    break;
                case '2':
                    do
                    {
                        system("cls");
                        Submenu();
                        opcion2=getch();
                        system("cls");
                        switch(opcion2)
                        {
                        case '1':
                            mostrarArchivoClientes();
                            break;
                        case '2':
                            mostrarArchivoClientesActivos();
                            break;
                        case '3':
                            mostrarArchivoClientesInactivos();
                            break;
                        case '4':
                            DarDeBajax();
                            break;

                        case '5':
                            DarDeAltax();
                            break;
                        case '6':
                            modificarCliMenus();
                        default:
                            printf("\nOpcion equivocada,Presione ESC para volver al menu General\n");
                            break;
                        }
                        system("pause");
                    }
                    while(opcion2!=ESC);
                    ///El submenu esta contenido en el case 1 del menu  de Clientes
                    break;
                case '3':
                    cantRegistros=cuentaRegistro(AR_CLIENTES,sizeof(stCliente));
                    printf("La Cantidad de registros es:%d \n",cantRegistros);
                    break;
                case '4':
                    printf("\nIngrese Numero de DNI a buscar\n");
                    scanf("%d",&dniBuscado);
                    a=buscaClientePorDni(dniBuscado);
                    if(a.id!=-1)
                    {
                        printf("\nEl cliente con el DNI %d Fue encontrado exitosamente.\n",dniBuscado);
                        mostrarUnClienteId(a);
                    }
                    else
                    {
                        printf("\nEl cliente con el DNI %d NO existe.\n",dniBuscado);
                    }
                    break;
                case '5':
                    printf("\nIngrese APELLIDO a buscar\n");
                    fflush(stdin);
                    gets(apellidoBuscado);
                    a=buscaClientePorApellido(apellidoBuscado);
                    if(a.id!=-1)
                    {
                        printf("\nEl cliente con el apellido %s Fue encontrado exitosamente.\n",apellidoBuscado);
                        mostrarUnClienteId(a);
                    }
                    else
                    {
                        printf("\nEl cliente con el apellido %s NO existe.\n",apellidoBuscado);
                    }
                    break;
                case '6':
                    ordenarDNIS(a);
                    break;
                case '7':
                    ordenarApellidos(a);
                    break;
                case '8':
                    ordenarEmails(a);
                    break;
                case '9':
                    printf("\n Cantidad de Clientes Random: ");
                    scanf("%d",&clientesrandom);
                    vClientes=funcion00(clientes,vClientes,clientesrandom);
                    break;
                default:
                    printf("\nOpcion equivocada,Presione ESC para Volver al Inicio.\n");
                    break;
                }
                system("pause");
            }
            while(opcion!=ESC);
            break;
        case '2':
            do
            {
                system("cls");
                consumoMenu();
                opcionConsumo=getch();
                system("cls");
                switch(opcionConsumo)
                {

                case '1':
                    cargaConsumosTeclado();
                    break;
                case '2':
                    printf("\nIngrese la Cantidad de consumos que quiera crear: ");
                    scanf("%d",&veces);
                    centrar_Texto("PRESIONE UNA TECLA Y ESPERE A QUE TERMINE DE CARGAR\n\n",8);
                    system("pause");
                    cargaConsumos(veces);
                    break;
                case '3':
                   mostrarArchivoConsumos();
                   break;
                case '4':
                     printf("\nIngrese Numero de mes:");
                    scanf("%d",&mes);
                    printf("\nIngrese Numero de dia:");
                    scanf("%d",&dia);
                    g=buscaConsumoPorFecha(mes,dia);

                    printf("\n");

                    if(g.id!=-1){
                    printf("La fecha %d/%d tiene el consumo\n",mes,dia);
                    mostrarUnConsumo(g);
                    }
                    else{
                        printf("La fecha %d/%d NO tiene consumos Registrados\n",mes,dia);
                    }

                    break;
               case '5':
                        cantConsumo=cuentaRegistro(AR_CONSUMOS, sizeof(stConsumo));
                        printf("La Cantidad de consumos es:%d \n",cantConsumo);
                    break;

               case '6':
                        modificarConsumosSubMenu();
                    break;

                default:
                    printf("\nOpcion equivocada,Presione ESC para Volver al Inicio.\n");
                  break;
               case '7':
                do{
                 printf("\nIngrese el mes para ver sus consumos: ");
                 scanf("%d",&dato);
                 if(dato<1 || dato>12)
                 {
                  printf("\nMes no valido, Por favor intente nuevamente.\n");
                 }
                 }while(dato<1 ||  dato>12);
                 ordenarMES(g,dato);
                 break;
               case '8':
                printf("\n");
                muestraSumaDatos(g);
                sumatotaldatos = sumadatosAll(g);
                printf("\nSUMA TOTAL DATOS: %d\n",sumatotaldatos);
                porcentajemesx = sumadatosAll(g);
                porcentajemesx = PorcentajeMesConsumo(porcentajemesx);
                printf("\nPromedio datos consumidos por mes: %.2fMBs\n",porcentajemesx);
                printf("\n\n");
                promedio=promedioXdia();
                printf("\nEl Promedio datos consumidos por dia: %.2fMBs\n",promedio);
                printf("\n\n");
                validosSuma=pasarArraySumaDatos(g,arregloSumas,validosSuma);
                posMenor=buscaPosMenorConsumoMes(arregloSumas,validosSuma);
                printf("\nEl mes con MENOR consumo:%s(%d): %dMBs\n",arregloMeses[posMenor],posMenor+1,arregloSumas[posMenor]);
                validosSuma=pasarArraySumaDatos(g,arregloSumas,validosSuma);
                posMayor=buscaPosMayorConsumoMeees(arregloSumas,validosSuma);
                printf("\nEl mes con MAYOR consumo:%s(%d): %dMBs\n",arregloMeses[posMayor],posMayor+1,arregloSumas[posMayor]);
                porcentajeClientesActivos_Inactivos();
                break;

                case '9':
                validosConsumo=archivo2ArrayConsumosEnteros(g,consumoArray,validosConsumo,DIM_CLI);
                ordenarArrayConsumosPorMes(consumoArray,validosConsumo);
                validosDias=ordenarArrayConsumosPorDiaYMes(consumoArray,validosConsumo,arregloDeDias);
                printf("\nConsumos Ordenados por dia-:\n");
                ordenarSelDia(arregloDeDias,validosDias);///en este tengo los dias, tecnicamente es una copia del otro arreglo,pero
                muestraConsumos(arregloDeDias,validosDias);///cuando tengamos que hacer la matriz, va a servir mucho tener copias.
                break;
                case 'a':

                    break;
                }

            system("pause");
            }while(opcionConsumo!=ESC);
         break;
        }

    }
    while(opcionPricipal!=ESC);

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


