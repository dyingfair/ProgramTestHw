#include<map>
#include<queue>
#include<iostream>
using namespace std;

typedef void(*SoftIRQProc)( void );

class SoftIRQ
{
public:
	int swiId_;
	int prio_;
	SoftIRQProc proc_;

public:
	SoftIRQ() {}
	SoftIRQ(int swiId1, int prio, SoftIRQProc proc):swiId_(swiId1), prio_(prio), proc_(proc) {}
	friend bool operator <(const SoftIRQ &proc1, const SoftIRQ & proc2)
	{
		return proc1.prio_ > proc2.prio_;
	}
};

map<int, SoftIRQ> validCreateIdMap;
priority_queue<SoftIRQ> irqQueue;
int runningID = -1;


int SwiCreate(unsigned int swiId, unsigned int prio, void(*proc)( void ))
{
	//TODO: 添加代码...
	if ((swiId > 99) || (prio < 0) || (prio > 31) || (proc == NULL))
		return -1;
	SoftIRQ irq(swiId, prio, proc);

	if (validCreateIdMap.count(irq.swiId_) != 0) {
		return -1;
	}
	else {
		validCreateIdMap[irq.swiId_] = irq;// 如果符合条件则添加进map
	}
	return 0;
}

/*************************************************************************************************
函数说明：软中断激活
输入参数：swiId： 待激活软中断ID
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiActivate(unsigned int swiId)
{
	//TODO: 添加代码...
	if (validCreateIdMap.count(swiId) == 0)
		return -1;
	irqQueue.push(validCreateIdMap[swiId]);	//按照优先级放入优先队列
	while (!irqQueue.empty()) {
		SoftIRQ firstIrq = irqQueue.top();
		if (runningID != firstIrq.swiId_) {
			int tmp = runningID;
			runningID = firstIrq.swiId_;
			firstIrq.proc_();
			runningID = tmp;
			irqQueue.pop();//出队列
		}
		else {
			break;//是同一个的时候继续
		}
	}
	return 0;
}

/*************************************************************************************************
函数说明：清空所有的信息
输入参数：无
输出参数：无
返回值  ：无
**************************************************************************************************/
static void Clear(void)
{
	validCreateIdMap.clear();
	while (!irqQueue.empty()) {
		irqQueue.pop();
	}
	runningID = -1;
}