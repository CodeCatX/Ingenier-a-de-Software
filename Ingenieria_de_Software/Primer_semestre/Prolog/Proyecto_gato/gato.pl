% Juego del Gato (Tic-Tac-Toe) en Prolog

% Definición del tablero inicial como una lista de posiciones del 1 al 9
board([
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
]).

% Definición de los jugadores
% isAPlayer/1 verifica si X es un jugador válido (x o o)
isAPlayer(X) :- X = x; X = o.

% Cambio de turno entre los jugadores
% switchPlayer/2 determina el siguiente jugador dado el actual
switchPlayer(x, NextPlayer) :- NextPlayer = o.
switchPlayer(o, NextPlayer) :- NextPlayer = x.

% Oponente del jugador actual
% opponent/2 establece quién es el oponente de un jugador
opponent(x, o).
opponent(o, x).

% Verificación de condiciones de victoria
% checkWin/2 verifica si el jugador actual ha ganado
checkWin(Board, Player) :-
    (
        % Filas
        Board = [Player, Player, Player, _, _, _, _, _, _]; % Fila superior
        Board = [_, _, _, Player, Player, Player, _, _, _]; % Fila media
        Board = [_, _, _, _, _, _, Player, Player, Player]; % Fila inferior
        % Columnas
        Board = [Player, _, _, Player, _, _, Player, _, _]; % Columna izquierda
        Board = [_, Player, _, _, Player, _, _, Player, _]; % Columna central
        Board = [_, _, Player, _, _, Player, _, _, Player]; % Columna derecha
        % Diagonales
        Board = [Player, _, _, _, Player, _, _, _, Player]; % Diagonal principal
        Board = [_, _, Player, _, Player, _, Player, _, _]  % Diagonal secundaria
    ).

% Predicado para verificar si un elemento es miembro de una lista
% isMember/2 es una implementación personalizada del predicado member/2
isMember(Element, [Element|_]).
isMember(Element, [_|Rest]) :- isMember(Element, Rest).

% Verificar si una posición está desocupada
% isUnoccupied/1 verifica si una posición está disponible en el tablero inicial
isUnoccupied(Pos) :-
    board(InitialBoard),
    isMember(Pos, InitialBoard).

% Verificar si una celda en el tablero actual está desocupada
% isUnoccupiedCell/2 utiliza nth1/3 para acceder a la celda en la posición Pos
isUnoccupiedCell(Pos, Board) :-
    nth1(Pos, Board, Cell),
    isUnoccupied(Cell).

% Comprobar si el juego es un empate
% isDraw/1 verifica que no queden posiciones disponibles en el tablero
isDraw(Board) :-
    \+ (isMember(Pos, Board), board(InitialBoard), isMember(Pos, InitialBoard)).

% Dibujar el símbolo del jugador o un espacio en blanco si la celda está vacía
% drawPlayer/1 muestra el símbolo del jugador o espacios en blanco
drawPlayer(X) :-
    (isAPlayer(X) ->
        write(' '), write(X), write(' ')
    ;
        write('   ')
    ).

% Dibujar el tablero actual
% drawBoard/1 imprime el tablero con las posiciones y símbolos actuales
drawBoard([A, B, C, D, E, F, G, H, I]) :-
    drawPlayer(A), write("|"), drawPlayer(B), write("|"), drawPlayer(C), nl,
    write("---+---+---"), nl,
    drawPlayer(D), write("|"), drawPlayer(E), write("|"), drawPlayer(F), nl,
    write("---+---+---"), nl,
    drawPlayer(G), write("|"), drawPlayer(H), write("|"), drawPlayer(I), nl.

% Realizar un movimiento en el tablero
% moveTo/4 coloca el símbolo del jugador en la posición especificada
moveTo(Pos, Player, [Pos|Rest], [Player|Rest]).
moveTo(Pos, Player, [H|T], [H|T2]) :-
    Pos >= 1, Pos =< 9,
    moveTo(Pos, Player, T, T2).

% Movimiento estratégico de la IA
% strategicModeMove/3 define el comportamiento de la IA en modo estratégico
strategicModeMove(Board, Player, NewBoard) :-
    % Intentar ganar en el siguiente movimiento
    findWinningMove(Board, Player, Move),
    moveTo(Move, Player, Board, NewBoard), nl.

strategicModeMove(Board, Player, NewBoard) :-
    % Bloquear al oponente si puede ganar en su próximo movimiento
    opponent(Player, Opponent),
    findWinningMove(Board, Opponent, Move),
    moveTo(Move, Player, Board, NewBoard), nl.

strategicModeMove(Board, Player, NewBoard) :-
    % Elegir la mejor posición disponible
    chooseBestMove(Board, Player, Move),
    moveTo(Move, Player, Board, NewBoard), nl.

% Elegir la mejor posición disponible según prioridades
% chooseBestMove/3 selecciona la posición óptima para la IA
chooseBestMove(Board, _Player, Move) :-
    (
        % Prioridad 1: Centro
        isUnoccupiedCell(5, Board) ->
            Move = 5
    ;
        % Prioridad 2: Esquinas
        isMember(Move, [1, 3, 7, 9]),
        isUnoccupiedCell(Move, Board)
    ;
        % Prioridad 3: Lados
        isMember(Move, [2, 4, 6, 8]),
        isUnoccupiedCell(Move, Board)
    ).

% Encontrar un movimiento ganador para el jugador
% findWinningMove/3 busca una posición que permita ganar al jugador
findWinningMove(Board, Player, Move) :-
    isUnoccupiedCell(Move, Board),
    moveTo(Move, Player, Board, TempBoard),
    checkWin(TempBoard, Player).

% Movimiento aleatorio de la IA
% randomMode_ai_move/3 define el comportamiento de la IA en modo aleatorio
randomMode_ai_move(Board, Player, NewBoard) :-
    random_between(1, 9, Move),
    (isUnoccupiedCell(Move, Board) ->
        moveTo(Move, Player, Board, NewBoard),
        write("La computadora ha movido en la posición "), write(Move), write("."), nl, nl
    ;
        % Si la posición está ocupada, intenta de nuevo
        randomMode_ai_move(Board, Player, NewBoard)
    ).

% Preguntar al usuario si desea continuar jugando
% askContinue/1 solicita al jugador si quiere seguir jugando
askContinue(Result) :-
    write("¿Quieres seguir jugando? [y/n]"),
    read(Result).

% Continuar el juego o finalizar según el estado actual
% continueGame/3 maneja el flujo del juego después de cada movimiento
continueGame(NewBoard, Player, Mode) :-
    (checkWin(NewBoard, Player) ->
        % Si hay un ganador
        drawBoard(NewBoard), nl,
        write("¡Jugador "), write(Player), write(" gana!"), nl,
        askContinue(Result),
        (Result = y -> play ; Result = n -> true), !
    ; isDraw(NewBoard) ->
        % Si es un empate
        drawBoard(NewBoard), nl,
        write("¡Es un empate!"), nl,
        askContinue(Result),
        (Result = y -> play ; Result = n -> true), !
    ;
        % Continuar el juego
        switchPlayer(Player, NextPlayer),
        onPlay(NewBoard, NextPlayer, Mode)
    ).

% Solicitar al jugador que ingrese su posición
% requierePlayerPosition/1 pide al jugador que ingrese la posición donde quiere jugar
requierePlayerPosition(Pos) :-
    write("Ingresa tu posición: "),
    read(Pos), nl.

% Manejo del turno de juego
% onPlay/3 gestiona el turno actual, ya sea del jugador o de la IA según el modo
onPlay(Board, Player, Mode) :-
    drawBoard(Board), nl,
    write("Es el turno de "), write(Player), nl,
    (Player = x ->
        % Turno del jugador humano
        requierePlayerPosition(Pos),
        (moveTo(Pos, Player, Board, NewBoard) ->
            continueGame(NewBoard, Player, Mode)
        ;
            % Movimiento inválido
            write("Movimiento inválido. La posición está ocupada o es inválida. Intenta de nuevo!"), nl,
            onPlay(Board, Player, Mode)
        )
    ;
        % Turno del jugador 'o' (puede ser humano o IA)
        (Mode = pvpMode ->
            % Modo jugador vs jugador
            requierePlayerPosition(Pos),
            (moveTo(Pos, Player, Board, NewBoard) ->
                continueGame(NewBoard, Player, Mode)
            ;
                % Movimiento inválido
                write("Movimiento inválido. La posición está ocupada o es inválida. Intenta de nuevo!"), nl,
                onPlay(Board, Player, Mode)
            )
        ; Mode = randomMode ->
            % Modo IA aleatoria
            randomMode_ai_move(Board, Player, NewBoard),
            continueGame(NewBoard, Player, Mode)
        ; Mode = strategicMode ->
            % Modo IA estratégica
            strategicModeMove(Board, Player, NewBoard),
            continueGame(NewBoard, Player, Mode)
        )
    ).

% Iniciar el juego
% play/0 es el punto de entrada del juego
play :-
    write("--- [Juego del Gato] ---"), nl, nl,
    write("[1] 1 vs 1"), nl,
    write("[2] Jugador vs Máquina (modo aleatorio)"), nl,
    write("[3] Jugador vs Máquina (modo estratégico)"), nl, nl,
    write("Ingresa el modo de juego: "),
    read(Mode), nl,
    (Mode = 1 ->
        board(Board),
        onPlay(Board, x, pvpMode)
    ; Mode = 2 ->
        board(Board),
        onPlay(Board, x, randomMode)
    ; Mode = 3 ->
        board(Board),
        onPlay(Board, x, strategicMode)
    ;
        % Modo inválido, pedir nuevamente
        write("Modo de juego inválido. Intenta de nuevo!"), nl,
        play
    ).