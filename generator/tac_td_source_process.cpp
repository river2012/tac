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

