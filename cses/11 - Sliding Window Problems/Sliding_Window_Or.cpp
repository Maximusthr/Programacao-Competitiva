#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct AggStack{
    stack<pair<ll, ll>> st;
    
    void push(ll v){
        ll x = (st.empty() ? v : (v | st.top().second));
        st.push({v, x});
    }

    void pop(){
        st.pop();
    }

    int Agg(){
        return st.top().second;
    }
};

struct AggQueue{
    AggStack in, out;

    void push(ll x){
        in.push(x);
    }

    void pop(){
        if (out.st.empty()){
            while(!in.st.empty()){
                out.push(in.st.top().first);
                in.pop();
            }
        }
        out.pop();
    }

    int query(){
        if (out.st.empty()) return in.Agg();
        if (in.st.empty()) return out.Agg();
        return (in.Agg() | out.Agg());
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

    int wind = 0;
    ll ans = 0;
    AggQueue pilha;
    for (int i = 0; i < n; i++){
        pilha.push(arr[i]);
        wind++;
        if (wind == k){
            ans ^= pilha.query();
            pilha.pop();
            wind--;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}