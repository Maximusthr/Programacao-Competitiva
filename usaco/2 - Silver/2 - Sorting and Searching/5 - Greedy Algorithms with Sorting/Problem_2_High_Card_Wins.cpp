#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n; cin >> n;

    vector<int> arr(n);
    vector<bool> vis(2*n + 1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        vis[arr[i]] = true;
    }

    vector<int> qtd;
    for (int i = 1; i <= 2*n; i++){
        if (!vis[i]) qtd.push_back(i);
    }

    sort(arr.begin(), arr.end());

    int ans = 0;

    int i = 0, j = 0;
    while (i < n && j < n){
        if (qtd[i] > arr[j]){
            ans++;
            j++;
        }
        i++;
    }

    cout << ans << "\n";
}