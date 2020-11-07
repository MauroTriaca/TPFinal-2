#include "ordenamientosYestadisticas.h"

/*********************************************************************//**
*
* \brief intercambia 2 variables de tipo cliente
* \param un cliente tipo puntero a, un cliente tipo puntero b
* \return es void
*
**************************************************************************/
void CambiaValoresCliente(stCliente *a,stCliente *b)
{
 stCliente aux;
 aux = *a;
 *a = *b;
 *b = aux;
}

/*********************************************************************//**
*
* \brief Busca el menor por dni em un arreglo de clientes
* \param arreglo de clientes, sus validos, y el inicio
* \return la posicion del menor
*
**************************************************************************/
int buscaMenorPosDni(stCliente a[],int v,int inicio)
{
    int posMenor=inicio;
    int i=inicio+1;
    while(i<v){
        if(a[i].dni < a[posMenor].dni){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/*********************************************************************//**
*
* \brief ordena por seleccion los clientes de un arreglo segun el dni
* \param el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
void ordenarSelDni(stCliente a[],int v)
{
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor = buscaMenorPosDni(a,v,i);
        CambiaValoresCliente(&a[posMenor], &a[i]);
        i++;
    }
}

/*********************************************************************//**
*
* \brief Busca el menor segun el apellido
* \param el arreglo de clientes, sus validos y el inicio
* \return la posicion del menor
*
**************************************************************************/
int buscaMenorPosApe(stCliente a[],int v,int inicio)
{
 int PosMenor = inicio;
 int i=inicio+1;
 while(i<v){
    if(strcmp(a[i].apellido,a[PosMenor].apellido)<0){
        PosMenor = i;
    }
    i++;
 }
  return PosMenor;
}

/*********************************************************************//**
*
* \brief Busca el menor segun el email
* \param el arreglo de clientes, sus validos y el inicio
* \return la posicion del menor
*
**************************************************************************/
int buscaMenorPosEmail(stCliente a[],int v,int inicio)
{
 int PosMenor = inicio;
 int i=inicio+1;
 while(i<v){
    if(strcmp(a[i].email,a[PosMenor].email)<0){
        PosMenor=i;
    }
    i++;
 }
  return PosMenor;
}

/*********************************************************************//**
*
* \brief ordena por seleccion los clientes de un arreglo segun el email
* \param el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
void OrdenarSelEmail(stCliente a[],int v)
{
 int posMenor;
 stCliente aux;
 int i=0;

 while(i<v-1){
    posMenor = buscaMenorPosEmail(a,v,i);
    aux = a[posMenor];
    a[posMenor] = a[i];
    a[i] = aux;
    i++;
 }
}

/*********************************************************************//**
*
* \brief ordena por los emails del archivo de clientes
* \param el clientes
* \return es void
*
**************************************************************************/
void ordenarEmails(stCliente a)
{
 stCliente c[DIM_CLI];
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    v = archivo2arrayBaja(a,c);
    fclose(pArchClientes);
 }
 OrdenarSelEmail(c,v);
 muestraClientes(c,v);
}

/*********************************************************************//**
*
* \brief ordena por seleccion los clientes de un arreglo segun el apellido
* \param el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
void ordenarSelApe(stCliente a[],int v)
{
 int posMenor;
 stCliente aux;
 int i=0;

 while(i<v-1){
    posMenor = buscaMenorPosApe(a,v,i);
    aux = a[posMenor];
    a[posMenor] = a[i];
    a[i] = aux;
    i++;
 }
}

/*********************************************************************//**
*
* \brief ordena el archivo de clientes segun el apellido
* \param el cliente
* \return es void
*
**************************************************************************/
void ordenarApellidos(stCliente a)
{
 stCliente c[DIM_CLI];
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    v = archivo2arrayActivos(a,c);
    fclose(pArchClientes);
 }
 ordenarSelApe(c,v);
 muestraClientes(c,v);
}

/*********************************************************************//**
*
* \brief ordena el archivo de clientes segun dni
* \param el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
void ordenarDNIS(stCliente a)
{
 stCliente c[DIM_CLI];
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
      v = archivo2arrayActivos(a,c);
      fclose(pArchClientes);
}
  ordenarSelDni(c,v);
  muestraClientes(c,v);
 }

 /*********************************************************************//**
*
* \brief muestra arreglo de clientes
* \param el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
 void muestraClientes(stCliente c[], int v)
{
    printf("\n\t\t Listado de Clientes");
    for(int i=0;i<v;i++){
        mostrarUnClienteId(c[i]);
    }
    printf("\n");
}
///-------------------------------consumos
/*********************************************************************//**
*
* \brief ordena los consumos por mes
* \param el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
int ordenarMES(stConsumo a,int dato){
 stConsumo c[DIM_CLI];
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayConsumos(a,c,dato);
      fclose(pArchConsumos);
}
  muestraConsumos(c,v);
  return v;
 }
/*********************************************************************//**
*
* \brief muestra un arreglo de consumos (en un mes)
* \param el arreglo de consumos, y sus validos
* \return es void
*
**************************************************************************/
void muestraConsumos(stConsumo c[], int v)
{
    if(v!=0){
    printf("\n\t----Listado Consumos----\n");
    for(int i=0;i<v;i++){
        mostrarUnConsumo(c[i]);
    }
    printf("\n");
    }else{
    printf("\n\t---No se realizaron consumos este mes---\n");
    printf("\n");
    }
}

/*********************************************************************//**
*
* \brief pasa un mes el archivo de consumos entero a un arreglo de consumos
* \param el consumo, el arreglo de consumos, y dato(mes)
* \return los validos
*
**************************************************************************/
int archivo2arrayConsumos(stConsumo a,stConsumo c[DIM_CLI],int dato){
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
    while(fread(&a,sizeof(stConsumo),1,pArchConsumos)>0){
        if(a.mes == dato){
            c[v] = a;
            v++;
        }
    }
    fclose(pArchConsumos);
 }
 return v;
}

/*********************************************************************//**
*
* \brief pasa un mes del campo de consumos de el archivo de consumos a un arreglo
* \param el consumo, el arreglo, y dato(mes)
* \return los validos
*
**************************************************************************/
int archivo2arrayDatos(stConsumo a,int c[DIM_CLI],int dato){
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
    while(fread(&a,sizeof(stConsumo),1,pArchConsumos)>0){
        if(a.mes == dato){
            c[v] = a.datosConsumidos;
            v++;
        }
    }
    fclose(pArchConsumos);
 }
 return v;
}

/*********************************************************************//**
*
* \brief suma los datos del mes 1
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatos1(stConsumo a){
 int dato=1;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

/*********************************************************************//**
*
* \brief suma los datos del mes 2
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatos2(stConsumo a){
 int dato=2;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

/*********************************************************************//**
*
* \brief suma los datos del mes 3
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatos3(stConsumo a){
 int dato=3;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

/*********************************************************************//**
*
* \brief suma los datos del mes 4
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatos4(stConsumo a){
 int dato=4;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

/*********************************************************************//**
*
* \brief suma los datos del mes 5
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatos5(stConsumo a){
 int dato = 5;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 float porcentaje=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
 }

 /*********************************************************************//**
*
* \brief suma los datos del mes 6
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatos6(stConsumo a){
 int dato = 6;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
 }

 /*********************************************************************//**
*
* \brief muestra la suma de los datos de cada mes particular y su porcentaje
* \param el consumo
* \return es void
*
**************************************************************************/
void muestraSumaDatos(stConsumo a){
  int enero,febrero,marzo,abril,mayo,junio;
  enero=sumadatos1(a);
  printf("\nMES ENERO(1): %d (%.2f%%)\n",enero,calcularporcentaje2(a,enero));
  febrero=sumadatos2(a);
  printf("\nMES FEBRERO(2): %d (%.2f%%)\n",febrero,calcularporcentaje2(a,febrero));
  marzo=sumadatos3(a);
  printf("\nMES MARZO(3): %d (%.2f%%)\n",marzo,calcularporcentaje2(a,marzo));
  abril=sumadatos4(a);
  printf("\nMES ABRIL(4): %d (%.2f%%)\n",abril,calcularporcentaje2(a,abril));
  mayo=sumadatos5(a);
  printf("\nMES MAYO(5): %d (%.2f)\n",mayo,calcularporcentaje2(a,mayo));
  junio=sumadatos6(a);
  printf("\nMES JUNIO(6): %d (%.2f%%)\n",junio,calcularporcentaje2(a,junio));
 }

 /*********************************************************************//**
*
* \brief crea un arreglo con la suma de cada mes particular
* \param el consumo, un arreglo, y sus validos
* \return los validos
*
**************************************************************************/
int pasarArraySumaDatos(stConsumo a,int arraySumas[],int v){
    int enero,febrero,marzo,abril,mayo,junio;

    enero=sumadatos1(a);
    arraySumas[0]=enero;

    febrero=sumadatos2(a);
    arraySumas[1]=febrero;

    marzo=sumadatos3(a);
    arraySumas[2]=marzo;

    abril=sumadatos4(a);
    arraySumas[3]=abril;

    mayo=sumadatos5(a);
    arraySumas[4]=mayo;

    junio=sumadatos6(a);
    arraySumas[5]=junio;

    v=6;
    return v;
 }

/*********************************************************************//**
*
* \brief suma todos los datos de consumos que se le pasen
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int sumadatosAll(stConsumo a){
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayAlldato(a,c);
      fclose(pArchConsumos);
 }
  suma=sumararray(c,v);
  return suma;
}

/*********************************************************************//**
*
* \brief pasa el archivo de consumos el todos los campo consumo a un arreglo
* \param el consumo
* \return retorna la suma
*
**************************************************************************/
int archivo2arrayAlldato(stConsumo a,int c[DIM_CLI]){
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
    while(fread(&a,sizeof(stConsumo),1,pArchConsumos)>0){
            c[v] = a.datosConsumidos;
            v++;
    }
    fclose(pArchConsumos);
   }
   return v;
}

/*********************************************************************//**
*
* \brief calcular el porcentaje del mes de consumos
* \param el total
* \return el porcentaje
*
**************************************************************************/
float PorcentajeMesConsumo(int total){
 int mes =6;
 float porcentaje=0;
 porcentaje = (float)total / mes;
 return (float)porcentaje;
}

/*********************************************************************//**
*
* \brief suma todos los datos de un arreglo
* \param el arreglo y sus validos
* \return retorna la suma
*
**************************************************************************/
int sumararray(int a[],int validos){
 int i = 0;
 int suma =0;
 if(validos!=0){
 for(i=0;i<validos;i++){
  suma = suma + a[i];
  }
}
  return suma;
}

/*********************************************************************//**
*
* \brief calcular el porcentaje  de un mes de  consumos
* \param el consumo, y el mes
* \return el porcentaje
*
**************************************************************************/
float calcularporcentaje2(stConsumo a,int dato){
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 float porcentaje=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayAlldato(a,c);
      fclose(pArchConsumos);
 }
  suma=sumararray(c,v);
  porcentaje = (float)dato*100/suma;
  return (float)porcentaje;
 }

/*********************************************************************//**
*
* \brief pasa todo el archivo de consumos a un arreglo de consumos
* \param el consumo, un arreglo de consumos, sus validos y su dim
* \return sus validos
*
**************************************************************************/
int archivo2ArrayConsumosEnteros(stConsumo g,stConsumo conArray[],int v,int dim)
{

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            conArray[v]=g;
            v++;
        }
        fclose(archi);
    }

    return v;
}

/*********************************************************************//**
*
* \brief intercambia 2 variables de tipo consumo
* \param un consumo tipo puntero a, un consumo tipo puntero b
* \return es void
*
**************************************************************************/
 void CambiaValoresConsumo(stConsumo *a,stConsumo *b)
{
 stConsumo aux;
 aux = *a;
 *a = *b;
 *b = aux;
}

/*********************************************************************//**
*
* \brief Busca el menor por dia en un arreglo de consumos
* \param arreglo de clientes, sus validos, el inicio y el mes
* \return la posicion del menor
*
**************************************************************************/
int buscaMenorPosDia(stConsumo g[],int v,int inicio,int mes)
{
    int posMenor=inicio;
    int i=inicio+1;
      while(i<v){
        if(g[i].dia < g[posMenor].dia && g[posMenor].mes==g[i].mes){
            posMenor = i;
        }
        i++;
      }

    return posMenor;
}

/*********************************************************************//**
*
* \brief ordena por seleccion los dias de un arreglo de consumos
* \param arreglo de clientes, sus validos
* \return es void
*
**************************************************************************/
void ordenarSelDia(stConsumo g[],int v)
{
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor = buscaMenorPosDia(g,v,i,i);
        CambiaValoresConsumo(&g[posMenor], &g[i]);
        i++;
    }
}

/*********************************************************************//**
*
* \brief genera un arreglo de  dias, guardando el consumo entero
* \param arreglo de consumos, sus validos, y un arreglo de consumos para los dias
* \return sus validos
*
**************************************************************************/
int ordenarArrayConsumosPorDiaYMes(stConsumo g[],int v,stConsumo arreglodias[]){///la idea es ordenarlo primeramente por mes

int i=0;

  for(i=0;i<v;i++){
    arreglodias[i]=g[i];
    }
return i;
}

/*********************************************************************//**
*
* \brief Busca el menor por mes en un arreglo de consumos
* \param arreglo de clientes, sus validos, y el inicio
* \return la posicion del menor
*
**************************************************************************/
int buscaMenorPosMes(stConsumo g[],int v,int inicio)
{
    int posMenor=inicio;
    int i=inicio+1;
    while(i<v){
        if(g[i].mes < g[posMenor].mes){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/*********************************************************************//**
*
* \brief ordena por seleccion arreglo de meses(es un campo de consumos)
* \param arreglo de consumos y  sus validos
* \return es void
*
**************************************************************************/
void ordenarArrayConsumosPorMes(stConsumo g[],int v){///la idea es ordenarlo primeramente por mes
   int posMenor;
    int i=0;

    while(i<v-1){
        posMenor = buscaMenorPosMes(g,v,i);
        CambiaValoresConsumo(&g[posMenor], &g[i]);
        i++;
    }
}

///Se busca el MENOR consumo por mes
/*********************************************************************//**
*
* \brief Busca la posicion de el menor consumo por mes
* \param arreglo de clientes y sus validos
* \return la posicion del menor
*
**************************************************************************/
int buscaPosMenorConsumoMes(int a[],int v){
  int i=0;
  int posMenor=i;
  i++;
    while(i<v){
        if(a[posMenor]>a[i])
        {
            posMenor=i;
        }
       i++;
    }

return posMenor;
}

/*********************************************************************//**
*
* \brief Busca la posicion de el mayor consumo por mes
* \param arreglo de clientes , sus validos , el inicio y el mes
* \return la posicion del menor
*
**************************************************************************/
int buscaMayorPosDdia(stConsumo g[],int v,int inicio,int mes)
{
    int posMayor=inicio;
    int i=inicio+1;
      while(i<v){
        if(g[i].dia < g[posMayor].dia && g[posMayor].mes==g[i].mes){
            posMayor = i;
        }
        i++;
      }

    return posMayor;
}

/*********************************************************************//**
*
* \brief ordena por seleccion arreglo de consumos segun los dias
* \param arreglo de clientes y sus validos
* \return es void
*
**************************************************************************/
void ordenarSelDddia(stConsumo g[],int v)
{
    int posMayor;
    int i=0;

    while(i<v-1){
        posMayor = buscaMayorPosDdia(g,v,i,i);
        CambiaValoresConsumo(&g[posMayor], &g[i]);
        i++;
    }
}

/*********************************************************************//**
*
* \brief genera un arreglo de  dias, guardando el consumo entero
* \param arreglo de consumos, sus validos, y un arreglo de consumos para los dias
* \return sus validos
*
**************************************************************************/
int ordenarArrayConsumosPorDiaYMmes(stConsumo g[],int v,stConsumo arreglodias[]){///la idea es ordenarlo primeramente por mes

int i=0;

  for(i=0;i<v;i++){
    arreglodias[i]=g[i];
    }
return i;
}

/*********************************************************************//**
*
* \brief busca la poscion del mauor mes en un arreglo de consumos
* \param arreglo de consumos, sus validos, y el inicio
* \return la posicion del menor
*
**************************************************************************/
int buscaMayorPosMmes(stConsumo g[],int v,int inicio)

{
    int posMayor=inicio;
    int i=inicio+1;
    while(i<v){
        if(g[i].mes < g[posMayor].mes){
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

/*********************************************************************//**
*
* \brief ordena mediante seleccion arreglo de consumos por mes
* \param arreglo de consumos, sus validos, y un arreglo de consumos para los dias
* \return sus validos
*
**************************************************************************/
void ordenarArrayConsumosPorMmmes(stConsumo g[],int v){///la idea es ordenarlo primeramente por mes
   int posMayor;
    int i=0;

    while(i<v-1){
        posMayor = buscaMayorPosMmes(g,v,i);
        CambiaValoresConsumo(&g[posMayor], &g[i]);
        i++;
    }
}
///Se busca el MAYOR consumo por mes
/*********************************************************************//**
*
* \brief busca la posicion mayor de un arreglo
* \param un arreglo  de enteros y sus validos
* \return la posicion del mayor
*
**************************************************************************/
int buscaPosMayorConsumoMeees(int a[],int v)
{
  int i=0;
  int posMayor=i;
  i++;
    while(i<v){
        if(a[posMayor]<a[i])
        {
            posMayor=i;
        }
       i++;
    }

return posMayor;
}

/*********************************************************************//**
*
* \brief cuenta consumos activos por mes
* \param el mes
* \return los contados
*
**************************************************************************/
int cuentaConsumosActivosMes(int mes){
stConsumo c;
FILE *archi=fopen(AR_CONSUMOS,"rb");
int i=0;
int contador=0;
if(archi){
    while(fread(&c,sizeof(stConsumo),1,archi)>0){
        if(c.mes == mes){
            if(c.baja == 0){
                contador++;
      }
      }
    }
  }
  return contador;
}

/*********************************************************************//**
*
* \brief cuenta consumos inactivos por mes
* \param el mes
* \return los contados
*
**************************************************************************/
int cuentaConsumosInactivosMes(int mes){
stConsumo c;
FILE *archi=fopen(AR_CONSUMOS,"rb");
int i=0;
int contador=0;
if(archi){
    while(fread(&c,sizeof(stConsumo),1,archi)>0){
        if(c.mes == mes){
            if(c.baja == 1){
                contador++;
      }
      }
    }
  }
  return contador;
}

/*********************************************************************//**
*
* \brief cuenta clientes inactivos
* \param no tiene parametros
* \return los contados
*
**************************************************************************/
int cuentaClientesNegativos(){

stCliente c;
 FILE *archi=fopen(AR_CLIENTES,"rb");
 int i=0;
 if(archi){
    while(fread(&c,sizeof(stCliente),1,archi)>0){
        if(c.baja==1){
            i++;
        }
     }
  }
 return i;
}

/*********************************************************************//**
*
* \brief cuenta clientes activos
* \param no tiene parametros
* \return los contados
*
**************************************************************************/
int cuentaClientesPositivos(){

stCliente c;
 FILE *archi=fopen(AR_CLIENTES,"rb");
 int i=0;
 if(archi){
    while(fread(&c,sizeof(stCliente),1,archi)>0){
        if(c.baja==0){
            i++;
        }
     }
  }
 return i;
}

/*********************************************************************//**
*
* \brief muestra el porcentaje de clientes activos e inactivos
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void porcentajeClientesActivos_Inactivos(){
    float porcentajePositivos;
    float porcentajeNegativos;
    int positivos;
    int negativos;
    int total;

    positivos=cuentaClientesPositivos();
    negativos=cuentaClientesNegativos();

    total=positivos+negativos;

    if(positivos>0){
    porcentajePositivos=(float)positivos*100/total;
    }

    if(negativos>0){
    porcentajeNegativos=(float)negativos*100/total;
    }

    printf("\nEl Porcentajes de Clientes es:\n");
    printf("\nEl Porcentaje de activos es: %.2f%%\n",porcentajePositivos);
    printf("\nEl Porcentaje de inactivos es: %.2f%%\n",porcentajeNegativos);
    printf("\n\n");

}

/*********************************************************************//**
*
* \brief hace la sumatoria de todos los  consumos respecto a los dias
* \param no tiene parametros
* \return la sumatoria
*
**************************************************************************/
int sumatoriaDeDias(){
stConsumo g;
int sumatoria=0;

 FILE *archi=fopen(AR_CONSUMOS,"rb");

 if(archi){

    while(fread(&g,sizeof(stConsumo),1,archi)>0){
        sumatoria=sumatoria+g.datosConsumidos;
    }
 }

  return sumatoria;
}

/*********************************************************************//**
*
* \brief calcula el promedio de consumos por dia
* \param no tiene parametros
* \return el promedio
*
**************************************************************************/
float promedioXdia(){
    float promedio=0;
    int contados;
    int sumados;

    contados=cuentaRegistro(AR_CONSUMOS,sizeof(stConsumo));
    sumados=sumatoriaDeDias();

    if(contados>0){
    promedio=(float)sumados/contados;
    }

   return promedio;
}



