#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<string> alunos;

    while(n--){
        string aluno; cin >> aluno;
        alunos.push_back(aluno);
    }
    sort(alunos.begin(), alunos.end());

    cout << alunos[x-1] << "\n"; // x-1, pois inicia-se com a posição no 0
}
