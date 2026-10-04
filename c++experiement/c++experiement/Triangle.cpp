#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

bool Triangle::isValid() const {
    return (a > 0 && b > 0 && c > 0) &&
        (a + b > c) && (a + c > b) && (b + c > a);
}

string Triangle::getTypeStr() const {
    if (!isValid()) return "非三角形";
    if (a == b && b == c) return "等边三角形";
    if (a == b || b == c || a == c) return "等腰三角形";
    double aa = a * a, bb = b * b, cc = c * c;
    if (abs(aa + bb - cc) < 0.0001 || abs(aa + cc - bb) < 0.0001 || abs(bb + cc - aa) < 0.0001)
        return "直角三角形";
    return "普通三角形";
}

// 构造函数
Triangle::Triangle(int id, double a, double b, double c)
    : id(id), a(a), b(b), c(c), userAns(""), correctAns("") {
    calculateCorrectAns();
}

// 修改边长 
void Triangle::setSides(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
    // BUG: 修改边长后未调用 calculateCorrectAns()，标准答案不会更新
    // calculateCorrectAns(); // 边长改变后，重新计算正确答案
}

int Triangle::getId() const { return id; }

double Triangle::getArea() const {
    if (!isValid()) return 0;
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::getPerimeter() const { return a + b + c; }

void Triangle::calculateCorrectAns() {
    if (isValid()) {
        double area = getArea();
        ostringstream oss;
        oss << fixed << setprecision(2) << area;
        correctAns = oss.str();
    }
    else {
        correctAns = "无效三角形";
    }
}

void Triangle::inputUserAns(const string& ans) {
    userAns = ans;
}

bool Triangle::isCorrect() const {
    return userAns == correctAns;
}

void Triangle::display() const {
    
    cout << "题目编号: " << id << endl;
    cout << "三边长度: a=" << a << ", b=" << b << ", c=" << c << endl;
    cout << "三角形类型: " << getTypeStr() << endl;
    cout << "周长: " << getPerimeter() << endl;
    cout << "正确答案(面积): " << correctAns << endl;
    cout << "你的答案: " << (userAns.empty() ? "(未作答)" : userAns) << endl;
    
}
