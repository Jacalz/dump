# The defined points in R3:
p1 = [0; 0; 0]
p2 = [1; 0; 0]
p3 = [1; 1; 0]
p4 = [0; 1; 0]

# Matrix so that we can transform it later.
M = [p1, p2, p3, p4]

# Shear the matrix to produce view 10.
T =  [1, 0.5, 0; 0, 1, 0; 0, 0, 1]
#M = T * M

# Shear the matrix to produce view 11.
T =  [1, 0, 0; 0.6, 1, 0; 0, 0, 1]
M = T * M

# Define plot settings.
hold on # Plot in same plot.
grid on # Turn on the grid for our plot.

# Plot lines between points.
plot([ M(1, 1) M(1, 2)], [M(2, 1) M(2, 2) ])
plot([ M(1, 2) M(1, 3)], [M(2, 2) M(2, 3) ])
plot([ M(1, 3) M(1, 4)], [M(2, 3) M(2, 4) ])
plot([ M(1, 1) M(1, 4)], [M(2, 2) M(2, 4) ])
