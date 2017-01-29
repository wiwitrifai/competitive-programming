#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1024;
pair<double, double> p[N];
int id[N];
double yc, xc;

int main() {
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    xc = 0, yc = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &p[i].first, &p[i].second);
        xc += p[i].first;
        yc += p[i].second;
        id[i] = i;
    }
    xc /= n;
    yc /= n;
    sort(id, id+n, [](int a, int b) {
        if (p[a].second < yc && p[b].second >= yc)
            return true;
        if (p[a].second >= yc && p[b].second < yc)
            return false;
        return atan2(p[a].second - yc, p[a].first-xc) < atan2(p[b].second - yc, p[b].first-xc);
    });
    puts("0");
    for (int i = 0; i < n; i++)
        printf("%d ", id[i]+1);
    
    return 0;
}