#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        string x; cin >> x;
        
        int tam = (int)x.size();

        int i = 0, j = 0;
        int ans = INF;
        map<char, int> dist;
        
        if (tam < 3) cout << 0 << "\n";
        else {
            bool fim = false;
            bool ok = false;
            while (i < tam){
                while(j < tam && !fim && !ok && (dist['1'] == 0 || dist['2'] == 0 || dist['3'] == 0)){
                    dist[x[j]]++;
                    if (dist['1'] >= 1 && dist['2'] >= 1 && dist['3'] >= 1) {
                        ans = min(ans, j-i+1);
                        ok = true; // A way that I have thought to check distinct numbers
                        continue;
                    }
                    j++;
                    if (j == tam) {
                        // I did this to force j to be the last element.
                        fim = true;
                        j--;
                    }
                }

                if (ok) {
                    if (dist['1'] >= 1 && dist['2'] >= 1 && dist['3'] >= 1) ans = min(ans, j-i+1);
                    else if (dist['1'] < 1 || dist['2'] < 1 || dist['3'] < 1 || i == j){
                        ok = false;
                        j++;
                        continue;
                    }
                    dist[x[i]]--;
                }
                i++;
            }
            
            cout << (ans == INF ? 0 : ans) << "\n";
        }
    }
}
