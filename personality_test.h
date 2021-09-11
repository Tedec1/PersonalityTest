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
        question(int id,string line){
            category_id = id;
            stringstream ss;

            q = line;

            //TODO
        }
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
        void add_question(int id,string line){
            auto* a = new question(id,line);
            questions.push_back(*a);
        }
    vector<question> questions;
    private:


};

#endif
