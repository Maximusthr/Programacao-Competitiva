#include <iostream>
#include <map>

using namespace std;

// int main(){
//     map<string, int> mapa1;

//     mapa1["Lucas"] = 13;

//     if (mapa1.find("Lucas") == mapa1.end()){
//         printf("Chave não encontrada");
//     } else {
//         printf("%d\n", mapa1["Lucas"]);
//     }

//     mapa1.erase("Lucas");
//     if (mapa1.find("Lucas") != mapa1.end()){
//         printf("%d", mapa1["Lucas"]);
//     } else printf("Chave nao encontrada");
// }

int main()
{
	map<string, int> mapa1; // Declaração do map mapa1 que possui strings como chaves e ints como valores

	mapa1["Lucas"] = 13; // Insiro a chave "Lucas" de valor 13
	mapa1["Ana"] = 7; // Insiro a chave "Ana" de valor 7
	mapa1["Thiago"] = 20; // Insiro a chave "Thiago" de valor 20

 	map<string, int>::iterator it;
	for(it=mapa1.begin(); it!=mapa1.end(); it++) // O iterator it irá percorrer o map do seu ínicio ao fim
	{
	    	// O iterator it será um par de dois valores:
	    	printf("Chave: %d\n", (*it).first); // O seu valor first será a chave na posição atual do map 
	    	printf("Valor: %d\n", (*it).second); // O seu valor second será o valor mapeado à chave
	}
    
    // auto it = times.begin();
    // for (it; it != times.end(); it++){
    //     cout << (*it).first << " " << (*it).second << "\n";
    // }


    // for (auto [x, y] : times) {
    //     cout << x << ' ' << y << "\n";
    // }

}

