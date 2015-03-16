# DAA_05


La programación dinámica es un método general para la resolución de problemas complejos consistente en la división de los mismos en subproblemas más sencillos de forma recursiva, reduciendo así el tiempo de ejecución. Para poder aplicar estos métodos el problema a resolver debe tener una subestructuta óptima, es decir, para cada subproblema se puede encontrar una solución óptima, de manera que la combinación de todas ellas dará una solución óptima del problema completo. Además, debe presentar subproblemas superpuestos, es decir, el espacio requerido para los subproblemas debe ser pequeño, para que una vez resuelto un subproblema se pueda almacenar el resultado sin un coste excesivo, y así poder reutilizarlo en pasos posteriores.



En el tercer apartado de esta práctica se debe resolver el problema de encontrar la máxima subcadena común dadas dos cadenas, o lo que es lo mismo, la cadena común más larga que se puede conseguir en ambas cadenas iniciales a base de eliminar letras.

Si se parte de dos cadenas S=[s1 ... sp] y T=[t1 ... tq], se quiere determinar el valor de l(S,T)=lpq, que define la longitud de la subcadena común más larga. Como en los apartados anteriores, para llegar a esta expresión se rellenará de forma recursiva una matriz tomando como criterio la siguiente expresión:

        lij = 1 + l(i-1)(j-1) si si = tj.
        lij = máx {l(i-1)j, li(j-1), l(i-1)(j-1)} si son distintos. 

        Con valores de arranque:
            0 para la cadena vacía (primera fila y primera columna).
La matriz a rellenar tendrá tantas filas como la longitud de la primera cadena más uno y tantas columnas como la longitud de la segunda cadena más uno. La matriz se rellenará de izquierda a derecha y de arriba abajo.

La reconstrucción de la subcadena común se hará, al igual que en el problema de la suma, recorriendo la tabla por el camino que da la solución óptima pero hacia atrás. Habrá que identificar qué caracteres han producido, durante la primera fase del algoritmo, un aumento de la longitud de la subcadena para llegar a la mejor solución. Intuitivamente, habrá que desplazarse hacia la casilla adyacente (en este caso, la superior, izquierda o diagonal superior izquierda) que haya inducido el valor de la casilla actual. En los casos en los que haya sido la casilla diagonal, y se haya producido además un aumento de la longitud de la subcadena parcial, se añadirá el carácter correspondiente a la subcadena total.

Esto se puede formalizar en el siguiente algoritmo:

Comenzar en la esquina inferior derecha.
Mientras la celda actual (i, j) sea mayor que 0:
Avanzar a la celda adyacente (superior (i-1,j), izquierda (i,j-1) o diagonal superior izquierda (i-1,j-1)) con mayor valor asociado. En caso de empate, avanzar a la celda diagonal.
Si se ha avanzado a la celda diagonal (i-1,j-1) y el valor de esta celda es uno menos el valor de la celda de la que se procede, m(i-1,j-1) = m(i,j) - 1, añadir el carácter correspondiente (el carácter de la posición i-1 de la cadena 1, que coincidirá con el carácter j-1 de la cadena 2) a la subcadena común.
Invertir la subcadena obtenida.
NOTA: En caso de empate, se prefieren los movimientos diagonales porque optimizan la reconstrucción, puesto que el algoritmo anterior terminará cuando se alcance una celda que contenga 0, y esto se asegura en el borde de la matriz (aunque pueda darse antes).



