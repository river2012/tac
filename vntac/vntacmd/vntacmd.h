//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vntac.h"
#include "pybind11/pybind11.h"
#include "tac/tacfeedmd.h"


using namespace pybind11;
using namespace std;

//常量
#define __TACFEED_MD_H__ 0 
#define LEVEL1CALLBACK 1
#define LEVEL2CALLBACK 2
#define MBLCALLBACK 3


///-----------------------------------------------------------------------------------------------------------------
///C++ SPI 的回调函数方法实现
///-----------------------------------------------------------------------------------------------------------------
class MdApi
{
private:
	static int *api;       //API对象    river???
	thread task_thread;    //工作线程指针
	TaskQueue task_queue;  //工作队列
	bool active = false;   //工作状态

public:
	MdApi()
	{
	};
	//~MdApi()
	//{
	//	if (this->active)
	//	{
	//		this->exit();
	//	}
	//};

	///-----------------------------------------------------------------------------------------------------------------
	///C++ API回调函数
	///-----------------------------------------------------------------------------------------------------------------
	void Level1Callback(Level1QuoteDataT *pData);
	void Level2Callback(Level2QuoteDataT *pData);
	void MBLCallback(MBLQuoteDataT *pData);


	///-----------------------------------------------------------------------------------------------------------------
	///task : 任务
	///-----------------------------------------------------------------------------------------------------------------
	void processTask();
	void processLevel1Callback(Task *task);
	void processLevel2Callback(Task *task);
	void processMBLCallback(Task *task);

	///-----------------------------------------------------------------------------------------------------------------
	///data:  回调函数的数据字典
	///error: 回调函数的错误字典
	///id:    强求id
	///last:  是否为最后返回
	///i:	  整数
	///-----------------------------------------------------------------------------------------------------------------
	virtual void onLevel1Callback(const dict &data) {};
	virtual void onLevel2Callback(const dict &data) {};
	virtual void onMBLCallback(const dict &data) {};

	///-----------------------------------------------------------------------------------------------------------------
	///req: 主动函数的请求字典
	///-----------------------------------------------------------------------------------------------------------------
	string TacFeedGetApiVersion();

	int TacFeedSetCpuAffinity(int cpu);

	//int TacFeedSubscribe(const TacFeedInitParam* init_param);
	int TacFeedSubscribe(const dict &req);
	
	int TacFeedRelease();
};

