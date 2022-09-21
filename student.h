#ifndef STUDENT_H
#define STUDENT_H

#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_BOARDS = 5;

class Student
{
 public:
	Student(); 													//student default constructor
	Student(string name);										//student constructor
    ~Student();                                                 //destructor
	void setStudentBoardPreference(string board, int value); 	//set Student Preferences for boards
	void setBoardStudentPreference(string board, int value); 	//set board preferences for student
    void setName(string name);
	void sort(); 												//sort the rankings to create the rankings vector
 private: 
    string name;                                                //student name
	map <string, int> studentRank; 					//A list of how the student ranks each of the boards
	map <string, int> boardRank;						//A list of how the boards rank the student
	vector <string> rankings; 									//A list of all the boards ranked best to worst for the student
	int boardSelection; 										//An int holding the index of the board in rankings for the current match
	static vector <pair<Student, string> > pairing;				//a list holding all the currently decided student board rankings
};

#endif
