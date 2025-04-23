es_par(X) :- X mod 2 =:= 0.
es_impar(X) :- X mod 2 =\= 0.

% Sucesion con Collatz %
collatz(_, 1).
collatz(I, N) :- (es_par(N), I>0, I1 is I-1, collatz(I1, R), R is N//2);(es_impar(N), I>0, I1 is I-1, collatz(I1, R), R is N*3+1).

% Sucesión de Collatz con lista %

collatz_lista(1, [1]).
collatz_lista(X, [X|C]) :- es_par(X), X>1, X1 is X//2, collatz_lista(X1, C).
collatz_lista(X, [X|C]) :- es_impar(X), X>1, X1 is 3*X+1, collatz_lista(X1, C).

% Otra función recursiva %
f(1, 1).
f(2, 1).
f(N, R) :- N>=3, N1 is N-1, f(N1, X), N2 is N1*X, N3 is N-2, f(N3, X1), N4 is N3*X1, R is N2-N4.

% Función piso %
piso(X, 0) :- X>=0, X<1.
piso(X, Y) :- X>0, X1 is X-1, piso(X1, Y1), Y is Y1+1.
piso(X, Y) :- X<0, X1 is X+1, piso(X1, Y1), Y is Y1-1.

% Función techo %
techo(X, 0) :- X>=0, X<1.
techo(X, Y) :- X>0, X1 is X-1, piso(X1, Y1), Y is Y1+2.
techo(X, Y) :- X<0, X1 is X+1, piso(X1, Y1), Y is Y1-2.

% Otra %
otra(1, 0).
otra(N, Y) :- N>1, Div is N/2, Potencia is N*N, piso(Div, Y1), Y is Y1+Potencia.
