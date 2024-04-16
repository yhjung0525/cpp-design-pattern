#pragma once

// ICalc.h 

// Proxy 의 수명을 reference counting 기술로 관리한다면
// Proxy 인터페이스 안에서 관련 함수를 정의해야 합니다.

// proxy 의 종류에 상관없이 reference counting 함수의 이름은 동일합니다.
// => 기반 클래스(인터페이스)로 제공하는 것이 좋습니다
struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// 이제 CalcProxy.cpp 다시 DLL로 빌드하면 됩니다.
