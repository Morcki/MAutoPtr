#pragma once
#include <iostream>
#include <string>
using namespace std;
class TestClass
{
public:
	TestClass(string name) : m_name(name) { printf("Creat %s\n", m_name.c_str()); };
	~TestClass() { printf("Destroy %s\n", m_name.c_str()); };
	friend bool AddPartner(shared_ptr<TestClass> p1, shared_ptr<TestClass> p2) {
		if (!p1 || !p2) {
			return false;
		}
		p1->m_partner = p2;
		p2->m_partner = p1;
		printf("%s is now with %s\n", p1->m_name.c_str(), p2->m_name.c_str());
		return true;
	};
private:
	string m_name;
	weak_ptr<TestClass> m_partner;
};