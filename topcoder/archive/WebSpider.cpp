#include <bits/stdc++.h>

using namespace std;

void back(string & fold) {
	if (fold.empty())
		return;
	if (fold.back() == '/')
		fold.pop_back();
	while (!fold.empty() && fold.back() != '/')
		fold.pop_back();
}
vector<string> separate(string s) {
	string now = "";
	vector<string> res;
	for (char c : s) {
		if (c == '/') {
			res.push_back(now);
			now = "";
			continue;
		}
		now.push_back(c);
	}
	res.push_back(now);
	return res;
}

class WebSpider {
public:
	int countPages(vector <string> firstPass, vector <string> secondPass, vector <string> thirdPass) {
		set<string> ans;
		vector<string> folder;
		for (auto & str : firstPass) {
			ans.insert(str);
			string fold = str;
			back(fold);
			folder.push_back(fold); 
		}
		vector<string> newfolder;
		for (auto & str : secondPass) {
			stringstream ss(str);
			int num;
			string path;
			ss >> num >> path;
			string fold = folder[num];
			vector<string> parts = separate(path);
			for (string & s : parts) {
				if (s == "..")
					back(fold);
				else {
					fold += s;
					fold.push_back('/');
				}
			}
			fold.pop_back();
			ans.insert(fold);
			back(fold);
			newfolder.push_back(fold);
		}
		folder.swap(newfolder);
		newfolder.clear();
		for (auto & str : thirdPass) {
			stringstream ss(str);
			int num;
			string path;
			ss >> num >> path;
			string fold = folder[num];
			vector<string> parts = separate(path);
			for (string & s : parts) {
				if (s == "..")
					back(fold);
				else {
					fold += s;
					fold.push_back('/');
				}
			}
			fold.pop_back();
			ans.insert(fold);
			back(fold);
			newfolder.push_back(fold);
		}
		return (int)ans.size();
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
		cout << "Testing WebSpider (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1565455004;
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
		WebSpider _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string firstPass[] = {"home.htm", "sitemap.htm", "contact.htm", "support/login.jsp"};
				string secondPass[] = {"2 locations.htm", "3 ../home.htm"};
				string thirdPass[] = {"0 contact.htm"};
				_expected = 5;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 1:
			{
				string firstPass[] = {"index.html","products/all/INDEX.HTML","images/products/A101.GIF"};
				string secondPass[] = {"1 ../../index.html","1 ../../products"};
				string thirdPass[] = {};
				_expected = 4;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 2:
			{
				string firstPass[] = {".rc"};
				string secondPass[] = {};
				string thirdPass[] = {};
				_expected = 1;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 3:
			{
				string firstPass[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
				string secondPass[] = {"0 a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
				string thirdPass[] = {"0 ../a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a",
				                      "0 ..a/a",
				                      "0 a../a.."};
				_expected = 5;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 4:
			{
				string firstPass[] = {"abc/ccba","ab/cba","..a"};
				string secondPass[] = {"0 cba","1 ccba"};
				string thirdPass[] = {"0 cba","1 ccba"};
				_expected = 5;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 5:
			{
				string firstPass[] = {"a","ab/ab","ab/ab/abc","abc/abc"};
				string secondPass[] = {"0 ab/ab","1 ab","1 ../ab/ab","2 ../../ab/abc"};
				string thirdPass[] = {"0 ../ab/ab","2 ../abc/abc","1 ab/ab"};
				_expected = 6;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 6:
			{
				string firstPass[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"};
				string secondPass[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"};
				string thirdPass[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"};
				_expected = 1;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			case 7:
			{
				string firstPass[] = {"index.asp", "contact.asp", "about/index.asp", "users/support.asp",
				                      "company/executiveteam.asp", "products/catalog.asp"};
				string secondPass[] = {"1 index.asp", "1 requestinfo.asp", "2 ../index.asp", "2 history.asp",
				                      "3 ../index.asp", "3 helpdesk.asp", "4 ../index.asp", "4 boardofdirectors.asp",
				                      "4 location.asp", "5 ../index.asp", "5 new/index.asp",  "5 ../index.asp", "5 sale.asp"};
				string thirdPass[] = {"10 ../../index.asp", "11 products/index.asp", "11 products/catalog.asp"};
				_expected = 14;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}
			/*case 8:
			{
				string firstPass[] = ;
				string secondPass[] = ;
				string thirdPass[] = ;
				_expected = ;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string firstPass[] = ;
				string secondPass[] = ;
				string thirdPass[] = ;
				_expected = ;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string firstPass[] = ;
				string secondPass[] = ;
				string thirdPass[] = ;
				_expected = ;
				_received = _obj.countPages(vector <string>(firstPass, firstPass+sizeof(firstPass)/sizeof(string)), vector <string>(secondPass, secondPass+sizeof(secondPass)/sizeof(string)), vector <string>(thirdPass, thirdPass+sizeof(thirdPass)/sizeof(string))); break;
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
