#include <cstdio> // scanf e printf
#include <algorithm> // sort
#include <cstring> // strcmp

// defino os limites de n e do tamanho da string
#define MAXN 100100 
#define MAXL 30

using namespace std; // algorithm

int n, aluno[MAXN]; // declaro os inteiros que vou usar

double nota[MAXN]; // declaro o vetor de double, nota

char nome[MAXN][MAXL]; // declaro o vetor de strings, nome

bool compara(int x, int y){ // declaro a bool compara, que recebe dois inteiros
	
	if(nota[x]>nota[y]) return true; // se a nota do primeiro for maior estão em ordem
	
	if(nota[y]>nota[x]) return false; // se a nota do segundo for maior, não estão em ordem
	
	// se o programa chegar nessa linha, então as notas são iguais, então olho para os nomes
	
	if(strcmp(nome[x], nome[y])<0) return true; // se o nome do prieiro vier antes, estão em ordem
	
	//se o programa chegar nessa linha, então o nome do primeiro não vem antes
	
	return false; // então eles não estão em ordem
}

int main(){
	
	scanf("%d", &n); // leio o valor de n
	
	for(int i=1; i<=n; i++) scanf(" %s %lf", nome[i], &nota[i]); // leios os nomes e notas dos alunos
	
	for(int i=1; i<=n; i++) aluno[i]=i; // faço o vetor aluno guardar os números de 1 a n
	
	sort(aluno+1, aluno+n+1, compara); // e o ordeno segundo a função compara
	
	// depois imprimo os nomes dos alunos salvos em aluno
	for(int i=1; i<=n; i++) printf("%s\n", nome[ aluno[i] ]); // para cada i, imprimo o nome de aluno[i]
	
	return 0;
}