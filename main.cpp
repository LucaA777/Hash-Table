#include <iostream>
#include <cstring>

using namespace std;

int main() {
	cout << "Hello world." << endl;

	char* str = new char[20];

	cout << "Enter up to 20 characters: " << endl;
	cin.get(str, 20);
	cin.get();

	int sum = 0;
	for (int i = 0; i < strlen(str); i++) {

		sum += (int)str[i];

	}

	int index = sum % 100;

	cout << "Index: " << index << endl;

	return 0;
}
