## Chapter 2

``` cpp
#include<iostream>

using namespace std;

int main(){
	cout << "Hello" << endl;
}

```

## Chapter 3

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
