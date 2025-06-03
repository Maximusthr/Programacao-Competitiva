#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Cubes{
    int w, l, h;
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        vector<Cubes> cubos;
        for (int i = 0; i < m; i++){
            int w, l, h; cin >> w >> l >> h;

            cubos.push_back({w, l, h});
        }

        vector<int> fib;
        fib.push_back(1);
        fib.push_back(2);
        int a = 1, b = 2;
        for (int i = 0; i < n-2; i++){
            int c = a + b;
            a = b;
            b = c;
            fib.push_back(c);
        }

        int tam = fib.size();
        for (int i = 0; i < m; i++){
            if (fib[tam-1] <= cubos[i].l){
                if (fib[tam-1] + fib[tam-2] <= cubos[i].h && fib[tam-1] <= cubos[i].w && fib[tam-1] <= cubos[i].l){
                    cout << 1 << "";
                }
                else if (fib[tam-1] + fib[tam-2] <= cubos[i].w && fib[tam-1] <= cubos[i].l && fib[tam-1] <= cubos[i].h){
                    cout << 1 << "";
                }
                else if (fib[tam-1] + fib[tam-2] <= cubos[i].l && fib[tam-1] <= cubos[i].w && fib[tam-1] <= cubos[i].h){
                    cout << 1 << "";
                }
                else cout << 0 << "";
            }
            else cout << 0 << "";
        }
        cout << "\n";
    }
}