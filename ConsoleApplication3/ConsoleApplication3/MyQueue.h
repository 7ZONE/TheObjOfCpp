#ifndef LOOP_QUEUE_H
#define LOOP_QUEUE_H
/**
���ζ��е�C++ʵ��
C++��������������������ͬ
**/
class LoopQueue {
public:
	LoopQueue(int queueCapacity);//initQueue(&Q)��������
	virtual ~LoopQueue();        //destoryQueue(&Q)���ٶ���
	void clearQueue();           //clearQueue(&Q)��ն���
	bool queueEmpty() const;     //queueEmpty(&Q)�пն���
	bool queueFull() const;      //queueFull(&Q)��������
	int queueLength() const;     //queueLength(&Q)�ж϶��еĳ���
	bool enQueue(int element);              //enQueue(&Q element)�������
	bool deQueue(int &element);              //deQueue(&Q element)��Ԫ�س���
	void queueTraverse();        //queueTraverse(&Q,visit())��������
private:
	int *m_lqueue;                 //����������ָ��
	int m_lqueueLen;               //���г���
	int m_lqueueCapacity;          //��������
	int m_lqueueHead;
	int m_lqueueTail;
};
#endif // LOOP_QUEUE
#pragma once
