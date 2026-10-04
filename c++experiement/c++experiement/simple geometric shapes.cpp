#include <iostream>
#include "QuestionBank.h"

using namespace std;

int main() {
    QuestionBank myBank("简单几何图形题库");
    int choice, id;
    double a, b, c;
    string userAns;

    while (true) {
        cout << "\n========== 菜单 ==========" << endl;
        cout << "1. 新增题目" << endl;
        cout << "2. 查询题目" << endl;
        cout << "3. 删除题目" << endl;
        cout << "4. 计算并显示成绩" << endl;
        cout << "0. 退出程序" << endl;
        cout << "============================" << endl;
        cout << "请输入你的选择: ";
        cin >> choice;

        if (choice == 1) {
            cout << "请输入题目编号: "; cin >> id;
            cout << "请输入三角形三条边长 (a b c): ";
            cin >> a >> b >> c;


            Triangle t(id, a, b, c);
            string type = t.getTypeStr();
            cout << "这是一个" << type << endl;
            if (type == "非三角形") {
                cout << "无法构成三角形" << endl;
            }
            else {
                cout << "请输入你的答案 (面积): ";
                cin >> userAns;
                t.inputUserAns(userAns);

                myBank.addQuestion(t);
                cout << ">>> 题目添加成功！" << endl;

                // ===== 演示逻辑错误：修改边长后，正确答案不会自动更新 =====
                cout << "\n>>> 现在调用 setSides 修改边长 (每条边 +1) ..." << endl;
                t.setSides(a + 1, b + 1, c + 1);   // 断点调试入口
                t.display();
                // ==========================================================
            }
        }
        else if (choice == 2) {
            cout << "请输入要查询的题目编号: "; cin >> id;
            myBank.queryQuestion(id);

        }
        else if (choice == 3) {
            cout << "请输入要删除的题目编号: "; cin >> id;
            if (myBank.deleteQuestion(id)) {
                cout << " 删除成功！" << endl;
            }
            else {
                cout << " 未找到该题目，删除失败！" << endl;
            }

        }
        else if (choice == 4) {
            myBank.calculateStats();
            myBank.showStats();

        }
        else if (choice == 0) {
            cout << "程序已退出。" << endl;
            break;
        }
        else {
            cout << "无效输入，请重新选择！" << endl;
        }
    }

    return 0;
}
