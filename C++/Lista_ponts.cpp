#include <iostream>
#include<locale.h>
#include<stdlib.h>
using namespace std;

struct Aluno{
	string nome;
	int idade;
	string curso;
};

struct No{
	Aluno elem;
	No *prox;
};

typedef No *PtNo;

Aluno entradaDados(){
	Aluno dados;
	
	cout<<"Nome: ";
	cin>>dados.nome;
	cout<<endl;
	cout<<"Idade:";
	cin>>dados.idade;
	cout<<endl;
	cout<<"Curso: ";
	cin>>dados.curso;
	cout<<endl;
	
	return dados;
}


void inserirInicio(PtNo &p, Aluno dados){
	PtNo q;
	q = new No;
	q->elem=dados;
	q->prox=NULL;
	q->prox=p;
	p=q;
	
}

void inserirFinal(PtNo p, Aluno dados){
	while((p->prox!=NULL) && (p!=NULL)){
		p=p->prox;
	}
	PtNo q;
	q = new No;
	q->elem=dados;
	q->prox=NULL;
	p->prox=q;
	
	system("cls");
}

void excluirInicio(PtNo &p){
	if(p == NULL){
		cout<<"Lista vazia"<<endl;
	} else{
		PtNo q;
		q = p;
		p = p->prox;
		free(q);
	}
}

void excluirFinal(PtNo &p){
	PtNo q = p;
	PtNo aux;
	
	if(p->prox == NULL){
		free(p);
		p = NULL;
		cout<<"Elemento excluido"<<endl;
	} else {
		while (q->prox != NULL){
			aux = q;
			q = q->prox;
		}
		aux->prox = NULL;
		free(q);
		cout<<"Elemento excluido"<<endl;
	}
}


void exibir(PtNo p){
	
	if(p==NULL)
		cout<<"Lista vazia."<<endl;
	while(p!=NULL){
		cout<<"________________________________"<<endl;
		cout<<"Nome: "<<p->elem.nome<<endl;
		cout<<"Idade: "<<p->elem.idade<<endl;
		cout<<"Curso: "<<p->elem.curso<<endl;
		cout<<"________________________________"<<endl;
		p=p->prox;
	}
}

void Menu(){
	cout<<"\t"<<"MENU"<<endl;
	cout<<"______________________________________"<<endl;
	cout<<"[1] Inserir no inicio da lista"<<endl;
	cout<<"[2] Inserir no fim da lista"<<endl;
	cout<<"[3] Excluir no inicio da lista"<<endl;
	cout<<"[4] Excluir no final da lista"<<endl;
	cout<<"[5] Visualizar lista"<<endl;
	cout<<"[0] Sair"<<endl;
	cout<<"_______________________________________"<<endl;
}

void opcao(PtNo p){
	Aluno dados;
	int op=1;
	
	while(op != 0){
		Menu();
		cout<<"Digite uma opção: ";
		cin>>op;
		cout<<endl;
		system("cls");
	
		while((op <0) || (op>5)){
			opcao(p);
		}

		switch(op){
			case 1:
			{
				dados = entradaDados();
				inserirInicio(p,dados);
				system("cls");
				break;
			}
			case 2:
			{
				dados = entradaDados();
				inserirFinal(p,dados);
				system("cls");
				break;
			}
			case 3:
			{
				excluirInicio(p);
				break;
			}
			case 4:
			{
				excluirFinal(p);	
				break;
			}
			case 5:
			{
				exibir(p);
				break;	
			}
			case 0:
			{
				system("cls");
				break;
			}
			
		}
		
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	PtNo p = NULL;
	
	opcao(p);
}
