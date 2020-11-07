#include "archivoConsumos.h"

/*********************************************************************//**
*
* \brief escribe un consumo en el archivo
* \param un consumo
* \return es void
*
**************************************************************************/
void cargaArchivoConsumos(stConsumo g)
{

    FILE *archi=fopen(AR_CONSUMOS,"ab");
    if(archi!=NULL)
    {
        fwrite(&g,sizeof(stConsumo),1,archi);
        fclose(archi);
    }
}

/*********************************************************************//**
*
* \brief carga un consumo por teclado al archivo y si hay consumos previos en la misma fecha los acumula
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void cargaConsumosTeclado()
{

    char opcion;

    stConsumo g;
    stConsumo gRead;
    int pos;
    int idTotal;
    idTotal=buscaUltimoIdConsumos();

     ///aca se verifica si el consumo no es creado previamente, por eso se usan 2 variables de consumo y si no esta creado
     ///se crea y se le añade un id, de esta manera no se duplican los consumos al acumularse
    while(opcion!=ESC)
    {
        system("cls");
        printf("\nCarga de Consumos:\n");

        g=cargaConsumoCliente();
        pos=existenConsumos(g.mes,g.dia,g.idCliente,g.baja);///esta funcion verifica si existe un consumo previo

      if(pos>-1) {///si pos es =-1 significa que no existian consumos previos y se va directamente al else
        FILE *archi=fopen(AR_CONSUMOS,"r+b");///abre el archivo en modo r+b para modificarlo
       if(archi){
        fseek(archi,sizeof(stConsumo)*pos,SEEK_SET);///encuentra el registro a modificar
        fread(&gRead,sizeof(stConsumo),1,archi);///con este fread se lee el registro del archivo
        gRead.datosConsumidos=gRead.datosConsumidos+g.datosConsumidos;/// y luego se acumulan con los del nuevo consumo

        fseek(archi,sizeof(stConsumo)*(-1),SEEK_CUR);///con fseek desde la posicion me muevo un registro para atras para quedar
                                                     ///por encima del registro a modicar
        g.datosConsumidos=gRead.datosConsumidos; ///aca cambio sus datos consumidos a los que serian acumulados los consumos

        fwrite(&gRead,sizeof(stConsumo),1,archi);/// aca finalmente escribo el registro
        fclose(archi);                           ///en si con todo esto lo que hice fue modificar(acumulando) el registro original
       }                                         /// en tiempo de ejecucion
    }
    else{
        FILE *archi=fopen(AR_CONSUMOS,"ab");///en este lugar se supone que el pos fue =-1 por lo tanto el consumo no existia
         if(archi){                         ///previamente, por eso lo creo abriendo en modo ab
         idTotal++;                         ///en la variable idTotal guardo el ultimo id y lo incremento para crear el consumo
         g.id=idTotal;                      ///luego ese valor se lo asigno a la id del consumo
         fwrite(&g,sizeof(stConsumo),1,archi);/// y al final escribo en el archivo ese consumo nuevo.
        fclose(archi);
       }
    }


        ///primero se carga el consumo y luego se guarda en el archivo de consumos
        printf("\nPresione ESC para dejar de cargar\n");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }

 }
 ///---------------------------------------------------------------------------------------------------------------------------
 /*********************************************************************//**
*
* \brief carga la cantidad que quieras consumos cargados de forma automatica en el archivo
* \param las cantidad de consumos que quieras(veces que se repite la carga de uno)
* \return es void
*
**************************************************************************/
 void cargaConsumos(int veces)
{

    stConsumo g;
    stConsumo gRead;
    int pos;
    int idTotal;

    idTotal=buscaUltimoIdConsumos()+1;

    printf("\nCarga de Consumos:\n");

    for(int i=0;i<veces;i++)
    {
        system("cls");


         g=cargarConsumosRandom();
         pos=existenConsumos(g.mes,g.dia,g.idCliente,g.baja);

       if(pos>-1) {
        FILE *archi=fopen(AR_CONSUMOS,"r+b");
       if(archi){
        fseek(archi,sizeof(stConsumo)*pos,SEEK_SET);
        fread(&gRead,sizeof(stConsumo),1,archi);
        gRead.datosConsumidos=gRead.datosConsumidos+g.datosConsumidos;

        fseek(archi,sizeof(stConsumo)*(-1),SEEK_CUR);
        g.datosConsumidos=gRead.datosConsumidos;

        fwrite(&gRead,sizeof(stConsumo),1,archi);
        fclose(archi);
       }
    }
    else{
        FILE *archi=fopen(AR_CONSUMOS,"a+b");
       if(archi){
         idTotal++;
         g.id=idTotal;
         fwrite(&g,sizeof(stConsumo),1,archi);
        fclose(archi);
       }
    }
        ///primero se carga el consumo y luego se guarda en el archivo de consumos

        fflush(stdin);
        system("cls");
    }
    printf("\nCargados Exitosamente\n");

 }

 /*********************************************************************//**
*
* \brief carga un consumo random acumulando si existe uno previametne
* \param no tiene parametros
* \return el consumo
*
**************************************************************************/
stConsumo cargarConsumosRandom()
{
    stConsumo g;
    stConsumo gRead;
    int pos;
    g = cargaConsumoAuto();
    pos=existenConsumos(g.mes,g.dia,g.idCliente,g.baja);

    if(pos>-1){
       FILE *archi=fopen(AR_CONSUMOS,"r+b");
       if(archi) {
        fseek(archi,sizeof(stConsumo)*pos,SEEK_SET);
        fread(&g,sizeof(stConsumo),1,archi);
        gRead.datosConsumidos=gRead.datosConsumidos+g.datosConsumidos;
        ///si no anda probar anadiendole el otro fseek y una lectura.
        fclose(archi);
       }
    }
    else{
        FILE *archiAux=fopen(AR_CONSUMOS,"ab");
        if(archiAux){
         g.id=buscaUltimoIdConsumos()+1;
         fclose(archiAux);
        }
    }

    g.baja=0;

    return g;
}
///----------------------------------------------------------------------------------------------------------------------------

 /*********************************************************************//**
*
* \brief calcula la cantidad de dias de un mes
* \param recibe un mes y un año (de un consumo)
* \return la cantidad de dias del mes
*
**************************************************************************/
int CalcularDias(int mes,int anio)
{
    int dias=0;
    switch(mes)
    {
    case 1:  // Enero
    case 3:  // Marzo
    case 5:  // Mayo
    case 7:  // Julio
    case 8:  // Agosto
    case 10:  // Octubre
    case 12: // Diciembre
        dias=31;
     break;
    case 4:  // Abril
    case 6:  // Junio
    case 9:  // Septiembre
    case 11: // Noviembre
        dias=30;
        break;
    case 2:  // Febrero
        if ( ((anio%100 == 0) && (anio%400 == 0)) ||((anio%100 != 0) && (anio%  4 == 0))   )
            dias=29;  // Año Bisiesto
        else
            dias=28;

    }
    return dias;
}

 /*********************************************************************//**
*
* \brief busca un consumo por fecha
* \param recibe un mes y un dia (de un consumo)
* \return si existe la posicion del consumo
*
**************************************************************************/
stConsumo buscaConsumoPorFecha(int mes,int dia)
{
    int flag=0;
    stConsumo g;
    FILE *archi = fopen(AR_CONSUMOS, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&g, sizeof(stConsumo), 1,archi) > 0)
        {
            if(g.mes==mes &&  g.dia==dia)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag==0)
    {
        g.id=-1;
    }

    return g;
}

 /*********************************************************************//**
*
* \brief verifica si hay un consumo previamente creado
* \param recibe un mes, un dia, un id del cliente, y baja (de un consumo)
* \return si existe la posicion del consumo, sino existe -1
*
**************************************************************************/
int existenConsumos(int mes,int dia,int idCliente,int baja){

    int flag=-1;
    stConsumo g;

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(flag==-1 && fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            if((g.mes==mes)&&(g.dia==dia)&&(g.idCliente==idCliente)&&(g.baja==baja)){

                flag=ftell(archi)/sizeof(stConsumo)-1;

            }
        }
        fclose(archi);
    }

return flag;
}

 /*********************************************************************//**
*
* \brief busca el ultimo id en el archivo de consumos
* \param no tiene parametros
* \return id
*
**************************************************************************/
int buscaUltimoIdConsumos()
{
    stConsumo g;
    int id=-1;

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {

        fseek(archi,sizeof(stConsumo)*-1,SEEK_END);
        if(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            id=g.id;
        }
        fclose(archi);
    }

    return id;
}


 /*********************************************************************//**
*
* \brief muestra el archivo de consumos
* \param no tiene parametros
* \return es void
*
**************************************************************************/
 void mostrarArchivoConsumos()
{
    stConsumo g;

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            mostrarUnConsumo(g);
        }
        fclose(archi);
    }
}

 /*********************************************************************//**
*
* \brief busca la posicion del consumo
* \param recibe una id de consumo
* \return la posicion si existe, si no existe -1
*
**************************************************************************/
int buscaPosicionConsumo(int id)
{
    int pos=-1;
    stConsumo c;
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo)
    {
        while(pos == -1 && fread(&c, sizeof(stConsumo), 1, pArchConsumo) > 0)
        {
            if(c.id == id)
            {
                pos = ftell(pArchConsumo)/sizeof(stConsumo)-1;
            }
        }
        fclose(pArchConsumo);
    }

    return pos;
}

 /*********************************************************************//**
*
* \brief trae un consumo buscado por id
* \param recibe el id del consumo
* \return retorna el consumo si existe
*
**************************************************************************/
stConsumo traeConsumo(int id)
{
    stConsumo g;
    int flag = 0;
    FILE  *pArchConsumo = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo)
    {
        while(flag==0 && fread(&g,sizeof(stConsumo),1,pArchConsumo)>0)
        {
            if(g.id == id)
            {
                flag = 1;
            }
        }
        fclose(pArchConsumo);
    }
    if(flag==1){
        return g;
    }
    else{
       printf("\nError,ingrese id nuevamente.\n");
       scanf("%d",&id);
       traeConsumo(id);
    }
}

