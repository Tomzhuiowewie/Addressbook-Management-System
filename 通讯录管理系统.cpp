#include<iostream>
using namespace std;
#define MAX 1000

//设计联系人结构体
struct Person
{
	string m_Name; //姓名
	int m_Sex; //性别 1 男 2 女
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人的数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};

//1. 添加联系人函数
void addPerson(Addressbooks* p)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (p->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->personArray[p->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是1或者2可以退出循环，因为输入正确
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personArray[p->m_Size].m_Sex = sex;
				break;
			}
			cout << "性别输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		p->personArray[p->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		p->personArray[p->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		p->personArray[p->m_Size].m_Addr = address;

		//更新通讯中的人数
		p->m_Size++;

		cout << "添加成功！" << endl;

		system("pause"); //请按任意键继续
		system("cls"); //清屏
	}
}

//2. 显示所有联系人函数
void showPerson(Addressbooks* p)
{
	//判断通讯录中人数是否为0，如果为0,提示记录为空，否则，显示联系人信息
	if (p->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << "姓名：" << p->personArray[i].m_Name << "\t";
			cout << "性别：" << (p->personArray[i].m_Sex == 1 ? "男":"女") << "\t";
			cout << "年龄：" << p->personArray[i].m_Age << "\t";
			cout << "电话：" << p->personArray[i].m_Phone << "\t";
			cout << "住址：" << p->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏
}

//检测联系人是否存在，存在，返回联系人位置，否则返回-1
//参数1：通讯录；参数2：对比姓名
int isExist(Addressbooks* p,string name)
{
	for (int i = 0; i < p->m_Size; i++)
	{
		//找到用户输入的姓名了
		if (p->personArray[i].m_Name == name)
		{
			return i; //找到了，返回这个人在数组中的下标编号
		}
	}
	return -1; //如果遍历结束都没找到，返回-1
}

//3. 删除指定联系人
void deletePerson(Addressbooks* p)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	//ret == -1 未查到
	//ret ！= -1 查到了
	int ret = isExist(p, name);
	if (ret != -1)
	{
		//查到了,进行删除操作
		for (int i = ret; i < p->m_Size; i++)
		{
			//数据迁移
			p->personArray[i] = p->personArray[i + 1];
		}
		p->m_Size--;//更新通讯录中人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏

}

//4. 查找指定联系人
void findPerson(Addressbooks* p)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(p, name);

	if (ret != -1)//找到联系人
	{
		cout << "姓名：" << p->personArray[ret].m_Name << "\t";
		cout << "性别：" << (p->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << p->personArray[ret].m_Age << "\t";
		cout << "电话：" << p->personArray[ret].m_Phone << "\t";
		cout << "住址：" << p->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏

}

//5. 修改指定联系人信息
void modifyPerson(Addressbooks* p)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(p, name);

	if (ret != -1)//找到联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->personArray[ret].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是1或者2可以退出循环，因为输入正确
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "性别输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		p->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		p->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		p->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else //未找到
	{
		cout << "查无此人" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏

}

//6.清空联系人
void cleanPerson(Addressbooks* p)
{
	p->m_Size = 0;//将当期记录联系人数量置为0，逻辑情况
	cout << "通讯录已清空" << endl;

	system("pause");//按任意键继续
	system("cls");//清屏
}

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main() {

	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入的变量

	while (true)
	{
		//菜单的调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: // 1、添加联系人
			addPerson(&abs); //利用地址传递，可以修饰实参
			break;
		case 2: // 2、显示联系人
			showPerson(&abs);
			break;
		case 3: // 3、删除联系人
		/*{
			cout << "请输入删除联系人姓名：" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4: // 4、查找联系人
			findPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
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