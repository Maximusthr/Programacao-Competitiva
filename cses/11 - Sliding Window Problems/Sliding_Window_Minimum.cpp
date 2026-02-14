#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct AggStack {
    stack<pair<ll, ll>> st;

    void push (ll x){
        ll cur = (st.empty() ? x : min(x, st.top().second));
        st.push({x, cur});
    }

    void pop(){
        st.pop();
    }

    ll agg() const {
        return st.top().second;
    }
};

struct AggQueue {
    AggStack in, out;

    // adiciona novos elementos
    void push(ll x){
        in.push(x);
    }
 
    // remove os elementos (vai de in para out)
    void pop(){
        if (out.st.empty()){
            while (!in.st.empty()){
                out.push(in.st.top().first);
                in.pop();

            }
        }
        out.pop();
    }

    // mesma ideia do pop
    ll query(){
        if (in.st.empty()) return out.agg();
        if (out.st.empty()) return in.agg();
        return min(out.agg(), in.agg());
    }
};

void solve(){
    int n, k; cin >> n >> k;

    ll x, a, b, c; cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;

    for (int i = 1; i < n; i++){
        arr[i] = (arr[i-1] * a + b) % c;
    }

    ll ans = 0;
    
    AggQueue pilha;
    for (int i = 0; i < k; i++){
        pilha.push(arr[i]);
    }

    ans ^= pilha.query();
    pilha.pop();
    for (int i = k; i < n; i++){
        pilha.push(arr[i]);
        ans ^= pilha.query();
        pilha.pop();
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}