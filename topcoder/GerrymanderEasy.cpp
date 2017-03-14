#include <bits/stdc++.h>

using namespace std;

class GerrymanderEasy {
public:
	double getmax(vector <int> A, vector <int> B, int K) {
		double ans = 0;
		int n = A.size();
		for (int i = 0; i < n; i++) {
			long long x = 0, y = 0;
			for (int j = i; j < n; j++) {
				x += B[j];
				y += A[j];
				if (j-i+1 >= K)
					ans = max(ans, (double)x/y);
			}
		}
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
		cout << "Testing GerrymanderEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489476731;
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
		GerrymanderEasy _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {5,1,2,7};
				int B[] = {4,0,2,2};
				int K = 2;
				_expected = 0.75;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
			}
			case 1:
			{
				int A[] = {12,34,56,78,90};
				int B[] = {1,1,1,1,1};
				int K = 1;
				_expected = 0.08333333333333333;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
			}
			case 2:
			{
				int A[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
				int B[] = {3,1,4,1,5,9,2,6,5,3};
				int K = 5;
				_expected = 5.4E-4;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
			}
			case 3:
			{
				int A[] = {123,4,46,88,22,34,564,87,56,311,886};
				int B[] = {0,0,0,0,0,0,0,0,0,0,0};
				int K = 1;
				_expected = 0.0;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
			}
			/*case 4:
			{
				int A[] = ;
				int B[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
			}*/
			/*case 5:
			{
				int A[] = ;
				int B[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), K); break;
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
