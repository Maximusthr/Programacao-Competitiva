#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, v;
    
    int i = 1;
    while (cin >> a >> v && (a || v)){
        map<int, int> voos;
    
        for (int i = 0; i < v; i++){
            int x, y; cin >> x >> y;
            voos[x]++;
            voos[y]++;
        }
    
        int max = 0;
        for (auto [x, y] : voos){
            if (max < y) max = y;
        }
        
        cout << "Teste " << i << "\n";
        for (auto [x, y] : voos){
            if (max == y) cout << x << " ";
        }
        cout << "\n\n";
        i++;
    }
}
