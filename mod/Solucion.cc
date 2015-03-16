/**
 * Descripción: Tiene los metodos para resolver el problema
 * utilizando la técnica de "PROGRMACIÓN DINÁMICA".
 * @class Solusion.cc
 * @see Solucion.h
 * @see main.cc
 */

# include "Solucion.h"

Solucion::Solucion (string c1, string c2) {
  
  set_cadena1 (c1);
  set_cadena2 (c2);
  set_c (cadena1.size () + 1);
  set_f (cadena2.size () + 1);
  set_resultado ("Default");
  Tabla = new unsigned*[num_Columna()];
  
  for (unsigned i = 0; i < num_Columna (); i++){
    Tabla[i] = new unsigned[filas];
      for (unsigned j = 0; j < num_Fila (); j++)
	Tabla[i][j] = 0;
  }  
}

/**
@return unsigned
*/
unsigned Solucion::resolver (void) {
  string cad_aux = "";
 
  for (unsigned i = 1; i < num_Columna (); i++) {
    for (unsigned j = 1; j < num_Fila (); j++) {
      if (get_cadena1 () [i-1] == get_cadena2 () [j-1]) {
        Tabla[i][j] = get_elemento_tabla (i - 1, j - 1) + 1;
        
      } else if (get_elemento_tabla (i - 1, j) >= get_elemento_tabla (i, j - 1))
        Tabla[i][j] = get_elemento_tabla (i - 1, j);
      
      else
        Tabla[i][j] = get_elemento_tabla (i, j - 1);
      if (j + 1 == num_Fila () && get_elemento_tabla (i - 1, j) < get_elemento_tabla (i, j) )
                cad_aux += get_cadena1 ()[i-1];
    }
  }
  set_resultado (cad_aux);
  return Tabla[columnas - 1][filas - 1];
}


/**
Imprime por pantalla la matriz
@author JuanFGR
@return void
*/
void Solucion::mostrar_tabla (void) {
  for (unsigned i = 1; i < num_Columna (); i++) {
    for (unsigned j = 1; j < num_Fila (); j++)
      cout << "|" << get_elemento_tabla (i, j) << "|";  
    cout << endl;
  }

  
  int pos = 0;
  
  //Almacenando cadenas para ser tratadas en la modificacion del laboratorio
  string aux1 = get_cadena1(); 
  string aux2 = get_resultado();
  string aux3 = get_cadena2();
   
  for(int i=0;i<aux1.size();i++){
      if(aux1[i] == aux2[pos]){
	//pintando la solcuion debido a vizualirse mal con guiones
	cout<<"\033[0;43m"<<aux1[i]<<"\033[0m"; 
	pos++;
      }else
      cout<<aux1[i];//imprimos caracteres que no coincidan
  }
   cout<<endl;
   
   pos = 0; 
    for(int i=0;i<aux3.size();i++){
      if(aux3[i] == aux2[pos]){
	//pintando la solcuion debido a vizualirse mal con guiones
	cout<<"\033[0;43m"<<aux1[i]<<"\033[0m";
	pos++;
      }else
      cout<<aux3[i];//imprimos caracteres que no coincidan
  }
   cout<<endl;
    
   
  cout<<"Resultado:"<< aux2 << endl;
  
  
  
  
  
  
  
}
