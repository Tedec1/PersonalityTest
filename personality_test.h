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
    class type_info {
    public:
        type_info(string type, const string& rest_of_line);
        string personality;
        string category;
        string title;
        string desc;
    };
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
        bool run_test();
        string analyze_personality();
        void categorize_output(const string&);
        void save_output(type_info);
        // Add anything you may need
        void add_question(int id,const string& line);
    vector<question> questions;
    int amount_of_categories;
    vector<string> all_types;
private:
};

#endif
