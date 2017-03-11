#include <bits/stdc++.h>

using namespace std;

const int N = 333, inf = 1e8;

long long ans[N][N];
int dist[N][N];
vector< pair< int, int > > g[N];

class MinMaxMax {
public:
	long long findMin(vector <int> a, vector <int> b, vector <int> w, vector <int> v) {
		int n = v.size(), m = a.size();
		for (int i = 0; i < m; ++i) {
			g[a[i]].emplace_back(b[i], w[i]);
			g[b[i]].emplace_back(a[i], w[i]);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = 1e17;
		vector< int > ver = v;
		sort(ver.begin(), ver.end());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = inf;
		ver.erase(unique(ver.begin(), ver.end()), ver.end());
		for (int lim : ver) {
			for (int i = 0; i < n; i++) if (v[i] <= lim) {
				dist[i][i] = 0;
				set< pair< int, int > > st;
				st.insert({0, i});
				for (int u = 0; u < n; u++) if (v[u] <= lim){
					for (auto nx : g[u]) {
						if (v[nx.first] > lim) continue;
						int nw = max(dist[i][u], nx.second);
						if (nw >= dist[i][nx.first]) continue;
						st.erase(make_pair(dist[i][nx.first], nx.first));
						dist[i][nx.first] = nw;
						st.insert(make_pair(dist[i][nx.first], nx.first));	
					}
				}
				while (!st.empty()) {
					auto it = st.begin();
					int u = it->second;
					st.erase(it);
					for (auto nx : g[u]) {
						if (v[nx.first] > lim) continue;
						int nw = max(dist[i][u], nx.second);
						if (nw >= dist[i][nx.first]) continue;
						st.erase(make_pair(dist[i][nx.first], nx.first));
						dist[i][nx.first] = nw;
						st.insert(make_pair(dist[i][nx.first], nx.first));
					}
				}
			}
			for (int i = 0; i < n; i++) if (v[i] <= lim) {
				for (int j = i+1; j < n; j++) if (dist[i][j] < inf && v[j] <= lim) {
					ans[i][j] = min(ans[i][j], 1LL * lim * dist[i][j]);
				}
			}
		}
		long long ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				ret += ans[i][j];
		return ret;
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
		cout << "Testing MinMaxMax (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489234886;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MinMaxMax _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0};
				int b[] = {1};
				int w[] = {5};
				int v[] = {3,6};
				_expected = 30LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {0,0,1};
				int b[] = {1,2,2};
				int w[] = {10,11,12};
				int v[] = {6,5,4};
				_expected = 186LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0,0,1};
				int b[] = {1,2,2};
				int w[] = {100,1,1};
				int v[] = {1,1,100};
				_expected = 300LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {0,1,2,3,4,5,6,7,8,9};
				int b[] = {1,2,3,4,5,6,7,8,9,10};
				int w[] = {1000000,1,1000000,1,1000000,1,1000000,1,1000000,1};
				int v[] = {1000000,1,1000000,1,1000000,1,1000000,1,1000000,1,1000000};
				_expected = 50000005000000LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {9,12,4,11,0,8,6,11,11,10,12,7,3,12,3,10,0,3,2,7,
				          0,10,8,1,11,9,2,0,3,6,4,2,3,5,9,0,6};
				int b[] = {0,5,6,5,10,2,1,2,3,4,6,9,9,10,5,5,6,4,12,5,12,7,
				          7,3,4,12,4,1,8,7,1,6,6,4,11,5,11};
				int w[] = {879651,656980,11,51564,206,420,917584,205,59290,3323,
				          644,1,13243,84162,154,561242,1,190,10,136901,420623,
				          353,573129,81,25,133670,72,528049,5,715560,82641,46,
				          1,527672,923948,1,13};
				int v[] = {5,1829,51302,3026,4,14,5189,3,25289,2,2967,15994,6};
				_expected = 157740289LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {4,16,0,10,11,21,11,21,20,6,13,10,10,3,20,15,16,9,6,14,13,8,
				          17,9,2,21,3,4,10,13,5,7,13,1,12,1,3,13,5,21,12,0,19,15,6,0,
				          5,13,1,8};
				int b[] = {17,1,8,2,1,7,6,12,18,21,7,20,18,7,6,7,17,20,15,10,14,16,2,6,
				          19,3,19,3,6,18,10,11,10,4,17,13,15,9,15,17,11,16,13,1,19,17,
				          19,17,10,2};
				int w[] = {327583,4194,990205,481090,868602,722789,547481,738569,188373,
				          973550,462208,74066,639614,693164,86808,442101,811939,995334,
				          551737,335601,147231,93330,799032,130164,839277,757103,234057,
				          909252,415269,945015,715797,549525,581349,130104,493780,553519,
				          755216,626951,743631,231151,205857,917585,553454,352015,873807,
				          573520,569698,317228,754891,875856};
				int v[] = {220468,844712,599675,53333,825995,711279,289092,415428,805292,
				          985205,197039,193974,95433,244829,558762,555423,725065,498922,
				          519543,4803,305565,61949};
				_expected = 64390854062526LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int w[] = ;
				int v[] = ;
				_expected = LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int w[] = ;
				int v[] = ;
				_expected = LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				int b[] = ;
				int w[] = ;
				int v[] = ;
				_expected = LL;
				_received = _obj.findMin(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
