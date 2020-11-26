#include "lista.h"

///funcion que inicializa la lista en NULL,para luego poder  saber si esta vacia.
nodo* inicLista(){
  return NULL;
}

/*********************************************************************//**
*
* \brief crea  un puntero a un nodo
* \param recibe un consumo
* \return retorna  un puntero al nodo
*
**************************************************************************/
nodo* crearNodo(stConsumo e){

 nodo* nuevo = (nodo*) malloc(sizeof(nodo));
 nuevo->dato = e;
 nuevo->siguiente = NULL;
return nuevo;
}

/*********************************************************************//**
*
* \brief agrega un nodo al principio de la lista
* \param recibe un puntero a un nodo(lista) y otro puntero a un nodo(nuevo nodo)
* \return retorna  un puntero al nodo(lista)
*
**************************************************************************/
nodo* agregarAlPrincipio(nodo* lista, nodo* nodoNuevo){

    if(lista==NULL){
        lista = nodoNuevo;
    }else{
     nodoNuevo->siguiente = lista;
     lista = nodoNuevo;
    }

 return lista;
}

/*********************************************************************//**
*
* \brief agrega un nodo al final de la lista
* \param recibe un puntero a un nodo(lista) y otro puntero a un nodo(nuevo nodo)
* \return retorna  un puntero al nodo(lista)
*
**************************************************************************/
nodo* agregarFinal(nodo* lista, nodo* nodoNuevo){

    if(lista==NULL){
        lista = nodoNuevo;
    }else{
     nodo* nodoUltimo = buscarUltimo(lista);
     nodoUltimo->siguiente = nodoNuevo;
    }

 return lista;
}

/*********************************************************************//**
*
* \brief muestra un nodo
* \param recibe un puntero a un nodo que va a mostrar
* \return es void
*
**************************************************************************/
void mostrarNodo(nodo* nodoAMostrar){
  ///printf("\nMi direccion: %p - Direccion del siguiente:%p", nodoAMostrar, nodoAMostrar->siguiente); ///didactico--------------------------
  mostrarUnConsumo(nodoAMostrar->dato);
}

/*********************************************************************//**
*
* \brief muestra una lista
* \param recibe un puntero a un nodo(lista) que va a mostrar
* \return es void
*
**************************************************************************/
void mostrarLista(nodo* lista){
   nodo* seg = lista;

   while(seg){
    mostrarNodo(seg);
    seg = seg->siguiente;
   }

}

/*********************************************************************//**
*
* \brief busca el ultimo nodo de una lista
* \param recibe un puntero a un nodo(lista)
* \return un puntero a ese ultimo nodo
*
**************************************************************************/
nodo* buscarUltimo(nodo* lista){
   nodo* seg = lista;

   while(seg->siguiente!=NULL){

    seg = seg->siguiente;

   }
 return seg;
}

/*********************************************************************//**
*
* \brief borra una lista, liberando la memoria
* \param recibe un puntero a un nodo(lista)
* \return un puntero a la lista por que se modifico la lista
*
**************************************************************************/
nodo* borrarLista(nodo* lista){///la unica manera de elimir una lista es nodo por nodo

      nodo* seg = lista;
      nodo* proximo;

      while(seg){
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
      }

   return seg;
}
///borra nodos de la lista, filtrando por la id
nodo* borrarListaConFiltro(nodo* lista, int id){///la unica manera de elimir una lista es nodo por nodo

      nodo* seg = lista;
      nodo* proximo;

      while(seg){

        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
      }

   return seg;
}

/*********************************************************************//**
*
* \brief borra un solo nodo de la lista
* \param recibe un puntero a un nodo(lista)
* \return un puntero al nodo de la lista por que se modifico
*
**************************************************************************/
nodo* borrarNodoListaId(nodo* lista, int idCliente){

      nodo* seg;
      nodo* ante;


      if(lista && lista->dato.idCliente == idCliente){

        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);

      }else{
       seg = lista;

       while(seg && seg->dato.idCliente < idCliente){
        ante = seg;
        seg = seg->siguiente;
       }

        if(seg){
         ante->siguiente = seg->siguiente;
         free(seg);
         }

      }

  return lista;
}

/*********************************************************************//**
*
* \brief cuenta la cantida de nodos en una lista
* \param recibe un puntero a un nodo(lista)
* \return la cantidad de nodos en la lista
*
**************************************************************************/
int cuentaLista(nodo* lista){
 nodo* seg = lista;
 int cont = 0;

    while(seg){
      cont++;
      seg = seg->siguiente;
      }

return cont;
}

/*********************************************************************//**
*
* \brief elimina el ultimo nodo de una lista
* \param recibe un puntero a un nodo(lista)
* \return un puntero a la lista, por que se modifica
*
**************************************************************************/
nodo* eliminaUltimoNodo(nodo* lista){

   nodo* aux = lista;
   nodo* ante;

   while(aux->siguiente){
    ante = aux;
    aux = aux->siguiente;
   }

   free(aux);
   ante->siguiente = NULL;

  return lista;
}

/*********************************************************************//**
*
* \brief borra el primer nodo de una lista, liberando la memoria
* \param recibe un puntero a un nodo(lista)
* \return un puntero a la lista por que se modifico
*
**************************************************************************/
nodo* eliminaPrimerNodo(nodo* lista){

    nodo* aux = lista;
    lista = lista->siguiente;
    free(aux);

  return lista;
}

/*********************************************************************//**
*
* \brief nos da el primer consumo de una lista
* \param recibe un puntero a un nodo(lista)
* \return el primer consumo de la lista
*
**************************************************************************/
stConsumo verPrimero(nodo* lista){
  return lista->dato;
}

/// Suma datosConsumidoss de manera iterativa
int sumardatosConsumidossLista(nodo* lista)
{
    int suma = 0;
    nodo* seg = lista;
    while (seg)
    {
        suma = suma + seg->dato.datosConsumidos;
        seg = seg->siguiente;
    }
    return suma;
}
/// Suma datosConsumidoss de manera recursiva
int sumardatosConsumidossListaRecursivo(nodo* lista)
{
    int suma=0;
    if(lista)
    {
        suma=lista->dato.datosConsumidos + sumardatosConsumidossListaRecursivo(lista->siguiente);
    }
    return suma;
}
/// Suma datosConsumidoss de manera recursiva con un operador ternario
int sumardatosConsumidossListaRecursivoTernario(nodo* lista)
{
    return (lista)?lista->dato.datosConsumidos + sumardatosConsumidossListaRecursivoTernario(lista->siguiente):0;
}

/***
* \brief Calcula suma todos  los  megabytes consumidos en un  mes.
* \param Recibe un nodo(lista), un año, un mes
* \return Retorna un entero.
*/
int cuentaTotal(nodo* lista, int anio, int mes){
    nodo* seg = lista;
    int mbsTotales;

    if(seg){
        while(seg){
            if(seg->dato.anio == anio && seg->dato.mes == mes){
                mbsTotales = mbsTotales + seg->dato.datosConsumidos;
            }
            seg = seg->siguiente;
        }
    }
    return mbsTotales;
}



