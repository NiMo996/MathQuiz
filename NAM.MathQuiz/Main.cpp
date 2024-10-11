
// Math Quiz Assignment: Week 6
// Nick Moede

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Function to check if a file exists and create it if not
void checkAndCreateDFile(const string& filePath) {
	ifstream ifs(filePath);
	if (!ifs) {  // If the file does not exist
		cout << "File not found: " << filePath << ". Creating file..." << endl;
		ofstream ofs(filePath);  // Create the file
		if (ofs) {
			cout << "File created successfully: " << filePath << endl;
		}
		else {
			cout << "Failed to create the file: " << filePath << endl;
		}
		ofs.close();
	}
	ifs.close();
}
// Function to check if a file exists and create it with default math problems if not
void checkAndCreateAFile(const string& assignmentPath) {
	ifstream ifs(assignmentPath);
	if (!ifs) {  // If the file does not exist
		cout << "File not found: " << assignmentPath << ". Creating file with default math problems..." << endl;
		ofstream ofs(assignmentPath);  // Create the file
		if (ofs) {
			// Write default math problems into the file
			ofs << "1 + 1\n";
			ofs << "2 * 3\n";
			ofs << "4 / 2\n";
			ofs << "5 - 3\n";
			ofs << "6 + 4\n";
			ofs << "8 * 2\n";
			ofs << "10 / 5\n";
			ofs << "7 - 2\n";
			ofs << "9 + 1\n";
			ofs << "3 * 5\n";
			cout << "File created successfully with default math problems: " << assignmentPath << endl;
		}
		else {
			cout << "Failed to create the file: " << assignmentPath << endl;
		}
		ofs.close();
	}
	ifs.close();
}


int main()
{
	

	string line;
	float answer;

	//vector initialization
	vector<float> answers; //vector to store the answers as they are entered
	vector<string> problems; //vector to store the problems from the file
	vector<string> selectedProblems; //vector to store the selected problems from the file

	//read the problems from the file
	string assignmentPath = "AssignRandomProblems.txt";  // Relative path
	string filePath = "QuizResults.txt";  // Relative path

	checkAndCreateAFile(assignmentPath);

	ifstream ifs(assignmentPath);
	
	if (!ifs) {
		cout << "Error: Failed to open the problems file!" << endl;
		return 1;
	}

	//read the problems from the file and store them in the vector called problems
	while (getline(ifs, line))
	{
		problems.push_back(line);
		
	}
	//close the file
	ifs.close();
	srand(time(NULL)); //initialize the random number generator and seed it with the current time
	cout << "Welcome to the Math Quiz" << endl;
	//display the problems
	for (int i = 0; i < 3; i++)
	{
		int randomNumber = rand() % problems.size(); //generate a random number between 0 and the size of the vector
		selectedProblems.push_back(problems[randomNumber]); //store the selected problem in the vector called selectedProblems
		cout << "Question " << i + 1 << ": " << problems[randomNumber] << " = "; //display the problem
		cin >> answer; //get the answer from the user
		answers.push_back(answer); //store the answer in the vector called answers
		//debugging option below to see if the answer is stored correctly
		//cout << "You entered: " << answer << endl;
		
	}
	cout << endl;

	//store the answers in filePath(QuizResults.txt)
	checkAndCreateDFile(filePath);
	ofstream ofs(filePath);
	if (!ofs.is_open()) {
		cout << "Error: Could not open " << filePath << " for writing!" << endl;
		return 1;
	}
	//write the answers to the file
	ofs << "The answers are: " << endl;
	for (int i = 0; i < 3; i++)
	{
		ofs << "Question " << i + 1 << ": " << selectedProblems[i] << " = " << answers[i] << endl;
	}
	//close the file
	ofs.flush();
	ofs.close();

	if (!ofs) {
		cout << "Error: Failed to write to " << filePath << endl;
	}
	else {
		cout << "Results saved to " << filePath << endl;
	}

	(void)_getch();
	return 0;
}
