% 1. Merge Sort
% splitList(List, Left, Right) - dzieli listę na dwie części
splitList([], [], []).
splitList([X], [X], []).
splitList([X, Y | Rest], [X | Left], [Y | Right]) :-
    splitList(Rest, Left, Right).

% merge(Left, Right, Merged) - scala dwie posortowane listy
merge([], Right, Right).
merge(Left, [], Left).
merge([H1 | T1], [H2 | T2], [H1 | Merged]) :-
    H1 =< H2,
    merge(T1, [H2 | T2], Merged).
merge([H1 | T1], [H2 | T2], [H2 | Merged]) :-
    H1 > H2,
    merge([H1 | T1], T2, Merged).

% mergesort(List, Sorted) - sortuje listę za pomocą mergesort
mergesort([], []).
mergesort([X], [X]).
mergesort(List, Sorted) :-
    splitList(List, Left, Right),
    mergesort(Left, SortedLeft),
    mergesort(Right, SortedRight),
    merge(SortedLeft, SortedRight, Sorted).


% 2. De
% gcd(A, B, G) - oblicza największy wspólny dzielnik (NWD)
gcd(A, 0, A).
gcd(A, B, G) :-
    B > 0,
    R is A mod B,
    gcd(B, R, G).

% de(A, B, X, Y, Z) - rozwiązuje równanie diofantyczne ax + by = z = gcd(a, b)
de(A, B, X, Y, Z) :-
    gcd(A, B, G),
    Z = G,
    deExtended(A, B, X, Y, G).

% deExtended(A, B, X, Y, G) - rozszerzony algorytm Euklidesa
deExtended(A, 0, 1, 0, A).
deExtended(A, B, X, Y, G) :-
    B > 0,
    R is A mod B,
    Q is A // B,
    deExtended(B, R, X1, Y1, G),
    X is Y1,
    Y is X1 - Q * Y1.


% 3. Prime Factors
% primeFactors(N, Factors) - zwraca listę czynników pierwszych
primeFactors(N, Factors) :-
    primeFactors(N, 2, Factors).

primeFactors(1, _, []).
primeFactors(N, F, [F | Factors]) :-
    N > 1,
    R is N // F,
    N =:= R * F,
    primeFactors(R, F, Factors).
primeFactors(N, F, Factors) :-
    N > 1,
    R is N // F,
    N =\= R * F,
    next_factor(F, NextF),
    primeFactors(N, NextF, Factors).

% next_factor(F, NextF) - znajduje kolejny potencjalny czynnik
next_factor(2, 3).
next_factor(F, NextF) :-
    F > 2,
    NextF is F + 2.


% 4. Totient
% gcd(A, B, G) - oblicza największy wspólny dzielnik (NWD)
% gcd(A, 0, A).
% gcd(A, B, G) :-
%    B > 0,
%    R is A mod B,
%    gcd(B, R, G).

% totient(N, T) - zwraca wartość funkcji Eulera
totient(1, 1).
totient(N, T) :-
    N > 1,
    findall(X, (between(1, N, X), gcd(N, X, 1)), Relatives),
    length(Relatives, T).


% 5. Primes
% isPrime(N) - sprawdza, czy N jest liczbą pierwszą
isPrime(2).
isPrime(3).
isPrime(N) :-
    N > 3,
    N mod 2 =\= 0,
    \+ hasFactor(N, 3).

% hasFactor(N, F) - sprawdza, czy N ma czynnik F
hasFactor(N, F) :-
    N mod F =:= 0.
hasFactor(N, F) :-
    F * F < N,
    F2 is F + 2,
    hasFactor(N, F2).

% primes(N, Primes) - zwraca listę liczb pierwszych między 2 a N
primes(N, Primes) :-
    findall(X, (between(2, N, X), isPrime(X)), Primes).
