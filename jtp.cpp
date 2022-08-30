/**
 * class MdApi
 * ----------------
 * On functions from CThostFtdcMdSpi to put event into a queue
 * OnFrontConnected()
 * OnFrontDisconnected(int nReason)
 * OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
 * OnRspXXX(CThostFtdcXXXField *pXXX, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
 * OnRtnXXX(CThostFtdcXXXField *pXXX)  //2个通知推送
 * ----------------
 * API from CThostFtdcMdApi
 * 3个请求API virtual int ReqXXX(CThostFtdcXXXField *pXXX, int nRequestID)
 * ----------------
 * 
 */

/**
 * class TdApi
 * ----------------
 * On functions from CThostFtdcTraderSpi to put event into a queue
 * OnFrontConnected()
 * OnFrontDisconnected(int nReason)
 * OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
 * OnRspXXX(CThostFtdcXXXField *pXXX, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
 * OnRtnXXX(CThostFtdcXXXField *pXXX)  //26个通知推送
 * OnErrXXX(CThostFtdcXXXField *pXXX, CThostFtdcRspInfoField *pRspInfo) //错误回报
 * ----------------
 * API from CThostFtdcMdApi
 * 84个请求API virtual int ReqXXX(CThostFtdcXXXField *pXXX, int nRequestID)
 * ----------------
 */

#include "jtp_mdapi.h"
#include "jtp_tdapi.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports = MdApi::AddonInit(env, exports);
    exports = TdApi::AddonInit(env, exports);
    return exports;
}

NODE_API_MODULE(jtp, Init)