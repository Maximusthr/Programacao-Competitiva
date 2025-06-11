#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int x, y; cin >> x >> y;

        int ans = 0;
        int num = 0;
        for (int i = y; i >= x; i--){
            int temp = i;
            int menor = INF;
            int maior = 0;

            while(temp > 0){
                int n = temp % 10;
                menor = min(n, menor);
                maior = max(n, maior);
                temp /= 10;
            }

            ans = max(ans, maior-menor);
            if (maior-menor == ans) num = i;
            
            if (ans == 9) {
                break;
            }
        }

        cout << num << "\n";
    }
}