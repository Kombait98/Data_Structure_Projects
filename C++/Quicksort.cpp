#include<iostream>
using namespace std;
void Quick(int vetor[10], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}

int main(){
   
   int vetor[10] = {7, 9, 4, 3, 6, 1, 18, 2, 10, 5};
   
   int i;   
   cout<<"Vetor desordenado:\n";
   for(i = 0; i < 10; i++){
      cout<<" "<< vetor[i];
   }
	cout<<"\n";   
   
   Quick(vetor, 0, 9);
   
   cout<<"Vetor ordenado:\n";
   for(i = 0; i < 10; i++){
     cout<<" "<< vetor[i];
   }
	cout<<"\n";  
}

