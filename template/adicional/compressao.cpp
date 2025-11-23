#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;

    vector<int> a; // indicies originais
    vector<int> d = a; // compressão nos indices

    sort(d.begin(), d.end()); 
    d.resize(unique(d.begin(), d.end()) - d.begin());

    for (int i = 0; i < n; i++) {
        // resgatando os indices originais
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    }


}