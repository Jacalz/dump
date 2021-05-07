# The defined points in R3:
p1 = [1.000; -0.800; 0.000]
p2 = [0.500; -0.800; -0.866]
p3 = [-0.500; -0.800; -0.866]
p4 = [-1.000; -0.800; 0.000]
p5 = [-0.500; -0.800; 0.866]
p6 = [0.500; -0.800; 0.866]
p7 = [0.840; -0.400; 0.000]
p8 = [0.315; 0.125; -0.546]
p9 = [-0.210; 0.650; -0.364]
p10 = [-0.360; 0.800; 0.000]
p11 = [-0.210; 0.650; 0.364]
p12 = [0.315; 0.125; 0.546]

# Matrix so that we can transform it later.
M = [p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12]

# Scale by a factor of 0.3 in the x-direction, and 0.5 in the y-direction.
x = 0.3
y = 0.5
S = [x, 0, 0; 0, y, 0; 0, 0, 1]
M = S * M

# Rotate 45 degrees about the x-axis.
a = deg2rad(45)
T = [1, 0, 0; 0, cos(a), -sin(a); 0, sin(a), cos(a)]
M = T * M

# Translate 1 unit in the x-direction.
u = [1; 0; 0]
M = M + u # Fake matrix addition with vector.

# Rotate 35 degrees about the y-axis.
a = deg2rad(35)
T = [cos(a), 0, sin(a); 0, 1, 0; -sin(a), 0, cos(a)]
M = T * M

# Rotate -45 degrees about the z-axis.
a = deg2rad(-45)
T = [cos(a), -sin(a), 0; sin(a), cos(a), 0; 0, 0, 1]
M = T * M

# Translate 1 unit in the z-direction.
u = [0; 0; 1]
M = M + u # Fake matrix addition with vector.

# Scale by a factor of 2in the x-direction.
x = 2
S = [x, 0, 0; 0, 1, 0; 0, 0, 1]
M = S * M

# Define plot settings.
hold on # Plot in same plot.
grid on # Turn on the grid for our plot.

# Plot lines between points.
plot([ M(1, 1) M(1, 2)], [M(2, 1) M(2, 2) ])
plot([ M(1, 2) M(1, 3)], [M(2, 2) M(2, 3) ])
plot([ M(1, 3) M(1, 4)], [M(2, 3) M(2, 4) ])
plot([ M(1, 4) M(1, 5)], [M(2, 4) M(2, 5) ])
plot([ M(1, 5) M(1, 6)], [M(2, 5) M(2, 6) ])
plot([ M(1, 6) M(1, 1)], [M(2, 6) M(2, 1) ])
plot([ M(1, 7) M(1, 8)], [M(2, 7) M(2, 8) ])
plot([ M(1, 8) M(1, 9)], [M(2, 8) M(2, 9) ])
plot([ M(1, 9) M(1, 10)], [M(2, 9) M(2, 10) ])
plot([ M(1, 10) M(1, 11)], [M(2, 10) M(2, 11) ])
plot([ M(1, 11) M(1, 12)], [M(2, 11) M(2, 12) ])
plot([ M(1, 12) M(1, 7)], [M(2, 12) M(2, 7) ])
plot([ M(1, 1) M(1, 7)], [M(2, 1) M(2, 7) ])
plot([ M(1, 2) M(1, 8)], [M(2, 2) M(2, 8) ])
plot([ M(1, 3) M(1, 9)], [M(2, 3) M(2, 9) ])
plot([ M(1, 4) M(1, 10)], [M(2, 4) M(2, 10) ])
plot([ M(1, 5) M(1, 11)], [M(2, 5) M(2, 11) ])
plot([ M(1, 6) M(1, 12)], [M(2, 6) M(2, 12) ])
