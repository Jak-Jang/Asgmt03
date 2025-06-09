// Ŭ������ �̸��� SimpleVector��� �մϴ�.
// Ÿ�Կ� �������� �ʰ� �����͸� ������ �ִ� �迭�� ��������� �����ϴ�.

// �����ڴ� �Ʒ��� ���� ���� �մϴ�.
// �⺻ �����ڴ� ũ�Ⱑ 10�� �迭�� ����ϴ�.
// ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� ����ϴ�.

// �Ʒ��� ���� ����Լ��� ���� �մϴ�.

// push_back  ���ڷ� ���� ���Ҹ�  �� �ڿ� �߰� �մϴ�.
// ��ȯ���� �����ϴ�.
// �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð�� �ƹ� ���۵� ���� �ʽ��ϴ�.

// pop_back�� ������ ������ ���Ҹ� ���� �մϴ�.
// ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ������, ���� �� ��ȯ���� �����ϴ�.

// size�� ���ڰ� ���� ���� ������ ������ ��ȯ�մϴ�.
// capacity ���� ���� �迭�� ũ�⸦ ��ȯ�մϴ�.

//������ �� �ڿ� Ŭ������ ������ �Ʒ��� �����ϴ�.

// �ʼ�
// 1.�迭�� �� ���� ���Ҹ� ����/���� �ϴ� ����� �䱸���׿� �°� �����ϴ��� Ȯ��      
// 2.���ø��� ������ ���� �������� ���� ��츦 ���ؼ� ������ �� �ִ��� Ȯ��
// 3.�䱸���׿� �ִ� ������ ������, �ټ��� �����ڸ� ������ �ʰ�, 
// �⺻���ڸ� Ȱ���ؼ� �ϳ��� �����ڷ� ó���� �� �ִ���(ó���ߴ���) Ȯ��

#include <iostream>
#include <vector>
using namespace std;

template <typename T> // �Լ� ���ø�
class SimpleVector
{
public:
	// ������ (�迭�� ũ�� ����)
	SimpleVector(T capacity) : Capacity(10)
	{
		Capacity = capacity;
		My_Vec.resize(Capacity); // �迭�� ũ�� ����, ���� NULL �ʱ�ȭ
		My_Vec.clear();	// ���� ����
	}

	// ��� �Լ�
	void Push_back(T a) // ������ Ÿ���� ���� ���� a�� ������ ���ҷ� ����
	{
		if (My_Vec.size() != My_Vec.capacity()) // �뷮�� �ʰ��ؼ� ���� X
		{
			My_Vec.push_back(a);
		}
		else
		{
			cout << "�Է� �Ұ�" << endl;
		}
	}

	void Pop_back() // ���� ������ ���� ����
	{
		if (!My_Vec.empty()) // .empty() �� ��� true, else false // ! not
		{
			My_Vec.pop_back();
		}
	}

	int currentSize() // �迭�� size �� ��ȯ
	{
		return My_Vec.size();
	}

	int currentCapacity() // �迭�� capacity �� ��ȯ
	{
		return My_Vec.capacity();
	}

	void Print() // �迭 ���� ���
	{
		cout << "\n���� �迭�� ���� : ";
		for (int i = 0; i < My_Vec.size(); i++)
		{
			cout << "'" << My_Vec[i] << "' ";
		}
		cout << endl;
	}

	~SimpleVector() {} // new�� ������� �ʾ���

private:
	// ��� ����
	int Capacity;
	vector<T> My_Vec;
};

int main()
{
	int capacity; // �迭�� ũ��
	cout << "���� �迭�� ����ϴ�.\n ũ�⸦ �Է��� �ּ���. : ";
	cin >> capacity;
	SimpleVector<int> My_Class(capacity); // Ŭ���� ȣ��

	cout << "���� �迭�� size : " << My_Class.currentSize() << endl;
	cout << "���� �迭�� capacity : " << My_Class.currentCapacity() << endl;
	cout << "-----------------------------------------------" << endl;

	int num1; // ���� �Է�
	cout << "\n�迭�� �� ���� ���Ҹ� �����ðڽ��ϴ�? : " << endl;
	cin >> num1;
	for (int i = 1; i <= num1; i++)
	{
		int element;
		cout << "���Ҹ� �Է����ּ���. : ";
		cin >> element;
		My_Class.Push_back(element);
		cout << My_Class.currentSize() << "/" << My_Class.currentCapacity() << endl;
	}
	My_Class.Print();
	cout << "���� �迭�� size : " << My_Class.currentSize() << endl;
	cout << "���� �迭�� capacity : " << My_Class.currentCapacity() << endl;
	cout << "-----------------------------------------------" << endl;

	int num; // ���� ����
	cout << "\n�� ���� ���Ҹ� ����ðڽ��ϱ�? : " << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		My_Class.Pop_back();
	}
	My_Class.Print();
	cout << "���� �迭�� size : " << My_Class.currentSize() << endl;
	cout << "���� �迭�� capacity : " << My_Class.currentCapacity() << endl;

	return 0;
}