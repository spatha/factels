-- Code during HACKATHON 2012
--
-- Yury Vorobyov <teupollam@gmail.com>
--
--

hello = putStrLn "Hello world!"

factorial 1 = 1
factorial n = n * factorial (n-1)

main = hello

motion x v delta =
	x + v * delta;

forcefield :: Double -> Double
forcefield r = r^(-14)-r^(-7)

potential :: Particles -> Double
potential particles = sum forcefield 

