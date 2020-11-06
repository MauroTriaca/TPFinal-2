#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "clientes.h"

void cargaArchivoCLientes(stCliente c) ;
void cargaCLientes();
///------------------------------------------------------------------------------------------------------------------------------
int funcion00(stCliente c[], int v, int dim);
///------------------------------------------------------------------------------------------------------------------------------
void arreglo2archivo(stCliente a[],int v);

void mostrarArchivoClientes();
void mostrarArchivoClientesInactivos();
int cuentaRegistro(char nombreArchivo[],int dato);
int buscaUltimoId();
///todas veficaciones de si existe el cliente
int buscaUnClienteDNIArchivo(int dni);
int buscaUnNroClienteArchivo(int nroCliente);
int buscaUnNroMovilArchivo(int movil);
///devuelven el cliente
stCliente buscaClientePorApellido(char apellido[]);
stCliente buscaClientePorDni(int dni);

int archivo2arrayBaja(stCliente a,stCliente c[DIM_CLI]);
int archivo2arrayActivos(stCliente a,stCliente c[DIM_CLI]);


#endif // ARCHIVOCLIENTES_H_INCLUDED
