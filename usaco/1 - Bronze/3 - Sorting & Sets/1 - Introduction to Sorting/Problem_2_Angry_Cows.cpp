#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        map<int, int> explosao;
        int temp = 1;
        explosao[arr[i]] = 1;
        for (int j = i; j < n; j++){
            for (int k = j+1; k < n; k++){
                if (explosao[arr[k]] == 0 && arr[j] + explosao[arr[j]] >= arr[k]){
                    explosao[arr[k]] = explosao[arr[j]] + 1;
                    temp++;
                }
                else break;
            }
        }
        for (int j = i; j >= 0; j--){
            for (int k = j-1; k >= 0; k--){
                if (explosao[arr[k]] == 0 && arr[j] - explosao[arr[j]] <= arr[k]){
                    explosao[arr[k]] = explosao[arr[j]] + 1;
                    temp++;
                }
                else break;
            }
        }
        ans = max(temp, ans);
    }

    cout << ans << "\n";
}