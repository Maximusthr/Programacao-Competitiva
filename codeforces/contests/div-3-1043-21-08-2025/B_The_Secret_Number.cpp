// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> val;

ll exp(ll a, ll b){
    ll x = 1;
    while (b > 0){
        if (b%2) x *= a;
        a *= a;
        b >>= 1;
    }

    return x;
}

void solve(){
    ll x; cin >> x;

    vector<ll> todo;
    for (int i = 0; i < val.size(); i++){
        if (x % val[i] == 0){
            todo.push_back(x/val[i]);
        }
    }

    sort(todo.begin(), todo.end());

    cout << todo.size() << "\n";
    for (int i = 0; i < todo.size(); i++){
        cout << todo[i] << " \n"[i == todo.size()-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    // val.push_back(1);
    for (int i = 1; i < 18; i++){
        val.push_back(exp(10, i) + 1);
    }
    
    while(t--){
        solve();
    }
}