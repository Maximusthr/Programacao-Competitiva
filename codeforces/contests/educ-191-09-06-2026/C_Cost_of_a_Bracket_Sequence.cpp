#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    string ans(n, '0');
    int v = INF;

    for (int i = 0; i < n; i++){
        string aux = s;
        string best(n, '0');
        int kk = k;

        for (int j = 0; j < i; j++){
            if (aux[j] == '(' && kk > 0){
                best[j] = '1';
                aux[j] = 'x';
                kk--;
            }
        }
        for (int j = n-1; j > i; j--){
            if (aux[j] == ')' && kk > 0){
                best[j] = '1';
                aux[j] = 'x';
                kk--;
            }
        }   

        int tem = 0;
        int sum = 0;
        for (int j = 0; j < n; j++){
            if (aux[j] == 'x') continue;
            
            if (aux[j] == '(') tem++;
            else if (aux[j] == ')' && tem > 0){
                sum++;
                tem--;
            }
        }

        if (sum < v){
            v = sum;
            ans = best;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}