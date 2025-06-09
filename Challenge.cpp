// 복사 생성자 구현

// 멤버함수 추가/변경

// push_back에서 배열의 크기가 꽉 찼는데 원소가 더 들어올 경우,
// 기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가됩니다.
// 기존에 있던 값 유지

// resize는 정수 하나를 인자로 받음. 해당 크기로 재할당
// 해당 정수보다 배열의 크기가 작으면 아무 동작 X

// sortData는 내부 데이터를 정렬하는 함수
// algorithm의 sort함수 활용

#include <iostream>
#include <vector> // 동적 배열
#include <algorithm> // sort 함수
using namespace std;

template <typename T> // 템플릿
class SimpleVector
{
public:
	// 생성자
	SimpleVector() : capacity(10) // 초기 용량 10
	{
		My_Vec.resize(capacity);
		My_Vec.clear(); // 배열을 비움
	}
	SimpleVector(const SimpleVector& other) {}

	void Resize(int newCapacity)
	{
		capacity = newCapacity;
		My_Vec.reserve(capacity); // resize를 사용하면 빈공간 null 입력
	}

	// 멤버 함수
	void Push_back(const T element)
	{
		if (My_Vec.size() != My_Vec.capacity())
		{
			My_Vec.push_back(element);
		}
		else // 한도 초과 시 capacity + 5
		{
			cout << "용량이 부족합니다. 5만큼 추가합니다." << endl;
			My_Vec.reserve(My_Vec.capacity() + 5);
			My_Vec.push_back(element);
		}
	}

	void Pop_back() // 가장 마지막 원소 삭제
	{
		if (!My_Vec.empty()) // .empty() 빌 경우 true, else false // ! not
		{
			My_Vec.pop_back();
		}
	}

	int currentSize() // 배열의 size 값 반환
	{
		return My_Vec.size();
	}

	int currentCapacity() // 배열의 capacity 값 반환
	{
		return My_Vec.capacity();
	}

	void Status() // 배열 원소 출력
	{
		cout << "현재 배열의 size : " << currentSize() << endl;
		cout << "현재 배열의 capacity : " << currentCapacity() << endl;
		cout << "현재 배열의 원소 : ";
		for (int i = 0; i < My_Vec.size(); i++)
		{
			cout << "'" << My_Vec[i] << "' ";
		}
		cout << "\n-----------------------------------------------" << endl;
	}

	void sortData()
	{
		cout << "입력된 원소를 정렬합니다." << endl;
		sort(My_Vec.begin(), My_Vec.end(), less<T>()); // 오름차순
		// sort(My_Vec.begin(), My_Vec.end(), greater<T>()); // 내림차순
	}

	~SimpleVector() {}

private:
	int capacity;
	vector<T> My_Vec;
};

int main()
{
	SimpleVector<int> My_Class; // 정수형 템플릿 클래스 호출
	
	int capacity; // 배열의 크기
	cout << "배열의 초기 용량은 10입니다. 변경할 값을 입력해주세요. ";
	cin >> capacity;
	My_Class.Resize(capacity);
	My_Class.Status();

	int num1; // 원소 입력
	cout << "\n배열에 몇 개의 원소를 넣으시겠습니다? : ";
	cin >> num1;
	for (int i = 1; i <= num1; i++)
	{
		int element;
		cout << "원소를 입력해주세요. ";
		cin >> element;
		My_Class.Push_back(element);
		cout << My_Class.currentSize() << "/" << My_Class.currentCapacity() << endl;
	}
	My_Class.Status();

	int num; // 원소 삭제
	cout << "\n몇 개의 원소를 지우시겠습니까? : ";
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		My_Class.Pop_back();
	}
	My_Class.Status();

	cout << "\n배열을 오름차순으로 정렬합니다." << endl;
	My_Class.sortData();
	My_Class.Status();

	return 0;
}