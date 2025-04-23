suma([], 0).
suma([X|C], Suma):- suma(C, Sumacola), Suma is Sumacola+X.

n_elementos([], 0).
n_elementos([_|C], Total) :- n_elementos(C, Contador), Total is Contador+1.

ordenar_elementos([], []).
ordenar_elementos([X|Y], Z):- ordenar_elementos(Y, Z1), insertar(X, Z1, Z).
insertar(X, [], [X]).
insertar(X, [Y|Z], [X,Y|Z]):- X=<Y.
insertar(X, [Y|Z], [Y|W]):- X>Y, insertar(X, Z, W).

es_par(X) :- X mod 2 =:= 0.
es_impar(X) :- X mod 2 =\= 0.

f_piso(N, 0) :- N>=0, N<1.
f_piso(N, NP) :- N>0, N1 is N-1, f_piso(N1, NP1), NP is NP1+1.
f_techo(N, 0) :- N>=0, N<1.
f_techo(N, NT) :- N>0, N1 is N-1, f_piso(N1, NT1), NT is NT1+2.

media([], 0).
media([X|Y], Media) :- suma([X|Y], Suma), n_elementos([_|Y], TotalE), Media is Suma/TotalE.

k_elemento([Resultado|_], 0, Resultado).
k_elemento([_|C], K, Resultado):- K > 0, K1 is K - 1 , k_elemento(C,K1,Resultado).
mediana([], 0).
mediana(Lista, Z):- n_elementos(Lista, Z1), es_impar(Z1), Z2 is (Z1+1)/2, ordenar_elementos(Lista, Z3), k_elemento(Z3, Z2-1, Z).
mediana(Lista, Z):- n_elementos(Lista, Z1), es_par(Z1), ordenar_elementos(Lista, Z3), k_elemento(Z3, (Z1/2)-1, Num1), k_elemento(Z3, (Z1/2), Num2), Z is (Num1+ Num2)/2.

contador_de_apariciones(_, [], 0).
contador_de_apariciones(X, [X|Z], N):- contador_de_apariciones(X, Z, N1), N is N1+1.
contador_de_apariciones(X, [_|Z], N):- contador_de_apariciones(X, Z, N).
actualizar(X, M, Z1, Z2, R, R1):- (Z1>Z2)-> R is X, R1 is Z1.
actualizar(X, M, Z1, Z2, R, R1):- (Z1=<Z2)-> R is M, R1 is Z2.
modacalc(Lista, M, Z2, Iteracion, Z, Detenerse):- (contar_elem(Detenerse, Iteracion))-> Z is M.
modacalc([X|Y], M, Z2, Iteracion, Z, Detenerse):- contador_de_apariciones(X, [X|Y], Z1), actualizar(X, M, Z1, Z2, R, R1), Iteracion2 is Iteracion + 1, modacalc(Y, R, R1, Iteracion2, Z, Detenerse).

moda([], 0). 
moda(Lista, Z):- modacalc(Lista, 0, 1, 1, Z, Lista).

sumatoria([X|Y], Sumatoria) :- suma([X|Y], Sumatoria).

productorio([],  1).
productorio([X|Y], Productorio) :- productorio(Y, P1), Productorio is P1*X.


