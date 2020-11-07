#ifndef ORDENAMIENTOSYESTADISTICAS_H_INCLUDED
#define ORDENAMIENTOSYESTADISTICAS_H_INCLUDED
#include "crudClientes.h"
#include "crudConsumos.h"

void CambiaValoresCliente(stCliente *a,stCliente *b);

int buscaMenorPosDni(stCliente a[],int v,int inicio);
void ordenarSelDni(stCliente a[],int v);

int buscaMenorPosApe(stCliente a[],int v,int inicio);

int buscaMenorPosEmail(stCliente a[],int v,int inicio);
void OrdenarSelEmail(stCliente a[],int v);
void ordenarEmails(stCliente a);

void ordenarSelApe(stCliente a[],int v);
void ordenarApellidos(stCliente a);

void ordenarDNIS(stCliente a);

void muestraClientes(stCliente c[], int v);
int ordenarMES(stConsumo a,int dato);

void muestraConsumos(stConsumo c[], int v);

int archivo2arrayConsumos(stConsumo a,stConsumo c[DIM_CLI],int dato);

int archivo2arrayDatos(stConsumo a,int c[DIM_CLI],int dato);

int sumadatos1(stConsumo a);
int sumadatos2(stConsumo a);
int sumadatos3(stConsumo a);
int sumadatos4(stConsumo a);
int sumadatos5(stConsumo a);
int sumadatos6(stConsumo a);
void muestraSumaDatos(stConsumo a);
int pasarArraySumaDatos(stConsumo a,int arraySumas[],int v);
int sumadatosAll(stConsumo a);

int archivo2arrayAlldato(stConsumo a,int c[DIM_CLI]);

float PorcentajeMesConsumo(int total);

int sumararray(int a[],int validos);

float calcularporcentaje2(stConsumo a,int dato);

int archivo2ArrayConsumosEnteros(stConsumo g,stConsumo conArray[],int v,int dim);

void CambiaValoresConsumo(stConsumo *a,stConsumo *b);

int buscaMenorPosDia(stConsumo g[],int v,int inicio,int mes);
void ordenarSelDia(stConsumo g[],int v);

int ordenarArrayConsumosPorDiaYMes(stConsumo g[],int v,stConsumo arreglodias[]);
int buscaMenorPosMes(stConsumo g[],int v,int inicio);
void ordenarArrayConsumosPorMes(stConsumo g[],int v);
int buscaPosMenorConsumoMes(int a[],int v);
int buscaMayorPosDdia(stConsumo g[],int v,int inicio,int mes);
void ordenarSelDddia(stConsumo g[],int v);
int ordenarArrayConsumosPorDiaYMmes(stConsumo g[],int v,stConsumo arreglodias[]);
int buscaMayorPosMmes(stConsumo g[],int v,int inicio);
void ordenarArrayConsumosPorMmmes(stConsumo g[],int v);
int buscaPosMayorConsumoMeees(int a[],int v);

int cuentaConsumosActivosMes(int mes);
int cuentaConsumosInactivosMes(int mes);

int cuentaClientesNegativos();
int cuentaClientesPositivos();

void porcentajeClientesActivos_Inactivos();

int sumatoriaDeDias();

float promedioXdia();


#endif // ORDENAMIENTOSYESTADISTICAS_H_INCLUDED
