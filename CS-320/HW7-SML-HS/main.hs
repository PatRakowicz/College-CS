-- Problem 6
cubed :: Int -> [Int]
cubed n = [x^3 | x <- [1..n]]

-- Problem 7
palindrome :: [Int] -> Bool
palindrome [] = True
palindrome [_] = True
palindrome xs = (head xs == last xs) && (palindrome (init (tail xs)))

-- Problem 8
primeList :: Int -> [Int]
primeList x = filter isPrime [x, x-1 .. 2]
	where
	    isPrime n = n > 1 && all (\i -> n 'mod' i /= 0) [2..n-1]
