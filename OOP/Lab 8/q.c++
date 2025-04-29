class MyClass{
    int value;
    friend void func ();
};

void func(){
     
     cout<<"Value of A: "<<value;
}

