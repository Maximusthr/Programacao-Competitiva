#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, l; cin >> n >> l;

    vector<int> lanternas;
    for (int i = 0; i < n; i++){
        int aux; cin >> aux;
        lanternas.push_back(aux);
    }

    sort(lanternas.begin(), lanternas.end());

    double d;
    for (int i = 0; i < (int)lanternas.size(); i++){
        if (i == 0 && (int)lanternas.size() > 1) {
            if (lanternas[0] != 0) d = lanternas[0];
            else d = (double)(lanternas[i+1]-lanternas[i])/2;
        } else if (i == 0){
            if (lanternas[0] != 0) d = lanternas[0];
        }
        
        if (i == (int)lanternas.size()-1) {
            if (lanternas[i] != l && d < (l-lanternas[i])) d = l - lanternas[i];
            break;
        }
        else if (d < (double)(lanternas[i+1]-lanternas[i])/2) d = (double)(lanternas[i+1]-lanternas[i])/2;
    }

    for (int i = (int)lanternas.size()-1; i >= 0; i--){
        if (i == 0) break;
        else if (d < (double)(lanternas[i]-lanternas[i-1])/2) d = (double)(lanternas[i]-lanternas[i-1])/2;
    }

    cout << fixed << setprecision(10);
    cout << d << '\n';

}
