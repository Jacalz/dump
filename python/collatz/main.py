
# CollatzCounter beräkningar antalet itereringar som krävs för att få svaret 1 från talet n med Collatz förmodan.
def CollatzCounter(n):
	# Variablen i är vår iterator som adderas för att beräkna hur många ittereringar som vi behöver.
	i = 0

	# Vi loopar så länge som inputen inte är ett.
	while n != 1:
		# Om input modulo 2 är noll så betyder det att rest vid division med två. Alltså är talet jämnt, annars så är det udda.
		if n % 2 == 0:
			n /= 2 # Beräkning för jämnt tal,dela n med två. Shorthand för att slippa skriva n = n / 2...
		else:
			n = n * 3 + 1 # Beräkning för udda tal.
		
		# Addera ett till iteratorn i.
		i = i + 1

	return i


# Loopa igenom alla tal från 1 till 1000. Slutvärde måste vara 1001 för annars slutar den på 999 då den kollar om talet är indre än 1000 annars.
for n in range(1, 1001, 1):
	print("Antal itereringar för n =", n, "är:", CollatzCounter(n)) # Kör beräkningarna med CollatzCounter() för varje nummer på n.


# Definiera variabeln maxiter som håller max antal ierationer och maxnum som håller i talet som ger det nummret av itterationer.
maxiter = 0
maxnum = 0

# Undersök alla tal från 1 till 1000000 för att se vilken som har störst antal ittereringar.
for t in range(1, 1000001,1):
	i = CollatzCounter(t)
	
	if i > maxiter:
		maxiter = i
		maxnum = t
		
# Skriv ut talet som har flest med flest antal ittereringar.
print("Störst antal ittereringar får vi då n =", maxnum, "och antalet ittereringar är:", maxiter) # Längsta serien får vi på 524 itereringar då n = 837799
