#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<char> times = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    for (int i = 0, j = 0; i < 8; i++){
        int aux1, aux2; cin >> aux1 >> aux2;
        if (aux1 > aux2) {
            j++;
            times.erase(times.begin() + j);
        } else {
            times.erase(times.begin() + j);
            j++;
        }
    }

    for (int i = 0, j = 0; i < 4; i++){
        int aux1, aux2; cin >> aux1 >> aux2;
        if (aux1 > aux2) {
            j++;
            times.erase(times.begin() + j);
        } else {
            times.erase(times.begin() + j);
            j++;
        }
    }

    for (int i = 0, j = 0; i < 2; i++){
        int aux1, aux2; cin >> aux1 >> aux2;
        if (aux1 > aux2) {
            j++;
            times.erase(times.begin() + j);
        } else {
            times.erase(times.begin() + j);
            j++;
        }
    }

    for (int i = 0, j = 0; i < 1; i++){
        int aux1, aux2; cin >> aux1 >> aux2;
        if (aux1 > aux2) {
            j++;
            times.erase(times.begin() + j);
        } else {
            times.erase(times.begin() + j);
            j++;
        }
    }

    cout << times[0] << "\n";
}
