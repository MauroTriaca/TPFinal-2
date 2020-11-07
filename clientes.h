#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "gotoxy.h"
#define ESC 27
#define DIM_CLI 100

#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"

typedef struct
{
    int id;///unico y autoIncremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[30];
    int movil;
    int baja;///0(activado o 1(elimando)
} stCliente;

stCliente cargaUnClienteConId();///carga manual de cliente
///carga automatica de cliente
int rangoRandom(int min,int max);
int getNroCliente();
int getMovilCliente();
void getNombre(char n[]);
void getApellido(char a[]);
int getDNI();
void getCalle(char c[]);
int getCalleNro();
stCliente cargoRegistroClienteRandom();
///mostrar el cliente con id
void mostrarUnClienteId(stCliente c);


#endif // CLIENTES_H_INCLUDED
