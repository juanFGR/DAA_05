/*
 * SubSecuencia.h
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#ifndef SUBSECUENCIA_H_
#define SUBSECUENCIA_H_

#include <iostream>
using namespace std;

class SubSecuencia {
public:
	SubSecuencia(string cadena1, string cadena2);
	virtual ~SubSecuencia();

	void mostrarTabla ();
	void subSecComunMasLarga ();

private:
	int** _tabla;
	int nFilas;
	int nCols;

	string _subSecComun;
	string _cad1;
	string _cad2;

	void vueltaAtras ();
	int posMayor (int* pos);
};

#endif /* SUBSECUENCIA_H_ */
