#include <iostream>
#include <locale.h>
using namespace std ;
const int TamMax = 10;


struct tLista{ 
        int N;
        int Elem[TamMax];
};

void sair(){
	system("cls");
	exit(0);
}
void CriarList(tLista &tDado){
	int i ;
	cout<<"quantos itens você ira ultilizar ? \n";
	cin>>tDado.N;
	for(i=0;i<tDado.N;i++){
		cout<<("insira os valores da sua lista \n");
		cin>>tDado.Elem[i];
	}
	system("cls");
	cout<<"lista criada com valores inseridos \n";
}
void ExibLista (tLista &tDado ){
	int i ;
	cout<<"sua lista atual é de : \n";
for(i=0;i<tDado.N;i++){
		cout<<tDado.Elem[i]<<"  ";
	}
		cout<<endl;
}
void AcessarNaLista (tLista &tDado){
	int Posi;
	cout<<"Digite a posiçao que quer encontar na lista : \n ";
	cin>>Posi;
	
	if(Posi < 0 | Posi > tDado.N){
	cout<<"posiçao invalida !!";
	}else{
	cout<<"o elemento na posiçao "<<Posi<<" é de : "<<tDado.Elem[Posi-1]<<endl;
	}
}
void InserirNaK (tLista &tDado){
	int Posi;
	cout<<("digite a posiçao que deseja inserir o novo elemento \n ");
	cin>>Posi;
	if(Posi < 0 | Posi > tDado.N){
		cout<<"posiçao invalida !!";
	}else{
		int i;
		int NewValue;
		cout<<"digite o valor do novo numero que será inserido \n";
		cin>>NewValue;
		for(i=tDado.N; i>=Posi-1; i--){
				tDado.Elem[i+1] = tDado.Elem[i];
			}
			tDado.Elem[Posi-1]=NewValue;
			tDado.N++;
		}
	}
void AlterarElemento (tLista &tDado){
	int Posi;
	cout << "Qual posiçao deseja alterar : \n";
		cin >> Posi;
		if(Posi < 0 | Posi > tDado.N){
		cout<<"posiçao invalida !!";
	}else{
		int NewValue;
		cout << "O Valor Atual" << tDado.Elem[Posi-1] << endl;
		cout << "Esse valor será alterado para ?" << endl;
			cin >> NewValue;
		tDado.Elem[Posi-1] = NewValue;
		cout << "Valor Alterado com sucesso " << endl;
			
	}
}
void RemoverDaK (tLista &tDado){
	int Posi;
	cout << "Qual posiçao deseja remover : \n";
		cin >> Posi;
		if(Posi < 0 | Posi > tDado.N){
		cout<<"posiçao invalida !!";
	}else{
		int i;
		for(i=Posi-1; i<tDado.N-1; i++){
			tDado.Elem[i]=tDado.Elem[i+1];
		}
	tDado.N--;
	}
	}
void LocaleCont(tLista &tDado){
			int i;
			int Value;
			int retorno ;
			cout<<"qual valor deseja encontrar ? \n";
			cin>>Value;
		for(i=0; i<tDado.N; i++){
			if(tDado.Elem[i]==Value)
				retorno=i+1;
			else 
				retorno=-1;			
			}
			
			if(retorno==-1)
				cout <<"O Valor Não Foi Encontrado \n";
			else
				cout << "O Valor Foi Encontrado Na Posiçao " << retorno << endl;	

}
void opcao(tLista &tDado ,int op){
	switch(op){
		case 1:
		CriarList(tDado);	
		break;
		case 2:
		ExibLista(tDado);
		break;
		case 3:
		AcessarNaLista(tDado);
		break;
		case 4:
		InserirNaK(tDado);
		break;
		case 5:
		AlterarElemento(tDado);
		break;
		case 6:
		RemoverDaK(tDado);
		break;
		case 7:
		LocaleCont(tDado);
		break;
		case 8:
		sair();
		break;
		
	}
}

void menu (tLista &tDado, int op){
cout<<"\n";
cout<<"-----------------------------------------------------------------------\n";
cout<<"[1] criar lista \n";
cout<<"[2] ver lista \n";
cout<<"[3] Acessar uma posiçao na lista \n";
cout<<"[4] inserir um elemento na k-esima posiçao \n";
cout<<"[5] alterar um elemento inserido \n";
cout<<"[6] remover um elemento da k-esima posiçao \n";
cout<<"[7] localizar um elemento com determinado conteudo \n";
cout<<"[8] sair da lista \n";
cout<<"-----------------------------------------------------------------------\n";
cin>>op;

while(op ==0 ||op>8||op<0){
	cout<<"erro , opçao invalida \n";
	cin>>op;
}
system("cls");
opcao(tDado ,op);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
//	int i;
	tLista tDado;
	int op;
	menu(tDado,op);
	while(op!=8)
	 menu(tDado,op);
	
}

