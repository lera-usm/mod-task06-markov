#pragma once
#include <map>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef deque<string> prefix;
class textgen
{
	public: 
	textgen(const int col, vector<string> slova);
	string generate(int kol);
	map<prefix, vector<string>> get_table();
	private: 
	map<prefix, vector<string>> statetab;
	const int col=2;
};