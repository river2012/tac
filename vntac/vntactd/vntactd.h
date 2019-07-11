//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vntac.h"
#include "pybind11/pybind11.h"
#include "tac/TacFtdcTraderApi.h"


using namespace pybind11;

//常量
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPERROR 2
#define ONRSPAUTHENTICATE 3      //新增v14
#define ONRSPUSERLOGIN 4
#define ONRSPUSERLOGOUT 5
#define ONRSPORDERINSERT 6
#define ONRSPORDERACTION 7
#define ONRTNORDER 8
#define ONRTNTRADE 9
#define ONRSPQRYINSTRUMENT 10
#define ONRSPQRYACCOUNT 11
#define ONRSPQRYPOSITION 12


///------------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///------------------------------------------------------------------------------------------
class TdApi : public CTacFtdcTraderSpi
{
private:
	CTacFtdcTraderApi* api; //API对象
	thread task_thread;     //工作线程指针
	TaskQueue task_queue;   //工作队列
	bool active = false;	//工作状态

public:
	TdApi()
	{
	};

	~TdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	///------------------------------------------------------------------------------------------
	///C++ API回调函数
	///------------------------------------------------------------------------------------------
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected();

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	virtual void OnFrontDisconnected(int nReason);

	///错误应答
	virtual void OnRspError(CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///App认证应答   //新增v14
	virtual void OnRspAuthenticate(CTacFtdcRspAuthenticateField *pRspAuthenticate, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登录应答
	virtual void OnRspUserLogin(CTacFtdcRspUserLoginField *pRspUserLogin, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///用户登出应答
	virtual void OnRspUserLogout(CTacFtdcUserLogoutField *pUserLogout, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单录入应答
	virtual void OnRspOrderInsert(CTacFtdcRspOrderInsertField *pRspOrderInsert, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单操作应答
	virtual void OnRspOrderAction(CTacFtdcRspOrderActionField *pRspOrderAction, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///报单回报
	virtual void OnRtnOrder(CTacFtdcRtnOrderField *pOrder);

	///成交回报
	virtual void OnRtnTrade(CTacFtdcRtnTradeField *pTrade);

	///合约查询应答
	virtual void OnRspQryInstrument(CTacFtdcInstrumentField *pInstrument, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///资金查询应答
	virtual void OnRspQryAccount(CTacFtdcAccountField *pAccount, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///持仓查询应答
	virtual void OnRspQryPosition(CTacFtdcPositionField *pPosition, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///------------------------------------------------------------------------------------------
	///task:任务
	///------------------------------------------------------------------------------------------
	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspError(Task *task);

	void processRspAuthenticate(Task *task);   //新增v14

	void processRspUserLogin(Task *task);

	void processRspUserLogout(Task *task);

	void processRspOrderInsert(Task *task);

	void processRspOrderAction(Task *task);

	void processRtnOrder(Task *task);

	void processRtnTrade(Task *task);

	void processRspQryInstrument(Task *task);

	void processRspQryAccount(Task *task);

	void processRspQryPosition(Task *task);

	///------------------------------------------------------------------------------------------
	///data: 回调函数的数据字典
	///error:回调函数的错误字典
	///id:	 请求id
	///last: 是否为最后返回
	///i:    整数
	///------------------------------------------------------------------------------------------
	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onRspError(const dict &error, int reqid, bool last) {};

	virtual void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) {};   //新增v14

	virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRtnOrder(const dict &data) {};

	virtual void onRtnTrade(const dict &data) {};

	virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryAccount(const dict &data, const dict &error, int reqid, bool last) {};

	virtual void onRspQryPosition(const dict &data, const dict &error, int reqid, bool last) {};

	///------------------------------------------------------------------------------------------
	///req: 主动函数的请求字典------------------------------------------------------------------------------------------
	///------------------------------------------------------------------------------------------
	void createFtdcTraderApi(string pszFlowPath = "");

	//static const char *GetApiVersion();       //river: not use

	void init();

	void release();

	int join();

	int exit();                                 //river: added exit

	void registerFront(string pszFrontAddress); 

	//void RegisterSpi(CTacFtdcTraderSpi *pSpi); //river: not use

	void subscribePrivateTopic(int nType);

	bool setLogFilePath(string pszLoggerFilePath);//river:???

	void setLogLevel(bool isLogMsg);

	int setTraderApiCpuAffinity(int cpu1, int cpu2);

	string getTradingDay();

	//uint64_t getNextOrderRef();  //v14删除部分

	//App认证请求    v14新增
	int reqAuthenticate(const dict &req, int reqid);

	///用户登录请求
	int reqUserLogin(const dict &req, int reqid);

	///用户登出请求
	int reqUserLogout(const dict &req, int reqid);

	///报单录入请求
	int reqOrderInsert(const dict &req, int reqid);

	///报单操作请求
	int reqOrderAction(const dict &req, int reqid);

	///合约查询请求
	int reqQryInstrument(const dict &req, int reqid);

	///资金查询请求
	int reqQryAccount(const dict &req, int reqid);

	///持仓查询请求
	int reqQryPosition(const dict &req, int reqid);
};
