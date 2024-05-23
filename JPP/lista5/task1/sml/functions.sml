(*1. Binomial*)
(* Funkcja obliczająca dwumian Newtona *)
fun binomial (n, k) =
    if k = 0 orelse k = n then 1
    else binomial(n-1, k) + binomial(n-1, k-1);

(*2. Binomial2*)
(* Funkcja obliczająca k-ty element n-tego wiersza trójkąta Pascala *)
fun binomial2 (n, k) =
    let
        fun pascal 0 _ = 1
          | pascal i 0 = 1
          | pascal i j = if i = j then 1
                         else pascal (i-1) (j-1) + pascal (i-1) j

        fun buildRow i = List.tabulate (i+1, fn j => pascal i j)

        fun buildTriangle i = if i < n+1 then buildRow i :: buildTriangle (i+1)
                              else []

        val pascalTriangle = buildTriangle 0
    in
        List.nth (List.nth (pascalTriangle, n), k)
    end;


(*3. Mergesort*)
(* Funkcja sortująca przez scalanie *)
fun mergesort [] = []
  | mergesort [x] = [x]
  | mergesort xs =
    let
        fun splitAt (_, [], acc1, acc2) = (List.rev acc1, List.rev acc2)
          | splitAt (0, ys, acc1, acc2) = splitAt (0, tl ys, hd ys :: acc2, acc1)
          | splitAt (n, y::ys, acc1, acc2) = splitAt (n-1, ys, y :: acc1, acc2)
        val (firstHalf, secondHalf) = splitAt (length xs div 2, xs, [], [])
        
        fun merge ([], ys) = ys
          | merge (xs, []) = xs
          | merge (x::xs, y::ys) = if x <= y then x :: merge (xs, y::ys)
                                   else y :: merge (x::xs, ys)
    in
        merge (mergesort firstHalf, mergesort secondHalf)
    end;


(*4. De*)
(* Funkcja rozwiązująca równanie diofantyczne *)
fun de a b =
    let
        fun extended_gcd 0 b = (0, 1, b)
          | extended_gcd a b =
            let
                val (x, y, d) = extended_gcd (b mod a) a
            in
                (y - (b div a) * x, x, d)
            end
        val (x, y, d) = extended_gcd a b
    in
        (x, y, d)
    end;

(*5. Prime Factors*)
(* Funkcja zwracająca listę rozkładu liczby na czynniki pierwsze *)
fun primeFactors n =
    let
        fun factorsHelper (k, p, xs) =
            if k = 1 then xs
            else if k mod p = 0 then factorsHelper(k div p, p, p::xs)
            else factorsHelper(k, p+1, xs)
    in
        factorsHelper(n, 2, [])
    end;

(*6. Totient*)
(* Funkcja obliczająca wartość funkcji Eulera *)
fun totient n =
    let
        fun gcd(a, b) =
            if b = 0 then a
            else gcd(b, a mod b)

        fun isCoprime (a, b) = gcd(a, b) = 1

        fun totientHelper (n, k, count) =
            if k = n then count
            else if isCoprime(n, k) then totientHelper(n, k+1, count+1)
            else totientHelper(n, k+1, count)
    in
        totientHelper(n, 1, 0)
    end;

(*7. Totient2*)
(* Helper function to remove duplicates from a list *)
fun removeDuplicates lst =
    let
        fun remove (_, []) = []
          | remove (seen, x::xs) =
                if List.exists (fn y => y = x) seen then remove (seen, xs)
                else x :: remove (x::seen, xs)
    in
        remove ([], lst)
    end

(* Funkcja obliczająca wartość funkcji Eulera bazując na faktoryzacji liczby *)
fun totient2 n =
    let
        val factors = primeFactors n
        val uniqueFactors = removeDuplicates factors
        val productUniqueFactors = List.foldl (fn (x, y) => x * y) 1 uniqueFactors
        val productPMinus1 = List.foldl (fn (x, y) => x * y) 1 (List.map (fn p => p - 1) uniqueFactors)
    in
        n * productPMinus1 div productUniqueFactors
    end

(*EXTRA TODO: nicer print for large lists*)
(*8. Primes*)
(* Funkcja zwracająca listę liczb pierwszych między 2 a n *)
fun primes n =
    let
        fun sieve [] = []
          | sieve (x::xs) = x :: sieve(List.filter(fn y => y mod x <> 0) xs)
    in
        sieve (List.tabulate(n-1, fn x => x+2))
    end;
