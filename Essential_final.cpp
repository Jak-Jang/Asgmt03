//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T>
//class SimpleVector
//{
//private:
//	T* data;
//	int currentSize = 0;
//	int currentCapacity = 0;
//
//public:
//	void Resize()
//	{
//		data = new T[currentCapacity];
//	}
//
//	SimpleVector(int Capacity = 10)
//	{
//		currentCapacity = Capacity;
//		Resize();
//	}
//
//	void Push_back(const T& value)
//	{
//		if (currentSize != currentCapacity)
//		{
//			data[currentSize] = value;
//			currentSize++; // ������ ����
//		}
//	}
//
//	void Pop_back()
//	{
//		if (currentSize != 0)
//		{
//			data[currentSize - 1] = "0"; // ������ ���Ҹ� ���� ����
//			currentSize--; // ������ ���� 
//			// �����δ� ���� ����
//		}
//	}
//
//	int Size()
//	{
//		return currentSize;
//	}
//
//	int Capacity()
//	{
//		return currentCapacity;
//	}
//
//	void Status()
//	{
//		cout << "- - - - - - - -" << endl;
//		cout << "Status : " << Size() << "/" << Capacity() << endl;
//		for (int i = 0; i < Size(); i++)
//		{
//			cout << "'" << data[i] << "' ";
//		}
//		cout << "\n- - - - - - - -\n" << endl;
//	}
//
//	~SimpleVector()
//	{
//		delete[] data;
//		cout << "\n���α׷� ����. ������ �Ҹ�" << endl;
//	}
//};
//
//int main()
//{
//	int n;
//	//SimpleVector<int> MyClass; // default �Ű�����, Ÿ�� ����
//	cout << "�뷮�� �Է����ּ���. ";
//	cin >> n;
//	SimpleVector<string> C(n); // �Ű� ���� �Է� �� �迭 �뷮 ����
//	C.Status();
//
//	cout << "�� ���� �����͸� �����Ͻʴϱ�? ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "(" << i + 1 << "/" << n << ") ";
//		string str;
//		cin >> str;
//		C.Push_back(str);
//	}
//	C.Status();
//
//	cout << "\n�� ���� �����͸� �����Ͻʴϱ�? ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		C.Pop_back();
//	}
//	C.Status();
//
//	return 0;
//}