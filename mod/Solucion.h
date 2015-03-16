/**
 * Descripción: Declaracion de la clase utlizada en la resolucion 
 * del problema
 * @class Solusion.h
 * @see Solucion.cc
 * @see main.cc
 */

# ifndef _SOLUCION_H_
# define _SOLUCION_H_

# include <iostream>
#include <stdlib.h>
using namespace std;

class Solucion {
  private:
    string cadena1;
    string cadena2;
    string resultado;
    
    unsigned filas; 
    unsigned columnas; 
    unsigned** Tabla;
    
    
  public:
    Solucion (string c1, string c2);
    
    inline void set_cadena1 (string c1) { cadena1 = c1; }
    inline void set_cadena2 (string c2) { cadena2 = c2; }
    inline void set_resultado (string r) { resultado = r;}
    inline void set_f (unsigned fils) { filas = fils; }
    inline void set_c (unsigned cols) { columnas = cols; }
    
    inline unsigned num_Fila (void) { return filas; }
    inline unsigned num_Columna (void) { return columnas; }
    inline string get_cadena1 (void) { return cadena1; }
    inline string get_cadena2 (void) { return cadena2; }
    inline string get_resultado (void) { return resultado; }
    
    inline unsigned get_elemento_tabla (unsigned i, unsigned j) { return Tabla[i][j]; }
    
    unsigned resolver (void); 
    
    void mostrar_tabla (void);
  
};

# endif