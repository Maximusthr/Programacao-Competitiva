#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, x, y; cin >> n >> x >> y;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int l = 0, r = 0;
    int candidatos_l = 0;
    int candidatos_r = 0;

    int talvez = 0;

    bool achou = false;

    if (y == 0) {
        cout << 1 << "\n";
        return 0;
    }

    int primeiro = 0;
    while(l < n && r < n){
        if (talvez <= x && candidatos_r >= y){
            cout << talvez + 1 << "\n";
            return 0;
        }
        if (candidatos_l >= x && candidatos_r >= y){
            cout << l+1 << "\n";
            return 0;
        }

        if (l+1 == n || r+1 == n){
            cout << talvez + 1 << "\n";
            return 0;
        }

        if (!achou && arr[l] > arr[l+1]){
            candidatos_l++;
            l++;
            talvez = l;
            continue;
        }
        else if (!achou) {
            primeiro++;
            achou = true;
            talvez = l;
            r = l;
        }

        if (achou && arr[talvez] < arr[r+1]){
            candidatos_r++;
            r++;
        }
        else if (achou){
            achou = false;
            talvez = r+1;
            candidatos_l += candidatos_r + 1;
            candidatos_r = 0;
            l = r;
        }
    }
}
