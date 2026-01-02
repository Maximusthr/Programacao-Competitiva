#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
 
    vector<pair<int, int>> tempos;
 
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
 
        tempos.push_back({x, 1});
        tempos.push_back({y, -1});
    }
 
    sort(tempos.begin(), tempos.end());
 
    int ans = 0;
    int maior = 0;
    int ano = INF;
    for (auto &[x, y] : tempos){
        maior += y;
        if (maior > ans){
            ans = max(maior, ans);
            ano = x;
        }
    }
 
    cout << ano << " " << ans << "\n";
}