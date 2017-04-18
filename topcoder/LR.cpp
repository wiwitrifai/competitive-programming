#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long C[N][N], tmp[N];

class LR {
public:
	string construct(vector<long long> s, vector<long long> t) {
		for (int i = 0; i < N; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
		int n = s.size();
		int m = -1, off = -1;
		long long biggest = 0;
		for (int i = 0; i < n; i++)
			if (t[i] > biggest) biggest = t[i];
		for (int i = 0; i < N && m == -1; i++) {
			long long bg = 0;
			for (int j = 0; j < n; j++) {
				tmp[j] = 0;
				for (int k = 0; k <= i; k++) {
					tmp[j] += C[i][k] * s[(j+k) % n];
				}
				bg = max(bg, tmp[j]);
			}
			if (bg > biggest) return "No solution";
			if (bg < biggest) continue;
			for (int k = 0; k < n && m == -1; k++) {
				if (t[0] != tmp[k]) continue;
				if (k != 0 && k+i < n) continue;
				bool ok = 1;
				for (int z = 0; z < n; z++) {
					if (t[z] != tmp[(k+z) % n]) {
						ok = 0;
						break;
					} 
				}
				if (ok) {
					m = i;
					off = k;
					break;
				}
			}
		}
		if (m == -1) return "No solution";
		int id = 0;
		string ans = "";
		while (m > 0 && id != off) {
			ans.push_back('L');
			id = (id+n-1) % n;
			m--;
		}
		while (m-- > 0)
			ans.push_back('R');
		return ans;
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
		cout << "Testing LR (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1492513205;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LR _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long s[] = {0,1,0,0,0};
				long long t[] = {0,1,2,1,0};
				_expected = "LL";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 1:
			{
				long long s[] = {0,0,0,1};
				long long t[] = {0,1,0,0};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 2:
			{
				long long s[] = {1,2,3,4,5,6,7,8,9,10};
				long long t[] = {12,24,56,95,12,78,0,100,54,88};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 3:
			{
				long long s[] = {1,0,0};
				long long t[] = {11,11,10};
				_expected = "RRRRR";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 4:
			{
				long long s[] = {1,1};
				long long t[] = {562949953421312,562949953421312};
				_expected = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 5:
			{
				long long s[] = {0,0,0,0,0};
				long long t[] = {0,0,0,1,0};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 6:
			{
				long long s[] = {123,456};
				long long t[] = {123,456};
				_expected = "";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			/*case 7:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}*/
			/*case 9:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
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
