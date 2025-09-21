#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 105;

void solve(){
    int n; cin >> n;

    vector<int> arr(MAX);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x]++;
    }

    vector<int> ocur;
    for (int i = 0; i < MAX; i++){
        if (arr[i] > 0){
            ocur.push_back(arr[i]);
        }
    }

    sort(ocur.begin(), ocur.end());

    int maior = 0;
    int aux = 0;
    for (int i = 0; i < ocur.size(); i++){
        maior = max(maior, (ocur[i] * ((int)ocur.size() - i)));
    }
    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}