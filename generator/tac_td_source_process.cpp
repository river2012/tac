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
		delete task->task_error;
	}
	this->onRspError(error, task->task_id, task->task_last);
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
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
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
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
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
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
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
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
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
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
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
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
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
		delete task->task_data;
	}
	dict error;
	if (task->task_error)
	{
		CTacFtdcRspInfoField *task_error = (CTacFtdcRspInfoField*)task->task_error;
		delete task->task_error;
	}
	this->onRspQryPosition(data, error, task->task_id, task->task_last);
};

