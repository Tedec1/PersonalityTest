#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "personality_test.h"
#include <regex>
#include <stdexcept>

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
        int i = 0;
        int numOfQuestions;
        while(!in.eof()){
            getline(in,s);
            if(i == 0){
                numOfQuestions = stoi(s.substr(0,s.find(' ')));
                i++;
                continue;
            }
            regex test("([0-9]+ [A-z] [A-z] .+)");
            if(regex_match(s,test)){
                add_question(stoi(s.substr(0,s.find(' '))),s.substr(s.find(' ') + 1));
            }
            i++;
        } 
    if (questions.empty()) return false;
    cout << "questions loaded" << endl;
    if(questions.size() == numOfQuestions){
        return true;
    } else return false;
}
        
/* personality_test::printout method
 * 1) Printout the questions to ensure that the load method was written correctly
 * This part will not be graded, just for your own check
 */

personality_test::question::question(int id, const string& line) {
    category_id = id;
    int pos = 0;
    yes_answer = line.substr(pos,line.find(' '));
    pos = line.find(' ',pos) + 1;
    no_answer = line.substr(pos,line.find(' '));
    pos = line.find(' ',pos) + 1;
    q = line.substr(pos);
}
void personality_test::add_question(int id, const string& line) {
    if(id > amount_of_categories){
        amount_of_categories = id;
    }
    auto* a = new question(id,line);
    questions.push_back(*a);
    if(!all_types.empty()){
        for (const string& t: all_types) {
            if(t == a->no_answer || t == a->yes_answer){
                return;
            }
        }
        all_types.push_back(a->yes_answer);
        all_types.push_back(a->no_answer);
    } else {
        all_types.push_back(a->yes_answer);
        all_types.push_back(a->no_answer);
    }
}


void personality_test::printout() {
    for(const question& q: questions){
        cout << "cat_id: "<< q.category_id << endl;
        cout << "yes_answer: "<< q.yes_answer << endl;
        cout << "no_answer: "<< q.no_answer << endl;
        cout << "question: "<< q.q << "\n\n";
    }
    cout << "called printout" << endl;
}

/* Run Test method
 * 1) Call proper methods in order to run the test
 * @param: None
 * @return: None, Text to Console
 */
bool valid_response(string& s){
    const vector<string> yes_tests = {"Y", "y", "yes", "Yes", "YES"};
    const vector<string> no_tests = { "N", "n", "no", "No", "NO"};
    for (const string& test:yes_tests) {
        if(s == test){
            return true;
        }
    }
    for (const string& test:no_tests) {
        if(s == test){
            return false;
        }
    }
    throw runtime_error("Sorry, I didn't recognize your input, please type again");
}

bool personality_test::run_test() {
    //Uncomment below as you complete them
    //Feel free to add any other methods to call

    string output = analyze_personality();
    categorize_output(output);
    string res;
    res.clear();
    cout << "Would you like to play again?";
    while(res.empty()){
        try {
            cin >> res;
            if(valid_response(res)){
                return true;
            } else {
                return false;
            }
        } catch (runtime_error &e){
            cout << e.what() << endl;
            res.clear();
        }
    }
    return false;
}



/* Analyze Personality Method
 * 1) Ask user one question at a time
 * 2) Read in user's response and construct a vector containing the responses
 * 3) Analyze the responses to construct a personality type (eg. ENFJ)
 * @param None
 * @return string
 */
string personality_test::analyze_personality() {
    string response;
    map<string,int> types;
    for (const string& t:all_types) {
        types.insert(pair<string,int>(t,0));
    }
    for (const question& q:questions) {
        cout << q.q + "\n";
        while(response.empty()){
            cin >> response;
            try {
                if(valid_response(response)){
                    types.at(q.yes_answer) += 1;
                } else {
                    types.at(q.no_answer) += 1;
                }
            } catch (runtime_error& e) {
                cout << e.what() << endl;
                response.clear();
            }
        }
        response.clear();
    }
    string output;
    output += types.at("I") > types.at("E") ? "I" : "E";
    output += types.at("N") > types.at("S") ? "N" : "S";
    output += types.at("T") > types.at("F") ? "T" : "F";
    output += types.at("P") > types.at("J") ? "P" : "J";
    return output;
}

/* Categorize Output Method
 * 1) Read in the analysis.txt file
 * 2) Provided a user's personality type, print out to console the user's personality description
 * @param Personality type string (eg. "ENFJ")
 * @return None, Text to console
 */
personality_test::type_info::type_info(string type, const string& rest_of_line) {
    int pos = 0;
    personality = type;
    category = rest_of_line.substr(pos,rest_of_line.find(' '));
    pos = rest_of_line.find(' ',pos) + 1;
    title = rest_of_line.substr(pos,rest_of_line.find(' ') + 1);
    pos = rest_of_line.find(' ',pos) + 1;
    desc = rest_of_line.substr(pos);
}

void personality_test::categorize_output(const string& my_personality) {
    map<string,string> full_type_def;
    string s;
    bool a = true;
    while (a) {
        string fileName;
        cout << endl;
        cout << "Please enter the analysis file name, e.g., \"analysis.txt\": ";
        cin >> fileName;
        ifstream fin;
        fin.exceptions(ifstream::failbit | ifstream::badbit);
        try {
            fin.open(fileName);
            int i = 0;
            while(!fin.eof()){
                if(i == 17){
                    break;
                }
                getline(fin,s);
                if(i == 0){
                    i++;
                    continue;
                }
                full_type_def.insert(pair<string,string>(s.substr(0,s.find(' ')),s.substr(s.find(' ') + 1)));
                i++;
            }
            a = false;
            fin.close();
        } catch (ifstream::failure &e) {
            cout << endl;
            cout << "error opening file: \"" << fileName << "\" " << endl;
            a = true;
        } catch (runtime_error &e){
            cout << e.what() << endl;
            a = true;
        } catch (exception &e){
            cout << e.what() << endl;
            a = true;
        }
    }

    type_info result(my_personality,full_type_def.at(my_personality));
    cout << "===============\n";
    cout << "Your personality type is: " << result.personality << endl;
    cout << "The category is: " << result.category << endl;
    cout << "You are: The "<<  result.title << endl;
    cout << "Description: " << result.desc << endl;
    cout << "===============\n";
    cout << "Would you like to save? \n";
    string res;
    while(res.empty()){
        try {
            cin >> res;
            if(valid_response(res)){
                save_output(result);
            } else {
                return;
            }
        } catch (runtime_error &e){
            cout << e.what() << endl;
            res.clear();
        }
    }
}

/* Save Output
 * 1) Ask user to save or not
 * 2) If yes, ask for a file name and save the results
 * @param string (the thing to write)
 * @return None, creates a file
 */
void personality_test::save_output(type_info output) {

    try {
        cout << "Please enter a file name \n";
        string res;
        cin >> res;
        ofstream of(res);
        string to_file = "Your personality type is: " + output.personality + "\n" + "The category is: " + output.category + "\n" + "You are: The " + output.title + "\n" + "Description: " + output.desc;
        of << to_file;
        of.close();
    } catch (ifstream::failure &e) {
        cout << "file was not saved";
    } catch (runtime_error &e){
        cout << e.what() << endl;
    } catch (exception &e){
        cout << e.what() << endl;
    }
}
