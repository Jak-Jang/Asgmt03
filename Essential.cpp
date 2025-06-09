// 클래스의 이름은 SimpleVector라고 합니다.
// 타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.

// 생성자는 아래와 같이 구현 합니다.
// 기본 생성자는 크기가 10인 배열을 만듭니다.
// 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.

// 아래와 같은 멤버함수를 구현 합니다.

// push_back  인자로 받은 원소를  맨 뒤에 추가 합니다.
// 반환값은 없습니다.
// 배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.

// pop_back은 벡터의 마지막 원소를 제거 합니다.
// 만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.

// size는 인자가 없고 현재 원소의 개수를 반환합니다.
// capacity 현재 내부 배열의 크기를 반환합니다.

//구현을 한 뒤에 클래스의 구조는 아래와 같습니다.

// 필수
// 1.배열의 맨 끝에 원소를 삽입/삭제 하는 기능이 요구사항에 맞게 동작하는지 확인      
// 2.템플릿을 적용한 경우와 적용하지 않은 경우를 비교해서 설명할 수 있는지 확인
// 3.요구사항에 있는 생성자 구현시, 다수의 생성자를 만들지 않고, 
// 기본인자를 활용해서 하나의 생성자로 처리할 수 있는지(처리했는지) 확인

#include <iostream>
#include <vector>
using namespace std;

template <typename T> // 함수 템플릿
class SimpleVector
{
public:
	// 생성자 (배열의 크기 지정)
	SimpleVector(T capacity) : Capacity(10)
	{
		Capacity = capacity;
		My_Vec.resize(Capacity); // 배열의 크기 변경, 원소 NULL 초기화
		My_Vec.clear();	// 원소 삭제
	}

	// 멤버 함수
	void Push_back(T a) // 미지의 타입을 가진 변수 a를 마지막 원소로 삽입
	{
		if (My_Vec.size() != My_Vec.capacity()) // 용량을 초과해서 삽입 X
		{
			My_Vec.push_back(a);
		}
		else
		{
			cout << "입력 불가" << endl;
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

	void Print() // 배열 원소 출력
	{
		cout << "\n현재 배열의 원소 : ";
		for (int i = 0; i < My_Vec.size(); i++)
		{
			cout << "'" << My_Vec[i] << "' ";
		}
		cout << endl;
	}

	~SimpleVector() {} // new를 사용하지 않았음

private:
	// 멤버 변수
	int Capacity;
	vector<T> My_Vec;
};

int main()
{
	int capacity; // 배열의 크기
	cout << "벡터 배열을 만듭니다.\n 크기를 입력해 주세요. : ";
	cin >> capacity;
	SimpleVector<int> My_Class(capacity); // 클래스 호출

	cout << "현재 배열의 size : " << My_Class.currentSize() << endl;
	cout << "현재 배열의 capacity : " << My_Class.currentCapacity() << endl;
	cout << "-----------------------------------------------" << endl;

	int num1; // 원소 입력
	cout << "\n배열에 몇 개의 원소를 넣으시겠습니다? : " << endl;
	cin >> num1;
	for (int i = 1; i <= num1; i++)
	{
		int element;
		cout << "원소를 입력해주세요. : ";
		cin >> element;
		My_Class.Push_back(element);
		cout << My_Class.currentSize() << "/" << My_Class.currentCapacity() << endl;
	}
	My_Class.Print();
	cout << "현재 배열의 size : " << My_Class.currentSize() << endl;
	cout << "현재 배열의 capacity : " << My_Class.currentCapacity() << endl;
	cout << "-----------------------------------------------" << endl;

	int num; // 원소 삭제
	cout << "\n몇 개의 원소를 지우시겠습니까? : " << endl;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		My_Class.Pop_back();
	}
	My_Class.Print();
	cout << "현재 배열의 size : " << My_Class.currentSize() << endl;
	cout << "현재 배열의 capacity : " << My_Class.currentCapacity() << endl;

	return 0;
}