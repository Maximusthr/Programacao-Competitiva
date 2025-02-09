#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, d; cin >> n >> m >> d;

    queue<int> c;
    int teste = 0;
    for (int i = 0; i < m; i++){
        int aux; cin >> aux;
        c.push(aux);
    }

    vector<int> rio(n);
    int elem = (n/m)-1;
    int num = 1;

    bool ok = true;

    if (d >= n)
        rio[n-1] = 1;
    else if (m == 1){
        elem = n-d-1;
        for (int i = 0, j = elem; i < c.front(); i++){
            rio[j] = num;
            j++;
        }
        elem += d+1;
        if (elem < n) ok = false;
    }
    else {
        while(!c.empty()){
            for (int i = 0, j = elem; i < c.front(); i++){
                rio[j] = num;
                j++;
            }
            elem += (n/m);
            if (c.front() > 1) elem += c.front()-1; 
            
            if (elem >= n) break;

            c.pop();
            num++;

            if (c.empty()){
                if (elem < n) ok = false;
            }
        }
    }

    if (ok) {
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++){
            if (i == n) cout << rio[i];
            else cout << rio[i] << " ";
        }
        cout << "\n";
    }
    else cout << "NO" << "\n";
}
