CTacFtdcRspInfoField = {
    "ErrorID": "int",
    "ErrorMsg": "string",
}

CTacFtdcUserLoginField = {
    "UserID": "string",
    "Password": "string",
}

CTacFtdcRspUserLoginField = {
    "UserID": "string",
    "MaxOrderRef": "uint64_t",
    "SystemName": "string",
    "TradingDay": "string",
    "LoginTime": "string",
}

CTacFtdcUserLogoutField = {
    "UserID": "string",
}

CTacFtdcInputOrderField = {
    "InstrumentID": "string",
    "OrderPriceType": "char",
    "Direction": "char",
    "OffsetFlag": "char",
    "LimitPrice": "double",
    "VolumeTotalOriginal": "int",
    "TimeCondition": "char",
    "OrderRef": "uint64_t",
    "ClientID": "string",
    "HedgeFlag": "char",
    "ExchangeID": "char",
}

CTacFtdcRspOrderInsertField = {
    "OrderRef": "uint64_t",
    "OrderLocalID": "uint64_t",
    "OrderSysID": "uint64_t",
    "ClientID": "string",
}

CTacFtdcInputOrderActionField = {
    "OrderRef": "uint64_t",
    "OrderLocalID": "uint64_t",
    "ClientID": "string",
}

CTacFtdcRspOrderActionField = {
    "OrderRef": "uint64_t",
    "OrderLocalID": "uint64_t",
    "ClientID": "string",
}

CTacFtdcRtnOrderField = {
    "OrderSysID": "uint64_t",
    "OrderLocalID": "uint64_t",
    "OrderRef": "uint64_t",
    "OrderStatus": "char",
    "VolumeTraded": "int",
    "VolumeTotal": "int",
    "ClientID": "string",
    "InstrumentID": "string",
    "OrderPriceType": "char",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeFlag": "char",
    "LimitPrice": "double",
    "TimeCondition": "char",
    "VolumeTotalOriginal": "int",
    "ExchangeID": "char",
}

CTacFtdcRtnTradeField = {
    "TradeID": "uint64_t",
    "OrderSysID": "uint64_t",
    "OrderLocalID": "uint64_t",
    "OrderRef": "uint64_t",
    "ClientID": "string",
    "InstrumentID": "string",
    "Direction": "char",
    "OffsetFlag": "char",
    "HedgeFlag": "char",
    "Price": "double",
    "Volume": "int",
    "ExchangeID": "char",
}

CTacFtdcQryInstrumentField = {
    "ExchangeID": "char",
    "InstrumentID": "string",
    "ClientID": "string",
}

CTacFtdcInstrumentField = {
    "InstrumentID": "string",
    "ExchangeID": "char",
    "MaxLimitOrderVolume": "int",
    "MinLimitOrderVolume": "int",
    "VolumeMultiple": "int",
    "PriceTick": "double",
    "PreSettlementPrice": "double",
    "UpperLimitPrice": "double",
    "LowerLimitPrice": "double",
    "LongMarginRatio": "double",
    "ShortMarginRatio": "double",
    "MaxMarginSideAlgorithm": "bool",
    "OpenRatioByMoney": "double",
    "CloseRatioByMoney": "double",
    "CloseTodayRatioByMoney": "double",
    "OpenRatioByVolume": "double",
    "CloseRatioByVolume": "double",
    "CloseTodayRatioByVolume": "double",
}

CTacFtdcQryAccountField = {
    "ClientID": "string",
}

CTacFtdcAccountField = {
    "ClientID": "string",
    "InitFund": "double",
    "FrozenMargin": "double",
    "FrozenFee": "double",
    "CurrMargin": "double",
    "Fee": "double",
    "CloseProfit": "double",
    "PositionProfit": "double",
    "Available": "double",
    "Balance": "double",
}

CTacFtdcQryPositionField = {
    "ClientID": "string",
    "InstrumentID": "string",
}

CTacFtdcPositionField = {
    "InstrumentID": "string",
    "ClientID": "string",
    "HedgeFlag": "char",
    "PosiDirection": "char",
    "YdPosition": "int",
    "Position": "int",
    "LongFrozen": "int",
    "ShortFrozen": "int",
}

