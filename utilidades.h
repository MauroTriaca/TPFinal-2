#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include "crudClientes.h"
#include "crudConsumos.h"


int validaEmail(char email[]);

void mostrarArray(int a[],int v);

void cargar50consumos();

void imprimirFactura(stCliente cli, int total,int anio, int mes);
void factura(int cantidadCons, float precio);
#endif // UTILIDADES_H_INCLUDED
