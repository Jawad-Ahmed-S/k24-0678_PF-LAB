print("Calculate equivalent capacitance")
c1=float(input("Enter the capacitance 1(in Farad) : "))
c2=float(input("Enter the capacitance 2(in Farad) : "))
c3=float(input("Enter the capacitance 3(in Farad) : "))
type = input("Circuit Type : ")
if type =="series" :
    Ceq=1/(1/c1 + 1/c2 +1/c3)

elif type == "parallel":
    Ceq=(c1 + c2 +c3)

else:
    print("invalid type")
    Ceq=None

if Ceq is not None:
    print(f"Ceq = {Ceq}F")
