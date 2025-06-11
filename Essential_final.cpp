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
//			currentSize++; // 사이즈 증가
//		}
//	}
//
//	void Pop_back()
//	{
//		if (currentSize != 0)
//		{
//			data[currentSize - 1] = "0"; // 마지막 원소를 삭제 못함
//			currentSize--; // 사이즈 감소 
//			// 실제로는 원소 존재
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
//		cout << "\n프로그램 종료. 데이터 소멸" << endl;
//	}
//};
//
//int main()
//{
//	int n;
//	//SimpleVector<int> MyClass; // default 매개변수, 타입 변경
//	cout << "용량을 입력해주세요. ";
//	cin >> n;
//	SimpleVector<string> C(n); // 매개 변수 입력 시 배열 용량 변경
//	C.Status();
//
//	cout << "몇 개의 데이터를 저장하십니까? ";
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
//	cout << "\n몇 개의 데이터를 삭제하십니까? ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		C.Pop_back();
//	}
//	C.Status();
//
//	return 0;
//}