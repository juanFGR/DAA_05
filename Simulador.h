/*
 * Simulador.h
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#ifndef SIMULADOR_H_
#define SIMULADOR_H_

#include "SubSecuencia.h"

class Simulador {
public:
	Simulador(string cadena1, string cadena2);
	virtual ~Simulador();

	void interfazAlgoritmo ();

public:
	SubSecuencia* _subSec;
};

#endif /* SIMULADOR_H_ */
