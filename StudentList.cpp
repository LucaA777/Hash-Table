/*
   This is an updated version of the student list project describe below that implements a hash table over a linked list or vectors.

   This program serves as a database for students. The user may addand remove students, as well as see the complete list of students they've entered. Each student has a first and last name, as well as an ID number and a GPA (0.0-5.0).

Author: Luca Ardanaz
Last Updated: 9/26/2025
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include "Node.h"
#include "Student.h"

using namespace std;

void addStudent(Node** &hash, int hashSize);
void removeStudent(Node** &hash, int hashSize);
void cinReset();

void printFilledHash(Node** hash, int hashSize);
void printNodeChain(Node* node);
void insertNodeInChain(Node* &node, Node* &newNode);
int calculateIndex(char* str, int hashSize);

void removeStudentByID(int ID, Node* previous, Node* current, Node* &head);

Node* generateRandomStudent();


int main() {



	int hashSize = 100;
	Node** hash = new Node*[hashSize];
	char input[20];

	//This loop will run until the user enters "QUIT"
	do {
		//ask for user input
		cout << endl << endl << endl << "Enter command (type \"HELP\" for all commands):" << endl; 
		cin.get(input, 20);
		cinReset();

		cout << endl;

		if (strcmp(input, "HELP") == 0) {
			//show all the valid commands
			cout << "List of commands:" << endl;
			cout << " - ADD: Add a new student to the database." << endl;
			cout << " - PRINT: Prints out all of the students in the database." << endl;
			cout << " - DELETE: Remove a student from the database." << endl;
			cout << " - AVERAGE: Calculates the average GPA of all the students." << endl;
			cout << " - QUIT: Close the program" << endl;
		}
		else if (strcmp(input, "ADD") == 0) {
			//add a student
			addStudent(hash, hashSize);
		}
		else if (strcmp(input, "PRINT") == 0) {
			//show the complete list of students
			printFilledHash(hash, hashSize);
		}
		else if (strcmp(input, "DELETE") == 0) {
			//remove a student
			removeStudent(hash, hashSize);
		}

	} while (strcmp(input, "QUIT") != 0);

	cout << "Ending program." << endl;


	return 0;
}

void addStudent(Node** &hash, int hashSize) {

	char* firstName = new char[20];
	char* lastName = new char[20];
	int ID = 0;
	double GPA = 0;

	//asks for first name
	cout <<"Adding a new student..." << endl;
	cout << "Enter first name:" << endl;
	cin.get(firstName, 20);
	cin.get();

	//asks for last name
	cout << "Enter last name:" << endl;
	cin.get(lastName, 20);
	cin.get();

	//gets student id and verifies that its valid
	do {
		if (cin.fail()) {
			cinReset();

		}
		cout << "Enter student ID:" << endl;
		cin >> ID;
	} while (cin.fail() || ID <= 0);


	//gets student GPA and verifies its valid
	do {
		if (cin.fail()) {
			cinReset();

		}
		cout << "Enter GPA:" << endl;
		cin >> GPA;
	} while (cin.fail() || GPA < 0 || GPA > 5.0);

	cinReset();

	//adds student to hash table
	Node* newStudent = new Node(new Student(firstName, lastName, ID, GPA));
	
	insertNodeInChain(hash[calculateIndex(lastName, hashSize)], newStudent);
}



void removeStudent(Node** &hash, int hashSize) {

	//asks for ID and saves it
	//keeps asking till it gets an int
	int id = 0;
	do {
		if (cin.fail()) {
			cinReset();
		}
		cout << "Enter the student ID of the student to remove:" << endl;
		cin >> id;
	} while (cin.fail());

	cinReset();

	//go through the hash table and delete all matches
	for (int i = 0; i < hashSize; i++) {
		if (hash[i] != NULL) {
			removeStudentByID(id, NULL, hash[i], hash[i]);
		}
	}
}

void removeStudentByID(int ID, Node* previous, Node* current, Node* &head) {
	//if the list is empty, return
	if (head == NULL) {
		return;
	}

	//checks if the current node matches
	if (current -> getStudent() -> getID() == ID) {
		//head deletion case
		if (current == head) {
			head = current -> getNext();
		}

		//tail deletion case
		else if (current -> getNext() == NULL) {
			previous -> setNext(NULL);
		}

		//body deletion case
		else {
			previous -> setNext(current -> getNext());
		}

		delete current;
		return;
	}

	//if the node isn't the last one, continue search
	if (current -> getNext() != NULL) {
		removeStudentByID(ID, current, current -> getNext(), head);
	}


}


//this clears all errors with cin so that cin always works as expected.
void cinReset() {
	cin.clear();
	cin.ignore(10000, '\n');
}


void printFilledHash(Node** hash, int hashSize) {
	cout << "Hash:" << endl;

	//go through each slot in hash table
	for (int i = 0; i < hashSize; i++) {
		//if the slot is not empty, print its values
		if (hash[i] != NULL) {
			cout << i;
			printNodeChain(hash[i]);
			cout << endl;
		}
	}
}

void printNodeChain(Node* node) {
	//print out current node
	cout << " -> ";
	cout << node -> getStudent() -> getFirstName();
	cout << " ";
	cout << node -> getStudent() -> getLastName();
	cout << ", "; 
	cout << node -> getStudent() -> getID(); 
	cout << ", ";
	cout << fixed << setprecision(2) << node -> getStudent() -> getGPA() << endl;


	//if there are more nodes, keep going
	if (node -> getNext() != NULL) {
		printNodeChain(node -> getNext());
	}
}

void insertNodeInChain(Node* &node, Node* &newNode) {
	//if the node chain is empty, make new head
	if (node == NULL) {
		node = newNode;
	}

	//if the next node exists, keep ging down the chain
	else if (node -> getNext() != NULL) {
		Node* nextNode = node -> getNext();
		insertNodeInChain(nextNode, newNode);
	}

	//if this is the last node, add new node as next
	else {
		node -> setNext(newNode);
	}
}

int calculateIndex(char* str, int hashSize) {
	int sum = 0;

	for (int i = 0;  i < strlen(str); i++) {
		sum += (int)str[i];
	}

	return sum % hashSize;
}

Node* generateRandomStudent() {
	//read files for name generator
	ifstream firstNames("first_names.txt");
	ifstream lastNames("last_names.txt");

	srand(time(0));
	
	int firstNamesSize = 4945;	
	int lastNamesSize = 21985;

	int firstIndex = (rand() % firstNamesSize) + 1;
	int lastIndex = (rand() % lastNamesSize) + 1;

	char* firstName;
	for (int i = 0; i < firstIndex; i++) {
		getLine(firstNames, firstName);
	}	

	char* lastName;
	for (int i = 0; i < lastIndex; i++) {
		getLine(lastNames, lastName);
	}

}
