#include "textgen.h"
#include <iostream>;
#include <fstream>
#include "stream_reader.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin;
	fin.open("text.txt");

	vector<string> v=read_stream(fin);
	textgen t(2, v);
	string text = t.generate(5);
	cout << text;
}