#include "textgen.h"

textgen::textgen(const int col, vector<string> slova)
{
	this->col=col;
	prefix p;
	for (int i=0; i<col; i++)
	{
		p.push_back(slova[i]);
	}
	for (int i=col; i<slova.size();i++)
	{
		 statetab[p].push_back(slova[i]);
		 p.pop_front();
		 p.push_back(slova[i]);
	}
	statetab[p].push_back(".");
}
string textgen::generate(int kol)
{
	srand(time(nullptr));
	string text="";
	prefix p;
	p=statetab.begin()->first;
	int pos;
	for (int i=0; i<p.size(); i++)
	{
		text+=p[i]+" ";
	}
	for (int i=p.size(); i<kol;i++)
	{
		pos=rand()%statetab[p].size();
		text+=statetab[p][pos]+" ";
		if(statetab[p][pos]==".")
		{
			break;
		}
		p.push_back(statetab[p][pos]);
		p.pop_front();
	}
}
map<prefix, vector<string>> textgen::get_table()
{
	return statetab;
}