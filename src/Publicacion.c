/*
 * Publicacion.c
 *
 *  Created on: 8 may. 2020
 *      Author: Vicente Montilla
 */
#include "Publicacion.h"
#include "Cliente.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLIENTES_LEN 100
static const char TXT_ESTADOS[2][8]={"ACTIVA","PAUSADA"};

/**
 * \brief Inicializa el array.
 * \param  Array: Array de tipo publicacion a ser actualizado.
 * \param limite:  Limite del array de tipo publicacion.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}

	return respuesta;
}

/**
 * \brief Da de alta una publicacion en una posicion del array
 * \param ARRAY: Array de publicacion a ser actualizado
 * \param LIMITE: Limite del array de publicacion
 * \param INDICE=: Posicion a ser actualizada
 * \param id Identificador a ser asignado a la publicacion
 * \param id Identificador del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	!utn_getNumero(&bufferPublicacion.rubro,"\n Rubro? \n", "\nError",0,100,2) &&
			!utn_getDescripcion(bufferPublicacion.texto,TEXTO_LEN,"\nIngrese el Texto:\n ", "\nError",2)&&
			!utn_getNumero(&bufferPublicacion.estado,"\nEstado:\n 0:Activa \n 1:Pausada\n","\nError",0,1,2) )
		{
			respuesta = 0;
			bufferPublicacion.idCliente = idCliente;
			bufferPublicacion.id = *idPublicacion;
			bufferPublicacion.isEmpty = 0;
			array[indice] = bufferPublicacion;
			(*idPublicacion)++;
		}
	}

	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de publicaciones
 * \param limite Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int pub_posicionDisponible(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de publicacion a ser actualizado
 * \param limite Limite del array de publicacion
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_PausadaArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].estado == 0)
	{
		array[indice].estado = 1;
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief Imprime los datos de una publicacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_imprimir(Publicacion* pElemento)
{
	int retorno=-1;

	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID Publicacion: %d -ID Cliente %d - Estado: %s ",pElemento->id,pElemento->idCliente,TXT_ESTADOS[pElemento->estado]);
	}

	return retorno;
}

/**
 * \brief Imprime el array de publicaciones
 * \param array Array de publicacion  a ser actualizado
 * \param limite Limite del array de publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_imprimirArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}

	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra.
* \param array publicacion Array de publcacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado , retorna posicion donde se encuentra.
*
*/

int pub_buscarId(Publicacion* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra.
* \param array publicacion Array de publcacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado , retorna posicion donde se encuentra.
*
*/

int pub_buscarPublicacionId(Publicacion* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idCliente == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array publicacion a ser actualizado
 * \param limite Limite del array de publicacion
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_bajaArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de publicacion a ser actualizado
 * \param limite Limite del array de publicacion
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_reanudarArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].estado == 1)
	{
		array[indice].estado = 0;
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief cantidad de publicaciones activas
 * \param array Array de publicacion
 * \param limite Limite del array de publicacion
 * \param id del cliente
 * \return Retorna cantidad de publicaciones (EXITO) y -1 (ERROR)
 *
 */

int pub_CantidadPublicacionesActivas(Publicacion* array,int limite,int idCliente)
{
	int respuesta = -1;
	int i;
	int cantidadPublicaciones = 0;

	if(array != NULL && limite > 0 && idCliente>=0)
	{
		for(i=0;i<limite;i++)
		{
			if (array[i].isEmpty == 0 && array[i].estado == 0 && array[i].idCliente == idCliente)
		    {
				cantidadPublicaciones++;
		    }
		}

		respuesta = cantidadPublicaciones;
	}

	return respuesta;
}

/**
 * \brief cantidad de publicaciones pausadas
 * \param array Array de publicacion
 * \param limite Limite del array de publicacion
 * \param id del cliente
 * \return Retorna cantidad de publicaciones (EXITO) y -1 (ERROR)
 *
 */

int pub_CantidadPublicacionesPausadas(Publicacion* array,int limite,int idCliente)
{
	int respuesta = -1;
	int i;
	int cantidadPublicaciones = 0;

	if(array != NULL && limite > 0 && idCliente>=0)
	{
		for(i=0;i<limite;i++)
		{
			if (array[i].isEmpty == 0 && array[i].estado == 1 && array[i].idCliente == idCliente)
		    {
				cantidadPublicaciones++;
		    }
		}

		respuesta = cantidadPublicaciones;
	}

	return respuesta;
}

/**
 * \brief Imprime los datos de una publicacion con cuil del cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \param cuit: cuit del ciente.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirPublicacionesCuit(Publicacion* pElemento,char*cuit)
{
	int retorno=-1;

	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID Publicacion: %d -ID Cliente %d - Cuit %s   - Estado: %s ",pElemento->id,pElemento->idCliente,cuit,TXT_ESTADOS[pElemento->estado]);
	}

	return retorno;
}

