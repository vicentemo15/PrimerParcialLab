/*
 * Cliente.c
 *
 *  Created on: 7 may. 2020
 *      Author: Vicente Montilla
 */
#include "Cliente.h"
#include "Publicacion.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Inicializa el array.
 * \param  Array: Array de tipo cliente a ser actualizado.
 * \param limite:  Limite del array de tipo cliente.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_inicializarArray(Cliente* array,int limite)
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
 * \brief Buscar primer posicion vacia.
 * \param array: Array de cliente.
 * \param limite: Limite del array de cliente.
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int cli_posicionDisponible(Cliente* array,int limite)
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
 * \brief Da de alta un cliente en una posicion del array.
 * \param array: Array de cliente a ser actualizado.
 * \param limite: Limite del array de cliente.
 * \param indice: Posicion a ser actualizada
 * \param id: Identificador a ser asignado al cliente.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_altaArray(Cliente* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
			utn_getCuit(bufferCliente.cuit,CUIL_LEN,"\nCuit?\n","\nERROR\n",2) == 0 )
		{
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}

	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array: Array de cliente a ser actualizado.
 * \param limite: Limite del array de cliente.
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
				utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
				utn_getCuit(bufferCliente.cuit,CUIL_LEN,"\nCuit?\n","\nERROR\n",2) == 0 )
		{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
		}
	}

	return respuesta;
}

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;

	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %s",pElemento->id,pElemento->cuit,pElemento->nombre,pElemento->apellido);
	}

	return retorno;
}

/**
 * \brief Imprime el array de cliente.
 * \param array Array de cliente a ser actualizado
 * \param limite Limite del array de cliente.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cli_imprimir(&array[i]);
		}
	}

	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra.
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado , retorna posicion donde se encuentra.
*
*/

int cli_buscarId(Cliente* array, int limite, int valorBuscado)
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

/**
 * \brief Actualiza una posicion del array
 * \param array Array de cliente a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_bajaArray(Cliente* array,int limite, int indice)
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
 * \brief Imprime array de ciente con cantidad de avisos activos
 * \param array Array de cliente
 * \param limite Limite del array de clientes
 * * \param array Array de publicacion
 * \param limite Limite del array de publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArrayClienteCantidad(Cliente* array,int limite,Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	int auxiliarIdCliente;
	int cantidad=0 ;

	if(array != NULL && limite > 0 && arrayPub != NULL && limitePublicacion >0  )
	{
		for(i=0;i<limite;i++)
		{
			auxiliarIdCliente = array[i].id;
		    cantidad = pub_CantidadPublicacionesActivas(arrayPub,limitePublicacion,auxiliarIdCliente);
			cli_imprimirPublicaciones(&array[i],cantidad,"activas");
		}

		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief Imprime array de un  ciente con cantidad de avisos activos
 * \param pElemento Puntero al producto que se busca imprimir.
 * \param cantidad de avisos activos
 * * \param Estado de la puclicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_imprimirPublicaciones(Cliente* pElemento, int cantidad,char* tipo)
{
	int retorno=-1;

	if(pElemento != NULL && pElemento->isEmpty == 0 && cantidad >=0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %s -Cantidad de Publicaciones %s:  %d",pElemento->id,pElemento->cuit,pElemento->nombre,pElemento->apellido,tipo, cantidad);
	}

	return retorno;
}

/**
 * \brief Devuelve el cuit del cliente .
 * \param array: array de tipo cliente.
 * \param limite: limite del array tipo cliente
 * \param valorBuscado: array.id de tipo publicacion .
 * \param cuit:variable de retorno  al cuit.
 * \param limiteCuit:limite de array campo cuit.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_buscarIdCuit(Cliente* array, int limite, int valorBuscado,char* cuit, int limiteCuit)
{
	int respuesta = -1;
	int i;

	if(array != NULL && limite > 0 && valorBuscado >= 0 && cuit != NULL && limiteCuit > 0  )
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = 0;
				strncpy(cuit,array[i].cuit,sizeof(limiteCuit));
				break;
			}
		}
	}

	return respuesta;
}

/**
 * \brief Imprime array de publicaciones junto con cuit del cliente.
 * \param array: array de tipo cliente.
 * \param limite: limite del array tipo cliente
 * \param arrayPub: array de tipo publicacion.
 * \param limitepublicacion: limite del array tipo publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int pub_imprimirArrayPublicacionesCuit(Cliente* array,int limite,Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	char auxiliarCuit[100];

	if(array != NULL && limite > 0 && arrayPub != NULL && limitePublicacion >0  )
	{
		for(i=0;i<limitePublicacion;i++)
		{
			if ( cli_buscarIdCuit(array, limite,arrayPub[i].idCliente,auxiliarCuit,CUIL_LEN)==0)
			{
				pub_imprimirPublicacionesCuit(&arrayPub[i],auxiliarCuit);
			}
		}

		respuesta = 0;
	}

	return respuesta;
}

