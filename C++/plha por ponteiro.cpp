#include <iostream>
#include <stdlib.h>
using namespace std;

struct No{
	int dado;
	No *prox;
};
typedef No *pilha;

void sair(){
	system("cls");
	exit(0);
}
void exibir (pilha &p){
	pilha q=p;
	while(q!=NULL){
		cout<<q->dado<<endl;
		q=q->prox;
	}
}
void Empilhar (pilha &p){
	int value;
	cout<<"defina o valor que voce vai querer inserir : \n";
	cin>>value;
	pilha q;
	q= new No;
	q->dado=value;
	q->prox=p;
	p=q;
}
void Desempilha(pilha &p){
	pilha q=p;
	if(p== NULL)
	cout<<"pilha vazia \n";
	else{
		p=p->prox;
		free(q);
		cout<<"primeiro elemento removido da pilha. \n";
	}
}
void TopElem (pilha p){
	if(p==NULL){
		cout<<"pilha vazia \n";
	}else{
		cout<<p->dado<<" é o seu elemento do topo. \n";
	}
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
			Desempilha(p);
		break;
		case 4:
			TopElem(p);
		break;
		case 5:
		sair();
		break;
		
	}
}
void menu (pilha &p, int op){
cout<<"\n";
cout<<"-----------------------------------------------------------------------\n";
cout<<"[1] Exibir pilha\n";
cout<<"[2] Empilhar a pilha \n";
cout<<"[3] Desempilhar a pilha \n";
cout<<"[4] Acessar o primeiro elemento  \n";
cout<<"[5] Sair \n";
cout<<"-----------------------------------------------------------------------\n";
cin>>op;

while(op ==0 ||op>5||op<0){
	cout<<"erro , opçao invalida \n";
	cin>>op;
}
system("cls");
opcao(p ,op);
}

int main (){
setlocale(LC_ALL, "Portuguese");
pilha p,q;
p=NULL;
int op;
menu(p,op);
while(op!=5)
menu(p,op);
	
	
}
