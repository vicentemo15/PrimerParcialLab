//============================================================================
// Name        : PrimerParcialLob.cpp
// Author      : Vicente Montilla
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Publicacion.h"
#include "Informe.h"
#include "utn.h"
#define CLIENTES_LEN 100
#define PUBLICACION_LEN 1000
int main(void) {

	setbuf(stdout, NULL);
	Cliente arrayCliente[CLIENTES_LEN];
	Publicacion arrayPublicacion[PUBLICACION_LEN];
	int idCliente = 0;
	int idPublicacion = 0;
	int auxiliarIndiceCliente;
	int auxiliarIndicePublicacion;
	int confirmacion;
	int auxiliarId;
	int opcion;
	int opcionInf;
	int opcionRubro;
	int auxiliarRubro;

	if (cli_inicializarArray(arrayCliente, CLIENTES_LEN) == 0
			&& pub_inicializarArray(arrayPublicacion, PUBLICACION_LEN) == 0)
	{
		printf("Array Inicializado \n\n");
	}

	do {
		if (!utn_getNumero(&opcion, "\n\n MENU"
				"\n\n01.- Alta de Cliente."
				"\n02.- Modificar Cliente."
				"\n03.- Baja de Cliente."
				"\n04.- Publicar."
				"\n05.- Pausar Publicacion."
				"\n06.- Reanudar Publicacion."
				"\n07.- Imprimir Clientes."
				"\n08.- Imprimir Publicaciones."
				"\n09.- Informar Clientes."
				"\n10.-Informar Publicaciones."
				"\n11.-Salir.\n\n", "\nError OPCION INVALIDA", 1, 11, 2)) {
			switch (opcion) {
			case 1:
				auxiliarIndiceCliente = cli_posicionDisponible(arrayCliente, CLIENTES_LEN);

				if (auxiliarIndiceCliente >= 0)
				{
					if (cli_altaArray(arrayCliente, CLIENTES_LEN, auxiliarIndiceCliente, &idCliente) == 0)
					{
						printf("Carga Exitosa su numero de ID es %d:  \n", idCliente - 1);
					}
				}
				else
				{
					printf("No hay espacio disponible \n");
				};

				break;
			case 2:
				cli_imprimirArray(arrayCliente, CLIENTES_LEN);
				if (utn_getNumero(&auxiliarId,
						"\nNumero de ID del cliente a modificar\n",
						"\nError en los datos ingresados\n", 0, idCliente, 2) == 0)
				{
					auxiliarIndiceCliente = cli_buscarId(arrayCliente, CLIENTES_LEN, auxiliarId);
					if (auxiliarIndiceCliente >= 0
							&& cli_modificarArray(arrayCliente, CLIENTES_LEN, auxiliarIndiceCliente) == 0)
					{
						printf("Modificacion Exitosa");
					}
				}

				break;
			case 3:
				cli_imprimirArray(arrayCliente, CLIENTES_LEN)

				;
				if (utn_getNumero(&auxiliarId,
						"\nNumero de ID del cliente a dar de baja\n",
						"\nError en los datos ingresados\n", 0, idCliente, 2) == 0)
				{
					auxiliarIndiceCliente = cli_buscarId(arrayCliente, CLIENTES_LEN, auxiliarId);
					auxiliarIndicePublicacion = pub_buscarPublicacionId(arrayPublicacion, PUBLICACION_LEN, auxiliarId);
					if (auxiliarIndiceCliente >= 0 && auxiliarIndicePublicacion >=0
							&& cli_bajaArray(arrayCliente, CLIENTES_LEN, auxiliarIndiceCliente) == 0
							&& pub_bajaArray(arrayPublicacion,PUBLICACION_LEN,auxiliarIndicePublicacion) == 0)
					{
						printf("Baja Exitosa");
					}
				}

				break;
			case 4:
				auxiliarIndicePublicacion = pub_posicionDisponible(arrayPublicacion, PUBLICACION_LEN);
				if (auxiliarIndicePublicacion >= 0)
				{
					cli_imprimirArray(arrayCliente, CLIENTES_LEN);
					if (utn_getNumero(&auxiliarId, "\nId Cliente: ", "\nError",
							0, 10000, 2) == 0
							&& cli_buscarId(arrayCliente, CLIENTES_LEN,
									auxiliarId) != -1)
					{
						pub_altaArray(arrayPublicacion, PUBLICACION_LEN,
								auxiliarIndicePublicacion, &idPublicacion, auxiliarId);
						printf("Carga exitosa su numero  ID Publicacion es : %d", idPublicacion - 1);
					}
					else
					{
						printf("\nEL ID NO EXISTE");
					}
				}
				break;
			case 5:
				pub_imprimirArray(arrayPublicacion, PUBLICACION_LEN);
				if (utn_getNumero(&auxiliarId,
						"\nIndique el ID de la Publicacion a pausar",
						"\nID invalido", 0, idPublicacion, 0) == 0) {

					if (utn_getNumero(&confirmacion,"¿\n\n Desea continuar con el cambio? \n1)Si \n2)No ","OPCION INVALIDA",1,2,2)==0
							&& confirmacion == 1)
					{
					auxiliarIndicePublicacion = pub_buscarId(arrayPublicacion,
							PUBLICACION_LEN, auxiliarId);
					if (auxiliarIndicePublicacion >= 0
							&& pub_PausadaArray(arrayPublicacion,
									PUBLICACION_LEN, auxiliarIndicePublicacion)== 0)
					   {
						 printf("\nPublicion Pausada\n");
				        }
				   }
				}

				break;
			case 6:
				pub_imprimirArray(arrayPublicacion, PUBLICACION_LEN);
				if (utn_getNumero(&auxiliarId,
						"\nIndique el ID de la Publicacion a pausar",
						"\nID invalido", 0, idPublicacion, 0) == 0)
				{   if (utn_getNumero(&confirmacion,"¿\n\n Desea continuar con el cambio? \n1)Si \n2)No ","OPCION INVALIDA",1,2,2)==0
						&& confirmacion == 1)
				  {
					auxiliarIndicePublicacion = pub_buscarId(arrayPublicacion, PUBLICACION_LEN, auxiliarId);
					if (auxiliarIndicePublicacion >= 0
							&& pub_reanudarArray(arrayPublicacion, PUBLICACION_LEN, auxiliarIndicePublicacion) == 0)
					{
						printf("\nPublicion Activa\n");
					}
				  }
				}

				break;
			case 7:
				cli_imprimirArrayClienteCantidad(arrayCliente, CLIENTES_LEN, arrayPublicacion, PUBLICACION_LEN);

				break;
			case 8:
				pub_imprimirArrayPublicacionesCuit(arrayCliente, CLIENTES_LEN, arrayPublicacion, PUBLICACION_LEN);

				break;
			case 9:
				do {
					if (!utn_getNumero(&opcionInf,
							"\n\nINFORMAR CLIENTES: \n\n1.-Cliente con mas avisos activos."
							"\n2.-Cliente con mas avisos pausados."
							"\n3.-Cliente con mas avisos."
							"\n4.Volver\n\n", "\nError opcion invalida",
							1, 4, 2))
					{
						switch (opcionInf)
						{
						case 1:
							inf_imprimirClienteMaxPub(arrayCliente,
									CLIENTES_LEN, arrayPublicacion,
									PUBLICACION_LEN);

							break;
						case 2:
							inf_imprimirClienteMaxPubP(arrayCliente,
									CLIENTES_LEN, arrayPublicacion,
									PUBLICACION_LEN);

							break;
						case 3:
							inf_imprimirClienteCantidadPubTotal(arrayCliente,
									CLIENTES_LEN, arrayPublicacion,
									PUBLICACION_LEN);

							break;
						}
					}

				} while (opcionInf != 4);

				break;
			case 10:
				do {
					if (!utn_getNumero(&opcionInf,
							"\n\nINFORMAR PUBLICACIONES: \n\n1.-Cantidad de publicaciones de un rubro."
							"\n2.-Rubro con mas publicaciones activas."
							"\n3.-Rubro con menos publicaciones activas."
							"\n4.Volver\n\n", "\nError opcion invalida",
							1, 4, 2))
					{
						switch (opcionInf)
						{
						case 1:
							if (!utn_getNumero(&opcionRubro,
									"\n\nIngrese Rubro:    \n\n",
									"\nError Rubro invalido", 0, 1000, 2)) {

								auxiliarRubro = inf_RubroPubAct(
										arrayPublicacion, PUBLICACION_LEN,
										opcionRubro);
								printf("Total de Publicaciones:  %d",
										auxiliarRubro);
							}

							break;
						case 2:
							inf_RubroMaxPubAct(arrayPublicacion,
									PUBLICACION_LEN);

							break;
						case 3:
							inf_RubroMinPubAct(arrayPublicacion,
									PUBLICACION_LEN);

							break;
						}
					}

				} while (opcionInf != 4);

				break;
			}

		}
	} while (opcion != 11);

	return EXIT_SUCCESS;
}
