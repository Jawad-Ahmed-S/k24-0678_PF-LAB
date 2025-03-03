#include<iostream>

using namespace std;
class ValidateString{
    string str;
    public:
    ValidateString(string Str){
        for(int i=0;i<Str.length();i++){
            if(tolower(Str[i])<'a' || tolower(Str[i])>'z' ){
                cout<<"Validation Failed"<<endl;
                exit(1);
            }
    }
    cout<<"Validation Passed"<<endl;
}
};
int main(){
    ValidateString("hsglkjhfgjdgdhh789fSGDHG");
}