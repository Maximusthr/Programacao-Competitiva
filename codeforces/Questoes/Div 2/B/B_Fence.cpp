#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    vector<int> suffix(n+1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }


    for (int i = n-1; i >= 0; i--){
        suffix[i] += arr[i] + suffix[i+1];
    }

    int menor = INF;
    int idx = -1;
    for (int i = 0; i <= n-k; i++){
        if (menor > suffix[i] - suffix[i+k]){
            menor = suffix[i] - suffix[i+k];
            idx = i;
        }
    }

    cout << idx + 1 << "\n";
}