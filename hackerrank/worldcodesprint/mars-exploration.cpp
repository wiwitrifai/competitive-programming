#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string S;
    cin >> S;
    long long ans = 0;
    for(int i = 0; i<S.length(); i+=3) {
        ans += (S[i] != 'S') + (S[i+1] != 'O') + (S[i+2] != 'S');
    }
    cout << ans << endl;
    return 0;
}