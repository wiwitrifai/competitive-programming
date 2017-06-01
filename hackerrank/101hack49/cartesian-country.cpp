#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a, b, c, d, x, y;
    cin >> a >> b;
    cin >> c >> d;
    cin >> x >> y;
    long long dx = min(x-a, c-x), dy = min(y-b, d-y);
    long long ans = (2 * dx + 1) * (2 * dy + 1) - 1;
    cout << ans / 2 << endl;
    return 0;
}
