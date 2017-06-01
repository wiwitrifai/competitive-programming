#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m, t;
    cin >> t;
    while(t--) {
    cin >> n >> m;
    int r = m % n, k = (m-1)/n;
    if(r == 0)
        r = n;
    if(n & 1) {
        if(m&1) {
            if(k & 1)
                cout << r/2;
            else {
                cout << (r+1)/2;
            }
        }
        else {
            if(k & 1)
                cout << (n+1) - (r+1)/2;
            else 
                cout << (n+1-(r/2));
            
        }
    }
    else {
        if(m&1)
            cout << (r+1)/2;
        else {
            cout << (n+1-(r/2));
        }
    }
    cout << " " << k << "\n";
    }
    return 0;
}
