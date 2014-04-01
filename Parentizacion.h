/*
 * Parentizacion.h
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#ifndef PARENTOPTPRODMATRICES_H_
#define PARENTOPTPRODMATRICES_H_

#include <iostream>
#include <string>
using namespace std;

class Parentizacion {
public:
	Parentizacion(int* dim, int nDimensiones);
	virtual ~Parentizacion();

	void rellenarTablaNOperaciones ();
	void mostrarTablaNOp ();
	void mostrarParentizacion ();

private:
	int* _dimensionesMat;
	int** _tablaNOperaciones;
	int** _tablaParentizacion;
	int* _solucion;
	int nMatrices;

	void insertarParentizacion (int i, int j, int p);
	string vueltaAtras (int i, int j);
	void insertarSolucion (int i, int j, int posParentesis);
};

#endif /* PARENTOPTPRODMATRICES_H_ */
