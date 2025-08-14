#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n; cin >> n;
    
    vector<int> arr(n);
    
    for (auto &i : arr) cin >> i;

    if (arr[0] > 0) {
        cout << -1 << "\n";
        return 0;
    }

    bool ok = true;

    for (int i = n-1; i >= 0; i--){
        if (arr[i] > 0){
            int temp = arr[i] - 1;
            int j = i - 1;
            while (temp > 0){
                if (arr[j] == -1 || arr[j] == temp){
                    arr[j--] = temp--;
                }
                else {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    
    // for (auto &i : arr) cout << i << " ";
    // cout << "\n";

    int maximo = 0, minimo = 0;
    int temp = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0 || arr[i] == -1) maximo++;
    }

    for (int i = n-1; i >= 0; i--){
        if (arr[i] == -1){
            if (i != n-1 && arr[i+1] > 0) minimo++;
        } 
        if (arr[i] == 0 || (i == 0 && arr[i] == -1)) minimo++;
    }

    cout << minimo << " " << maximo << "\n";
}