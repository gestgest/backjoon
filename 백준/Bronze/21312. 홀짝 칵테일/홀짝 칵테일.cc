#include <iostream>

using namespace std;

int main() {
	bool isOdd = false;
	int num;
	int oddSum = 1;
	int EvenSum = 1;
	for (int i = 0; i < 3; i++)
	{
		cin >> num;
		if (num % 2 == 1) {
			isOdd = true;
			oddSum *= num;
		}
		else if(num % 2 == 0) {
			EvenSum *= num;
		}
	}
	if (isOdd == false) {
		cout << EvenSum << '\n';
		return 0;
	}
	else {
		cout << oddSum << '\n';
		return 0;
	}
}