/*
 * Parentizacion.cpp
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#include "Parentizacion.h"

Parentizacion::Parentizacion(int* dim, int nDimensiones) {
	cout << " **** PROBLEMA DE LA SUBSECUENCIA COMÚN MÁS LARGA ****" << endl;
	nMatrices = nDimensiones - 1;
	_solucion = NULL;

	_dimensionesMat = new int[nDimensiones];
	_tablaNOperaciones = new int*[nDimensiones];
	_tablaParentizacion = new int*[nDimensiones];

	for (int i = 0; i < nDimensiones; ++i) {
		_tablaNOperaciones[i] = new int[nDimensiones];
		_tablaParentizacion[i] = new int[nDimensiones];
	}

	for (int i = 0; i < nDimensiones; ++i) {
		for (int j = 0; j < nDimensiones; ++j) {
			_tablaNOperaciones[i][j] = 0;
			_tablaParentizacion[i][j] = 0;
		}
	}

	for (int i = 0; i < nDimensiones; ++i) {
		_dimensionesMat[i] = dim[i];
		cout << "Matriz " << i + 1 << ", dimensión = " << _dimensionesMat[i]
				<< endl;
	}
}

Parentizacion::~Parentizacion() {
	if (_dimensionesMat != NULL)
		delete[] _dimensionesMat;

	if (_tablaNOperaciones != NULL) {
		for (int i = 0; i < nMatrices + 1; ++i) {
			for (int j = 0; j < nMatrices + 1; ++j) {
				if (_tablaNOperaciones[i] == NULL) {
					delete _tablaNOperaciones[i];
					_tablaNOperaciones[i] = NULL;
				}
			}
		}
		delete[] _tablaNOperaciones;
	}

	if (_tablaParentizacion != NULL) {
		for (int i = 0; i < nMatrices + 1; ++i) {
			for (int j = 0; j < nMatrices + 1; ++j) {
				if (_tablaParentizacion[i] == NULL) {
					delete _tablaParentizacion[i];
					_tablaParentizacion[i] = NULL;
				}
			}
		}
		delete[] _tablaParentizacion;
	}
}

void Parentizacion::rellenarTablaNOperaciones() {
	const int UERROR = 9999999;
	int temp = 0;
	int j = -1;
	for (int l = 2; l <= nMatrices; ++l) {
		for (int i = 1; i <= (nMatrices - l + 1); ++i) {
			j = i + l - 1;
			_tablaNOperaciones[i][j] = UERROR;
			for (int k = i; k < j; ++k) {
				temp = _tablaNOperaciones[i][k] + _tablaNOperaciones[k + 1][j]
						+ (_dimensionesMat[i - 1] * _dimensionesMat[k]
								* _dimensionesMat[j]);
				if (temp < _tablaNOperaciones[i][j]) {
					_tablaNOperaciones[i][j] = temp;
					insertarParentizacion(i, j, k);
				}
			}
		}
	}

}

void Parentizacion::mostrarTablaNOp() {
	cout << endl << "\t Tabla de n Operaciones: " << endl;
	if (_tablaNOperaciones != NULL) {
		for (int i = 0; i < nMatrices + 1; ++i) {
			for (int j = 0; j < nMatrices + 1; ++j) {
				cout << "\t" << _tablaNOperaciones[i][j];
			}
			cout << endl;
		}
	} else
		cerr << "AVISO: TABLA DE OPERACIONES AÚN NO RELLENA!!" << endl;
}

void Parentizacion::mostrarParentizacion() {
	cout << endl << "\t Tabla de n Parentizaciones: " << endl;
	if (_tablaParentizacion != NULL) {
		for (int i = 0; i < nMatrices + 1; ++i) {
			for (int j = 0; j < nMatrices + 1; ++j)
				cout << "\t" << _tablaParentizacion[i][j];
			cout << endl;
		}
		cout << "Parentización Final = " << vueltaAtras(1, nMatrices);
	} else {
		cerr << "AVISO: TABLA DE PARENTIZACIÓN AUN NO RELLENA!!" << endl;
	}
}

void Parentizacion::insertarParentizacion(int i, int j, int p) {
	if (_tablaParentizacion != NULL)
		_tablaParentizacion[i][j] = p;
	else
		cerr << "ERROR: reserva de memoria no realizada!!" << endl;
}

string Parentizacion::vueltaAtras(int i, int j) {
	   string resultado = "";
	   string cadenaDr = "";
	   string cadenaIzq = "";
	   string* matrices = new string [10] {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

	   if (j > i) {
	      cadenaDr = vueltaAtras(i , _tablaParentizacion[i][j]);
	      cadenaIzq = vueltaAtras(_tablaParentizacion[i][j] + 1, j);
	      resultado = "( " + cadenaDr + " * " + cadenaIzq + " )";
	   } else {
	      resultado = " " + matrices[i - 1] + " ";
	   }
	   return resultado;
}
