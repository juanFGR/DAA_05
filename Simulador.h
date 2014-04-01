/*
 * Simulador.h
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#ifndef SIMULADOR_H_
#define SIMULADOR_H_

#include "SubSecuencia.h"
#include "Parentizacion.h"

class Simulador {
public:
	Simulador(string cadena1, string cadena2);
	Simulador(int* dimensiones, int tam);
	virtual ~Simulador();

	void interfazAlgoritmo ();

private:
	SubSecuencia* _subSec;
	Parentizacion* _parOpt;
};

#endif /* SIMULADOR_H_ */
