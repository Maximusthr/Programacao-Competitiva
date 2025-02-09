#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    while(qtd--){
        int x; cin >> x;
        
        vector<int> altura;

        for (int i = 0; i < x; i++){
            int a; cin >> a;
            altura.push_back(a);
        }

        sort(altura.begin(), altura.end());

        for (int i = 0; i < (int)altura.size(); i++){
            if (i != (int)altura.size()-1) cout << altura[i] << " ";
            else cout << altura[i] << "\n";
        }
    }
}
