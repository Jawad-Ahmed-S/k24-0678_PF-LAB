#include<stdio.h>
struct Student{
	int Roll;
	char name[10];
	struct Marks{
		int Maths;
		int Science;
		int English;
	};
};	
int main(){
	struct Marks M;
	struct Student S[2]{
		{123,"ABC",M{45,56,78},
		{123,"ABC",M{45,56,78},
		}
	};
}