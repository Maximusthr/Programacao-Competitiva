#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, q; cin >> n >> q; //n qtd de notas e q qtd de pessoas mínimas a passar.
    vector<int> concurso;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        concurso.push_back(x);
    }

    sort(concurso.begin(), concurso.end());

    cout << concurso[(int)concurso.size() - q];

}


