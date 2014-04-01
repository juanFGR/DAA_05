//============================================================================
// Name        : SubSecMasLarga.cpp
// Author      : JuanFGR
// Version     :
// Copyright   : alu4074
//============================================================================

#include <iostream>
using namespace std;

#include "Simulador.h"

int main() {
	int dim [5] = {10, 100, 5, 50, 1 };

	Simulador* simul = new Simulador ("ACGTGCATGGAAGTCAAGTCCAGTCACTGAAAGGTCGATACTGACTAAGGCCT", "ACTGAGAATTCCGATCAGACGTCACTGAAAGGTCGATACTGACTAAAAGTCCT");
	simul -> interfazAlgoritmo();
	simul = new Simulador (dim, 5);
	simul -> interfazAlgoritmo();
	return 0;
}
