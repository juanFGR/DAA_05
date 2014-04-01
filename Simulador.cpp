/*
 * Simulador.cpp
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#include "Simulador.h"

Simulador::Simulador(string cadena1, string cadena2) {
	_subSec = new SubSecuencia(cadena1, cadena2);
	_parOpt = NULL;
}

Simulador::Simulador(int* dimensiones, int tam) {
	_parOpt = new Parentizacion (dimensiones, tam);
	_subSec = NULL;
}

void Simulador::interfazAlgoritmo () {
	if (_subSec == NULL) {
		_parOpt -> rellenarTablaNOperaciones();
		_parOpt -> mostrarTablaNOp();
		_parOpt -> mostrarParentizacion();
	}
	if (_parOpt == NULL) {
		_subSec -> subSecComunMasLarga();
		_subSec -> mostrarTabla();
	}
}

Simulador::~Simulador() {
}

