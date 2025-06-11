#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	void Resize(int newCapacity)
	{
		if(newCapacity > currentCapacity) // ���� ũ�⺸�� Ŭ ��츸 ����
		{
			T* newData = new T[newCapacity];

			for (int i = 0; i < currentSize; i++)
			{
				newData[i] = data[i];
			}

			delete[] data;
			data = newData;
			currentCapacity = newCapacity;
		}
	}

	SimpleVector(int Capacity = 10) : currentSize(0), currentCapacity(0)
	{
		data = new T[Capacity];
		currentCapacity = Capacity;
	}

	SimpleVector(const SimpleVector& other) {}

	void Push_back(const T& value)
	{
		if (currentSize != currentCapacity)
		{
			data[currentSize] = value;
			currentSize++; // ������ ����
		}
		else
		{
			Resize(currentCapacity + 5);
			data[currentSize] = value;
			currentSize++; // ������ ����			
		}
	}

	void Pop_back()
	{
		if (currentSize != 0)
		{
			data[currentSize - 1] = "0"; // ������ ���Ҹ� ���� ����
			currentSize--; // ������ ���� 
			// �����δ� ���� ����
		}
	}

	int Size()
	{
		return currentSize;
	}

	int Capacity()
	{
		return currentCapacity;
	}

	void sortData()
	{
		// sort(data, data + currentSize); // sort �Լ� <algorithm>
		// �迭�� ù ����, �迭�� �������� ���� ����
		
		T temp; // ���� ����
		if (currentSize > 1)
		{
			for (int i = 0; i < currentSize; i++)
			{
				for (int j = 0; j < currentSize - i - 1; j++)
				{
					if (data[j] > data[j + 1])
					{
						temp = data[j];
						data[j] = data[j + 1];
						data[j + 1] = temp;
					}
				}
			}
		}
	}

	void Status()
	{
		cout << "\n- - - - - - - -" << endl;
		cout << "Status : " << Size() << "/" << Capacity() << endl;
		for (int i = 0; i < Size(); i++)
		{
			cout << "'" << data[i] << "' ";
		}
		cout << "\n- - - - - - - -\n" << endl;
	}

	~SimpleVector()
	{
		delete[] data;
		cout << "\n���α׷� ����. ������ �Ҹ�" << endl;
	}
};

int main()
{
	int n;
	//SimpleVector<int> MyClass; // default �Ű�����, Ÿ�� ����
	cout << "�뷮�� �Է����ּ���. ";
	cin >> n;
	SimpleVector<string> C(n); // �Ű� ���� �Է� �� �迭 �뷮 ����
	C.Status();

	cout << "�� ���� �����͸� �����Ͻʴϱ�? ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "(" << i + 1 << "/" << n << ") ";
		string str;
		cin >> str;
		C.Push_back(str);
	}
	C.Status();

	cout << "�� ���� �����͸� �����Ͻʴϱ�? ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		C.Pop_back();
	}
	C.Status();

	cout << "����Ҹ� Ȯ���մϴ�.";
	cin >> n;
	C.Resize(n);
	C.Status();

	cout << "�����͸� �����մϴ�.";
	C.sortData();
	C.Status();

	return 0;
}