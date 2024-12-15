import math
print("Projectile Motion")
Vi=float(input("Enter initial velocity (m/s) "))
x=float(input("Enter launch angle of the projectile (degree) "))

H=((Vi**2)*(math.sin(math.radians(x)))**2)/(2*9.8);

R=((Vi**2)*(math.sin(math.radians(2*x))))/9.8;

T=(2*(Vi**2)*(math.sin(math.radians(x))))/9.8;


print(f"Maximum Height reached : {H}m")
print(f"Range of projectile : {R}m")
print(f"Total time of flight : {T}s")
