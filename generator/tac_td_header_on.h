virtual void onFrontConnected() {};

virtual void onFrontDisconnected(int reqid) {};

virtual void onRspError(const dict &error, int reqid, bool last) {};

virtual void onRspUserLogin(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspUserLogout(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspOrderInsert(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspOrderAction(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRtnOrder(const dict &data) {};

virtual void onRtnTrade(const dict &data) {};

virtual void onRspQryInstrument(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryAccount(const dict &data, const dict &error, int reqid, bool last) {};

virtual void onRspQryPosition(const dict &data, const dict &error, int reqid, bool last) {};

