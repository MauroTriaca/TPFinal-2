#ifndef ARCHIVOCONSUMOS_H_INCLUDED
#define ARCHIVOCONSUMOS_H_INCLUDED
#include "clientes.h"
#include "consumos.h"

void cargaArchivoConsumos(stConsumo g);
void cargaConsumosTeclado();

 void cargaConsumos(int veces);
stConsumo cargarConsumosRandom();

int CalcularDias(int mes,int anio);
stConsumo buscaConsumoPorFecha(int mes,int dia);
int existenConsumos(int mes,int dia,int idCliente,int baja);

int buscaUltimoIdConsumos();

void mostrarArchivoConsumos();

stConsumo traeConsumo(int id);


#endif // ARCHIVOCONSUMOS_H_INCLUDED
