#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> ans(n+1);

    for (int i = 1; i <= n; i++){
        int a = arr[i];
        int b = arr[arr[i]];
        while (a != b){
            a = arr[a];
            b = arr[arr[b]];
        }

        a = i;
        while (a != b){
            a = arr[a];
            b = arr[b];
        }

        ans[i] = a;
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i==n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}