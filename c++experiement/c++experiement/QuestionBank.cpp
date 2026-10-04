#include "QuestionBank.h"
#include <iostream>
#include <iomanip>

using namespace std;

QuestionBank::QuestionBank(string name)
    : bankName(name), questionCount(0), totalScore(0), averageScore(0) {
}

string QuestionBank::getName() const { return bankName; }
int QuestionBank::getCount() const { return questionCount; }

void QuestionBank::addQuestion(const Triangle& t) {
    questions.push_back(t);
    questionCount++;
}

bool QuestionBank::deleteQuestion(int id) {
    for (auto it = questions.begin(); it != questions.end(); ++it) {
        if (it->getId() == id) {
            questions.erase(it);
            questionCount--;
            return true;
        }
    }
    return false;
}

void QuestionBank::queryQuestion(int id) const {
    for (const auto& t : questions) {
        if (t.getId() == id) {
            t.display();
            return;
        }
    }
    cout << "未找到编号为 " << id << " 的题目" << endl;
}

void QuestionBank::calculateStats() {
    if (questionCount == 0) {
        averageScore = 0;
        totalScore = 0;
        return;
    }

    int correctCount = 0;
    for (const auto& t : questions) {
        if (t.isCorrect()) correctCount++;
    }

    totalScore = correctCount;
    averageScore = (static_cast<double>(correctCount) / questionCount) * 100.0;
}

void QuestionBank::showStats() const {
    cout << "\n========== 题库统计 ==========" << endl;
    cout << "题库名称: " << bankName << endl;
    cout << "题目总数: " << questionCount << endl;
    cout << "答对题数: " << totalScore << endl;
    cout << "平均得分率: " << fixed << setprecision(2) << averageScore << "%" << endl;
    cout << "==============================" << endl;
}
