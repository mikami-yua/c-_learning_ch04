// c++_learning_ch04.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
系统需求
1.添加联系人：联系人（姓名，性别，年龄，联系电话，家庭住址）。最多1k人
2.显示联系人：显示通信录中所有的联系人
3.删除联系人：按照指定姓名删除联系人
4.查找联系人：按照姓名查找
5.修改联系人：按照姓名修改
6.清空联系人：全部删除
7.退出
*/

#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

struct Person
{
    string m_Name;
    int m_Sex;//1 代表男  2 代表女
    int m_Age;
    string m_Tel;
    string m_Addr;
};

struct AddressBook
{
    Person personArray[MAX];
    int m_size;
};



//菜单界面
void showMenu() {
    cout << "************************************" << endl;
    cout << "1.add person" << endl;
    cout << "2.show person" << endl;
    cout << "3.delete person" << endl;
    cout << "4.find person" << endl;
    cout << "5.mod person" << endl;
    cout << "6.clean person" << endl;
    cout << "7.exit" << endl;
    cout << "************************************" << endl;
}

//添加
void addPerson(AddressBook* abs) {
    //添加联系人先判断是否满了
    if (abs->m_size == MAX) {
        cout << "AddressBook cannot input more person !" << endl;
        return;
    }
    else {
        //添加联系人
        string name;
        cout << "please input the name :" << endl;
        cin >> name;
        abs->personArray[abs->m_size].m_Name = name;

        int sex;
        cout << "please input sex 1->male 2->famale:" << endl;
        
        while (true) {//死循环确保能输入正确的数
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_size].m_Sex = sex;
                break;
            }
            cout << "error number of sex!" << endl;
        }

        int age;
        cout << "please input age :" << endl;
        cin >> age;
        abs->personArray[abs->m_size].m_Age = age;

        string tel;
        cout << "please input the tel :" << endl;
        cin >> tel;
        abs->personArray[abs->m_size].m_Tel = tel;

        string addr;
        cout << "please input the addr :" << endl;
        cin >> addr;
        abs->personArray[abs->m_size].m_Addr = addr;
        
        //更新人数
        abs->m_size++;
        cout << "add person success!" << endl;
        system("pause");//按任意键继续
        system("cls");//清屏
    }
}

//显示
void showPerson(const AddressBook* abs) {
    if (abs->m_size == 0) {
        cout << "no person in this book!" << endl;
    }
    else {
        for (int i = 0; i < abs->m_size; i++) {
           
            cout << "name: " << abs->personArray[i].m_Name <<"\t";
            cout << "sex: " << (abs->personArray[i].m_Sex==1? "male":"famale") << "\t";
            cout << "age: " << abs->personArray[i].m_Age << "\t";
            cout << "tel: " << abs->personArray[i].m_Tel << "\t";
            cout << "addr: " << abs->personArray[i].m_Addr << endl;  
        }
    }
    system("pause");
    system("cls");
}

//检测人是否存在,存在返回index 否则返回-1
int isExist(AddressBook* abs,string name) {
    for (int i = 0; i < abs->m_size; i++) {
        if (abs->personArray[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}

//删除
void deletePerson(AddressBook* abs) {
    cout << "please input the name you want to delete :" << endl;
    string name;
    cin >> name;
    int ret=isExist(abs, name);
    if (ret == -1) {
        cout << "cannot find this person" << endl;
    }
    else {
        for (int i = ret; i < abs->m_size; i++) {
            abs->personArray[i] = abs->personArray[i + 1];//数据前移
        }
        abs->m_size--;
        cout << "success delete!" << endl;

    }
    system("pause");
    system("cls");
}

//查找
void findPerson(AddressBook* abs) {
    cout << "please input the name you want to find :" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "cannot find this person" << endl;
    }
    else {
        cout << "name: " << abs->personArray[ret].m_Name << "\t";
        cout << "sex: " << (abs->personArray[ret].m_Sex == 1 ? "male" : "famale") << "\t";
        cout << "age: " << abs->personArray[ret].m_Age << "\t";
        cout << "tel: " << abs->personArray[ret].m_Tel << "\t";
        cout << "addr: " << abs->personArray[ret].m_Addr << endl;
    }
    system("pause");
    system("cls");
}

//修改
void modifyPerson(AddressBook* abs) {
    cout << "please input the name you want to modify :" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "cannot find this person" << endl;
    }
    else {
        //添加联系人
        string name;
        cout << "please input the name :" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        int sex;
        cout << "please input sex 1->male 2->famale:" << endl;

        while (true) {//死循环确保能输入正确的数
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "error number of sex!" << endl;
        }

        int age;
        cout << "please input age :" << endl;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        string tel;
        cout << "please input the tel :" << endl;
        cin >> tel;
        abs->personArray[ret].m_Tel = tel;

        string addr;
        cout << "please input the addr :" << endl;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;
    }
    system("pause");
    system("cls");
}

//清空
void cleanPerson(AddressBook* abs) {
    abs->m_size = 0;
    cout << "AddressBook has cleaned!" << endl;
    system("pause");
    system("cls");
}

int main()
{

    //创建一个通讯录
    AddressBook abs;
    abs.m_size = 0;



    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1://添加
            addPerson(&abs);//地址传递修改实参
            break;
        case 2://显示
            showPerson(&abs);
            break;
        case 3://删除
            deletePerson(&abs);
            break;
        case 4://查找
            findPerson(&abs);
            break;
        case 5://修改
            modifyPerson(&abs);
            break;
        case 6://清空
            cleanPerson(&abs);
            break;
        case 7://退出
            cout << "thanks for using!" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }




    system("pause");
    return 0;
}


