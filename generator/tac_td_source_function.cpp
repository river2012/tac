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

