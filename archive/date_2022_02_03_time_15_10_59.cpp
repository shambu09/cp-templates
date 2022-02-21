#include<bits/stdc++.h>

using namespace std;
int main(){
	int temp0 = 10;
	int temp1 = 12;
	int temp2 = 14;

	auto i = {temp0, temp1, temp2};
	cout << *i.begin() << endl;
	cout << temp0 << endl;

	temp0 = 20;
	
	cout << *i.begin() << endl;
	cout << temp0 << endl;

	return 0;
}