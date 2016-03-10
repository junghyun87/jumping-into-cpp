## Chapter 2

``` cpp
#include<iostream>

using namespace std;

int main(){
	cout << "Hello" << endl;
}

```

## Chapter 3

* cin은 한 단어를 읽는다.

``` cpp
cin >> thisisanumber
cin.ignore() //문자 하나를 discard한다.
cin.get() //newline, space 문자도 받음. cin은 enter, space문자 무시. 마지막 enter문자는 버퍼에 남김. 한단어만 저장되고 나머지는 버퍼에 있음
```

### 문자열 저장하기
``` cpp
#include <string>
int main(){
  string my_string;
  string user_name="xxx";
  string fullName = firstName + " " + lastName;
  //한 행 전체 읽기
  //파라미터: 입력소스, 문자열 저장할 변수, 입력 중단 문자
  //입력중단문자도 buffer에서 제거됨.
  getline(cin, user_name,'\n');
}
```

## Chapter 4
문자열 비교에서 "==" 사용가능.

## Chapter 5
함수를 정의(define)하기 전에 선언(declare)부터 해야 함.
정의되지 않은 함수는 링크 단계에서 실패.

## Chapter 6

## Chapter 7

## Chapter 8

``` cpp
#include<cstdlib>
#include<ctime>
int main()
{
  srand(time(NULL)); //난수발생기의 시드 설정
  cout << rand() << '\n'; //rand는 0에서 RAND_MAX(최소 32767) 사이의 값을 리턴
  
}
```
srand는 시작시 한번만 호출한다. 여러번 호출하면 임의성이 떨어짐. 예를들어 time(NULL)을 시드로 srand를 계속호출하면 난수는 시간적 연관이 있는 수들을 바탕으로 생성되기 때문에 임의성이 떨어짐.

## Chapter 10 배열

## Chapter 11
``` cpp
struct PlayerInfo
{
  int skill_level;
  string name;
}; //semicolon 빼먹지 말기
```

## Chapter 13
``` cpp
int *p_points_to_integer;
int* p_points_to_integer; //위 둘은 같은 선언

//Using pointer
int x =5;
int *p_pointer_to_integer = &x;
*p_pointer_to_integer=3;

//NULL로 초기화하기
int *p_int = NULL;

```

### Reference
레퍼런스는 포인트의 간소화 버전
레퍼런스는 반드시 초기화 해야 한다. (언제나 유효한 메모리만을 가리켜야 한다.)
레퍼런스는 NULL을 가리킬 수 없음.
레퍼런스는 초기화되면 자신이 가리키는 메모리를 변경할 수 없음.
``` cpp
int x = 5;
int &ref = x;
```

## Chapter 14 동적메모리할당
``` cpp
int *p_int = new int;
delete p_int; //메모리 반환
p_int =NULL //메모리 반환 뒤에는 포인터를 NULL로 리셋하는 것이 좋음
```
* 할당된 메모리를 레퍼런스에 저장하면 안됨

### 포인터와 배열
``` cpp
//배열을 포인터에 대입할 수 있다.
int numbers[8];
int *p_numbers = numbers;
for (int i = 0; i <8; ++i)
{
  p_numbers[i]=i;
}

//메모리 배열 동적 할당
int *p_numbers = new int[8];
//메모리 배열 반환
delete[] p_numbers;

```

### 포인터 연산
``` cpp
int x[10];
x[3] = 120; //Syntatic sugar
*(x+3) = 120; // 3*sizeof(int)를 더함. 포인터 연산은 메모리의 슬롯을 더하는 것. 바이트의 수를 더하는 것이 아님

```

### 2차원 배열 이해하기
``` cpp
//2차원 배열 선언. 앞 뒤요소의 크기 제공하거나 뒷요소의 크기를 컴파일러에게 알려준다.
int sumTwoDArray(int array[4][4]){}
int sumTwoDArray(int array[][4]){}

//아래 두 expression은 같은 의미
array[3][2];
*(array + 3*<배열의 너비>+2);
```

### 포인터의 포인터
``` cpp
//2차원 배열 생성
int **p_p_tictactoe;
p_p_tictactoe = new int*[3];
for(int i=0;i<3;i++){
  p_p_tictactoe[i] = new int[3];
}
//2차원 배열처럼 사용 가능
p_p_tictactoe[i][j]=0;

//메모리 반환
for(int i=0;i<3;i++){
  delete [] p_p_tictactoe[i];
}
delete[] p_p_tictactoe;
```

### 포인터의 포인터와 2차원 배열
``` cpp
//2차원 배열을 포인터의 포인터로 대입할 수 없음.
int x[8][8];
int **y = x //compile error

//함수의 인수로 전달도 안됨.
int sum_matrix(int value[][4], int num_rows){
  cout >> values[0][1];
  return values[0][1];
}
int main(){
  int **x;
  sum_matrix(x,10); 
  return 0;
}
```
* 2차원 배열에서 element에 접근하는 방법(포인터연산으로 접근)과 포인터의 포인터로 element에 접근하는 방법(2번의 역참조로 접근)이 다르기 때문에 컴파일러에서 허용하지 않는 것임

## Chapter 15 연결리스트 데이터 구조

## Chapter 16 되부름
* 되부름이 효과적인 경우:
 1. 같은 문제를 더 작아진 버전으로 처리하여 문제해결 방법을 생각해 낼 수 있을 떄
 2. 탈출조건을 해결할 수 있을 떄

* 되부름 사용의 두가지 방식
 1.  되부름 호출에서 리턴된 값이 바로 리턴되는 경우. ex) 리스트에서 특정 노드 찾기
 2. 되부름 호출에서 리턴된 값을 가져다 어떤 일을 하는 경우. ex) 팩토리얼 함수 계산

### 루프와 되부름
* 되부름 함수를 호출하여 받은 결과로 무언가를 하지 않는다면 루프 알고리즘 또한 작성하기 쉽다.
* tail recursion의 경우 되부름 호출이 함수의 마지막에 수행되는 것을 말하는데, 루프의 다음 단계로 이동하는 것과 같다. ex) 리스트 탐색이 꼬리 되부름

## Chapter 17 바이너리 트리

## Chapter 18 표준 템플릿 라이브러리
### 벡터
``` cpp
#include <vector>
using namespace std;
vector<int> a_vector(10);

//배열처럼 사용가능
a_vector[3]=0;

a_vector.size();

a_vector.push_back(10); //현재 벡터의 끝에 추가. 배열 크기 자동으로 조절됨.
```
### 맵
``` cpp
#include <map>
#include <string>

using namespace std;
map<string, string> name_to_email;

//값 추가
name_to_email["John"]="aaa@abc.com";
//값 가져오기
cout << name_to_email["John"];
//삭제
name_to_email.erase("John");
//size
name_to_email.size();
//empty?
name_to_email.empty();
//맵 비우기
name_to_email.clear();
```
* 위 함수는 벡터에서도 사용가능

### 반복자
* 벡터의 경우에는 size와 배열접근을 이용하여 모든 개별요소 접근을 할 수 있는데, map의 경우에는 비숫자 키일때가 잦으므로 size함수를 이용한 방법으로 접근하는 것이 어려울 수도 있음

``` cpp
//반복자 선언
vector<int>::iterator

//반복자 사용
vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vector<int>::iterator itr = vec.begin();

//벡터 요소 읽기
cout << *itr;

//다음 요소 가져오기
itr++;

//끝인지 확인. 현재 반복자와 끝 반복자 비교.
itr == vec.end();

//벡터 전체 루프 반복
for(vector<int>::iterator itr = vec.begin(),
    end=vec.end();
    itr != end; ++itr)
    {
      cout << *itr << endl;
    }

//맵에서 반복자 사용
int key = itr->first //키
int value = itr->second //값

for(map<string,string>::iterator itr = map_to_print.begin(),
    end=map_to_print.end();
    itr != end; ++ itr){
      cout << itr->first << "-->" << itr->second << endl;
}

//값이 맵에 있는지 확인
//find 사용. 값을 찾으면 해당 위치의 반복자 리턴. 없으면 끝 반복자 리턴.
map<string, string>::iterator itr= name_to_email.find("John");
if (itr != name_to_email.end()){
  cout << itr->second;
}

//대괄호 연산자를 사용하여 접근할 경우 키가 존재하지 않으면 빈 요소 삽입
name_to_email["John"];
```
## Chapter 19. 문자열 고급
* cin은 객체. 타입은 입력스트림. cin>>은 데이터를 읽어들이는 메소드

``` cpp
string input;
getline(cin,input,'\n');
```
* 구분자까지 읽고 구분자는 string에 저장안되고 버퍼에서 제거됨
* 구분자를 '\n'가 아닌 다른 문자를 쓰면 마지막 엔터가 버퍼에 남음

### 문자열 길이, 개별요소에 접근
length() 또는 size()이용.
``` cpp
int len = my_string1.length();//or .size()
//배열처럼 사용가능
for (int i = 0; i< my_string.length();i++){
  cout << my_string[i];
}
```

### 탐색 및 sub string
* find(substring, start) 함수
 * substring을 start index에서 검색
 * substring이 있으면 index 리턴 없으면 string::npos 리턴

* substr(position, length)
 * string의 position 부터 length 길이 만큼의 substring 리턴

### 레퍼런스에 의한 전달
* sring은 레퍼런스로 전달하는 것이 좋다.
* 레퍼런스 파라미터를 수정못하게 하려면 const을 사용한다.

``` cpp
void print_string(const string& str){
  cout << str //okay
  str = "abc" //invalid
}

//point에 const 적용. point가 가리키는 메모리의 값을 바꾸지 못함
void print_ptr(const int *p_val){
  *p_val = 20; //invalid
  p_val = NULL; //okay.
}

//const 변수 선언. 선언하고 바로 초기화해야 함.
const int x = 4;
```

### const 전파
* const로 변수를 선언하면, 그 변수에 접근하는 함수 파라미터의 타입도 const여야 함.

``` cpp
//아래 예제는 compile안됨. fun1이 const인 a를 바꿀 수 있기 때문(바꾸지 않더라도).
void fun1(int &a){
  cout << a;
}
const int a = 4;
fun1(a);

//아래 예제는 compile됨. b값이 복사되어 const b는 변경이 안되기 때문.
void fun2(int b){
  cout << b;
}
const int b = 3;
fun2(b);
```

### const와 STL
* 벡터, 맵은 값에 의한 전달. 값들이 복사되어 함수 파라미터에 전달됨.
* 레퍼런스를 사용하면 공간을 아낄수 있고 const를 사용하면 함수에서 변경을 방지할 수 있음. const STL이면 반복자도 const를 써야 함(const_iterator).

``` cpp
void displayMap(const map<string, string>& map_to_print){
  for(map<string,string>::const_iterator itr = map_to_print.begin(),
      end=map_to_print.end();
      itr!=end;
      ++itr)
  {
    cout << itr-> first << endl;
  }
}
```

## Chapter 21 프로그램을 작은 조각으로 쪼개기
1. 전처리 (preprocessor)
  * preprocessor directive (#로 시작, e.g, #include)를 처리함
  * 예를들어 #include  &lt;iostream&gt; 이 있을 때, iostream 헤더파일 내용이 현재 파일에 붙여넣기 됨
  * 매크로 확장 (#define으로 정의된 것들 대체)
  * 특정코드만을 컴파일하고 싶을 떄. #ifdef SOMETHING, #ifnotdef SOMETHING #endif 사용
2. 컴파일 
  * 소스코드 파일을 목적 파일(기계어 파일)로 변환.
  * 소스파일이 여러개이면 개별적으로 컴파일 됨
3. 링크
  * 단일 실행 파일로 만드는 과정
  * 여러 목적 파일, 라이브러리가 모여 단일 실행파일 생성
  * 목적 파일에 정의되지 않은 함수가 사용될 경우 (선언이 담긴 (헤더)파일은 include되어 있어야 함) 컴파일 과정에서 일단 stub로 남겨둔다. 그리고 링크가 해당 함수를 링크 중인 목적파일을 찾아 stub부분을 채운다.(함수코드가 들어가는지 함수주소가 들어가는지 모르겠음. 중복 코드 삽입을 방지하는 것이 header파일이 있는 이유라면 함수주소가 들어가는 것이 맞는 것 같음)
  * 컴파일과 링크를 분리함으로써 발생하는 장점은 변경된 소스 파일만 컴파일하고 변경되지 않은 소스 파일들은 재컴파일 할 필요가 없이 링크타임에 묶는다. 따라서 시간 절약.

### 소스코드를 여러 파일로 나눌 때 유의점
* 헤더 파일에는 어떤 함수 정의도 담기면 안된다. 이 헤더 파일을 하나 이상의 소스 파일에서 include 했다면 링크 타임에 같은 함수 정의 여러개가 나오게 됨. 링크는 그 중에 어떤 함수 정의 주소를 사용할지 혼란스러울 것.
* 함수 선언이 하나의 소스파일에서 두번 이상 포함하게 해서는 안됨. 아래 코드는 그런 현상을 막기 위한 방법 (정확한 이유를 모르겠음)
``` cpp
#ifndef SOMETHING
#define SOMETHING
//헤더파일들
#endif
```
* .cpp파일을 직접 포함(include)하면 안됨. 링크 과정에서 같은 함수 정의가 여러번 발생할 수 있음.(첫번째 문제와 관련된 듯)
* main함수는 하나만 있어야 함.

### 소스파일이 여럿인 개발 환경 다루기 g++
``` bash
#여러 소스 코드 컴파일
#header파일은 cpp파일에 포함되어 있으므로 지정안해도 됨.
g++ orig.cpp shared.cpp

#개별 컴파일 (컴파일, 링크 따로 하기)
g++ -c orig.cpp #-c: 링크 안하고 컴파일만 하기
g++ -c shared.cpp
g++ orig.o shared.o #또는 g++ *.o
```

## Chapter 24 클래스
### 클래스 인스턴스 선언하기
* 클래스 선언하고 세미콜론 입력안하면 컴파일에러남.
* 클래스 정의에는 세미콜론 없음.

``` cpp
//구조체 인스턴스 선언과 같다.
ChessBoard b;
b.getMove();

//메모리 할당
ChessBoard *board = new ChessBoard;
```
* 캡슐화
 * 공개 메소드를 사용하고 비공개 데이터를 숨기는 것
 * 사용자가 클래스의 인터페이스를 구성하는 특정 메소드에만 접근할 수 있도록 하는 것

## Chapter 25 클래스의 수명주기
### 객체 생성
#### 클래스의 멤버 초기화하기
``` cpp
enum ChessPiece { EMPTY_SQUARE, WHITE_PAWN /* and others */ };
enum PlayerColor { PC_WHITE, PC_BLACK };

class ChessBoard
{
public:

	ChessBoard (); // <-- no return value at all!

	PlayerColor getMove ();
	ChessPiece getPiece (int x, int y);
	void makeMove (int from_x, int from_y, int to_x, int to_y);
	
private:
	ChessPiece _board[ 8 ][ 8 ];
	string _whose_move;
    string _var2;
};

//초기화 리스트 사용
ChessBoard::ChessBoard()
     : _whose_move("white"),_var2("some string"){
     
}
```

* 클래스의 필드를 const로 선언되면 해당 필드는 반드시 초기화 리스트로 초기화하여야 함. 레퍼런스 필드도 마찬가지로 초기화 리스트에서 초기화 해야 함. 생성자에서 초기화해서 에러 남.


### 객체 파괴
* 파괴자에서 포인터 메모리 정리를 주로 수행한다.
* 파괴자는 객체의 필요가 소멸되면 자동으로 호출된다.
* 필요하지 않는 경우
 1. 객체를 가리키는 포인터가 삭제될 때 (e.g., delete 호출)
 2. 객체가 영역 밖으로 넘어갈 때. 블록이 종료되는 곳 또는 return 문 또는 break문
 3. 다른 클래스에 담긴 객체의 파괴자는 포함하고 있는 클래스의 파괴자가 실행된 뒤에 호출. 그 이유는 클래스가 포함하고 있는 객체들에 대한 리소스 정리를 해당 클래스가 신경쓰지 않아도 된다. 그 객체들의 파괴자들이 그 일을 하니까. 자신이 할당한 리소스만 정리하면 된다.

### 클래스 복사하기
* 디폴트 버전의 복사 생성자와 대입 연산자는 포인터를 단순 복사(shallow copy)만 해준다.
#### 대입연산자
* 포인터 주소를 복사하기만 하면 한 포인터로 메모리를 삭제되었을 때, 다른 포인터는 삭제된 메모리를 가리키고 있어서 접근하면 에러 발생
* 대입연산자를 구현하여 포인터가 가리키고 있는 값들을 복사한다.
* 클래스 멤버에 포인터가 없으면 대입 연산자는 필요없음. C++에서 디폴트 대입 연산자가 각 요소를 복사해주기 때문
* 경험상 파괴자를 직접 작성해야 한다면 대입 연산자 또한 직접 작성하는 것이 바람직. 파괴자를 주로 메모리 반환할 때 사용하므로.
#### 복사생성자
* 한 객체를 다른 객체와 똑같이 구성하고자 할 때 사용. 생성자 인수에 복사할 객체가 들어감. 생성자에서 값의 복사가 이루어짐.
* 대입 연산자와 비슷한데 차이점은 복사생성자는 클래스가 초기화될 때 복사된다는 것. 그래서 CPU 시간을 낭비하지 않는다는 것.
* C++은 복사생성자가 없으면 디폴트 복사 생성자를 제공함
* 대입연산자 만들면 복사생성자 만드는 것이 일반적

### 전체 복사 방지하기
* 객체 복사를 하면 안되는 경우 사용
* 복사 생성자와 대입 연산자를 private에서 선언만 한다. 그래서 클래스 밖에서 사용할 경우 컴파일 에러가 발생하게 한다. public로 선언하면 컴파일에러는 발생하지않고 링크에러가 발생한다. 링크에러의 경우 어디에서 발생했는지 알기가 어렵다.

## Chapter 26. 상속과 다형성
### C++의 상속
``` cpp
class ship: public Drawble
{
};
//가상(virtual)으로 설정. 서브클래스가 재정의 할 수 있다는 것을 알림.
class Drawable
{
public:
  virtual void draw();
}

//순수 가상(pure virtual). 서브클래스는 반드시 구현해야 함. 0으로 설정. 메소드가 존재하지 않는다는 것을 뜻함. 순수 가상 함수가 있는 객체는 만들 수 없음.
class Drawable
{
public:
  virtual void draw()=0;
}
class ship: public Drawble
{
public:
  virtual draw(); //서브클래스는 0 생략
};
Ship::draw(){
}

//Drawable 인터페이스를 구현하는 다양한 클래스를 한 벡터에 담을 수 있음 (다형성)
//클래스 객체마다 필드가 달라 사이즈가 다르기 때문에 객체 자체를 벡터에 넣지 않고 객체의 포인터를 넣는다. 포인터는 사이즈가 같으니까.
vector<Drawable*> drawables;
```

* 다형성 - "형태가 많다." 인터페이스는 하나인데 그것을 구현한 클래스는 많을 수 있다. 다형성을 제공한다는 것은 공통 인터페이스를 구현한 다양한 형태의 클래스의 처리를 지원하는 것

### 상속, 객체 생성, 객체 파괴
* 슈퍼클래스에 담긴 비디폴트 생성자 호출하고 싶을 때, 초기화 리스트에 슈퍼클래스 이름을 포함한다.
* 슈퍼클래스 생성자 호출은 초기화 리스트의 클래스 필드보다 먼저 등장해야 함

``` cpp
class FooSuperclass
{
public:
  FooSuperClass(const string& val);
};
class Foo: FooSuperclass
{
public:
  Foo(): FooSuperclass("arg"){}
};
```

### 다형성과 객체 파괴
* 슈퍼클래스의 메소드를 virtual로 설정할 때는 파괴자도 함께 virtual로 설정해야 함
* 인터페이스 타입을 가진 변수로 그 인터페이스를 구현한 다양한 클래스 객체를 받아 인터페이스 함수를 호출할 수 있다(다형성).하지만 인터페이스를 가리키는 포인터에 대해 delete를 하면 인터페이스가 그 객체 고유의 파괴자를 찾지 못한다. 그래서 객체가 할당한 메모리를 해제할 수 없게 된다. 이를 해결하기 위해 인터페이스의 파괴자에 virtual이라고 선언해서 인터페이스 포인터에 대해 delete가 호출되면 그 인터페이스를 오버라이드하는 객체의 파괴자를 찾아야 한다고 알려준다.

### 쪼개기 문제
``` cpp
Subclass sub;
Superclass super = sub;
```
* 위 코드를 c++에서 지원하기는 하지만 문제 발생할 수 있어서 사용하지 않는다.
* 아래 처럼 슈퍼 클래스의 포인터에 서브 클래스의 주소를 할당한다.

``` cpp
Superclass *super = &sub;
```

### 클래스 차원의 데이터
* static 멤버, static 메소드
 * 클래스의 모든 객체가 공유한다. 
 * 객체 인스턴스 없이 사용될 수 있음.
 * static 메소드는 static 데이터에만 접근 가능함

```cpp
class Node
{
	public:
		Node();
		static int _getNextSerialNumber();
	private:
		static int _next_serial_number;
		int _serial_number;

};

int Node::_next_serial_number=0;

Node::Node()
	:_serial_number(_getNextSerialNumber()){} //초기화리스트에 함수를 넣어도 된다
int Node::_getNextSerialNumber(){
	cout << _next_serial_number;
	return _next_serial_number++;
}

int main(){
	Node node;
	Node::_getNextSerialNumber(); //클래스 이름으로 static 메서드접근
	Node node2;
	return 0;
}

```

### 다형성은 어떻게 구현되는가?
* 슈퍼클래스 변수로 어떻게 서브클래스에 구현되어 있는 인터페이스 함수를 찾는가?
 * 인터페이스 함수를 구현하는 객체마다 virtual table(vtable)에 접근할 수 있는 포인터가 있다. vtable에는 구현한 함수 주소들이 있다.

## Chapter 27. 네임스페이스
