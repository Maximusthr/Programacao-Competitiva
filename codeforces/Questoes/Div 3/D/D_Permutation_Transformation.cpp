#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> arr;
vector<int> prof;

void recursao(int l, int r, int p){
    if (r-l+1 < 1) return;

    int pos = -1;
    int maior = -1;
    for (int i = l; i <= r; i++){
        if (arr[i] > maior){
            maior = arr[i];
            pos = i;
        }
    }

    prof[maior] = p;

    recursao(l, pos-1, p+1);
    recursao(pos+1, r, p+1);
}   

void solve(){
    int n; cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }

    prof.resize(n);
    
    recursao(0, n-1, 0);

    for (int i = 0; i < n; i++){
        cout << prof[arr[i]] << " \n"[i==n-1];
    }

    arr.clear();
    prof.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}