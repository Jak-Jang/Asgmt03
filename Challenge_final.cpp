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
		if(newCapacity > currentCapacity) // 기존 크기보다 클 경우만 가능
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
			currentSize++; // 사이즈 증가
		}
		else
		{
			Resize(currentCapacity + 5);
			data[currentSize] = value;
			currentSize++; // 사이즈 증가			
		}
	}

	void Pop_back()
	{
		if (currentSize != 0)
		{
			data[currentSize - 1] = "0"; // 마지막 원소를 삭제 못함
			currentSize--; // 사이즈 감소 
			// 실제로는 원소 존재
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
		// sort(data, data + currentSize); // sort 함수 <algorithm>
		// 배열의 첫 원소, 배열의 마지막의 다음 원소
		
		T temp; // 버블 정렬
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
		cout << "\n프로그램 종료. 데이터 소멸" << endl;
	}
};

int main()
{
	int n;
	//SimpleVector<int> MyClass; // default 매개변수, 타입 변경
	cout << "용량을 입력해주세요. ";
	cin >> n;
	SimpleVector<string> C(n); // 매개 변수 입력 시 배열 용량 변경
	C.Status();

	cout << "몇 개의 데이터를 저장하십니까? ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "(" << i + 1 << "/" << n << ") ";
		string str;
		cin >> str;
		C.Push_back(str);
	}
	C.Status();

	cout << "몇 개의 데이터를 삭제하십니까? ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		C.Pop_back();
	}
	C.Status();

	cout << "저장소를 확장합니다.";
	cin >> n;
	C.Resize(n);
	C.Status();

	cout << "데이터를 정렬합니다.";
	C.sortData();
	C.Status();

	return 0;
}