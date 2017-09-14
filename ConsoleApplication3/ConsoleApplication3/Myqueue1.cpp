#include "stdafx.h"
#include <iostream>
#include "MyQueue.h"
using namespace std;
LoopQueue::LoopQueue(int queueCapacity) {
	m_lqueueCapacity = queueCapacity;
	m_lqueue = new int[queueCapacity];
	clearQueue();
}
LoopQueue::~LoopQueue() {
	delete[] m_lqueue;
	m_lqueue = NULL;
}
bool LoopQueue::queueEmpty()const {
	return m_lqueueLen == 0 ? true : false;
}
bool LoopQueue::queueFull() const {
	return  m_lqueueLen == m_lqueueCapacity ? true : false;
}
int LoopQueue::queueLength()const {
	return m_lqueueLen;
}

void LoopQueue::clearQueue() {
	m_lqueueLen = 0;
	m_lqueueHead = 0;
	m_lqueueTail = 0;
}
bool LoopQueue::enQueue(int element) {
	if (queueFull())
		return false;
	m_lqueue[m_lqueueTail] = element;
	m_lqueueTail++;
	m_lqueueTail = m_lqueueTail % m_lqueueCapacity;
	m_lqueueLen++;
	return true;
}
bool LoopQueue::deQueue(int &element) {
	if (queueEmpty())
		return false;
	element = m_lqueue[m_lqueueHead];
	m_lqueueHead++;
	m_lqueueHead = m_lqueueHead % m_lqueueCapacity;
	m_lqueueLen--;
	return true;
}
/**
��������
ע��iѭ���������յ��Ǽ��׳����
**/
void LoopQueue::queueTraverse() {
	cout << "��������---------------------------------------" << endl;
	for (int i = m_lqueueHead;i < m_lqueueLen + m_lqueueHead;i++) {
		cout << m_lqueue[i%m_lqueueCapacity] << endl;
	}
	cout << "��������---------------------------------------" << endl;
}


