#include<iostream>
using namespace std;
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	string m_Name; //����
	int m_Sex; //�Ա� 1 �� 2 Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ�˵�����
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

//1. �����ϵ�˺���
void addPerson(Addressbooks* p)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (p->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		p->personArray[p->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����������1����2�����˳�ѭ������Ϊ������ȷ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personArray[p->m_Size].m_Sex = sex;
				break;
			}
			cout << "�Ա�������������������" << endl;
		}
		
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		p->personArray[p->m_Size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		p->personArray[p->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		p->personArray[p->m_Size].m_Addr = address;

		//����ͨѶ�е�����
		p->m_Size++;

		cout << "��ӳɹ���" << endl;

		system("pause"); //�밴���������
		system("cls"); //����
	}
}

//2. ��ʾ������ϵ�˺���
void showPerson(Addressbooks* p)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0,��ʾ��¼Ϊ�գ�������ʾ��ϵ����Ϣ
	if (p->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << "������" << p->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (p->personArray[i].m_Sex == 1 ? "��":"Ů") << "\t";
			cout << "���䣺" << p->personArray[i].m_Age << "\t";
			cout << "�绰��" << p->personArray[i].m_Phone << "\t";
			cout << "סַ��" << p->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //�����������
	system("cls"); //����
}

//�����ϵ���Ƿ���ڣ����ڣ�������ϵ��λ�ã����򷵻�-1
//����1��ͨѶ¼������2���Ա�����
int isExist(Addressbooks* p,string name)
{
	for (int i = 0; i < p->m_Size; i++)
	{
		//�ҵ��û������������
		if (p->personArray[i].m_Name == name)
		{
			return i; //�ҵ��ˣ�����������������е��±���
		}
	}
	return -1; //�������������û�ҵ�������-1
}

//3. ɾ��ָ����ϵ��
void deletePerson(Addressbooks* p)
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	//ret == -1 δ�鵽
	//ret ��= -1 �鵽��
	int ret = isExist(p, name);
	if (ret != -1)
	{
		//�鵽��,����ɾ������
		for (int i = ret; i < p->m_Size; i++)
		{
			//����Ǩ��
			p->personArray[i] = p->personArray[i + 1];
		}
		p->m_Size--;//����ͨѶ¼������
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�����������
	system("cls");//����

}

//4. ����ָ����ϵ��
void findPerson(Addressbooks* p)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(p, name);

	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������" << p->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (p->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << p->personArray[ret].m_Age << "\t";
		cout << "�绰��" << p->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << p->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�����������
	system("cls");//����

}

//5. �޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* p)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(p, name);

	if (ret != -1)//�ҵ���ϵ��
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		p->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����������1����2�����˳�ѭ������Ϊ������ȷ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�Ա�������������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		p->personArray[ret].m_Age = age;

		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		p->personArray[ret].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		p->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else //δ�ҵ�
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�����������
	system("cls");//����

}

//6.�����ϵ��
void cleanPerson(Addressbooks* p)
{
	p->m_Size = 0;//�����ڼ�¼��ϵ��������Ϊ0���߼����
	cout << "ͨѶ¼�����" << endl;

	system("pause");//�����������
	system("cls");//����
}

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

int main() {

	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0; //�����û�ѡ������ı���

	while (true)
	{
		//�˵��ĵ���
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: // 1�������ϵ��
			addPerson(&abs); //���õ�ַ���ݣ���������ʵ��
			break;
		case 2: // 2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: // 3��ɾ����ϵ��
		/*{
			cout << "������ɾ����ϵ��������" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4: // 4��������ϵ��
			findPerson(&abs);
			break;
		case 5: // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // 6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: // 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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