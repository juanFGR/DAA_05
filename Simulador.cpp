/*
 * Simulador.cpp
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#include "Simulador.h"

Simulador::Simulador(string cadena1, string cadena2) {
	_subSec = new SubSecuencia(cadena1, cadena2);
}


void Simulador::interfazAlgoritmo () {
		_subSec -> subSecComunMasLarga();
		_subSec -> mostrarTabla();
}

Simulador::~Simulador() {
}

