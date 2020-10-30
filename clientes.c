#include "clientes.h"
stCliente cargaUnClienteConId()
{
    stCliente c;
    int repetido;
    int repetido2;
    int baja=0;///todos se cargan activos primeramente

    c.id=buscaUltimoId()+1;
    ///este ciclo sirve para validar la carga del numero de cliente
    do
    {
        printf("\nIngrese nro de Cliente.:");
        fflush(stdin);
        scanf("%d",&c.nroCliente);
        repetido=buscaUnNroClienteArchivo(c.nroCliente);
        if((c.nroCliente<0 ||  c.nroCliente>9999999) || repetido!=0)
        {

            printf("\n!!!!Error en la carga, Por favor intente nuevamente.\n");
        }
    }
    while((c.nroCliente<0 ||  c.nroCliente>9999999) || repetido!=0);


    printf("\nIngrese Nombre.........:");
    fflush(stdin);
    gets(c.nombre);
    printf("\nIngrese Apellido.......:");
    fflush(stdin);
    gets(c.apellido);

    do{
     printf("\nIngrese Dni............:");
     scanf("%d",&c.dni);
     repetido2=buscaUnClienteDNIArchivo(c.dni);
     if(repetido2!=0){
        printf("\n¡¡Error En la carga,intente Nuevamente Por favor.\n");
      }
    }while(repetido2!=0);
    ///con esto verifico que no haya dnis repetidos
    do
    {
        printf("\nIngrese el EMail...........: ");
        fflush(stdin);
        gets(c.email);
        if(!validaEmail(c.email))
        {
            printf("\n!!!!Error en la carga, Por favor intente nuevamente.\n");
        }
    }
    while(!validaEmail(c.email));
    printf("\nIngrese Domicilio......:");
    fflush(stdin);
    gets(c.domicilio);
    printf("\nIngrese Movil..........:");
    scanf("%d",&c.movil);
    c.baja=baja;

    return c;
}

void mostrarUnClienteId(stCliente c)
{

    printf("\n-----------------------\n");
    printf("\nNumero Id..:%d",c.id);
    printf("\nNroCliente.:%d",c.nroCliente);
    printf("\nNombre.....:%s",c.nombre);
    printf("\nApellido...:%s",c.apellido);
    printf("\nDni........:%d",c.dni);
    printf("\nEmail......:%s",c.email);
    printf("\nDomicilio..:%s",c.domicilio);
    printf("\nMovil......:%d",c.movil);
    printf("\nBaja.......:%d\n",c.baja);
    printf("\n-----------------------\n");
}

int rangoRandom(int min,int max)
{
    return rand()%(max-min)+min;
}

int getNroCliente(){
    int repetido;
    int validacion;
    do{
    repetido=rangoRandom(1,99999);
    validacion=buscaUnNroClienteArchivo(repetido);
    }while(validacion!=0);

return repetido;
}

int getMovilCliente(){
  int repetido;
  int validacion;
  do{
    repetido=rangoRandom(223578434,223999999);
    validacion=buscaUnNroMovilArchivo(repetido);
  }while(validacion!=0);
  return repetido;
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un nombre al azar
* \return void
*
*****************************************************************/
void getNombre(char n[]){
    char nombres[][30] = {"Amalio","Juan","Roberto","Antonio","Fernando","Anibal","Mariano","Jose",
                           "Anastasio","Arturo","Mario","Tamaro","Adolfo","Pedro","Alfredo","Arnaldo",
                           "Mauro","Benicio","Ildefonso","Cuchuflito","Remilgo","Miguel","Reinaldo"};

    strcpy(n,nombres[rangoRandom(0,sizeof(nombres)/(sizeof(char)*30))]);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un apellido al azar
* \return void
*
*****************************************************************/
void getApellido(char a[]){
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};

    strcpy(a,apellidos[rangoRandom(0,sizeof(apellidos)/(sizeof(char)*30))]);
}

/*********************************************************//**
*
* \brief Funcion que retorna un DNI de Cliente al azar
* \return int
*
*************************************************************/
int getDNI(){
    return rangoRandom(549,1982)* rangoRandom(549,19801);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido una calle al azar
* \return void
*
*****************************************************************/
void getCalle(char c[]){
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                            "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                            "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                            "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"};

    strcpy(c,calles[rangoRandom(0,sizeof(calles)/(sizeof(char)*30))]);
}

/*********************************************************//**
*
* \brief Funcion que retorna un Nro de calle de Cliente al azar
* \return int
*
*************************************************************/
int getCalleNro(){
    return rangoRandom(50,10000);
}

stCliente cargoRegistroClienteRandom(){
    stCliente c;

    c.id=buscaUltimoId()+1;
    c.nroCliente=getNroCliente();
    getNombre(c.nombre);
    getApellido(c.apellido);
    c.dni=getDNI();
    strcpy(c.email,c.nombre);
    strcat(c.email,"_");
    strcat(c.email,c.apellido);
    strcat(c.email,"@gmail.com");

    getCalle(c.domicilio);
    char nro[5];
    strcat(c.domicilio," ");
    strcat(c.domicilio, itoa(getCalleNro(),nro,10));
    c.movil = getMovilCliente();
    c.baja=0;
    return c;
}
