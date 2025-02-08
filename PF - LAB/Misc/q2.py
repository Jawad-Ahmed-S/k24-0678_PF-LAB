print("calculate Coloumb's Force")
q1=float(input("Enter the charge 1 (in Coloumbs) : "))
q2=float(input("Enter the charge 2 (in Coloumbs) : "))
r=float(input("Enter the sepration(r) (in meters) : "))
Force = ((9*(10**9))*(q1)*(q2))/r**2
print(f"{Force} N")
