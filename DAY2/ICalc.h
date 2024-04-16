#pragma once

// ICalc.h 

// Proxy �� ������ reference counting ����� �����Ѵٸ�
// Proxy �������̽� �ȿ��� ���� �Լ��� �����ؾ� �մϴ�.

// proxy �� ������ ������� reference counting �Լ��� �̸��� �����մϴ�.
// => ��� Ŭ����(�������̽�)�� �����ϴ� ���� �����ϴ�
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

// ���� CalcProxy.cpp �ٽ� DLL�� �����ϸ� �˴ϴ�.
