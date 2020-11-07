#include "crudClientes.h"

/*********************************************************************//**
*
* \brief Menu del Crud
* \param no tiene paremetros
* \return es void
*
**************************************************************************/
void modificarCliMenus()
{
    char opcion;
    do
    {
        system("cls");
        printf("\n MODIFICACION DE CLIENTES...\n");
        printf("\n 1-Modificar Nombre");///tenemos que pensar en poder modificar el NroCliente
        printf("\n 2-Modificar Apellido");
        printf("\n 3-Modificar DNI");
        printf("\n 4-Modificar email");
        printf("\n 5-Modificar Domicilio");
        printf("\n 6-Modificar Telefono Movil");
        printf("\n\n");
        printf("\n ESC para salir...");
        opcion=getch();
        switch(opcion)
        {
        case 49:
            modificarNombrex();
            break;
        case 50:
            ModificarApellidox();
            break;
        case 51:
            ModificarDNIx();
            break;
        case 52:
            ModificarEmailx();
            break;
        case 53:
            ModificarDomiciliox();
            break;
        case 54:
            ModificarMovilx();
            break;
        default:
            printf("\n Opcion incorrecta");
        }
        system("pause");
    }
    while(opcion!=27);
}

/*********************************************************************//**
*  FUNCIONES DE MODIFICACIONES
* \brief Modifica el campo de cliente que seleccine
*  SE SELECCIONA EL CAMPO A MODIFICAR DEL CLIENTE, LO TRAE POR ID Y
*  LO MODIFICA
**************************************************************************/

/*********************************************************************//**
*
* \brief modifica el nombre de un cliente por id
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void modificarNombrex()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    modificarnombre(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el nombre del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void modificarnombre(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo nombre: ");
        fflush(stdin);
        gets(c.nombre);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica el cliente ingresando su id por teclado
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void ModificarApellidox()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarApellido(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el apellido del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void ModificarApellido(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo apellido: ");
        fflush(stdin);
        gets(c.apellido);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica el cliente ingresando su id por teclado
* \param no tiene paremtros
* \return es void
*
**************************************************************************/
void ModificarDNIx()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarDNI(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el dni del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void ModificarDNI(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo DNI: ");
        scanf("%d",&c.dni);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica el  cliente ingresando su id por teclado
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void ModificarEmailx()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarEmail(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el email del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void ModificarEmail(stCliente c)
{
    int pos=0;
    pos=buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        do
        {
            printf("\nIngrese un nuevo EMAIL: ");
            fflush(stdin);
            gets(c.email);
        }
        while(!validaEmail(c.email));
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica el cliente ingresando su id por teclado
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void ModificarDomiciliox()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarDomicilio(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el domicilio del cliente por id
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void ModificarDomicilio(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo Domicilio: ");
        fflush(stdin);
        gets(c.domicilio);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica  el  cliente ingresando su id por teclado
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void ModificarMovilx()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID a Modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarMovil(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el movil del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void ModificarMovil(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo Movil: ");
        scanf("%d",&c.movil);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica el cliente ingresando su id por teclado
* \param no tiene paremetros
* \return es void
*
**************************************************************************/
void DarDeAltax()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID para dar de alta: ");
    scanf("%d",&id);
    c = traeCliente(id);
    DarDeAlta(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el campo baja del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void DarDeAlta(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\nCliente dado de alta exitosamente....\n");
        c.baja = 0;
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

/*********************************************************************//**
*
* \brief modifica el cliente ingresando su id por teclado
* \param no tiene parametros
* \return es void
*
**************************************************************************/
void DarDeBajax()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID para dar de baja: ");
    scanf("%d",&id);
    c = traeCliente(id);
    DarDeBaja(c);
}

/*********************************************************************//**
*
* \brief modifica en el registro el campo baja del cliente
* \param recibe el cliente
* \return es void
*
**************************************************************************/
void DarDeBaja(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Cliente dado de baja exitosamente.....\n\n");
        c.baja = 1;
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}


