#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e6+5;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    set<int> miss;
    for (int i = 0; i <= k; i++){
        miss.insert(i);
    }

    vector<int> freq(MAX);
    for (int i = 0; i < k; i++){
        if (arr[i] >= MAX) continue;
        freq[arr[i]]++;
        if(freq[arr[i]] == 1) miss.erase(arr[i]);
    }
    
    int menor = *miss.begin();
    
    for (int i = k; i < n; i++){
        if (arr[i-k] < MAX){
            freq[arr[i-k]]--;
            if (freq[arr[i-k]] == 0) miss.insert(arr[i-k]);
        }

        if (arr[i] < MAX){
            freq[arr[i]]++;
            if (freq[arr[i]] == 1) miss.erase(arr[i]);
        }

        menor = min(menor, *miss.begin());
    }

    cout << menor << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}