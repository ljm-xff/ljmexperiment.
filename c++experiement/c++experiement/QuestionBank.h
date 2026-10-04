#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include <string>
#include <vector>
#include "Triangle.h"
using namespace std;
class QuestionBank {
private:
    string bankName;
    int questionCount;
    vector<Triangle> questions;
    double totalScore;
    double averageScore;

public:
    QuestionBank(string name = "默认题库");

    string getName() const;
    int getCount() const;

    void addQuestion(const Triangle& t);
    bool deleteQuestion(int id);
    void queryQuestion(int id) const;
    void calculateStats();
    void showStats() const;
};

#endif
