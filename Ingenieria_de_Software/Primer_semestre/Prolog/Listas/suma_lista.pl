% Suma de elementos en una lista %
suma_lista([], 0).
suma_lista([Cabeza|C], X) :- suma_lista(C, X1), X is X1+Cabeza.

% Buscar elemento en una lista %
buscar(X, [X|_]).
buscar(X, [_|C]) :- buscar(X, C).









