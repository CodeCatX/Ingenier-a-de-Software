sumar_elem([], 0).
sumar_elem([H|T], Suma) :- sumar_elem(T, Sumatoria), Suma is Sumatoria+H.

insertar_elem(X, [], [X]).
insertar_elem(X, [H|T], [X, H|T]) :- X=<H.
insertar_elem(X, [H|T], [H|S]) :- X>H, insertar_elem(X,T,S).

ordenar_elem([], []).
ordenar_elem([H|T], Z) :- ordenar_elem(T, Z1), insertar_elem(H, Z1, Z).

f_piso(X, 0) :- X>=0, X<1.
f_piso(X, Y) :- X>0, X1 is X-1, f_piso(X1, Y1), Y is Y1+1.

n_apariciones(_, [] , 0).
n_apariciones(X, [X|T] , N) :- n_apariciones(X, T, N1), N is N1+1.
n_apariciones(X, [_|T], N) :- n_apariciones(X, T, N).


