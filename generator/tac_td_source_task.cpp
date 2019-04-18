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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
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
		CTacFtdcRspInfoField *task_data = new CTacFtdcRspInfoField();
		*task_data = *pRspInfo;
		task.task_data = task_data;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

