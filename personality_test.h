#ifndef _PERSONALITY_TEST_H
#define _PERSONALITY_TEST_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>
//#include <list>

using namespace std;

// personality test class
class personality_test {
    public:
    class question {
    public:
        question(int id,const string& line);
        int category_id;
        string q;
        string yes_answer;
        string no_answer;
    };
        bool load(istream&);
        void printout();
        void run_test();
        string analyze_personality();
        void categorize_output(string);
        void save_output(string);
        // Add anything you may need
        void add_question(int id,const string& line);
    vector<question> questions;
    int amount_of_categories;
    vector<string> all_types;
private:
};

#endif
