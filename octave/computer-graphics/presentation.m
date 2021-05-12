# The points for the corners of the cube.
p1 = [0; 0; 0]
p2 = [1; 0; 0]
p3 = [1; 1; 0]
p4 = [0; 1; 0]

# Put the points into a coordinate matrix.
M = [p1, p2, p3, p4]

# Translate by 1, 2 and -1 in x, y and z respectivly.
t = [1; 2; -1]
#M = M + t # Fake matrix addition using vector.

# Scale the cube by 2, 4 and 1 in x, y and z respectivly.
S = [2, 0, 0; 0, 4, 0; 0, 0, 1]
#M = S * M

# Rotate 45 degrees around the x-axis.
a = deg2rad(45)
R = [1, 0, 0; 0, cos(a), -sin(a); 0, sin(a), cos(a)]
#M = R * M

# Rotate 90 degrees around the y-axis.
b = deg2rad(90)
R = [cos(b), 0, sin(b); 0, 1, 0; -sin(b), 0, cos(b)]
#M = R * M

# Rotate 30 degrees around the z-axis.
c = deg2rad(30)
R = [cos(c), -sin(c), 0; sin(c), cos(c), 0; 0, 0, 1]
#M = R * M

# Shear the x-axis by y/2.
S = [1, 1/2, 0; 0, 1, 0; 0, 0, 1]
M = S * M

# Define plot settings.
hold on # Plot in same plot.
grid on # Turn on the grid for our plot.
axis ([0, 4, 0, 4], "square", "equal") # Define square axis between 0 and 4.

# Project the lines in two dimensions.
plot([ M(1, 1) M(1, 2)], [ M(2, 1) M(2, 2) ])
plot([ M(1, 2) M(1, 3)], [ M(2, 2) M(2, 3) ])
plot([ M(1, 3) M(1, 4)], [ M(2, 3) M(2, 4) ])
plot([ M(1, 4) M(1, 1)], [ M(2, 4) M(2, 1) ])
