#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 150005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    vector<bool> vis(MAX);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n; i++){
        if (arr[i] != 1 && !vis[arr[i] - 1]) vis[arr[i] - 1] = true;
        else if (!vis[arr[i]]) vis[arr[i]] = true;
        else if (!vis[arr[i] + 1]) vis[arr[i] + 1] = true;
    }

    int sum = 0;
    for (int i = 1; i < MAX; i++){
        if (vis[i]) sum++;
    }

    cout << sum << "\n";
}