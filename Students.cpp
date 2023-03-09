#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int UNITS_REGISTERED = 8;
const int UNITS_MARKS = 8;

struct Students {
  string regno;
  string courseid;
  string unitsRegistered[UNITS_REGISTERED];
  int unitsMarks[UNITS_MARKS];
  // string unitsData[UNITS_REGISTERED][UNITS_MARKS];
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
      getline(cin, student.unitsRegistered[i]);
    }
  cout << "Enter student's units marks according to the order of units registered: \n";
    for (int i = 0; i < UNITS_MARKS; i++) {
        cin >> student.unitsMarks[i];
    }
    // for (int i = 0; i < UNITS_REGISTERED; i++) {
    //   for (int j = 0; j < UNITS_MARKS; j++) {
    //     cin >> student.unitsData[i][j];
    //   }
    // }
}

// display the detail of the student
void printStudent(Students &student){
  cout << "Student's registration number: " << student.regno << endl;
  cout << "Student's course id: " << student.courseid << endl;
  cout << "Student's first name: " << student.firstname << endl;
  cout << "Student's surname: " << student.surname << endl;
  cout << "Student's address: " << student.address << endl;
  // cout << "Student's units registered: \n";
  //   for (int i = 0; i < UNITS_REGISTERED; i++) {
  //     cout << student.unitsRegistered[i] << endl;
  //   }
  cout << "Student's units marks: \n";
  //   for (int i = 0; i < UNITS_MARKS; i++) {
  //     cout << student.unitsMarks[i] << endl;
  //   }

    for (int i=0, j=0; i < UNITS_REGISTERED && j < UNITS_MARKS; i++) {
      if (i > -1 && i != j) {
          j = i;
      }
      if(i==j){
        cout << student.unitsRegistered[i] << " --> " << student.unitsMarks[j] << "\n ";
      }
    }
  // cout << "Student's units data: \n";
  //   for (int i = 0; i < UNITS_REGISTERED; i++) {
  //     for (int j = 0; j < UNITS_MARKS; j++) {
  //       cout << student.unitsRegistered[i] << " " << student.unitsMarks[j] << "\n ";
  //     }
  //     cout << endl;
  //   }
}

// compute the grade of the student
char computeGrade(int mark){
  if (mark >= 70) {
    return 'A';
  } else if (mark >= 60) {
    return 'B';
  } else if (mark >= 50) {
    return 'C';
  } else if (mark >= 40) {
    return 'D';
  } else {
    return 'F';
  }
}

// computes the mean of the student
float computeMean(int marks[],int size = UNITS_MARKS){
  int sum = 0;
  // int size = sizeof(marks) / sizeof(int);
  for (int i = 0; i < size; i++) {
    sum += marks[i];
  }
  return sum / size;
}

float computeStandardDeviation(const Students students[], int numStudents, float mean) {
    float variance = 0;
    for (int i = 0; i < numStudents; i++) {
        float studentTotal = 0;
        for (int j = 0; j < UNITS_MARKS; j++) {
            studentTotal += students[i].unitsMarks[j];
        }
        float studentMean = studentTotal / UNITS_MARKS;
        variance += pow(studentMean - mean, 2);
    }
    variance /= numStudents;
    return sqrt(variance);
}

int main (){
  const int STUDENTS = 3;
  Students student[STUDENTS];
  int studentsMean[STUDENTS];
  for (int i = 0; i < STUDENTS; i++) {
    getData(student[i]);
  }
  // for (int i = 0; i < STUDENTS; i++) {
  //   printStudent(student[i]);
  // }
  // for (int i = 0; i < STUDENTS; i++) {
  //   cout << "Student's mean: " << computeMean(student[i].unitsMarks) << endl;
  // }
  for (int i = 0; i < STUDENTS; i++) {
    studentsMean[i]= computeMean(student[i].unitsMarks) ;
  }
  float mean = computeMean(studentsMean, STUDENTS);
  cout << "Class mean: " << mean << endl;
  cout << "Class standard deviation: " << computeStandardDeviation(student, STUDENTS, mean) << endl;
  cout << "Highest mark: " << *max_element(studentsMean, studentsMean + STUDENTS) << endl;
  cout << "Lowest mark: " << *min_element(studentsMean, studentsMean + STUDENTS) << endl;

  // for (int i = 0; i < STUDENTS; i++) {
  //   cout << "Student's grade: " << computeGrade(computeMean(student[i].unitsMarks)) << endl;
  // }
  return 0;
}
