#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "clientes.h"
#include "archivoClientes.h"
#include "archivoConsumos.h"

/// estructura de datos

typedef struct nodoArbol
{
    stCliente dato;
    nodo * lista;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

/// funciones basicas
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(stCliente dato);
nodoArbol * insertar (nodoArbol * arbol, stCliente dato);

void inorder(nodoArbol * arbol);

void preorder(nodoArbol * arbol);

void postorder(nodoArbol * arbol);

nodoArbol * buscar(nodoArbol * arbol, stCliente dato);

int sumarValoresArbol(nodoArbol * arbol);

///-------------------------------------------Arbol de Listas-------------------------///
nodoArbol * cliente2Arbol(nodoArbol* arbol);
nodoArbol* asignaConsumosArbol(nodoArbol*arbol);
nodoArbol* buscaClienteEnArbol(nodoArbol* arbol, int nroCliente);
nodoArbol* buscaClienteEnArbol(nodoArbol* arbol, int idCliente);

void mostrarNodoArdl(nodoArbol* ardl);

nodoArbol* liquidarUnMesdeConsumos(nodoArbol* arbol, int idCliente);



#endif // ARBOL_H_INCLUDED
