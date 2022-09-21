#include <utility>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_BOARDS = 5;

class Student
{
 public:
	Student(); 													//student default constructor
	Student(string name);										//student constructor
	istream& readStudentRanksForBoards(istream& is);			//read in student ranks for the boards
	istream& readBoardRanksForStudent(istream& is);				//read in board ranks for the student
	void setStudentBoardPreference(string board, int value); 	//set Student Preferences for boards
	void setBoardStudentPreference(string board, int value); 	//set board preferences for student
	
 private: 
	vector<map <string, int>> studentRanks;
	vector<map <string, int>> boardRanks;
};

vector <Student> sList; //list of all the students
vector <string> bList; //list of all the boards

void initialize(){
	
	//initialize student list in vector
	for(int t = 0 ; t < NUM_STUDENTS; t++){
		string name;
		cin >> name;
		sList.push_back(Student(name));
	}
	
	//initialize list of board names
	for(int t = 0 ; t < NUM_BOARDS; t++){
		string name;
		cin >> name;
		bList.push_back(name);
	}
	
	//Intialize each student with their board preferences
	for(int t = 0; t < NUM_STUDENTS; t++){ //parse thru every student object
		for(int n = 0; n < NUM_BOARDS; n++){
			int rank;
			cin >> rank;
			sList[t].setStudentBoardPreference(bList[n], rank);
		}
	}
	
	//Read in board preferences for students
	for(int t = 0; t < NUM_BOARDS; t++){ //parse thru every student object
		for(int n = 0; n < NUM_STUDENTS; n++){
			int rank;
			cin >> rank;
			sList[n].setBoardPreference(bList[t], rank);
		}
	}

}
