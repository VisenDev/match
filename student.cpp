#include <student.h>

Student::Student() : Student("John Doe"){} 												//student default constructor

Student::Student(string name){										//student constructor
    setName(name);
}

void Student::setStudentBoardPreference(string board, int rank){ 	//set Student Preferences for boards
    studentRank[board] = rank;
}

void Student::setBoardStudentPreference(string board, int rank){ 	//set board preferences for student
    boardRank[board] = rank;
}

void Student::setName(string n){                                 //set student name
    name = n;
}

void Student::sort(){ 												//sort the rankings to create the rankings vector

}