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

void onRspError(const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspError, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserLogin(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspUserLogin, data, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUserLogout(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspUserLogout, data, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderInsert(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderInsert, data, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderAction(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, data, data, reqid, last);
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

void onRspQryInstrument(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryInstrument, data, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccount(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccount, data, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPosition(const dict &data, const dict &data, int reqid, bool last) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, data, data, reqid, last);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

