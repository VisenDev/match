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
	void setStudentBoardPreference(string board, int value); 	//set Student Preferences for boards
	void setBoardStudentPreference(string board, int value); 	//set board preferences for student
	void sort(); 												//sort the rankings to create the rankings vector
 private: 
	vector <map <string, int> > studentRank; 					//A list of how the student ranks each of the boards
	vector <map <string, int> > boardRank;						//A list of how the boards rank the student
	vector <string> rankings; 									//A list of all the boards ranked best to worst for the student
	int boardSelection; 										//An int holding the index of the board in rankings for the current match
	static vector <pair<Student, string> > pairing;				//a list holding all the currently decided student board rankings
};



vector <Student> sList; //list of all the students
vector <string> bList; //list of all the boards

//initializes all the data
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
			sList[n].setBoardStudentPreference(bList[t], rank);
		}
	}

}

int main(){
	initialize();

	return 0;
}
