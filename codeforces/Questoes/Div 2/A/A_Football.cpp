#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;

    map<string, int> match;

    for (int i = 0; i < n; i++){
        string x; cin >> x;
        match[x]++;
    }

    int max = 0;
    string aux;

    for (auto [x, y] : match){
        if (y > max) {
            max = y;
            aux = x;
        }
    }
    cout << aux << "\n";
}
