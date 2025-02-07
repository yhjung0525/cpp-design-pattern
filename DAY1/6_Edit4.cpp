// 33page ~ 

// 객체지향 디자인 패턴의 핵심 1. 공통성과 가변성의 분리
// => 변하지 않은 코드 내부에 숨은 변해야 하는 코드를 찾아서 분리하는 것

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 - template method (edit2.cpp)
// 2. 변하는 것을 다른 클래스로 - strategy     (edit3.cpp)

// edit2.cpp						// edit3.cpp
// => 변하는 것을 가상함수로			// => 변하는 것을 다른 클래스로	
// => 변경하고 싶다면 상속을 사용해라! // => 변경하고 싶다면 "정책 클래스"를 만들어라
// => 변하는것(정책)을 소유하게 된다.  // => Edit 와 정책은 완전히 분리 된다.
// => 실행시간에 교체 될수 없고        // => 실행시간에 정책은 교체될수 있고
//    다른 클래스가 정책을 사용할수 없다 // => 다른 클래스에서도 정책 사용이 가능하다
// template method					   strategy








