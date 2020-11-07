#ifndef CONSUMOS_H_INCLUDED
#define CONSUMOS_H_INCLUDED
#include "clientes.h"
#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"

typedef struct
{
    int id;  /// campo único y autoincremental
    int idCliente;
    int anio;///actual
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumo;

stConsumo cargaConsumoCliente(); ///carga por teclado de un consumo
stConsumo cargaConsumoAuto();///carga automatica un consumo, todo random
void mostrarUnConsumo(stConsumo g);




#endif // CONSUMOS_H_INCLUDED
