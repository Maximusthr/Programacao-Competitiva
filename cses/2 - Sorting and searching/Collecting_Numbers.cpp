#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int ans = 1;
    int ant = arr[0].second;
    for (int i = 1; i < n; i++){
        if (arr[i].second < ant){
            ans++;
        }
        ant = arr[i].second;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}