#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<pair<int, int>>> arr(3, vector<pair<int, int>> (n));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            int x; cin >> x;

            arr[i][j] = {x, j};
        }
        sort(arr[i].begin(), arr[i].end(), greater<pair<int, int>> ());
    }

    int sum = 0;
    for (int i = 0; i < 3; i++){
        int aux = arr[i][0].first;
        int maior = 0;
        for (int j = 0; j < 3; j++){
            while(j < 3 && (arr[(i+1) % 3][j].second == arr[i][0].second)){
                j++;
            }
            if (j == 3) continue;
            int aux2 = 0;
            int teste = arr[(i+1) % 3][j].first;

            for (int k = 0; k < 3; k++){
                while(k < 3 && (arr[(i+2) % 3][k].second == arr[i][0].second || arr[(i+2) % 3][k].second == arr[(i+1) % 3][j].second)){
                    k++;
                }
                if (k == 3) continue;
                aux2 = max(aux2, teste + arr[(i+2) % 3][k].first);
            }
            maior = max(maior, aux + aux2);
        }
        sum = max(sum, maior);
    }

    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}