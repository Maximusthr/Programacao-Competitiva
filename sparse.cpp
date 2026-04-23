#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int K = 25;
const int MAXN = 1e7;

void sparse() {
    int st[K][MAXN];

    for (int i = 1; i <= K; i++){
        for (int j = 0; j + (1 << i) <= MAXN; j++){
            st[i][j] = f(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }
};

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}