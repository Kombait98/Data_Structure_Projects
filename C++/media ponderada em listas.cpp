#include <iostream>
#include<locale.h>
#include<stdlib.h>
#define N 2
using namespace std;
typedef struct dados{
	string nome;
	float nota1;
	float nota2;
	int pesos[N];
	float geral;
	dados *prox;
};

typedef dados *PtDis;

void inserir_inicio(PtDis &p, string nome, float nota1 , float nota2){
	PtDis q= new dados;
	q->nome= nome;
	q->nota1= nota1;
	q->nota2= nota2;
	q->prox= p;
	p=q;	
}

void mostrar_rec(PtDis p){
	if (p!=NULL){
		cout<<"Aluno: "<<p->nome<<endl;
		cout<<"Media Final: "<<p->geral<<endl<<endl;
		mostrar_rec(p->prox);
	}
}

void media_pond(float nota1, float nota2){
	PtDis q= new dados;
	q->geral = (q->nota1 * 2  +  q->nota2 * 3)/5;
}

int main(){
	PtDis q= new dados;
	PtDis p=NULL;
	string nome;
	float nota1, nota2;
	int peso;
	cout<<"NOME: ";
	cin>>nome;		
	cout<<"PORTUGUES: ";
	cin>>nota1;
	cout<<"MATEMATICA: ";
	cin>>nota2;
	inserir_inicio(p, nome, nota1 ,nota2);
	media_pond(q->nota1, q->nota2);
	mostrar_rec(p);
}

