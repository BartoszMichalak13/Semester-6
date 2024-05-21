import Data.List (nub) --needed by Totient2

-- 1. Binomial
binomial :: Integer -> Integer -> Integer
binomial _ 0 = 1
binomial n k | n == k    = 1
             | otherwise = binomial (n - 1) k + binomial (n - 1) (k - 1)

-- 2. Binomial2
binomial2 :: Integer -> Integer -> Integer
binomial2 n k = (pascalTriangle !! (fromIntegral n)) !! (fromIntegral k)
  where pascalTriangle = [[pascal i j | j <- [0..i]] | i <- [0..]]
        pascal _ 0 = 1
        pascal x y | x == y    = 1
                   | otherwise = pascalTriangle !! (x - 1) !! (y - 1) + pascalTriangle !! (x - 1) !! y

-- 3. Mergesort
mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort firstHalf) (mergesort secondHalf)
  where (firstHalf, secondHalf) = splitAt (length xs `div` 2) xs
        merge [] ys = ys
        merge xs [] = xs
        merge (x:xs) (y:ys) | x <= y    = x : merge xs (y:ys)
                            | otherwise = y : merge (x:xs) ys

-- 4. De
-- Funkcja rozszerzonego algorytmu Euklidesa
extendedGCD :: Integral a => a -> a -> (a, a, a)
extendedGCD 0 b = (0, 1, b)
extendedGCD a b =
  let (q, r) = b `quotRem` a
      (x, y, g) = extendedGCD r a
  in (y - q * x, x, g)

-- Funkcja rozwiązująca równanie ax + by = gcd(a, b)
de :: Integral a => a -> a -> (a, a, a)
de a b = (x, y, g)
  where
    (x, y, g) = extendedGCD a b


-- 5. Prime factors
primeFactors :: Integer -> [Integer]
primeFactors n = factorize n 2
  where factorize 1 _ = []
        factorize n p
          | n `mod` p == 0 = p : factorize (n `div` p) p
          | otherwise      = factorize n (p + 1)

-- 6. Totient
totient :: Integer -> Integer
totient n = fromIntegral $ length [x | x <- [1..n], gcd n x == 1]

--7. Totient2
totient2 :: Integer -> Integer
totient2 n = n * product [(p - 1) | p <- uniqueFactors] `div` product uniqueFactors
  where
    factors = primeFactors n
    uniqueFactors = nub factors


-- 8. Primes
primes :: Integer -> [Integer]
primes n = sieve [2..n]
  where sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p /= 0]
        sieve []     = []

-- Test function
testFunction :: String -> [Integer] -> IO ()
testFunction "binomial" [n, k] = putStrLn $ "Binomial " ++ show n ++ " " ++ show k ++ " = " ++ show (binomial n k)
testFunction "binomial2" [n, k] = putStrLn $ "Binomial2 " ++ show n ++ " " ++ show k ++ " = " ++ show (binomial2 n k)
testFunction "mergesort" xs = putStrLn $ "Mergesort " ++ show xs ++ " = " ++ show (mergesort xs)
testFunction "de" [a, b] = let (x, y, z) = de a b in putStrLn $ "De " ++ show a ++ " " ++ show b ++ " = (" ++ show x ++ ", " ++ show y ++ ", " ++ show z ++ ")"
testFunction "primeFactors" [n] = putStrLn $ "Prime factors of " ++ show n ++ " = " ++ show (primeFactors n)
testFunction "totient" [n] = putStrLn $ "Totient of " ++ show n ++ " = " ++ show (totient n)
testFunction "totient2" [n] = putStrLn $ "Totient2 of " ++ show n ++ " = " ++ show (totient2 n)
testFunction "primes" [n] = putStrLn $ "Primes up to " ++ show n ++ " = " ++ show (primes n)
testFunction "quit" _ = putStrLn "Exiting..."
testFunction _ _ = putStrLn "Invalid function name or arguments"

-- Main function
main :: IO ()
main = do
    putStrLn "Enter function name and arguments separated by spaces (type 'quit' to exit):"
    input <- getLine
    let (funcName:args) = words input
    if funcName == "quit"
        then putStrLn "Exiting..."
        else do
            testFunction funcName (map read args)
            main