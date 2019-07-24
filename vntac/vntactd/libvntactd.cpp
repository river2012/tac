#include "vntactd.h"



///-----------------------------------------------------------------------
///C++回调函数将数据保存到队列中
///-----------------------------------------------------------------------
void TdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void TdApi::OnFrontDisconnected(int nReason)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nReason;
	this->task_queue.push(task);
};

void TdApi::OnRspError(CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPERROR;
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};


//v14 River
void TdApi::OnRspAuthenticate(CTacFtdcRspAuthenticateField *pRspAuthenticate, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPAUTHENTICATE;
	if (pRspAuthenticate)
	{
		CTacFtdcRspAuthenticateField *task_data = new CTacFtdcRspAuthenticateField();
		*task_data = *pRspAuthenticate;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserLogin(CTacFtdcRspUserLoginField *pRspUserLogin, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLogin)
	{
		CTacFtdcRspUserLoginField *task_data = new CTacFtdcRspUserLoginField();
		*task_data = *pRspUserLogin;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspUserLogout(CTacFtdcUserLogoutField *pUserLogout, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGOUT;
	if (pUserLogout)
	{
		CTacFtdcUserLogoutField *task_data = new CTacFtdcUserLogoutField();
		*task_data = *pUserLogout;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOrderInsert(CTacFtdcRspOrderInsertField *pRspOrderInsert, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPORDERINSERT;
	if (pRspOrderInsert)
	{
		CTacFtdcRspOrderInsertField *task_data = new CTacFtdcRspOrderInsertField();
		*task_data = *pRspOrderInsert;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(CTacFtdcRspOrderActionField *pRspOrderAction, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	if (pRspOrderAction)
	{
		CTacFtdcRspOrderActionField *task_data = new CTacFtdcRspOrderActionField();
		*task_data = *pRspOrderAction;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(CTacFtdcRtnOrderField *pOrder)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (pOrder)
	{
		CTacFtdcRtnOrderField *task_data = new CTacFtdcRtnOrderField();
		*task_data = *pOrder;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnTrade(CTacFtdcRtnTradeField *pTrade)
{
	Task task = Task();
	task.task_name = ONRTNTRADE;
	if (pTrade)
	{
		CTacFtdcRtnTradeField *task_data = new CTacFtdcRtnTradeField();
		*task_data = *pTrade;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryInstrument(CTacFtdcInstrumentField *pInstrument, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYINSTRUMENT;
	if (pInstrument)
	{
		CTacFtdcInstrumentField *task_data = new CTacFtdcInstrumentField();
		*task_data = *pInstrument;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccount(CTacFtdcAccountField *pAccount, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNT;
	if (pAccount)
	{
		CTacFtdcAccountField *task_data = new CTacFtdcAccountField();
		*task_data = *pAccount;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void TdApi::OnRspQryPosition(CTacFtdcPositionField *pPosition, CTacFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	if (pPosition)
	{
		CTacFtdcPositionField *task_data = new CTacFtdcPositionField();
		*task_data = *pPosition;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CTacFtdcRspInfoField *task_error = new CTacFtdcRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

///-----------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-----------------------------------------------------------------------
void TdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONFRONTCONNECTED:
			{
				this->processFrontConnected(&task);
				break;
			}

			case ONFRONTDISCONNECTED:
			{
				this->processFrontDisconnected(&task);
				break;
			}

			case ONRSPERROR:
			{
				this->processRspError(&task);
				break;
			}

			case ONRSPUSERLOGIN:
			{
				this->processRspUserLogin(&task);
				break;
			}

			case ONRSPUSERLOGOUT:
			{
				this->processRspUserLogout(&task);
				break;
			}

			case ONRSPORDERINSERT:
			{
				this->processRspOrderInsert(&task);
				break;
			}

			case ONRSPORDERACTION:
			{
				this->processRspOrderAction(&task);
				break;
			}

			case ONRTNORDER:
			{
				this->processRtnOrder(&task);
				break;
			}

			case ONRTNTRADE:
			{
				this->processRtnTrade(&task);
				break;
			}

			case ONRSPQRYINSTRUMENT:
			{
				this->processRspQryInstrument(&task);
				break;
			}

			case ONRSPQRYACCOUNT:
			{
				this->processRspQryAccount(&task);
				break;
			}

			case ONRSPQRYPOSITION:
			{
				this->processRspQryPosition(&task);
				break;
			}


			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};
void TdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void TdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void TdApi::processRspError(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
};

//v14
void TdApi::processRspAuthenticate(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspAuthenticateField *task_data = (CTacFtdcRspAuthenticateField*)task->task_data;
		data["AppID"] = toUtf(task_data->AppID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspAuthenticate(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspUserLoginField *task_data = (CTacFtdcRspUserLoginField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		data["MaxOrderRef"] = task_data->MaxOrderRef;
		data["SystemName"] = toUtf(task_data->SystemName);
		data["TradingDay"] = toUtf(task_data->TradingDay);
		data["LoginTime"] = toUtf(task_data->LoginTime);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspUserLogin(data, error, task->task_id, task->task_last);
};

void TdApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcUserLogoutField *task_data = (CTacFtdcUserLogoutField*)task->task_data;
		data["UserID"] = toUtf(task_data->UserID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspUserLogout(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspOrderInsertField *task_data = (CTacFtdcRspOrderInsertField*)task->task_data;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderLocalID"] = task_data->OrderLocalID;
		data["OrderSysID"] = task_data->OrderSysID;
		data["ClientID"] = toUtf(task_data->ClientID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspOrderInsert(data, error, task->task_id, task->task_last);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspOrderActionField *task_data = (CTacFtdcRspOrderActionField*)task->task_data;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderLocalID"] = task_data->OrderLocalID;
		data["ClientID"] = toUtf(task_data->ClientID);
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspOrderAction(data, error, task->task_id, task->task_last);
};

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRtnOrderField *task_data = (CTacFtdcRtnOrderField*)task->task_data;
		data["OrderSysID"] = task_data->OrderSysID;
		data["OrderLocalID"] = task_data->OrderLocalID;
		data["OrderRef"] = task_data->OrderRef;
		data["OrderStatus"] = task_data->OrderStatus;
		data["VolumeTraded"] = task_data->VolumeTraded;
		data["VolumeTotal"] = task_data->VolumeTotal;
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["OrderPriceType"] = task_data->OrderPriceType;
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["LimitPrice"] = task_data->LimitPrice;
		data["TimeCondition"] = task_data->TimeCondition;
		data["VolumeTotalOriginal"] = task_data->VolumeTotalOriginal;
		data["ExchangeID"] = task_data->ExchangeID;
		delete task->task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRtnTrade(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRtnTradeField *task_data = (CTacFtdcRtnTradeField*)task->task_data;
		data["TradeID"] = task_data->TradeID;
		data["OrderSysID"] = task_data->OrderSysID;
		data["OrderLocalID"] = task_data->OrderLocalID;
		data["OrderRef"] = task_data->OrderRef;
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["Direction"] = task_data->Direction;
		data["OffsetFlag"] = task_data->OffsetFlag;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["Price"] = task_data->Price;
		data["Volume"] = task_data->Volume;
		data["ExchangeID"] = task_data->ExchangeID;
		delete task->task_data;
	}
	this->onRtnTrade(data);
};

void TdApi::processRspQryInstrument(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcInstrumentField *task_data = (CTacFtdcInstrumentField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeID"] = task_data->ExchangeID;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["PriceTick"] = task_data->PriceTick;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["LongMarginRatio"] = task_data->LongMarginRatio;
		data["ShortMarginRatio"] = task_data->ShortMarginRatio;
		data["MaxMarginSideAlgorithm"] = task_data->MaxMarginSideAlgorithm;
		data["OpenRatioByMoney"] = task_data->OpenRatioByMoney;
		data["CloseRatioByMoney"] = task_data->CloseRatioByMoney;
		data["CloseTodayRatioByMoney"] = task_data->CloseTodayRatioByMoney;
		data["OpenRatioByVolume"] = task_data->OpenRatioByVolume;
		data["CloseRatioByVolume"] = task_data->CloseRatioByVolume;
		data["CloseTodayRatioByVolume"] = task_data->CloseTodayRatioByVolume;
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspQryInstrument(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcAccountField *task_data = (CTacFtdcAccountField*)task->task_data;
		data["ClientID"] = toUtf(task_data->ClientID);
		data["InitFund"] = task_data->InitFund;
		data["FrozenMargin"] = task_data->FrozenMargin;
		data["FrozenFee"] = task_data->FrozenFee;
		data["CurrMargin"] = task_data->CurrMargin;
		data["Fee"] = task_data->Fee;
		data["CloseProfit"] = task_data->CloseProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["Available"] = task_data->Available;
		data["Balance"] = task_data->Balance;
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspQryAccount(data, error, task->task_id, task->task_last);
};

void TdApi::processRspQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcPositionField *task_data = (CTacFtdcPositionField*)task->task_data;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PosiDirection"] = task_data->PosiDirection;
		data["YdPosition"] = task_data->YdPosition;
		data["Position"] = task_data->Position;
		data["LongFrozen"] = task_data->LongFrozen;
		data["ShortFrozen"] = task_data->ShortFrozen;
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task->task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};



///-----------------------------------------------------------------------
///主动函数
///-----------------------------------------------------------------------
void TdApi::createFtdcTraderApi(string pszFlowPath)
{
	this->api = CTacFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};

void TdApi::release()
{
	this->api->Release();
};

void TdApi::init()
{
	this->active = true;
	this->task_thread = thread(&TdApi::processTask, this);
	this->api->Init();
};

int TdApi::join()
{
	int i = this->api->Join();
	return i;
};

int TdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->Release();
	this->api = NULL;
	return 1;
};

string TdApi::getTradingDay()
{
	string day = this->api->GetTradingDay();
	return day;
};
void TdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront((char*)pszFrontAddress.c_str());
};

//v14
int TdApi::reqAuthenticate(const dict &req, int reqid)
{
	CTacFtdcAuthenticateField myreq = CTacFtdcAuthenticateField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AppID", myreq.AppID);
	getString(req, "AuthCode", myreq.AuthCode);
	int i = this->api->ReqAuthenticate(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogin(const dict &req, int reqid)
{
	CTacFtdcUserLoginField myreq = CTacFtdcUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	getString(req, "Password", myreq.Password);
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogout(const dict &req, int reqid)
{
	CTacFtdcUserLogoutField myreq = CTacFtdcUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserID", myreq.UserID);
	int i = this->api->ReqUserLogout(&myreq, reqid);
	return i;
};

int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CTacFtdcInputOrderField myreq = CTacFtdcInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "InstrumentID", myreq.InstrumentID);
	getChar(req, "OrderPriceType", &myreq.OrderPriceType);
	getChar(req, "Direction", &myreq.Direction);
	getChar(req, "OffsetFlag", &myreq.OffsetFlag);
	getDouble(req, "LimitPrice", &myreq.LimitPrice);
	getInt(req, "VolumeTotalOriginal", &myreq.VolumeTotalOriginal);
	getChar(req, "TimeCondition", &myreq.TimeCondition);
	getUint64_t(req, "OrderRef", &myreq.OrderRef);
	getString(req, "ClientID", myreq.ClientID);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CTacFtdcInputOrderActionField myreq = CTacFtdcInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	getUint64_t(req, "OrderRef", &myreq.OrderRef);
	getUint64_t(req, "OrderLocalID", &myreq.OrderLocalID);
	getString(req, "ClientID", myreq.ClientID);
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CTacFtdcQryInstrumentField myreq = CTacFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ExchangeID", &myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	getString(req, "ClientID", myreq.ClientID);
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryAccount(const dict &req, int reqid)
{
	CTacFtdcQryAccountField myreq = CTacFtdcQryAccountField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ClientID", myreq.ClientID);
	int i = this->api->ReqQryAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryPosition(const dict &req, int reqid)
{
	CTacFtdcQryPositionField myreq = CTacFtdcQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ClientID", myreq.ClientID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryPosition(&myreq, reqid);
	return i;
};


///-----------------------------------------------------------------------
///Boost.python封装
///-----------------------------------------------------------------------
class PyTdApi : public TdApi
{
	using TdApi::TdApi;
	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontConnected);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFrontDisconnected(int reqid) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onFrontDisconnected, reqid);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspError(const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspError, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	//v14
	void onRspAuthenticate(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspAuthenticate, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspUserLogin, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspUserLogout, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderInsert, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOrder(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTrade(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnTrade, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrument, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccount(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccount, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPosition(const dict &data, const dict &error, int reqid, bool last) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, data, error, reqid, last);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

};


///-----------------------------------------------------------------------
///PYBINd11
///-----------------------------------------------------------------------
PYBIND11_MODULE(libvntactd, m)
{
	class_<TdApi, PyTdApi> TdApi(m, "TdApi");
	TdApi
		.def(init<>())
		.def("createFtdcTraderApi", &TdApi::createFtdcTraderApi)
		.def("release",&TdApi::release)
		.def("init", &TdApi::init)
		.def("join", &TdApi::join)
		.def("exit", &TdApi::exit)
		.def("getTradingDay", &TdApi::getTradingDay)
		.def("registerFront", &TdApi::registerFront)
		
		.def("reqAuthenticate", &TdApi::reqAuthenticate)  
		.def("reqUserLogin", &TdApi::reqUserLogin)
		.def("reqUserLogout", &TdApi::reqUserLogout)
		.def("reqOrderInsert", &TdApi::reqOrderInsert)
		.def("reqOrderAction", &TdApi::reqOrderAction)
		.def("reqQryInstrument", &TdApi::reqQryInstrument)
		.def("reqQryAccount", &TdApi::reqQryAccount)
		.def("reqQryPosition", &TdApi::reqQryPosition)

		.def("onFrontConnected", &TdApi::onFrontConnected)
		.def("onFrontDisconnected", &TdApi::onFrontDisconnected)
		.def("onRspError", &TdApi::onRspError)
		.def("onRspAuthenticate", &TdApi::onRspAuthenticate) 
		.def("onRspUserLogin", &TdApi::onRspUserLogin)
		.def("onRspUserLogout", &TdApi::onRspUserLogout)
		.def("onRspOrderInsert", &TdApi::onRspOrderInsert)
		.def("onRspOrderAction", &TdApi::onRspOrderAction)
		.def("onRtnOrder", &TdApi::onRtnOrder)
		.def("onRtnTrade", &TdApi::onRtnTrade)
		.def("onRspQryInstrument", &TdApi::onRspQryInstrument)
		.def("onRspQryAccount", &TdApi::onRspQryAccount)
		.def("onRspQryPosition", &TdApi::onRspQryPosition)
		;
		;
		;
}

