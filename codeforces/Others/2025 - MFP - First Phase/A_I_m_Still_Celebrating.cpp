#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> suffix(MAX);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        suffix[a]++;
    }
    
    for (int i = MAX-2; i >= 0; i--){
        suffix[i] += suffix[i+1];
    }

    for (int i = 1; i <= m; i++){
        cout << suffix[i] << " \n"[i == m];
    }
}