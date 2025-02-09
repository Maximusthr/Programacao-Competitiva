#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// // declaração
// int main(){
//     pair<int, int> p1;
//     pair<int, string> p2;
// }

// int main(){
//     vector<pair<int, int>> exemplo = {{10, 1}, {1, 3}, {1, 2}};
//     cout << exemplo[1].first;
// }

// int main(){
//     vector<pair<pair<int, string>, int>> ex;

//     ex.push_back({{1,"ANA"},10}); // Insiro o par ((1,ANA),10) no vetor
//     ex.push_back({{2,"BRUNO"},4}); // Insiro o par ((2,BRUNO),4) no vetor
//     ex.push_back({{3,"CAIO"},7}); // Insiro o par ((3,CAIO),7) no vetor
  
//     for(int i=0; i<(int)ex.size(); i++) // Percorro o vetor do ínicio ao fim
//     {
//         printf("Numero: %d, Nome: %s, Nota: %d\n", ex[i].first.first, ex[i].first.second.c_str(), ex[i].second);
//         // Imprimo o primeiro elemento do primeiro elemento do pair (número de chamada) = v[i].first.first
//         // Imprimo o segundo elemento do primeiro elemento do pair (nome do aluno) = v[i].first.second
//         // Imprimo o único elemento do segundo elemento do pair = v[i].second
//     }
// }

// int main(){
//     pair <int, string> A = {10, "Thiago"};
//     pair<int, string> B = {20, "Lawrence"};
// 	pair<int, string> C = {20, "Davi"};

// 	if(A < B) {
// 		// A é menor do que B pois 10 é menor do que 20. (Primeiro ele compara o primeiro valor).
// 	}
// 	if(C < B){
// 		// C é menor do que B nesse caso, pois como o primeiro valor é igual, ele compara pelo segundo. Como 'D' vem antes de 'L', C < B
// 	}
// 	return 0;
// }


int main() 
{
	vector< pair<int, int> > v = { {10, 1}, {1, 3}, {1, 2}, {2, 4}, {3, 5} }; // Declaração de um vector de pair
	// v = { (10, 1), (1, 3), (1, 2), (2, 4), (3, 5) }

	sort(v.begin(), v.end()); // Ordena o vector

  	// v = { (1, 2), (1, 3), (2, 4), (3, 5), (10, 1) }
	return 0;
}