#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int mid = 0;
    for (int i = 1; i < n-1; i++){
        mid += arr[i];
    }

    int ini = arr[0];
    int fim = arr[n-1];

    if ((ini%3) == (fim%3) && (ini%3) == (mid%3)){
        cout << 1 << " " << n-1 << "\n";
        return;
    }
    else if ((ini%3) != (fim%3) && (ini%3) != (mid%3) && (fim%3) != (mid%3)){
        cout << 1 << " " << n-1 << "\n";
        return;
    }

    int aux = mid, aux2 = mid;
    for (int i = 0; i < n-1; i++){
        fim = arr[n-1];
        if (i != 0) {
            ini += arr[i];
            aux2 -= arr[i];
        }
        aux = aux2;
        if ((ini%3) == (fim%3) && (ini%3) == (aux%3)){
                cout << i+1 << " " << n-1 << "\n";
                return;
            }
        else if ((ini%3) != (fim%3) && (ini%3) != (aux%3) && (fim%3) != (aux%3)){
            cout << i+1 << " " << n-1 << "\n";
            return;
        }
        for (int j = n-2; j > i+1; j--){
            aux -= arr[j];
            fim += arr[j];
            if ((ini%3) == (fim%3) && (ini%3) == (aux%3)){
                cout << i+1 << " " << j+1 << "\n";
                return;
            }
            else if ((ini%3) != (fim%3) && (ini%3) != (aux%3) && (fim%3) != (aux%3)){
                cout << i+1 << " " << j+1 << "\n";
                return;
            }
        }
    }

    cout << 0 << " " << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}