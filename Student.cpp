#include "Student.h"
#include <cstring>

Student::Student(const char nFName[20], const char nLName[20], int nID, double nGPA) {
  firstName = new char[20];
  strcpy(firstName, nFName);

  lastName = new char[20];
  strcpy(lastName, nLName);

  ID = nID;

  GPA = nGPA;
}

Student::~Student() {
  delete firstName;
  delete lastName;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getID() {
  return ID;
}

double Student::getGPA() {
  return GPA;
}
