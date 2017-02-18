#include <bits/stdc++.h>

using namespace std;

class Arrfix {
public:
	int mindiff(vector <int> A, vector <int> B, vector <int> F) {
		int n = A.size();
		vector < pair< int, int > > diff;
		vector< int > same;
		for (int i = 0; i < n; i++) {
			if (A[i] != B[i])
				diff.emplace_back(A[i], B[i]);
			else
				same.push_back(A[i]);
		}
		vector< int > f2;
		int cnt = diff.size(), cnt2 = 0;
		for (int j = 0; j < F.size(); j++) {
			bool ok = 0;
			for (int i = 0; i < diff.size(); i++) {
				if (F[j] == diff[i].second) {
					diff[i] = {-1, -1};
					cnt--;
					ok = 1;
					break;
				}
			}
			for (int i = 0; !ok && i < same.size(); i++) {
				if (F[j] == same[i]) {
					same[i] = -1;
					ok = 1;
					break;
				}
			}
			if (!ok) {
				cnt2++;
			}
		}
		cnt2 -= min(cnt2, cnt);
		int ans = cnt + cnt2;
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
		cout << "Testing Arrfix (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487339559;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Arrfix _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,1,1};
				int B[] = {2,2,2};
				int F[] = {2};
				_expected = 2;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,1,1};
				int B[] = {2,2,1};
				int F[] = {2,2};
				_expected = 0;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1,2,3};
				int B[] = {3,2,1};
				int F[] = {};
				_expected = 2;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {2,2,2};
				int B[] = {2,2,2};
				int F[] = {1,2,3};
				_expected = 2;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {1,3,3,3};
				int B[] = {2,3,3,3};
				int F[] = {2,2};
				_expected = 1;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				int B[] = ;
				int F[] = ;
				_expected = ;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int F[] = ;
				_expected = ;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int F[] = ;
				_expected = ;
				_received = _obj.mindiff(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(F, F+sizeof(F)/sizeof(int))); break;
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
