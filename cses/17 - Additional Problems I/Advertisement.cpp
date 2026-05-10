#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    ll ans = 0;
    ll temp = 0;
    stack<pair<ll, ll>> st;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;

        while(!st.empty() && st.top().first >= x){
            temp += st.top().second;
            ans = max(ans, st.top().first * temp);
            st.pop();
        }

        st.push({x, temp + 1});
        temp = 0;
    }

    while(!st.empty()){
        temp += st.top().second;
        ans = max(ans, st.top().first * temp);
        st.pop();
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}