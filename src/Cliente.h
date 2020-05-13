/*
 * Cliente.h
 *
 *  Created on: 7 may. 2020
 *      Author: Vicente Montilla
 *
 */
#include "Publicacion.h"
#ifndef CLIENTE_H_
#define CLIENTE_H_
#define NOMBRE_LEN 51
#define APELLIDO_LEN 51
#define CUIL_LEN 12
typedef struct
{
	char nombre [NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit [CUIL_LEN];
	int isEmpty;
	int id;

}Cliente;

int cli_inicializarArray(Cliente* array,int limite);
int cli_posicionDisponible(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_imprimir(Cliente* pElemento);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente* array, int limite, int valorBuscado);
int cli_bajaArray(Cliente* array,int limite, int indice);
int cli_imprimirArrayClienteCantidad(Cliente* array,int limite,Publicacion* arrayPub,int limitePublicacion);
int cli_imprimirPublicaciones(Cliente* pElemento, int cantidad,char* tipo);
int cli_buscarIdCuit(Cliente* array, int limite, int valorBuscado,char* cuit, int limiteCuit);
int pub_imprimirArrayPublicacionesCuit(Cliente* array,int limite,Publicacion* arrayPub,int limitePublicacion);

#endif /* CLIENTE_H_ */
