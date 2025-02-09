#include <iostream>

using namespace std;

int main(){
    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;

    // p1 * c1 = p2 * c2 --> equilibrio 0 
    // p1 * c1 > p2 * c2 --> cai para direita -1
    // p1 * c1 < p2 * c2 --> cai para esquerda 1

    if (p1 * c1 > p2 * c2){
        cout << "-1" << endl;
    } else if (p1 * c1 < p2 * c2){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

}