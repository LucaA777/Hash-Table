#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void printFilledHash(Node* hash, int hashSize);

int main() {

	int hashSize = 100;
	Node* hash[100] = {};

	while(true) {	

		char* str = new char[20];

		cout << "Enter up to 20 characters: " << endl;
		cin.get(str, 20);
		cin.get();

		int sum = 0;
		for (int i = 0; i < strlen(str); i++) {

			sum += (int)str[i];

		}	

		int index = sum % hashSize;

		//hash[index] = new Node(str);
	
		cout << endl << "Index: " << index << endl;
		
		printFilledHash(hash, hashSize);

	}

	return 0;
}

void printFilledHash(Node* hash, int hashSize) {
	cout << "Hash:" << endl;
	
	for (int i = 0; i < hashSize; i++) {

		if (hash[i] != NULL) {
			//cout << hash[i] << endl;
		}

	}

}
