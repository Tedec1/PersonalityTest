#ifndef _PERSONALITY_TEST_H
#define _PERSONALITY_TEST_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

// personality test class
class personality_test {
    public:
        bool load(istream&);
        void printout();
        void run_test();
        string analyze_personality();
        void categorize_output(string);
        void save_output(string);
        // Add anything you may need
        
    private:
        class question {
        public:
            int category_id;
            string question;
            string yes_answer;
            string no_answer;
        };
        list<question> questions;
};

#endif
