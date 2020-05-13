/*
 * Publicacion.h
 *
 *  Created on: 8 may. 2020
 *      Author: Vicente Montilla
 */
#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define TEXTO_LEN 65
#define ESTADO_ACTIVA	0
#define ESTADO_PAUSADA	1

typedef struct
{
	int estado;
	char texto[TEXTO_LEN];
	int rubro;
	int isEmpty;
	int id;
	int idCliente;

}Publicacion;

int pub_inicializarArray(Publicacion* array,int limite);
int pub_posicionDisponible(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente);
int pub_imprimir(Publicacion* pElemento);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_buscarId(Publicacion* array, int limite, int valorBuscado);
int pub_buscarPublicacionId(Publicacion* array, int limite, int valorBuscado);
int pub_bajaArray(Publicacion* array,int limite, int indice);
int pub_PausadaArray(Publicacion* array,int limite, int indice);
int pub_reanudarArray(Publicacion* array,int limite, int indice);
int pub_CantidadPublicacionesActivas(Publicacion* array,int limite,int idCliente);
int pub_CantidadPublicacionesPausadas(Publicacion* array,int limite,int idCliente);
int pub_imprimirPublicacionesCuit(Publicacion* pElemento,char*cuit);

#endif /* PUBLICACION_H_ */
