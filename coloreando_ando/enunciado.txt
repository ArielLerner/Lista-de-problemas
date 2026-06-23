Coloreando ando
Enunciado

Una coloración de las celdas de una tabla de n × m se considera buena si no existen cuatro celdas del mismo color cuyos centros formen los vértices de un rectángulo con lados paralelos a los ejes.

Es decir, no debe existir una cuádrupla de enteros:

x1, x2, y1, y2

tal que:

1 ≤ x1 < x2 ≤ n
1 ≤ y1 < y2 ≤ m

y las cuatro celdas:

(x1, y1), (x2, y1), (x1, y2), (x2, y2)

tengan el mismo color.

Dado n, m y c, el objetivo es encontrar cualquier coloración buena de una tabla de n × m usando c colores.

Se garantiza que para todos los casos de prueba existe al menos una solución válida.

Input

La primera línea contiene tres enteros:

n m c

donde:

2 ≤ n, m ≤ 10
2 ≤ c ≤ 3
Output

Imprimir n filas con m enteros cada una.

El número j-ésimo de la fila i-ésima representa el color asignado a la celda (i, j).

Cada valor debe cumplir:

1 ≤ ai,j ≤ c

Si existen varias coloraciones válidas, se puede imprimir cualquiera.

Ejemplo
Input
2 2 2
Output
1 2
2 2
Idea de solución

Como n y m son como máximo 10, se puede buscar una coloración válida usando backtracking.

Para verificar que no se forme un rectángulo inválido, alcanza con controlar para cada color si ya hubo dos filas que comparten dos columnas del mismo color.

En mi implementación, voy llenando la matriz celda por celda e intento colocar un color. Antes de fijarlo, reviso si al poner ese color se forma un rectángulo monocromático. Si se forma, descarto esa rama.

También se pueden agregar podas para repartir mejor la cantidad de colores usados y evitar explorar ramas demasiado desbalanceadas.

Restricciones
2 ≤ n, m ≤ 10
2 ≤ c ≤ 3
Complejidad

La solución por backtracking no tiene una complejidad polinómica estricta, ya que en el peor caso podría probar muchas coloraciones.

Sin embargo, con podas y verificaciones rápidas, puede funcionar bien para los casos chicos o para generar construcciones válidas particulares.
