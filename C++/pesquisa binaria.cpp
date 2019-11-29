#include<iostream>
using namespace std;
const int n = 10;
	int valproc (int *vet ,int vl){
		int baixo=0;
		int alto =n-1;
		int meio;
		while (baixo<=alto){
			meio=(baixo+alto)/2;
			if(vl<vet[meio])
			alto=meio-1;
			if(vl>vet[meio])
			baixo=meio+1;
			else
			return meio;
		}
	return -1;
	}
	
	decrementar(int *vet,int val){
		for (int i =0 ;i<n;i++){
		if(val==i)
		vet[i]=vet[i]-1;
		}
	}
	
	
int main(){
	int vet [n];
	int vl ;
	int val=0;
	for(int i;i<n;i++){
		cout<<"digite seus valores da "<<i+1<<" de 10 posicoes em ordem crescente : ";
		cin>>vet[i];
		}
	cout<<"seu vetor atualmente e :";
	for(int i =0;i<n;i++){
		cout<<"\t"<<vet[i];
		}
		cout<<endl;
	cout<<"agora digite o seu valor procurado : ";
	cin>>vl;
	val=valproc(vet,vl);
	if(val==-1){
		cout<<"seu valor nao existe no vetor .";
	}else{
	cout<<"o valor foi encontrado no indice : "<<val<<endl;
	decrementar(vet,vl);
	cout<<"atualmente , seu vetor e :";
	for(int i =0;i<n;i++){
		cout<<"\t"<<vet[i];
		}
	}
	}
