#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    bool five = false, zero = false;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i] = x;
        if (x % 10 == 5){
            five = true;
            arr[i] += 5;
        }
        else if (x % 10 == 0){
            zero = true;
        }
    }

    if (five || zero || n == 1){
        for (int i = 1; i < n; i++){
            if (arr[i] != arr[i-1]){
                cout << "NO" << "\n";
                return;
            }
        }
        cout << "YES" << "\n";
        return;
    }

    int g1 = 0, g2 = 0;
    for (int i = 0; i < n; i++){
        int x = arr[i] % 100;
        if (x == 13 || x == 14 || x == 17){
            x += x % 10;
        }
        if (x < 12){
            while(x < 12){
                x += x % 10;
            }
        }
        else if (x > 18){
            while(x < 112){
                x += x % 10;
            }
            x = x % 100;
        }
        if (x == 16) g2++;
        else g1++;
    }

    if (g1 > 0 && g2 == 0 || g1 == 0 && g2 > 0){
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
