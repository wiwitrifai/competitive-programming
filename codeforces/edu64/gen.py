n = 2 * 10 ** 5
import random
p = [i+1 for i in range(n)]
random.shuffle(p)
print(n)
print(' '.join(map(str, p)))