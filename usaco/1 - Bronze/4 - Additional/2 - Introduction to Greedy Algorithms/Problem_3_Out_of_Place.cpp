#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int pos = -1;
    bool frente = false;
    for (int i = 0; i < n-1; i++){
        if (arr[i] > arr[i+1]){
            if (i < n-2 && arr[i] > arr[i+2]) pos = i;
            else {
                pos = i+1;
                frente = true;
            }
            break;
        }
    }

    int ans = 0;
    int temp = 0;
    
    while (!is_sorted(arr.begin(), arr.end())){
        if (frente){
            if (arr[pos-1] > arr[pos]){
                swap(arr[pos-1], arr[pos]);
                if (arr[pos] == temp) {
                    pos--;
                    continue;
                }
                temp = arr[pos];
                ans++;
                pos--;
            }
        }
        else {
            if (arr[pos] > arr[pos+1]){
                swap(arr[pos], arr[pos+1]);
                if (arr[pos] == temp) {
                    pos++;
                    continue;
                }
                temp = arr[pos];
                ans++;
                pos++;
            }
        }
    }

    cout << ans << "\n";
}
