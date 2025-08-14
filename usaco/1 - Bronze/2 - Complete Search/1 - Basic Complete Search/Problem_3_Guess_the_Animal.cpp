#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 101;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n; cin >> n;

    vector<string> animals[MAX];
   
    for (int i = 0; i < n; i++){
        string trash; cin >> trash;
        int k; cin >> k;
        for (int j = 0; j < k; j++){
            string x; cin >> x;
            animals[i].push_back(x);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            int temp = 0;
            for (int k = 0; k < animals[j].size(); k++){
                if (find(animals[i].begin(), animals[i].end(), animals[j][k]) != animals[i].end()) temp++;
            }
            temp++;

            ans = max(temp, ans);
        }
    }

    cout << ans << "\n";
}
