#include <iostream>
using namespace std;
char verifica(int idade){
	if(idade>=18){
		cout<<("Maior de idade");
	}else{
		cout<<("Menor de idade");
	}
}	
void verificaIdade (int anoNasc){
	int idade;
	if (anoNasc<1900 || anoNasc>2024){
		cout<<"idade invalida.";			
	}else{
		idade = 2023-anoNasc; 
		verifica(idade);
	}	
}
void leitura (){
	int anoNasc;
	cout<<("digite seu ano de nascimento : ");
	cin>>anoNasc;
	verificaIdade(anoNasc);
}
int main (){
	leitura();
}
