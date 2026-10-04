#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
using namespace std;
class Triangle {
private:
    double a, b, c;         // 三条边长
    int id;                 // 题目编号
    string userAns;    // 用户答案
    string correctAns; // 正确答案

    // 判断是否能构成有效三角形
    bool isValid() const;
    
    

public:
    // 获取三角形类型
    string getTypeStr() const;
    // 初始化
    Triangle(int id = 0, double a = 0, double b = 0, double c = 0);

    // 修改数据 
    void setSides(double a, double b, double c);

    // 获取数据
    int getId() const;
    double getArea() const;
    double getPerimeter() const;

    // 计算得到正确答案
    void calculateCorrectAns();

    // 输入自己的题目答案
    void inputUserAns(const string& ans);

    // 判断用户答案是否正确
    bool isCorrect() const;

    // 输出显示题目信息
    void display() const;
};

#endif
