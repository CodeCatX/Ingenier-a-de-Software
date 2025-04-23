:-style_check(-discontiguous).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Base de conocimiento - Árbol genealógico %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_padre_de(caos, nix).
es_padre_de(caos, erebo).
es_padre_de(caos, gea).
es_padre_de(caos, urano).
es_padre_de(caos, eter).
es_padre_de(caos, hemera).
es_padre_de(caos, tartaro).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Nix %
es_madre_de(nix, moros).
es_madre_de(nix, ker).
es_madre_de(nix, tanatos).
es_madre_de(nix, hipnos).

% Nix y Erebo %
es_madre_de(nix, aether).
es_madre_de(nix, hemera).
es_padre_de(erebo, aether).
es_padre_de(erebo, hemera).

% Gea y Urano %
es_madre_de(gea, cronos).
es_madre_de(gea, rea).
es_madre_de(gea, oceano).
es_madre_de(gea, hiperion).
es_madre_de(gea, tethys).
es_madre_de(gea, tea).
es_madre_de(gea, japeto).
es_madre_de(gea, temis).
es_madre_de(gea, crio).
es_madre_de(gea, mnemosine).
es_madre_de(gea, ceos).
es_madre_de(gea, febe).
es_padre_de(urano, cronos).
es_padre_de(urano, rea).
es_padre_de(urano, oceano).
es_padre_de(urano, hiperion).
es_padre_de(urano, tethys).
es_padre_de(urano, tea).
es_padre_de(urano, japeto).
es_padre_de(urano, temis).
es_padre_de(urano, crio).
es_padre_de(urano, mnemosine).
es_padre_de(urano, ceos).
es_padre_de(urano, febe).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Cronos y Rea %
es_madre_de(rea, hestia).
es_madre_de(rea, demeter).
es_madre_de(rea, hera).
es_madre_de(rea, hades).
es_madre_de(rea, poseidon).
es_madre_de(rea, zeus).
es_padre_de(cronos, hestia).
es_padre_de(cronos, demeter).
es_padre_de(cronos, hera).
es_padre_de(cronos, hades).
es_padre_de(cronos, poseidon).
es_padre_de(cronos, zeus).

% Hiperion y Tea %
es_madre_de(tea, helios).
es_madre_de(tea, selene).
es_madre_de(tea, eos).
es_padre_de(hiperion, helios).
es_padre_de(hiperion, selene).
es_padre_de(hiperion, eos).

% Oceano y Tethys %
es_madre_de(tethys, climene).
es_madre_de(tethys, metis).
es_madre_de(tethys, pleyone).
es_padre_de(oceano, climene).
es_padre_de(oceano, metis).
es_padre_de(oceano, pleyone).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Japeto y Climene %
es_madre_de(climene, atlas).
es_madre_de(climene, prometeo).
es_madre_de(climene, menecio).
es_madre_de(climene, epimeteo).
es_padre_de(japeto, atlas).
es_padre_de(japeto, prometeo).
es_padre_de(japeto, menecio).
es_padre_de(japeto, epimeteo).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Zeus y Hera %
es_madre_de(hera, hebe).
es_madre_de(hera, ares).
es_madre_de(hera, llitia).
es_madre_de(hera, hefesto).
es_madre_de(hera, enio).
es_madre_de(hera, eris).
es_padre_de(zeus, hebe).
es_padre_de(zeus, ares).
es_padre_de(zeus, illitia).
es_padre_de(zeus, hefestos).
es_padre_de(zeus, enio).
es_padre_de(zeus, eris).

% Zeus y Demeter %
es_madre_de(demeter, persefone).
es_padre_de(zeus, persefone).

% Zeus y Gea %
es_madre_de(gea, agdistis).
es_madre_de(gea, manes).
es_padre_de(zeus, agdistis).
es_padre_de(zeus, manes).

% Zeus y Persefone %
es_madre_de(demeter, zagro).
es_madre_de(demeter, melinoe).
es_padre_de(zeus, zagreo).
es_padre_de(zeus, melinoe).

% Zeus y Selene %
es_madre_de(selene, ersa).
es_madre_de(selene, pandia).
es_madre_de(selene, nemea).
es_madre_de(selene, dioniso).
es_padre_de(zeus, ersa).
es_padre_de(zeus, pandia).
es_padre_de(zeus, nemea).
es_padre_de(zeus, dioniso).

%Zeus y Metis%
es_madre_de(metis, atenea).
es_padre_de(zeus, atenea).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Hijo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
es_hijo_de(X, Y) :- es_padre_de(Y, X); es_madre_de(Y, X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Hermano %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_hermano_de(X, Y) :- es_padre_de(Z, X), es_padre_de(Z, Y), X \= Y.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Abuelo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_abuelo_de(X, Y) :- es_padre_de(X, Z), es_padre_de(Z, Y), X \= Y.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Nieto %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_nieto_de(X, Y) :- es_padre_de(Y, Z), es_padre_de(Z, X), Y \= X.
% es_nieto_de(X, Y) :- es_abuelo_de(Y, X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Tío %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_tio_de(X, Y) :- es_padre_de(K, Z), es_padre_de(K, X), es_padre_de(Z, Y).
% es_tio_de(X, Y) :- es_hermano_de(X, Z), es_hijo_de(Y, Z).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Primo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_primo_de(X, Y) :- es_padre_de(K, J), es_padre_de(K, Z), es_padre_de(J, X), J \= Z.
% es_primo_de(X, Y) :- es_tio_de(J, Y), es_padre_de(K, X), es_hermano_de(K, J).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Primo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_sobrino_de(X, Y) :- es_padre_de(A, B), es_padre_de(A, Y), es_padre_de(B, X), Y \= B.
% es_sobrino_de(X, Y) :- es_tio_de(Y, X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Suegro %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_suegro_de(X, Y) :- es_padre_de(X, A), es_padre_de(A, B), (es_padre_de(Y, B); es_madre_de(Y, B)), X \= A.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Yerno %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_yerno_de(X, Y) :- es_padre_de(X, A), es_madre_de(Y, A), A \= X.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Familiar político %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_familiar_politico_de(X, Y) :- es_yerno_de(X, Y); es_suegro_de(X, Y).