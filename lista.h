#ifndef LISTAEMPS_H_INCLUDED
#define LISTAEMPS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ArchivoClientes.h"
#include "ArchivoConsumos.h"


typedef struct _nodo{

  stConsumo dato;
  struct _nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stConsumo e);

nodo* agregarAlPrincipio(nodo* lista,nodo* nodoNuevo);
nodo* agregarFinal(nodo* lista,nodo* nodoNuevo);


void mostrarNodo(nodo* nodoAMostrar);
void mostrarLista(nodo* lista);

nodo* buscarUltimo(nodo* lista);

nodo* borrarLista(nodo* lista);
nodo* borrarNodoListaId(nodo* lista, int idCliente);

int cuentaLista(nodo* lista);

nodo* eliminaUltimoNodo(nodo* lista);
nodo* eliminaPrimerNodo(nodo* lista);

stConsumo verPrimero(nodo* lista);


int sumardatosConsumidossLista(nodo* lista);
int sumardatosConsumidossListaRecursivo(nodo* lista);
int sumardatosConsumidossListaRecursivoTernario(nodo* lista);

int cuentaTotal(nodo* lista, int anio, int mes);

#endif // LISTAEMPS_H_INCLUDED
