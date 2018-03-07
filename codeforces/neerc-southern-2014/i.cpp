#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <stack>

#define maximum(a,b) (a > b ? a : b)
#define minimum(a,b) (a < b ? a : b)
#define gcd(a,b) (a == 0 ? b : gcd(b%a, a))
#define pow(a,b) (b == 0 ? 1 : a*pow(a, b-1))

typedef long long ll;

using namespace std;

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
template <class T>
inline long long to_longlong (const T& t)
{
    std::stringstream ss;
    long long val;
    ss.str(t);
    ss >> val;
    return val;
}

//#define OFFLINE_TESTING

int main() {
    ios_base::sync_with_stdio(false);
    #ifdef OFFLINE_TESTING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr+n);
    ll cnt = 0;
    ll max = arr[n-1];
    ll idx;
    for (int i = 0; i < n; i++) {
        cnt += arr[i];
        if (cnt > max) {
            idx = i;
            break;
        }
    }
    cout << idx+1 << endl;


    #ifdef OFFLINE_TESTING
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}