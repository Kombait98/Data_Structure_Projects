#include <iostream>
using namespace std;
#define Max 5
struct Lista{
	int N;
	int Elementos[Max];
};

void CASOI(){
	cout << "Tamanho Máximo Atingido" << endl;
	exit(0);
}

void CASOII(){
	cout << "Lista Vazia!" << endl;
	exit(0);
}

void FimDoPrograma(){
	system("clear");
	exit(0);
}

void CriarLista(Lista &Dados){
	int i;
	cout << "Quantas Posições Você Utilizará? (1 - " << Max << ")" << endl;
		cin >> Dados.N;
	if(Dados.N>Max){
		cout << "Tamanho Inválido" << endl;
	}
	else{
		for(i=0; i<Dados.N; i++){
		cout << "Preencha A Posição " << i+1 << endl;
		cout << ">> ";
			cin >> Dados.Elementos[i];
		}
		system("clear");
	}
	while(Dados.N>Max){
		CriarLista(Dados);
	}
	
}

void VerLista(Lista &Dados){
	int i;
	cout << "Sua Lista é:" << endl << endl;
	for(i=0; i<Dados.N; i++){
	cout << Dados.Elementos[i] << " ";
	}
}

void AcessarPosicaoNaLista(Lista &Dados){
	int P;
	cout << "Qual a Posição Deseja Acessar? (1 - " << Dados.N << ")" << endl;
	cout << ">> ";
		cin >> P;
	if(P < 0 | P> Dados.N){
		cout << "O Elemento Não Existe!" << endl;
		cout << "Escolha Um Uma Posição de 1 a " << Dados.N << "!" << endl;
		while(P=0 | P>Dados.N | P<0){
			AcessarPosicaoNaLista(Dados);
		}
	}
	else{
		cout << "O Elemento Na Posição " << P << " é " << Dados.Elementos[P-1] << endl;
	} 
}

void InserirUmElementoNaKesimaPosicao(Lista &Dados){
	if(Dados.N == Max){
		CASOI();
	}
	else{
		int P;
		cout << "Qual a Posição Na Qual Deseja Inserir Um Elemento? (1 - " << Dados.N << ")" << endl;
		cout << ">> ";
			cin >> P;
		if(P<0 | P>Dados.N){
			cout << "Posição Não Existe!" << endl;
			cout <<	"Escolha Uma Posição de 1 a " << Dados.N << "!" << endl;
			while(P=0 | P>Dados.N | P<0){
				InserirUmElementoNaKesimaPosicao(Dados);
			}
		}
		else{
			int i;
			int Val;
			cout << "Qual O valor Do Novo Elemento?" << endl;
			cout << ">> ";
				cin >> Val;
			for(i=Dados.N; i>=P-1; i--){
				Dados.Elementos[i+1] = Dados.Elementos[i];
			}
			Dados.Elementos[P-1]=Val;
			Dados.N++;
		}
	}
}

void AlterarUmElementoInserido(Lista &Dados){	
	int P;
	cout << "Qual a Posição? (1 - " << Dados.N << ")" << endl;
	cout << ">> ";
		cin >> P;
	if(P<0 | P>Dados.N){
		cout << "O Elemento Não Existe!" << endl;
		cout << "Escolha Um Uma Posição de 1 a " << Dados.N << "!" << endl;
		while(P=0 | P>Dados.N | P<0){
		AlterarUmElementoInserido(Dados);
		}
	}
	else{
		int Val;
		cout << "O Valor Atual é " << Dados.Elementos[P-1] << endl;
		cout << "Para Qual Valor Será Alterado o Valor? " << endl;
		cout << ">> ";
			cin >> Val;
		Dados.Elementos[P-1] = Val;
		cout << "Valor Alterado!" << endl;
		cout << "Novo Valor é " << Dados.Elementos[P-1] << endl;
	}
}

void RemoverUmElementoDaKesimaPosicao(Lista &Dados){
	int P;
	cout << "Qual a Posição? (1 - " << Dados.N << ")" << endl;
	cout << ">> ";
		cin >> P;
	if(P<0 | P>Dados.N){
		cout << "O Elemento Não Existe!" << endl;
		cout << "Escolha Um Uma Posição de 1 a " << Dados.N << "!" << endl;
		while(P=0 | P>Dados.N | P<0){
		RemoverUmElementoDaKesimaPosicao(Dados);
		}
	}
	else{
		int i;
		for(i=P; i<Dados.N-1; i++){
			Dados.Elementos[i]=Dados.Elementos[i+1];
		}
		Dados.N--;
	}
}

void LocalizarUmElementoComDeterminadoConteudo(Lista &Dados){
	if(Dados.N==0){
		CASOII();
	}
	else{
		int i;
		int Val;
		cout << "Qual O Valor a Ser Localizado?" << endl;
		cout << ">> ";
			cin >> Val;
		for(i=0; i<Dados.N; i++){
			if(Dados.Elementos[i]==Val){
				cout << "O Valor Foi Encontrado Na(s) Posição(ões) " << i+1 << endl;
			}
			else if(Dados.Elementos[i]!=Val){
				cout << "O Valor Procurado Não Existe Na Lista!";
				
			}
		}
	}
}

void Opcao(Lista &Dados, int Escolha){
	switch(Escolha){
		case 1: 
		system("clear");
		CriarLista(Dados);
		cout << endl << endl << endl;
		break;
		case 2:
		system("clear");
		VerLista(Dados);
		cout << endl << endl << endl;
		break;
		case 3:
		system("clear");
		AcessarPosicaoNaLista(Dados);
		cout << endl << endl << endl;
		break;
		case 4:
		system("clear");
		InserirUmElementoNaKesimaPosicao(Dados);
		cout << endl << endl << endl;
		break;
		case 5:
		system("clear");
		AlterarUmElementoInserido(Dados);
		cout << endl << endl << endl;
		break;
		case 6:
		system("clear");
		RemoverUmElementoDaKesimaPosicao(Dados);
		cout << endl << endl << endl;
		break;
		case 7:
		system("clear");
		LocalizarUmElementoComDeterminadoConteudo(Dados);
		cout << endl << endl << endl;
		break;
		case 8:
		system("clear");
		FimDoPrograma();
		break;	
		}
}

void Menu(Lista &Dados, int Escolha){
	cout << "Bem Vindo!" << endl;
	cout << "Escolha Um Opção Abaixo:" << endl;
	cout << "	1 | Criar Lista;" << endl;
	cout << "	2 | Ver Lista;" << endl;	
	cout << "	3 | Acessar Uma Posição Na Lista;" << endl;
	cout << "	4 | Inserir Um Elemento Na K-ésima Posição;" << endl;
	cout << "	5 | Alterar Um Elemento Inserido;" << endl;
	cout << "	6 | Remover Um Elemento Da K-ésima Posição;" << endl;
	cout << "	7 | localizar Um Elemento Com Determinado Conteúdo;" << endl;
	cout << "	8 | Sair;" << endl;
	cout << ">> ";
		cin >> Escolha;
	while(Escolha == 0 | Escolha > 8 | Escolha < 0){
		cout << "ERRO!" << endl;
		cout << "OPÇÃO INVALIDA!" << endl;
		cout << ">> ";
			cin >> Escolha;
	}
	system("clear");
	Opcao(Dados, Escolha);
}

int main(){
	int i;
	Lista Dados;
	int Escolha;
	Escolha = 0;
	system("clear"); 
	Menu(Dados, Escolha);
	while(Escolha != 8){
		Menu(Dados, Escolha);
	}
}
