#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<ll> bit;

    BIT(vector<ll> &arr) : n(arr.size()), bit(n+1) {
        for (int i = 1; i <= n; i++){
            bit[i] += arr[i-1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    ll sum(int i){
        ll ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }

        return ret;
    }

    ll query(int l, int r){
        return sum(r) - sum(l-1);
    }

};

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    stack<ll> st;
    vector<ll> left(n), right(n);
    BIT bit(arr);

    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            ll x = bit.query(st.top(), i);
            if (arr[i] < x){
                cout << "NO" << "\n";
                return;
            }
            st.pop();
        }

        if (st.empty()) left[i] = i+1;
        else left[i] = i - st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for (int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            ll x = bit.query(i, st.top());
            if (arr[i] < x){
                cout << "NO" << "\n";
                return;
            }
            st.pop();
        }

        if (st.empty()) right[i] = n - i;
        else right[i] = st.top() - i;
        st.push(i);
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}