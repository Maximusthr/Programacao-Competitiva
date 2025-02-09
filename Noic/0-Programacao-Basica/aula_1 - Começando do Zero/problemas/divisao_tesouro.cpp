#include <iostream>

using namespace std;

int main(){

    int moedas, marinheiros;
    cin >> moedas >> marinheiros;

    int divisao = (moedas/(marinheiros+2)); // 2 representa o capitão que vale por 2 marinheiros

    cout << divisao*2 << endl; // divisao*2, pois representa a quantidade de moedas que o capitão receberá

}