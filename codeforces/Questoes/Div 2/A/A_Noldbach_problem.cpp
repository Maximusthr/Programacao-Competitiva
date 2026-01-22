#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1005;

void solve(){
    vector<int> crivo(MAX, true);
    
    crivo[0] = 0;
    crivo[1] = 0;
    
    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }

    int n, k; cin >> n >> k;

    vector<int> prime;

    for (int i = 2; i <= n; i++){
        if (crivo[i]) prime.push_back(i);
    }

    int sum = 0;
    for (int i = 2; i < prime.size(); i++){
        int v = 0;
        for (int j = 1; j < i; j++){
            v = prime[j] + prime[j-1] + 1;
            if (v == prime[i]) {
                sum++;
                break;
            }
            if (v > prime[i]) break;
        }
    }

    if (sum >= k){
        cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);


    solve();
}