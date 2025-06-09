// ���� ������ ����

// ����Լ� �߰�/����

// push_back���� �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���� ���,
// ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��˴ϴ�.
// ������ �ִ� �� ����

// resize�� ���� �ϳ��� ���ڷ� ����. �ش� ũ��� ���Ҵ�
// �ش� �������� �迭�� ũ�Ⱑ ������ �ƹ� ���� X

// sortData�� ���� �����͸� �����ϴ� �Լ�
// algorithm�� sort�Լ� Ȱ��

#include <iostream>
#include <vector> // ���� �迭
#include <algorithm> // sort �Լ�
using namespace std;

template <typename T> // ���ø�
class SimpleVector
{
public:
	// ������
	SimpleVector() : capacity(10) // �ʱ� �뷮 10
	{
		My_Vec.resize(capacity);
		My_Vec.clear(); // �迭�� ���
	}
	SimpleVector(const SimpleVector& other) {}

	void Resize(int newCapacity)
	{
		capacity = newCapacity;
		My_Vec.reserve(capacity); // resize�� ����ϸ� ����� null �Է�
	}

	// ��� �Լ�
	void Push_back(const T element)
	{
		if (My_Vec.size() != My_Vec.capacity())
		{
			My_Vec.push_back(element);
		}
		else // �ѵ� �ʰ� �� capacity + 5
		{
			cout << "�뷮�� �����մϴ�. 5��ŭ �߰��մϴ�." << endl;
			My_Vec.reserve(My_Vec.capacity() + 5);
			My_Vec.push_back(element);
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

	void Status() // �迭 ���� ���
	{
		cout << "���� �迭�� size : " << currentSize() << endl;
		cout << "���� �迭�� capacity : " << currentCapacity() << endl;
		cout << "���� �迭�� ���� : ";
		for (int i = 0; i < My_Vec.size(); i++)
		{
			cout << "'" << My_Vec[i] << "' ";
		}
		cout << "\n-----------------------------------------------" << endl;
	}

	void sortData()
	{
		cout << "�Էµ� ���Ҹ� �����մϴ�." << endl;
		sort(My_Vec.begin(), My_Vec.end(), less<T>()); // ��������
		// sort(My_Vec.begin(), My_Vec.end(), greater<T>()); // ��������
	}

	~SimpleVector() {}

private:
	int capacity;
	vector<T> My_Vec;
};

int main()
{
	SimpleVector<int> My_Class; // ������ ���ø� Ŭ���� ȣ��
	
	int capacity; // �迭�� ũ��
	cout << "�迭�� �ʱ� �뷮�� 10�Դϴ�. ������ ���� �Է����ּ���. ";
	cin >> capacity;
	My_Class.Resize(capacity);
	My_Class.Status();

	int num1; // ���� �Է�
	cout << "\n�迭�� �� ���� ���Ҹ� �����ðڽ��ϴ�? : ";
	cin >> num1;
	for (int i = 1; i <= num1; i++)
	{
		int element;
		cout << "���Ҹ� �Է����ּ���. ";
		cin >> element;
		My_Class.Push_back(element);
		cout << My_Class.currentSize() << "/" << My_Class.currentCapacity() << endl;
	}
	My_Class.Status();

	int num; // ���� ����
	cout << "\n�� ���� ���Ҹ� ����ðڽ��ϱ�? : ";
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		My_Class.Pop_back();
	}
	My_Class.Status();

	cout << "\n�迭�� ������������ �����մϴ�." << endl;
	My_Class.sortData();
	My_Class.Status();

	return 0;
}