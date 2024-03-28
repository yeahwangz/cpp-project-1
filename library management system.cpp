/*##########系统需求##########

通讯录是一个可以记录亲人、好友信息的工具。

本教程主要利用C++来实现一个通讯录管理系统

系统中需要实现的功能如下：

* 添加联系人:向通讯录中添加新人,信息包括(姓名、性别、年龄、联系电话、家庭住址)最多记录1000人
* 显示联系人：显示通讯录中所有联系人信息
* 删除联系人：按照姓名进行删除指定联系人
* 查找联系人：按照姓名查看指定联系人信息
* 修改联系人：按照姓名重新修改指定联系人
* 清空联系人：清空通讯录中所有信息
* 退出通讯录：退出当前使用的通讯录
#############################*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 1000

void jmxs()
{
    cout << "************************" << endl;
    cout << "******1、添加联系人******" << endl;
    cout << "******2、显示联系人******" << endl;
    cout << "******3、删除联系人******" << endl;
    cout << "******4、查找联系人******" << endl;
    cout << "******5、修改联系人******" << endl;
    cout << "******6、清空联系人******" << endl;
    cout << "******0、退出通讯录******" << endl;
    cout << "************************" << endl;
}
// 联系人
struct lxr
{
    string name;
    int sex;
    int age;
    string phone;
    string home;
};
// 通讯录
struct txl
{
    int pnumber = 0;
    lxr person[MAX];
};
// 添加联系人
void addperson(txl *abs)
{
    if (abs->pnumber == MAX)
    {
        cout << "通讯录已满！" << endl;
        return;
    }
    else
    {
        cout << "请输入要添加人的姓名：" << endl;
        cin >> abs->person[abs->pnumber].name;
        cout << "请输入要添加人的性别：(1---男    0---女)" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 0 || sex == 1)
            {
                abs->person[abs->pnumber].sex = sex;
                break;
            }
            else
                cout << "输入错误！请重新输入:" << endl;
        }
        cout << "请输入要添加人的年龄：" << endl;
        cin >> abs->person[abs->pnumber].age;
        cout << "请输入要添加人的电话号码：" << endl;
        cin >> abs->person[abs->pnumber].phone;
        cout << "请输入要添加人的家庭住址：" << endl;
        cin >> abs->person[abs->pnumber].home;
    }
    cout << "添加完成！";
    abs->pnumber++;
}
// 查找联系人
void searchperson(txl *abs)
{
    if (abs->pnumber == 0)
    {
        cout << "通讯录为空，无法查询！" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "请输入你要查找的人的姓名：" << endl;
    string a;
    cin >> a;
    int b = 0;
    for (int i = 0; i < abs->pnumber; i++)
    {
        if (a == abs->person[i].name)
        {
            b = i;
        }
    }
    cout << "查询人的姓名：" << abs->person[b].name << endl;
    if (abs->person[b].sex == 1)
    {
        cout << "查询人的性别：男" << endl;
    }
    else
    {
        cout << "查询人的性别：女" << endl;
    }
    cout << "查询人的年龄：" << abs->person[b].age << endl;
    cout << "查询人的电话号码：" << abs->person[b].phone << endl;
    cout << "查询人的家庭住址：" << abs->person[b].home << endl;
}
// 清空联系人
void delecttxl(txl *abs)
{
    if (abs->pnumber == 0)
    {
        cout << "通讯录列表已为空！" << endl;
        return;
    }
    else
    {
        abs->pnumber = 0;
        cout << "成功删除通讯录列表所有信息！" << endl;
    }
}
// 显示联系人
void showperson(txl *abs)
{
    if (abs->pnumber == 0)
    {
        cout << "通讯录列表为空！" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < abs->pnumber; i++)
        {
            cout << "联系人姓名：" << abs->person[i].name << endl;
            cout << "联系人性别：" << abs->person[i].sex << endl;
            cout << "联系人年龄：" << abs->person[i].age << endl;
            cout << "联系人电话号码：" << abs->person[i].phone << endl;
            cout << "联系人家庭住址：" << abs->person[i].home << endl
                 << endl;
        }
    }
}
// 修改联系人
void changeperson(txl *abs)
{
    cout << "请输入需要修改的联系人姓名：" << endl;
    string cname;
    cin >> cname;
    int a = -1;
    for (int i = 0; i < abs->pnumber; i++)
    {
        if (cname == abs->person[i].name)
        {
            a = i;
        }
    }
    if (a == -1)
    {
        cout << "没有你要找的联系人！" << endl;
        return;
    }
    else
    {
        cout << "修改后的联系人姓名：" << endl;
        string name1;
        cin >> name1;
        abs->person[a].name = name1;
        cout << "修改后的联系人性别：(1---男  0---女)" << endl;
        int sex1;
        cin >> sex1;
        abs->person[a].sex = sex1;
        cout << "修改后的联系人年龄：" << endl;
        int age1;
        cin >> age1;
        abs->person[a].age = age1;
        cout << "修改后的联系人电话号码：" << endl;
        string phone1;
        cin >> phone1;
        abs->person[a].phone = phone1;
        cout << "修改后的联系人家庭住址：" << endl;
        string home1;
        cin >> home1;
        abs->person[a].home = home1;
        cout << "修改联系人成功！" << endl;
    }
}
// 删除联系人
void delectperson(txl *abs)
{
    if (abs->pnumber == 0)
    {
        cout << "通讯录已为空！" << endl;
        return;
    }
    else
    {
        cout << "请问你要删除的联系人的姓名是什么：" << endl;
        string cname;
        cin >> cname;
        for (int i = 0; i < abs->pnumber; i++)
        {
            if (abs->person[i].name == cname)
            {
                for (int j = i; j < abs->pnumber - 1; j++)
                {
                    abs->person[j] = abs->person[j + 1];
                }
                abs->pnumber--;
            }
        }
        cout << "成功删除！" << endl;
    }
}
// 读取文件
void loadFromFile(txl *abs)
{
    ifstream file_in("data.txt");
    string line;
    lxr temp;

    while (getline(file_in, line))
    {
        stringstream ss(line);
        getline(ss, temp.name, ',');
        ss >> temp.sex;
        ss.ignore(1, ',');
        ss >> temp.age;
        ss.ignore(1, ',');
        getline(ss, temp.phone, ',');
        ss.ignore(1, '\"');
        getline(ss, temp.home, '\"');
        abs->person[abs->pnumber++] = temp;
    }

    file_in.close();
}
// 将数据保存至指定文件
void savetofile(const txl *abs)
{
    ofstream file_out("data.txt");
    for (int i = 0; i < abs->pnumber; i++)
    {
        file_out << abs->person[i].name << ","
                 << abs->person[i].sex << ","
                 << abs->person[i].age << ","
                 << abs->person[i].phone << ","
                 << "\"" << abs->person[i].home << "\"" << endl;
    }
    file_out.close();
}
// 主函数
int main()
{
    txl abs;
    loadFromFile(&abs);
    while (true)
    {
        jmxs();
        cout << "请选择操作：" << endl;
        int a = 0;
        cin >> a;
        switch (a)
        {
        // 1、添加联系人
        case 1:
            addperson(&abs);
            system("pause");
            system("cls");
            break;
        // 2、显示联系人
        case 2:
            showperson(&abs);
            system("pause");
            system("cls");
            break;
        // 3、删除联系人
        case 3:
            delectperson(&abs);
            system("pause");
            system("cls");
            break;
        // 4、查找联系人
        case 4:
            searchperson(&abs);
            system("pause");
            system("cls");
            break;
        // 5、修改联系人
        case 5:
            changeperson(&abs);
            system("pause");
            system("cls");
            break;
        // 6、清空联系人
        case 6:
            delecttxl(&abs);
            system("pause");
            system("cls");
            break;
        // 0、退出通讯录
        case 0:
            savetofile(&abs);
            cout << "数据已保存至指定文件！成功退出通讯录！" << endl;
            // 程序最终退出出口
            return 0;
        default:
            cout << "输入错误！请重新选择" << endl;
            system("pause");
            system("cls");
            continue;
        }
    }
}