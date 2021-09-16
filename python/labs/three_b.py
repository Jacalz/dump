def factorial(n):
    return fact_above(n, 1)

def fact_above(n, mini):
    if n == mini:
        return 1

    return n * fact_above(n - 1, mini)

def choose(n, k):
    if n - k > k:
        return fact_above(n, n - k) // factorial(k)

    return fact_above(n, k) // factorial(n - k)

if __name__ == "__main__":
    print(choose(5, 3))
    print(choose(1000, 1))
    print(choose(52, 5))
    print(choose(1000, 4))
    print(choose(1000, 800))
    print(choose(1000, 999))
