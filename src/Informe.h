/*
 * Informe.h
 *
 *  Created on: 10 may. 2020
 *      Author: Vicente Montilla
 */

#ifndef INFORME_H_
#define INFORME_H_

int inf_imprimirClienteMaxPub(Cliente* arrayCli,int limite,Publicacion* arrayPub,int limitePublicacion);
int inf_imprimirClienteMaxPubP(Cliente* arrayCli,int limite,Publicacion* arrayPub,int limitePublicacion);
int inf_imprimirClienteCantidadPubTotal(Cliente* arrayCli,int limite,Publicacion* arrayPub,int limitePublicacion);
int inf_RubroPubAct(Publicacion* array, int limite, int valorBuscado);
int inf_RubroMaxPubAct(Publicacion* arrayPub,int limitePublicacion);
int inf_RubroMinPubAct(Publicacion* arrayPub,int limitePublicacion);

#endif /* INFORME_H_ */
