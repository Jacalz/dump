import math

# Amount of triangles to calculate. Larger number equals to longer time to completion.
n = 3000

# Just define the c variable to zero initally.
c = 0

# Loop through and calculate all the triangles.
for a in range(1, n+1, 1):
    for b in range(a, min(a*a+1, n+1), 1):
      if math.floor(math.sqrt(a*a+b*b-a*b)) == math.ceil((math.sqrt(a*a+b*b-a*b))):
        c += 1

# Lastly, we print the amount of possible triangles within the n number of triangles.
print(c)
