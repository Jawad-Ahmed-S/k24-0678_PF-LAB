#include<iostream>
#include<fstream>
using namespace std;
int main() {
    string searchWord="",replaceWord="";
 cout<<"enter a word to replace";
 cin>>searchWord;
 cout<<"enter a word to be replaced with";
 cin>>replaceWord;

 string CompleteData ="";

    fstream file;
    file.open("data.txt",ios::in|ios::out);
    string str="";
        if(searchWord.length()==replaceWord.length()){
        while(getline(file,str)){
        int pos=str.find(searchWord);
            while(pos != string::npos){
        str.replace(pos,searchWord.length(),replaceWord);
        pos=str.find(searchWord,pos+searchWord.length());
            }

        cout<<str<<" "<<endl;
        CompleteData+=str;
        }
        }
        else{
            cout<<"This replacement will cause errors\n";
        }

    file.close();
    file.open("data.txt",ios::out);
    file<<CompleteData;
    file.close();
    return 0;
}