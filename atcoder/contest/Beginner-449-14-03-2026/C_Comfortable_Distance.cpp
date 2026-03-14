#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, l, r; cin >> n >> l >> r;

    string s; cin >> s;

    map<char, vector<int>> mapa;
    for (int i = 0; i < n; i++){
        mapa[s[i]].push_back(i);
    }

    ll ans = 0;

    for (auto [x, y] : mapa){
        for (int i = 0; i < y.size()-1; i++){
            int esq = l + y[i];
            int dir = r + y[i];
            
            // relacao a direita
            int left = 0, right = y.size()-1;
            while(left < right){
                int mid = left + (right - left + 1)/2;

                if (y[mid] <= dir) left = mid;
                else right = mid - 1;
            }
            if (y[left] < esq) continue;

            int achou_R = left;

            // relacao a esquerda
            left = 0, right = y.size()-1;
            while(left < right){
                int mid = left + (right - left)/2;

                if (y[mid] >= esq) right = mid;
                else left = mid + 1;
            }
            if (left == i){
                left++;
            }
            if (y[left] > dir) continue;

            int achou_L = left;

            ans += achou_R - achou_L + 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}