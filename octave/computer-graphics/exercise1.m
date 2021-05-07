# The defined points in R3:
p1 = [0; 0; 0]
p2 = [1; 0; 0]
p3 = [1; 1; 0]
p4 = [0; 1; 0]

# Matrix so that we can transform it later.
M = [p1, p2, p3, p4]

# Scale around x, y, z factors for exercise b.
x = 1.5 
y = 0.5
z = 1.0
T =  [x, 0, 0; 0, y, 0; 0, 0, z]
#M = T * M

# Translated by vector for exercise c.
u = [-2.0; -1.0; 3.0] 
#M = M + u # Fake matrix addition with vector.

# Transpose -30 degress around z-axis for exercise c.
a = -pi / 6
T =  [cos(a), -sin(a), 0; sin(a), cos(a), 0; 0, 0, 1]
M = T * M

# Define plot settings.
hold on # Plot in same plot.
grid on # Turn on the grid for our plot.

# Plot lines between points.
plot([ M(1, 1) M(1, 2)], [M(2, 1) M(2, 2) ])
plot([ M(1, 2) M(1, 3)], [M(2, 2) M(2, 3) ])
plot([ M(1, 3) M(1, 4)], [M(2, 3) M(2, 4) ])
plot([ M(1, 4) M(1, 1)], [M(2, 4) M(2, 1) ])
