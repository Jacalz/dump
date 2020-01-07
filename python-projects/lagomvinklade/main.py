import math

n = 30
c = 0

for a in range(1, n+1, 1):
    for b in range(a, min(a*a+1, n+1), 1):
      if math.floor(math.sqrt(a*a+b*b-a*b)) == math.ceil((math.sqrt(a*a+b*b-a*b))):
        c += 1

print(c)
