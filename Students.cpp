#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int UNITS_REGISTERED = 8;
const int UNITS_MARKS = 8;

struct Students {
  string regno;
  string courseid;
  string unitsData[UNITS_REGISTERED][UNITS_MARKS];
  string firstname;
  string surname;
  string address;
};

// populate structure
void getData(Students &student){
  cout << "Enter student's registration number: ";
  cin >> student.regno;
  cout << "Enter student's course id: ";
  cin >> student.courseid;
  cout << "Enter student's first name: ";
  cin >> student.firstname;
  cout << "Enter student's surname: ";
  cin >> student.surname;
  cout << "Enter student's address: ";
  cin >> student.address;
  cout << "Enter student's units registered: \n";
    for (int i = 0; i < UNITS_REGISTERED; i++) {
      for (int j = 0; j < UNITS_MARKS; j++) {
        cin >> student.unitsData[i][j];
      }
    }
}

// display the detail of the student
void printStudent(Students &student){
  cout << "Student's registration number: " << student.regno << endl;
  cout << "Student's course id: " << student.courseid << endl;
  cout << "Student's first name: " << student.firstname << endl;
  cout << "Student's surname: " << student.surname << endl;
  cout << "Student's address: " << student.address << endl;
  cout << "Student's units registered: \n";
    for (int i = 0; i < UNITS_REGISTERED; i++) {
      for (int j = 0; j < UNITS_MARKS; j++) {
        cout << student.unitsData[i][j] << "\n ";
      }
      cout << endl;
    }
}

int main (){
  return 0;
}
