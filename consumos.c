#include "consumos.h"

/*********************************************************************//**
*
* \brief Carga un consumo a un cliente
* \param  no tiene parametros
* \return Retorna el consumo cargado
*
**************************************************************************/
stConsumo cargaConsumoCliente()
{
    stConsumo g;
    int baja=0;
    int dias=0;



        do{
         printf("\ningrese El IdCliente.:");
         scanf("%d", &g.idCliente);


          if(g.idCliente<0 || g.idCliente>buscaUltimoId()){
            printf("\n　Error,Ingrese un Id valido Por favor.\n");
         }

        }while(g.idCliente<0 || g.idCliente>buscaUltimoId());
         ///Con esto se verifica que el cliente al que se le va a cargar un consumo exista
        do{
         printf("\ningrese El Consumo.:");
         scanf("%d", &g.datosConsumidos);

         if(g.datosConsumidos<0 || g.datosConsumidos>9999999){
            printf("\n　Error,Ingrese un consumo valido Por favor.\n");
         }
        }while(g.datosConsumidos<0 || g.datosConsumidos>9999999);
        ///con esto se verifica que el consumo sea positivo, y se le dio un tope el cual se supone que nunca se llegue
        do{
         printf("\ningrese el a%co......:",164);
        scanf("%d", &g.anio);
         if(g.anio!=2020){
            printf("\n　Ese a%co no esta Disponible,Ingrese el a%co Actual Por favor.\n",164,164);
         }

        }while(g.anio!=2020);

      do{
         printf("\ningrese el mes.......:");
         scanf("%d", &g.mes);
          if(g.mes<1 || g.mes>6){
            printf("\n　Ingrese Un mes Entre el 1(enero) al mes actual Por favor.\n");
         }
        }while(g.mes<1 || g.mes>6);

        dias=CalcularDias(g.mes,g.anio);
       do{
         printf("\ningrese un dia.......:");
         scanf("%d", &g.dia);
            if(g.dia<1 || g.dia>dias){
            printf("\n　Ingrese Un dia Entre el periodo de 1 a %d Por favor.\n",dias);
         }

         }while(g.dia<1 || g.dia>dias);
         g.baja=baja;

     ///Revisar todo lo refirido a existen Consumos.

    return g;
}

/*********************************************************************//**
*
* \brief Carga un consumo de manera automatica y random
* \param no tiene paremetros
* \return Retorna el consumo
*
**************************************************************************/
stConsumo cargaConsumoAuto(){

    stConsumo g;

    int dia;

    g.idCliente=rangoRandom(0,buscaUltimoId());

    g.anio=2020;
    g.mes=rangoRandom(1,7);
    dia = CalcularDias(g.mes,g.anio);
    g.dia=rangoRandom(1,dia);
    g.datosConsumidos=rangoRandom(30,1000);

 return g;
}

/*********************************************************************//**
*
* \brief Muestra un consumo
* \param Recibe el consumo
* \return es void
*
**************************************************************************/
void mostrarUnConsumo(stConsumo g)
{

    printf("\n-----------------------\n");
    printf("\nNumero Id........:%d",g.id);
    printf("\nIdCliente........:%d",g.idCliente);
    printf("\nDatos consumidos.:%d",g.datosConsumidos);
    printf("\nA%co..............:%d",164,g.anio);
    printf("\nMes..............:%d",g.mes);
    printf("\nDia..............:%d",g.dia);
    printf("\nBaja.............:%d\n",g.baja);
    printf("\n-----------------------\n");
}

