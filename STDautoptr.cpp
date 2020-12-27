#include <iostream>
#include "STDautoptr.h"
#include "TestClass.h"
using namespace std;
STD_AutoPtrTest::STD_AutoPtrTest() {

}

STD_AutoPtrTest::~STD_AutoPtrTest() {

}

void STD_AutoPtrTest::test_sharedptr() {
	// unique_ptr test
	// ���⣺��̫�����ڴ������飿
	// ����unique_ptr��������
	unique_ptr<int> m_uptr = make_unique<int>(5);
	printf("%d\n", *m_uptr);
	unique_ptr<int> m_uptr_r = move(m_uptr);
	if (m_uptr.get() == nullptr) {
		printf("unique_ptr has been moved to m_uptr_r");
	}
	printf("[%d]\n", *m_uptr_r);
	// shared_ptr test ����ָ�����
	shared_ptr<double> m_sptr = make_shared<double>(3.2);
	if (m_sptr.unique()) {

		printf("Only One:\n\t");
		
		printf("%lf\n", *m_sptr);

	}
	shared_ptr<double> m_sptr_r = m_sptr;
	if (!m_sptr.unique()) {

		printf("Number : %d\n\t", m_sptr.use_count());

		printf("%lf\n", *m_sptr_r);

	}
	// reset �Ƴ�����
	m_sptr.reset();
	printf("m_sptr has been reset, count[%d]\n", m_sptr.use_count());
	printf("m_sptr_r still exists, count[%d]\n", m_sptr_r.use_count());
	printf("m_sptr_r[%lf]\n", *m_sptr_r);

	// weak_ptr test �����ò��ԣ�����������������
	// AddPartner ���m_partner��Ҫ�õ�������
	shared_ptr<TestClass> test1_sptr = make_shared<TestClass>("Luccy");
	shared_ptr<TestClass> test2_sptr = make_shared<TestClass>("Mocki");
	AddPartner(test1_sptr, test2_sptr);
}