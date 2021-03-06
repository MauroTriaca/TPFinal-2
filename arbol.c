#include "arbol.h"

///inicializa el arbol
nodoArbol * inicArbol()
{
    return NULL;
}

/*********************************************************************//**
*
* \brief crea  un puntero a un nodo Arbol
* \param recibe un cliente
* \return retorna  un puntero al nodo Arbol creado
*
**************************************************************************/
nodoArbol * crearNodoArbol(stCliente dato)
{
    nodoArbol * aux = (nodoArbol *)malloc(sizeof(nodoArbol));

    aux->dato=dato;
    aux->lista = NULL; ///modif

    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

/*********************************************************************//**
*
* \brief suma los valores de un arbol
* \param recibe un puntero a nodoArbol
* \return retorna  la suma de sus valores
*
**************************************************************************/
int sumarValoresArbol(nodoArbol * arbol)
{
    int rta;
    if(arbol==NULL)
    {
        rta=0;
    }
    else
    {
        rta=arbol->dato.id+sumarValoresArbol(arbol->izq)+sumarValoresArbol(arbol->der);
    }
    return rta;
}

/*********************************************************************//**
*
* \brief insertar un nodoArbol, a un arbol
* \param recibe un puntero a nodoArbol, y un cliente
* \return retorna  el arbol
*
**************************************************************************/
nodoArbol * insertar (nodoArbol * arbol, stCliente dato)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(dato);
    }

    else
    {
        if(dato.id>arbol->dato.id)
        {
            arbol->der=insertar(arbol->der, dato);
        }
        else
        {
            arbol->izq=insertar(arbol->izq, dato);
        }
    }
    return arbol;
}

/*********************************************************************//**
*
* \brief muestra el arbol de manera izquierda, raiz y derecha
* \param recibe un puntero a nodoArbol
* \return es void
*
**************************************************************************/
void inorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        mostrarUnClienteId(arbol->dato);
        inorder(arbol->der);
    }
}
///-------------------uso este para el ardl
/*********************************************************************//**
*
* \brief muestra el arbol de manera  raiz,izquierda y derecha
* \param recibe un puntero a nodoArbol
* \return es void
*
**************************************************************************/
void preorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        mostrarNodoArdl(arbol);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

/*********************************************************************//**
*
* \brief muestra el arbol de manera izquierda, derecha y raiz
* \param recibe un puntero a nodoArbol
* \return es void
*
**************************************************************************/
void postorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarUnClienteId(arbol->dato);
    }
}

/*********************************************************************//**
*
* \brief busca un cliente en el arbol
* \param recibe un puntero a nodoArbol y un cliente
* \return si existe un puntero al nodoArbol donde esta el cliente, sino existe retorna un puntero a NULL
*
**************************************************************************/
nodoArbol * buscar(nodoArbol * arbol, stCliente dato)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        if(dato.id == arbol->dato.id)
            rta = arbol;
        else if(dato.id>arbol->dato.id)
            rta = buscar(arbol->der, dato);
        else
            rta = buscar(arbol->izq, dato);
    }
    return rta;
}

///-------------------------------------------Arbol de Listas-------------------------///
/*********************************************************************//**
*
* \brief pasa los clientes al arbol
* \param recibe un puntero a nodoArbol
* \return el puntero de el nodo arbol
*
**************************************************************************/
nodoArbol * cliente2Arbol(nodoArbol* arbol) ///pasa los datos de los clientes al arbol
{
    FILE * arch = fopen(AR_CLIENTES, "rb");
    nodoArbol* aux = arbol;
    stCliente c;

    if(arch)
    {
        while(fread(&c,sizeof(stCliente),1,arch)>0) ///HAY Q CHEQUEAR SI EL CLIENTE YA EXISTE EN EL ARBOL
        {
            aux = insertar(aux, c);
        }
        fclose(arch);
    }
    return aux;
}

/*********************************************************************//**
*
* \brief asigna los consumos al arbol de clientes
* \param recibe un puntero a nodoArbol(tiene que ser un arbol con clientes)
* \return el puntero al nodo arbol
*
**************************************************************************/
nodoArbol* asignaConsumosArbol(nodoArbol*arbol) ///funcion para darle los consumos a cada hoja del arbol
{
    FILE * consumos = fopen(AR_CONSUMOS,"rb");

    nodoArbol * leaf; /// hoja
    stConsumo c;

    if(consumos)///si el archivo abre correctamente
    {
        while(fread(&c,sizeof(stConsumo),1,consumos)>0)
        {
            leaf = buscaClienteEnArbol(arbol, c.idCliente); ///busca el nodo en el arbol y lo iguala
            if(leaf)
            {
                leaf->lista = agregarFinal(crearNodo(c), leaf->lista); ///agrega el consumo al cliente particular
            }
        }

        fclose(consumos);
    }
    return arbol;
}

/*********************************************************************//**
*
* \brief busca un cliente el arbol
* \param recibe un puntero a nodoArbol y un idCliente
* \return un puntero al nodo arbol(que contiene el cliente) si se encontro, sino retorna un puntero a NULL
*
**************************************************************************/
nodoArbol* buscaClienteEnArbol(nodoArbol* arbol, int idCliente) ///busca cliente en el arbol
{
    nodoArbol* found = NULL; ///variable por si encuentra el arbol

    if(arbol)
    {
        if(arbol->dato.id == idCliente) ///si el nodo es igual al pasado por parametro:
        {
            found = arbol; ///lo encontro
        }
        else
        {
            found = buscaClienteEnArbol(arbol->izq, idCliente);///se mueve a los nodos de abajo
            found = buscaClienteEnArbol(arbol->der, idCliente);
        }
    }

    return found; ///devuelve el encontrado
}

/*********************************************************************//**
*
* \brief muestra el arbol de listas
* \param recibe un puntero a nodoArbol
* \return es void
*
**************************************************************************/
void mostrarNodoArdl(nodoArbol* ardl){
    mostrarUnClienteId(ardl->dato);
    mostrarLista(ardl->lista);
    printf("\n--");
}

/***
* \brief Liquida un periodo(mes) de consumo del arbol de listas
* \param Recibe un nodo Arbol, idCliente
* \return Retorna un puntero a nodo Arbol.
*/
nodoArbol* liquidarUnMesdeConsumos(nodoArbol* arbol, int idCliente){

    nodoArbol* encontrado;
    int anio, mes;
    int total;
    if(arbol){

          encontrado = buscaClienteEnArbol(arbol,idCliente);
          if(encontrado)///Encontrado != NULL
            {
            printf("\nIngrese el anio que desea liquidar: ");
            scanf("%d",&anio);
            printf("\nIngrese el mes que desea liquidar: ");
            scanf("%d",&mes);

            total = cuentaTotal(encontrado->lista,anio,mes);
            if (total > 0) {
                imprimirFactura(encontrado->dato, total, anio,mes);
                printf("\n Liquidacion exitosa...");
                           }else {
                                printf("\nEl cliente no registra ningun consumo en ese mes.");
                                }
                }else {///Encontrado == NULL
                printf("\nNo existe ese cliente en el arbol.");
                    }

    }

return arbol;
}

int esHoja(nodoArbol* arbol){
    int flag = 0;
    if(!arbol->der && !arbol->izq){
        flag = 1;
    }
    else{
        flag = 0;
    }
  return flag;
}


nodoArbol* masDerecho(nodoArbol* arbol)
{
    nodoArbol* seg = arbol;
    while(seg->der)
    {
        seg = seg->der;
    }
    return seg;
}

nodoArbol* masIzquierdo(nodoArbol* arbol)
{
    nodoArbol* seg = arbol;
    while(seg->izq)
    {
        seg = seg->izq;
    }
    return seg;
}

nodoArbol* borrarNodoArbol(nodoArbol* arbol,int dato)
{
    nodoArbol* aux = arbol;
    if(aux)
    {
        if(dato == aux->dato.id)
        {
            if(aux->izq)
            {
                nodoArbol* masDer = masDerecho(aux->izq);
                aux->dato = masDer->dato;
                aux->izq = borrarNodoArbol(aux->izq,masDer->dato.id);
            }
            else if(aux->der)
            {
                nodoArbol* masIzq = masIzquierdo(aux->der);
                aux->dato = masIzq->dato;
                aux->der = borrarNodoArbol(aux->der,masIzq->dato.id);
            }
            else if(esHoja(aux))
            {
                free(aux);
                aux = NULL;
            }

        }
        else if(dato > aux->dato.id)
        {
            aux->der = borrarNodoArbol(aux->der,dato);
        }
        else if(dato < aux->dato.id)
        {
            aux->izq = borrarNodoArbol(aux->izq,dato);
        }

    }
return aux;
}
