#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    map<ll, ll> arr, ans;

    for (int i = 0; i < n; i++){
        ll l, r; cin >> l >> r;

        arr[l]++;
        arr[r+1]--;
    }

    auto i = arr.begin(), atual = arr.begin();
    atual++;

    int total = (*i).second;
    while(atual != arr.end()){
        ans[total] += (*atual).first - (*i).first;
        total += (*atual).second;
        i++, atual++;
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i==n];
    }
}