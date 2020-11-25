#include "utilidades.h"

/*********************************************************************//**
*
* \brief valida que tenga un "@" el email del cliente
* \param recibe el email
* \return es void
*
**************************************************************************/
int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0)
    {
        if(email[i]==64)/// =='@'
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

///\brief mostrar un arreglo, recibe el arreglo y sus validos
void mostrarArray(int a[],int v){

  for(int i=0;i<v;i++){
    printf("\n%d\n",a[i]);
  }

}

///carga a 50 consumos por cliente
void cargar50consumos(){
     int veces = 50;
     stCliente cli;
     FILE* archi = fopen(AR_CLIENTES, "rb");

     if(archi){
        while(fread(&cli, sizeof(stCliente), 1, archi)>0){
            cargaConsumosEspecificos(cli.id, veces);
        }
        fclose(archi);
     }

}

void imprimirFactura(stCliente cli, int total,int anio, int mes){

printf("\n**********************************************************************");
printf("\n*     Nombre.......: %s                                               ",cli.nombre);
printf("\n*     Apellido.....: %s                                               ",cli.apellido);
printf("\n*     Nro. Cliente.: %d                                              ",cli.nroCliente);
printf("\n*     DNI..........: %d                                               ",cli.dni);
printf("\n*     Email........: %s                                               ",cli.email);
printf("\n*     Domicilio....: %s                                               ",cli.domicilio);
printf("\n*     Nro. Movil...: %d                                              ",cli.movil);
printf("\n*                                                                     ");
printf("\n********************************FACTURA DEL MES***********************");
factura(total,2.15);
printf("\n**********************************************************************\n");
}
///imprime la factura con todos los calculos
void factura(int cantidadCons, float precio){
     int  IVA;
    IVA = 21;

    float totalIVA, subtotal, total;


    subtotal = (float)cantidadCons * precio;
    totalIVA = (float)(subtotal *  IVA) / 100;
    total = subtotal + totalIVA;
    printf("\n                  \n");
    printf("Cantidad           Precio de un MB pesos      Total\n");
    printf("%4dMB        *           $%.2f               $%.2f\n\n",cantidadCons, precio, subtotal);
    printf("Con un IVA del %d%%     se le sumaran          $%.2f\n\n", IVA, totalIVA);
    printf("Total a pagar................................:$%.2f\n", total);

}


