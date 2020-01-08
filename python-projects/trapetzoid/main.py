# Define the equation to integrate.
def f(x):
    return x * x

# Integral gives us the area under a graph between the start and end values. The accuracy is defined by telling the amount of trapzoids to divide it up into.
def integral(start, end, ammount):

    # h gives us the length of each divided part.
    h = (end - start) / ammount

    # s is our initial sum of half the start values.
    s = 0.5 * (f(start) + f(end))

    # Loop through the sums of the functions at each trapzoid.
    for i in range(1, ammount-1, 1):
        s += f(start + i * h)
    
    # Multiply the height and sum to get the area.
    return h * s

# Run the code outside of a main function weirdly enough.
print(integral(2, 4, 1000000))
