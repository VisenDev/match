#include "student.h"

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
