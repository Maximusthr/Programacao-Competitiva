#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> freq(MAX);
    for (int i = 0; i < n; i++){
        cin >> arr[i];

        for (int j = 1; j * j <= arr[i]; j++){
            if (arr[i] % j == 0){
                if (arr[i]/j == j) freq[j]++;
                else {
                    freq[arr[i]/j]++;
                    freq[j]++;
                }
            }
        }
    }

    for (int i = MAX-1; i >= 0; i--){
        if (freq[i] > 1){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}