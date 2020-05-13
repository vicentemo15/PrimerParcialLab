/*
 * Informe.c
 *
 *  Created on: 10 may. 2020
 *      Author: Vicente Montilla
 */
#include "Publicacion.h"
#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief imprime cliente con mas avisos activos .
 * \param arrayCli: array de tipo cliente.
 * \param limite: limite del array tipo cliente
 * \param arrayPub: array de tipo publicacion.
 * \param limitePub: limite del array tipo publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int inf_imprimirClienteMaxPub(Cliente* arrayCli,int limite,Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	int cantidad=0 ;
	int maxCantidad = -1;
    Cliente maxCliente;

	if(arrayCli != NULL && limite > 0 && arrayPub != NULL && limitePublicacion > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayCli[i].isEmpty == 0)
			{
				cantidad = pub_CantidadPublicacionesActivas(arrayPub,limitePublicacion, arrayCli[i].id);
				if (cantidad >= maxCantidad)
				{
					maxCantidad = cantidad;
					maxCliente = arrayCli[i];
				}
			}
		}

		cli_imprimirPublicaciones(&maxCliente,maxCantidad, "activas");
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief imprime cliente con mas avisos pausados .
 * \param arrayCli: array de tipo cliente.
 * \param limite: limite del array tipo cliente
 * \param arrayPub: array de tipo publicacion.
 * \param limitePub: limite del array tipo publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int inf_imprimirClienteMaxPubP(Cliente* arrayCli,int limite,Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	int cantidad=0 ;
	int maxCantidad = -1;
    Cliente maxCliente;
	if(arrayCli != NULL && limite > 0 && arrayPub != NULL && limitePublicacion > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayCli[i].isEmpty == 0)
			{
				cantidad = pub_CantidadPublicacionesPausadas(arrayPub,limitePublicacion, arrayCli[i].id);

				if (cantidad >= maxCantidad)
				{
					maxCantidad = cantidad;
					maxCliente = arrayCli[i];
				}
			}
		}

		cli_imprimirPublicaciones(&maxCliente,maxCantidad, "pausadas");
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief imprime cliente con mas avisos .
 * \param arrayCli: array de tipo cliente.
 * \param limite: limite del array tipo cliente
 * \param arrayPub: array de tipo publicacion.
 * \param limitePub: limite del array tipo publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int inf_imprimirClienteCantidadPubTotal(Cliente* arrayCli,int limite,Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	int cantidadP=0 ;
	int cantidadA=0 ;
	int cantidadT=0 ;
	int maxCantidad = -1;
    Cliente maxCliente;

	if(arrayCli != NULL && limite > 0 && arrayPub != NULL && limitePublicacion > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayCli[i].isEmpty == 0)
			{
				cantidadP = pub_CantidadPublicacionesPausadas(arrayPub,limitePublicacion, arrayCli[i].id);
				cantidadA = pub_CantidadPublicacionesActivas(arrayPub,limitePublicacion, arrayCli[i].id);
				cantidadT = cantidadP + cantidadA;
				if (cantidadT >= maxCantidad)
				{
					maxCantidad = cantidadT;
					maxCliente = arrayCli[i];
				}
			}
		}

		cli_imprimirPublicaciones(&maxCliente,maxCantidad, "");
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief imprime publicaciones activas de un rubro .
 * \param array: array de tipo publicacion.
 * \param limite: limite del array tipo publicacion
 * \param valorBuscado: tipo de rubro,
 * \return Retorna cantidad de publicaciones acitvas(EXITO) y -1 (ERROR)
 *
 */

int inf_RubroPubAct(Publicacion* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	int cantidad=0;

	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==0 && array[i].estado==0 && array[i].rubro == valorBuscado)
			{
				cantidad++;
			}
		}

		respuesta =cantidad ;
	}

	return respuesta;
}

/**
 * \brief imprime el tipo de rubro con mas publicaciones activas .
 * \param array: array de tipo publicacion.
 * \param limite: limite del array tipo publicacion
 * \return Retorna 0(EXITO) y -1 (ERROR)
 *
 */

int inf_RubroMaxPubAct(Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	int maxRubro = -1;
	int cantidad=0 ;
	int maxCantidad = -1;

	if( arrayPub != NULL && limitePublicacion > 0)
	{
		for(i=0;i<limitePublicacion;i++)
		{
			if(arrayPub[i].isEmpty == 0)
			{
				cantidad = inf_RubroPubAct(arrayPub, limitePublicacion,arrayPub[i].rubro);
				if (cantidad >= maxCantidad)
				{
					maxCantidad = cantidad;
					maxRubro = arrayPub[i].rubro;
				}

				respuesta =0;
			}
		}

		respuesta = 0;
		if (maxRubro != -1)
		{
			printf("Rubro con mas publicaciones activas: %d Cantidad:  %d",maxRubro,maxCantidad);
		}
		else
		{
			printf("No hay publicaciones activas");
		}
	}

	return respuesta;
}

/**
 * \brief imprime el tipo de rubro con menos publicaciones activas .
 * \param array: array de tipo publicacion.
 * \param limite: limite del array tipo publicacion
 * \return Retorna 0(EXITO) y -1 (ERROR)
 *
 */

int inf_RubroMinPubAct(Publicacion* arrayPub,int limitePublicacion)
{
	int respuesta = -1;
	int i;
	int minRubro = -1;
	int cantidad=0;
	int minCantidad = 1001;

	if( arrayPub != NULL && limitePublicacion > 0)
	{
		for(i=0;i<limitePublicacion;i++)
		{
			if(arrayPub[i].isEmpty == 0)
			{
				cantidad = inf_RubroPubAct(arrayPub, limitePublicacion,arrayPub[i].rubro);
				if (cantidad <= minCantidad)
				{
					minCantidad = cantidad;
					minRubro = arrayPub[i].rubro;
				}

				respuesta =0;
			}
		}

		respuesta = 0;
		if (minRubro != -1)
		{
			printf("Rubro con menos publicaciones activas: %d Cantidad:  %d", minRubro, minCantidad);
		}
		else
		{
			printf("No hay publicaciones activas");
		}
	}

	return respuesta;
}
