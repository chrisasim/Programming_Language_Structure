-- example of defining variable in 'where' binding
bmiTell :: (RealFloat a) => a -> a -> String  
bmiTell weight height  
     | bmi <= skinny = "You're underweight, you emo, you!"  
     | bmi <= normal = "You're supposedly normal. Pffft, I bet you're ugly!"  
     | bmi <= fat    = "You're fat! Lose some weight, fatty!"  
     | otherwise     = "You're a whale, congratulations!"  
     where bmi = weight / height ^ 2  
           skinny = 18.5  
           normal = 25.0  
           fat = 30.0

-- example of defining variable in 'let' binding           
areaTriangle' :: Float -> Float -> Float -> Float
areaTriangle' a b c
     |(a + b <= c) || (a + c <= b) || (b + c <= a) = error "Sides a, b, c don't describe a triangle"
     |otherwise = let s=(a+b+c)/2
     in  sqrt(s*(s-a)*(s-b)*(s-c))  
     
-- example of type variables
head :: [a] -> a