//merge

#include <iostream> // scanf e printf

#define MAX 100100 // defino que MAX é 100100

int tam1, tam2, vetor1[MAX], vetor2[MAX], vetorzao[MAX]; // declaro as variáveis que vou precisar

void merge(){ // declaro a void merge
	
	int tam=0; // declaro a int tam, o tamanho atual de vetorzao
	
	int j=1; // declaro j, a posição de vetor2 que vou olhar
	
	for(int i=1; i<=tam1; i++){ // para cada posição de vetor1
		
		// enquanto houver elemento em vetor2 e seu primeiro não usado for menor que o de vetor1
		while(j<=tam2 && vetor2[j]<vetor1[i]){
			
			tam++; // aumento o tamanho de vetorzao
	
			vetorzao[tam]=vetor2[j]; // coloco nele o elemento vetor2[j]
			
			j++; // e vou para o próximo elemento de vetor2
		}
		
		//após inserir os elementos de vetor2 que são menores que o vetor1[i]
		
		tam++; // aumento o tamanho de vetorzao
		
		vetorzao[tam]=vetor1[i]; // e adiciono o elemento vetor1[i]
	}
	
	while(j<=tam2){ // enquanto ainda sobrarem elementos em vetor2
		
		tam++; // aumento o tamanho de vetorzao
		
		vetorzao[tam]=vetor2[j]; // coloco nele o elemento vetor2[j]
		
		j++; // e vou para o próximo elemento de vetor2
	}
}

int main(){
	
	scanf("%d", &tam1); // leio o tamanho do vetor1
	
	for(int i=1; i<=tam1; i++) scanf("%d", &vetor1[i]); // leio os elementos de vetor1
	
	scanf("%d", &tam2); // leio o tamanho de vetor2
	
	for(int i=1; i<=tam2; i++) scanf("%d", &vetor2[i]); // leio os elementos de vetor2
	
	merge(); // chamo a função merge
	
	for(int i=1; i<=tam1+tam2; i++) printf("%d ", vetorzao[i]); // imprimo os valores de vetorzao
	
	printf("\n"); // imprimo a quebra de linha no fim da saída
	
	return 0;
}
