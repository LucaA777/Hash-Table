#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>


class Student {
public:
	Student(const char nFName[20], const char nLName[20], int nID, double nGPA);
  	~Student();#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
 public:
  Student(const char nFName[20], const char nLName[20], int nID, double nGPA);
  ~Student();

  char* getFirstName();
  char* getLastName();
  int getID();
  double getGPA();

 private:
  char* firstName;
  char* lastName;
  int ID;
  double GPA;
};

#endif 

}
