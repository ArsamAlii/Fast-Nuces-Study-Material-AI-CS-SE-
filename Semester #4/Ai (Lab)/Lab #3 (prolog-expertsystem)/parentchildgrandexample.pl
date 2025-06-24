% Facts: Defining parent-child relationships
parent(john, mary).
parent(john, paul).
parent(susan, mary).
parent(susan, paul).
parent(mary, linda).
parent(paul, james).

% Rules: Defining relationships using logic
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).

grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% Defining gender
male(john).
male(paul).
male(james).
female(susan).
female(mary).
female(linda).
% vacuum_agent(Status_A, Status_B)
% Status can be either 'dirty' or 'clean'.

% Base case: If both rooms are already clean, print completion message
vacuum_agent(clean, clean) :-
    write('Both rooms are clean! Task complete.'), nl.

% Case 1: If Room A is dirty, clean it and move to Room B
vacuum_agent(dirty, Status_B) :-
    write('Cleaning Room A'), nl,
    vacuum_agent(clean, Status_B).

% Case 2: If Room B is dirty, clean it and complete the task
vacuum_agent(clean, dirty) :-
    write('Cleaning Room B'), nl,
    vacuum_agent(clean, clean).
