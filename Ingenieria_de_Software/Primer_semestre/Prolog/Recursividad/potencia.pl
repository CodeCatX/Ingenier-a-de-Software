potencia(_, 0,  1).
potencia(X, Y, Resultado) :- Y > 0, P is Y-1, potencia(X, P, Parcial), Resultado is X * Parcial.



















