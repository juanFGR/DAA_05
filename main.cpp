//============================================================================
// Name        : SubSecMasLarga.cpp
// Author      : JuanFGR
// Version     :
// Copyright   : alu4074
//============================================================================

#include <iostream>
using namespace std;

#include "Simulador.h"

int main(int argc, char *argv[]) {	
Simulador* simul = new Simulador (argv[1],argv[2]);
	simul -> interfazAlgoritmo();
	cout<<endl;
	return 0;
}
