#include <cstdio> // scanf e printf

#define MAXN 100100 // defino o limite de n

typedef long long int lli; // defino o tipo lli como long long int

int n, vetor[MAXN], aux[MAXN]; // declaro as variáveis e vetores que vamos usar

lli merge_sort(int ini, int fim){ // declaro a função merge_sort, que agora retorna um int
	
	if(ini==fim) return 0; // se o intervalo tiver um único elemento, ele não tem inversões
	
	// caso o contrário, declaro a variável invers, que começa com a soma das inversões das duas metades
	lli invers=merge_sort(ini, (ini+fim)/2) + merge_sort((ini+fim)/2+1, fim); // observe que chamei a recursão e ordenei as metades
	
	int tam=0, j=(ini+fim)/2+1; // declaro tam e j, como feito no código anterior do merge_sort
	
	for(int i=ini; i<=(ini+fim)/2; i++){ // para cada posição da metade da esquerda
		
		while(j<=fim && vetor[j]<vetor[i]){ // procuro os elementos da metade da direita menores que i
			
			// os adiciono ao vetor aux
			aux[tam]=vetor[j];
			tam++;
			j++; // passo para o próximo elemento
			invers+=(ini+fim)/2-i+1; // e adicino o número de inversões em metades diferentes com o elemento j
		}
		
		// adiciono o elemento i
		aux[tam]=vetor[i];
		tam++;
	}
	
	// adiciono o resto dos elementosda segunda metade
	while(j<=fim){
		
		aux[tam]=vetor[j];
		tam++;
		j++;
	}
	
	for(int i=ini; i<=fim; i++) vetor[i]=aux[i-ini]; // e troco os valores do vetor original pelos ordenados
	
	return invers; // retorno o número de inversões calculado
}

int main(){

	scanf("%d", &n); // leio o valor de n
	
	for(int i=1; i<=n; i++) scanf("%d", &vetor[i]); // leio os valores do vetor
	
	printf("%lld\n", merge_sort(1, n)); // imprimo a quantidade de inversões do vetor
	
	return 0;
}