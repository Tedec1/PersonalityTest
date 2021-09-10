#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "personality_test.h"

using namespace std;

/* Load method
 * 1) Provided an istream object, read in each line and process them accordingly
 * 2) Ensure to see if the input is "correct" (do at least one simple check, like first character is a number)
 * Input: istream object
 * Output: Boolean
 */
bool personality_test::load(istream &in) {
    in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        string s;
        while(!in.eof()){
            getline(in,s);
            cout << s << endl;
            //TODO
        }
    cout << "called load" << endl;
    return false;
}
        
/* personality_test::printout method
 * 1) Printout the questions to ensure that the load method was written correctly
 * This part will not be graded, just for your own check
 */
void personality_test::printout() {
    //TODO
    cout << "called printout" << endl;
}

/* Run Test method
 * 1) Call proper methods in order to run the test
 * @param: None
 * @return: None, Text to Console
 */
void personality_test::run_test() {
    //Uncomment below as you comeplete them
    //Feel free to add any other methods to call

    //string output = analyzePersonality();
    //categorizeOutput(output);
}

/* Analyze Personality Method
 * 1) Ask user one question at a time
 * 2) Read in user's response and construct a vector containing the responses
 * 3) Analyze the responses to construct a personality type (eg. ENFJ)
 * @param None
 * @return string
 */
string personality_test::analyze_personality() {
    //TODO
    string output = "";
    return output;
}

/* Categorize Output Method
 * 1) Read in the analysis.txt file
 * 2) Provided a user's personality type, print out to console the user's personality description
 * @param Personality type string (eg. "ENFJ")
 * @return None, Text to console
 */
void personality_test::categorize_output(string my_personality) {
    //TODO
}

/* Save Output
 * 1) Ask user to save or not
 * 2) If yes, ask for a file name and save the results
 * @param string (the thing to write)
 * @return None, creates a file
 */
void personality_test::save_output(string output) {
    //TODO
}
