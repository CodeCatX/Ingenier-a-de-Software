% Hechos
es_mujer(ana).
es_hombre(luis).
engendro_a(luis, maria).
engendro_a(luis, jose).
engendro_a(ana, maria).
engendro_a(ana, juan).

% Reglas
es_madre(X, Y) :- es_mujer(X), engendro_a(X, Y).
es_padre(J, K) :- es_hombre(J), engendro_a(J, K).
