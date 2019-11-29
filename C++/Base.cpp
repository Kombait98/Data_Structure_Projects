// code base in c++

#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std ;


void sair(){
	system("cls");
	exit(0);
}
void opcao(int op){
	switch(op){

		case 0:
		sair();
		break;

	}
}

void menu (int op){
cout<<"\n";
cout<<"-----------------------------------------------------------------------\n";
cout<<"base base base \n";
cout<<"[0] sair da lista \n";
cout<<"-----------------------------------------------------------------------\n";
cin>>op;

while(op ==-1 ||op>8||op<-1){
	cout<<"erro , opçao invalida \n";
	cin>>op;
}
system("cls");
opcao(op);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	menu(op);
	while(op!=8)
	 menu(op);

}


//using menu mode :)
