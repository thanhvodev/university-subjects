main :: IO ()
main = return ()
doubleAll :: [Int] -> [Int]
doubleAll n = [2*x| x <-n]
positives :: [Int] -> [Int]
positives n = [x|x<-n,x>0]
