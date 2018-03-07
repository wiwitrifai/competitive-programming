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
    //ios_base::sync_with_stdio(false);
    #ifdef OFFLINE_TESTING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n], sum[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    if (k > n) k = n;

    sum[0] = arr[0];
    int max_sum = sum[0];
    for (int i = 1; i < k; i++) {
        sum[i] = sum[i-1] + arr[i];
        if (sum[i] > max_sum) max_sum = sum[i];
    }
    for (int i = k; i < n; i++) {
        sum[i] = arr[i]-arr[i-k]+sum[i-1];
        if (sum[i] > max_sum) max_sum = sum[i];
    }

    int max_elem = sum[0];
    for (int i = k; i < n; i++) {
        if (sum[i-k] > max_elem)
           max_elem = sum[i-k];
        if (sum[i] + max_elem > max_sum)
           max_sum = sum[i] + max_elem;
    }
    printf("%d\n", max_sum);
    
    #ifdef OFFLINE_TESTING
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}