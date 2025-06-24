agent(dirty,B,clean,B):-
    write("cleaning room a")
.
agent(A,dirty,A,clean):-
    write("cleaning rOom b")
.

agent(dirty,dirty,clean,clean):-
    agent(A,dirty,newA,newB)
    agent(dirty,B,newA,newB)
.

vaccumcleaner(A,B):-
    agent(A,B,newA,newB):-
        agent(newA,newB):-

        .
    .
.

vaccumcleaner(clean,clean):-
    write("cleaned room a and rrom b")
.