#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<string> arr;

bool verif(int xi, int yi, int xf, int yf){
    vector<char> carac;
    for (int i = xi; i <= xf; i++){
        for (int j = yi; j <= yf; j++){
            carac.push_back(arr[i][j]);
        }
    }
    vector<char> carac2;
    for (int i = xf; i >= xi; i--){
        for (int j = yf; j >= yi; j--){
            carac2.push_back(arr[i][j]);
        }
    }

    for (int i = 0; i < carac.size(); i++){
        if (carac[i] != carac2[i]) return false;
    }
    return true;
}   

void solve(){
    cin >> n >> m;

    int ans = 0;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            for (int l = n-1; l >= i; l--){
                for (int k = m-1; k >= j; k--){
                    ans += verif(i, j, l, k);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}