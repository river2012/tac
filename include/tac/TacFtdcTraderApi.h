/////////////////////////////////////////////////////////////////////////
///@system      TacMars交易系统
///@company     上海广策信息技术有限公司
///@file        TacFtdcTraderApi.h
///@brief       定义了客户端接口
///@version     1.3 
/////////////////////////////////////////////////////////////////////////

#if !defined(TAC_FTDCTRADERAPI_H)
#define TAC_FTDCTRADERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif

#include "TacFtdcUserApiStruct.h"

#if defined(IS_LIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

class CTacFtdcTraderSpi
{
public:
    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected(){};
    
    ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    virtual void OnFrontDisconnected(int nReason){};

    ///错误应答
    virtual void OnRspError(CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///用户登录应答
    virtual void OnRspUserLogin(CTacFtdcRspUserLoginField *pRspUserLogin, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///用户登出应答
    virtual void OnRspUserLogout(CTacFtdcUserLogoutField *pUserLogout, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///报单录入应答
    virtual void OnRspOrderInsert(CTacFtdcRspOrderInsertField *pRspOrderInsert, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///报单操作应答
    virtual void OnRspOrderAction(CTacFtdcRspOrderActionField *pRspOrderAction, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///报单回报
    virtual void OnRtnOrder(CTacFtdcRtnOrderField *pOrder) {};

    ///成交回报
    virtual void OnRtnTrade(CTacFtdcRtnTradeField *pTrade) {};

    ///合约查询应答
    virtual void OnRspQryInstrument(CTacFtdcInstrumentField *pInstrument, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///资金查询应答
    virtual void OnRspQryAccount(CTacFtdcAccountField *pAccount, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

    ///持仓查询应答
    virtual void OnRspQryPosition(CTacFtdcPositionField *pPosition, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

class TRADER_API_EXPORT CTacFtdcTraderApi
{
public:
    ///创建TraderApi
    ///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
    ///@return 创建出的TraderApi
    static CTacFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = ".");

    ///获取API版本号
    ///@return API版本号
    static const char *GetApiVersion();
    
    ///初始化
    ///@remark 初始化运行环境,只有调用后,接口才开始工作
    virtual void Init() = 0;

    ///删除接口对象本身
    ///@remark 不再使用本接口对象时,调用该函数删除接口对象
    virtual void Release() = 0;
    
    ///等待接口线程结束运行
    ///@return 线程退出代码
    virtual int Join() = 0;
    
    ///注册前置机网络地址
    /// url格式为：“protocol://ip:port”，如：”tcp://127.0.0.1:17001”
    virtual void RegisterFront(const char *pszFrontAddress) = 0;
    
    ///注册回调接口
    ///@param pSpi 派生自回调接口类的实例
    virtual void RegisterSpi(CTacFtdcTraderSpi *pSpi) = 0;

    ///订阅私有流。
    ///@param nResumeType 私有流重传方式  
    ///        TAC_TERT_RESTART:从本交易日开始重传
    ///        TAC_TERT_RESUME:从上次收到的续传
    ///        TAC_TERT_QUICK:只传送登录后私有流的内容
    ///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
    virtual void SubscribePrivateTopic(TAC_TE_RESUME_TYPE nResumeType) = 0;

    ///设置日志目录路径
    virtual bool SetLogFilePath(const char* pszLoggerFilePath) = 0;

    ///设置日志级别
    virtual void SetLogLevel(bool isLogMsg) = 0;

    ///绑定指定的CPU核心
    virtual int SetTraderApiCpuAffinity(int cpu1, int cpu2) = 0;

    ///获取当前交易日
    ///@retrun 获取到的交易日
    ///@remark 只有登录成功后,才能得到正确的交易日
    virtual const char *GetTradingDay() = 0;

    ///获取下一个报单引用
    ///客户端不能简单的加1来维护本地的OrderRef，必须使用本方法。
    virtual uint64_t GetNextOrderRef() = 0 ;

    ///用户登录请求
    virtual int ReqUserLogin(CTacFtdcUserLoginField *pUserLoginField, int nRequestID) = 0;

    ///用户登出请求
    virtual int ReqUserLogout(CTacFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

    ///报单录入请求
    virtual int ReqOrderInsert(CTacFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

    ///报单操作请求
    virtual int ReqOrderAction(CTacFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

    ///合约查询请求
    virtual int ReqQryInstrument(CTacFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

    ///资金查询请求
    virtual int ReqQryAccount(CTacFtdcQryAccountField *pQryAccount, int nRequestID) = 0;

    ///持仓查询请求
    virtual int ReqQryPosition(CTacFtdcQryPositionField *pQryPosition, int nRequestID) = 0;

protected:
    ~CTacFtdcTraderApi(){};
};

#endif
