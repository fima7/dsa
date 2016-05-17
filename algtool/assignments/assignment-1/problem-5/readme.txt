Если слово "кольцо" вдруг пугает, представьте себе круглый циферблат часов, размеченный числами $0,1,\ldots,n-1$ через равномерные промежутки (классический циферблат --- для $n = 12$, только $12$ надо заменить на $0$). Кроме того, к циферблату приделана часовая стрелка, которая проходит одно деление в час. Теперь если мы выставим часовую стрелку часовую стрелку на $0$ и подождём $a$ часов, то она укажет на $a \mod n$...


Matrix exponentioation:

Matrix exponentiation makes use of the fact that a fibonacci number Fn can be represented by 2 corners of the nth power of a 2x2 matrix: (1 1 \n 1 0)^n. Then they make use of Euler's power modulo theorem to find the Fn mod m, which now will be equal to (1 1 \n 1 0)^n mod m.
