#include<iostream>
using namespace std;

const int TamMax= 1000;
 struct pilha {
	int top;
	int Elem[TamMax];
	
};
pilha p;
void iniciaPilha (pilha &p) {
     p.top = 0 ;
}
void sair(){
	system("cls");
	exit(0);
}
bool veryf (pilha &p){
if (p.top == -1) {
     return true;
}else
	 return false;
}

void Empilhar (pilha &p){
    int value;
	cout<<"defina o valor que voce vai querer inserir : \n";
	cin>>value;
	if(veryf(p)==false){
	p.Elem[p.top] = value;
    p.top++;
    cout<<value<<" inserido";
	}else{
	cout<<"sua pilha esta cheia";
	}
  }
  
void desempilha(pilha &p){
   if (p.top == -1) 
      cout<<"sua pilha esta vazia \n";
   else { 
           p.top--;
      cout<<"primeiro elemento removido \n";
  }
}
void exibir (pilha &p){
	cout<<"sua pilha é : \n";
	for(int i = p.top-1 ;i>=0;i--){
		cout<<p.Elem[i]<<endl;
	}
}
int ElementoTop(pilha p){
	if (veryf(p)==false)
     cout<< p.Elem[p.top -1]<<" é o seu elemento do topo .\n";
   else
     cout<<"sua pilha esta vazia : \n";
}

 
void opcao(pilha &p ,int op){
	switch(op){
		case 1:
			exibir(p);
		break;
		case 2:
			Empilhar(p);
		break;
		case 3:
			desempilha(p);
		break;
		case 4:
			ElementoTop(p);
		break;
		case 5:
		sair();
		break;
		
	}
}
void menu (pilha &p, int op){
cout<<"\n";
cout<<"-----------------------------------------------------------------------\n";
cout<<"[1] exibir pilha\n";
cout<<"[2] empilhar a pilha \n";
cout<<"[3] desempilhar a pilha \n";
cout<<"[4] acessar o primeiro elemento  \n";
cout<<"[5] sair \n";
cout<<"-----------------------------------------------------------------------\n";
cin>>op;
//	exibir , acessar, empilhar , desempilhar

while(op ==0 ||op>5||op<0){
	cout<<"erro , opçao invalida \n";
	cin>>op;
}
system("cls");
opcao(p ,op);
}
 int main(){
 	setlocale(LC_ALL, "Portuguese");
	pilha p;
	p.top=0;
	int op;
	menu(p,op);
	while(op!=5)
	 menu(p,op);
	
}
