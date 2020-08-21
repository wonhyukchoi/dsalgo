-- I felt obliged to add quicksort in Haskell
-- because it is the poster child for the language.
-- It's not fastest implementation out there,
-- and perhaps not even very intelligble,
-- but nonetheless I feel obliged to write it.

main :: IO ()
main = do 
  putStrLn "Input: "
  print example
  putStrLn "Sorted: "
  print $ quickSort example

example :: [Int]
example = [1,5,2345,12,32,12,23,1,3123,13,12]

quickSort :: (Ord a) => [a] -> [a]
quickSort []  = []
quickSort [x] = [x]
quickSort (x:xs) = 
  quickSort lesser ++ [x] ++ quickSort greater
  where 
    lesser  = filter (< x)  xs
    greater = filter (>= x) xs 




