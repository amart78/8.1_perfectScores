/***************************************************************************************
8.1 PERFECT SCORES

This program reports the number of "perfect" scores (i.e., scores of 100) that
are provided by the user. The user may provide up to 20 integer test scores 
with values between 0 and 100.
****************************************************************************************/

#include <iostream>
#include <ios>      // Used to get `streamsize`.
#include <limits>   // Used to get `numeric limits`.
using namespace std;

int countPerfect(int scores[], int scoreCount);

int main (){
    int maxNumScores = 20;          // Maximum number of scores that can be accepted.
    int scores [maxNumScores];      // Holds scores provided by user.
    int scoreCount = 0;             // Holds number of scores provided by user.
    int score;                      // Holds the user-entered score value.
    
    cout << "\nEnter the scores for up to 20 tests. Scores may range from 0 to 100.\n";
    cout << "*** NOTE: To end the input session early, enter -1. ***\n\n";

    // Prompts user for inputs of `score` up to `maxNumScores` times.
    for (int i = 0; i < maxNumScores; i++){
        cout << "Test Score #" << i+1 << ": ";
        
        // Validates that the input is an integer within the acceptable range. 
        // Throws an error message, clears the input, & reprompts the user for a valid value, otherwise.
        while (!(cin >> score) || score < -1 || score > 100){
            cout << "ERROR: Please enter a score between 0 and 100 or -1 to end input session.";
            cout << "\nTest Score #" << i+1 << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Breaks out of the input session/for loop when user inputs -1
        if (score == -1){
            cout << "\n-1 entered. Input session ended with " << scoreCount << " scores accepted.\n";
            break;
        }

        scores[i] = score;      // Saves the valid input value in the `scores` array.
        scoreCount += 1;        // Tracks number of inputs entered by increasing by 1 after every valid input
    }
    
    // Calculates & displays the number of perfect scores entered
    cout << endl << countPerfect(scores, scoreCount) << " perfect scores were entered.";

}


// This function iterates through the `scores` array up to the number of inputs the user entered 
// (`scoreCount`), adding up & returning the number of values that are equal to 100 (a perfect score).
int countPerfect(int scores[], int scoreCount){
    int perfectScore = 100;
    int perfectScoreCount = 0;

    for (int i = 0; i < scoreCount; i++){
        if (scores[i] == perfectScore){
            perfectScoreCount += 1;
        }
    }
    return perfectScoreCount;
}
