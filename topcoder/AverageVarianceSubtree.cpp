#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long cnt[N][N];
long double sum[N][N], sum2[N][N], sumd[N][N];
vector< int > g[N];
long double w[N]; 
int n;
void dfs(int v = 0, int par = -1) {
	for (int i = 0; i <= n; i++) {
		sum[v][i] = sum2[v][i] = sumd[v][i] = 0;
		cnt[v][i] = 0;
	}
	sum[v][1] = w[v];
	sum2[v][1] = w[v] * w[v];
	cnt[v][0] = cnt[v][1] = 1;
	for (int u : g[v]) if (u != par) {
		dfs(u, v);
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j < i; j++) {
				int k = i-j;
				sumd[v][i] += sumd[v][j] * cnt[u][k] + sumd[u][k] * cnt[v][j] + (double) sum[v][j] * sum[u][k]; 
				sum[v][i] += sum[v][j] * cnt[u][k] + sum[u][k] * cnt[v][j];
				sum2[v][i] += sum2[v][j] * cnt[u][k] + sum2[u][k] * cnt[v][j];
				cnt[v][i] += cnt[v][j] * cnt[u][k];
			}
		}
	}
}

class AverageVarianceSubtree {
public:
	double average(vector <int> p, vector <int> weight) {
		n = weight.size();
		long double avg = 0;
		for (int i = 0; i < n; i++)
			g[i].clear(), w[i] = weight[i], avg += w[i];
		avg /= n;
		for (int i = 0; i < n; i++) w[i] -= avg;
		for (int i = 0; i < n-1; i++) {
			g[i+1].push_back(p[i]);
			g[p[i]].push_back(i+1);
		}
		dfs(0, -1);
		long long all = 0;
		long double ans = 0;
		for (int i = 0; i < n; i++) {
			for (int s = 1; s <= n; s++) {
				long double x2 = sum2[i][s] + 2.0 * sumd[i][s], mu2 = x2/s; 
				long double var = (sum2[i][s] - mu2)/s;
				ans += var;
				all += cnt[i][s];
			}
		}
		return ans/(long double)all;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing AverageVarianceSubtree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1492514699;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AverageVarianceSubtree _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1};
				int weight[] = {10,20,30};
				_expected = 19.444444444444443;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1,1};
				int weight[] = {10,20,7,6};
				_expected = 23.014520202020204;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0};
				int weight[] = {1,1000000000};
				_expected = 8.3333333166666672E16;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,0,1,0,2,3,3,6};
				int weight[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};
				_expected = 4.432586365551196E14;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {};
				int weight[] = {712};
				_expected = 0.0;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 5:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int weight[] = ;
				_expected = ;
				_received = _obj.average(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
