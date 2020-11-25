#include "archivoClientes.h"
/*********************************************************************//**
*
* \brief Carga el un cliente en el archivo
* \param recibe un cliente
* \return es void
*
**************************************************************************/
void cargaArchivoCLientes(stCliente c)
{

    FILE *archi=fopen(AR_CLIENTES,"ab");
    if(archi!=NULL)
    {
        fwrite(&c,sizeof(stCliente),1,archi);
        fclose(archi);
    }
}

/*********************************************************************//**
*
* \brief Carga los cliente en el archivo
* \param no tiene paremetros
* \return es void
*
**************************************************************************/
void cargaCLientes()
{

    char opcion;

    while(opcion!=ESC)
    {
        system("cls");
        printf("\nCarga de Clientes\n");

        cargaArchivoCLientes(cargaUnClienteConId());
        ///primero se carga el cliente y luego se guarda en el archivo con cargaArhivosClientes

        printf("\nPresione ESC para dejar de cargar\n");
        fflush(stdin);
        opcion=getch();
    }

}

///--------------------------------------------------------------------------------------------------------------------------
/*********************************************************************//**
*
* \brief Crea clientes automaticamente
* \param recibe un arreglo de clientes, sus validos y dimension
* \return Retorna los validos cargados
*
**************************************************************************/
int funcion00(stCliente c[], int v, int dim){///rehacer por que funciona de  suerte, la idea de esta funcion es carga una cantidad
    int ultimoid=0;///de clientes(aleatorios) automatica.
    int contador=0;
    printf("\n Cargando Clientes");
    ultimoid= buscaUltimoId()+1;
    c[v]=cargoRegistroClienteRandom();
    c[v].id = ultimoid;
    contador++;
    v++;
    while(v<dim){
        c[v]=cargoRegistroClienteRandom();
        fflush(stdin);
        c[v].id=ultimoid+contador++;
        v++;

    }
    arreglo2archivo(c,v);;

    printf("\n Cargados exitosamente...\n");
    return v;
}

/*********************************************************************//**
*
* \brief pasa los datos del arreglo de clientes a un archivo
* \param recibe el arreglo de clientes, y sus validos
* \return es void
*
**************************************************************************/
void arreglo2archivo(stCliente a[],int v){
 FILE *pArchClientes = fopen(AR_CLIENTES,"ab");
 if(pArchClientes){
    fwrite(a,sizeof(stCliente),v,pArchClientes);
    fclose(pArchClientes);
 }
}

/*********************************************************************//**
*
* \brief muestra el archivo de clientes(internamente muestra un cliente)
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void mostrarArchivoClientes()
{
    stCliente c;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        while(fread(&c,sizeof(stCliente),1,archi) >0)
        {
            mostrarUnClienteId(c);
        }
        fclose(archi);
    }
}

/*********************************************************************//**
*
* \brief muestra el archivo de clientes activos
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void mostrarArchivoClientesActivos()
{
    stCliente c;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        while(fread(&c,sizeof(stCliente),1,archi) >0)
        {
            if(c.baja==0)
            {
                mostrarUnClienteId(c);
            }
        }
        fclose(archi);
    }
}

/*********************************************************************//**
*
* \brief muestra el archivo de clientes inactivos
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void mostrarArchivoClientesInactivos()
{
    stCliente c;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        while(fread(&c,sizeof(stCliente),1,archi) >0)
        {
            if(c.baja==1)
            {
                mostrarUnClienteId(c);
            }
        }
        fclose(archi);
    }
}

/*********************************************************************//**
*
* \brief Cuenta la cantidad de clientes en el archivo
* \param Recibe el archivo y dato es el sizeof del cliente
* \return Retorna la cantidad de elementos en el archivo
*
**************************************************************************/
int cuentaRegistro(char nombreArchivo[],int dato) ///dato va a ser el sizeof de stCliente
{

    int total=0;

    FILE *archi=fopen(nombreArchivo,"rb");

    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        total=ftell(archi)/dato;

        fclose(archi);
    }
    return total;
}

/*********************************************************************//**
*
* \brief busca el ultimo id en el archivo de clientes
* \param no tiene parametros
* \return retorna la ultima id
*
**************************************************************************/
int buscaUltimoId()
{
    stCliente c;
    int id=-1;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        fseek(archi,sizeof(stCliente)*-1,SEEK_END);
        if(fread(&c,sizeof(stCliente),1,archi)>0)
        {
            id=c.id;
        }
        fclose(archi);
    }

    return id;
}

/*********************************************************************//**
*
* \brief busca un cliente por dni en el archivp
* \param recibe el dni del cliente a buscar
* \return 1 si existe 0 sino
*
**************************************************************************/
int buscaUnClienteDNIArchivo(int dni)
{
    int flag = 0;
    stCliente c;
    FILE *pArch = fopen(AR_CLIENTES, "rb");
    if(pArch!=NULL)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente),1,pArch) > 0)
        {
            if(c.dni==dni)
            {
                flag=1;
            }
        }
        fclose(pArch);
    }

    return flag;
}

/*********************************************************************//**
*
* \brief busca un cliente por nro. de cliente en el archivp
* \param recibe el nro de clienre
* \return 1 si existe 0 sino
*
**************************************************************************/
int buscaUnNroClienteArchivo(int nroCliente){
    int flag = 0;
    stCliente c;
    FILE *pArch = fopen(AR_CLIENTES, "rb");
    if(pArch!=NULL)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente),1,pArch) > 0)
        {
            if(c.nroCliente==nroCliente)
            {
                flag=1;
            }
        }
        fclose(pArch);
    }

    return flag;
}

/*********************************************************************//**
*
* \brief busca un cliente por movil en el archivp
* \param recibe el movil
* \return 1 si existe 0 sino
*
**************************************************************************/
int buscaUnNroMovilArchivo(int movil)
{
    int flag = 0;
    stCliente c;
    FILE *pArch = fopen(AR_CLIENTES, "rb");
    if(pArch!=NULL)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente),1,pArch) > 0)
        {
            if(c.movil==movil)
            {
                flag=1;
            }
        }
        fclose(pArch);
    }

    return flag;
}

/*********************************************************************//**
*
* \brief busca un cliente por apellido en el archivp
* \param recibe el char apellido (string)
* \return el cliente con ese apellido (si existe)
*
**************************************************************************/
stCliente buscaClientePorApellido(char apellido[])
{
    int flag=0;
    stCliente c;
    FILE *archi = fopen(AR_CLIENTES,"rb");
    if(archi)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1,archi) > 0)
        {
            if(strcmp(c.apellido,apellido)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }

    if(flag==0)
    {
        c.id=-1;
    }

    return c;
}
/*********************************************************************//**
*
* \brief busca un cliente por dni en el archivp
* \param recibe el dni (int)
* \return el cliente con ese dni (si existe)
*
**************************************************************************/
stCliente buscaClientePorDni(int dni)
{
    int flag=0;
    stCliente c;
    FILE *archi = fopen(AR_CLIENTES, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1,archi) > 0)
        {
            if(c.dni==dni)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag==0)
    {
        c.id=-1;
    }

    return c;
}

/*********************************************************************//**
*
* \brief pasa de el archivo clientes solo los clientes que estan "debaja" a un arreglo.
* \param  el cliente, y un arreglo de clientes
* \return los validos
*
**************************************************************************/
int archivo2arrayBaja(stCliente a,stCliente c[DIM_CLI])
{
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    while(fread(&a,sizeof(stCliente),1,pArchClientes)>0){
        if(a.baja == 1){
            c[v]=a;
            v++;
        }
    }
    fclose(pArchClientes);
 }

 return v;
}

/*********************************************************************//**
*
* \brief pasa de el archivo clientes solo los clientes que estan "activos" a un arreglo.
* \param el cliente y un arreglo de clientes
* \return los validos
*
**************************************************************************/
int archivo2arrayActivos(stCliente a,stCliente c[DIM_CLI])
{
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    while(fread(&a,sizeof(stCliente),1,pArchClientes)>0){
        if(a.baja == 0){
            c[v] = a;
            v++;
        }
    }
    fclose(pArchClientes);
 }
 return v;
}

/*********************************************************************//**
*
* \brief Busca un cliente por ID
* \param ID de cliente a buscar
* \return 1 si existe, -1 si no existe
*
**************************************************************************/
int buscaCliente(int id)
{
    int flag=-1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes)
    {
        while(flag == -1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0)
        {
            if(c.id==id)
            {
                flag=1;
            }
        }
        fclose(pArchClientes);
    }
    return flag;
}

/*********************************************************************//**
*
* \brief Busca posicion del cliente por ID
* \param ID de cliente a buscar
* \return -1 si no existe - Retorna la posicion del cliente si existe
*
**************************************************************************/
int buscaPosicion(int id)
{
    int pos=-1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes)
    {
        while(pos == -1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0)
        {
            if(c.id == id)
            {
                pos = ftell(pArchClientes)/sizeof(stCliente)-1;
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}

/*********************************************************************//**
*
* \brief Retorna el cliente a buscar
* \param Ingresa la ID del cliente a buscar
* \return retorna el cliente si existe
*
**************************************************************************/
stCliente traeCliente(int id)
{
    stCliente c;
    int flag = 0;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes)
    {
        while(flag==0 && fread(&c,sizeof(stCliente),1,pArchClientes)>0)
        {
            if(c.id == id)
            {
                flag = 1;
            }
        }
        fclose(pArchClientes);
    }

    if(flag==1){
    return c;
    }
    else{
        printf("Id:%d no Existente.",id);
        printf("\nIngrese id correcto:");
        scanf("%d",&id);
        traeCliente(id);
    }
}

stCliente buscaClientePorId(int id){
    int flag=0;
    stCliente c;
    FILE *archi = fopen(AR_CLIENTES, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1,archi) > 0)
        {
            if(c.id==id)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag==0)
    {
        c.id=-1;
    }

    return c;
}



