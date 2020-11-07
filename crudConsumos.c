#include "crudConsumos.h"

 /*********************************************************************//**
*
* \brief modifica un consumo ingresando su id por teclado
* \param no tiene paremtros
* \return es void
*
**************************************************************************/
void modificarConsumo()
{
    stConsumo g;
    int id;
    printf("\n Ingrese ID de consumo a modificar: ");
    scanf("%d",&id);
    g = traeConsumo(id);
    modificaConsumo(g);
}

 /*********************************************************************//**
*
* \brief modifica en el registro de Consumos el campo consumo
* \param recibe el consumo
* \return es void
*
**************************************************************************/
 void modificaConsumo(stConsumo g)
{
    int pos=0;
    pos = buscaPosicionConsumo(g.id);
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"r+b");
    if(pArchConsumo)
    {
        fseek(pArchConsumo,sizeof(stConsumo)*pos,SEEK_SET);
        printf("\n Nuevo Consumo: ");
        scanf("%d",&g.datosConsumidos);
        fwrite(&g,sizeof(stConsumo),1,pArchConsumo);
        fclose(pArchConsumo);
    }
}

 /*********************************************************************//**
*
* \brief modifica un  consumo ingreando un id por teclado
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void modificarBajaConsumo(){
 stConsumo c;
 int id;
 printf("\n Ingrese ID consumo a dar de baja: ");
 scanf("%d",&id);
 c = traeConsumo(id);
 DarDeBajaConsumo(c);
}

 /*********************************************************************//**
*
* \brief modifica en el registro de Consumos el campo baja
* \param recibe el consumo
* \return es void
*
**************************************************************************/
void DarDeBajaConsumo(stConsumo g)
{
    int pos=0;
    pos = buscaPosicionConsumo(g.id);
    FILE *pArchConsumos = fopen(AR_CONSUMOS,"r+b");
    if(pArchConsumos)
    {
        fseek(pArchConsumos,sizeof(stConsumo)*pos,SEEK_SET);
        printf("\n Consumo dado de baja exitosamente.....\n\n");
        g.baja = 1;
        fwrite(&g,sizeof(stConsumo),1,pArchConsumos);
        fclose(pArchConsumos);
    }
}

 /*********************************************************************//**
*
* \brief modifica  un consumo ingresando su id por teclado
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void modificarConsumoAlta(){
    stConsumo g;
    int id;
    printf("\n Ingrese ID consumo a dar de alta: ");
    scanf("%d",&id);
    g = traeConsumo(id);
    DarDeAltaConsumo(g);
}

 /*********************************************************************//**
*
* \brief modifica en el registro de Consumos el campo baja
* \param recibe el consumo
* \return es void
*
**************************************************************************/
 void DarDeAltaConsumo(stConsumo g)
{
    int pos=0;
    pos = buscaPosicionConsumo(g.id);
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"r+b");
    if(pArchConsumo)
    {
       fseek(pArchConsumo,sizeof(stConsumo)*pos,SEEK_SET);
        printf("\n Consumo dado de alta exitosamente.....\n\n");
        g.baja = 0;
        fwrite(&g,sizeof(stConsumo),1,pArchConsumo);
        fclose(pArchConsumo);
    }
}

 /*********************************************************************//**
*
* \brief menu que maneja todo el crud
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void modificarConsumosSubMenu()
{
    char opcion;
    do
    {
        system("cls");
        printf("\n MODIFICACION DE Consumos...\n");
        printf("\n 1-Modificar un consumo");
        printf("\n 2-Modificar Estado de Baja");
        printf("\n 3-Modificar Estado de Alta");
        printf("\n\n");
        printf("\n ESC para salir...");
        opcion=getch();
        switch(opcion)
        {
        case 49:
            modificarConsumo();
            break;
        case 50:
            modificarBajaConsumo();
            break;
        case 51:
            modificarConsumoAlta();
            break;
        default:
            printf("\n Opcion incorrecta");
        }
        system("pause");
    }
    while(opcion!=27);
}
