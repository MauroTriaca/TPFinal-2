#ifndef CRUDCLIENTES_H_INCLUDED
#define CRUDCLIENTES_H_INCLUDED
#include "archivoClientes.h"
#include "utilidades.h"

void modificarCliMenus();///menu que maneja todo

void modificarNombrex();
void modificarnombre(stCliente c);

void ModificarApellidox();
void ModificarApellido(stCliente c);

void ModificarDNIx();
void ModificarDNI(stCliente c);

void ModificarEmailx();
void ModificarEmail(stCliente c);

void ModificarDomiciliox();
void ModificarDomicilio(stCliente c);

void ModificarMovilx();
void ModificarMovil(stCliente c);

void DarDeAltax();
void DarDeAlta(stCliente c);

void DarDeBajax();
void DarDeBaja(stCliente c);

#endif // CRUDCLIENTES_H_INCLUDED
