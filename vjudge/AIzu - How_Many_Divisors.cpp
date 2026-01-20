#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    
    set<int> div;
    for (int i = 1; i * i <= c; i++){
        if (c % i == 0){
            if (c/i >= a && c/i <= b){
                div.insert(c/i);
            }
            if (i >= a && i <= b) div.insert(i);
        }
    }

    cout << div.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}