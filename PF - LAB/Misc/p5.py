print("Checking if a device is Ohmic or not")
T1V=float(input("Enter Voltage for Test case 1: "));
T1C=float(input("Enter Current for Test case 1: "));
T2V=float(input("Enter Voltage for Test case 2: "));
T2C=float(input("Enter Current for Test case 2: "));
T3V=float(input("Enter Voltage for Test case 3: "));
T3C=float(input("Enter Current for Test case 3: "));

R1=T1V/T1C;
R2=T2V/T2C;
R3=T3V/T3C;

if R1==R2 and R1==R3 :
    print("It is an Ohmic Device")
else :
    print("It is a Non-Ohmic Device")