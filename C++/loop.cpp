#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std ;

void loop (float l){
for( l;l<999999999999999;l++){
cout<<l<<"\t";
Sleep(100); //1000 = 1 segundo 
}
}

int main(){
setlocale(LC_ALL, "Portuguese");
float n;
cout<<"digite o numero que quer come�ar : \n";
cin>>n;
cout<<"seu numero foi anotado com sucesso .\n";
cout<<"vamos come�ar ? \n";
system("pause");
loop(n);
//while (n=999);
//n=n+1;
}

