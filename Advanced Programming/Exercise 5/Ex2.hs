main :: IO ()
main = return ()

and :: [Bool] -> Bool
and [] = True
and (False:_) = False
and (True:xs) = Main.and xs

elem :: Eq a => a -> [a] ->  Bool
elem k [] = False
elem k (x:xs)
        | k == x = True
        | otherwise = Main.elem k xs 

concat :: [[a]] -> [a]
concat [] = []
concat (x:xs) = x ++ Main.concat xs

replicate :: Int -> a -> [a]
replicate 0 y = [ ]
replicate x y = y : Main.replicate (x-1) y

(!!) :: [a] -> Int -> a
(!!) (x:xs) k
        | k == 0 = x
        | otherwise = (Main.!!) xs (k-1) 


merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []

msort :: Ord a => [a] -> [a]
msort [] = []

