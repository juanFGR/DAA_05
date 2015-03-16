/*
 * SubSecuencia.cpp
 *
 *  Created on: 23/03/2014
 *      Author: JuanFGR
 */

#include "SubSecuencia.h"

SubSecuencia::SubSecuencia(string cadena1, string cadena2) {

	nFilas = cadena1.length() + 1;
	nCols = cadena2.length() + 1;

	_subSecComun = "";
	_cad1 = cadena1;
	_cad2 = cadena2;

	_tabla = new int*[nCols];
	for (int i = 0; i < nCols; ++i) {
		_tabla[i] = new int[nFilas];
	}

	for (int i = 0; i < nCols; ++i) {
		for (int j = 0; j < nFilas; ++j) {
			_tabla[i][j] = 0;
		}
	}
}

SubSecuencia::~SubSecuencia() {
	for (unsigned int i = 0; i < _cad1.length(); ++i) {
		delete _tabla[i];
	}
	delete[] _tabla;
	_tabla = NULL;
}





//Calculos 
void SubSecuencia::mostrarTabla() {
	cout << "********* Tabla resultado ********* " << endl << endl;
	cout << " \t";
	for (unsigned int j = 0; j < _cad1.length(); ++j)
		cout << "\t" << _cad1[j];
	cout << endl;
	for (int i = 0; i < nCols; ++i) {
		if (i != 0)
			cout << _cad2[i - 1];
		for (int j = 0; j < nFilas; ++j) {
			cout << "\t" << _tabla[i][j];
		}
		cout << endl;
	}
}

void SubSecuencia::subSecComunMasLarga() {
	int posA = 0;

	for (int i = 1; i < nCols; ++i) {
		for (int j = 1; j < nFilas; ++j) {
			if (_cad2[i - 1] == _cad1[j - 1])
				_tabla[i][j] = _tabla[i - 1][j - 1] + 1;

			else {
				int pos[3] = { _tabla[i - 1][j - 1], _tabla[i - 1][j], _tabla[i][j - 1]};
				posA = posMayor(pos);
				switch (posA) {
				case 0:
					_tabla[i][j] = pos[0];
					break;
				case 2:
					_tabla[i][j] = pos[2];
					break;
				case 1:
					_tabla[i][j] = pos[1];
					break;
				}
			}

		}
	}
	//cout << " Sub = " << _subSecComun << endl;
	cout << " Valor óptimo: " << _tabla[nCols - 1][nFilas - 1] << endl;
	vueltaAtras();
}

void SubSecuencia::vueltaAtras() {
	int i = nCols - 1, j = nFilas - 1;
	int pos[3];
	int posA = 0;

	while (_tabla[i][j] > 0) {
		pos[0] = _tabla[i - 1][j - 1]; // diag
		pos[1] = _tabla[i][j - 1]; // izq
		pos[2] = _tabla[i - 1][j]; // sup

		posA = posMayor(pos);

		switch (posA) {
		case 1:
			--j;
			break;
		case 0:
			if (pos[0] < _tabla[i][j]) {
				_subSecComun = _cad2[i - 1] + _subSecComun;
			}
			--i;
			--j;
			break;
		case 2:
			--i;
			break;
		}

	}
	cout << "SUB =  " << _subSecComun << endl;
}

int SubSecuencia::posMayor(int* pos) {
	int max = -999, posA = 0;
	for (int i = 0; i < 3; ++i) {
		if (pos[i] > max) {
			max = pos[i];
			posA = i;
		}
	}
	return posA;
}
