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

int main (){
  return 0;
}
