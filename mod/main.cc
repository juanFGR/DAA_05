/**
 * Práctica: "Subsecuencia Común más Larga"
 * Asignatura: Diseño y Análisis de Algoritmos.
 * Curso: 3º
 * Itinerario: Computación.
 * 
 * Alumno: Juan francsico González Ramos.
 * 
 * Fichero: main.cc
 * 
 * Descripción: Fichero que engloba la función principal que realiza el flujo de 
 *              ejecución del programa y dando solución al problema mediante la
 *              instanciación de un objeto de la clase solución.
 * @class main.cc
 * @see Solucion.cc
 * @see Solucion.h
 */




# include "Solucion.h"
# include <ctime>
int main (int argc, char** argv) {
  system("clear");
  time_t inicio, fin;
  
  
  Solucion s (argv[1], argv[2]);
  inicio = time (NULL);
  s.resolver ();
  fin = time (NULL);
  s.mostrar_tabla ();
  cout << "Tiempo : " << difftime (fin, inicio) << " segundos." << endl;
  
}
