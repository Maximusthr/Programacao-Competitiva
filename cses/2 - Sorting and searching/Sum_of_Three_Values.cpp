#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        arr[i] = {x, i+1};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++){
        int l = 0, r = n-1;
        while (l < r){
            int alvo = k - arr[i].first;
            if (l != i && r != i && arr[l].first + arr[r].first == alvo){
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
                return 0;
            }
            if (arr[l].first + arr[r].first > alvo){
                r--;
            }
            else l++;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}
