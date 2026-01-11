#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    int dois = 0;
    int um = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 1) um++;
        else dois++;
    }

    if (dois > 0){
        cout << 2 << " ";
        dois--;
    }

    if (um > 0){
        cout << 1 << " ";
        um--;
    }

    while(dois){
        cout << 2 << " ";
        dois--;
    }

    while(um){
        cout << 1 << " ";
        um--;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}