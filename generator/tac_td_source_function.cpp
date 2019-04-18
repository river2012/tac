int TdApi::reqUserLogin(const dict &req, int reqid)
{
	CTacFtdcUserLoginField myreq = CTacFtdcUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
};

int TdApi::reqUserLogout(const dict &req, int reqid)
{
	CTacFtdcUserLogoutField myreq = CTacFtdcUserLogoutField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqUserLogout(&myreq, reqid);
	return i;
};

int TdApi::reqOrderInsert(const dict &req, int reqid)
{
	CTacFtdcInputOrderField myreq = CTacFtdcInputOrderField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqOrderInsert(&myreq, reqid);
	return i;
};

int TdApi::reqOrderAction(const dict &req, int reqid)
{
	CTacFtdcInputOrderActionField myreq = CTacFtdcInputOrderActionField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqOrderAction(&myreq, reqid);
	return i;
};

int TdApi::reqQryInstrument(const dict &req, int reqid)
{
	CTacFtdcQryInstrumentField myreq = CTacFtdcQryInstrumentField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQryInstrument(&myreq, reqid);
	return i;
};

int TdApi::reqQryAccount(const dict &req, int reqid)
{
	CTacFtdcQryAccountField myreq = CTacFtdcQryAccountField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQryAccount(&myreq, reqid);
	return i;
};

int TdApi::reqQryPosition(const dict &req, int reqid)
{
	CTacFtdcQryPositionField myreq = CTacFtdcQryPositionField();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->ReqQryPosition(&myreq, reqid);
	return i;
};

