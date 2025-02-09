#include <iostream>

using namespace std;

const int MAX = 1002;
int camelos[MAX];

int main(){
    int n; cin >> n;
    int soma = 0, i;

    for (i = 0; i < n; i++){
        cin >> camelos[i];
        soma += camelos[i];
    }

    int media = soma/n;

    for (i = 0; i < n; i++){
        camelos[i] = media - camelos[i];
    }

    for (i = 0; i < n; i++){
        cout << camelos[i] << "\n";
    }
    
}