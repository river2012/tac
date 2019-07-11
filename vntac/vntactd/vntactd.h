//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif

#include "vntac.h"
#include "pybind11/pybind11.h"
#include "tac/TacFtdcTraderApi.h"


using namespace pybind11;

//����
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPERROR 2
#define ONRSPAUTHENTICATE 3      //����v14
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
///C++ SPI�Ļص���������ʵ��
///------------------------------------------------------------------------------------------
class TdApi : public CTacFtdcTraderSpi
{
private:
	CTacFtdcTraderApi* api; //API����
	thread task_thread;     //�����߳�ָ��
	TaskQueue task_queue;   //��������
	bool active = false;	//����״̬

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
	///C++ API�ص�����
	///------------------------------------------------------------------------------------------
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	virtual void OnFrontDisconnected(int nReason);

	///����Ӧ��
	virtual void OnRspError(CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///App��֤Ӧ��   //����v14
	virtual void OnRspAuthenticate(CTacFtdcRspAuthenticateField *pRspAuthenticate, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CTacFtdcRspUserLoginField *pRspUserLogin, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û��ǳ�Ӧ��
	virtual void OnRspUserLogout(CTacFtdcUserLogoutField *pUserLogout, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CTacFtdcRspOrderInsertField *pRspOrderInsert, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Ӧ��
	virtual void OnRspOrderAction(CTacFtdcRspOrderActionField *pRspOrderAction, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ر�
	virtual void OnRtnOrder(CTacFtdcRtnOrderField *pOrder);

	///�ɽ��ر�
	virtual void OnRtnTrade(CTacFtdcRtnTradeField *pTrade);

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CTacFtdcInstrumentField *pInstrument, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ʽ��ѯӦ��
	virtual void OnRspQryAccount(CTacFtdcAccountField *pAccount, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ֲֲ�ѯӦ��
	virtual void OnRspQryPosition(CTacFtdcPositionField *pPosition, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///------------------------------------------------------------------------------------------
	///task:����
	///------------------------------------------------------------------------------------------
	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspError(Task *task);

	void processRspAuthenticate(Task *task);   //����v14

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
	///data: �ص������������ֵ�
	///error:�ص������Ĵ����ֵ�
	///id:	 ����id
	///last: �Ƿ�Ϊ��󷵻�
	///i:    ����
	///------------------------------------------------------------------------------------------
	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int reqid) {};

	virtual void onRspError(const dict &error, int reqid, bool last) {};

	virtual void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) {};   //����v14

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
	///req: ���������������ֵ�------------------------------------------------------------------------------------------
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

	//uint64_t getNextOrderRef();  //v14ɾ������

	//App��֤����    v14����
	int reqAuthenticate(const dict &req, int reqid);

	///�û���¼����
	int reqUserLogin(const dict &req, int reqid);

	///�û��ǳ�����
	int reqUserLogout(const dict &req, int reqid);

	///����¼������
	int reqOrderInsert(const dict &req, int reqid);

	///������������
	int reqOrderAction(const dict &req, int reqid);

	///��Լ��ѯ����
	int reqQryInstrument(const dict &req, int reqid);

	///�ʽ��ѯ����
	int reqQryAccount(const dict &req, int reqid);

	///�ֲֲ�ѯ����
	int reqQryPosition(const dict &req, int reqid);
};
