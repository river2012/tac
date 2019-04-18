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
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspError(data, task->task_id, task->task_last);
};

void TdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspUserLoginField *task_data = (CTacFtdcRspUserLoginField*)task->task_data;
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspUserLogin(data, data, task->task_id, task->task_last);
};

void TdApi::processRspUserLogout(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcUserLogoutField *task_data = (CTacFtdcUserLogoutField*)task->task_data;
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspUserLogout(data, data, task->task_id, task->task_last);
};

void TdApi::processRspOrderInsert(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspOrderInsertField *task_data = (CTacFtdcRspOrderInsertField*)task->task_data;
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspOrderInsert(data, data, task->task_id, task->task_last);
};

void TdApi::processRspOrderAction(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspOrderActionField *task_data = (CTacFtdcRspOrderActionField*)task->task_data;
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspOrderAction(data, data, task->task_id, task->task_last);
};

void TdApi::processRtnOrder(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcRtnOrderField *task_data = (CTacFtdcRtnOrderField*)task->task_data;
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
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspQryInstrument(data, data, task->task_id, task->task_last);
};

void TdApi::processRspQryAccount(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcAccountField *task_data = (CTacFtdcAccountField*)task->task_data;
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspQryAccount(data, data, task->task_id, task->task_last);
};

void TdApi::processRspQryPosition(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CTacFtdcPositionField *task_data = (CTacFtdcPositionField*)task->task_data;
		delete task->task_data;
	}
	dict data;
	if (task->task_data)
	{
		CTacFtdcRspInfoField *task_data = (CTacFtdcRspInfoField*)task->task_data;
		delete task->task_data;
	}
	this->onRspQryPosition(data, data, task->task_id, task->task_last);
};

