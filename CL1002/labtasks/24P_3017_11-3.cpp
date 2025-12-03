#include <iostream>

using namespace std;

int main() 
{

    //Declaration of variables storing number of students and quizzes
    int students, Quiz;

    //Asking for number of students and quizzes
    cout << "Enter the number of students: ";
    cin >> students;
    cout << "Enter the number of quizzes: ";
    cin >> Quiz;

    //Declaration of 2D array for scores
    int scores[students][Quiz];
    int hscore = 0; // To keep track of the highest score

    //Asking the scores for each quiz
    for (int i = 0; i < students; i++) {
        cout<<"Enter scores for student"<<i+1<<": ";
        for (int j = 0; j < Quiz; j++) {
            cin >> scores[i][j];
            if (scores[i][j] > hscore) {
                hscore = scores[i][j];
            }
        }
    }

    //Calculating and displaying the average score for each quiz
    cout << endl;
    for (int j = 0; j < Quiz; j++) {
        int quizTotal = 0;
        for (int i = 0; i < students; i++) {
            quizTotal+=scores[i][j];
        }
        double quizAverage = static_cast<double>(quizTotal) / students;
        cout <<"Average score for quiz "<<j + 1<<": "<<quizAverage<< endl;
    }

    //Calculating and display the average score for each student
    cout << endl;
    double classTotal = 0;
    for (int i = 0; i < students; i++) {
        int studentTotal = 0;
        for (int j = 0; j < Quiz; j++) {
            studentTotal+=scores[i][j];
        }
        double studentAverage = static_cast<double>(studentTotal) / Quiz;
        cout <<"Average score for student "<<i+1<<": "<<studentAverage<< endl;
        classTotal += studentTotal; 
    }

    //Displaying the overall class average
    double totalaverage=classTotal/(students*Quiz);
    cout<<"\nOverall class average: "<<totalaverage<< endl;

    //Displaying the highest score achieved
    cout<<"Highest score achieved: "<<hscore<< endl;

}
