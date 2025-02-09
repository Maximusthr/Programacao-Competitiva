// quick sort (função da biblioteca algorithm)

#include <cstdio> // scanf e printf
#include <algorithm> // sort

#define MAXN 100100 // defino o limite de n

using namespace std; // algorithm

int n, capital[MAXN], empr[MAXN]; // declaro a variáveis que vou usar

bool compara(int x, int y){ // declaro a função bool compara, que recebe dois inteiros
	
	// se o capital do primeiro for maior que do segundo, estão na ordem certa
	if(capital[x]>capital[y]) return true;
	
	//se o programa chegar aqui, então a função não retornou na linha anterior
	return false; // então o capital de x não é maior, logo x e y não estão em ordem
}

int main(){
	
	scanf("%d", &n); // leio o valor de n
	
	for(int i=1; i<=n; i++) scanf("%d", &capital[i]); // leio o capital de cada empres
	
	for(int i=1; i<=n; i++) empr[i]=i; // faço um vetor com o número de cada empresa
	
	sort(empr+1, empr+n+1, compara); // ordeno o vetor pelo capital de cada empresa
	
	for(int i=1; i<=n; i++) printf("%d ", empr[i]); // imprimo os valores no vetor
	
	printf("\n"); // e imprimo a quebra de linha no fim da saída
	
	return 0;
}