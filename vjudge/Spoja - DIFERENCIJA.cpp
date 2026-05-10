#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> l_low(n), r_low(n);
    vector<ll> l_big(n), r_big(n);

    stack<ll> st;
    
    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if (st.empty()) l_low[i] = i+1;
        else l_low[i] = i - st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for (int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        if (st.empty()) r_low[i] = n - i;
        else r_low[i] = st.top() - i;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for (int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if (st.empty()) l_big[i] = i+1;
        else l_big[i] = i - st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for (int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }

        if (st.empty()) r_big[i] = n - i;
        else r_big[i] = st.top() - i;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    ll maior = 0, menor = 0;
    for (int i = 0; i < n; i++){
        maior += arr[i] * l_big[i] * r_big[i];
        menor += arr[i] * l_low[i] * r_low[i];
    }

    cout << maior - menor << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}