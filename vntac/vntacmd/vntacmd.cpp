//偷懒之把cast中的static_assert 给mute掉
#include "vntacmd.h"



///-------------------------------------------------------------------------------------
///C++回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------
void MdApi::Level1Callback(Level1QuoteDataT *pDataL1)
{
	Task task = Task();
	task.task_name = LEVEL1CALLBACK;
	if (pDataL1)
	{
		Level1QuoteDataT *task_data = new Level1QuoteDataT();
		*task_data = *pDataL1;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::Level2Callback(Level2QuoteDataT *pDataL2)
{
	Task task = Task();
	task.task_name = LEVEL2CALLBACK;
	if (pDataL2)
	{
		Level2QuoteDataT *task_data = new Level2QuoteDataT();
		*task_data = *pDataL2;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::MBLCallback(MBLQuoteDataT *pDataMBL)
{
	Task task = Task();
	task.task_name = MBLCALLBACK;
	if (pDataMBL)
	{
		MBLQuoteDataT *task_data = new MBLQuoteDataT();
		*task_data = *pDataMBL;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------
void MdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case LEVEL1CALLBACK:
			{
				this->processLevel1Callback(&task);
				break;
			}

			case LEVEL2CALLBACK:
			{
				this->processLevel2Callback(&task);
				break;
			}

			case MBLCALLBACK:
			{
				this->processMBLCallback(&task);
				break;
			}

			};
		}

	}
	catch (const TerminatedError&)
	{
	}
};


void MdApi::processLevel1Callback(Task *task)
{   
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		Level1QuoteDataT *task_data = (Level1QuoteDataT*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ActionDay"] = toUtf(task_data->ActionDay);
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["Volume"] = task_data->Volume;
		data["LastPrice"] = task_data->LastPrice;
		data["Turnover"] = task_data->Turnover;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1;"] = task_data->AskVolume1;
		delete task->task_data;
	}
	this->onLevel1Callback(data);
};



void MdApi::processLevel2Callback(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		Level2QuoteDataT *task_data = (Level2QuoteDataT*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ActionDay"] = toUtf(task_data->ActionDay);
		data["UpdateTime"] = toUtf(task_data->UpdateTime);
		data["UpdateMillisec"] = task_data->UpdateMillisec;
		data["Volume"] = task_data->Volume;
		data["LastPrice"] = task_data->LastPrice;
		data["Turnover"] = task_data->Turnover;
		data["OpenInterest"] = task_data->OpenInterest;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5;"] = task_data->AskVolume5;
		delete task->task_data;
	}

	this->onLevel2Callback(data);
};


void MdApi::processMBLCallback(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		MBLQuoteDataT *task_data = (MBLQuoteDataT*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["AskPrice1"] = task_data->AskPrice1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["AskPrice2"] = task_data->AskPrice2;
		data["AskVolume2"] = task_data->AskVolume2;
		data["AskPrice3"] = task_data->AskPrice3;
		data["AskVolume3"] = task_data->AskVolume3;
		data["AskPrice4"] = task_data->AskPrice4;
		data["AskVolume4"] = task_data->AskVolume4;
		data["AskPrice5"] = task_data->AskPrice5;
		data["AskVolume5"] = task_data->AskVolume5;
		data["AskPrice6"] = task_data->AskPrice6;
		data["AskVolume6"] = task_data->AskVolume6;
		data["AskPrice7"] = task_data->AskPrice7;
		data["AskVolume7"] = task_data->AskVolume7;
		data["AskPrice8"] = task_data->AskPrice8;
		data["AskVolume8"] = task_data->AskVolume8;
		data["AskPrice9"] = task_data->AskPrice9;
		data["AskVolume9"] = task_data->AskVolume9;
		data["AskPrice10"] = task_data->AskPrice10;
		data["AskVolume10"] = task_data->AskVolume10;
		data["BidPrice1"] = task_data->BidPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["BidPrice2"] = task_data->BidPrice2;
		data["BidVolume2"] = task_data->BidVolume2;
		data["BidPrice3"] = task_data->BidPrice3;
		data["BidVolume3"] = task_data->BidVolume3;
		data["BidPrice4"] = task_data->BidPrice4;
		data["BidVolume4"] = task_data->BidVolume4;
		data["BidPrice5"] = task_data->BidPrice5;
		data["BidVolume5"] = task_data->BidVolume5;
		data["BidPrice6"] = task_data->BidPrice6;
		data["BidVolume6"] = task_data->BidVolume6;
		data["BidPrice7"] = task_data->BidPrice7;
		data["BidVolume7"] = task_data->BidVolume7;
		data["BidPrice8"] = task_data->BidPrice8;
		data["BidVolume8"] = task_data->BidVolume8;
		data["BidPrice9"] = task_data->BidPrice9;
		data["BidVolume9"] = task_data->BidVolume9;
		data["BidPrice10"] = task_data->BidPrice10;
		data["BidVolume10;"] = task_data->BidVolume10;
		delete task->task_data;
	}
	this->onMBLCallback(data);
};



///-------------------------------------------------------------------------------------
///req:主动函数
///-------------------------------------------------------------------------------------


string MdApi::TacFeedGetApiVersion()
{
	////string version = this->api->TacFeedGetApiVersion();
	string version = this->TacFeedGetApiVersion();
	return version;
};


int MdApi::TacFeedSetCpuAffinity(int cpu)
{
	////this->api->TacFeedSetCpuAffinity(cpu);
	int i = this->TacFeedSetCpuAffinity(cpu);
	return i;
};
//int MdApi::TacFeedSubscribe(const TacFeedInitParam * init_param)
//{
//	return 0;
//};

int MdApi::TacFeedSubscribe(const dict &req)
{
	TacFeedInitParam myreq = TacFeedInitParam();
	memset(&myreq, 0, sizeof(myreq));
	getPointer(req, "LocalIP", &myreq.LocalIP);
	getPointer(req, "LoginServerIP", &myreq.LoginServerIP);
	getUint16_t(req, "LoginServerPort", &myreq.LoginServerPort);
	getPointer(req, "UserName", &myreq.UserName);
	getPointer(req, "Password", &myreq.Password);
	//getLevel1callback(req, "L1Callback", myreq.L1Callback);
	//getLevel2callback(req, "L2Callback", myreq.L2Callback);
	//getMblcallback(req, "MblCallback", myreq.MblCallback);
	//getTacfeedapiselectmode(req, "ApiSelectMode", myreq.ApiSelectMode);
	//getTacfeedflag(req, "Flag", myreq.Flag);
	////int i = this->api->TacFeedSubscribe(&myreq);
	int i = ::TacFeedSubscribe(&myreq);
	//int i = 0;
	return i;
}

int MdApi::TacFeedRelease()
{
	///this->api->TacFeedRelease();
	this->TacFeedRelease();
}


///-------------------------------------------------------------------------------------
///Boost.python封装
///-------------------------------------------------------------------------------------
class PyMdApi : public MdApi
{
	using MdApi::MdApi;
	void Level1Callback(const dict &data) //override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onLevel1Callback, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	}
	void Level2Callback(const dict &data) //override
	{
		try
		{
			//Level2QuoteDataT t;
			//这里写代码给t赋值
			//strncpy(t.ActionDay, data["ActionDay"].c_str(),9);
			//t.AskPrice1 = data["AskPrice1"];
			PYBIND11_OVERLOAD(void, MdApi, onLevel2Callback, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	}
	void MBLCallback(const dict &data) //override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onMBLCallback, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	}
};



///-------------------------------------------------------------------------------------
///PYBIND11
///-------------------------------------------------------------------------------------
PYBIND11_MODULE(vntacmd, m)
{
	class_<MdApi, PyMdApi> MdApi(m, "MdApi");
	MdApi
		//.def(init<>)
		.def("TacFeedGetApiVersion", &MdApi::TacFeedGetApiVersion)
		.def("TacFeedSetCpuAffinity", &MdApi::TacFeedSetCpuAffinity)
		.def("TacFeedSubscrib", &MdApi::TacFeedSubscribe)
		.def("TacFeedRelease", &MdApi::TacFeedRelease)
		
		.def("onLevel1Callback", &MdApi::onLevel1Callback)
		.def("onLevel2Callback", &MdApi::onLevel1Callback)
		.def("onMBLCallback", &MdApi::onMBLCallback)
		;
		;	
}
