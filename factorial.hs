-- Code during HACKATHON 2012
--
-- Yury Vorobyov <teupollam@gmail.com>
--
--

hello = putStrLn "Hello world!"

factorial 1 = 1
factorial n = n * factorial (n-1)

main = hello

