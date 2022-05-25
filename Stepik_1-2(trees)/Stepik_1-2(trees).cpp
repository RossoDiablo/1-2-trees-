// Stepik_1-2(trees).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int max (int a, int b) { return a > b ? a : b; }


 int height (int *parent, const int n) {
	int res = 0;
	for (int i = 0; i < n; i++) { 
		int p = i, current = 1;
		while (parent[p] != -1) {
			current++;
			p = parent[p];
		}
		res = max(res,current);
	}
	return res;
}

 void ConvertStrToInt(string str, int *arr) {
	int j = 0;
	string temp;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			temp = temp + str[i];
		}
		else {
			arr[j] = stoi(temp);
			j++;
			temp.clear();
		}
	}	
	arr[j] = stoi(temp);
 };



int _tmain(int argc, _TCHAR* argv[])
{
	string number, parents;
	getline(cin,number);
	getline(cin,parents);

	int numb = stoi(number);

	int *parents_int = new int[numb];
	ConvertStrToInt(parents, parents_int);

	cout << height(parents_int,numb);
	delete [] parents_int;
	return 0;
}

