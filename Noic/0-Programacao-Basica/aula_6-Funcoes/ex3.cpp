#include <bits/stdc++.h>

using namespace std;

// algoritmo de euclides

int euclides(int a, int b){
    if (a % b == 0) return b;
    return euclides(b, a % b);
}

int main(){
    int x, y; cin >> x >> y;
    cout << euclides(x, y) << "\n";
}