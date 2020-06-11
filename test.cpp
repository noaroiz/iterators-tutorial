#include "alg.h"
#include<iterator>
#include<iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv) 
{
	int ia2[] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> tmp(100);
	std::vector<int>::iterator it = transform(begin(ia2), end(ia2), tmp.begin(), [](const int x, const int y){return x + y; });
	cout << *it << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << *(tmp.begin()+i) << endl;
	}




}
