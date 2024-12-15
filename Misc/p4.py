import math
print("Projectile Motion")
Vi=float(input("Enter initial velocity"))
x=float(input("Enter launch angle of the projectile"))

H=((Vi**2)*(math.sin(math.radians(x)))**2)/(2*9.8);

R=((Vi**2)*(math.sin(math.radians(2*x))))/9.8;

T=(2*(Vi**2)*(math.sin(math.radians(x))))/9.8;


print("Maximum Height reached : {H}m")
print("Range of projectile : {R}m")
print("Total time of flight : {T}s")