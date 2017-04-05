#include <bits/stdc++.h>

using namespace std;

int cnt[3][3];

bool ok[1 << 18][3][3];

class LCMGCD {
public:
	string isPossible(vector <int> x, int t) {
		int p2 = 0, p3 = 0;
		while ((t % 2) == 0) p2++, t /= 2;
		while ((t % 3) == 0) p3++, t /= 3;
		memset(cnt, 0, sizeof cnt);
		for (int v : x) {
			int q2 = 0, q3 = 0;
			while ((v % 2) == 0) q2++, v /= 2;
			while ((v % 3) == 0) q3++, v /= 3;
			if (q2 < p2) q2 = 0;
			else if (q2 == p2) q2 = 1;
			else q2 = 2;
			if (q3 < p3) q3 = 0;
			else if (q3 == p3) q3 = 1;
			else q3 = 2;
			cnt[q2][q3]++;
		}
		vector< pair< int, int > > vp;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < min(2, cnt[i][j]); k++)
					vp.emplace_back(i, j);
		memset(ok, 0, sizeof ok);
		for (int i = 0; i < vp.size(); i++)
			ok[1<<i][vp[i].first][vp[i].second] = 1;
		for (int mask = 0; mask < (1<<vp.size()); mask++) {
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					if (!ok[mask][i][j]) continue;
					for (int k = 0; k < vp.size(); k++) {
						if (mask & (1<<k)) continue;
						int nmask = mask | (1<<k);
						ok[nmask][max(i, vp[k].first)][max(j, vp[k].second)] = 1;
						ok[nmask][min(i, vp[k].first)][min(j, vp[k].second)] = 1;
					}
				}
		}
		return ok[(1<<vp.size())-1][1][1] ? "Possible" : "Impossible";
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
		cout << "Testing LCMGCD (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491287943;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LCMGCD _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {2,3};
				int t = 6;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 1:
			{
				int x[] = {4,9};
				int t = 6;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 2:
			{
				int x[] = {6,12,24,18,36,72,54,108,216};
				int t = 36;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 3:
			{
				int x[] = {6,27,81,729};
				int t = 6;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 4:
			{
				int x[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int t = 1;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 5:
			{
				int x[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27};
				int t = 72;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 6:
			{
				int x[] = {100663296, 544195584, 229582512, 59049};
				int t = 60466176;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 7:
			{
				int x[] = {2,4,8,16,32,64};
				int t = 256;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			/*case 8:
			{
				int x[] = ;
				int t = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}*/
			/*case 9:
			{
				int x[] = ;
				int t = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}*/
			/*case 10:
			{
				int x[] = ;
				int t = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
