#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> b(n);

    int first = -1, sec = -1;
    for (int i = 0; i < n; i++){
        if (first == -1){
            for (int j = i+1; j < n; j++){
                if (arr[i] == arr[j]){
                    b[i] = 1;
                    b[j] = 2;
                    first = arr[i];
                }
            }
        }
        else if (first != -1 && sec == -1){
            if (arr[i] != first){
                for (int j = i+1; j < n; j++){
                    if (arr[i] == arr[j]){
                        b[i] = 1;
                        b[j] = 3;
                        sec = arr[j];
                    }
                }
            }
        }
    }

    bool tem_1 = false, tem_2 = false, tem_3 = false;
    for (int i = 0; i < n; i++){
        if (b[i] == 1) tem_1 = true;
        if (b[i] == 2) tem_2 = true;
        if (b[i] == 3) tem_3 = true;
        if (b[i] == 0) b[i] = 3;
    }

    if (tem_1 && tem_2 && tem_3){
        for (auto i : b){
            cout << i << " ";
        }
        cout << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}