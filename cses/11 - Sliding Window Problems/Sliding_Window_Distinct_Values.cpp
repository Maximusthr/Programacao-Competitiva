#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    int dist = 0;
    map<int, int> freq;
    vector<int> ans;
    for (int i = 0; i < k; i++){
        freq[arr[i]]++;
        if(freq[arr[i]] == 1) dist++;
    }
    ans.push_back(dist);
    for (int i = k; i < n; i++){
        freq[arr[i-k]]--;
        if (freq[arr[i-k]] == 0) dist--;
        freq[arr[i]]++;
        if (freq[arr[i]] == 1) dist++;
        ans.push_back(dist);
    }

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}