#ifndef JTP_TDAPI_H
#define JTP_TDAPI_H

#include <iostream>
#include <thread>

#include <napi.h>

#include "ThostFtdcTraderApi.h"

using namespace std;

class TdApi : public CThostFtdcTraderSpi, public Napi::ObjectWrap<TdApi>
{
private:
    CThostFtdcTraderApi *api;

public:
    static Napi::Object AddonInit(Napi::Env env, Napi::Object exports)
    {
        Napi::Function func =
            DefineClass(env,
                        "TdApi",
                        {
                            InstanceMethod("getEmitter", &TdApi::getEmitter),
                            InstanceMethod("closeEmitter", &TdApi::closeEmitter),
                            InstanceMethod("CreateFtdcTraderApi", &TdApi::CreateFtdcTraderApi),
                            InstanceMethod("GetApiVersion", &TdApi::GetApiVersion),
                            InstanceMethod("Release", &TdApi::Release),
                            InstanceMethod("Init", &TdApi::Init),
                            InstanceMethod("Join", &TdApi::Join),
                            InstanceMethod("GetTradingDay", &TdApi::GetTradingDay),
                            InstanceMethod("RegisterFront", &TdApi::RegisterFront),
                            InstanceMethod("RegisterNameServer", &TdApi::RegisterNameServer),
                            InstanceMethod("RegisterFensUserInfo", &TdApi::RegisterFensUserInfo),
                            InstanceMethod("RegisterSpi", &TdApi::RegisterSpi),
                            InstanceMethod("SubscribePrivateTopic", &TdApi::SubscribePrivateTopic),
                            InstanceMethod("SubscribePublicTopic", &TdApi::SubscribePublicTopic),
                            InstanceMethod("ReqAuthenticate", &TdApi::ReqAuthenticate),
                            InstanceMethod("RegisterUserSystemInfo", &TdApi::RegisterUserSystemInfo),
                            InstanceMethod("SubmitUserSystemInfo", &TdApi::SubmitUserSystemInfo),
                            InstanceMethod("ReqUserLogin", &TdApi::ReqUserLogin),
                            InstanceMethod("ReqUserLogout", &TdApi::ReqUserLogout),
                            InstanceMethod("ReqUserPasswordUpdate", &TdApi::ReqUserPasswordUpdate),
                            InstanceMethod("ReqTradingAccountPasswordUpdate", &TdApi::ReqTradingAccountPasswordUpdate),
                            InstanceMethod("ReqUserAuthMethod", &TdApi::ReqUserAuthMethod),
                            InstanceMethod("ReqGenUserCaptcha", &TdApi::ReqGenUserCaptcha),
                            InstanceMethod("ReqGenUserText", &TdApi::ReqGenUserText),
                            InstanceMethod("ReqUserLoginWithCaptcha", &TdApi::ReqUserLoginWithCaptcha),
                            InstanceMethod("ReqUserLoginWithText", &TdApi::ReqUserLoginWithText),
                            InstanceMethod("ReqUserLoginWithOTP", &TdApi::ReqUserLoginWithOTP),
                            InstanceMethod("ReqOrderInsert", &TdApi::ReqOrderInsert),
                            InstanceMethod("ReqParkedOrderInsert", &TdApi::ReqParkedOrderInsert),
                            InstanceMethod("ReqParkedOrderAction", &TdApi::ReqParkedOrderAction),
                            InstanceMethod("ReqOrderAction", &TdApi::ReqOrderAction),
                            InstanceMethod("ReqQryMaxOrderVolume", &TdApi::ReqQryMaxOrderVolume),
                            InstanceMethod("ReqSettlementInfoConfirm", &TdApi::ReqSettlementInfoConfirm),
                            InstanceMethod("ReqRemoveParkedOrder", &TdApi::ReqRemoveParkedOrder),
                            InstanceMethod("ReqRemoveParkedOrderAction", &TdApi::ReqRemoveParkedOrderAction),
                            InstanceMethod("ReqExecOrderInsert", &TdApi::ReqExecOrderInsert),
                            InstanceMethod("ReqExecOrderAction", &TdApi::ReqExecOrderAction),
                            InstanceMethod("ReqForQuoteInsert", &TdApi::ReqForQuoteInsert),
                            InstanceMethod("ReqQuoteInsert", &TdApi::ReqQuoteInsert),
                            InstanceMethod("ReqQuoteAction", &TdApi::ReqQuoteAction),
                            InstanceMethod("ReqBatchOrderAction", &TdApi::ReqBatchOrderAction),
                            InstanceMethod("ReqOptionSelfCloseInsert", &TdApi::ReqOptionSelfCloseInsert),
                            InstanceMethod("ReqOptionSelfCloseAction", &TdApi::ReqOptionSelfCloseAction),
                            InstanceMethod("ReqCombActionInsert", &TdApi::ReqCombActionInsert),
                            InstanceMethod("ReqQryOrder", &TdApi::ReqQryOrder),
                            InstanceMethod("ReqQryTrade", &TdApi::ReqQryTrade),
                            InstanceMethod("ReqQryInvestorPosition", &TdApi::ReqQryInvestorPosition),
                            InstanceMethod("ReqQryTradingAccount", &TdApi::ReqQryTradingAccount),
                            InstanceMethod("ReqQryInvestor", &TdApi::ReqQryInvestor),
                            InstanceMethod("ReqQryTradingCode", &TdApi::ReqQryTradingCode),
                            InstanceMethod("ReqQryInstrumentMarginRate", &TdApi::ReqQryInstrumentMarginRate),
                            InstanceMethod("ReqQryInstrumentCommissionRate", &TdApi::ReqQryInstrumentCommissionRate),
                            InstanceMethod("ReqQryExchange", &TdApi::ReqQryExchange),
                            InstanceMethod("ReqQryProduct", &TdApi::ReqQryProduct),
                            InstanceMethod("ReqQryInstrument", &TdApi::ReqQryInstrument),
                            InstanceMethod("ReqQryDepthMarketData", &TdApi::ReqQryDepthMarketData),
                            InstanceMethod("ReqQrySettlementInfo", &TdApi::ReqQrySettlementInfo),
                            InstanceMethod("ReqQryTransferBank", &TdApi::ReqQryTransferBank),
                            InstanceMethod("ReqQryInvestorPositionDetail", &TdApi::ReqQryInvestorPositionDetail),
                            InstanceMethod("ReqQryNotice", &TdApi::ReqQryNotice),
                            InstanceMethod("ReqQrySettlementInfoConfirm", &TdApi::ReqQrySettlementInfoConfirm),
                            InstanceMethod("ReqQryInvestorPositionCombineDetail", &TdApi::ReqQryInvestorPositionCombineDetail),
                            InstanceMethod("ReqQryCFMMCTradingAccountKey", &TdApi::ReqQryCFMMCTradingAccountKey),
                            InstanceMethod("ReqQryEWarrantOffset", &TdApi::ReqQryEWarrantOffset),
                            InstanceMethod("ReqQryInvestorProductGroupMargin", &TdApi::ReqQryInvestorProductGroupMargin),
                            InstanceMethod("ReqQryExchangeMarginRate", &TdApi::ReqQryExchangeMarginRate),
                            InstanceMethod("ReqQryExchangeMarginRateAdjust", &TdApi::ReqQryExchangeMarginRateAdjust),
                            InstanceMethod("ReqQryExchangeRate", &TdApi::ReqQryExchangeRate),
                            InstanceMethod("ReqQrySecAgentACIDMap", &TdApi::ReqQrySecAgentACIDMap),
                            InstanceMethod("ReqQryProductExchRate", &TdApi::ReqQryProductExchRate),
                            InstanceMethod("ReqQryProductGroup", &TdApi::ReqQryProductGroup),
                            InstanceMethod("ReqQryMMInstrumentCommissionRate", &TdApi::ReqQryMMInstrumentCommissionRate),
                            InstanceMethod("ReqQryMMOptionInstrCommRate", &TdApi::ReqQryMMOptionInstrCommRate),
                            InstanceMethod("ReqQryInstrumentOrderCommRate", &TdApi::ReqQryInstrumentOrderCommRate),
                            InstanceMethod("ReqQrySecAgentTradingAccount", &TdApi::ReqQrySecAgentTradingAccount),
                            InstanceMethod("ReqQrySecAgentCheckMode", &TdApi::ReqQrySecAgentCheckMode),
                            InstanceMethod("ReqQrySecAgentTradeInfo", &TdApi::ReqQrySecAgentTradeInfo),
                            InstanceMethod("ReqQryOptionInstrTradeCost", &TdApi::ReqQryOptionInstrTradeCost),
                            InstanceMethod("ReqQryOptionInstrCommRate", &TdApi::ReqQryOptionInstrCommRate),
                            InstanceMethod("ReqQryExecOrder", &TdApi::ReqQryExecOrder),
                            InstanceMethod("ReqQryForQuote", &TdApi::ReqQryForQuote),
                            InstanceMethod("ReqQryQuote", &TdApi::ReqQryQuote),
                            InstanceMethod("ReqQryOptionSelfClose", &TdApi::ReqQryOptionSelfClose),
                            InstanceMethod("ReqQryInvestUnit", &TdApi::ReqQryInvestUnit),
                            InstanceMethod("ReqQryCombInstrumentGuard", &TdApi::ReqQryCombInstrumentGuard),
                            InstanceMethod("ReqQryCombAction", &TdApi::ReqQryCombAction),
                            InstanceMethod("ReqQryTransferSerial", &TdApi::ReqQryTransferSerial),
                            InstanceMethod("ReqQryAccountregister", &TdApi::ReqQryAccountregister),
                            InstanceMethod("ReqQryContractBank", &TdApi::ReqQryContractBank),
                            InstanceMethod("ReqQryParkedOrder", &TdApi::ReqQryParkedOrder),
                            InstanceMethod("ReqQryParkedOrderAction", &TdApi::ReqQryParkedOrderAction),
                            InstanceMethod("ReqQryTradingNotice", &TdApi::ReqQryTradingNotice),
                            InstanceMethod("ReqQryBrokerTradingParams", &TdApi::ReqQryBrokerTradingParams),
                            InstanceMethod("ReqQryBrokerTradingAlgos", &TdApi::ReqQryBrokerTradingAlgos),
                            InstanceMethod("ReqQueryCFMMCTradingAccountToken", &TdApi::ReqQueryCFMMCTradingAccountToken),
                            InstanceMethod("ReqFromBankToFutureByFuture", &TdApi::ReqFromBankToFutureByFuture),
                            InstanceMethod("ReqFromFutureToBankByFuture", &TdApi::ReqFromFutureToBankByFuture),
                            InstanceMethod("ReqQueryBankAccountMoneyByFuture", &TdApi::ReqQueryBankAccountMoneyByFuture),
                            InstanceMethod("ReqQryClassifiedInstrument", &TdApi::ReqQryClassifiedInstrument),
                            InstanceMethod("ReqQryCombPromotionParam", &TdApi::ReqQryCombPromotionParam),
                            InstanceMethod("ReqQryRiskSettleInvstPosition", &TdApi::ReqQryRiskSettleInvstPosition),
                            InstanceMethod("ReqQryRiskSettleProductStatus", &TdApi::ReqQryRiskSettleProductStatus),

                        });

        Napi::FunctionReference *constructor = new Napi::FunctionReference();
        *constructor = Napi::Persistent(func);
        env.SetInstanceData(constructor);
        exports.Set("TdApi", func);
        return exports;
    }
    TdApi(const Napi::CallbackInfo &info) : Napi::ObjectWrap<TdApi>(info)
    {

    }
    ~TdApi()
    {

    }

    void OnFrontConnected()
    {
        
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnFrontConnected");
            Napi::Object js_event_data = Napi::Object::New(env);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnFrontDisconnected(int nReason)
    {
        
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnFrontDisconnected");
            Napi::Object js_event_data = Napi::Object::New(env);
            js_event_data.Set("nReason", nReason);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnHeartBeatWarning(int nTimeLapse)
    {
        
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnHeartBeatWarning");
            Napi::Object js_event_data = Napi::Object::New(env);
            js_event_data.Set("nTimeLapse", nTimeLapse);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspAuthenticate(CThostFtdcRspAuthenticateField * pRspAuthenticateField, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRspAuthenticateField *ptrCfd_pRspAuthenticateField = new CThostFtdcRspAuthenticateField();
        if(pRspAuthenticateField)
        {
            memcpy(ptrCfd_pRspAuthenticateField, pRspAuthenticateField, sizeof(CThostFtdcRspAuthenticateField));
        }
        else
        {
            memset(ptrCfd_pRspAuthenticateField, 0, sizeof(CThostFtdcRspAuthenticateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspAuthenticate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspAuthenticateField = Napi::Object::New(env);
            js_pRspAuthenticateField.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspAuthenticateField->BrokerID, strlen(ptrCfd_pRspAuthenticateField->BrokerID)) );
            js_pRspAuthenticateField.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspAuthenticateField->UserID, strlen(ptrCfd_pRspAuthenticateField->UserID)) );
            js_pRspAuthenticateField.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspAuthenticateField->UserProductInfo, strlen(ptrCfd_pRspAuthenticateField->UserProductInfo)) );
            js_pRspAuthenticateField.Set("AppID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspAuthenticateField->AppID, strlen(ptrCfd_pRspAuthenticateField->AppID)) );
            js_pRspAuthenticateField.Set("AppType", string(1u, ptrCfd_pRspAuthenticateField->AppType).c_str());
            js_event_data.Set("pRspAuthenticateField", js_pRspAuthenticateField);
            delete ptrCfd_pRspAuthenticateField;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRspUserLoginField *ptrCfd_pRspUserLogin = new CThostFtdcRspUserLoginField();
        if(pRspUserLogin)
        {
            memcpy(ptrCfd_pRspUserLogin, pRspUserLogin, sizeof(CThostFtdcRspUserLoginField));
        }
        else
        {
            memset(ptrCfd_pRspUserLogin, 0, sizeof(CThostFtdcRspUserLoginField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspUserLogin");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspUserLogin = Napi::Object::New(env);
            js_pRspUserLogin.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->TradingDay, strlen(ptrCfd_pRspUserLogin->TradingDay)) );
            js_pRspUserLogin.Set("LoginTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->LoginTime, strlen(ptrCfd_pRspUserLogin->LoginTime)) );
            js_pRspUserLogin.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->BrokerID, strlen(ptrCfd_pRspUserLogin->BrokerID)) );
            js_pRspUserLogin.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->UserID, strlen(ptrCfd_pRspUserLogin->UserID)) );
            js_pRspUserLogin.Set("SystemName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->SystemName, strlen(ptrCfd_pRspUserLogin->SystemName)) );
            js_pRspUserLogin.Set("FrontID", ptrCfd_pRspUserLogin->FrontID);
            js_pRspUserLogin.Set("SessionID", ptrCfd_pRspUserLogin->SessionID);
            js_pRspUserLogin.Set("MaxOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->MaxOrderRef, strlen(ptrCfd_pRspUserLogin->MaxOrderRef)) );
            js_pRspUserLogin.Set("SHFETime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->SHFETime, strlen(ptrCfd_pRspUserLogin->SHFETime)) );
            js_pRspUserLogin.Set("DCETime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->DCETime, strlen(ptrCfd_pRspUserLogin->DCETime)) );
            js_pRspUserLogin.Set("CZCETime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->CZCETime, strlen(ptrCfd_pRspUserLogin->CZCETime)) );
            js_pRspUserLogin.Set("FFEXTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->FFEXTime, strlen(ptrCfd_pRspUserLogin->FFEXTime)) );
            js_pRspUserLogin.Set("INETime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspUserLogin->INETime, strlen(ptrCfd_pRspUserLogin->INETime)) );
            js_event_data.Set("pRspUserLogin", js_pRspUserLogin);
            delete ptrCfd_pRspUserLogin;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspUserLogout(CThostFtdcUserLogoutField * pUserLogout, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcUserLogoutField *ptrCfd_pUserLogout = new CThostFtdcUserLogoutField();
        if(pUserLogout)
        {
            memcpy(ptrCfd_pUserLogout, pUserLogout, sizeof(CThostFtdcUserLogoutField));
        }
        else
        {
            memset(ptrCfd_pUserLogout, 0, sizeof(CThostFtdcUserLogoutField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspUserLogout");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pUserLogout = Napi::Object::New(env);
            js_pUserLogout.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pUserLogout->BrokerID, strlen(ptrCfd_pUserLogout->BrokerID)) );
            js_pUserLogout.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pUserLogout->UserID, strlen(ptrCfd_pUserLogout->UserID)) );
            js_event_data.Set("pUserLogout", js_pUserLogout);
            delete ptrCfd_pUserLogout;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField * pUserPasswordUpdate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcUserPasswordUpdateField *ptrCfd_pUserPasswordUpdate = new CThostFtdcUserPasswordUpdateField();
        if(pUserPasswordUpdate)
        {
            memcpy(ptrCfd_pUserPasswordUpdate, pUserPasswordUpdate, sizeof(CThostFtdcUserPasswordUpdateField));
        }
        else
        {
            memset(ptrCfd_pUserPasswordUpdate, 0, sizeof(CThostFtdcUserPasswordUpdateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspUserPasswordUpdate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pUserPasswordUpdate = Napi::Object::New(env);
            js_pUserPasswordUpdate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pUserPasswordUpdate->BrokerID, strlen(ptrCfd_pUserPasswordUpdate->BrokerID)) );
            js_pUserPasswordUpdate.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pUserPasswordUpdate->UserID, strlen(ptrCfd_pUserPasswordUpdate->UserID)) );
            js_pUserPasswordUpdate.Set("OldPassword", Napi::Buffer<char>::Copy(env, ptrCfd_pUserPasswordUpdate->OldPassword, strlen(ptrCfd_pUserPasswordUpdate->OldPassword)) );
            js_pUserPasswordUpdate.Set("NewPassword", Napi::Buffer<char>::Copy(env, ptrCfd_pUserPasswordUpdate->NewPassword, strlen(ptrCfd_pUserPasswordUpdate->NewPassword)) );
            js_event_data.Set("pUserPasswordUpdate", js_pUserPasswordUpdate);
            delete ptrCfd_pUserPasswordUpdate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField * pTradingAccountPasswordUpdate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTradingAccountPasswordUpdateField *ptrCfd_pTradingAccountPasswordUpdate = new CThostFtdcTradingAccountPasswordUpdateField();
        if(pTradingAccountPasswordUpdate)
        {
            memcpy(ptrCfd_pTradingAccountPasswordUpdate, pTradingAccountPasswordUpdate, sizeof(CThostFtdcTradingAccountPasswordUpdateField));
        }
        else
        {
            memset(ptrCfd_pTradingAccountPasswordUpdate, 0, sizeof(CThostFtdcTradingAccountPasswordUpdateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspTradingAccountPasswordUpdate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTradingAccountPasswordUpdate = Napi::Object::New(env);
            js_pTradingAccountPasswordUpdate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccountPasswordUpdate->BrokerID, strlen(ptrCfd_pTradingAccountPasswordUpdate->BrokerID)) );
            js_pTradingAccountPasswordUpdate.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccountPasswordUpdate->AccountID, strlen(ptrCfd_pTradingAccountPasswordUpdate->AccountID)) );
            js_pTradingAccountPasswordUpdate.Set("OldPassword", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccountPasswordUpdate->OldPassword, strlen(ptrCfd_pTradingAccountPasswordUpdate->OldPassword)) );
            js_pTradingAccountPasswordUpdate.Set("NewPassword", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccountPasswordUpdate->NewPassword, strlen(ptrCfd_pTradingAccountPasswordUpdate->NewPassword)) );
            js_pTradingAccountPasswordUpdate.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccountPasswordUpdate->CurrencyID, strlen(ptrCfd_pTradingAccountPasswordUpdate->CurrencyID)) );
            js_event_data.Set("pTradingAccountPasswordUpdate", js_pTradingAccountPasswordUpdate);
            delete ptrCfd_pTradingAccountPasswordUpdate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField * pRspUserAuthMethod, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRspUserAuthMethodField *ptrCfd_pRspUserAuthMethod = new CThostFtdcRspUserAuthMethodField();
        if(pRspUserAuthMethod)
        {
            memcpy(ptrCfd_pRspUserAuthMethod, pRspUserAuthMethod, sizeof(CThostFtdcRspUserAuthMethodField));
        }
        else
        {
            memset(ptrCfd_pRspUserAuthMethod, 0, sizeof(CThostFtdcRspUserAuthMethodField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspUserAuthMethod");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspUserAuthMethod = Napi::Object::New(env);
            js_pRspUserAuthMethod.Set("UsableAuthMethod", ptrCfd_pRspUserAuthMethod->UsableAuthMethod);
            js_event_data.Set("pRspUserAuthMethod", js_pRspUserAuthMethod);
            delete ptrCfd_pRspUserAuthMethod;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField * pRspGenUserCaptcha, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRspGenUserCaptchaField *ptrCfd_pRspGenUserCaptcha = new CThostFtdcRspGenUserCaptchaField();
        if(pRspGenUserCaptcha)
        {
            memcpy(ptrCfd_pRspGenUserCaptcha, pRspGenUserCaptcha, sizeof(CThostFtdcRspGenUserCaptchaField));
        }
        else
        {
            memset(ptrCfd_pRspGenUserCaptcha, 0, sizeof(CThostFtdcRspGenUserCaptchaField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspGenUserCaptcha");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspGenUserCaptcha = Napi::Object::New(env);
            js_pRspGenUserCaptcha.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspGenUserCaptcha->BrokerID, strlen(ptrCfd_pRspGenUserCaptcha->BrokerID)) );
            js_pRspGenUserCaptcha.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspGenUserCaptcha->UserID, strlen(ptrCfd_pRspGenUserCaptcha->UserID)) );
            js_pRspGenUserCaptcha.Set("CaptchaInfoLen", ptrCfd_pRspGenUserCaptcha->CaptchaInfoLen);
            js_pRspGenUserCaptcha.Set("CaptchaInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspGenUserCaptcha->CaptchaInfo, strlen(ptrCfd_pRspGenUserCaptcha->CaptchaInfo)) );
            js_event_data.Set("pRspGenUserCaptcha", js_pRspGenUserCaptcha);
            delete ptrCfd_pRspGenUserCaptcha;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspGenUserText(CThostFtdcRspGenUserTextField * pRspGenUserText, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRspGenUserTextField *ptrCfd_pRspGenUserText = new CThostFtdcRspGenUserTextField();
        if(pRspGenUserText)
        {
            memcpy(ptrCfd_pRspGenUserText, pRspGenUserText, sizeof(CThostFtdcRspGenUserTextField));
        }
        else
        {
            memset(ptrCfd_pRspGenUserText, 0, sizeof(CThostFtdcRspGenUserTextField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspGenUserText");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspGenUserText = Napi::Object::New(env);
            js_pRspGenUserText.Set("UserTextSeq", ptrCfd_pRspGenUserText->UserTextSeq);
            js_event_data.Set("pRspGenUserText", js_pRspGenUserText);
            delete ptrCfd_pRspGenUserText;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspOrderInsert(CThostFtdcInputOrderField * pInputOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputOrderField *ptrCfd_pInputOrder = new CThostFtdcInputOrderField();
        if(pInputOrder)
        {
            memcpy(ptrCfd_pInputOrder, pInputOrder, sizeof(CThostFtdcInputOrderField));
        }
        else
        {
            memset(ptrCfd_pInputOrder, 0, sizeof(CThostFtdcInputOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspOrderInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputOrder = Napi::Object::New(env);
            js_pInputOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->BrokerID, strlen(ptrCfd_pInputOrder->BrokerID)) );
            js_pInputOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->InvestorID, strlen(ptrCfd_pInputOrder->InvestorID)) );
            js_pInputOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->reserve1, strlen(ptrCfd_pInputOrder->reserve1)) );
            js_pInputOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->OrderRef, strlen(ptrCfd_pInputOrder->OrderRef)) );
            js_pInputOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->UserID, strlen(ptrCfd_pInputOrder->UserID)) );
            js_pInputOrder.Set("OrderPriceType", string(1u, ptrCfd_pInputOrder->OrderPriceType).c_str());
            js_pInputOrder.Set("Direction", string(1u, ptrCfd_pInputOrder->Direction).c_str());
            js_pInputOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->CombOffsetFlag, strlen(ptrCfd_pInputOrder->CombOffsetFlag)) );
            js_pInputOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->CombHedgeFlag, strlen(ptrCfd_pInputOrder->CombHedgeFlag)) );
            js_pInputOrder.Set("LimitPrice", ptrCfd_pInputOrder->LimitPrice);
            js_pInputOrder.Set("VolumeTotalOriginal", ptrCfd_pInputOrder->VolumeTotalOriginal);
            js_pInputOrder.Set("TimeCondition", string(1u, ptrCfd_pInputOrder->TimeCondition).c_str());
            js_pInputOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->GTDDate, strlen(ptrCfd_pInputOrder->GTDDate)) );
            js_pInputOrder.Set("VolumeCondition", string(1u, ptrCfd_pInputOrder->VolumeCondition).c_str());
            js_pInputOrder.Set("MinVolume", ptrCfd_pInputOrder->MinVolume);
            js_pInputOrder.Set("ContingentCondition", string(1u, ptrCfd_pInputOrder->ContingentCondition).c_str());
            js_pInputOrder.Set("StopPrice", ptrCfd_pInputOrder->StopPrice);
            js_pInputOrder.Set("ForceCloseReason", string(1u, ptrCfd_pInputOrder->ForceCloseReason).c_str());
            js_pInputOrder.Set("IsAutoSuspend", ptrCfd_pInputOrder->IsAutoSuspend);
            js_pInputOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->BusinessUnit, strlen(ptrCfd_pInputOrder->BusinessUnit)) );
            js_pInputOrder.Set("RequestID", ptrCfd_pInputOrder->RequestID);
            js_pInputOrder.Set("UserForceClose", ptrCfd_pInputOrder->UserForceClose);
            js_pInputOrder.Set("IsSwapOrder", ptrCfd_pInputOrder->IsSwapOrder);
            js_pInputOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->ExchangeID, strlen(ptrCfd_pInputOrder->ExchangeID)) );
            js_pInputOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->InvestUnitID, strlen(ptrCfd_pInputOrder->InvestUnitID)) );
            js_pInputOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->AccountID, strlen(ptrCfd_pInputOrder->AccountID)) );
            js_pInputOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->CurrencyID, strlen(ptrCfd_pInputOrder->CurrencyID)) );
            js_pInputOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->ClientID, strlen(ptrCfd_pInputOrder->ClientID)) );
            js_pInputOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->reserve2, strlen(ptrCfd_pInputOrder->reserve2)) );
            js_pInputOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->MacAddress, strlen(ptrCfd_pInputOrder->MacAddress)) );
            js_pInputOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->InstrumentID, strlen(ptrCfd_pInputOrder->InstrumentID)) );
            js_pInputOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->IPAddress, strlen(ptrCfd_pInputOrder->IPAddress)) );
            js_event_data.Set("pInputOrder", js_pInputOrder);
            delete ptrCfd_pInputOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspParkedOrderInsert(CThostFtdcParkedOrderField * pParkedOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcParkedOrderField *ptrCfd_pParkedOrder = new CThostFtdcParkedOrderField();
        if(pParkedOrder)
        {
            memcpy(ptrCfd_pParkedOrder, pParkedOrder, sizeof(CThostFtdcParkedOrderField));
        }
        else
        {
            memset(ptrCfd_pParkedOrder, 0, sizeof(CThostFtdcParkedOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspParkedOrderInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pParkedOrder = Napi::Object::New(env);
            js_pParkedOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->BrokerID, strlen(ptrCfd_pParkedOrder->BrokerID)) );
            js_pParkedOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->InvestorID, strlen(ptrCfd_pParkedOrder->InvestorID)) );
            js_pParkedOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->reserve1, strlen(ptrCfd_pParkedOrder->reserve1)) );
            js_pParkedOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->OrderRef, strlen(ptrCfd_pParkedOrder->OrderRef)) );
            js_pParkedOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->UserID, strlen(ptrCfd_pParkedOrder->UserID)) );
            js_pParkedOrder.Set("OrderPriceType", string(1u, ptrCfd_pParkedOrder->OrderPriceType).c_str());
            js_pParkedOrder.Set("Direction", string(1u, ptrCfd_pParkedOrder->Direction).c_str());
            js_pParkedOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->CombOffsetFlag, strlen(ptrCfd_pParkedOrder->CombOffsetFlag)) );
            js_pParkedOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->CombHedgeFlag, strlen(ptrCfd_pParkedOrder->CombHedgeFlag)) );
            js_pParkedOrder.Set("LimitPrice", ptrCfd_pParkedOrder->LimitPrice);
            js_pParkedOrder.Set("VolumeTotalOriginal", ptrCfd_pParkedOrder->VolumeTotalOriginal);
            js_pParkedOrder.Set("TimeCondition", string(1u, ptrCfd_pParkedOrder->TimeCondition).c_str());
            js_pParkedOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->GTDDate, strlen(ptrCfd_pParkedOrder->GTDDate)) );
            js_pParkedOrder.Set("VolumeCondition", string(1u, ptrCfd_pParkedOrder->VolumeCondition).c_str());
            js_pParkedOrder.Set("MinVolume", ptrCfd_pParkedOrder->MinVolume);
            js_pParkedOrder.Set("ContingentCondition", string(1u, ptrCfd_pParkedOrder->ContingentCondition).c_str());
            js_pParkedOrder.Set("StopPrice", ptrCfd_pParkedOrder->StopPrice);
            js_pParkedOrder.Set("ForceCloseReason", string(1u, ptrCfd_pParkedOrder->ForceCloseReason).c_str());
            js_pParkedOrder.Set("IsAutoSuspend", ptrCfd_pParkedOrder->IsAutoSuspend);
            js_pParkedOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->BusinessUnit, strlen(ptrCfd_pParkedOrder->BusinessUnit)) );
            js_pParkedOrder.Set("RequestID", ptrCfd_pParkedOrder->RequestID);
            js_pParkedOrder.Set("UserForceClose", ptrCfd_pParkedOrder->UserForceClose);
            js_pParkedOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ExchangeID, strlen(ptrCfd_pParkedOrder->ExchangeID)) );
            js_pParkedOrder.Set("ParkedOrderID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ParkedOrderID, strlen(ptrCfd_pParkedOrder->ParkedOrderID)) );
            js_pParkedOrder.Set("UserType", string(1u, ptrCfd_pParkedOrder->UserType).c_str());
            js_pParkedOrder.Set("Status", string(1u, ptrCfd_pParkedOrder->Status).c_str());
            js_pParkedOrder.Set("ErrorID", ptrCfd_pParkedOrder->ErrorID);
            js_pParkedOrder.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ErrorMsg, strlen(ptrCfd_pParkedOrder->ErrorMsg)) );
            js_pParkedOrder.Set("IsSwapOrder", ptrCfd_pParkedOrder->IsSwapOrder);
            js_pParkedOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->AccountID, strlen(ptrCfd_pParkedOrder->AccountID)) );
            js_pParkedOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->CurrencyID, strlen(ptrCfd_pParkedOrder->CurrencyID)) );
            js_pParkedOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ClientID, strlen(ptrCfd_pParkedOrder->ClientID)) );
            js_pParkedOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->InvestUnitID, strlen(ptrCfd_pParkedOrder->InvestUnitID)) );
            js_pParkedOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->reserve2, strlen(ptrCfd_pParkedOrder->reserve2)) );
            js_pParkedOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->MacAddress, strlen(ptrCfd_pParkedOrder->MacAddress)) );
            js_pParkedOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->InstrumentID, strlen(ptrCfd_pParkedOrder->InstrumentID)) );
            js_pParkedOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->IPAddress, strlen(ptrCfd_pParkedOrder->IPAddress)) );
            js_event_data.Set("pParkedOrder", js_pParkedOrder);
            delete ptrCfd_pParkedOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField * pParkedOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcParkedOrderActionField *ptrCfd_pParkedOrderAction = new CThostFtdcParkedOrderActionField();
        if(pParkedOrderAction)
        {
            memcpy(ptrCfd_pParkedOrderAction, pParkedOrderAction, sizeof(CThostFtdcParkedOrderActionField));
        }
        else
        {
            memset(ptrCfd_pParkedOrderAction, 0, sizeof(CThostFtdcParkedOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspParkedOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pParkedOrderAction = Napi::Object::New(env);
            js_pParkedOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->BrokerID, strlen(ptrCfd_pParkedOrderAction->BrokerID)) );
            js_pParkedOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->InvestorID, strlen(ptrCfd_pParkedOrderAction->InvestorID)) );
            js_pParkedOrderAction.Set("OrderActionRef", ptrCfd_pParkedOrderAction->OrderActionRef);
            js_pParkedOrderAction.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->OrderRef, strlen(ptrCfd_pParkedOrderAction->OrderRef)) );
            js_pParkedOrderAction.Set("RequestID", ptrCfd_pParkedOrderAction->RequestID);
            js_pParkedOrderAction.Set("FrontID", ptrCfd_pParkedOrderAction->FrontID);
            js_pParkedOrderAction.Set("SessionID", ptrCfd_pParkedOrderAction->SessionID);
            js_pParkedOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->ExchangeID, strlen(ptrCfd_pParkedOrderAction->ExchangeID)) );
            js_pParkedOrderAction.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->OrderSysID, strlen(ptrCfd_pParkedOrderAction->OrderSysID)) );
            js_pParkedOrderAction.Set("ActionFlag", string(1u, ptrCfd_pParkedOrderAction->ActionFlag).c_str());
            js_pParkedOrderAction.Set("LimitPrice", ptrCfd_pParkedOrderAction->LimitPrice);
            js_pParkedOrderAction.Set("VolumeChange", ptrCfd_pParkedOrderAction->VolumeChange);
            js_pParkedOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->UserID, strlen(ptrCfd_pParkedOrderAction->UserID)) );
            js_pParkedOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->reserve1, strlen(ptrCfd_pParkedOrderAction->reserve1)) );
            js_pParkedOrderAction.Set("ParkedOrderActionID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->ParkedOrderActionID, strlen(ptrCfd_pParkedOrderAction->ParkedOrderActionID)) );
            js_pParkedOrderAction.Set("UserType", string(1u, ptrCfd_pParkedOrderAction->UserType).c_str());
            js_pParkedOrderAction.Set("Status", string(1u, ptrCfd_pParkedOrderAction->Status).c_str());
            js_pParkedOrderAction.Set("ErrorID", ptrCfd_pParkedOrderAction->ErrorID);
            js_pParkedOrderAction.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->ErrorMsg, strlen(ptrCfd_pParkedOrderAction->ErrorMsg)) );
            js_pParkedOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->InvestUnitID, strlen(ptrCfd_pParkedOrderAction->InvestUnitID)) );
            js_pParkedOrderAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->reserve2, strlen(ptrCfd_pParkedOrderAction->reserve2)) );
            js_pParkedOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->MacAddress, strlen(ptrCfd_pParkedOrderAction->MacAddress)) );
            js_pParkedOrderAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->InstrumentID, strlen(ptrCfd_pParkedOrderAction->InstrumentID)) );
            js_pParkedOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->IPAddress, strlen(ptrCfd_pParkedOrderAction->IPAddress)) );
            js_event_data.Set("pParkedOrderAction", js_pParkedOrderAction);
            delete ptrCfd_pParkedOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspOrderAction(CThostFtdcInputOrderActionField * pInputOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputOrderActionField *ptrCfd_pInputOrderAction = new CThostFtdcInputOrderActionField();
        if(pInputOrderAction)
        {
            memcpy(ptrCfd_pInputOrderAction, pInputOrderAction, sizeof(CThostFtdcInputOrderActionField));
        }
        else
        {
            memset(ptrCfd_pInputOrderAction, 0, sizeof(CThostFtdcInputOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputOrderAction = Napi::Object::New(env);
            js_pInputOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->BrokerID, strlen(ptrCfd_pInputOrderAction->BrokerID)) );
            js_pInputOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->InvestorID, strlen(ptrCfd_pInputOrderAction->InvestorID)) );
            js_pInputOrderAction.Set("OrderActionRef", ptrCfd_pInputOrderAction->OrderActionRef);
            js_pInputOrderAction.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->OrderRef, strlen(ptrCfd_pInputOrderAction->OrderRef)) );
            js_pInputOrderAction.Set("RequestID", ptrCfd_pInputOrderAction->RequestID);
            js_pInputOrderAction.Set("FrontID", ptrCfd_pInputOrderAction->FrontID);
            js_pInputOrderAction.Set("SessionID", ptrCfd_pInputOrderAction->SessionID);
            js_pInputOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->ExchangeID, strlen(ptrCfd_pInputOrderAction->ExchangeID)) );
            js_pInputOrderAction.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->OrderSysID, strlen(ptrCfd_pInputOrderAction->OrderSysID)) );
            js_pInputOrderAction.Set("ActionFlag", string(1u, ptrCfd_pInputOrderAction->ActionFlag).c_str());
            js_pInputOrderAction.Set("LimitPrice", ptrCfd_pInputOrderAction->LimitPrice);
            js_pInputOrderAction.Set("VolumeChange", ptrCfd_pInputOrderAction->VolumeChange);
            js_pInputOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->UserID, strlen(ptrCfd_pInputOrderAction->UserID)) );
            js_pInputOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->reserve1, strlen(ptrCfd_pInputOrderAction->reserve1)) );
            js_pInputOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->InvestUnitID, strlen(ptrCfd_pInputOrderAction->InvestUnitID)) );
            js_pInputOrderAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->reserve2, strlen(ptrCfd_pInputOrderAction->reserve2)) );
            js_pInputOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->MacAddress, strlen(ptrCfd_pInputOrderAction->MacAddress)) );
            js_pInputOrderAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->InstrumentID, strlen(ptrCfd_pInputOrderAction->InstrumentID)) );
            js_pInputOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrderAction->IPAddress, strlen(ptrCfd_pInputOrderAction->IPAddress)) );
            js_event_data.Set("pInputOrderAction", js_pInputOrderAction);
            delete ptrCfd_pInputOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField * pQryMaxOrderVolume, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcQryMaxOrderVolumeField *ptrCfd_pQryMaxOrderVolume = new CThostFtdcQryMaxOrderVolumeField();
        if(pQryMaxOrderVolume)
        {
            memcpy(ptrCfd_pQryMaxOrderVolume, pQryMaxOrderVolume, sizeof(CThostFtdcQryMaxOrderVolumeField));
        }
        else
        {
            memset(ptrCfd_pQryMaxOrderVolume, 0, sizeof(CThostFtdcQryMaxOrderVolumeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryMaxOrderVolume");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pQryMaxOrderVolume = Napi::Object::New(env);
            js_pQryMaxOrderVolume.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pQryMaxOrderVolume->BrokerID, strlen(ptrCfd_pQryMaxOrderVolume->BrokerID)) );
            js_pQryMaxOrderVolume.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pQryMaxOrderVolume->InvestorID, strlen(ptrCfd_pQryMaxOrderVolume->InvestorID)) );
            js_pQryMaxOrderVolume.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pQryMaxOrderVolume->reserve1, strlen(ptrCfd_pQryMaxOrderVolume->reserve1)) );
            js_pQryMaxOrderVolume.Set("Direction", string(1u, ptrCfd_pQryMaxOrderVolume->Direction).c_str());
            js_pQryMaxOrderVolume.Set("OffsetFlag", string(1u, ptrCfd_pQryMaxOrderVolume->OffsetFlag).c_str());
            js_pQryMaxOrderVolume.Set("HedgeFlag", string(1u, ptrCfd_pQryMaxOrderVolume->HedgeFlag).c_str());
            js_pQryMaxOrderVolume.Set("MaxVolume", ptrCfd_pQryMaxOrderVolume->MaxVolume);
            js_pQryMaxOrderVolume.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pQryMaxOrderVolume->ExchangeID, strlen(ptrCfd_pQryMaxOrderVolume->ExchangeID)) );
            js_pQryMaxOrderVolume.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pQryMaxOrderVolume->InvestUnitID, strlen(ptrCfd_pQryMaxOrderVolume->InvestUnitID)) );
            js_pQryMaxOrderVolume.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pQryMaxOrderVolume->InstrumentID, strlen(ptrCfd_pQryMaxOrderVolume->InstrumentID)) );
            js_event_data.Set("pQryMaxOrderVolume", js_pQryMaxOrderVolume);
            delete ptrCfd_pQryMaxOrderVolume;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSettlementInfoConfirmField *ptrCfd_pSettlementInfoConfirm = new CThostFtdcSettlementInfoConfirmField();
        if(pSettlementInfoConfirm)
        {
            memcpy(ptrCfd_pSettlementInfoConfirm, pSettlementInfoConfirm, sizeof(CThostFtdcSettlementInfoConfirmField));
        }
        else
        {
            memset(ptrCfd_pSettlementInfoConfirm, 0, sizeof(CThostFtdcSettlementInfoConfirmField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspSettlementInfoConfirm");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSettlementInfoConfirm = Napi::Object::New(env);
            js_pSettlementInfoConfirm.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->BrokerID, strlen(ptrCfd_pSettlementInfoConfirm->BrokerID)) );
            js_pSettlementInfoConfirm.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->InvestorID, strlen(ptrCfd_pSettlementInfoConfirm->InvestorID)) );
            js_pSettlementInfoConfirm.Set("ConfirmDate", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->ConfirmDate, strlen(ptrCfd_pSettlementInfoConfirm->ConfirmDate)) );
            js_pSettlementInfoConfirm.Set("ConfirmTime", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->ConfirmTime, strlen(ptrCfd_pSettlementInfoConfirm->ConfirmTime)) );
            js_pSettlementInfoConfirm.Set("SettlementID", ptrCfd_pSettlementInfoConfirm->SettlementID);
            js_pSettlementInfoConfirm.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->AccountID, strlen(ptrCfd_pSettlementInfoConfirm->AccountID)) );
            js_pSettlementInfoConfirm.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->CurrencyID, strlen(ptrCfd_pSettlementInfoConfirm->CurrencyID)) );
            js_event_data.Set("pSettlementInfoConfirm", js_pSettlementInfoConfirm);
            delete ptrCfd_pSettlementInfoConfirm;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField * pRemoveParkedOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRemoveParkedOrderField *ptrCfd_pRemoveParkedOrder = new CThostFtdcRemoveParkedOrderField();
        if(pRemoveParkedOrder)
        {
            memcpy(ptrCfd_pRemoveParkedOrder, pRemoveParkedOrder, sizeof(CThostFtdcRemoveParkedOrderField));
        }
        else
        {
            memset(ptrCfd_pRemoveParkedOrder, 0, sizeof(CThostFtdcRemoveParkedOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspRemoveParkedOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRemoveParkedOrder = Napi::Object::New(env);
            js_pRemoveParkedOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrder->BrokerID, strlen(ptrCfd_pRemoveParkedOrder->BrokerID)) );
            js_pRemoveParkedOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrder->InvestorID, strlen(ptrCfd_pRemoveParkedOrder->InvestorID)) );
            js_pRemoveParkedOrder.Set("ParkedOrderID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrder->ParkedOrderID, strlen(ptrCfd_pRemoveParkedOrder->ParkedOrderID)) );
            js_pRemoveParkedOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrder->InvestUnitID, strlen(ptrCfd_pRemoveParkedOrder->InvestUnitID)) );
            js_event_data.Set("pRemoveParkedOrder", js_pRemoveParkedOrder);
            delete ptrCfd_pRemoveParkedOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField * pRemoveParkedOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRemoveParkedOrderActionField *ptrCfd_pRemoveParkedOrderAction = new CThostFtdcRemoveParkedOrderActionField();
        if(pRemoveParkedOrderAction)
        {
            memcpy(ptrCfd_pRemoveParkedOrderAction, pRemoveParkedOrderAction, sizeof(CThostFtdcRemoveParkedOrderActionField));
        }
        else
        {
            memset(ptrCfd_pRemoveParkedOrderAction, 0, sizeof(CThostFtdcRemoveParkedOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspRemoveParkedOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRemoveParkedOrderAction = Napi::Object::New(env);
            js_pRemoveParkedOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrderAction->BrokerID, strlen(ptrCfd_pRemoveParkedOrderAction->BrokerID)) );
            js_pRemoveParkedOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrderAction->InvestorID, strlen(ptrCfd_pRemoveParkedOrderAction->InvestorID)) );
            js_pRemoveParkedOrderAction.Set("ParkedOrderActionID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrderAction->ParkedOrderActionID, strlen(ptrCfd_pRemoveParkedOrderAction->ParkedOrderActionID)) );
            js_pRemoveParkedOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pRemoveParkedOrderAction->InvestUnitID, strlen(ptrCfd_pRemoveParkedOrderAction->InvestUnitID)) );
            js_event_data.Set("pRemoveParkedOrderAction", js_pRemoveParkedOrderAction);
            delete ptrCfd_pRemoveParkedOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspExecOrderInsert(CThostFtdcInputExecOrderField * pInputExecOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputExecOrderField *ptrCfd_pInputExecOrder = new CThostFtdcInputExecOrderField();
        if(pInputExecOrder)
        {
            memcpy(ptrCfd_pInputExecOrder, pInputExecOrder, sizeof(CThostFtdcInputExecOrderField));
        }
        else
        {
            memset(ptrCfd_pInputExecOrder, 0, sizeof(CThostFtdcInputExecOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspExecOrderInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputExecOrder = Napi::Object::New(env);
            js_pInputExecOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->BrokerID, strlen(ptrCfd_pInputExecOrder->BrokerID)) );
            js_pInputExecOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->InvestorID, strlen(ptrCfd_pInputExecOrder->InvestorID)) );
            js_pInputExecOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->reserve1, strlen(ptrCfd_pInputExecOrder->reserve1)) );
            js_pInputExecOrder.Set("ExecOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->ExecOrderRef, strlen(ptrCfd_pInputExecOrder->ExecOrderRef)) );
            js_pInputExecOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->UserID, strlen(ptrCfd_pInputExecOrder->UserID)) );
            js_pInputExecOrder.Set("Volume", ptrCfd_pInputExecOrder->Volume);
            js_pInputExecOrder.Set("RequestID", ptrCfd_pInputExecOrder->RequestID);
            js_pInputExecOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->BusinessUnit, strlen(ptrCfd_pInputExecOrder->BusinessUnit)) );
            js_pInputExecOrder.Set("OffsetFlag", string(1u, ptrCfd_pInputExecOrder->OffsetFlag).c_str());
            js_pInputExecOrder.Set("HedgeFlag", string(1u, ptrCfd_pInputExecOrder->HedgeFlag).c_str());
            js_pInputExecOrder.Set("ActionType", string(1u, ptrCfd_pInputExecOrder->ActionType).c_str());
            js_pInputExecOrder.Set("PosiDirection", string(1u, ptrCfd_pInputExecOrder->PosiDirection).c_str());
            js_pInputExecOrder.Set("ReservePositionFlag", string(1u, ptrCfd_pInputExecOrder->ReservePositionFlag).c_str());
            js_pInputExecOrder.Set("CloseFlag", string(1u, ptrCfd_pInputExecOrder->CloseFlag).c_str());
            js_pInputExecOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->ExchangeID, strlen(ptrCfd_pInputExecOrder->ExchangeID)) );
            js_pInputExecOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->InvestUnitID, strlen(ptrCfd_pInputExecOrder->InvestUnitID)) );
            js_pInputExecOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->AccountID, strlen(ptrCfd_pInputExecOrder->AccountID)) );
            js_pInputExecOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->CurrencyID, strlen(ptrCfd_pInputExecOrder->CurrencyID)) );
            js_pInputExecOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->ClientID, strlen(ptrCfd_pInputExecOrder->ClientID)) );
            js_pInputExecOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->reserve2, strlen(ptrCfd_pInputExecOrder->reserve2)) );
            js_pInputExecOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->MacAddress, strlen(ptrCfd_pInputExecOrder->MacAddress)) );
            js_pInputExecOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->InstrumentID, strlen(ptrCfd_pInputExecOrder->InstrumentID)) );
            js_pInputExecOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->IPAddress, strlen(ptrCfd_pInputExecOrder->IPAddress)) );
            js_event_data.Set("pInputExecOrder", js_pInputExecOrder);
            delete ptrCfd_pInputExecOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField * pInputExecOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputExecOrderActionField *ptrCfd_pInputExecOrderAction = new CThostFtdcInputExecOrderActionField();
        if(pInputExecOrderAction)
        {
            memcpy(ptrCfd_pInputExecOrderAction, pInputExecOrderAction, sizeof(CThostFtdcInputExecOrderActionField));
        }
        else
        {
            memset(ptrCfd_pInputExecOrderAction, 0, sizeof(CThostFtdcInputExecOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspExecOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputExecOrderAction = Napi::Object::New(env);
            js_pInputExecOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->BrokerID, strlen(ptrCfd_pInputExecOrderAction->BrokerID)) );
            js_pInputExecOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->InvestorID, strlen(ptrCfd_pInputExecOrderAction->InvestorID)) );
            js_pInputExecOrderAction.Set("ExecOrderActionRef", ptrCfd_pInputExecOrderAction->ExecOrderActionRef);
            js_pInputExecOrderAction.Set("ExecOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->ExecOrderRef, strlen(ptrCfd_pInputExecOrderAction->ExecOrderRef)) );
            js_pInputExecOrderAction.Set("RequestID", ptrCfd_pInputExecOrderAction->RequestID);
            js_pInputExecOrderAction.Set("FrontID", ptrCfd_pInputExecOrderAction->FrontID);
            js_pInputExecOrderAction.Set("SessionID", ptrCfd_pInputExecOrderAction->SessionID);
            js_pInputExecOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->ExchangeID, strlen(ptrCfd_pInputExecOrderAction->ExchangeID)) );
            js_pInputExecOrderAction.Set("ExecOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->ExecOrderSysID, strlen(ptrCfd_pInputExecOrderAction->ExecOrderSysID)) );
            js_pInputExecOrderAction.Set("ActionFlag", string(1u, ptrCfd_pInputExecOrderAction->ActionFlag).c_str());
            js_pInputExecOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->UserID, strlen(ptrCfd_pInputExecOrderAction->UserID)) );
            js_pInputExecOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->reserve1, strlen(ptrCfd_pInputExecOrderAction->reserve1)) );
            js_pInputExecOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->InvestUnitID, strlen(ptrCfd_pInputExecOrderAction->InvestUnitID)) );
            js_pInputExecOrderAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->reserve2, strlen(ptrCfd_pInputExecOrderAction->reserve2)) );
            js_pInputExecOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->MacAddress, strlen(ptrCfd_pInputExecOrderAction->MacAddress)) );
            js_pInputExecOrderAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->InstrumentID, strlen(ptrCfd_pInputExecOrderAction->InstrumentID)) );
            js_pInputExecOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrderAction->IPAddress, strlen(ptrCfd_pInputExecOrderAction->IPAddress)) );
            js_event_data.Set("pInputExecOrderAction", js_pInputExecOrderAction);
            delete ptrCfd_pInputExecOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspForQuoteInsert(CThostFtdcInputForQuoteField * pInputForQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputForQuoteField *ptrCfd_pInputForQuote = new CThostFtdcInputForQuoteField();
        if(pInputForQuote)
        {
            memcpy(ptrCfd_pInputForQuote, pInputForQuote, sizeof(CThostFtdcInputForQuoteField));
        }
        else
        {
            memset(ptrCfd_pInputForQuote, 0, sizeof(CThostFtdcInputForQuoteField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspForQuoteInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputForQuote = Napi::Object::New(env);
            js_pInputForQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->BrokerID, strlen(ptrCfd_pInputForQuote->BrokerID)) );
            js_pInputForQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->InvestorID, strlen(ptrCfd_pInputForQuote->InvestorID)) );
            js_pInputForQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->reserve1, strlen(ptrCfd_pInputForQuote->reserve1)) );
            js_pInputForQuote.Set("ForQuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->ForQuoteRef, strlen(ptrCfd_pInputForQuote->ForQuoteRef)) );
            js_pInputForQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->UserID, strlen(ptrCfd_pInputForQuote->UserID)) );
            js_pInputForQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->ExchangeID, strlen(ptrCfd_pInputForQuote->ExchangeID)) );
            js_pInputForQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->InvestUnitID, strlen(ptrCfd_pInputForQuote->InvestUnitID)) );
            js_pInputForQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->reserve2, strlen(ptrCfd_pInputForQuote->reserve2)) );
            js_pInputForQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->MacAddress, strlen(ptrCfd_pInputForQuote->MacAddress)) );
            js_pInputForQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->InstrumentID, strlen(ptrCfd_pInputForQuote->InstrumentID)) );
            js_pInputForQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->IPAddress, strlen(ptrCfd_pInputForQuote->IPAddress)) );
            js_event_data.Set("pInputForQuote", js_pInputForQuote);
            delete ptrCfd_pInputForQuote;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQuoteInsert(CThostFtdcInputQuoteField * pInputQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputQuoteField *ptrCfd_pInputQuote = new CThostFtdcInputQuoteField();
        if(pInputQuote)
        {
            memcpy(ptrCfd_pInputQuote, pInputQuote, sizeof(CThostFtdcInputQuoteField));
        }
        else
        {
            memset(ptrCfd_pInputQuote, 0, sizeof(CThostFtdcInputQuoteField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQuoteInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputQuote = Napi::Object::New(env);
            js_pInputQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->BrokerID, strlen(ptrCfd_pInputQuote->BrokerID)) );
            js_pInputQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->InvestorID, strlen(ptrCfd_pInputQuote->InvestorID)) );
            js_pInputQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->reserve1, strlen(ptrCfd_pInputQuote->reserve1)) );
            js_pInputQuote.Set("QuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->QuoteRef, strlen(ptrCfd_pInputQuote->QuoteRef)) );
            js_pInputQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->UserID, strlen(ptrCfd_pInputQuote->UserID)) );
            js_pInputQuote.Set("AskPrice", ptrCfd_pInputQuote->AskPrice);
            js_pInputQuote.Set("BidPrice", ptrCfd_pInputQuote->BidPrice);
            js_pInputQuote.Set("AskVolume", ptrCfd_pInputQuote->AskVolume);
            js_pInputQuote.Set("BidVolume", ptrCfd_pInputQuote->BidVolume);
            js_pInputQuote.Set("RequestID", ptrCfd_pInputQuote->RequestID);
            js_pInputQuote.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->BusinessUnit, strlen(ptrCfd_pInputQuote->BusinessUnit)) );
            js_pInputQuote.Set("AskOffsetFlag", string(1u, ptrCfd_pInputQuote->AskOffsetFlag).c_str());
            js_pInputQuote.Set("BidOffsetFlag", string(1u, ptrCfd_pInputQuote->BidOffsetFlag).c_str());
            js_pInputQuote.Set("AskHedgeFlag", string(1u, ptrCfd_pInputQuote->AskHedgeFlag).c_str());
            js_pInputQuote.Set("BidHedgeFlag", string(1u, ptrCfd_pInputQuote->BidHedgeFlag).c_str());
            js_pInputQuote.Set("AskOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->AskOrderRef, strlen(ptrCfd_pInputQuote->AskOrderRef)) );
            js_pInputQuote.Set("BidOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->BidOrderRef, strlen(ptrCfd_pInputQuote->BidOrderRef)) );
            js_pInputQuote.Set("ForQuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ForQuoteSysID, strlen(ptrCfd_pInputQuote->ForQuoteSysID)) );
            js_pInputQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ExchangeID, strlen(ptrCfd_pInputQuote->ExchangeID)) );
            js_pInputQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->InvestUnitID, strlen(ptrCfd_pInputQuote->InvestUnitID)) );
            js_pInputQuote.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ClientID, strlen(ptrCfd_pInputQuote->ClientID)) );
            js_pInputQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->reserve2, strlen(ptrCfd_pInputQuote->reserve2)) );
            js_pInputQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->MacAddress, strlen(ptrCfd_pInputQuote->MacAddress)) );
            js_pInputQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->InstrumentID, strlen(ptrCfd_pInputQuote->InstrumentID)) );
            js_pInputQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->IPAddress, strlen(ptrCfd_pInputQuote->IPAddress)) );
            js_pInputQuote.Set("ReplaceSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ReplaceSysID, strlen(ptrCfd_pInputQuote->ReplaceSysID)) );
            js_event_data.Set("pInputQuote", js_pInputQuote);
            delete ptrCfd_pInputQuote;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQuoteAction(CThostFtdcInputQuoteActionField * pInputQuoteAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputQuoteActionField *ptrCfd_pInputQuoteAction = new CThostFtdcInputQuoteActionField();
        if(pInputQuoteAction)
        {
            memcpy(ptrCfd_pInputQuoteAction, pInputQuoteAction, sizeof(CThostFtdcInputQuoteActionField));
        }
        else
        {
            memset(ptrCfd_pInputQuoteAction, 0, sizeof(CThostFtdcInputQuoteActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQuoteAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputQuoteAction = Napi::Object::New(env);
            js_pInputQuoteAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->BrokerID, strlen(ptrCfd_pInputQuoteAction->BrokerID)) );
            js_pInputQuoteAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->InvestorID, strlen(ptrCfd_pInputQuoteAction->InvestorID)) );
            js_pInputQuoteAction.Set("QuoteActionRef", ptrCfd_pInputQuoteAction->QuoteActionRef);
            js_pInputQuoteAction.Set("QuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->QuoteRef, strlen(ptrCfd_pInputQuoteAction->QuoteRef)) );
            js_pInputQuoteAction.Set("RequestID", ptrCfd_pInputQuoteAction->RequestID);
            js_pInputQuoteAction.Set("FrontID", ptrCfd_pInputQuoteAction->FrontID);
            js_pInputQuoteAction.Set("SessionID", ptrCfd_pInputQuoteAction->SessionID);
            js_pInputQuoteAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->ExchangeID, strlen(ptrCfd_pInputQuoteAction->ExchangeID)) );
            js_pInputQuoteAction.Set("QuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->QuoteSysID, strlen(ptrCfd_pInputQuoteAction->QuoteSysID)) );
            js_pInputQuoteAction.Set("ActionFlag", string(1u, ptrCfd_pInputQuoteAction->ActionFlag).c_str());
            js_pInputQuoteAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->UserID, strlen(ptrCfd_pInputQuoteAction->UserID)) );
            js_pInputQuoteAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->reserve1, strlen(ptrCfd_pInputQuoteAction->reserve1)) );
            js_pInputQuoteAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->InvestUnitID, strlen(ptrCfd_pInputQuoteAction->InvestUnitID)) );
            js_pInputQuoteAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->ClientID, strlen(ptrCfd_pInputQuoteAction->ClientID)) );
            js_pInputQuoteAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->reserve2, strlen(ptrCfd_pInputQuoteAction->reserve2)) );
            js_pInputQuoteAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->MacAddress, strlen(ptrCfd_pInputQuoteAction->MacAddress)) );
            js_pInputQuoteAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->InstrumentID, strlen(ptrCfd_pInputQuoteAction->InstrumentID)) );
            js_pInputQuoteAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuoteAction->IPAddress, strlen(ptrCfd_pInputQuoteAction->IPAddress)) );
            js_event_data.Set("pInputQuoteAction", js_pInputQuoteAction);
            delete ptrCfd_pInputQuoteAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField * pInputBatchOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputBatchOrderActionField *ptrCfd_pInputBatchOrderAction = new CThostFtdcInputBatchOrderActionField();
        if(pInputBatchOrderAction)
        {
            memcpy(ptrCfd_pInputBatchOrderAction, pInputBatchOrderAction, sizeof(CThostFtdcInputBatchOrderActionField));
        }
        else
        {
            memset(ptrCfd_pInputBatchOrderAction, 0, sizeof(CThostFtdcInputBatchOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspBatchOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputBatchOrderAction = Napi::Object::New(env);
            js_pInputBatchOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->BrokerID, strlen(ptrCfd_pInputBatchOrderAction->BrokerID)) );
            js_pInputBatchOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->InvestorID, strlen(ptrCfd_pInputBatchOrderAction->InvestorID)) );
            js_pInputBatchOrderAction.Set("OrderActionRef", ptrCfd_pInputBatchOrderAction->OrderActionRef);
            js_pInputBatchOrderAction.Set("RequestID", ptrCfd_pInputBatchOrderAction->RequestID);
            js_pInputBatchOrderAction.Set("FrontID", ptrCfd_pInputBatchOrderAction->FrontID);
            js_pInputBatchOrderAction.Set("SessionID", ptrCfd_pInputBatchOrderAction->SessionID);
            js_pInputBatchOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->ExchangeID, strlen(ptrCfd_pInputBatchOrderAction->ExchangeID)) );
            js_pInputBatchOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->UserID, strlen(ptrCfd_pInputBatchOrderAction->UserID)) );
            js_pInputBatchOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->InvestUnitID, strlen(ptrCfd_pInputBatchOrderAction->InvestUnitID)) );
            js_pInputBatchOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->reserve1, strlen(ptrCfd_pInputBatchOrderAction->reserve1)) );
            js_pInputBatchOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->MacAddress, strlen(ptrCfd_pInputBatchOrderAction->MacAddress)) );
            js_pInputBatchOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputBatchOrderAction->IPAddress, strlen(ptrCfd_pInputBatchOrderAction->IPAddress)) );
            js_event_data.Set("pInputBatchOrderAction", js_pInputBatchOrderAction);
            delete ptrCfd_pInputBatchOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputOptionSelfCloseField *ptrCfd_pInputOptionSelfClose = new CThostFtdcInputOptionSelfCloseField();
        if(pInputOptionSelfClose)
        {
            memcpy(ptrCfd_pInputOptionSelfClose, pInputOptionSelfClose, sizeof(CThostFtdcInputOptionSelfCloseField));
        }
        else
        {
            memset(ptrCfd_pInputOptionSelfClose, 0, sizeof(CThostFtdcInputOptionSelfCloseField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspOptionSelfCloseInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputOptionSelfClose = Napi::Object::New(env);
            js_pInputOptionSelfClose.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->BrokerID, strlen(ptrCfd_pInputOptionSelfClose->BrokerID)) );
            js_pInputOptionSelfClose.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->InvestorID, strlen(ptrCfd_pInputOptionSelfClose->InvestorID)) );
            js_pInputOptionSelfClose.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->reserve1, strlen(ptrCfd_pInputOptionSelfClose->reserve1)) );
            js_pInputOptionSelfClose.Set("OptionSelfCloseRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->OptionSelfCloseRef, strlen(ptrCfd_pInputOptionSelfClose->OptionSelfCloseRef)) );
            js_pInputOptionSelfClose.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->UserID, strlen(ptrCfd_pInputOptionSelfClose->UserID)) );
            js_pInputOptionSelfClose.Set("Volume", ptrCfd_pInputOptionSelfClose->Volume);
            js_pInputOptionSelfClose.Set("RequestID", ptrCfd_pInputOptionSelfClose->RequestID);
            js_pInputOptionSelfClose.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->BusinessUnit, strlen(ptrCfd_pInputOptionSelfClose->BusinessUnit)) );
            js_pInputOptionSelfClose.Set("HedgeFlag", string(1u, ptrCfd_pInputOptionSelfClose->HedgeFlag).c_str());
            js_pInputOptionSelfClose.Set("OptSelfCloseFlag", string(1u, ptrCfd_pInputOptionSelfClose->OptSelfCloseFlag).c_str());
            js_pInputOptionSelfClose.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->ExchangeID, strlen(ptrCfd_pInputOptionSelfClose->ExchangeID)) );
            js_pInputOptionSelfClose.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->InvestUnitID, strlen(ptrCfd_pInputOptionSelfClose->InvestUnitID)) );
            js_pInputOptionSelfClose.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->AccountID, strlen(ptrCfd_pInputOptionSelfClose->AccountID)) );
            js_pInputOptionSelfClose.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->CurrencyID, strlen(ptrCfd_pInputOptionSelfClose->CurrencyID)) );
            js_pInputOptionSelfClose.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->ClientID, strlen(ptrCfd_pInputOptionSelfClose->ClientID)) );
            js_pInputOptionSelfClose.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->reserve2, strlen(ptrCfd_pInputOptionSelfClose->reserve2)) );
            js_pInputOptionSelfClose.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->MacAddress, strlen(ptrCfd_pInputOptionSelfClose->MacAddress)) );
            js_pInputOptionSelfClose.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->InstrumentID, strlen(ptrCfd_pInputOptionSelfClose->InstrumentID)) );
            js_pInputOptionSelfClose.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->IPAddress, strlen(ptrCfd_pInputOptionSelfClose->IPAddress)) );
            js_event_data.Set("pInputOptionSelfClose", js_pInputOptionSelfClose);
            delete ptrCfd_pInputOptionSelfClose;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField * pInputOptionSelfCloseAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputOptionSelfCloseActionField *ptrCfd_pInputOptionSelfCloseAction = new CThostFtdcInputOptionSelfCloseActionField();
        if(pInputOptionSelfCloseAction)
        {
            memcpy(ptrCfd_pInputOptionSelfCloseAction, pInputOptionSelfCloseAction, sizeof(CThostFtdcInputOptionSelfCloseActionField));
        }
        else
        {
            memset(ptrCfd_pInputOptionSelfCloseAction, 0, sizeof(CThostFtdcInputOptionSelfCloseActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspOptionSelfCloseAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputOptionSelfCloseAction = Napi::Object::New(env);
            js_pInputOptionSelfCloseAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->BrokerID, strlen(ptrCfd_pInputOptionSelfCloseAction->BrokerID)) );
            js_pInputOptionSelfCloseAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->InvestorID, strlen(ptrCfd_pInputOptionSelfCloseAction->InvestorID)) );
            js_pInputOptionSelfCloseAction.Set("OptionSelfCloseActionRef", ptrCfd_pInputOptionSelfCloseAction->OptionSelfCloseActionRef);
            js_pInputOptionSelfCloseAction.Set("OptionSelfCloseRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->OptionSelfCloseRef, strlen(ptrCfd_pInputOptionSelfCloseAction->OptionSelfCloseRef)) );
            js_pInputOptionSelfCloseAction.Set("RequestID", ptrCfd_pInputOptionSelfCloseAction->RequestID);
            js_pInputOptionSelfCloseAction.Set("FrontID", ptrCfd_pInputOptionSelfCloseAction->FrontID);
            js_pInputOptionSelfCloseAction.Set("SessionID", ptrCfd_pInputOptionSelfCloseAction->SessionID);
            js_pInputOptionSelfCloseAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->ExchangeID, strlen(ptrCfd_pInputOptionSelfCloseAction->ExchangeID)) );
            js_pInputOptionSelfCloseAction.Set("OptionSelfCloseSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->OptionSelfCloseSysID, strlen(ptrCfd_pInputOptionSelfCloseAction->OptionSelfCloseSysID)) );
            js_pInputOptionSelfCloseAction.Set("ActionFlag", string(1u, ptrCfd_pInputOptionSelfCloseAction->ActionFlag).c_str());
            js_pInputOptionSelfCloseAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->UserID, strlen(ptrCfd_pInputOptionSelfCloseAction->UserID)) );
            js_pInputOptionSelfCloseAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->reserve1, strlen(ptrCfd_pInputOptionSelfCloseAction->reserve1)) );
            js_pInputOptionSelfCloseAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->InvestUnitID, strlen(ptrCfd_pInputOptionSelfCloseAction->InvestUnitID)) );
            js_pInputOptionSelfCloseAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->reserve2, strlen(ptrCfd_pInputOptionSelfCloseAction->reserve2)) );
            js_pInputOptionSelfCloseAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->MacAddress, strlen(ptrCfd_pInputOptionSelfCloseAction->MacAddress)) );
            js_pInputOptionSelfCloseAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->InstrumentID, strlen(ptrCfd_pInputOptionSelfCloseAction->InstrumentID)) );
            js_pInputOptionSelfCloseAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfCloseAction->IPAddress, strlen(ptrCfd_pInputOptionSelfCloseAction->IPAddress)) );
            js_event_data.Set("pInputOptionSelfCloseAction", js_pInputOptionSelfCloseAction);
            delete ptrCfd_pInputOptionSelfCloseAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspCombActionInsert(CThostFtdcInputCombActionField * pInputCombAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInputCombActionField *ptrCfd_pInputCombAction = new CThostFtdcInputCombActionField();
        if(pInputCombAction)
        {
            memcpy(ptrCfd_pInputCombAction, pInputCombAction, sizeof(CThostFtdcInputCombActionField));
        }
        else
        {
            memset(ptrCfd_pInputCombAction, 0, sizeof(CThostFtdcInputCombActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspCombActionInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputCombAction = Napi::Object::New(env);
            js_pInputCombAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->BrokerID, strlen(ptrCfd_pInputCombAction->BrokerID)) );
            js_pInputCombAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->InvestorID, strlen(ptrCfd_pInputCombAction->InvestorID)) );
            js_pInputCombAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->reserve1, strlen(ptrCfd_pInputCombAction->reserve1)) );
            js_pInputCombAction.Set("CombActionRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->CombActionRef, strlen(ptrCfd_pInputCombAction->CombActionRef)) );
            js_pInputCombAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->UserID, strlen(ptrCfd_pInputCombAction->UserID)) );
            js_pInputCombAction.Set("Direction", string(1u, ptrCfd_pInputCombAction->Direction).c_str());
            js_pInputCombAction.Set("Volume", ptrCfd_pInputCombAction->Volume);
            js_pInputCombAction.Set("CombDirection", string(1u, ptrCfd_pInputCombAction->CombDirection).c_str());
            js_pInputCombAction.Set("HedgeFlag", string(1u, ptrCfd_pInputCombAction->HedgeFlag).c_str());
            js_pInputCombAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->ExchangeID, strlen(ptrCfd_pInputCombAction->ExchangeID)) );
            js_pInputCombAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->reserve2, strlen(ptrCfd_pInputCombAction->reserve2)) );
            js_pInputCombAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->MacAddress, strlen(ptrCfd_pInputCombAction->MacAddress)) );
            js_pInputCombAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->InvestUnitID, strlen(ptrCfd_pInputCombAction->InvestUnitID)) );
            js_pInputCombAction.Set("FrontID", ptrCfd_pInputCombAction->FrontID);
            js_pInputCombAction.Set("SessionID", ptrCfd_pInputCombAction->SessionID);
            js_pInputCombAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->InstrumentID, strlen(ptrCfd_pInputCombAction->InstrumentID)) );
            js_pInputCombAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->IPAddress, strlen(ptrCfd_pInputCombAction->IPAddress)) );
            js_event_data.Set("pInputCombAction", js_pInputCombAction);
            delete ptrCfd_pInputCombAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryOrder(CThostFtdcOrderField * pOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcOrderField *ptrCfd_pOrder = new CThostFtdcOrderField();
        if(pOrder)
        {
            memcpy(ptrCfd_pOrder, pOrder, sizeof(CThostFtdcOrderField));
        }
        else
        {
            memset(ptrCfd_pOrder, 0, sizeof(CThostFtdcOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOrder = Napi::Object::New(env);
            js_pOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->BrokerID, strlen(ptrCfd_pOrder->BrokerID)) );
            js_pOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InvestorID, strlen(ptrCfd_pOrder->InvestorID)) );
            js_pOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->reserve1, strlen(ptrCfd_pOrder->reserve1)) );
            js_pOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->OrderRef, strlen(ptrCfd_pOrder->OrderRef)) );
            js_pOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->UserID, strlen(ptrCfd_pOrder->UserID)) );
            js_pOrder.Set("OrderPriceType", string(1u, ptrCfd_pOrder->OrderPriceType).c_str());
            js_pOrder.Set("Direction", string(1u, ptrCfd_pOrder->Direction).c_str());
            js_pOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CombOffsetFlag, strlen(ptrCfd_pOrder->CombOffsetFlag)) );
            js_pOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CombHedgeFlag, strlen(ptrCfd_pOrder->CombHedgeFlag)) );
            js_pOrder.Set("LimitPrice", ptrCfd_pOrder->LimitPrice);
            js_pOrder.Set("VolumeTotalOriginal", ptrCfd_pOrder->VolumeTotalOriginal);
            js_pOrder.Set("TimeCondition", string(1u, ptrCfd_pOrder->TimeCondition).c_str());
            js_pOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->GTDDate, strlen(ptrCfd_pOrder->GTDDate)) );
            js_pOrder.Set("VolumeCondition", string(1u, ptrCfd_pOrder->VolumeCondition).c_str());
            js_pOrder.Set("MinVolume", ptrCfd_pOrder->MinVolume);
            js_pOrder.Set("ContingentCondition", string(1u, ptrCfd_pOrder->ContingentCondition).c_str());
            js_pOrder.Set("StopPrice", ptrCfd_pOrder->StopPrice);
            js_pOrder.Set("ForceCloseReason", string(1u, ptrCfd_pOrder->ForceCloseReason).c_str());
            js_pOrder.Set("IsAutoSuspend", ptrCfd_pOrder->IsAutoSuspend);
            js_pOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->BusinessUnit, strlen(ptrCfd_pOrder->BusinessUnit)) );
            js_pOrder.Set("RequestID", ptrCfd_pOrder->RequestID);
            js_pOrder.Set("OrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->OrderLocalID, strlen(ptrCfd_pOrder->OrderLocalID)) );
            js_pOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ExchangeID, strlen(ptrCfd_pOrder->ExchangeID)) );
            js_pOrder.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ParticipantID, strlen(ptrCfd_pOrder->ParticipantID)) );
            js_pOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ClientID, strlen(ptrCfd_pOrder->ClientID)) );
            js_pOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->reserve2, strlen(ptrCfd_pOrder->reserve2)) );
            js_pOrder.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->TraderID, strlen(ptrCfd_pOrder->TraderID)) );
            js_pOrder.Set("InstallID", ptrCfd_pOrder->InstallID);
            js_pOrder.Set("OrderSubmitStatus", string(1u, ptrCfd_pOrder->OrderSubmitStatus).c_str());
            js_pOrder.Set("NotifySequence", ptrCfd_pOrder->NotifySequence);
            js_pOrder.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->TradingDay, strlen(ptrCfd_pOrder->TradingDay)) );
            js_pOrder.Set("SettlementID", ptrCfd_pOrder->SettlementID);
            js_pOrder.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->OrderSysID, strlen(ptrCfd_pOrder->OrderSysID)) );
            js_pOrder.Set("OrderSource", string(1u, ptrCfd_pOrder->OrderSource).c_str());
            js_pOrder.Set("OrderStatus", string(1u, ptrCfd_pOrder->OrderStatus).c_str());
            js_pOrder.Set("OrderType", string(1u, ptrCfd_pOrder->OrderType).c_str());
            js_pOrder.Set("VolumeTraded", ptrCfd_pOrder->VolumeTraded);
            js_pOrder.Set("VolumeTotal", ptrCfd_pOrder->VolumeTotal);
            js_pOrder.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InsertDate, strlen(ptrCfd_pOrder->InsertDate)) );
            js_pOrder.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InsertTime, strlen(ptrCfd_pOrder->InsertTime)) );
            js_pOrder.Set("ActiveTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ActiveTime, strlen(ptrCfd_pOrder->ActiveTime)) );
            js_pOrder.Set("SuspendTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->SuspendTime, strlen(ptrCfd_pOrder->SuspendTime)) );
            js_pOrder.Set("UpdateTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->UpdateTime, strlen(ptrCfd_pOrder->UpdateTime)) );
            js_pOrder.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CancelTime, strlen(ptrCfd_pOrder->CancelTime)) );
            js_pOrder.Set("ActiveTraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ActiveTraderID, strlen(ptrCfd_pOrder->ActiveTraderID)) );
            js_pOrder.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ClearingPartID, strlen(ptrCfd_pOrder->ClearingPartID)) );
            js_pOrder.Set("SequenceNo", ptrCfd_pOrder->SequenceNo);
            js_pOrder.Set("FrontID", ptrCfd_pOrder->FrontID);
            js_pOrder.Set("SessionID", ptrCfd_pOrder->SessionID);
            js_pOrder.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->UserProductInfo, strlen(ptrCfd_pOrder->UserProductInfo)) );
            js_pOrder.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->StatusMsg, strlen(ptrCfd_pOrder->StatusMsg)) );
            js_pOrder.Set("UserForceClose", ptrCfd_pOrder->UserForceClose);
            js_pOrder.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ActiveUserID, strlen(ptrCfd_pOrder->ActiveUserID)) );
            js_pOrder.Set("BrokerOrderSeq", ptrCfd_pOrder->BrokerOrderSeq);
            js_pOrder.Set("RelativeOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->RelativeOrderSysID, strlen(ptrCfd_pOrder->RelativeOrderSysID)) );
            js_pOrder.Set("ZCETotalTradedVolume", ptrCfd_pOrder->ZCETotalTradedVolume);
            js_pOrder.Set("IsSwapOrder", ptrCfd_pOrder->IsSwapOrder);
            js_pOrder.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->BranchID, strlen(ptrCfd_pOrder->BranchID)) );
            js_pOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InvestUnitID, strlen(ptrCfd_pOrder->InvestUnitID)) );
            js_pOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->AccountID, strlen(ptrCfd_pOrder->AccountID)) );
            js_pOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CurrencyID, strlen(ptrCfd_pOrder->CurrencyID)) );
            js_pOrder.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->reserve3, strlen(ptrCfd_pOrder->reserve3)) );
            js_pOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->MacAddress, strlen(ptrCfd_pOrder->MacAddress)) );
            js_pOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InstrumentID, strlen(ptrCfd_pOrder->InstrumentID)) );
            js_pOrder.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ExchangeInstID, strlen(ptrCfd_pOrder->ExchangeInstID)) );
            js_pOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->IPAddress, strlen(ptrCfd_pOrder->IPAddress)) );
            js_event_data.Set("pOrder", js_pOrder);
            delete ptrCfd_pOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryTrade(CThostFtdcTradeField * pTrade, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTradeField *ptrCfd_pTrade = new CThostFtdcTradeField();
        if(pTrade)
        {
            memcpy(ptrCfd_pTrade, pTrade, sizeof(CThostFtdcTradeField));
        }
        else
        {
            memset(ptrCfd_pTrade, 0, sizeof(CThostFtdcTradeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryTrade");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTrade = Napi::Object::New(env);
            js_pTrade.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->BrokerID, strlen(ptrCfd_pTrade->BrokerID)) );
            js_pTrade.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->InvestorID, strlen(ptrCfd_pTrade->InvestorID)) );
            js_pTrade.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->reserve1, strlen(ptrCfd_pTrade->reserve1)) );
            js_pTrade.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->OrderRef, strlen(ptrCfd_pTrade->OrderRef)) );
            js_pTrade.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->UserID, strlen(ptrCfd_pTrade->UserID)) );
            js_pTrade.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ExchangeID, strlen(ptrCfd_pTrade->ExchangeID)) );
            js_pTrade.Set("TradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradeID, strlen(ptrCfd_pTrade->TradeID)) );
            js_pTrade.Set("Direction", string(1u, ptrCfd_pTrade->Direction).c_str());
            js_pTrade.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->OrderSysID, strlen(ptrCfd_pTrade->OrderSysID)) );
            js_pTrade.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ParticipantID, strlen(ptrCfd_pTrade->ParticipantID)) );
            js_pTrade.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ClientID, strlen(ptrCfd_pTrade->ClientID)) );
            js_pTrade.Set("TradingRole", string(1u, ptrCfd_pTrade->TradingRole).c_str());
            js_pTrade.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->reserve2, strlen(ptrCfd_pTrade->reserve2)) );
            js_pTrade.Set("OffsetFlag", string(1u, ptrCfd_pTrade->OffsetFlag).c_str());
            js_pTrade.Set("HedgeFlag", string(1u, ptrCfd_pTrade->HedgeFlag).c_str());
            js_pTrade.Set("Price", ptrCfd_pTrade->Price);
            js_pTrade.Set("Volume", ptrCfd_pTrade->Volume);
            js_pTrade.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradeDate, strlen(ptrCfd_pTrade->TradeDate)) );
            js_pTrade.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradeTime, strlen(ptrCfd_pTrade->TradeTime)) );
            js_pTrade.Set("TradeType", string(1u, ptrCfd_pTrade->TradeType).c_str());
            js_pTrade.Set("PriceSource", string(1u, ptrCfd_pTrade->PriceSource).c_str());
            js_pTrade.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TraderID, strlen(ptrCfd_pTrade->TraderID)) );
            js_pTrade.Set("OrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->OrderLocalID, strlen(ptrCfd_pTrade->OrderLocalID)) );
            js_pTrade.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ClearingPartID, strlen(ptrCfd_pTrade->ClearingPartID)) );
            js_pTrade.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->BusinessUnit, strlen(ptrCfd_pTrade->BusinessUnit)) );
            js_pTrade.Set("SequenceNo", ptrCfd_pTrade->SequenceNo);
            js_pTrade.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradingDay, strlen(ptrCfd_pTrade->TradingDay)) );
            js_pTrade.Set("SettlementID", ptrCfd_pTrade->SettlementID);
            js_pTrade.Set("BrokerOrderSeq", ptrCfd_pTrade->BrokerOrderSeq);
            js_pTrade.Set("TradeSource", string(1u, ptrCfd_pTrade->TradeSource).c_str());
            js_pTrade.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->InvestUnitID, strlen(ptrCfd_pTrade->InvestUnitID)) );
            js_pTrade.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->InstrumentID, strlen(ptrCfd_pTrade->InstrumentID)) );
            js_pTrade.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ExchangeInstID, strlen(ptrCfd_pTrade->ExchangeInstID)) );
            js_event_data.Set("pTrade", js_pTrade);
            delete ptrCfd_pTrade;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField * pInvestorPosition, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInvestorPositionField *ptrCfd_pInvestorPosition = new CThostFtdcInvestorPositionField();
        if(pInvestorPosition)
        {
            memcpy(ptrCfd_pInvestorPosition, pInvestorPosition, sizeof(CThostFtdcInvestorPositionField));
        }
        else
        {
            memset(ptrCfd_pInvestorPosition, 0, sizeof(CThostFtdcInvestorPositionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInvestorPosition");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInvestorPosition = Napi::Object::New(env);
            js_pInvestorPosition.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->reserve1, strlen(ptrCfd_pInvestorPosition->reserve1)) );
            js_pInvestorPosition.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->BrokerID, strlen(ptrCfd_pInvestorPosition->BrokerID)) );
            js_pInvestorPosition.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->InvestorID, strlen(ptrCfd_pInvestorPosition->InvestorID)) );
            js_pInvestorPosition.Set("PosiDirection", string(1u, ptrCfd_pInvestorPosition->PosiDirection).c_str());
            js_pInvestorPosition.Set("HedgeFlag", string(1u, ptrCfd_pInvestorPosition->HedgeFlag).c_str());
            js_pInvestorPosition.Set("PositionDate", string(1u, ptrCfd_pInvestorPosition->PositionDate).c_str());
            js_pInvestorPosition.Set("YdPosition", ptrCfd_pInvestorPosition->YdPosition);
            js_pInvestorPosition.Set("Position", ptrCfd_pInvestorPosition->Position);
            js_pInvestorPosition.Set("LongFrozen", ptrCfd_pInvestorPosition->LongFrozen);
            js_pInvestorPosition.Set("ShortFrozen", ptrCfd_pInvestorPosition->ShortFrozen);
            js_pInvestorPosition.Set("LongFrozenAmount", ptrCfd_pInvestorPosition->LongFrozenAmount);
            js_pInvestorPosition.Set("ShortFrozenAmount", ptrCfd_pInvestorPosition->ShortFrozenAmount);
            js_pInvestorPosition.Set("OpenVolume", ptrCfd_pInvestorPosition->OpenVolume);
            js_pInvestorPosition.Set("CloseVolume", ptrCfd_pInvestorPosition->CloseVolume);
            js_pInvestorPosition.Set("OpenAmount", ptrCfd_pInvestorPosition->OpenAmount);
            js_pInvestorPosition.Set("CloseAmount", ptrCfd_pInvestorPosition->CloseAmount);
            js_pInvestorPosition.Set("PositionCost", ptrCfd_pInvestorPosition->PositionCost);
            js_pInvestorPosition.Set("PreMargin", ptrCfd_pInvestorPosition->PreMargin);
            js_pInvestorPosition.Set("UseMargin", ptrCfd_pInvestorPosition->UseMargin);
            js_pInvestorPosition.Set("FrozenMargin", ptrCfd_pInvestorPosition->FrozenMargin);
            js_pInvestorPosition.Set("FrozenCash", ptrCfd_pInvestorPosition->FrozenCash);
            js_pInvestorPosition.Set("FrozenCommission", ptrCfd_pInvestorPosition->FrozenCommission);
            js_pInvestorPosition.Set("CashIn", ptrCfd_pInvestorPosition->CashIn);
            js_pInvestorPosition.Set("Commission", ptrCfd_pInvestorPosition->Commission);
            js_pInvestorPosition.Set("CloseProfit", ptrCfd_pInvestorPosition->CloseProfit);
            js_pInvestorPosition.Set("PositionProfit", ptrCfd_pInvestorPosition->PositionProfit);
            js_pInvestorPosition.Set("PreSettlementPrice", ptrCfd_pInvestorPosition->PreSettlementPrice);
            js_pInvestorPosition.Set("SettlementPrice", ptrCfd_pInvestorPosition->SettlementPrice);
            js_pInvestorPosition.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->TradingDay, strlen(ptrCfd_pInvestorPosition->TradingDay)) );
            js_pInvestorPosition.Set("SettlementID", ptrCfd_pInvestorPosition->SettlementID);
            js_pInvestorPosition.Set("OpenCost", ptrCfd_pInvestorPosition->OpenCost);
            js_pInvestorPosition.Set("ExchangeMargin", ptrCfd_pInvestorPosition->ExchangeMargin);
            js_pInvestorPosition.Set("CombPosition", ptrCfd_pInvestorPosition->CombPosition);
            js_pInvestorPosition.Set("CombLongFrozen", ptrCfd_pInvestorPosition->CombLongFrozen);
            js_pInvestorPosition.Set("CombShortFrozen", ptrCfd_pInvestorPosition->CombShortFrozen);
            js_pInvestorPosition.Set("CloseProfitByDate", ptrCfd_pInvestorPosition->CloseProfitByDate);
            js_pInvestorPosition.Set("CloseProfitByTrade", ptrCfd_pInvestorPosition->CloseProfitByTrade);
            js_pInvestorPosition.Set("TodayPosition", ptrCfd_pInvestorPosition->TodayPosition);
            js_pInvestorPosition.Set("MarginRateByMoney", ptrCfd_pInvestorPosition->MarginRateByMoney);
            js_pInvestorPosition.Set("MarginRateByVolume", ptrCfd_pInvestorPosition->MarginRateByVolume);
            js_pInvestorPosition.Set("StrikeFrozen", ptrCfd_pInvestorPosition->StrikeFrozen);
            js_pInvestorPosition.Set("StrikeFrozenAmount", ptrCfd_pInvestorPosition->StrikeFrozenAmount);
            js_pInvestorPosition.Set("AbandonFrozen", ptrCfd_pInvestorPosition->AbandonFrozen);
            js_pInvestorPosition.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->ExchangeID, strlen(ptrCfd_pInvestorPosition->ExchangeID)) );
            js_pInvestorPosition.Set("YdStrikeFrozen", ptrCfd_pInvestorPosition->YdStrikeFrozen);
            js_pInvestorPosition.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->InvestUnitID, strlen(ptrCfd_pInvestorPosition->InvestUnitID)) );
            js_pInvestorPosition.Set("PositionCostOffset", ptrCfd_pInvestorPosition->PositionCostOffset);
            js_pInvestorPosition.Set("TasPosition", ptrCfd_pInvestorPosition->TasPosition);
            js_pInvestorPosition.Set("TasPositionCost", ptrCfd_pInvestorPosition->TasPositionCost);
            js_pInvestorPosition.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPosition->InstrumentID, strlen(ptrCfd_pInvestorPosition->InstrumentID)) );
            js_event_data.Set("pInvestorPosition", js_pInvestorPosition);
            delete ptrCfd_pInvestorPosition;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryTradingAccount(CThostFtdcTradingAccountField * pTradingAccount, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTradingAccountField *ptrCfd_pTradingAccount = new CThostFtdcTradingAccountField();
        if(pTradingAccount)
        {
            memcpy(ptrCfd_pTradingAccount, pTradingAccount, sizeof(CThostFtdcTradingAccountField));
        }
        else
        {
            memset(ptrCfd_pTradingAccount, 0, sizeof(CThostFtdcTradingAccountField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryTradingAccount");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTradingAccount = Napi::Object::New(env);
            js_pTradingAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->BrokerID, strlen(ptrCfd_pTradingAccount->BrokerID)) );
            js_pTradingAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->AccountID, strlen(ptrCfd_pTradingAccount->AccountID)) );
            js_pTradingAccount.Set("PreMortgage", ptrCfd_pTradingAccount->PreMortgage);
            js_pTradingAccount.Set("PreCredit", ptrCfd_pTradingAccount->PreCredit);
            js_pTradingAccount.Set("PreDeposit", ptrCfd_pTradingAccount->PreDeposit);
            js_pTradingAccount.Set("PreBalance", ptrCfd_pTradingAccount->PreBalance);
            js_pTradingAccount.Set("PreMargin", ptrCfd_pTradingAccount->PreMargin);
            js_pTradingAccount.Set("InterestBase", ptrCfd_pTradingAccount->InterestBase);
            js_pTradingAccount.Set("Interest", ptrCfd_pTradingAccount->Interest);
            js_pTradingAccount.Set("Deposit", ptrCfd_pTradingAccount->Deposit);
            js_pTradingAccount.Set("Withdraw", ptrCfd_pTradingAccount->Withdraw);
            js_pTradingAccount.Set("FrozenMargin", ptrCfd_pTradingAccount->FrozenMargin);
            js_pTradingAccount.Set("FrozenCash", ptrCfd_pTradingAccount->FrozenCash);
            js_pTradingAccount.Set("FrozenCommission", ptrCfd_pTradingAccount->FrozenCommission);
            js_pTradingAccount.Set("CurrMargin", ptrCfd_pTradingAccount->CurrMargin);
            js_pTradingAccount.Set("CashIn", ptrCfd_pTradingAccount->CashIn);
            js_pTradingAccount.Set("Commission", ptrCfd_pTradingAccount->Commission);
            js_pTradingAccount.Set("CloseProfit", ptrCfd_pTradingAccount->CloseProfit);
            js_pTradingAccount.Set("PositionProfit", ptrCfd_pTradingAccount->PositionProfit);
            js_pTradingAccount.Set("Balance", ptrCfd_pTradingAccount->Balance);
            js_pTradingAccount.Set("Available", ptrCfd_pTradingAccount->Available);
            js_pTradingAccount.Set("WithdrawQuota", ptrCfd_pTradingAccount->WithdrawQuota);
            js_pTradingAccount.Set("Reserve", ptrCfd_pTradingAccount->Reserve);
            js_pTradingAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->TradingDay, strlen(ptrCfd_pTradingAccount->TradingDay)) );
            js_pTradingAccount.Set("SettlementID", ptrCfd_pTradingAccount->SettlementID);
            js_pTradingAccount.Set("Credit", ptrCfd_pTradingAccount->Credit);
            js_pTradingAccount.Set("Mortgage", ptrCfd_pTradingAccount->Mortgage);
            js_pTradingAccount.Set("ExchangeMargin", ptrCfd_pTradingAccount->ExchangeMargin);
            js_pTradingAccount.Set("DeliveryMargin", ptrCfd_pTradingAccount->DeliveryMargin);
            js_pTradingAccount.Set("ExchangeDeliveryMargin", ptrCfd_pTradingAccount->ExchangeDeliveryMargin);
            js_pTradingAccount.Set("ReserveBalance", ptrCfd_pTradingAccount->ReserveBalance);
            js_pTradingAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->CurrencyID, strlen(ptrCfd_pTradingAccount->CurrencyID)) );
            js_pTradingAccount.Set("PreFundMortgageIn", ptrCfd_pTradingAccount->PreFundMortgageIn);
            js_pTradingAccount.Set("PreFundMortgageOut", ptrCfd_pTradingAccount->PreFundMortgageOut);
            js_pTradingAccount.Set("FundMortgageIn", ptrCfd_pTradingAccount->FundMortgageIn);
            js_pTradingAccount.Set("FundMortgageOut", ptrCfd_pTradingAccount->FundMortgageOut);
            js_pTradingAccount.Set("FundMortgageAvailable", ptrCfd_pTradingAccount->FundMortgageAvailable);
            js_pTradingAccount.Set("MortgageableFund", ptrCfd_pTradingAccount->MortgageableFund);
            js_pTradingAccount.Set("SpecProductMargin", ptrCfd_pTradingAccount->SpecProductMargin);
            js_pTradingAccount.Set("SpecProductFrozenMargin", ptrCfd_pTradingAccount->SpecProductFrozenMargin);
            js_pTradingAccount.Set("SpecProductCommission", ptrCfd_pTradingAccount->SpecProductCommission);
            js_pTradingAccount.Set("SpecProductFrozenCommission", ptrCfd_pTradingAccount->SpecProductFrozenCommission);
            js_pTradingAccount.Set("SpecProductPositionProfit", ptrCfd_pTradingAccount->SpecProductPositionProfit);
            js_pTradingAccount.Set("SpecProductCloseProfit", ptrCfd_pTradingAccount->SpecProductCloseProfit);
            js_pTradingAccount.Set("SpecProductPositionProfitByAlg", ptrCfd_pTradingAccount->SpecProductPositionProfitByAlg);
            js_pTradingAccount.Set("SpecProductExchangeMargin", ptrCfd_pTradingAccount->SpecProductExchangeMargin);
            js_pTradingAccount.Set("BizType", string(1u, ptrCfd_pTradingAccount->BizType).c_str());
            js_pTradingAccount.Set("FrozenSwap", ptrCfd_pTradingAccount->FrozenSwap);
            js_pTradingAccount.Set("RemainSwap", ptrCfd_pTradingAccount->RemainSwap);
            js_event_data.Set("pTradingAccount", js_pTradingAccount);
            delete ptrCfd_pTradingAccount;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInvestor(CThostFtdcInvestorField * pInvestor, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInvestorField *ptrCfd_pInvestor = new CThostFtdcInvestorField();
        if(pInvestor)
        {
            memcpy(ptrCfd_pInvestor, pInvestor, sizeof(CThostFtdcInvestorField));
        }
        else
        {
            memset(ptrCfd_pInvestor, 0, sizeof(CThostFtdcInvestorField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInvestor");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInvestor = Napi::Object::New(env);
            js_pInvestor.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->InvestorID, strlen(ptrCfd_pInvestor->InvestorID)) );
            js_pInvestor.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->BrokerID, strlen(ptrCfd_pInvestor->BrokerID)) );
            js_pInvestor.Set("InvestorGroupID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->InvestorGroupID, strlen(ptrCfd_pInvestor->InvestorGroupID)) );
            js_pInvestor.Set("InvestorName", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->InvestorName, strlen(ptrCfd_pInvestor->InvestorName)) );
            js_pInvestor.Set("IdentifiedCardType", string(1u, ptrCfd_pInvestor->IdentifiedCardType).c_str());
            js_pInvestor.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->IdentifiedCardNo, strlen(ptrCfd_pInvestor->IdentifiedCardNo)) );
            js_pInvestor.Set("IsActive", ptrCfd_pInvestor->IsActive);
            js_pInvestor.Set("Telephone", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->Telephone, strlen(ptrCfd_pInvestor->Telephone)) );
            js_pInvestor.Set("Address", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->Address, strlen(ptrCfd_pInvestor->Address)) );
            js_pInvestor.Set("OpenDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->OpenDate, strlen(ptrCfd_pInvestor->OpenDate)) );
            js_pInvestor.Set("Mobile", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->Mobile, strlen(ptrCfd_pInvestor->Mobile)) );
            js_pInvestor.Set("CommModelID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->CommModelID, strlen(ptrCfd_pInvestor->CommModelID)) );
            js_pInvestor.Set("MarginModelID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestor->MarginModelID, strlen(ptrCfd_pInvestor->MarginModelID)) );
            js_event_data.Set("pInvestor", js_pInvestor);
            delete ptrCfd_pInvestor;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryTradingCode(CThostFtdcTradingCodeField * pTradingCode, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTradingCodeField *ptrCfd_pTradingCode = new CThostFtdcTradingCodeField();
        if(pTradingCode)
        {
            memcpy(ptrCfd_pTradingCode, pTradingCode, sizeof(CThostFtdcTradingCodeField));
        }
        else
        {
            memset(ptrCfd_pTradingCode, 0, sizeof(CThostFtdcTradingCodeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryTradingCode");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTradingCode = Napi::Object::New(env);
            js_pTradingCode.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingCode->InvestorID, strlen(ptrCfd_pTradingCode->InvestorID)) );
            js_pTradingCode.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingCode->BrokerID, strlen(ptrCfd_pTradingCode->BrokerID)) );
            js_pTradingCode.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingCode->ExchangeID, strlen(ptrCfd_pTradingCode->ExchangeID)) );
            js_pTradingCode.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingCode->ClientID, strlen(ptrCfd_pTradingCode->ClientID)) );
            js_pTradingCode.Set("IsActive", ptrCfd_pTradingCode->IsActive);
            js_pTradingCode.Set("ClientIDType", string(1u, ptrCfd_pTradingCode->ClientIDType).c_str());
            js_pTradingCode.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingCode->BranchID, strlen(ptrCfd_pTradingCode->BranchID)) );
            js_pTradingCode.Set("BizType", string(1u, ptrCfd_pTradingCode->BizType).c_str());
            js_pTradingCode.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingCode->InvestUnitID, strlen(ptrCfd_pTradingCode->InvestUnitID)) );
            js_event_data.Set("pTradingCode", js_pTradingCode);
            delete ptrCfd_pTradingCode;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField * pInstrumentMarginRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInstrumentMarginRateField *ptrCfd_pInstrumentMarginRate = new CThostFtdcInstrumentMarginRateField();
        if(pInstrumentMarginRate)
        {
            memcpy(ptrCfd_pInstrumentMarginRate, pInstrumentMarginRate, sizeof(CThostFtdcInstrumentMarginRateField));
        }
        else
        {
            memset(ptrCfd_pInstrumentMarginRate, 0, sizeof(CThostFtdcInstrumentMarginRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInstrumentMarginRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInstrumentMarginRate = Napi::Object::New(env);
            js_pInstrumentMarginRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentMarginRate->reserve1, strlen(ptrCfd_pInstrumentMarginRate->reserve1)) );
            js_pInstrumentMarginRate.Set("InvestorRange", string(1u, ptrCfd_pInstrumentMarginRate->InvestorRange).c_str());
            js_pInstrumentMarginRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentMarginRate->BrokerID, strlen(ptrCfd_pInstrumentMarginRate->BrokerID)) );
            js_pInstrumentMarginRate.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentMarginRate->InvestorID, strlen(ptrCfd_pInstrumentMarginRate->InvestorID)) );
            js_pInstrumentMarginRate.Set("HedgeFlag", string(1u, ptrCfd_pInstrumentMarginRate->HedgeFlag).c_str());
            js_pInstrumentMarginRate.Set("LongMarginRatioByMoney", ptrCfd_pInstrumentMarginRate->LongMarginRatioByMoney);
            js_pInstrumentMarginRate.Set("LongMarginRatioByVolume", ptrCfd_pInstrumentMarginRate->LongMarginRatioByVolume);
            js_pInstrumentMarginRate.Set("ShortMarginRatioByMoney", ptrCfd_pInstrumentMarginRate->ShortMarginRatioByMoney);
            js_pInstrumentMarginRate.Set("ShortMarginRatioByVolume", ptrCfd_pInstrumentMarginRate->ShortMarginRatioByVolume);
            js_pInstrumentMarginRate.Set("IsRelative", ptrCfd_pInstrumentMarginRate->IsRelative);
            js_pInstrumentMarginRate.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentMarginRate->ExchangeID, strlen(ptrCfd_pInstrumentMarginRate->ExchangeID)) );
            js_pInstrumentMarginRate.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentMarginRate->InvestUnitID, strlen(ptrCfd_pInstrumentMarginRate->InvestUnitID)) );
            js_pInstrumentMarginRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentMarginRate->InstrumentID, strlen(ptrCfd_pInstrumentMarginRate->InstrumentID)) );
            js_event_data.Set("pInstrumentMarginRate", js_pInstrumentMarginRate);
            delete ptrCfd_pInstrumentMarginRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField * pInstrumentCommissionRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInstrumentCommissionRateField *ptrCfd_pInstrumentCommissionRate = new CThostFtdcInstrumentCommissionRateField();
        if(pInstrumentCommissionRate)
        {
            memcpy(ptrCfd_pInstrumentCommissionRate, pInstrumentCommissionRate, sizeof(CThostFtdcInstrumentCommissionRateField));
        }
        else
        {
            memset(ptrCfd_pInstrumentCommissionRate, 0, sizeof(CThostFtdcInstrumentCommissionRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInstrumentCommissionRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInstrumentCommissionRate = Napi::Object::New(env);
            js_pInstrumentCommissionRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentCommissionRate->reserve1, strlen(ptrCfd_pInstrumentCommissionRate->reserve1)) );
            js_pInstrumentCommissionRate.Set("InvestorRange", string(1u, ptrCfd_pInstrumentCommissionRate->InvestorRange).c_str());
            js_pInstrumentCommissionRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentCommissionRate->BrokerID, strlen(ptrCfd_pInstrumentCommissionRate->BrokerID)) );
            js_pInstrumentCommissionRate.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentCommissionRate->InvestorID, strlen(ptrCfd_pInstrumentCommissionRate->InvestorID)) );
            js_pInstrumentCommissionRate.Set("OpenRatioByMoney", ptrCfd_pInstrumentCommissionRate->OpenRatioByMoney);
            js_pInstrumentCommissionRate.Set("OpenRatioByVolume", ptrCfd_pInstrumentCommissionRate->OpenRatioByVolume);
            js_pInstrumentCommissionRate.Set("CloseRatioByMoney", ptrCfd_pInstrumentCommissionRate->CloseRatioByMoney);
            js_pInstrumentCommissionRate.Set("CloseRatioByVolume", ptrCfd_pInstrumentCommissionRate->CloseRatioByVolume);
            js_pInstrumentCommissionRate.Set("CloseTodayRatioByMoney", ptrCfd_pInstrumentCommissionRate->CloseTodayRatioByMoney);
            js_pInstrumentCommissionRate.Set("CloseTodayRatioByVolume", ptrCfd_pInstrumentCommissionRate->CloseTodayRatioByVolume);
            js_pInstrumentCommissionRate.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentCommissionRate->ExchangeID, strlen(ptrCfd_pInstrumentCommissionRate->ExchangeID)) );
            js_pInstrumentCommissionRate.Set("BizType", string(1u, ptrCfd_pInstrumentCommissionRate->BizType).c_str());
            js_pInstrumentCommissionRate.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentCommissionRate->InvestUnitID, strlen(ptrCfd_pInstrumentCommissionRate->InvestUnitID)) );
            js_pInstrumentCommissionRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentCommissionRate->InstrumentID, strlen(ptrCfd_pInstrumentCommissionRate->InstrumentID)) );
            js_event_data.Set("pInstrumentCommissionRate", js_pInstrumentCommissionRate);
            delete ptrCfd_pInstrumentCommissionRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryExchange(CThostFtdcExchangeField * pExchange, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcExchangeField *ptrCfd_pExchange = new CThostFtdcExchangeField();
        if(pExchange)
        {
            memcpy(ptrCfd_pExchange, pExchange, sizeof(CThostFtdcExchangeField));
        }
        else
        {
            memset(ptrCfd_pExchange, 0, sizeof(CThostFtdcExchangeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryExchange");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExchange = Napi::Object::New(env);
            js_pExchange.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchange->ExchangeID, strlen(ptrCfd_pExchange->ExchangeID)) );
            js_pExchange.Set("ExchangeName", Napi::Buffer<char>::Copy(env, ptrCfd_pExchange->ExchangeName, strlen(ptrCfd_pExchange->ExchangeName)) );
            js_pExchange.Set("ExchangeProperty", string(1u, ptrCfd_pExchange->ExchangeProperty).c_str());
            js_event_data.Set("pExchange", js_pExchange);
            delete ptrCfd_pExchange;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryProduct(CThostFtdcProductField * pProduct, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcProductField *ptrCfd_pProduct = new CThostFtdcProductField();
        if(pProduct)
        {
            memcpy(ptrCfd_pProduct, pProduct, sizeof(CThostFtdcProductField));
        }
        else
        {
            memset(ptrCfd_pProduct, 0, sizeof(CThostFtdcProductField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryProduct");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pProduct = Napi::Object::New(env);
            js_pProduct.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->reserve1, strlen(ptrCfd_pProduct->reserve1)) );
            js_pProduct.Set("ProductName", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->ProductName, strlen(ptrCfd_pProduct->ProductName)) );
            js_pProduct.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->ExchangeID, strlen(ptrCfd_pProduct->ExchangeID)) );
            js_pProduct.Set("ProductClass", string(1u, ptrCfd_pProduct->ProductClass).c_str());
            js_pProduct.Set("VolumeMultiple", ptrCfd_pProduct->VolumeMultiple);
            js_pProduct.Set("PriceTick", ptrCfd_pProduct->PriceTick);
            js_pProduct.Set("MaxMarketOrderVolume", ptrCfd_pProduct->MaxMarketOrderVolume);
            js_pProduct.Set("MinMarketOrderVolume", ptrCfd_pProduct->MinMarketOrderVolume);
            js_pProduct.Set("MaxLimitOrderVolume", ptrCfd_pProduct->MaxLimitOrderVolume);
            js_pProduct.Set("MinLimitOrderVolume", ptrCfd_pProduct->MinLimitOrderVolume);
            js_pProduct.Set("PositionType", string(1u, ptrCfd_pProduct->PositionType).c_str());
            js_pProduct.Set("PositionDateType", string(1u, ptrCfd_pProduct->PositionDateType).c_str());
            js_pProduct.Set("CloseDealType", string(1u, ptrCfd_pProduct->CloseDealType).c_str());
            js_pProduct.Set("TradeCurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->TradeCurrencyID, strlen(ptrCfd_pProduct->TradeCurrencyID)) );
            js_pProduct.Set("MortgageFundUseRange", string(1u, ptrCfd_pProduct->MortgageFundUseRange).c_str());
            js_pProduct.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->reserve2, strlen(ptrCfd_pProduct->reserve2)) );
            js_pProduct.Set("UnderlyingMultiple", ptrCfd_pProduct->UnderlyingMultiple);
            js_pProduct.Set("ProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->ProductID, strlen(ptrCfd_pProduct->ProductID)) );
            js_pProduct.Set("ExchangeProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pProduct->ExchangeProductID, strlen(ptrCfd_pProduct->ExchangeProductID)) );
            js_event_data.Set("pProduct", js_pProduct);
            delete ptrCfd_pProduct;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInstrument(CThostFtdcInstrumentField * pInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInstrumentField *ptrCfd_pInstrument = new CThostFtdcInstrumentField();
        if(pInstrument)
        {
            memcpy(ptrCfd_pInstrument, pInstrument, sizeof(CThostFtdcInstrumentField));
        }
        else
        {
            memset(ptrCfd_pInstrument, 0, sizeof(CThostFtdcInstrumentField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInstrument");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInstrument = Napi::Object::New(env);
            js_pInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve1, strlen(ptrCfd_pInstrument->reserve1)) );
            js_pInstrument.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ExchangeID, strlen(ptrCfd_pInstrument->ExchangeID)) );
            js_pInstrument.Set("InstrumentName", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->InstrumentName, strlen(ptrCfd_pInstrument->InstrumentName)) );
            js_pInstrument.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve2, strlen(ptrCfd_pInstrument->reserve2)) );
            js_pInstrument.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve3, strlen(ptrCfd_pInstrument->reserve3)) );
            js_pInstrument.Set("ProductClass", string(1u, ptrCfd_pInstrument->ProductClass).c_str());
            js_pInstrument.Set("DeliveryYear", ptrCfd_pInstrument->DeliveryYear);
            js_pInstrument.Set("DeliveryMonth", ptrCfd_pInstrument->DeliveryMonth);
            js_pInstrument.Set("MaxMarketOrderVolume", ptrCfd_pInstrument->MaxMarketOrderVolume);
            js_pInstrument.Set("MinMarketOrderVolume", ptrCfd_pInstrument->MinMarketOrderVolume);
            js_pInstrument.Set("MaxLimitOrderVolume", ptrCfd_pInstrument->MaxLimitOrderVolume);
            js_pInstrument.Set("MinLimitOrderVolume", ptrCfd_pInstrument->MinLimitOrderVolume);
            js_pInstrument.Set("VolumeMultiple", ptrCfd_pInstrument->VolumeMultiple);
            js_pInstrument.Set("PriceTick", ptrCfd_pInstrument->PriceTick);
            js_pInstrument.Set("CreateDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->CreateDate, strlen(ptrCfd_pInstrument->CreateDate)) );
            js_pInstrument.Set("OpenDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->OpenDate, strlen(ptrCfd_pInstrument->OpenDate)) );
            js_pInstrument.Set("ExpireDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ExpireDate, strlen(ptrCfd_pInstrument->ExpireDate)) );
            js_pInstrument.Set("StartDelivDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->StartDelivDate, strlen(ptrCfd_pInstrument->StartDelivDate)) );
            js_pInstrument.Set("EndDelivDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->EndDelivDate, strlen(ptrCfd_pInstrument->EndDelivDate)) );
            js_pInstrument.Set("InstLifePhase", string(1u, ptrCfd_pInstrument->InstLifePhase).c_str());
            js_pInstrument.Set("IsTrading", ptrCfd_pInstrument->IsTrading);
            js_pInstrument.Set("PositionType", string(1u, ptrCfd_pInstrument->PositionType).c_str());
            js_pInstrument.Set("PositionDateType", string(1u, ptrCfd_pInstrument->PositionDateType).c_str());
            js_pInstrument.Set("LongMarginRatio", ptrCfd_pInstrument->LongMarginRatio);
            js_pInstrument.Set("ShortMarginRatio", ptrCfd_pInstrument->ShortMarginRatio);
            js_pInstrument.Set("MaxMarginSideAlgorithm", string(1u, ptrCfd_pInstrument->MaxMarginSideAlgorithm).c_str());
            js_pInstrument.Set("reserve4", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve4, strlen(ptrCfd_pInstrument->reserve4)) );
            js_pInstrument.Set("StrikePrice", ptrCfd_pInstrument->StrikePrice);
            js_pInstrument.Set("OptionsType", string(1u, ptrCfd_pInstrument->OptionsType).c_str());
            js_pInstrument.Set("UnderlyingMultiple", ptrCfd_pInstrument->UnderlyingMultiple);
            js_pInstrument.Set("CombinationType", string(1u, ptrCfd_pInstrument->CombinationType).c_str());
            js_pInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->InstrumentID, strlen(ptrCfd_pInstrument->InstrumentID)) );
            js_pInstrument.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ExchangeInstID, strlen(ptrCfd_pInstrument->ExchangeInstID)) );
            js_pInstrument.Set("ProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ProductID, strlen(ptrCfd_pInstrument->ProductID)) );
            js_pInstrument.Set("UnderlyingInstrID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->UnderlyingInstrID, strlen(ptrCfd_pInstrument->UnderlyingInstrID)) );
            js_event_data.Set("pInstrument", js_pInstrument);
            delete ptrCfd_pInstrument;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketData, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcDepthMarketDataField *ptrCfd_pDepthMarketData = new CThostFtdcDepthMarketDataField();
        if(pDepthMarketData)
        {
            memcpy(ptrCfd_pDepthMarketData, pDepthMarketData, sizeof(CThostFtdcDepthMarketDataField));
        }
        else
        {
            memset(ptrCfd_pDepthMarketData, 0, sizeof(CThostFtdcDepthMarketDataField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryDepthMarketData");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pDepthMarketData = Napi::Object::New(env);
            js_pDepthMarketData.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->TradingDay, strlen(ptrCfd_pDepthMarketData->TradingDay)) );
            js_pDepthMarketData.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->reserve1, strlen(ptrCfd_pDepthMarketData->reserve1)) );
            js_pDepthMarketData.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->ExchangeID, strlen(ptrCfd_pDepthMarketData->ExchangeID)) );
            js_pDepthMarketData.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->reserve2, strlen(ptrCfd_pDepthMarketData->reserve2)) );
            js_pDepthMarketData.Set("LastPrice", ptrCfd_pDepthMarketData->LastPrice);
            js_pDepthMarketData.Set("PreSettlementPrice", ptrCfd_pDepthMarketData->PreSettlementPrice);
            js_pDepthMarketData.Set("PreClosePrice", ptrCfd_pDepthMarketData->PreClosePrice);
            js_pDepthMarketData.Set("PreOpenInterest", ptrCfd_pDepthMarketData->PreOpenInterest);
            js_pDepthMarketData.Set("OpenPrice", ptrCfd_pDepthMarketData->OpenPrice);
            js_pDepthMarketData.Set("HighestPrice", ptrCfd_pDepthMarketData->HighestPrice);
            js_pDepthMarketData.Set("LowestPrice", ptrCfd_pDepthMarketData->LowestPrice);
            js_pDepthMarketData.Set("Volume", ptrCfd_pDepthMarketData->Volume);
            js_pDepthMarketData.Set("Turnover", ptrCfd_pDepthMarketData->Turnover);
            js_pDepthMarketData.Set("OpenInterest", ptrCfd_pDepthMarketData->OpenInterest);
            js_pDepthMarketData.Set("ClosePrice", ptrCfd_pDepthMarketData->ClosePrice);
            js_pDepthMarketData.Set("SettlementPrice", ptrCfd_pDepthMarketData->SettlementPrice);
            js_pDepthMarketData.Set("UpperLimitPrice", ptrCfd_pDepthMarketData->UpperLimitPrice);
            js_pDepthMarketData.Set("LowerLimitPrice", ptrCfd_pDepthMarketData->LowerLimitPrice);
            js_pDepthMarketData.Set("PreDelta", ptrCfd_pDepthMarketData->PreDelta);
            js_pDepthMarketData.Set("CurrDelta", ptrCfd_pDepthMarketData->CurrDelta);
            js_pDepthMarketData.Set("UpdateTime", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->UpdateTime, strlen(ptrCfd_pDepthMarketData->UpdateTime)) );
            js_pDepthMarketData.Set("UpdateMillisec", ptrCfd_pDepthMarketData->UpdateMillisec);
            js_pDepthMarketData.Set("BidPrice1", ptrCfd_pDepthMarketData->BidPrice1);
            js_pDepthMarketData.Set("BidVolume1", ptrCfd_pDepthMarketData->BidVolume1);
            js_pDepthMarketData.Set("AskPrice1", ptrCfd_pDepthMarketData->AskPrice1);
            js_pDepthMarketData.Set("AskVolume1", ptrCfd_pDepthMarketData->AskVolume1);
            js_pDepthMarketData.Set("BidPrice2", ptrCfd_pDepthMarketData->BidPrice2);
            js_pDepthMarketData.Set("BidVolume2", ptrCfd_pDepthMarketData->BidVolume2);
            js_pDepthMarketData.Set("AskPrice2", ptrCfd_pDepthMarketData->AskPrice2);
            js_pDepthMarketData.Set("AskVolume2", ptrCfd_pDepthMarketData->AskVolume2);
            js_pDepthMarketData.Set("BidPrice3", ptrCfd_pDepthMarketData->BidPrice3);
            js_pDepthMarketData.Set("BidVolume3", ptrCfd_pDepthMarketData->BidVolume3);
            js_pDepthMarketData.Set("AskPrice3", ptrCfd_pDepthMarketData->AskPrice3);
            js_pDepthMarketData.Set("AskVolume3", ptrCfd_pDepthMarketData->AskVolume3);
            js_pDepthMarketData.Set("BidPrice4", ptrCfd_pDepthMarketData->BidPrice4);
            js_pDepthMarketData.Set("BidVolume4", ptrCfd_pDepthMarketData->BidVolume4);
            js_pDepthMarketData.Set("AskPrice4", ptrCfd_pDepthMarketData->AskPrice4);
            js_pDepthMarketData.Set("AskVolume4", ptrCfd_pDepthMarketData->AskVolume4);
            js_pDepthMarketData.Set("BidPrice5", ptrCfd_pDepthMarketData->BidPrice5);
            js_pDepthMarketData.Set("BidVolume5", ptrCfd_pDepthMarketData->BidVolume5);
            js_pDepthMarketData.Set("AskPrice5", ptrCfd_pDepthMarketData->AskPrice5);
            js_pDepthMarketData.Set("AskVolume5", ptrCfd_pDepthMarketData->AskVolume5);
            js_pDepthMarketData.Set("AveragePrice", ptrCfd_pDepthMarketData->AveragePrice);
            js_pDepthMarketData.Set("ActionDay", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->ActionDay, strlen(ptrCfd_pDepthMarketData->ActionDay)) );
            js_pDepthMarketData.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->InstrumentID, strlen(ptrCfd_pDepthMarketData->InstrumentID)) );
            js_pDepthMarketData.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pDepthMarketData->ExchangeInstID, strlen(ptrCfd_pDepthMarketData->ExchangeInstID)) );
            js_pDepthMarketData.Set("BandingUpperPrice", ptrCfd_pDepthMarketData->BandingUpperPrice);
            js_pDepthMarketData.Set("BandingLowerPrice", ptrCfd_pDepthMarketData->BandingLowerPrice);
            js_event_data.Set("pDepthMarketData", js_pDepthMarketData);
            delete ptrCfd_pDepthMarketData;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField * pSettlementInfo, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSettlementInfoField *ptrCfd_pSettlementInfo = new CThostFtdcSettlementInfoField();
        if(pSettlementInfo)
        {
            memcpy(ptrCfd_pSettlementInfo, pSettlementInfo, sizeof(CThostFtdcSettlementInfoField));
        }
        else
        {
            memset(ptrCfd_pSettlementInfo, 0, sizeof(CThostFtdcSettlementInfoField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQrySettlementInfo");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSettlementInfo = Napi::Object::New(env);
            js_pSettlementInfo.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfo->TradingDay, strlen(ptrCfd_pSettlementInfo->TradingDay)) );
            js_pSettlementInfo.Set("SettlementID", ptrCfd_pSettlementInfo->SettlementID);
            js_pSettlementInfo.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfo->BrokerID, strlen(ptrCfd_pSettlementInfo->BrokerID)) );
            js_pSettlementInfo.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfo->InvestorID, strlen(ptrCfd_pSettlementInfo->InvestorID)) );
            js_pSettlementInfo.Set("SequenceNo", ptrCfd_pSettlementInfo->SequenceNo);
            js_pSettlementInfo.Set("Content", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfo->Content, strlen(ptrCfd_pSettlementInfo->Content)) );
            js_pSettlementInfo.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfo->AccountID, strlen(ptrCfd_pSettlementInfo->AccountID)) );
            js_pSettlementInfo.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfo->CurrencyID, strlen(ptrCfd_pSettlementInfo->CurrencyID)) );
            js_event_data.Set("pSettlementInfo", js_pSettlementInfo);
            delete ptrCfd_pSettlementInfo;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryTransferBank(CThostFtdcTransferBankField * pTransferBank, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTransferBankField *ptrCfd_pTransferBank = new CThostFtdcTransferBankField();
        if(pTransferBank)
        {
            memcpy(ptrCfd_pTransferBank, pTransferBank, sizeof(CThostFtdcTransferBankField));
        }
        else
        {
            memset(ptrCfd_pTransferBank, 0, sizeof(CThostFtdcTransferBankField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryTransferBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTransferBank = Napi::Object::New(env);
            js_pTransferBank.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferBank->BankID, strlen(ptrCfd_pTransferBank->BankID)) );
            js_pTransferBank.Set("BankBrchID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferBank->BankBrchID, strlen(ptrCfd_pTransferBank->BankBrchID)) );
            js_pTransferBank.Set("BankName", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferBank->BankName, strlen(ptrCfd_pTransferBank->BankName)) );
            js_pTransferBank.Set("IsActive", ptrCfd_pTransferBank->IsActive);
            js_event_data.Set("pTransferBank", js_pTransferBank);
            delete ptrCfd_pTransferBank;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField * pInvestorPositionDetail, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInvestorPositionDetailField *ptrCfd_pInvestorPositionDetail = new CThostFtdcInvestorPositionDetailField();
        if(pInvestorPositionDetail)
        {
            memcpy(ptrCfd_pInvestorPositionDetail, pInvestorPositionDetail, sizeof(CThostFtdcInvestorPositionDetailField));
        }
        else
        {
            memset(ptrCfd_pInvestorPositionDetail, 0, sizeof(CThostFtdcInvestorPositionDetailField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInvestorPositionDetail");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInvestorPositionDetail = Napi::Object::New(env);
            js_pInvestorPositionDetail.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->reserve1, strlen(ptrCfd_pInvestorPositionDetail->reserve1)) );
            js_pInvestorPositionDetail.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->BrokerID, strlen(ptrCfd_pInvestorPositionDetail->BrokerID)) );
            js_pInvestorPositionDetail.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->InvestorID, strlen(ptrCfd_pInvestorPositionDetail->InvestorID)) );
            js_pInvestorPositionDetail.Set("HedgeFlag", string(1u, ptrCfd_pInvestorPositionDetail->HedgeFlag).c_str());
            js_pInvestorPositionDetail.Set("Direction", string(1u, ptrCfd_pInvestorPositionDetail->Direction).c_str());
            js_pInvestorPositionDetail.Set("OpenDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->OpenDate, strlen(ptrCfd_pInvestorPositionDetail->OpenDate)) );
            js_pInvestorPositionDetail.Set("TradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->TradeID, strlen(ptrCfd_pInvestorPositionDetail->TradeID)) );
            js_pInvestorPositionDetail.Set("Volume", ptrCfd_pInvestorPositionDetail->Volume);
            js_pInvestorPositionDetail.Set("OpenPrice", ptrCfd_pInvestorPositionDetail->OpenPrice);
            js_pInvestorPositionDetail.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->TradingDay, strlen(ptrCfd_pInvestorPositionDetail->TradingDay)) );
            js_pInvestorPositionDetail.Set("SettlementID", ptrCfd_pInvestorPositionDetail->SettlementID);
            js_pInvestorPositionDetail.Set("TradeType", string(1u, ptrCfd_pInvestorPositionDetail->TradeType).c_str());
            js_pInvestorPositionDetail.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->reserve2, strlen(ptrCfd_pInvestorPositionDetail->reserve2)) );
            js_pInvestorPositionDetail.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->ExchangeID, strlen(ptrCfd_pInvestorPositionDetail->ExchangeID)) );
            js_pInvestorPositionDetail.Set("CloseProfitByDate", ptrCfd_pInvestorPositionDetail->CloseProfitByDate);
            js_pInvestorPositionDetail.Set("CloseProfitByTrade", ptrCfd_pInvestorPositionDetail->CloseProfitByTrade);
            js_pInvestorPositionDetail.Set("PositionProfitByDate", ptrCfd_pInvestorPositionDetail->PositionProfitByDate);
            js_pInvestorPositionDetail.Set("PositionProfitByTrade", ptrCfd_pInvestorPositionDetail->PositionProfitByTrade);
            js_pInvestorPositionDetail.Set("Margin", ptrCfd_pInvestorPositionDetail->Margin);
            js_pInvestorPositionDetail.Set("ExchMargin", ptrCfd_pInvestorPositionDetail->ExchMargin);
            js_pInvestorPositionDetail.Set("MarginRateByMoney", ptrCfd_pInvestorPositionDetail->MarginRateByMoney);
            js_pInvestorPositionDetail.Set("MarginRateByVolume", ptrCfd_pInvestorPositionDetail->MarginRateByVolume);
            js_pInvestorPositionDetail.Set("LastSettlementPrice", ptrCfd_pInvestorPositionDetail->LastSettlementPrice);
            js_pInvestorPositionDetail.Set("SettlementPrice", ptrCfd_pInvestorPositionDetail->SettlementPrice);
            js_pInvestorPositionDetail.Set("CloseVolume", ptrCfd_pInvestorPositionDetail->CloseVolume);
            js_pInvestorPositionDetail.Set("CloseAmount", ptrCfd_pInvestorPositionDetail->CloseAmount);
            js_pInvestorPositionDetail.Set("TimeFirstVolume", ptrCfd_pInvestorPositionDetail->TimeFirstVolume);
            js_pInvestorPositionDetail.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->InvestUnitID, strlen(ptrCfd_pInvestorPositionDetail->InvestUnitID)) );
            js_pInvestorPositionDetail.Set("SpecPosiType", string(1u, ptrCfd_pInvestorPositionDetail->SpecPosiType).c_str());
            js_pInvestorPositionDetail.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->InstrumentID, strlen(ptrCfd_pInvestorPositionDetail->InstrumentID)) );
            js_pInvestorPositionDetail.Set("CombInstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionDetail->CombInstrumentID, strlen(ptrCfd_pInvestorPositionDetail->CombInstrumentID)) );
            js_event_data.Set("pInvestorPositionDetail", js_pInvestorPositionDetail);
            delete ptrCfd_pInvestorPositionDetail;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryNotice(CThostFtdcNoticeField * pNotice, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcNoticeField *ptrCfd_pNotice = new CThostFtdcNoticeField();
        if(pNotice)
        {
            memcpy(ptrCfd_pNotice, pNotice, sizeof(CThostFtdcNoticeField));
        }
        else
        {
            memset(ptrCfd_pNotice, 0, sizeof(CThostFtdcNoticeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryNotice");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pNotice = Napi::Object::New(env);
            js_pNotice.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotice->BrokerID, strlen(ptrCfd_pNotice->BrokerID)) );
            js_pNotice.Set("Content", Napi::Buffer<char>::Copy(env, ptrCfd_pNotice->Content, strlen(ptrCfd_pNotice->Content)) );
            js_pNotice.Set("SequenceLabel", Napi::Buffer<char>::Copy(env, ptrCfd_pNotice->SequenceLabel, strlen(ptrCfd_pNotice->SequenceLabel)) );
            js_event_data.Set("pNotice", js_pNotice);
            delete ptrCfd_pNotice;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSettlementInfoConfirmField *ptrCfd_pSettlementInfoConfirm = new CThostFtdcSettlementInfoConfirmField();
        if(pSettlementInfoConfirm)
        {
            memcpy(ptrCfd_pSettlementInfoConfirm, pSettlementInfoConfirm, sizeof(CThostFtdcSettlementInfoConfirmField));
        }
        else
        {
            memset(ptrCfd_pSettlementInfoConfirm, 0, sizeof(CThostFtdcSettlementInfoConfirmField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQrySettlementInfoConfirm");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSettlementInfoConfirm = Napi::Object::New(env);
            js_pSettlementInfoConfirm.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->BrokerID, strlen(ptrCfd_pSettlementInfoConfirm->BrokerID)) );
            js_pSettlementInfoConfirm.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->InvestorID, strlen(ptrCfd_pSettlementInfoConfirm->InvestorID)) );
            js_pSettlementInfoConfirm.Set("ConfirmDate", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->ConfirmDate, strlen(ptrCfd_pSettlementInfoConfirm->ConfirmDate)) );
            js_pSettlementInfoConfirm.Set("ConfirmTime", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->ConfirmTime, strlen(ptrCfd_pSettlementInfoConfirm->ConfirmTime)) );
            js_pSettlementInfoConfirm.Set("SettlementID", ptrCfd_pSettlementInfoConfirm->SettlementID);
            js_pSettlementInfoConfirm.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->AccountID, strlen(ptrCfd_pSettlementInfoConfirm->AccountID)) );
            js_pSettlementInfoConfirm.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pSettlementInfoConfirm->CurrencyID, strlen(ptrCfd_pSettlementInfoConfirm->CurrencyID)) );
            js_event_data.Set("pSettlementInfoConfirm", js_pSettlementInfoConfirm);
            delete ptrCfd_pSettlementInfoConfirm;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField * pInvestorPositionCombineDetail, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInvestorPositionCombineDetailField *ptrCfd_pInvestorPositionCombineDetail = new CThostFtdcInvestorPositionCombineDetailField();
        if(pInvestorPositionCombineDetail)
        {
            memcpy(ptrCfd_pInvestorPositionCombineDetail, pInvestorPositionCombineDetail, sizeof(CThostFtdcInvestorPositionCombineDetailField));
        }
        else
        {
            memset(ptrCfd_pInvestorPositionCombineDetail, 0, sizeof(CThostFtdcInvestorPositionCombineDetailField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInvestorPositionCombineDetail");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInvestorPositionCombineDetail = Napi::Object::New(env);
            js_pInvestorPositionCombineDetail.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->TradingDay, strlen(ptrCfd_pInvestorPositionCombineDetail->TradingDay)) );
            js_pInvestorPositionCombineDetail.Set("OpenDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->OpenDate, strlen(ptrCfd_pInvestorPositionCombineDetail->OpenDate)) );
            js_pInvestorPositionCombineDetail.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->ExchangeID, strlen(ptrCfd_pInvestorPositionCombineDetail->ExchangeID)) );
            js_pInvestorPositionCombineDetail.Set("SettlementID", ptrCfd_pInvestorPositionCombineDetail->SettlementID);
            js_pInvestorPositionCombineDetail.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->BrokerID, strlen(ptrCfd_pInvestorPositionCombineDetail->BrokerID)) );
            js_pInvestorPositionCombineDetail.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->InvestorID, strlen(ptrCfd_pInvestorPositionCombineDetail->InvestorID)) );
            js_pInvestorPositionCombineDetail.Set("ComTradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->ComTradeID, strlen(ptrCfd_pInvestorPositionCombineDetail->ComTradeID)) );
            js_pInvestorPositionCombineDetail.Set("TradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->TradeID, strlen(ptrCfd_pInvestorPositionCombineDetail->TradeID)) );
            js_pInvestorPositionCombineDetail.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->reserve1, strlen(ptrCfd_pInvestorPositionCombineDetail->reserve1)) );
            js_pInvestorPositionCombineDetail.Set("HedgeFlag", string(1u, ptrCfd_pInvestorPositionCombineDetail->HedgeFlag).c_str());
            js_pInvestorPositionCombineDetail.Set("Direction", string(1u, ptrCfd_pInvestorPositionCombineDetail->Direction).c_str());
            js_pInvestorPositionCombineDetail.Set("TotalAmt", ptrCfd_pInvestorPositionCombineDetail->TotalAmt);
            js_pInvestorPositionCombineDetail.Set("Margin", ptrCfd_pInvestorPositionCombineDetail->Margin);
            js_pInvestorPositionCombineDetail.Set("ExchMargin", ptrCfd_pInvestorPositionCombineDetail->ExchMargin);
            js_pInvestorPositionCombineDetail.Set("MarginRateByMoney", ptrCfd_pInvestorPositionCombineDetail->MarginRateByMoney);
            js_pInvestorPositionCombineDetail.Set("MarginRateByVolume", ptrCfd_pInvestorPositionCombineDetail->MarginRateByVolume);
            js_pInvestorPositionCombineDetail.Set("LegID", ptrCfd_pInvestorPositionCombineDetail->LegID);
            js_pInvestorPositionCombineDetail.Set("LegMultiple", ptrCfd_pInvestorPositionCombineDetail->LegMultiple);
            js_pInvestorPositionCombineDetail.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->reserve2, strlen(ptrCfd_pInvestorPositionCombineDetail->reserve2)) );
            js_pInvestorPositionCombineDetail.Set("TradeGroupID", ptrCfd_pInvestorPositionCombineDetail->TradeGroupID);
            js_pInvestorPositionCombineDetail.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->InvestUnitID, strlen(ptrCfd_pInvestorPositionCombineDetail->InvestUnitID)) );
            js_pInvestorPositionCombineDetail.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->InstrumentID, strlen(ptrCfd_pInvestorPositionCombineDetail->InstrumentID)) );
            js_pInvestorPositionCombineDetail.Set("CombInstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorPositionCombineDetail->CombInstrumentID, strlen(ptrCfd_pInvestorPositionCombineDetail->CombInstrumentID)) );
            js_event_data.Set("pInvestorPositionCombineDetail", js_pInvestorPositionCombineDetail);
            delete ptrCfd_pInvestorPositionCombineDetail;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField * pCFMMCTradingAccountKey, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcCFMMCTradingAccountKeyField *ptrCfd_pCFMMCTradingAccountKey = new CThostFtdcCFMMCTradingAccountKeyField();
        if(pCFMMCTradingAccountKey)
        {
            memcpy(ptrCfd_pCFMMCTradingAccountKey, pCFMMCTradingAccountKey, sizeof(CThostFtdcCFMMCTradingAccountKeyField));
        }
        else
        {
            memset(ptrCfd_pCFMMCTradingAccountKey, 0, sizeof(CThostFtdcCFMMCTradingAccountKeyField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryCFMMCTradingAccountKey");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCFMMCTradingAccountKey = Napi::Object::New(env);
            js_pCFMMCTradingAccountKey.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountKey->BrokerID, strlen(ptrCfd_pCFMMCTradingAccountKey->BrokerID)) );
            js_pCFMMCTradingAccountKey.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountKey->ParticipantID, strlen(ptrCfd_pCFMMCTradingAccountKey->ParticipantID)) );
            js_pCFMMCTradingAccountKey.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountKey->AccountID, strlen(ptrCfd_pCFMMCTradingAccountKey->AccountID)) );
            js_pCFMMCTradingAccountKey.Set("KeyID", ptrCfd_pCFMMCTradingAccountKey->KeyID);
            js_pCFMMCTradingAccountKey.Set("CurrentKey", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountKey->CurrentKey, strlen(ptrCfd_pCFMMCTradingAccountKey->CurrentKey)) );
            js_event_data.Set("pCFMMCTradingAccountKey", js_pCFMMCTradingAccountKey);
            delete ptrCfd_pCFMMCTradingAccountKey;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField * pEWarrantOffset, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcEWarrantOffsetField *ptrCfd_pEWarrantOffset = new CThostFtdcEWarrantOffsetField();
        if(pEWarrantOffset)
        {
            memcpy(ptrCfd_pEWarrantOffset, pEWarrantOffset, sizeof(CThostFtdcEWarrantOffsetField));
        }
        else
        {
            memset(ptrCfd_pEWarrantOffset, 0, sizeof(CThostFtdcEWarrantOffsetField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryEWarrantOffset");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pEWarrantOffset = Napi::Object::New(env);
            js_pEWarrantOffset.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->TradingDay, strlen(ptrCfd_pEWarrantOffset->TradingDay)) );
            js_pEWarrantOffset.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->BrokerID, strlen(ptrCfd_pEWarrantOffset->BrokerID)) );
            js_pEWarrantOffset.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->InvestorID, strlen(ptrCfd_pEWarrantOffset->InvestorID)) );
            js_pEWarrantOffset.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->ExchangeID, strlen(ptrCfd_pEWarrantOffset->ExchangeID)) );
            js_pEWarrantOffset.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->reserve1, strlen(ptrCfd_pEWarrantOffset->reserve1)) );
            js_pEWarrantOffset.Set("Direction", string(1u, ptrCfd_pEWarrantOffset->Direction).c_str());
            js_pEWarrantOffset.Set("HedgeFlag", string(1u, ptrCfd_pEWarrantOffset->HedgeFlag).c_str());
            js_pEWarrantOffset.Set("Volume", ptrCfd_pEWarrantOffset->Volume);
            js_pEWarrantOffset.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->InvestUnitID, strlen(ptrCfd_pEWarrantOffset->InvestUnitID)) );
            js_pEWarrantOffset.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pEWarrantOffset->InstrumentID, strlen(ptrCfd_pEWarrantOffset->InstrumentID)) );
            js_event_data.Set("pEWarrantOffset", js_pEWarrantOffset);
            delete ptrCfd_pEWarrantOffset;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField * pInvestorProductGroupMargin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInvestorProductGroupMarginField *ptrCfd_pInvestorProductGroupMargin = new CThostFtdcInvestorProductGroupMarginField();
        if(pInvestorProductGroupMargin)
        {
            memcpy(ptrCfd_pInvestorProductGroupMargin, pInvestorProductGroupMargin, sizeof(CThostFtdcInvestorProductGroupMarginField));
        }
        else
        {
            memset(ptrCfd_pInvestorProductGroupMargin, 0, sizeof(CThostFtdcInvestorProductGroupMarginField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInvestorProductGroupMargin");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInvestorProductGroupMargin = Napi::Object::New(env);
            js_pInvestorProductGroupMargin.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->reserve1, strlen(ptrCfd_pInvestorProductGroupMargin->reserve1)) );
            js_pInvestorProductGroupMargin.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->BrokerID, strlen(ptrCfd_pInvestorProductGroupMargin->BrokerID)) );
            js_pInvestorProductGroupMargin.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->InvestorID, strlen(ptrCfd_pInvestorProductGroupMargin->InvestorID)) );
            js_pInvestorProductGroupMargin.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->TradingDay, strlen(ptrCfd_pInvestorProductGroupMargin->TradingDay)) );
            js_pInvestorProductGroupMargin.Set("SettlementID", ptrCfd_pInvestorProductGroupMargin->SettlementID);
            js_pInvestorProductGroupMargin.Set("FrozenMargin", ptrCfd_pInvestorProductGroupMargin->FrozenMargin);
            js_pInvestorProductGroupMargin.Set("LongFrozenMargin", ptrCfd_pInvestorProductGroupMargin->LongFrozenMargin);
            js_pInvestorProductGroupMargin.Set("ShortFrozenMargin", ptrCfd_pInvestorProductGroupMargin->ShortFrozenMargin);
            js_pInvestorProductGroupMargin.Set("UseMargin", ptrCfd_pInvestorProductGroupMargin->UseMargin);
            js_pInvestorProductGroupMargin.Set("LongUseMargin", ptrCfd_pInvestorProductGroupMargin->LongUseMargin);
            js_pInvestorProductGroupMargin.Set("ShortUseMargin", ptrCfd_pInvestorProductGroupMargin->ShortUseMargin);
            js_pInvestorProductGroupMargin.Set("ExchMargin", ptrCfd_pInvestorProductGroupMargin->ExchMargin);
            js_pInvestorProductGroupMargin.Set("LongExchMargin", ptrCfd_pInvestorProductGroupMargin->LongExchMargin);
            js_pInvestorProductGroupMargin.Set("ShortExchMargin", ptrCfd_pInvestorProductGroupMargin->ShortExchMargin);
            js_pInvestorProductGroupMargin.Set("CloseProfit", ptrCfd_pInvestorProductGroupMargin->CloseProfit);
            js_pInvestorProductGroupMargin.Set("FrozenCommission", ptrCfd_pInvestorProductGroupMargin->FrozenCommission);
            js_pInvestorProductGroupMargin.Set("Commission", ptrCfd_pInvestorProductGroupMargin->Commission);
            js_pInvestorProductGroupMargin.Set("FrozenCash", ptrCfd_pInvestorProductGroupMargin->FrozenCash);
            js_pInvestorProductGroupMargin.Set("CashIn", ptrCfd_pInvestorProductGroupMargin->CashIn);
            js_pInvestorProductGroupMargin.Set("PositionProfit", ptrCfd_pInvestorProductGroupMargin->PositionProfit);
            js_pInvestorProductGroupMargin.Set("OffsetAmount", ptrCfd_pInvestorProductGroupMargin->OffsetAmount);
            js_pInvestorProductGroupMargin.Set("LongOffsetAmount", ptrCfd_pInvestorProductGroupMargin->LongOffsetAmount);
            js_pInvestorProductGroupMargin.Set("ShortOffsetAmount", ptrCfd_pInvestorProductGroupMargin->ShortOffsetAmount);
            js_pInvestorProductGroupMargin.Set("ExchOffsetAmount", ptrCfd_pInvestorProductGroupMargin->ExchOffsetAmount);
            js_pInvestorProductGroupMargin.Set("LongExchOffsetAmount", ptrCfd_pInvestorProductGroupMargin->LongExchOffsetAmount);
            js_pInvestorProductGroupMargin.Set("ShortExchOffsetAmount", ptrCfd_pInvestorProductGroupMargin->ShortExchOffsetAmount);
            js_pInvestorProductGroupMargin.Set("HedgeFlag", string(1u, ptrCfd_pInvestorProductGroupMargin->HedgeFlag).c_str());
            js_pInvestorProductGroupMargin.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->ExchangeID, strlen(ptrCfd_pInvestorProductGroupMargin->ExchangeID)) );
            js_pInvestorProductGroupMargin.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->InvestUnitID, strlen(ptrCfd_pInvestorProductGroupMargin->InvestUnitID)) );
            js_pInvestorProductGroupMargin.Set("ProductGroupID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestorProductGroupMargin->ProductGroupID, strlen(ptrCfd_pInvestorProductGroupMargin->ProductGroupID)) );
            js_event_data.Set("pInvestorProductGroupMargin", js_pInvestorProductGroupMargin);
            delete ptrCfd_pInvestorProductGroupMargin;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField * pExchangeMarginRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcExchangeMarginRateField *ptrCfd_pExchangeMarginRate = new CThostFtdcExchangeMarginRateField();
        if(pExchangeMarginRate)
        {
            memcpy(ptrCfd_pExchangeMarginRate, pExchangeMarginRate, sizeof(CThostFtdcExchangeMarginRateField));
        }
        else
        {
            memset(ptrCfd_pExchangeMarginRate, 0, sizeof(CThostFtdcExchangeMarginRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryExchangeMarginRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExchangeMarginRate = Napi::Object::New(env);
            js_pExchangeMarginRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRate->BrokerID, strlen(ptrCfd_pExchangeMarginRate->BrokerID)) );
            js_pExchangeMarginRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRate->reserve1, strlen(ptrCfd_pExchangeMarginRate->reserve1)) );
            js_pExchangeMarginRate.Set("HedgeFlag", string(1u, ptrCfd_pExchangeMarginRate->HedgeFlag).c_str());
            js_pExchangeMarginRate.Set("LongMarginRatioByMoney", ptrCfd_pExchangeMarginRate->LongMarginRatioByMoney);
            js_pExchangeMarginRate.Set("LongMarginRatioByVolume", ptrCfd_pExchangeMarginRate->LongMarginRatioByVolume);
            js_pExchangeMarginRate.Set("ShortMarginRatioByMoney", ptrCfd_pExchangeMarginRate->ShortMarginRatioByMoney);
            js_pExchangeMarginRate.Set("ShortMarginRatioByVolume", ptrCfd_pExchangeMarginRate->ShortMarginRatioByVolume);
            js_pExchangeMarginRate.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRate->ExchangeID, strlen(ptrCfd_pExchangeMarginRate->ExchangeID)) );
            js_pExchangeMarginRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRate->InstrumentID, strlen(ptrCfd_pExchangeMarginRate->InstrumentID)) );
            js_event_data.Set("pExchangeMarginRate", js_pExchangeMarginRate);
            delete ptrCfd_pExchangeMarginRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField * pExchangeMarginRateAdjust, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcExchangeMarginRateAdjustField *ptrCfd_pExchangeMarginRateAdjust = new CThostFtdcExchangeMarginRateAdjustField();
        if(pExchangeMarginRateAdjust)
        {
            memcpy(ptrCfd_pExchangeMarginRateAdjust, pExchangeMarginRateAdjust, sizeof(CThostFtdcExchangeMarginRateAdjustField));
        }
        else
        {
            memset(ptrCfd_pExchangeMarginRateAdjust, 0, sizeof(CThostFtdcExchangeMarginRateAdjustField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryExchangeMarginRateAdjust");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExchangeMarginRateAdjust = Napi::Object::New(env);
            js_pExchangeMarginRateAdjust.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRateAdjust->BrokerID, strlen(ptrCfd_pExchangeMarginRateAdjust->BrokerID)) );
            js_pExchangeMarginRateAdjust.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRateAdjust->reserve1, strlen(ptrCfd_pExchangeMarginRateAdjust->reserve1)) );
            js_pExchangeMarginRateAdjust.Set("HedgeFlag", string(1u, ptrCfd_pExchangeMarginRateAdjust->HedgeFlag).c_str());
            js_pExchangeMarginRateAdjust.Set("LongMarginRatioByMoney", ptrCfd_pExchangeMarginRateAdjust->LongMarginRatioByMoney);
            js_pExchangeMarginRateAdjust.Set("LongMarginRatioByVolume", ptrCfd_pExchangeMarginRateAdjust->LongMarginRatioByVolume);
            js_pExchangeMarginRateAdjust.Set("ShortMarginRatioByMoney", ptrCfd_pExchangeMarginRateAdjust->ShortMarginRatioByMoney);
            js_pExchangeMarginRateAdjust.Set("ShortMarginRatioByVolume", ptrCfd_pExchangeMarginRateAdjust->ShortMarginRatioByVolume);
            js_pExchangeMarginRateAdjust.Set("ExchLongMarginRatioByMoney", ptrCfd_pExchangeMarginRateAdjust->ExchLongMarginRatioByMoney);
            js_pExchangeMarginRateAdjust.Set("ExchLongMarginRatioByVolume", ptrCfd_pExchangeMarginRateAdjust->ExchLongMarginRatioByVolume);
            js_pExchangeMarginRateAdjust.Set("ExchShortMarginRatioByMoney", ptrCfd_pExchangeMarginRateAdjust->ExchShortMarginRatioByMoney);
            js_pExchangeMarginRateAdjust.Set("ExchShortMarginRatioByVolume", ptrCfd_pExchangeMarginRateAdjust->ExchShortMarginRatioByVolume);
            js_pExchangeMarginRateAdjust.Set("NoLongMarginRatioByMoney", ptrCfd_pExchangeMarginRateAdjust->NoLongMarginRatioByMoney);
            js_pExchangeMarginRateAdjust.Set("NoLongMarginRatioByVolume", ptrCfd_pExchangeMarginRateAdjust->NoLongMarginRatioByVolume);
            js_pExchangeMarginRateAdjust.Set("NoShortMarginRatioByMoney", ptrCfd_pExchangeMarginRateAdjust->NoShortMarginRatioByMoney);
            js_pExchangeMarginRateAdjust.Set("NoShortMarginRatioByVolume", ptrCfd_pExchangeMarginRateAdjust->NoShortMarginRatioByVolume);
            js_pExchangeMarginRateAdjust.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeMarginRateAdjust->InstrumentID, strlen(ptrCfd_pExchangeMarginRateAdjust->InstrumentID)) );
            js_event_data.Set("pExchangeMarginRateAdjust", js_pExchangeMarginRateAdjust);
            delete ptrCfd_pExchangeMarginRateAdjust;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryExchangeRate(CThostFtdcExchangeRateField * pExchangeRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcExchangeRateField *ptrCfd_pExchangeRate = new CThostFtdcExchangeRateField();
        if(pExchangeRate)
        {
            memcpy(ptrCfd_pExchangeRate, pExchangeRate, sizeof(CThostFtdcExchangeRateField));
        }
        else
        {
            memset(ptrCfd_pExchangeRate, 0, sizeof(CThostFtdcExchangeRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryExchangeRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExchangeRate = Napi::Object::New(env);
            js_pExchangeRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeRate->BrokerID, strlen(ptrCfd_pExchangeRate->BrokerID)) );
            js_pExchangeRate.Set("FromCurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeRate->FromCurrencyID, strlen(ptrCfd_pExchangeRate->FromCurrencyID)) );
            js_pExchangeRate.Set("FromCurrencyUnit", ptrCfd_pExchangeRate->FromCurrencyUnit);
            js_pExchangeRate.Set("ToCurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pExchangeRate->ToCurrencyID, strlen(ptrCfd_pExchangeRate->ToCurrencyID)) );
            js_pExchangeRate.Set("ExchangeRate", ptrCfd_pExchangeRate->ExchangeRate);
            js_event_data.Set("pExchangeRate", js_pExchangeRate);
            delete ptrCfd_pExchangeRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField * pSecAgentACIDMap, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSecAgentACIDMapField *ptrCfd_pSecAgentACIDMap = new CThostFtdcSecAgentACIDMapField();
        if(pSecAgentACIDMap)
        {
            memcpy(ptrCfd_pSecAgentACIDMap, pSecAgentACIDMap, sizeof(CThostFtdcSecAgentACIDMapField));
        }
        else
        {
            memset(ptrCfd_pSecAgentACIDMap, 0, sizeof(CThostFtdcSecAgentACIDMapField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQrySecAgentACIDMap");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSecAgentACIDMap = Napi::Object::New(env);
            js_pSecAgentACIDMap.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentACIDMap->BrokerID, strlen(ptrCfd_pSecAgentACIDMap->BrokerID)) );
            js_pSecAgentACIDMap.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentACIDMap->UserID, strlen(ptrCfd_pSecAgentACIDMap->UserID)) );
            js_pSecAgentACIDMap.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentACIDMap->AccountID, strlen(ptrCfd_pSecAgentACIDMap->AccountID)) );
            js_pSecAgentACIDMap.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentACIDMap->CurrencyID, strlen(ptrCfd_pSecAgentACIDMap->CurrencyID)) );
            js_pSecAgentACIDMap.Set("BrokerSecAgentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentACIDMap->BrokerSecAgentID, strlen(ptrCfd_pSecAgentACIDMap->BrokerSecAgentID)) );
            js_event_data.Set("pSecAgentACIDMap", js_pSecAgentACIDMap);
            delete ptrCfd_pSecAgentACIDMap;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryProductExchRate(CThostFtdcProductExchRateField * pProductExchRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcProductExchRateField *ptrCfd_pProductExchRate = new CThostFtdcProductExchRateField();
        if(pProductExchRate)
        {
            memcpy(ptrCfd_pProductExchRate, pProductExchRate, sizeof(CThostFtdcProductExchRateField));
        }
        else
        {
            memset(ptrCfd_pProductExchRate, 0, sizeof(CThostFtdcProductExchRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryProductExchRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pProductExchRate = Napi::Object::New(env);
            js_pProductExchRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pProductExchRate->reserve1, strlen(ptrCfd_pProductExchRate->reserve1)) );
            js_pProductExchRate.Set("QuoteCurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pProductExchRate->QuoteCurrencyID, strlen(ptrCfd_pProductExchRate->QuoteCurrencyID)) );
            js_pProductExchRate.Set("ExchangeRate", ptrCfd_pProductExchRate->ExchangeRate);
            js_pProductExchRate.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pProductExchRate->ExchangeID, strlen(ptrCfd_pProductExchRate->ExchangeID)) );
            js_pProductExchRate.Set("ProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pProductExchRate->ProductID, strlen(ptrCfd_pProductExchRate->ProductID)) );
            js_event_data.Set("pProductExchRate", js_pProductExchRate);
            delete ptrCfd_pProductExchRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryProductGroup(CThostFtdcProductGroupField * pProductGroup, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcProductGroupField *ptrCfd_pProductGroup = new CThostFtdcProductGroupField();
        if(pProductGroup)
        {
            memcpy(ptrCfd_pProductGroup, pProductGroup, sizeof(CThostFtdcProductGroupField));
        }
        else
        {
            memset(ptrCfd_pProductGroup, 0, sizeof(CThostFtdcProductGroupField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryProductGroup");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pProductGroup = Napi::Object::New(env);
            js_pProductGroup.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pProductGroup->reserve1, strlen(ptrCfd_pProductGroup->reserve1)) );
            js_pProductGroup.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pProductGroup->ExchangeID, strlen(ptrCfd_pProductGroup->ExchangeID)) );
            js_pProductGroup.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pProductGroup->reserve2, strlen(ptrCfd_pProductGroup->reserve2)) );
            js_pProductGroup.Set("ProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pProductGroup->ProductID, strlen(ptrCfd_pProductGroup->ProductID)) );
            js_pProductGroup.Set("ProductGroupID", Napi::Buffer<char>::Copy(env, ptrCfd_pProductGroup->ProductGroupID, strlen(ptrCfd_pProductGroup->ProductGroupID)) );
            js_event_data.Set("pProductGroup", js_pProductGroup);
            delete ptrCfd_pProductGroup;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField * pMMInstrumentCommissionRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcMMInstrumentCommissionRateField *ptrCfd_pMMInstrumentCommissionRate = new CThostFtdcMMInstrumentCommissionRateField();
        if(pMMInstrumentCommissionRate)
        {
            memcpy(ptrCfd_pMMInstrumentCommissionRate, pMMInstrumentCommissionRate, sizeof(CThostFtdcMMInstrumentCommissionRateField));
        }
        else
        {
            memset(ptrCfd_pMMInstrumentCommissionRate, 0, sizeof(CThostFtdcMMInstrumentCommissionRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryMMInstrumentCommissionRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pMMInstrumentCommissionRate = Napi::Object::New(env);
            js_pMMInstrumentCommissionRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pMMInstrumentCommissionRate->reserve1, strlen(ptrCfd_pMMInstrumentCommissionRate->reserve1)) );
            js_pMMInstrumentCommissionRate.Set("InvestorRange", string(1u, ptrCfd_pMMInstrumentCommissionRate->InvestorRange).c_str());
            js_pMMInstrumentCommissionRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pMMInstrumentCommissionRate->BrokerID, strlen(ptrCfd_pMMInstrumentCommissionRate->BrokerID)) );
            js_pMMInstrumentCommissionRate.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pMMInstrumentCommissionRate->InvestorID, strlen(ptrCfd_pMMInstrumentCommissionRate->InvestorID)) );
            js_pMMInstrumentCommissionRate.Set("OpenRatioByMoney", ptrCfd_pMMInstrumentCommissionRate->OpenRatioByMoney);
            js_pMMInstrumentCommissionRate.Set("OpenRatioByVolume", ptrCfd_pMMInstrumentCommissionRate->OpenRatioByVolume);
            js_pMMInstrumentCommissionRate.Set("CloseRatioByMoney", ptrCfd_pMMInstrumentCommissionRate->CloseRatioByMoney);
            js_pMMInstrumentCommissionRate.Set("CloseRatioByVolume", ptrCfd_pMMInstrumentCommissionRate->CloseRatioByVolume);
            js_pMMInstrumentCommissionRate.Set("CloseTodayRatioByMoney", ptrCfd_pMMInstrumentCommissionRate->CloseTodayRatioByMoney);
            js_pMMInstrumentCommissionRate.Set("CloseTodayRatioByVolume", ptrCfd_pMMInstrumentCommissionRate->CloseTodayRatioByVolume);
            js_pMMInstrumentCommissionRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pMMInstrumentCommissionRate->InstrumentID, strlen(ptrCfd_pMMInstrumentCommissionRate->InstrumentID)) );
            js_event_data.Set("pMMInstrumentCommissionRate", js_pMMInstrumentCommissionRate);
            delete ptrCfd_pMMInstrumentCommissionRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField * pMMOptionInstrCommRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcMMOptionInstrCommRateField *ptrCfd_pMMOptionInstrCommRate = new CThostFtdcMMOptionInstrCommRateField();
        if(pMMOptionInstrCommRate)
        {
            memcpy(ptrCfd_pMMOptionInstrCommRate, pMMOptionInstrCommRate, sizeof(CThostFtdcMMOptionInstrCommRateField));
        }
        else
        {
            memset(ptrCfd_pMMOptionInstrCommRate, 0, sizeof(CThostFtdcMMOptionInstrCommRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryMMOptionInstrCommRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pMMOptionInstrCommRate = Napi::Object::New(env);
            js_pMMOptionInstrCommRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pMMOptionInstrCommRate->reserve1, strlen(ptrCfd_pMMOptionInstrCommRate->reserve1)) );
            js_pMMOptionInstrCommRate.Set("InvestorRange", string(1u, ptrCfd_pMMOptionInstrCommRate->InvestorRange).c_str());
            js_pMMOptionInstrCommRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pMMOptionInstrCommRate->BrokerID, strlen(ptrCfd_pMMOptionInstrCommRate->BrokerID)) );
            js_pMMOptionInstrCommRate.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pMMOptionInstrCommRate->InvestorID, strlen(ptrCfd_pMMOptionInstrCommRate->InvestorID)) );
            js_pMMOptionInstrCommRate.Set("OpenRatioByMoney", ptrCfd_pMMOptionInstrCommRate->OpenRatioByMoney);
            js_pMMOptionInstrCommRate.Set("OpenRatioByVolume", ptrCfd_pMMOptionInstrCommRate->OpenRatioByVolume);
            js_pMMOptionInstrCommRate.Set("CloseRatioByMoney", ptrCfd_pMMOptionInstrCommRate->CloseRatioByMoney);
            js_pMMOptionInstrCommRate.Set("CloseRatioByVolume", ptrCfd_pMMOptionInstrCommRate->CloseRatioByVolume);
            js_pMMOptionInstrCommRate.Set("CloseTodayRatioByMoney", ptrCfd_pMMOptionInstrCommRate->CloseTodayRatioByMoney);
            js_pMMOptionInstrCommRate.Set("CloseTodayRatioByVolume", ptrCfd_pMMOptionInstrCommRate->CloseTodayRatioByVolume);
            js_pMMOptionInstrCommRate.Set("StrikeRatioByMoney", ptrCfd_pMMOptionInstrCommRate->StrikeRatioByMoney);
            js_pMMOptionInstrCommRate.Set("StrikeRatioByVolume", ptrCfd_pMMOptionInstrCommRate->StrikeRatioByVolume);
            js_pMMOptionInstrCommRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pMMOptionInstrCommRate->InstrumentID, strlen(ptrCfd_pMMOptionInstrCommRate->InstrumentID)) );
            js_event_data.Set("pMMOptionInstrCommRate", js_pMMOptionInstrCommRate);
            delete ptrCfd_pMMOptionInstrCommRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField * pInstrumentOrderCommRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInstrumentOrderCommRateField *ptrCfd_pInstrumentOrderCommRate = new CThostFtdcInstrumentOrderCommRateField();
        if(pInstrumentOrderCommRate)
        {
            memcpy(ptrCfd_pInstrumentOrderCommRate, pInstrumentOrderCommRate, sizeof(CThostFtdcInstrumentOrderCommRateField));
        }
        else
        {
            memset(ptrCfd_pInstrumentOrderCommRate, 0, sizeof(CThostFtdcInstrumentOrderCommRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInstrumentOrderCommRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInstrumentOrderCommRate = Napi::Object::New(env);
            js_pInstrumentOrderCommRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentOrderCommRate->reserve1, strlen(ptrCfd_pInstrumentOrderCommRate->reserve1)) );
            js_pInstrumentOrderCommRate.Set("InvestorRange", string(1u, ptrCfd_pInstrumentOrderCommRate->InvestorRange).c_str());
            js_pInstrumentOrderCommRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentOrderCommRate->BrokerID, strlen(ptrCfd_pInstrumentOrderCommRate->BrokerID)) );
            js_pInstrumentOrderCommRate.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentOrderCommRate->InvestorID, strlen(ptrCfd_pInstrumentOrderCommRate->InvestorID)) );
            js_pInstrumentOrderCommRate.Set("HedgeFlag", string(1u, ptrCfd_pInstrumentOrderCommRate->HedgeFlag).c_str());
            js_pInstrumentOrderCommRate.Set("OrderCommByVolume", ptrCfd_pInstrumentOrderCommRate->OrderCommByVolume);
            js_pInstrumentOrderCommRate.Set("OrderActionCommByVolume", ptrCfd_pInstrumentOrderCommRate->OrderActionCommByVolume);
            js_pInstrumentOrderCommRate.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentOrderCommRate->ExchangeID, strlen(ptrCfd_pInstrumentOrderCommRate->ExchangeID)) );
            js_pInstrumentOrderCommRate.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentOrderCommRate->InvestUnitID, strlen(ptrCfd_pInstrumentOrderCommRate->InvestUnitID)) );
            js_pInstrumentOrderCommRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentOrderCommRate->InstrumentID, strlen(ptrCfd_pInstrumentOrderCommRate->InstrumentID)) );
            js_pInstrumentOrderCommRate.Set("OrderCommByTrade", ptrCfd_pInstrumentOrderCommRate->OrderCommByTrade);
            js_pInstrumentOrderCommRate.Set("OrderActionCommByTrade", ptrCfd_pInstrumentOrderCommRate->OrderActionCommByTrade);
            js_event_data.Set("pInstrumentOrderCommRate", js_pInstrumentOrderCommRate);
            delete ptrCfd_pInstrumentOrderCommRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField * pTradingAccount, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTradingAccountField *ptrCfd_pTradingAccount = new CThostFtdcTradingAccountField();
        if(pTradingAccount)
        {
            memcpy(ptrCfd_pTradingAccount, pTradingAccount, sizeof(CThostFtdcTradingAccountField));
        }
        else
        {
            memset(ptrCfd_pTradingAccount, 0, sizeof(CThostFtdcTradingAccountField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQrySecAgentTradingAccount");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTradingAccount = Napi::Object::New(env);
            js_pTradingAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->BrokerID, strlen(ptrCfd_pTradingAccount->BrokerID)) );
            js_pTradingAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->AccountID, strlen(ptrCfd_pTradingAccount->AccountID)) );
            js_pTradingAccount.Set("PreMortgage", ptrCfd_pTradingAccount->PreMortgage);
            js_pTradingAccount.Set("PreCredit", ptrCfd_pTradingAccount->PreCredit);
            js_pTradingAccount.Set("PreDeposit", ptrCfd_pTradingAccount->PreDeposit);
            js_pTradingAccount.Set("PreBalance", ptrCfd_pTradingAccount->PreBalance);
            js_pTradingAccount.Set("PreMargin", ptrCfd_pTradingAccount->PreMargin);
            js_pTradingAccount.Set("InterestBase", ptrCfd_pTradingAccount->InterestBase);
            js_pTradingAccount.Set("Interest", ptrCfd_pTradingAccount->Interest);
            js_pTradingAccount.Set("Deposit", ptrCfd_pTradingAccount->Deposit);
            js_pTradingAccount.Set("Withdraw", ptrCfd_pTradingAccount->Withdraw);
            js_pTradingAccount.Set("FrozenMargin", ptrCfd_pTradingAccount->FrozenMargin);
            js_pTradingAccount.Set("FrozenCash", ptrCfd_pTradingAccount->FrozenCash);
            js_pTradingAccount.Set("FrozenCommission", ptrCfd_pTradingAccount->FrozenCommission);
            js_pTradingAccount.Set("CurrMargin", ptrCfd_pTradingAccount->CurrMargin);
            js_pTradingAccount.Set("CashIn", ptrCfd_pTradingAccount->CashIn);
            js_pTradingAccount.Set("Commission", ptrCfd_pTradingAccount->Commission);
            js_pTradingAccount.Set("CloseProfit", ptrCfd_pTradingAccount->CloseProfit);
            js_pTradingAccount.Set("PositionProfit", ptrCfd_pTradingAccount->PositionProfit);
            js_pTradingAccount.Set("Balance", ptrCfd_pTradingAccount->Balance);
            js_pTradingAccount.Set("Available", ptrCfd_pTradingAccount->Available);
            js_pTradingAccount.Set("WithdrawQuota", ptrCfd_pTradingAccount->WithdrawQuota);
            js_pTradingAccount.Set("Reserve", ptrCfd_pTradingAccount->Reserve);
            js_pTradingAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->TradingDay, strlen(ptrCfd_pTradingAccount->TradingDay)) );
            js_pTradingAccount.Set("SettlementID", ptrCfd_pTradingAccount->SettlementID);
            js_pTradingAccount.Set("Credit", ptrCfd_pTradingAccount->Credit);
            js_pTradingAccount.Set("Mortgage", ptrCfd_pTradingAccount->Mortgage);
            js_pTradingAccount.Set("ExchangeMargin", ptrCfd_pTradingAccount->ExchangeMargin);
            js_pTradingAccount.Set("DeliveryMargin", ptrCfd_pTradingAccount->DeliveryMargin);
            js_pTradingAccount.Set("ExchangeDeliveryMargin", ptrCfd_pTradingAccount->ExchangeDeliveryMargin);
            js_pTradingAccount.Set("ReserveBalance", ptrCfd_pTradingAccount->ReserveBalance);
            js_pTradingAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingAccount->CurrencyID, strlen(ptrCfd_pTradingAccount->CurrencyID)) );
            js_pTradingAccount.Set("PreFundMortgageIn", ptrCfd_pTradingAccount->PreFundMortgageIn);
            js_pTradingAccount.Set("PreFundMortgageOut", ptrCfd_pTradingAccount->PreFundMortgageOut);
            js_pTradingAccount.Set("FundMortgageIn", ptrCfd_pTradingAccount->FundMortgageIn);
            js_pTradingAccount.Set("FundMortgageOut", ptrCfd_pTradingAccount->FundMortgageOut);
            js_pTradingAccount.Set("FundMortgageAvailable", ptrCfd_pTradingAccount->FundMortgageAvailable);
            js_pTradingAccount.Set("MortgageableFund", ptrCfd_pTradingAccount->MortgageableFund);
            js_pTradingAccount.Set("SpecProductMargin", ptrCfd_pTradingAccount->SpecProductMargin);
            js_pTradingAccount.Set("SpecProductFrozenMargin", ptrCfd_pTradingAccount->SpecProductFrozenMargin);
            js_pTradingAccount.Set("SpecProductCommission", ptrCfd_pTradingAccount->SpecProductCommission);
            js_pTradingAccount.Set("SpecProductFrozenCommission", ptrCfd_pTradingAccount->SpecProductFrozenCommission);
            js_pTradingAccount.Set("SpecProductPositionProfit", ptrCfd_pTradingAccount->SpecProductPositionProfit);
            js_pTradingAccount.Set("SpecProductCloseProfit", ptrCfd_pTradingAccount->SpecProductCloseProfit);
            js_pTradingAccount.Set("SpecProductPositionProfitByAlg", ptrCfd_pTradingAccount->SpecProductPositionProfitByAlg);
            js_pTradingAccount.Set("SpecProductExchangeMargin", ptrCfd_pTradingAccount->SpecProductExchangeMargin);
            js_pTradingAccount.Set("BizType", string(1u, ptrCfd_pTradingAccount->BizType).c_str());
            js_pTradingAccount.Set("FrozenSwap", ptrCfd_pTradingAccount->FrozenSwap);
            js_pTradingAccount.Set("RemainSwap", ptrCfd_pTradingAccount->RemainSwap);
            js_event_data.Set("pTradingAccount", js_pTradingAccount);
            delete ptrCfd_pTradingAccount;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField * pSecAgentCheckMode, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSecAgentCheckModeField *ptrCfd_pSecAgentCheckMode = new CThostFtdcSecAgentCheckModeField();
        if(pSecAgentCheckMode)
        {
            memcpy(ptrCfd_pSecAgentCheckMode, pSecAgentCheckMode, sizeof(CThostFtdcSecAgentCheckModeField));
        }
        else
        {
            memset(ptrCfd_pSecAgentCheckMode, 0, sizeof(CThostFtdcSecAgentCheckModeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQrySecAgentCheckMode");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSecAgentCheckMode = Napi::Object::New(env);
            js_pSecAgentCheckMode.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentCheckMode->InvestorID, strlen(ptrCfd_pSecAgentCheckMode->InvestorID)) );
            js_pSecAgentCheckMode.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentCheckMode->BrokerID, strlen(ptrCfd_pSecAgentCheckMode->BrokerID)) );
            js_pSecAgentCheckMode.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentCheckMode->CurrencyID, strlen(ptrCfd_pSecAgentCheckMode->CurrencyID)) );
            js_pSecAgentCheckMode.Set("BrokerSecAgentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentCheckMode->BrokerSecAgentID, strlen(ptrCfd_pSecAgentCheckMode->BrokerSecAgentID)) );
            js_pSecAgentCheckMode.Set("CheckSelfAccount", ptrCfd_pSecAgentCheckMode->CheckSelfAccount);
            js_event_data.Set("pSecAgentCheckMode", js_pSecAgentCheckMode);
            delete ptrCfd_pSecAgentCheckMode;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField * pSecAgentTradeInfo, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSecAgentTradeInfoField *ptrCfd_pSecAgentTradeInfo = new CThostFtdcSecAgentTradeInfoField();
        if(pSecAgentTradeInfo)
        {
            memcpy(ptrCfd_pSecAgentTradeInfo, pSecAgentTradeInfo, sizeof(CThostFtdcSecAgentTradeInfoField));
        }
        else
        {
            memset(ptrCfd_pSecAgentTradeInfo, 0, sizeof(CThostFtdcSecAgentTradeInfoField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQrySecAgentTradeInfo");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSecAgentTradeInfo = Napi::Object::New(env);
            js_pSecAgentTradeInfo.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentTradeInfo->BrokerID, strlen(ptrCfd_pSecAgentTradeInfo->BrokerID)) );
            js_pSecAgentTradeInfo.Set("BrokerSecAgentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentTradeInfo->BrokerSecAgentID, strlen(ptrCfd_pSecAgentTradeInfo->BrokerSecAgentID)) );
            js_pSecAgentTradeInfo.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentTradeInfo->InvestorID, strlen(ptrCfd_pSecAgentTradeInfo->InvestorID)) );
            js_pSecAgentTradeInfo.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pSecAgentTradeInfo->LongCustomerName, strlen(ptrCfd_pSecAgentTradeInfo->LongCustomerName)) );
            js_event_data.Set("pSecAgentTradeInfo", js_pSecAgentTradeInfo);
            delete ptrCfd_pSecAgentTradeInfo;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField * pOptionInstrTradeCost, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcOptionInstrTradeCostField *ptrCfd_pOptionInstrTradeCost = new CThostFtdcOptionInstrTradeCostField();
        if(pOptionInstrTradeCost)
        {
            memcpy(ptrCfd_pOptionInstrTradeCost, pOptionInstrTradeCost, sizeof(CThostFtdcOptionInstrTradeCostField));
        }
        else
        {
            memset(ptrCfd_pOptionInstrTradeCost, 0, sizeof(CThostFtdcOptionInstrTradeCostField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryOptionInstrTradeCost");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOptionInstrTradeCost = Napi::Object::New(env);
            js_pOptionInstrTradeCost.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrTradeCost->BrokerID, strlen(ptrCfd_pOptionInstrTradeCost->BrokerID)) );
            js_pOptionInstrTradeCost.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrTradeCost->InvestorID, strlen(ptrCfd_pOptionInstrTradeCost->InvestorID)) );
            js_pOptionInstrTradeCost.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrTradeCost->reserve1, strlen(ptrCfd_pOptionInstrTradeCost->reserve1)) );
            js_pOptionInstrTradeCost.Set("HedgeFlag", string(1u, ptrCfd_pOptionInstrTradeCost->HedgeFlag).c_str());
            js_pOptionInstrTradeCost.Set("FixedMargin", ptrCfd_pOptionInstrTradeCost->FixedMargin);
            js_pOptionInstrTradeCost.Set("MiniMargin", ptrCfd_pOptionInstrTradeCost->MiniMargin);
            js_pOptionInstrTradeCost.Set("Royalty", ptrCfd_pOptionInstrTradeCost->Royalty);
            js_pOptionInstrTradeCost.Set("ExchFixedMargin", ptrCfd_pOptionInstrTradeCost->ExchFixedMargin);
            js_pOptionInstrTradeCost.Set("ExchMiniMargin", ptrCfd_pOptionInstrTradeCost->ExchMiniMargin);
            js_pOptionInstrTradeCost.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrTradeCost->ExchangeID, strlen(ptrCfd_pOptionInstrTradeCost->ExchangeID)) );
            js_pOptionInstrTradeCost.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrTradeCost->InvestUnitID, strlen(ptrCfd_pOptionInstrTradeCost->InvestUnitID)) );
            js_pOptionInstrTradeCost.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrTradeCost->InstrumentID, strlen(ptrCfd_pOptionInstrTradeCost->InstrumentID)) );
            js_event_data.Set("pOptionInstrTradeCost", js_pOptionInstrTradeCost);
            delete ptrCfd_pOptionInstrTradeCost;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField * pOptionInstrCommRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcOptionInstrCommRateField *ptrCfd_pOptionInstrCommRate = new CThostFtdcOptionInstrCommRateField();
        if(pOptionInstrCommRate)
        {
            memcpy(ptrCfd_pOptionInstrCommRate, pOptionInstrCommRate, sizeof(CThostFtdcOptionInstrCommRateField));
        }
        else
        {
            memset(ptrCfd_pOptionInstrCommRate, 0, sizeof(CThostFtdcOptionInstrCommRateField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryOptionInstrCommRate");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOptionInstrCommRate = Napi::Object::New(env);
            js_pOptionInstrCommRate.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrCommRate->reserve1, strlen(ptrCfd_pOptionInstrCommRate->reserve1)) );
            js_pOptionInstrCommRate.Set("InvestorRange", string(1u, ptrCfd_pOptionInstrCommRate->InvestorRange).c_str());
            js_pOptionInstrCommRate.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrCommRate->BrokerID, strlen(ptrCfd_pOptionInstrCommRate->BrokerID)) );
            js_pOptionInstrCommRate.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrCommRate->InvestorID, strlen(ptrCfd_pOptionInstrCommRate->InvestorID)) );
            js_pOptionInstrCommRate.Set("OpenRatioByMoney", ptrCfd_pOptionInstrCommRate->OpenRatioByMoney);
            js_pOptionInstrCommRate.Set("OpenRatioByVolume", ptrCfd_pOptionInstrCommRate->OpenRatioByVolume);
            js_pOptionInstrCommRate.Set("CloseRatioByMoney", ptrCfd_pOptionInstrCommRate->CloseRatioByMoney);
            js_pOptionInstrCommRate.Set("CloseRatioByVolume", ptrCfd_pOptionInstrCommRate->CloseRatioByVolume);
            js_pOptionInstrCommRate.Set("CloseTodayRatioByMoney", ptrCfd_pOptionInstrCommRate->CloseTodayRatioByMoney);
            js_pOptionInstrCommRate.Set("CloseTodayRatioByVolume", ptrCfd_pOptionInstrCommRate->CloseTodayRatioByVolume);
            js_pOptionInstrCommRate.Set("StrikeRatioByMoney", ptrCfd_pOptionInstrCommRate->StrikeRatioByMoney);
            js_pOptionInstrCommRate.Set("StrikeRatioByVolume", ptrCfd_pOptionInstrCommRate->StrikeRatioByVolume);
            js_pOptionInstrCommRate.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrCommRate->ExchangeID, strlen(ptrCfd_pOptionInstrCommRate->ExchangeID)) );
            js_pOptionInstrCommRate.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrCommRate->InvestUnitID, strlen(ptrCfd_pOptionInstrCommRate->InvestUnitID)) );
            js_pOptionInstrCommRate.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionInstrCommRate->InstrumentID, strlen(ptrCfd_pOptionInstrCommRate->InstrumentID)) );
            js_event_data.Set("pOptionInstrCommRate", js_pOptionInstrCommRate);
            delete ptrCfd_pOptionInstrCommRate;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryExecOrder(CThostFtdcExecOrderField * pExecOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcExecOrderField *ptrCfd_pExecOrder = new CThostFtdcExecOrderField();
        if(pExecOrder)
        {
            memcpy(ptrCfd_pExecOrder, pExecOrder, sizeof(CThostFtdcExecOrderField));
        }
        else
        {
            memset(ptrCfd_pExecOrder, 0, sizeof(CThostFtdcExecOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryExecOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExecOrder = Napi::Object::New(env);
            js_pExecOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->BrokerID, strlen(ptrCfd_pExecOrder->BrokerID)) );
            js_pExecOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InvestorID, strlen(ptrCfd_pExecOrder->InvestorID)) );
            js_pExecOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->reserve1, strlen(ptrCfd_pExecOrder->reserve1)) );
            js_pExecOrder.Set("ExecOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExecOrderRef, strlen(ptrCfd_pExecOrder->ExecOrderRef)) );
            js_pExecOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->UserID, strlen(ptrCfd_pExecOrder->UserID)) );
            js_pExecOrder.Set("Volume", ptrCfd_pExecOrder->Volume);
            js_pExecOrder.Set("RequestID", ptrCfd_pExecOrder->RequestID);
            js_pExecOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->BusinessUnit, strlen(ptrCfd_pExecOrder->BusinessUnit)) );
            js_pExecOrder.Set("OffsetFlag", string(1u, ptrCfd_pExecOrder->OffsetFlag).c_str());
            js_pExecOrder.Set("HedgeFlag", string(1u, ptrCfd_pExecOrder->HedgeFlag).c_str());
            js_pExecOrder.Set("ActionType", string(1u, ptrCfd_pExecOrder->ActionType).c_str());
            js_pExecOrder.Set("PosiDirection", string(1u, ptrCfd_pExecOrder->PosiDirection).c_str());
            js_pExecOrder.Set("ReservePositionFlag", string(1u, ptrCfd_pExecOrder->ReservePositionFlag).c_str());
            js_pExecOrder.Set("CloseFlag", string(1u, ptrCfd_pExecOrder->CloseFlag).c_str());
            js_pExecOrder.Set("ExecOrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExecOrderLocalID, strlen(ptrCfd_pExecOrder->ExecOrderLocalID)) );
            js_pExecOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExchangeID, strlen(ptrCfd_pExecOrder->ExchangeID)) );
            js_pExecOrder.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ParticipantID, strlen(ptrCfd_pExecOrder->ParticipantID)) );
            js_pExecOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ClientID, strlen(ptrCfd_pExecOrder->ClientID)) );
            js_pExecOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->reserve2, strlen(ptrCfd_pExecOrder->reserve2)) );
            js_pExecOrder.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->TraderID, strlen(ptrCfd_pExecOrder->TraderID)) );
            js_pExecOrder.Set("InstallID", ptrCfd_pExecOrder->InstallID);
            js_pExecOrder.Set("OrderSubmitStatus", string(1u, ptrCfd_pExecOrder->OrderSubmitStatus).c_str());
            js_pExecOrder.Set("NotifySequence", ptrCfd_pExecOrder->NotifySequence);
            js_pExecOrder.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->TradingDay, strlen(ptrCfd_pExecOrder->TradingDay)) );
            js_pExecOrder.Set("SettlementID", ptrCfd_pExecOrder->SettlementID);
            js_pExecOrder.Set("ExecOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExecOrderSysID, strlen(ptrCfd_pExecOrder->ExecOrderSysID)) );
            js_pExecOrder.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InsertDate, strlen(ptrCfd_pExecOrder->InsertDate)) );
            js_pExecOrder.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InsertTime, strlen(ptrCfd_pExecOrder->InsertTime)) );
            js_pExecOrder.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->CancelTime, strlen(ptrCfd_pExecOrder->CancelTime)) );
            js_pExecOrder.Set("ExecResult", string(1u, ptrCfd_pExecOrder->ExecResult).c_str());
            js_pExecOrder.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ClearingPartID, strlen(ptrCfd_pExecOrder->ClearingPartID)) );
            js_pExecOrder.Set("SequenceNo", ptrCfd_pExecOrder->SequenceNo);
            js_pExecOrder.Set("FrontID", ptrCfd_pExecOrder->FrontID);
            js_pExecOrder.Set("SessionID", ptrCfd_pExecOrder->SessionID);
            js_pExecOrder.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->UserProductInfo, strlen(ptrCfd_pExecOrder->UserProductInfo)) );
            js_pExecOrder.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->StatusMsg, strlen(ptrCfd_pExecOrder->StatusMsg)) );
            js_pExecOrder.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ActiveUserID, strlen(ptrCfd_pExecOrder->ActiveUserID)) );
            js_pExecOrder.Set("BrokerExecOrderSeq", ptrCfd_pExecOrder->BrokerExecOrderSeq);
            js_pExecOrder.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->BranchID, strlen(ptrCfd_pExecOrder->BranchID)) );
            js_pExecOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InvestUnitID, strlen(ptrCfd_pExecOrder->InvestUnitID)) );
            js_pExecOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->AccountID, strlen(ptrCfd_pExecOrder->AccountID)) );
            js_pExecOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->CurrencyID, strlen(ptrCfd_pExecOrder->CurrencyID)) );
            js_pExecOrder.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->reserve3, strlen(ptrCfd_pExecOrder->reserve3)) );
            js_pExecOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->MacAddress, strlen(ptrCfd_pExecOrder->MacAddress)) );
            js_pExecOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InstrumentID, strlen(ptrCfd_pExecOrder->InstrumentID)) );
            js_pExecOrder.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExchangeInstID, strlen(ptrCfd_pExecOrder->ExchangeInstID)) );
            js_pExecOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->IPAddress, strlen(ptrCfd_pExecOrder->IPAddress)) );
            js_event_data.Set("pExecOrder", js_pExecOrder);
            delete ptrCfd_pExecOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryForQuote(CThostFtdcForQuoteField * pForQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcForQuoteField *ptrCfd_pForQuote = new CThostFtdcForQuoteField();
        if(pForQuote)
        {
            memcpy(ptrCfd_pForQuote, pForQuote, sizeof(CThostFtdcForQuoteField));
        }
        else
        {
            memset(ptrCfd_pForQuote, 0, sizeof(CThostFtdcForQuoteField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryForQuote");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pForQuote = Napi::Object::New(env);
            js_pForQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->BrokerID, strlen(ptrCfd_pForQuote->BrokerID)) );
            js_pForQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->InvestorID, strlen(ptrCfd_pForQuote->InvestorID)) );
            js_pForQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->reserve1, strlen(ptrCfd_pForQuote->reserve1)) );
            js_pForQuote.Set("ForQuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ForQuoteRef, strlen(ptrCfd_pForQuote->ForQuoteRef)) );
            js_pForQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->UserID, strlen(ptrCfd_pForQuote->UserID)) );
            js_pForQuote.Set("ForQuoteLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ForQuoteLocalID, strlen(ptrCfd_pForQuote->ForQuoteLocalID)) );
            js_pForQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ExchangeID, strlen(ptrCfd_pForQuote->ExchangeID)) );
            js_pForQuote.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ParticipantID, strlen(ptrCfd_pForQuote->ParticipantID)) );
            js_pForQuote.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ClientID, strlen(ptrCfd_pForQuote->ClientID)) );
            js_pForQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->reserve2, strlen(ptrCfd_pForQuote->reserve2)) );
            js_pForQuote.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->TraderID, strlen(ptrCfd_pForQuote->TraderID)) );
            js_pForQuote.Set("InstallID", ptrCfd_pForQuote->InstallID);
            js_pForQuote.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->InsertDate, strlen(ptrCfd_pForQuote->InsertDate)) );
            js_pForQuote.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->InsertTime, strlen(ptrCfd_pForQuote->InsertTime)) );
            js_pForQuote.Set("ForQuoteStatus", string(1u, ptrCfd_pForQuote->ForQuoteStatus).c_str());
            js_pForQuote.Set("FrontID", ptrCfd_pForQuote->FrontID);
            js_pForQuote.Set("SessionID", ptrCfd_pForQuote->SessionID);
            js_pForQuote.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->StatusMsg, strlen(ptrCfd_pForQuote->StatusMsg)) );
            js_pForQuote.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ActiveUserID, strlen(ptrCfd_pForQuote->ActiveUserID)) );
            js_pForQuote.Set("BrokerForQutoSeq", ptrCfd_pForQuote->BrokerForQutoSeq);
            js_pForQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->InvestUnitID, strlen(ptrCfd_pForQuote->InvestUnitID)) );
            js_pForQuote.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->reserve3, strlen(ptrCfd_pForQuote->reserve3)) );
            js_pForQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->MacAddress, strlen(ptrCfd_pForQuote->MacAddress)) );
            js_pForQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->InstrumentID, strlen(ptrCfd_pForQuote->InstrumentID)) );
            js_pForQuote.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->ExchangeInstID, strlen(ptrCfd_pForQuote->ExchangeInstID)) );
            js_pForQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuote->IPAddress, strlen(ptrCfd_pForQuote->IPAddress)) );
            js_event_data.Set("pForQuote", js_pForQuote);
            delete ptrCfd_pForQuote;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryQuote(CThostFtdcQuoteField * pQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcQuoteField *ptrCfd_pQuote = new CThostFtdcQuoteField();
        if(pQuote)
        {
            memcpy(ptrCfd_pQuote, pQuote, sizeof(CThostFtdcQuoteField));
        }
        else
        {
            memset(ptrCfd_pQuote, 0, sizeof(CThostFtdcQuoteField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryQuote");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pQuote = Napi::Object::New(env);
            js_pQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BrokerID, strlen(ptrCfd_pQuote->BrokerID)) );
            js_pQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InvestorID, strlen(ptrCfd_pQuote->InvestorID)) );
            js_pQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->reserve1, strlen(ptrCfd_pQuote->reserve1)) );
            js_pQuote.Set("QuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->QuoteRef, strlen(ptrCfd_pQuote->QuoteRef)) );
            js_pQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->UserID, strlen(ptrCfd_pQuote->UserID)) );
            js_pQuote.Set("AskPrice", ptrCfd_pQuote->AskPrice);
            js_pQuote.Set("BidPrice", ptrCfd_pQuote->BidPrice);
            js_pQuote.Set("AskVolume", ptrCfd_pQuote->AskVolume);
            js_pQuote.Set("BidVolume", ptrCfd_pQuote->BidVolume);
            js_pQuote.Set("RequestID", ptrCfd_pQuote->RequestID);
            js_pQuote.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BusinessUnit, strlen(ptrCfd_pQuote->BusinessUnit)) );
            js_pQuote.Set("AskOffsetFlag", string(1u, ptrCfd_pQuote->AskOffsetFlag).c_str());
            js_pQuote.Set("BidOffsetFlag", string(1u, ptrCfd_pQuote->BidOffsetFlag).c_str());
            js_pQuote.Set("AskHedgeFlag", string(1u, ptrCfd_pQuote->AskHedgeFlag).c_str());
            js_pQuote.Set("BidHedgeFlag", string(1u, ptrCfd_pQuote->BidHedgeFlag).c_str());
            js_pQuote.Set("QuoteLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->QuoteLocalID, strlen(ptrCfd_pQuote->QuoteLocalID)) );
            js_pQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ExchangeID, strlen(ptrCfd_pQuote->ExchangeID)) );
            js_pQuote.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ParticipantID, strlen(ptrCfd_pQuote->ParticipantID)) );
            js_pQuote.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ClientID, strlen(ptrCfd_pQuote->ClientID)) );
            js_pQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->reserve2, strlen(ptrCfd_pQuote->reserve2)) );
            js_pQuote.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->TraderID, strlen(ptrCfd_pQuote->TraderID)) );
            js_pQuote.Set("InstallID", ptrCfd_pQuote->InstallID);
            js_pQuote.Set("NotifySequence", ptrCfd_pQuote->NotifySequence);
            js_pQuote.Set("OrderSubmitStatus", string(1u, ptrCfd_pQuote->OrderSubmitStatus).c_str());
            js_pQuote.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->TradingDay, strlen(ptrCfd_pQuote->TradingDay)) );
            js_pQuote.Set("SettlementID", ptrCfd_pQuote->SettlementID);
            js_pQuote.Set("QuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->QuoteSysID, strlen(ptrCfd_pQuote->QuoteSysID)) );
            js_pQuote.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InsertDate, strlen(ptrCfd_pQuote->InsertDate)) );
            js_pQuote.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InsertTime, strlen(ptrCfd_pQuote->InsertTime)) );
            js_pQuote.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->CancelTime, strlen(ptrCfd_pQuote->CancelTime)) );
            js_pQuote.Set("QuoteStatus", string(1u, ptrCfd_pQuote->QuoteStatus).c_str());
            js_pQuote.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ClearingPartID, strlen(ptrCfd_pQuote->ClearingPartID)) );
            js_pQuote.Set("SequenceNo", ptrCfd_pQuote->SequenceNo);
            js_pQuote.Set("AskOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->AskOrderSysID, strlen(ptrCfd_pQuote->AskOrderSysID)) );
            js_pQuote.Set("BidOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BidOrderSysID, strlen(ptrCfd_pQuote->BidOrderSysID)) );
            js_pQuote.Set("FrontID", ptrCfd_pQuote->FrontID);
            js_pQuote.Set("SessionID", ptrCfd_pQuote->SessionID);
            js_pQuote.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->UserProductInfo, strlen(ptrCfd_pQuote->UserProductInfo)) );
            js_pQuote.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->StatusMsg, strlen(ptrCfd_pQuote->StatusMsg)) );
            js_pQuote.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ActiveUserID, strlen(ptrCfd_pQuote->ActiveUserID)) );
            js_pQuote.Set("BrokerQuoteSeq", ptrCfd_pQuote->BrokerQuoteSeq);
            js_pQuote.Set("AskOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->AskOrderRef, strlen(ptrCfd_pQuote->AskOrderRef)) );
            js_pQuote.Set("BidOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BidOrderRef, strlen(ptrCfd_pQuote->BidOrderRef)) );
            js_pQuote.Set("ForQuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ForQuoteSysID, strlen(ptrCfd_pQuote->ForQuoteSysID)) );
            js_pQuote.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BranchID, strlen(ptrCfd_pQuote->BranchID)) );
            js_pQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InvestUnitID, strlen(ptrCfd_pQuote->InvestUnitID)) );
            js_pQuote.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->AccountID, strlen(ptrCfd_pQuote->AccountID)) );
            js_pQuote.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->CurrencyID, strlen(ptrCfd_pQuote->CurrencyID)) );
            js_pQuote.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->reserve3, strlen(ptrCfd_pQuote->reserve3)) );
            js_pQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->MacAddress, strlen(ptrCfd_pQuote->MacAddress)) );
            js_pQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InstrumentID, strlen(ptrCfd_pQuote->InstrumentID)) );
            js_pQuote.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ExchangeInstID, strlen(ptrCfd_pQuote->ExchangeInstID)) );
            js_pQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->IPAddress, strlen(ptrCfd_pQuote->IPAddress)) );
            js_pQuote.Set("ReplaceSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ReplaceSysID, strlen(ptrCfd_pQuote->ReplaceSysID)) );
            js_event_data.Set("pQuote", js_pQuote);
            delete ptrCfd_pQuote;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField * pOptionSelfClose, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcOptionSelfCloseField *ptrCfd_pOptionSelfClose = new CThostFtdcOptionSelfCloseField();
        if(pOptionSelfClose)
        {
            memcpy(ptrCfd_pOptionSelfClose, pOptionSelfClose, sizeof(CThostFtdcOptionSelfCloseField));
        }
        else
        {
            memset(ptrCfd_pOptionSelfClose, 0, sizeof(CThostFtdcOptionSelfCloseField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryOptionSelfClose");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOptionSelfClose = Napi::Object::New(env);
            js_pOptionSelfClose.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->BrokerID, strlen(ptrCfd_pOptionSelfClose->BrokerID)) );
            js_pOptionSelfClose.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InvestorID, strlen(ptrCfd_pOptionSelfClose->InvestorID)) );
            js_pOptionSelfClose.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->reserve1, strlen(ptrCfd_pOptionSelfClose->reserve1)) );
            js_pOptionSelfClose.Set("OptionSelfCloseRef", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->OptionSelfCloseRef, strlen(ptrCfd_pOptionSelfClose->OptionSelfCloseRef)) );
            js_pOptionSelfClose.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->UserID, strlen(ptrCfd_pOptionSelfClose->UserID)) );
            js_pOptionSelfClose.Set("Volume", ptrCfd_pOptionSelfClose->Volume);
            js_pOptionSelfClose.Set("RequestID", ptrCfd_pOptionSelfClose->RequestID);
            js_pOptionSelfClose.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->BusinessUnit, strlen(ptrCfd_pOptionSelfClose->BusinessUnit)) );
            js_pOptionSelfClose.Set("HedgeFlag", string(1u, ptrCfd_pOptionSelfClose->HedgeFlag).c_str());
            js_pOptionSelfClose.Set("OptSelfCloseFlag", string(1u, ptrCfd_pOptionSelfClose->OptSelfCloseFlag).c_str());
            js_pOptionSelfClose.Set("OptionSelfCloseLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->OptionSelfCloseLocalID, strlen(ptrCfd_pOptionSelfClose->OptionSelfCloseLocalID)) );
            js_pOptionSelfClose.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ExchangeID, strlen(ptrCfd_pOptionSelfClose->ExchangeID)) );
            js_pOptionSelfClose.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ParticipantID, strlen(ptrCfd_pOptionSelfClose->ParticipantID)) );
            js_pOptionSelfClose.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ClientID, strlen(ptrCfd_pOptionSelfClose->ClientID)) );
            js_pOptionSelfClose.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->reserve2, strlen(ptrCfd_pOptionSelfClose->reserve2)) );
            js_pOptionSelfClose.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->TraderID, strlen(ptrCfd_pOptionSelfClose->TraderID)) );
            js_pOptionSelfClose.Set("InstallID", ptrCfd_pOptionSelfClose->InstallID);
            js_pOptionSelfClose.Set("OrderSubmitStatus", string(1u, ptrCfd_pOptionSelfClose->OrderSubmitStatus).c_str());
            js_pOptionSelfClose.Set("NotifySequence", ptrCfd_pOptionSelfClose->NotifySequence);
            js_pOptionSelfClose.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->TradingDay, strlen(ptrCfd_pOptionSelfClose->TradingDay)) );
            js_pOptionSelfClose.Set("SettlementID", ptrCfd_pOptionSelfClose->SettlementID);
            js_pOptionSelfClose.Set("OptionSelfCloseSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->OptionSelfCloseSysID, strlen(ptrCfd_pOptionSelfClose->OptionSelfCloseSysID)) );
            js_pOptionSelfClose.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InsertDate, strlen(ptrCfd_pOptionSelfClose->InsertDate)) );
            js_pOptionSelfClose.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InsertTime, strlen(ptrCfd_pOptionSelfClose->InsertTime)) );
            js_pOptionSelfClose.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->CancelTime, strlen(ptrCfd_pOptionSelfClose->CancelTime)) );
            js_pOptionSelfClose.Set("ExecResult", string(1u, ptrCfd_pOptionSelfClose->ExecResult).c_str());
            js_pOptionSelfClose.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ClearingPartID, strlen(ptrCfd_pOptionSelfClose->ClearingPartID)) );
            js_pOptionSelfClose.Set("SequenceNo", ptrCfd_pOptionSelfClose->SequenceNo);
            js_pOptionSelfClose.Set("FrontID", ptrCfd_pOptionSelfClose->FrontID);
            js_pOptionSelfClose.Set("SessionID", ptrCfd_pOptionSelfClose->SessionID);
            js_pOptionSelfClose.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->UserProductInfo, strlen(ptrCfd_pOptionSelfClose->UserProductInfo)) );
            js_pOptionSelfClose.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->StatusMsg, strlen(ptrCfd_pOptionSelfClose->StatusMsg)) );
            js_pOptionSelfClose.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ActiveUserID, strlen(ptrCfd_pOptionSelfClose->ActiveUserID)) );
            js_pOptionSelfClose.Set("BrokerOptionSelfCloseSeq", ptrCfd_pOptionSelfClose->BrokerOptionSelfCloseSeq);
            js_pOptionSelfClose.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->BranchID, strlen(ptrCfd_pOptionSelfClose->BranchID)) );
            js_pOptionSelfClose.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InvestUnitID, strlen(ptrCfd_pOptionSelfClose->InvestUnitID)) );
            js_pOptionSelfClose.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->AccountID, strlen(ptrCfd_pOptionSelfClose->AccountID)) );
            js_pOptionSelfClose.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->CurrencyID, strlen(ptrCfd_pOptionSelfClose->CurrencyID)) );
            js_pOptionSelfClose.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->reserve3, strlen(ptrCfd_pOptionSelfClose->reserve3)) );
            js_pOptionSelfClose.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->MacAddress, strlen(ptrCfd_pOptionSelfClose->MacAddress)) );
            js_pOptionSelfClose.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InstrumentID, strlen(ptrCfd_pOptionSelfClose->InstrumentID)) );
            js_pOptionSelfClose.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ExchangeInstID, strlen(ptrCfd_pOptionSelfClose->ExchangeInstID)) );
            js_pOptionSelfClose.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->IPAddress, strlen(ptrCfd_pOptionSelfClose->IPAddress)) );
            js_event_data.Set("pOptionSelfClose", js_pOptionSelfClose);
            delete ptrCfd_pOptionSelfClose;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryInvestUnit(CThostFtdcInvestUnitField * pInvestUnit, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInvestUnitField *ptrCfd_pInvestUnit = new CThostFtdcInvestUnitField();
        if(pInvestUnit)
        {
            memcpy(ptrCfd_pInvestUnit, pInvestUnit, sizeof(CThostFtdcInvestUnitField));
        }
        else
        {
            memset(ptrCfd_pInvestUnit, 0, sizeof(CThostFtdcInvestUnitField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryInvestUnit");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInvestUnit = Napi::Object::New(env);
            js_pInvestUnit.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->BrokerID, strlen(ptrCfd_pInvestUnit->BrokerID)) );
            js_pInvestUnit.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->InvestorID, strlen(ptrCfd_pInvestUnit->InvestorID)) );
            js_pInvestUnit.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->InvestUnitID, strlen(ptrCfd_pInvestUnit->InvestUnitID)) );
            js_pInvestUnit.Set("InvestorUnitName", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->InvestorUnitName, strlen(ptrCfd_pInvestUnit->InvestorUnitName)) );
            js_pInvestUnit.Set("InvestorGroupID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->InvestorGroupID, strlen(ptrCfd_pInvestUnit->InvestorGroupID)) );
            js_pInvestUnit.Set("CommModelID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->CommModelID, strlen(ptrCfd_pInvestUnit->CommModelID)) );
            js_pInvestUnit.Set("MarginModelID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->MarginModelID, strlen(ptrCfd_pInvestUnit->MarginModelID)) );
            js_pInvestUnit.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->AccountID, strlen(ptrCfd_pInvestUnit->AccountID)) );
            js_pInvestUnit.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInvestUnit->CurrencyID, strlen(ptrCfd_pInvestUnit->CurrencyID)) );
            js_event_data.Set("pInvestUnit", js_pInvestUnit);
            delete ptrCfd_pInvestUnit;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField * pCombInstrumentGuard, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcCombInstrumentGuardField *ptrCfd_pCombInstrumentGuard = new CThostFtdcCombInstrumentGuardField();
        if(pCombInstrumentGuard)
        {
            memcpy(ptrCfd_pCombInstrumentGuard, pCombInstrumentGuard, sizeof(CThostFtdcCombInstrumentGuardField));
        }
        else
        {
            memset(ptrCfd_pCombInstrumentGuard, 0, sizeof(CThostFtdcCombInstrumentGuardField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryCombInstrumentGuard");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCombInstrumentGuard = Napi::Object::New(env);
            js_pCombInstrumentGuard.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombInstrumentGuard->BrokerID, strlen(ptrCfd_pCombInstrumentGuard->BrokerID)) );
            js_pCombInstrumentGuard.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pCombInstrumentGuard->reserve1, strlen(ptrCfd_pCombInstrumentGuard->reserve1)) );
            js_pCombInstrumentGuard.Set("GuarantRatio", ptrCfd_pCombInstrumentGuard->GuarantRatio);
            js_pCombInstrumentGuard.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombInstrumentGuard->ExchangeID, strlen(ptrCfd_pCombInstrumentGuard->ExchangeID)) );
            js_pCombInstrumentGuard.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombInstrumentGuard->InstrumentID, strlen(ptrCfd_pCombInstrumentGuard->InstrumentID)) );
            js_event_data.Set("pCombInstrumentGuard", js_pCombInstrumentGuard);
            delete ptrCfd_pCombInstrumentGuard;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryCombAction(CThostFtdcCombActionField * pCombAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcCombActionField *ptrCfd_pCombAction = new CThostFtdcCombActionField();
        if(pCombAction)
        {
            memcpy(ptrCfd_pCombAction, pCombAction, sizeof(CThostFtdcCombActionField));
        }
        else
        {
            memset(ptrCfd_pCombAction, 0, sizeof(CThostFtdcCombActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryCombAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCombAction = Napi::Object::New(env);
            js_pCombAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->BrokerID, strlen(ptrCfd_pCombAction->BrokerID)) );
            js_pCombAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->InvestorID, strlen(ptrCfd_pCombAction->InvestorID)) );
            js_pCombAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->reserve1, strlen(ptrCfd_pCombAction->reserve1)) );
            js_pCombAction.Set("CombActionRef", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->CombActionRef, strlen(ptrCfd_pCombAction->CombActionRef)) );
            js_pCombAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->UserID, strlen(ptrCfd_pCombAction->UserID)) );
            js_pCombAction.Set("Direction", string(1u, ptrCfd_pCombAction->Direction).c_str());
            js_pCombAction.Set("Volume", ptrCfd_pCombAction->Volume);
            js_pCombAction.Set("CombDirection", string(1u, ptrCfd_pCombAction->CombDirection).c_str());
            js_pCombAction.Set("HedgeFlag", string(1u, ptrCfd_pCombAction->HedgeFlag).c_str());
            js_pCombAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ActionLocalID, strlen(ptrCfd_pCombAction->ActionLocalID)) );
            js_pCombAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ExchangeID, strlen(ptrCfd_pCombAction->ExchangeID)) );
            js_pCombAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ParticipantID, strlen(ptrCfd_pCombAction->ParticipantID)) );
            js_pCombAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ClientID, strlen(ptrCfd_pCombAction->ClientID)) );
            js_pCombAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->reserve2, strlen(ptrCfd_pCombAction->reserve2)) );
            js_pCombAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->TraderID, strlen(ptrCfd_pCombAction->TraderID)) );
            js_pCombAction.Set("InstallID", ptrCfd_pCombAction->InstallID);
            js_pCombAction.Set("ActionStatus", string(1u, ptrCfd_pCombAction->ActionStatus).c_str());
            js_pCombAction.Set("NotifySequence", ptrCfd_pCombAction->NotifySequence);
            js_pCombAction.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->TradingDay, strlen(ptrCfd_pCombAction->TradingDay)) );
            js_pCombAction.Set("SettlementID", ptrCfd_pCombAction->SettlementID);
            js_pCombAction.Set("SequenceNo", ptrCfd_pCombAction->SequenceNo);
            js_pCombAction.Set("FrontID", ptrCfd_pCombAction->FrontID);
            js_pCombAction.Set("SessionID", ptrCfd_pCombAction->SessionID);
            js_pCombAction.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->UserProductInfo, strlen(ptrCfd_pCombAction->UserProductInfo)) );
            js_pCombAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->StatusMsg, strlen(ptrCfd_pCombAction->StatusMsg)) );
            js_pCombAction.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->reserve3, strlen(ptrCfd_pCombAction->reserve3)) );
            js_pCombAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->MacAddress, strlen(ptrCfd_pCombAction->MacAddress)) );
            js_pCombAction.Set("ComTradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ComTradeID, strlen(ptrCfd_pCombAction->ComTradeID)) );
            js_pCombAction.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->BranchID, strlen(ptrCfd_pCombAction->BranchID)) );
            js_pCombAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->InvestUnitID, strlen(ptrCfd_pCombAction->InvestUnitID)) );
            js_pCombAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->InstrumentID, strlen(ptrCfd_pCombAction->InstrumentID)) );
            js_pCombAction.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ExchangeInstID, strlen(ptrCfd_pCombAction->ExchangeInstID)) );
            js_pCombAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->IPAddress, strlen(ptrCfd_pCombAction->IPAddress)) );
            js_event_data.Set("pCombAction", js_pCombAction);
            delete ptrCfd_pCombAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryTransferSerial(CThostFtdcTransferSerialField * pTransferSerial, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTransferSerialField *ptrCfd_pTransferSerial = new CThostFtdcTransferSerialField();
        if(pTransferSerial)
        {
            memcpy(ptrCfd_pTransferSerial, pTransferSerial, sizeof(CThostFtdcTransferSerialField));
        }
        else
        {
            memset(ptrCfd_pTransferSerial, 0, sizeof(CThostFtdcTransferSerialField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryTransferSerial");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTransferSerial = Napi::Object::New(env);
            js_pTransferSerial.Set("PlateSerial", ptrCfd_pTransferSerial->PlateSerial);
            js_pTransferSerial.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->TradeDate, strlen(ptrCfd_pTransferSerial->TradeDate)) );
            js_pTransferSerial.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->TradingDay, strlen(ptrCfd_pTransferSerial->TradingDay)) );
            js_pTransferSerial.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->TradeTime, strlen(ptrCfd_pTransferSerial->TradeTime)) );
            js_pTransferSerial.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->TradeCode, strlen(ptrCfd_pTransferSerial->TradeCode)) );
            js_pTransferSerial.Set("SessionID", ptrCfd_pTransferSerial->SessionID);
            js_pTransferSerial.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BankID, strlen(ptrCfd_pTransferSerial->BankID)) );
            js_pTransferSerial.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BankBranchID, strlen(ptrCfd_pTransferSerial->BankBranchID)) );
            js_pTransferSerial.Set("BankAccType", string(1u, ptrCfd_pTransferSerial->BankAccType).c_str());
            js_pTransferSerial.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BankAccount, strlen(ptrCfd_pTransferSerial->BankAccount)) );
            js_pTransferSerial.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BankSerial, strlen(ptrCfd_pTransferSerial->BankSerial)) );
            js_pTransferSerial.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BrokerID, strlen(ptrCfd_pTransferSerial->BrokerID)) );
            js_pTransferSerial.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BrokerBranchID, strlen(ptrCfd_pTransferSerial->BrokerBranchID)) );
            js_pTransferSerial.Set("FutureAccType", string(1u, ptrCfd_pTransferSerial->FutureAccType).c_str());
            js_pTransferSerial.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->AccountID, strlen(ptrCfd_pTransferSerial->AccountID)) );
            js_pTransferSerial.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->InvestorID, strlen(ptrCfd_pTransferSerial->InvestorID)) );
            js_pTransferSerial.Set("FutureSerial", ptrCfd_pTransferSerial->FutureSerial);
            js_pTransferSerial.Set("IdCardType", string(1u, ptrCfd_pTransferSerial->IdCardType).c_str());
            js_pTransferSerial.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->IdentifiedCardNo, strlen(ptrCfd_pTransferSerial->IdentifiedCardNo)) );
            js_pTransferSerial.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->CurrencyID, strlen(ptrCfd_pTransferSerial->CurrencyID)) );
            js_pTransferSerial.Set("TradeAmount", ptrCfd_pTransferSerial->TradeAmount);
            js_pTransferSerial.Set("CustFee", ptrCfd_pTransferSerial->CustFee);
            js_pTransferSerial.Set("BrokerFee", ptrCfd_pTransferSerial->BrokerFee);
            js_pTransferSerial.Set("AvailabilityFlag", string(1u, ptrCfd_pTransferSerial->AvailabilityFlag).c_str());
            js_pTransferSerial.Set("OperatorCode", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->OperatorCode, strlen(ptrCfd_pTransferSerial->OperatorCode)) );
            js_pTransferSerial.Set("BankNewAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->BankNewAccount, strlen(ptrCfd_pTransferSerial->BankNewAccount)) );
            js_pTransferSerial.Set("ErrorID", ptrCfd_pTransferSerial->ErrorID);
            js_pTransferSerial.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pTransferSerial->ErrorMsg, strlen(ptrCfd_pTransferSerial->ErrorMsg)) );
            js_event_data.Set("pTransferSerial", js_pTransferSerial);
            delete ptrCfd_pTransferSerial;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryAccountregister(CThostFtdcAccountregisterField * pAccountregister, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcAccountregisterField *ptrCfd_pAccountregister = new CThostFtdcAccountregisterField();
        if(pAccountregister)
        {
            memcpy(ptrCfd_pAccountregister, pAccountregister, sizeof(CThostFtdcAccountregisterField));
        }
        else
        {
            memset(ptrCfd_pAccountregister, 0, sizeof(CThostFtdcAccountregisterField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryAccountregister");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pAccountregister = Napi::Object::New(env);
            js_pAccountregister.Set("TradeDay", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->TradeDay, strlen(ptrCfd_pAccountregister->TradeDay)) );
            js_pAccountregister.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->BankID, strlen(ptrCfd_pAccountregister->BankID)) );
            js_pAccountregister.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->BankBranchID, strlen(ptrCfd_pAccountregister->BankBranchID)) );
            js_pAccountregister.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->BankAccount, strlen(ptrCfd_pAccountregister->BankAccount)) );
            js_pAccountregister.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->BrokerID, strlen(ptrCfd_pAccountregister->BrokerID)) );
            js_pAccountregister.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->BrokerBranchID, strlen(ptrCfd_pAccountregister->BrokerBranchID)) );
            js_pAccountregister.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->AccountID, strlen(ptrCfd_pAccountregister->AccountID)) );
            js_pAccountregister.Set("IdCardType", string(1u, ptrCfd_pAccountregister->IdCardType).c_str());
            js_pAccountregister.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->IdentifiedCardNo, strlen(ptrCfd_pAccountregister->IdentifiedCardNo)) );
            js_pAccountregister.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->CustomerName, strlen(ptrCfd_pAccountregister->CustomerName)) );
            js_pAccountregister.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->CurrencyID, strlen(ptrCfd_pAccountregister->CurrencyID)) );
            js_pAccountregister.Set("OpenOrDestroy", string(1u, ptrCfd_pAccountregister->OpenOrDestroy).c_str());
            js_pAccountregister.Set("RegDate", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->RegDate, strlen(ptrCfd_pAccountregister->RegDate)) );
            js_pAccountregister.Set("OutDate", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->OutDate, strlen(ptrCfd_pAccountregister->OutDate)) );
            js_pAccountregister.Set("TID", ptrCfd_pAccountregister->TID);
            js_pAccountregister.Set("CustType", string(1u, ptrCfd_pAccountregister->CustType).c_str());
            js_pAccountregister.Set("BankAccType", string(1u, ptrCfd_pAccountregister->BankAccType).c_str());
            js_pAccountregister.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pAccountregister->LongCustomerName, strlen(ptrCfd_pAccountregister->LongCustomerName)) );
            js_event_data.Set("pAccountregister", js_pAccountregister);
            delete ptrCfd_pAccountregister;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspError(CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspError");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnOrder(CThostFtdcOrderField * pOrder)
    {
        
        CThostFtdcOrderField *ptrCfd_pOrder = new CThostFtdcOrderField();
        if(pOrder)
        {
            memcpy(ptrCfd_pOrder, pOrder, sizeof(CThostFtdcOrderField));
        }
        else
        {
            memset(ptrCfd_pOrder, 0, sizeof(CThostFtdcOrderField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOrder = Napi::Object::New(env);
            js_pOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->BrokerID, strlen(ptrCfd_pOrder->BrokerID)) );
            js_pOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InvestorID, strlen(ptrCfd_pOrder->InvestorID)) );
            js_pOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->reserve1, strlen(ptrCfd_pOrder->reserve1)) );
            js_pOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->OrderRef, strlen(ptrCfd_pOrder->OrderRef)) );
            js_pOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->UserID, strlen(ptrCfd_pOrder->UserID)) );
            js_pOrder.Set("OrderPriceType", string(1u, ptrCfd_pOrder->OrderPriceType).c_str());
            js_pOrder.Set("Direction", string(1u, ptrCfd_pOrder->Direction).c_str());
            js_pOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CombOffsetFlag, strlen(ptrCfd_pOrder->CombOffsetFlag)) );
            js_pOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CombHedgeFlag, strlen(ptrCfd_pOrder->CombHedgeFlag)) );
            js_pOrder.Set("LimitPrice", ptrCfd_pOrder->LimitPrice);
            js_pOrder.Set("VolumeTotalOriginal", ptrCfd_pOrder->VolumeTotalOriginal);
            js_pOrder.Set("TimeCondition", string(1u, ptrCfd_pOrder->TimeCondition).c_str());
            js_pOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->GTDDate, strlen(ptrCfd_pOrder->GTDDate)) );
            js_pOrder.Set("VolumeCondition", string(1u, ptrCfd_pOrder->VolumeCondition).c_str());
            js_pOrder.Set("MinVolume", ptrCfd_pOrder->MinVolume);
            js_pOrder.Set("ContingentCondition", string(1u, ptrCfd_pOrder->ContingentCondition).c_str());
            js_pOrder.Set("StopPrice", ptrCfd_pOrder->StopPrice);
            js_pOrder.Set("ForceCloseReason", string(1u, ptrCfd_pOrder->ForceCloseReason).c_str());
            js_pOrder.Set("IsAutoSuspend", ptrCfd_pOrder->IsAutoSuspend);
            js_pOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->BusinessUnit, strlen(ptrCfd_pOrder->BusinessUnit)) );
            js_pOrder.Set("RequestID", ptrCfd_pOrder->RequestID);
            js_pOrder.Set("OrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->OrderLocalID, strlen(ptrCfd_pOrder->OrderLocalID)) );
            js_pOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ExchangeID, strlen(ptrCfd_pOrder->ExchangeID)) );
            js_pOrder.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ParticipantID, strlen(ptrCfd_pOrder->ParticipantID)) );
            js_pOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ClientID, strlen(ptrCfd_pOrder->ClientID)) );
            js_pOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->reserve2, strlen(ptrCfd_pOrder->reserve2)) );
            js_pOrder.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->TraderID, strlen(ptrCfd_pOrder->TraderID)) );
            js_pOrder.Set("InstallID", ptrCfd_pOrder->InstallID);
            js_pOrder.Set("OrderSubmitStatus", string(1u, ptrCfd_pOrder->OrderSubmitStatus).c_str());
            js_pOrder.Set("NotifySequence", ptrCfd_pOrder->NotifySequence);
            js_pOrder.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->TradingDay, strlen(ptrCfd_pOrder->TradingDay)) );
            js_pOrder.Set("SettlementID", ptrCfd_pOrder->SettlementID);
            js_pOrder.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->OrderSysID, strlen(ptrCfd_pOrder->OrderSysID)) );
            js_pOrder.Set("OrderSource", string(1u, ptrCfd_pOrder->OrderSource).c_str());
            js_pOrder.Set("OrderStatus", string(1u, ptrCfd_pOrder->OrderStatus).c_str());
            js_pOrder.Set("OrderType", string(1u, ptrCfd_pOrder->OrderType).c_str());
            js_pOrder.Set("VolumeTraded", ptrCfd_pOrder->VolumeTraded);
            js_pOrder.Set("VolumeTotal", ptrCfd_pOrder->VolumeTotal);
            js_pOrder.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InsertDate, strlen(ptrCfd_pOrder->InsertDate)) );
            js_pOrder.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InsertTime, strlen(ptrCfd_pOrder->InsertTime)) );
            js_pOrder.Set("ActiveTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ActiveTime, strlen(ptrCfd_pOrder->ActiveTime)) );
            js_pOrder.Set("SuspendTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->SuspendTime, strlen(ptrCfd_pOrder->SuspendTime)) );
            js_pOrder.Set("UpdateTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->UpdateTime, strlen(ptrCfd_pOrder->UpdateTime)) );
            js_pOrder.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CancelTime, strlen(ptrCfd_pOrder->CancelTime)) );
            js_pOrder.Set("ActiveTraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ActiveTraderID, strlen(ptrCfd_pOrder->ActiveTraderID)) );
            js_pOrder.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ClearingPartID, strlen(ptrCfd_pOrder->ClearingPartID)) );
            js_pOrder.Set("SequenceNo", ptrCfd_pOrder->SequenceNo);
            js_pOrder.Set("FrontID", ptrCfd_pOrder->FrontID);
            js_pOrder.Set("SessionID", ptrCfd_pOrder->SessionID);
            js_pOrder.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->UserProductInfo, strlen(ptrCfd_pOrder->UserProductInfo)) );
            js_pOrder.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->StatusMsg, strlen(ptrCfd_pOrder->StatusMsg)) );
            js_pOrder.Set("UserForceClose", ptrCfd_pOrder->UserForceClose);
            js_pOrder.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ActiveUserID, strlen(ptrCfd_pOrder->ActiveUserID)) );
            js_pOrder.Set("BrokerOrderSeq", ptrCfd_pOrder->BrokerOrderSeq);
            js_pOrder.Set("RelativeOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->RelativeOrderSysID, strlen(ptrCfd_pOrder->RelativeOrderSysID)) );
            js_pOrder.Set("ZCETotalTradedVolume", ptrCfd_pOrder->ZCETotalTradedVolume);
            js_pOrder.Set("IsSwapOrder", ptrCfd_pOrder->IsSwapOrder);
            js_pOrder.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->BranchID, strlen(ptrCfd_pOrder->BranchID)) );
            js_pOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InvestUnitID, strlen(ptrCfd_pOrder->InvestUnitID)) );
            js_pOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->AccountID, strlen(ptrCfd_pOrder->AccountID)) );
            js_pOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->CurrencyID, strlen(ptrCfd_pOrder->CurrencyID)) );
            js_pOrder.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->reserve3, strlen(ptrCfd_pOrder->reserve3)) );
            js_pOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->MacAddress, strlen(ptrCfd_pOrder->MacAddress)) );
            js_pOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->InstrumentID, strlen(ptrCfd_pOrder->InstrumentID)) );
            js_pOrder.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->ExchangeInstID, strlen(ptrCfd_pOrder->ExchangeInstID)) );
            js_pOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOrder->IPAddress, strlen(ptrCfd_pOrder->IPAddress)) );
            js_event_data.Set("pOrder", js_pOrder);
            delete ptrCfd_pOrder;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnTrade(CThostFtdcTradeField * pTrade)
    {
        
        CThostFtdcTradeField *ptrCfd_pTrade = new CThostFtdcTradeField();
        if(pTrade)
        {
            memcpy(ptrCfd_pTrade, pTrade, sizeof(CThostFtdcTradeField));
        }
        else
        {
            memset(ptrCfd_pTrade, 0, sizeof(CThostFtdcTradeField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnTrade");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTrade = Napi::Object::New(env);
            js_pTrade.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->BrokerID, strlen(ptrCfd_pTrade->BrokerID)) );
            js_pTrade.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->InvestorID, strlen(ptrCfd_pTrade->InvestorID)) );
            js_pTrade.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->reserve1, strlen(ptrCfd_pTrade->reserve1)) );
            js_pTrade.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->OrderRef, strlen(ptrCfd_pTrade->OrderRef)) );
            js_pTrade.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->UserID, strlen(ptrCfd_pTrade->UserID)) );
            js_pTrade.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ExchangeID, strlen(ptrCfd_pTrade->ExchangeID)) );
            js_pTrade.Set("TradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradeID, strlen(ptrCfd_pTrade->TradeID)) );
            js_pTrade.Set("Direction", string(1u, ptrCfd_pTrade->Direction).c_str());
            js_pTrade.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->OrderSysID, strlen(ptrCfd_pTrade->OrderSysID)) );
            js_pTrade.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ParticipantID, strlen(ptrCfd_pTrade->ParticipantID)) );
            js_pTrade.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ClientID, strlen(ptrCfd_pTrade->ClientID)) );
            js_pTrade.Set("TradingRole", string(1u, ptrCfd_pTrade->TradingRole).c_str());
            js_pTrade.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->reserve2, strlen(ptrCfd_pTrade->reserve2)) );
            js_pTrade.Set("OffsetFlag", string(1u, ptrCfd_pTrade->OffsetFlag).c_str());
            js_pTrade.Set("HedgeFlag", string(1u, ptrCfd_pTrade->HedgeFlag).c_str());
            js_pTrade.Set("Price", ptrCfd_pTrade->Price);
            js_pTrade.Set("Volume", ptrCfd_pTrade->Volume);
            js_pTrade.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradeDate, strlen(ptrCfd_pTrade->TradeDate)) );
            js_pTrade.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradeTime, strlen(ptrCfd_pTrade->TradeTime)) );
            js_pTrade.Set("TradeType", string(1u, ptrCfd_pTrade->TradeType).c_str());
            js_pTrade.Set("PriceSource", string(1u, ptrCfd_pTrade->PriceSource).c_str());
            js_pTrade.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TraderID, strlen(ptrCfd_pTrade->TraderID)) );
            js_pTrade.Set("OrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->OrderLocalID, strlen(ptrCfd_pTrade->OrderLocalID)) );
            js_pTrade.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ClearingPartID, strlen(ptrCfd_pTrade->ClearingPartID)) );
            js_pTrade.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->BusinessUnit, strlen(ptrCfd_pTrade->BusinessUnit)) );
            js_pTrade.Set("SequenceNo", ptrCfd_pTrade->SequenceNo);
            js_pTrade.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->TradingDay, strlen(ptrCfd_pTrade->TradingDay)) );
            js_pTrade.Set("SettlementID", ptrCfd_pTrade->SettlementID);
            js_pTrade.Set("BrokerOrderSeq", ptrCfd_pTrade->BrokerOrderSeq);
            js_pTrade.Set("TradeSource", string(1u, ptrCfd_pTrade->TradeSource).c_str());
            js_pTrade.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->InvestUnitID, strlen(ptrCfd_pTrade->InvestUnitID)) );
            js_pTrade.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->InstrumentID, strlen(ptrCfd_pTrade->InstrumentID)) );
            js_pTrade.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pTrade->ExchangeInstID, strlen(ptrCfd_pTrade->ExchangeInstID)) );
            js_event_data.Set("pTrade", js_pTrade);
            delete ptrCfd_pTrade;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnOrderInsert(CThostFtdcInputOrderField * pInputOrder, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcInputOrderField *ptrCfd_pInputOrder = new CThostFtdcInputOrderField();
        if(pInputOrder)
        {
            memcpy(ptrCfd_pInputOrder, pInputOrder, sizeof(CThostFtdcInputOrderField));
        }
        else
        {
            memset(ptrCfd_pInputOrder, 0, sizeof(CThostFtdcInputOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnOrderInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputOrder = Napi::Object::New(env);
            js_pInputOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->BrokerID, strlen(ptrCfd_pInputOrder->BrokerID)) );
            js_pInputOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->InvestorID, strlen(ptrCfd_pInputOrder->InvestorID)) );
            js_pInputOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->reserve1, strlen(ptrCfd_pInputOrder->reserve1)) );
            js_pInputOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->OrderRef, strlen(ptrCfd_pInputOrder->OrderRef)) );
            js_pInputOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->UserID, strlen(ptrCfd_pInputOrder->UserID)) );
            js_pInputOrder.Set("OrderPriceType", string(1u, ptrCfd_pInputOrder->OrderPriceType).c_str());
            js_pInputOrder.Set("Direction", string(1u, ptrCfd_pInputOrder->Direction).c_str());
            js_pInputOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->CombOffsetFlag, strlen(ptrCfd_pInputOrder->CombOffsetFlag)) );
            js_pInputOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->CombHedgeFlag, strlen(ptrCfd_pInputOrder->CombHedgeFlag)) );
            js_pInputOrder.Set("LimitPrice", ptrCfd_pInputOrder->LimitPrice);
            js_pInputOrder.Set("VolumeTotalOriginal", ptrCfd_pInputOrder->VolumeTotalOriginal);
            js_pInputOrder.Set("TimeCondition", string(1u, ptrCfd_pInputOrder->TimeCondition).c_str());
            js_pInputOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->GTDDate, strlen(ptrCfd_pInputOrder->GTDDate)) );
            js_pInputOrder.Set("VolumeCondition", string(1u, ptrCfd_pInputOrder->VolumeCondition).c_str());
            js_pInputOrder.Set("MinVolume", ptrCfd_pInputOrder->MinVolume);
            js_pInputOrder.Set("ContingentCondition", string(1u, ptrCfd_pInputOrder->ContingentCondition).c_str());
            js_pInputOrder.Set("StopPrice", ptrCfd_pInputOrder->StopPrice);
            js_pInputOrder.Set("ForceCloseReason", string(1u, ptrCfd_pInputOrder->ForceCloseReason).c_str());
            js_pInputOrder.Set("IsAutoSuspend", ptrCfd_pInputOrder->IsAutoSuspend);
            js_pInputOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->BusinessUnit, strlen(ptrCfd_pInputOrder->BusinessUnit)) );
            js_pInputOrder.Set("RequestID", ptrCfd_pInputOrder->RequestID);
            js_pInputOrder.Set("UserForceClose", ptrCfd_pInputOrder->UserForceClose);
            js_pInputOrder.Set("IsSwapOrder", ptrCfd_pInputOrder->IsSwapOrder);
            js_pInputOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->ExchangeID, strlen(ptrCfd_pInputOrder->ExchangeID)) );
            js_pInputOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->InvestUnitID, strlen(ptrCfd_pInputOrder->InvestUnitID)) );
            js_pInputOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->AccountID, strlen(ptrCfd_pInputOrder->AccountID)) );
            js_pInputOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->CurrencyID, strlen(ptrCfd_pInputOrder->CurrencyID)) );
            js_pInputOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->ClientID, strlen(ptrCfd_pInputOrder->ClientID)) );
            js_pInputOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->reserve2, strlen(ptrCfd_pInputOrder->reserve2)) );
            js_pInputOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->MacAddress, strlen(ptrCfd_pInputOrder->MacAddress)) );
            js_pInputOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->InstrumentID, strlen(ptrCfd_pInputOrder->InstrumentID)) );
            js_pInputOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOrder->IPAddress, strlen(ptrCfd_pInputOrder->IPAddress)) );
            js_event_data.Set("pInputOrder", js_pInputOrder);
            delete ptrCfd_pInputOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnOrderAction(CThostFtdcOrderActionField * pOrderAction, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcOrderActionField *ptrCfd_pOrderAction = new CThostFtdcOrderActionField();
        if(pOrderAction)
        {
            memcpy(ptrCfd_pOrderAction, pOrderAction, sizeof(CThostFtdcOrderActionField));
        }
        else
        {
            memset(ptrCfd_pOrderAction, 0, sizeof(CThostFtdcOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOrderAction = Napi::Object::New(env);
            js_pOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->BrokerID, strlen(ptrCfd_pOrderAction->BrokerID)) );
            js_pOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->InvestorID, strlen(ptrCfd_pOrderAction->InvestorID)) );
            js_pOrderAction.Set("OrderActionRef", ptrCfd_pOrderAction->OrderActionRef);
            js_pOrderAction.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->OrderRef, strlen(ptrCfd_pOrderAction->OrderRef)) );
            js_pOrderAction.Set("RequestID", ptrCfd_pOrderAction->RequestID);
            js_pOrderAction.Set("FrontID", ptrCfd_pOrderAction->FrontID);
            js_pOrderAction.Set("SessionID", ptrCfd_pOrderAction->SessionID);
            js_pOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->ExchangeID, strlen(ptrCfd_pOrderAction->ExchangeID)) );
            js_pOrderAction.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->OrderSysID, strlen(ptrCfd_pOrderAction->OrderSysID)) );
            js_pOrderAction.Set("ActionFlag", string(1u, ptrCfd_pOrderAction->ActionFlag).c_str());
            js_pOrderAction.Set("LimitPrice", ptrCfd_pOrderAction->LimitPrice);
            js_pOrderAction.Set("VolumeChange", ptrCfd_pOrderAction->VolumeChange);
            js_pOrderAction.Set("ActionDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->ActionDate, strlen(ptrCfd_pOrderAction->ActionDate)) );
            js_pOrderAction.Set("ActionTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->ActionTime, strlen(ptrCfd_pOrderAction->ActionTime)) );
            js_pOrderAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->TraderID, strlen(ptrCfd_pOrderAction->TraderID)) );
            js_pOrderAction.Set("InstallID", ptrCfd_pOrderAction->InstallID);
            js_pOrderAction.Set("OrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->OrderLocalID, strlen(ptrCfd_pOrderAction->OrderLocalID)) );
            js_pOrderAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->ActionLocalID, strlen(ptrCfd_pOrderAction->ActionLocalID)) );
            js_pOrderAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->ParticipantID, strlen(ptrCfd_pOrderAction->ParticipantID)) );
            js_pOrderAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->ClientID, strlen(ptrCfd_pOrderAction->ClientID)) );
            js_pOrderAction.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->BusinessUnit, strlen(ptrCfd_pOrderAction->BusinessUnit)) );
            js_pOrderAction.Set("OrderActionStatus", string(1u, ptrCfd_pOrderAction->OrderActionStatus).c_str());
            js_pOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->UserID, strlen(ptrCfd_pOrderAction->UserID)) );
            js_pOrderAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->StatusMsg, strlen(ptrCfd_pOrderAction->StatusMsg)) );
            js_pOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->reserve1, strlen(ptrCfd_pOrderAction->reserve1)) );
            js_pOrderAction.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->BranchID, strlen(ptrCfd_pOrderAction->BranchID)) );
            js_pOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->InvestUnitID, strlen(ptrCfd_pOrderAction->InvestUnitID)) );
            js_pOrderAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->reserve2, strlen(ptrCfd_pOrderAction->reserve2)) );
            js_pOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->MacAddress, strlen(ptrCfd_pOrderAction->MacAddress)) );
            js_pOrderAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->InstrumentID, strlen(ptrCfd_pOrderAction->InstrumentID)) );
            js_pOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOrderAction->IPAddress, strlen(ptrCfd_pOrderAction->IPAddress)) );
            js_event_data.Set("pOrderAction", js_pOrderAction);
            delete ptrCfd_pOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField * pInstrumentStatus)
    {
        
        CThostFtdcInstrumentStatusField *ptrCfd_pInstrumentStatus = new CThostFtdcInstrumentStatusField();
        if(pInstrumentStatus)
        {
            memcpy(ptrCfd_pInstrumentStatus, pInstrumentStatus, sizeof(CThostFtdcInstrumentStatusField));
        }
        else
        {
            memset(ptrCfd_pInstrumentStatus, 0, sizeof(CThostFtdcInstrumentStatusField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnInstrumentStatus");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInstrumentStatus = Napi::Object::New(env);
            js_pInstrumentStatus.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->ExchangeID, strlen(ptrCfd_pInstrumentStatus->ExchangeID)) );
            js_pInstrumentStatus.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->reserve1, strlen(ptrCfd_pInstrumentStatus->reserve1)) );
            js_pInstrumentStatus.Set("SettlementGroupID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->SettlementGroupID, strlen(ptrCfd_pInstrumentStatus->SettlementGroupID)) );
            js_pInstrumentStatus.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->reserve2, strlen(ptrCfd_pInstrumentStatus->reserve2)) );
            js_pInstrumentStatus.Set("InstrumentStatus", string(1u, ptrCfd_pInstrumentStatus->InstrumentStatus).c_str());
            js_pInstrumentStatus.Set("TradingSegmentSN", ptrCfd_pInstrumentStatus->TradingSegmentSN);
            js_pInstrumentStatus.Set("EnterTime", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->EnterTime, strlen(ptrCfd_pInstrumentStatus->EnterTime)) );
            js_pInstrumentStatus.Set("EnterReason", string(1u, ptrCfd_pInstrumentStatus->EnterReason).c_str());
            js_pInstrumentStatus.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->ExchangeInstID, strlen(ptrCfd_pInstrumentStatus->ExchangeInstID)) );
            js_pInstrumentStatus.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrumentStatus->InstrumentID, strlen(ptrCfd_pInstrumentStatus->InstrumentID)) );
            js_event_data.Set("pInstrumentStatus", js_pInstrumentStatus);
            delete ptrCfd_pInstrumentStatus;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnBulletin(CThostFtdcBulletinField * pBulletin)
    {
        
        CThostFtdcBulletinField *ptrCfd_pBulletin = new CThostFtdcBulletinField();
        if(pBulletin)
        {
            memcpy(ptrCfd_pBulletin, pBulletin, sizeof(CThostFtdcBulletinField));
        }
        else
        {
            memset(ptrCfd_pBulletin, 0, sizeof(CThostFtdcBulletinField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnBulletin");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pBulletin = Napi::Object::New(env);
            js_pBulletin.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->ExchangeID, strlen(ptrCfd_pBulletin->ExchangeID)) );
            js_pBulletin.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->TradingDay, strlen(ptrCfd_pBulletin->TradingDay)) );
            js_pBulletin.Set("BulletinID", ptrCfd_pBulletin->BulletinID);
            js_pBulletin.Set("SequenceNo", ptrCfd_pBulletin->SequenceNo);
            js_pBulletin.Set("NewsType", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->NewsType, strlen(ptrCfd_pBulletin->NewsType)) );
            js_pBulletin.Set("NewsUrgency", string(1u, ptrCfd_pBulletin->NewsUrgency).c_str());
            js_pBulletin.Set("SendTime", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->SendTime, strlen(ptrCfd_pBulletin->SendTime)) );
            js_pBulletin.Set("Abstract", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->Abstract, strlen(ptrCfd_pBulletin->Abstract)) );
            js_pBulletin.Set("ComeFrom", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->ComeFrom, strlen(ptrCfd_pBulletin->ComeFrom)) );
            js_pBulletin.Set("Content", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->Content, strlen(ptrCfd_pBulletin->Content)) );
            js_pBulletin.Set("URLLink", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->URLLink, strlen(ptrCfd_pBulletin->URLLink)) );
            js_pBulletin.Set("MarketID", Napi::Buffer<char>::Copy(env, ptrCfd_pBulletin->MarketID, strlen(ptrCfd_pBulletin->MarketID)) );
            js_event_data.Set("pBulletin", js_pBulletin);
            delete ptrCfd_pBulletin;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField * pTradingNoticeInfo)
    {
        
        CThostFtdcTradingNoticeInfoField *ptrCfd_pTradingNoticeInfo = new CThostFtdcTradingNoticeInfoField();
        if(pTradingNoticeInfo)
        {
            memcpy(ptrCfd_pTradingNoticeInfo, pTradingNoticeInfo, sizeof(CThostFtdcTradingNoticeInfoField));
        }
        else
        {
            memset(ptrCfd_pTradingNoticeInfo, 0, sizeof(CThostFtdcTradingNoticeInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnTradingNotice");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTradingNoticeInfo = Napi::Object::New(env);
            js_pTradingNoticeInfo.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNoticeInfo->BrokerID, strlen(ptrCfd_pTradingNoticeInfo->BrokerID)) );
            js_pTradingNoticeInfo.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNoticeInfo->InvestorID, strlen(ptrCfd_pTradingNoticeInfo->InvestorID)) );
            js_pTradingNoticeInfo.Set("SendTime", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNoticeInfo->SendTime, strlen(ptrCfd_pTradingNoticeInfo->SendTime)) );
            js_pTradingNoticeInfo.Set("FieldContent", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNoticeInfo->FieldContent, strlen(ptrCfd_pTradingNoticeInfo->FieldContent)) );
            js_pTradingNoticeInfo.Set("SequenceSeries", ptrCfd_pTradingNoticeInfo->SequenceSeries);
            js_pTradingNoticeInfo.Set("SequenceNo", ptrCfd_pTradingNoticeInfo->SequenceNo);
            js_pTradingNoticeInfo.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNoticeInfo->InvestUnitID, strlen(ptrCfd_pTradingNoticeInfo->InvestUnitID)) );
            js_event_data.Set("pTradingNoticeInfo", js_pTradingNoticeInfo);
            delete ptrCfd_pTradingNoticeInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField * pErrorConditionalOrder)
    {
        
        CThostFtdcErrorConditionalOrderField *ptrCfd_pErrorConditionalOrder = new CThostFtdcErrorConditionalOrderField();
        if(pErrorConditionalOrder)
        {
            memcpy(ptrCfd_pErrorConditionalOrder, pErrorConditionalOrder, sizeof(CThostFtdcErrorConditionalOrderField));
        }
        else
        {
            memset(ptrCfd_pErrorConditionalOrder, 0, sizeof(CThostFtdcErrorConditionalOrderField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnErrorConditionalOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pErrorConditionalOrder = Napi::Object::New(env);
            js_pErrorConditionalOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->BrokerID, strlen(ptrCfd_pErrorConditionalOrder->BrokerID)) );
            js_pErrorConditionalOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->InvestorID, strlen(ptrCfd_pErrorConditionalOrder->InvestorID)) );
            js_pErrorConditionalOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->reserve1, strlen(ptrCfd_pErrorConditionalOrder->reserve1)) );
            js_pErrorConditionalOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->OrderRef, strlen(ptrCfd_pErrorConditionalOrder->OrderRef)) );
            js_pErrorConditionalOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->UserID, strlen(ptrCfd_pErrorConditionalOrder->UserID)) );
            js_pErrorConditionalOrder.Set("OrderPriceType", string(1u, ptrCfd_pErrorConditionalOrder->OrderPriceType).c_str());
            js_pErrorConditionalOrder.Set("Direction", string(1u, ptrCfd_pErrorConditionalOrder->Direction).c_str());
            js_pErrorConditionalOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->CombOffsetFlag, strlen(ptrCfd_pErrorConditionalOrder->CombOffsetFlag)) );
            js_pErrorConditionalOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->CombHedgeFlag, strlen(ptrCfd_pErrorConditionalOrder->CombHedgeFlag)) );
            js_pErrorConditionalOrder.Set("LimitPrice", ptrCfd_pErrorConditionalOrder->LimitPrice);
            js_pErrorConditionalOrder.Set("VolumeTotalOriginal", ptrCfd_pErrorConditionalOrder->VolumeTotalOriginal);
            js_pErrorConditionalOrder.Set("TimeCondition", string(1u, ptrCfd_pErrorConditionalOrder->TimeCondition).c_str());
            js_pErrorConditionalOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->GTDDate, strlen(ptrCfd_pErrorConditionalOrder->GTDDate)) );
            js_pErrorConditionalOrder.Set("VolumeCondition", string(1u, ptrCfd_pErrorConditionalOrder->VolumeCondition).c_str());
            js_pErrorConditionalOrder.Set("MinVolume", ptrCfd_pErrorConditionalOrder->MinVolume);
            js_pErrorConditionalOrder.Set("ContingentCondition", string(1u, ptrCfd_pErrorConditionalOrder->ContingentCondition).c_str());
            js_pErrorConditionalOrder.Set("StopPrice", ptrCfd_pErrorConditionalOrder->StopPrice);
            js_pErrorConditionalOrder.Set("ForceCloseReason", string(1u, ptrCfd_pErrorConditionalOrder->ForceCloseReason).c_str());
            js_pErrorConditionalOrder.Set("IsAutoSuspend", ptrCfd_pErrorConditionalOrder->IsAutoSuspend);
            js_pErrorConditionalOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->BusinessUnit, strlen(ptrCfd_pErrorConditionalOrder->BusinessUnit)) );
            js_pErrorConditionalOrder.Set("RequestID", ptrCfd_pErrorConditionalOrder->RequestID);
            js_pErrorConditionalOrder.Set("OrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->OrderLocalID, strlen(ptrCfd_pErrorConditionalOrder->OrderLocalID)) );
            js_pErrorConditionalOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ExchangeID, strlen(ptrCfd_pErrorConditionalOrder->ExchangeID)) );
            js_pErrorConditionalOrder.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ParticipantID, strlen(ptrCfd_pErrorConditionalOrder->ParticipantID)) );
            js_pErrorConditionalOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ClientID, strlen(ptrCfd_pErrorConditionalOrder->ClientID)) );
            js_pErrorConditionalOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->reserve2, strlen(ptrCfd_pErrorConditionalOrder->reserve2)) );
            js_pErrorConditionalOrder.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->TraderID, strlen(ptrCfd_pErrorConditionalOrder->TraderID)) );
            js_pErrorConditionalOrder.Set("InstallID", ptrCfd_pErrorConditionalOrder->InstallID);
            js_pErrorConditionalOrder.Set("OrderSubmitStatus", string(1u, ptrCfd_pErrorConditionalOrder->OrderSubmitStatus).c_str());
            js_pErrorConditionalOrder.Set("NotifySequence", ptrCfd_pErrorConditionalOrder->NotifySequence);
            js_pErrorConditionalOrder.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->TradingDay, strlen(ptrCfd_pErrorConditionalOrder->TradingDay)) );
            js_pErrorConditionalOrder.Set("SettlementID", ptrCfd_pErrorConditionalOrder->SettlementID);
            js_pErrorConditionalOrder.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->OrderSysID, strlen(ptrCfd_pErrorConditionalOrder->OrderSysID)) );
            js_pErrorConditionalOrder.Set("OrderSource", string(1u, ptrCfd_pErrorConditionalOrder->OrderSource).c_str());
            js_pErrorConditionalOrder.Set("OrderStatus", string(1u, ptrCfd_pErrorConditionalOrder->OrderStatus).c_str());
            js_pErrorConditionalOrder.Set("OrderType", string(1u, ptrCfd_pErrorConditionalOrder->OrderType).c_str());
            js_pErrorConditionalOrder.Set("VolumeTraded", ptrCfd_pErrorConditionalOrder->VolumeTraded);
            js_pErrorConditionalOrder.Set("VolumeTotal", ptrCfd_pErrorConditionalOrder->VolumeTotal);
            js_pErrorConditionalOrder.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->InsertDate, strlen(ptrCfd_pErrorConditionalOrder->InsertDate)) );
            js_pErrorConditionalOrder.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->InsertTime, strlen(ptrCfd_pErrorConditionalOrder->InsertTime)) );
            js_pErrorConditionalOrder.Set("ActiveTime", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ActiveTime, strlen(ptrCfd_pErrorConditionalOrder->ActiveTime)) );
            js_pErrorConditionalOrder.Set("SuspendTime", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->SuspendTime, strlen(ptrCfd_pErrorConditionalOrder->SuspendTime)) );
            js_pErrorConditionalOrder.Set("UpdateTime", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->UpdateTime, strlen(ptrCfd_pErrorConditionalOrder->UpdateTime)) );
            js_pErrorConditionalOrder.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->CancelTime, strlen(ptrCfd_pErrorConditionalOrder->CancelTime)) );
            js_pErrorConditionalOrder.Set("ActiveTraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ActiveTraderID, strlen(ptrCfd_pErrorConditionalOrder->ActiveTraderID)) );
            js_pErrorConditionalOrder.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ClearingPartID, strlen(ptrCfd_pErrorConditionalOrder->ClearingPartID)) );
            js_pErrorConditionalOrder.Set("SequenceNo", ptrCfd_pErrorConditionalOrder->SequenceNo);
            js_pErrorConditionalOrder.Set("FrontID", ptrCfd_pErrorConditionalOrder->FrontID);
            js_pErrorConditionalOrder.Set("SessionID", ptrCfd_pErrorConditionalOrder->SessionID);
            js_pErrorConditionalOrder.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->UserProductInfo, strlen(ptrCfd_pErrorConditionalOrder->UserProductInfo)) );
            js_pErrorConditionalOrder.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->StatusMsg, strlen(ptrCfd_pErrorConditionalOrder->StatusMsg)) );
            js_pErrorConditionalOrder.Set("UserForceClose", ptrCfd_pErrorConditionalOrder->UserForceClose);
            js_pErrorConditionalOrder.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ActiveUserID, strlen(ptrCfd_pErrorConditionalOrder->ActiveUserID)) );
            js_pErrorConditionalOrder.Set("BrokerOrderSeq", ptrCfd_pErrorConditionalOrder->BrokerOrderSeq);
            js_pErrorConditionalOrder.Set("RelativeOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->RelativeOrderSysID, strlen(ptrCfd_pErrorConditionalOrder->RelativeOrderSysID)) );
            js_pErrorConditionalOrder.Set("ZCETotalTradedVolume", ptrCfd_pErrorConditionalOrder->ZCETotalTradedVolume);
            js_pErrorConditionalOrder.Set("ErrorID", ptrCfd_pErrorConditionalOrder->ErrorID);
            js_pErrorConditionalOrder.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ErrorMsg, strlen(ptrCfd_pErrorConditionalOrder->ErrorMsg)) );
            js_pErrorConditionalOrder.Set("IsSwapOrder", ptrCfd_pErrorConditionalOrder->IsSwapOrder);
            js_pErrorConditionalOrder.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->BranchID, strlen(ptrCfd_pErrorConditionalOrder->BranchID)) );
            js_pErrorConditionalOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->InvestUnitID, strlen(ptrCfd_pErrorConditionalOrder->InvestUnitID)) );
            js_pErrorConditionalOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->AccountID, strlen(ptrCfd_pErrorConditionalOrder->AccountID)) );
            js_pErrorConditionalOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->CurrencyID, strlen(ptrCfd_pErrorConditionalOrder->CurrencyID)) );
            js_pErrorConditionalOrder.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->reserve3, strlen(ptrCfd_pErrorConditionalOrder->reserve3)) );
            js_pErrorConditionalOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->MacAddress, strlen(ptrCfd_pErrorConditionalOrder->MacAddress)) );
            js_pErrorConditionalOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->InstrumentID, strlen(ptrCfd_pErrorConditionalOrder->InstrumentID)) );
            js_pErrorConditionalOrder.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->ExchangeInstID, strlen(ptrCfd_pErrorConditionalOrder->ExchangeInstID)) );
            js_pErrorConditionalOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pErrorConditionalOrder->IPAddress, strlen(ptrCfd_pErrorConditionalOrder->IPAddress)) );
            js_event_data.Set("pErrorConditionalOrder", js_pErrorConditionalOrder);
            delete ptrCfd_pErrorConditionalOrder;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnExecOrder(CThostFtdcExecOrderField * pExecOrder)
    {
        
        CThostFtdcExecOrderField *ptrCfd_pExecOrder = new CThostFtdcExecOrderField();
        if(pExecOrder)
        {
            memcpy(ptrCfd_pExecOrder, pExecOrder, sizeof(CThostFtdcExecOrderField));
        }
        else
        {
            memset(ptrCfd_pExecOrder, 0, sizeof(CThostFtdcExecOrderField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnExecOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExecOrder = Napi::Object::New(env);
            js_pExecOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->BrokerID, strlen(ptrCfd_pExecOrder->BrokerID)) );
            js_pExecOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InvestorID, strlen(ptrCfd_pExecOrder->InvestorID)) );
            js_pExecOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->reserve1, strlen(ptrCfd_pExecOrder->reserve1)) );
            js_pExecOrder.Set("ExecOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExecOrderRef, strlen(ptrCfd_pExecOrder->ExecOrderRef)) );
            js_pExecOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->UserID, strlen(ptrCfd_pExecOrder->UserID)) );
            js_pExecOrder.Set("Volume", ptrCfd_pExecOrder->Volume);
            js_pExecOrder.Set("RequestID", ptrCfd_pExecOrder->RequestID);
            js_pExecOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->BusinessUnit, strlen(ptrCfd_pExecOrder->BusinessUnit)) );
            js_pExecOrder.Set("OffsetFlag", string(1u, ptrCfd_pExecOrder->OffsetFlag).c_str());
            js_pExecOrder.Set("HedgeFlag", string(1u, ptrCfd_pExecOrder->HedgeFlag).c_str());
            js_pExecOrder.Set("ActionType", string(1u, ptrCfd_pExecOrder->ActionType).c_str());
            js_pExecOrder.Set("PosiDirection", string(1u, ptrCfd_pExecOrder->PosiDirection).c_str());
            js_pExecOrder.Set("ReservePositionFlag", string(1u, ptrCfd_pExecOrder->ReservePositionFlag).c_str());
            js_pExecOrder.Set("CloseFlag", string(1u, ptrCfd_pExecOrder->CloseFlag).c_str());
            js_pExecOrder.Set("ExecOrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExecOrderLocalID, strlen(ptrCfd_pExecOrder->ExecOrderLocalID)) );
            js_pExecOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExchangeID, strlen(ptrCfd_pExecOrder->ExchangeID)) );
            js_pExecOrder.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ParticipantID, strlen(ptrCfd_pExecOrder->ParticipantID)) );
            js_pExecOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ClientID, strlen(ptrCfd_pExecOrder->ClientID)) );
            js_pExecOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->reserve2, strlen(ptrCfd_pExecOrder->reserve2)) );
            js_pExecOrder.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->TraderID, strlen(ptrCfd_pExecOrder->TraderID)) );
            js_pExecOrder.Set("InstallID", ptrCfd_pExecOrder->InstallID);
            js_pExecOrder.Set("OrderSubmitStatus", string(1u, ptrCfd_pExecOrder->OrderSubmitStatus).c_str());
            js_pExecOrder.Set("NotifySequence", ptrCfd_pExecOrder->NotifySequence);
            js_pExecOrder.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->TradingDay, strlen(ptrCfd_pExecOrder->TradingDay)) );
            js_pExecOrder.Set("SettlementID", ptrCfd_pExecOrder->SettlementID);
            js_pExecOrder.Set("ExecOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExecOrderSysID, strlen(ptrCfd_pExecOrder->ExecOrderSysID)) );
            js_pExecOrder.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InsertDate, strlen(ptrCfd_pExecOrder->InsertDate)) );
            js_pExecOrder.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InsertTime, strlen(ptrCfd_pExecOrder->InsertTime)) );
            js_pExecOrder.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->CancelTime, strlen(ptrCfd_pExecOrder->CancelTime)) );
            js_pExecOrder.Set("ExecResult", string(1u, ptrCfd_pExecOrder->ExecResult).c_str());
            js_pExecOrder.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ClearingPartID, strlen(ptrCfd_pExecOrder->ClearingPartID)) );
            js_pExecOrder.Set("SequenceNo", ptrCfd_pExecOrder->SequenceNo);
            js_pExecOrder.Set("FrontID", ptrCfd_pExecOrder->FrontID);
            js_pExecOrder.Set("SessionID", ptrCfd_pExecOrder->SessionID);
            js_pExecOrder.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->UserProductInfo, strlen(ptrCfd_pExecOrder->UserProductInfo)) );
            js_pExecOrder.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->StatusMsg, strlen(ptrCfd_pExecOrder->StatusMsg)) );
            js_pExecOrder.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ActiveUserID, strlen(ptrCfd_pExecOrder->ActiveUserID)) );
            js_pExecOrder.Set("BrokerExecOrderSeq", ptrCfd_pExecOrder->BrokerExecOrderSeq);
            js_pExecOrder.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->BranchID, strlen(ptrCfd_pExecOrder->BranchID)) );
            js_pExecOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InvestUnitID, strlen(ptrCfd_pExecOrder->InvestUnitID)) );
            js_pExecOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->AccountID, strlen(ptrCfd_pExecOrder->AccountID)) );
            js_pExecOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->CurrencyID, strlen(ptrCfd_pExecOrder->CurrencyID)) );
            js_pExecOrder.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->reserve3, strlen(ptrCfd_pExecOrder->reserve3)) );
            js_pExecOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->MacAddress, strlen(ptrCfd_pExecOrder->MacAddress)) );
            js_pExecOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->InstrumentID, strlen(ptrCfd_pExecOrder->InstrumentID)) );
            js_pExecOrder.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->ExchangeInstID, strlen(ptrCfd_pExecOrder->ExchangeInstID)) );
            js_pExecOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrder->IPAddress, strlen(ptrCfd_pExecOrder->IPAddress)) );
            js_event_data.Set("pExecOrder", js_pExecOrder);
            delete ptrCfd_pExecOrder;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField * pInputExecOrder, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcInputExecOrderField *ptrCfd_pInputExecOrder = new CThostFtdcInputExecOrderField();
        if(pInputExecOrder)
        {
            memcpy(ptrCfd_pInputExecOrder, pInputExecOrder, sizeof(CThostFtdcInputExecOrderField));
        }
        else
        {
            memset(ptrCfd_pInputExecOrder, 0, sizeof(CThostFtdcInputExecOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnExecOrderInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputExecOrder = Napi::Object::New(env);
            js_pInputExecOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->BrokerID, strlen(ptrCfd_pInputExecOrder->BrokerID)) );
            js_pInputExecOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->InvestorID, strlen(ptrCfd_pInputExecOrder->InvestorID)) );
            js_pInputExecOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->reserve1, strlen(ptrCfd_pInputExecOrder->reserve1)) );
            js_pInputExecOrder.Set("ExecOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->ExecOrderRef, strlen(ptrCfd_pInputExecOrder->ExecOrderRef)) );
            js_pInputExecOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->UserID, strlen(ptrCfd_pInputExecOrder->UserID)) );
            js_pInputExecOrder.Set("Volume", ptrCfd_pInputExecOrder->Volume);
            js_pInputExecOrder.Set("RequestID", ptrCfd_pInputExecOrder->RequestID);
            js_pInputExecOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->BusinessUnit, strlen(ptrCfd_pInputExecOrder->BusinessUnit)) );
            js_pInputExecOrder.Set("OffsetFlag", string(1u, ptrCfd_pInputExecOrder->OffsetFlag).c_str());
            js_pInputExecOrder.Set("HedgeFlag", string(1u, ptrCfd_pInputExecOrder->HedgeFlag).c_str());
            js_pInputExecOrder.Set("ActionType", string(1u, ptrCfd_pInputExecOrder->ActionType).c_str());
            js_pInputExecOrder.Set("PosiDirection", string(1u, ptrCfd_pInputExecOrder->PosiDirection).c_str());
            js_pInputExecOrder.Set("ReservePositionFlag", string(1u, ptrCfd_pInputExecOrder->ReservePositionFlag).c_str());
            js_pInputExecOrder.Set("CloseFlag", string(1u, ptrCfd_pInputExecOrder->CloseFlag).c_str());
            js_pInputExecOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->ExchangeID, strlen(ptrCfd_pInputExecOrder->ExchangeID)) );
            js_pInputExecOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->InvestUnitID, strlen(ptrCfd_pInputExecOrder->InvestUnitID)) );
            js_pInputExecOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->AccountID, strlen(ptrCfd_pInputExecOrder->AccountID)) );
            js_pInputExecOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->CurrencyID, strlen(ptrCfd_pInputExecOrder->CurrencyID)) );
            js_pInputExecOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->ClientID, strlen(ptrCfd_pInputExecOrder->ClientID)) );
            js_pInputExecOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->reserve2, strlen(ptrCfd_pInputExecOrder->reserve2)) );
            js_pInputExecOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->MacAddress, strlen(ptrCfd_pInputExecOrder->MacAddress)) );
            js_pInputExecOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->InstrumentID, strlen(ptrCfd_pInputExecOrder->InstrumentID)) );
            js_pInputExecOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputExecOrder->IPAddress, strlen(ptrCfd_pInputExecOrder->IPAddress)) );
            js_event_data.Set("pInputExecOrder", js_pInputExecOrder);
            delete ptrCfd_pInputExecOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField * pExecOrderAction, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcExecOrderActionField *ptrCfd_pExecOrderAction = new CThostFtdcExecOrderActionField();
        if(pExecOrderAction)
        {
            memcpy(ptrCfd_pExecOrderAction, pExecOrderAction, sizeof(CThostFtdcExecOrderActionField));
        }
        else
        {
            memset(ptrCfd_pExecOrderAction, 0, sizeof(CThostFtdcExecOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnExecOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pExecOrderAction = Napi::Object::New(env);
            js_pExecOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->BrokerID, strlen(ptrCfd_pExecOrderAction->BrokerID)) );
            js_pExecOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->InvestorID, strlen(ptrCfd_pExecOrderAction->InvestorID)) );
            js_pExecOrderAction.Set("ExecOrderActionRef", ptrCfd_pExecOrderAction->ExecOrderActionRef);
            js_pExecOrderAction.Set("ExecOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ExecOrderRef, strlen(ptrCfd_pExecOrderAction->ExecOrderRef)) );
            js_pExecOrderAction.Set("RequestID", ptrCfd_pExecOrderAction->RequestID);
            js_pExecOrderAction.Set("FrontID", ptrCfd_pExecOrderAction->FrontID);
            js_pExecOrderAction.Set("SessionID", ptrCfd_pExecOrderAction->SessionID);
            js_pExecOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ExchangeID, strlen(ptrCfd_pExecOrderAction->ExchangeID)) );
            js_pExecOrderAction.Set("ExecOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ExecOrderSysID, strlen(ptrCfd_pExecOrderAction->ExecOrderSysID)) );
            js_pExecOrderAction.Set("ActionFlag", string(1u, ptrCfd_pExecOrderAction->ActionFlag).c_str());
            js_pExecOrderAction.Set("ActionDate", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ActionDate, strlen(ptrCfd_pExecOrderAction->ActionDate)) );
            js_pExecOrderAction.Set("ActionTime", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ActionTime, strlen(ptrCfd_pExecOrderAction->ActionTime)) );
            js_pExecOrderAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->TraderID, strlen(ptrCfd_pExecOrderAction->TraderID)) );
            js_pExecOrderAction.Set("InstallID", ptrCfd_pExecOrderAction->InstallID);
            js_pExecOrderAction.Set("ExecOrderLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ExecOrderLocalID, strlen(ptrCfd_pExecOrderAction->ExecOrderLocalID)) );
            js_pExecOrderAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ActionLocalID, strlen(ptrCfd_pExecOrderAction->ActionLocalID)) );
            js_pExecOrderAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ParticipantID, strlen(ptrCfd_pExecOrderAction->ParticipantID)) );
            js_pExecOrderAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->ClientID, strlen(ptrCfd_pExecOrderAction->ClientID)) );
            js_pExecOrderAction.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->BusinessUnit, strlen(ptrCfd_pExecOrderAction->BusinessUnit)) );
            js_pExecOrderAction.Set("OrderActionStatus", string(1u, ptrCfd_pExecOrderAction->OrderActionStatus).c_str());
            js_pExecOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->UserID, strlen(ptrCfd_pExecOrderAction->UserID)) );
            js_pExecOrderAction.Set("ActionType", string(1u, ptrCfd_pExecOrderAction->ActionType).c_str());
            js_pExecOrderAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->StatusMsg, strlen(ptrCfd_pExecOrderAction->StatusMsg)) );
            js_pExecOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->reserve1, strlen(ptrCfd_pExecOrderAction->reserve1)) );
            js_pExecOrderAction.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->BranchID, strlen(ptrCfd_pExecOrderAction->BranchID)) );
            js_pExecOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->InvestUnitID, strlen(ptrCfd_pExecOrderAction->InvestUnitID)) );
            js_pExecOrderAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->reserve2, strlen(ptrCfd_pExecOrderAction->reserve2)) );
            js_pExecOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->MacAddress, strlen(ptrCfd_pExecOrderAction->MacAddress)) );
            js_pExecOrderAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->InstrumentID, strlen(ptrCfd_pExecOrderAction->InstrumentID)) );
            js_pExecOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pExecOrderAction->IPAddress, strlen(ptrCfd_pExecOrderAction->IPAddress)) );
            js_event_data.Set("pExecOrderAction", js_pExecOrderAction);
            delete ptrCfd_pExecOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField * pInputForQuote, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcInputForQuoteField *ptrCfd_pInputForQuote = new CThostFtdcInputForQuoteField();
        if(pInputForQuote)
        {
            memcpy(ptrCfd_pInputForQuote, pInputForQuote, sizeof(CThostFtdcInputForQuoteField));
        }
        else
        {
            memset(ptrCfd_pInputForQuote, 0, sizeof(CThostFtdcInputForQuoteField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnForQuoteInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputForQuote = Napi::Object::New(env);
            js_pInputForQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->BrokerID, strlen(ptrCfd_pInputForQuote->BrokerID)) );
            js_pInputForQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->InvestorID, strlen(ptrCfd_pInputForQuote->InvestorID)) );
            js_pInputForQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->reserve1, strlen(ptrCfd_pInputForQuote->reserve1)) );
            js_pInputForQuote.Set("ForQuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->ForQuoteRef, strlen(ptrCfd_pInputForQuote->ForQuoteRef)) );
            js_pInputForQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->UserID, strlen(ptrCfd_pInputForQuote->UserID)) );
            js_pInputForQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->ExchangeID, strlen(ptrCfd_pInputForQuote->ExchangeID)) );
            js_pInputForQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->InvestUnitID, strlen(ptrCfd_pInputForQuote->InvestUnitID)) );
            js_pInputForQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->reserve2, strlen(ptrCfd_pInputForQuote->reserve2)) );
            js_pInputForQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->MacAddress, strlen(ptrCfd_pInputForQuote->MacAddress)) );
            js_pInputForQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->InstrumentID, strlen(ptrCfd_pInputForQuote->InstrumentID)) );
            js_pInputForQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputForQuote->IPAddress, strlen(ptrCfd_pInputForQuote->IPAddress)) );
            js_event_data.Set("pInputForQuote", js_pInputForQuote);
            delete ptrCfd_pInputForQuote;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnQuote(CThostFtdcQuoteField * pQuote)
    {
        
        CThostFtdcQuoteField *ptrCfd_pQuote = new CThostFtdcQuoteField();
        if(pQuote)
        {
            memcpy(ptrCfd_pQuote, pQuote, sizeof(CThostFtdcQuoteField));
        }
        else
        {
            memset(ptrCfd_pQuote, 0, sizeof(CThostFtdcQuoteField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnQuote");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pQuote = Napi::Object::New(env);
            js_pQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BrokerID, strlen(ptrCfd_pQuote->BrokerID)) );
            js_pQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InvestorID, strlen(ptrCfd_pQuote->InvestorID)) );
            js_pQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->reserve1, strlen(ptrCfd_pQuote->reserve1)) );
            js_pQuote.Set("QuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->QuoteRef, strlen(ptrCfd_pQuote->QuoteRef)) );
            js_pQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->UserID, strlen(ptrCfd_pQuote->UserID)) );
            js_pQuote.Set("AskPrice", ptrCfd_pQuote->AskPrice);
            js_pQuote.Set("BidPrice", ptrCfd_pQuote->BidPrice);
            js_pQuote.Set("AskVolume", ptrCfd_pQuote->AskVolume);
            js_pQuote.Set("BidVolume", ptrCfd_pQuote->BidVolume);
            js_pQuote.Set("RequestID", ptrCfd_pQuote->RequestID);
            js_pQuote.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BusinessUnit, strlen(ptrCfd_pQuote->BusinessUnit)) );
            js_pQuote.Set("AskOffsetFlag", string(1u, ptrCfd_pQuote->AskOffsetFlag).c_str());
            js_pQuote.Set("BidOffsetFlag", string(1u, ptrCfd_pQuote->BidOffsetFlag).c_str());
            js_pQuote.Set("AskHedgeFlag", string(1u, ptrCfd_pQuote->AskHedgeFlag).c_str());
            js_pQuote.Set("BidHedgeFlag", string(1u, ptrCfd_pQuote->BidHedgeFlag).c_str());
            js_pQuote.Set("QuoteLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->QuoteLocalID, strlen(ptrCfd_pQuote->QuoteLocalID)) );
            js_pQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ExchangeID, strlen(ptrCfd_pQuote->ExchangeID)) );
            js_pQuote.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ParticipantID, strlen(ptrCfd_pQuote->ParticipantID)) );
            js_pQuote.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ClientID, strlen(ptrCfd_pQuote->ClientID)) );
            js_pQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->reserve2, strlen(ptrCfd_pQuote->reserve2)) );
            js_pQuote.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->TraderID, strlen(ptrCfd_pQuote->TraderID)) );
            js_pQuote.Set("InstallID", ptrCfd_pQuote->InstallID);
            js_pQuote.Set("NotifySequence", ptrCfd_pQuote->NotifySequence);
            js_pQuote.Set("OrderSubmitStatus", string(1u, ptrCfd_pQuote->OrderSubmitStatus).c_str());
            js_pQuote.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->TradingDay, strlen(ptrCfd_pQuote->TradingDay)) );
            js_pQuote.Set("SettlementID", ptrCfd_pQuote->SettlementID);
            js_pQuote.Set("QuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->QuoteSysID, strlen(ptrCfd_pQuote->QuoteSysID)) );
            js_pQuote.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InsertDate, strlen(ptrCfd_pQuote->InsertDate)) );
            js_pQuote.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InsertTime, strlen(ptrCfd_pQuote->InsertTime)) );
            js_pQuote.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->CancelTime, strlen(ptrCfd_pQuote->CancelTime)) );
            js_pQuote.Set("QuoteStatus", string(1u, ptrCfd_pQuote->QuoteStatus).c_str());
            js_pQuote.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ClearingPartID, strlen(ptrCfd_pQuote->ClearingPartID)) );
            js_pQuote.Set("SequenceNo", ptrCfd_pQuote->SequenceNo);
            js_pQuote.Set("AskOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->AskOrderSysID, strlen(ptrCfd_pQuote->AskOrderSysID)) );
            js_pQuote.Set("BidOrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BidOrderSysID, strlen(ptrCfd_pQuote->BidOrderSysID)) );
            js_pQuote.Set("FrontID", ptrCfd_pQuote->FrontID);
            js_pQuote.Set("SessionID", ptrCfd_pQuote->SessionID);
            js_pQuote.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->UserProductInfo, strlen(ptrCfd_pQuote->UserProductInfo)) );
            js_pQuote.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->StatusMsg, strlen(ptrCfd_pQuote->StatusMsg)) );
            js_pQuote.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ActiveUserID, strlen(ptrCfd_pQuote->ActiveUserID)) );
            js_pQuote.Set("BrokerQuoteSeq", ptrCfd_pQuote->BrokerQuoteSeq);
            js_pQuote.Set("AskOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->AskOrderRef, strlen(ptrCfd_pQuote->AskOrderRef)) );
            js_pQuote.Set("BidOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BidOrderRef, strlen(ptrCfd_pQuote->BidOrderRef)) );
            js_pQuote.Set("ForQuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ForQuoteSysID, strlen(ptrCfd_pQuote->ForQuoteSysID)) );
            js_pQuote.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->BranchID, strlen(ptrCfd_pQuote->BranchID)) );
            js_pQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InvestUnitID, strlen(ptrCfd_pQuote->InvestUnitID)) );
            js_pQuote.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->AccountID, strlen(ptrCfd_pQuote->AccountID)) );
            js_pQuote.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->CurrencyID, strlen(ptrCfd_pQuote->CurrencyID)) );
            js_pQuote.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->reserve3, strlen(ptrCfd_pQuote->reserve3)) );
            js_pQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->MacAddress, strlen(ptrCfd_pQuote->MacAddress)) );
            js_pQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->InstrumentID, strlen(ptrCfd_pQuote->InstrumentID)) );
            js_pQuote.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ExchangeInstID, strlen(ptrCfd_pQuote->ExchangeInstID)) );
            js_pQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->IPAddress, strlen(ptrCfd_pQuote->IPAddress)) );
            js_pQuote.Set("ReplaceSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuote->ReplaceSysID, strlen(ptrCfd_pQuote->ReplaceSysID)) );
            js_event_data.Set("pQuote", js_pQuote);
            delete ptrCfd_pQuote;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField * pInputQuote, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcInputQuoteField *ptrCfd_pInputQuote = new CThostFtdcInputQuoteField();
        if(pInputQuote)
        {
            memcpy(ptrCfd_pInputQuote, pInputQuote, sizeof(CThostFtdcInputQuoteField));
        }
        else
        {
            memset(ptrCfd_pInputQuote, 0, sizeof(CThostFtdcInputQuoteField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnQuoteInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputQuote = Napi::Object::New(env);
            js_pInputQuote.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->BrokerID, strlen(ptrCfd_pInputQuote->BrokerID)) );
            js_pInputQuote.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->InvestorID, strlen(ptrCfd_pInputQuote->InvestorID)) );
            js_pInputQuote.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->reserve1, strlen(ptrCfd_pInputQuote->reserve1)) );
            js_pInputQuote.Set("QuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->QuoteRef, strlen(ptrCfd_pInputQuote->QuoteRef)) );
            js_pInputQuote.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->UserID, strlen(ptrCfd_pInputQuote->UserID)) );
            js_pInputQuote.Set("AskPrice", ptrCfd_pInputQuote->AskPrice);
            js_pInputQuote.Set("BidPrice", ptrCfd_pInputQuote->BidPrice);
            js_pInputQuote.Set("AskVolume", ptrCfd_pInputQuote->AskVolume);
            js_pInputQuote.Set("BidVolume", ptrCfd_pInputQuote->BidVolume);
            js_pInputQuote.Set("RequestID", ptrCfd_pInputQuote->RequestID);
            js_pInputQuote.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->BusinessUnit, strlen(ptrCfd_pInputQuote->BusinessUnit)) );
            js_pInputQuote.Set("AskOffsetFlag", string(1u, ptrCfd_pInputQuote->AskOffsetFlag).c_str());
            js_pInputQuote.Set("BidOffsetFlag", string(1u, ptrCfd_pInputQuote->BidOffsetFlag).c_str());
            js_pInputQuote.Set("AskHedgeFlag", string(1u, ptrCfd_pInputQuote->AskHedgeFlag).c_str());
            js_pInputQuote.Set("BidHedgeFlag", string(1u, ptrCfd_pInputQuote->BidHedgeFlag).c_str());
            js_pInputQuote.Set("AskOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->AskOrderRef, strlen(ptrCfd_pInputQuote->AskOrderRef)) );
            js_pInputQuote.Set("BidOrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->BidOrderRef, strlen(ptrCfd_pInputQuote->BidOrderRef)) );
            js_pInputQuote.Set("ForQuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ForQuoteSysID, strlen(ptrCfd_pInputQuote->ForQuoteSysID)) );
            js_pInputQuote.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ExchangeID, strlen(ptrCfd_pInputQuote->ExchangeID)) );
            js_pInputQuote.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->InvestUnitID, strlen(ptrCfd_pInputQuote->InvestUnitID)) );
            js_pInputQuote.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ClientID, strlen(ptrCfd_pInputQuote->ClientID)) );
            js_pInputQuote.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->reserve2, strlen(ptrCfd_pInputQuote->reserve2)) );
            js_pInputQuote.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->MacAddress, strlen(ptrCfd_pInputQuote->MacAddress)) );
            js_pInputQuote.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->InstrumentID, strlen(ptrCfd_pInputQuote->InstrumentID)) );
            js_pInputQuote.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->IPAddress, strlen(ptrCfd_pInputQuote->IPAddress)) );
            js_pInputQuote.Set("ReplaceSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputQuote->ReplaceSysID, strlen(ptrCfd_pInputQuote->ReplaceSysID)) );
            js_event_data.Set("pInputQuote", js_pInputQuote);
            delete ptrCfd_pInputQuote;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnQuoteAction(CThostFtdcQuoteActionField * pQuoteAction, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcQuoteActionField *ptrCfd_pQuoteAction = new CThostFtdcQuoteActionField();
        if(pQuoteAction)
        {
            memcpy(ptrCfd_pQuoteAction, pQuoteAction, sizeof(CThostFtdcQuoteActionField));
        }
        else
        {
            memset(ptrCfd_pQuoteAction, 0, sizeof(CThostFtdcQuoteActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnQuoteAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pQuoteAction = Napi::Object::New(env);
            js_pQuoteAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->BrokerID, strlen(ptrCfd_pQuoteAction->BrokerID)) );
            js_pQuoteAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->InvestorID, strlen(ptrCfd_pQuoteAction->InvestorID)) );
            js_pQuoteAction.Set("QuoteActionRef", ptrCfd_pQuoteAction->QuoteActionRef);
            js_pQuoteAction.Set("QuoteRef", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->QuoteRef, strlen(ptrCfd_pQuoteAction->QuoteRef)) );
            js_pQuoteAction.Set("RequestID", ptrCfd_pQuoteAction->RequestID);
            js_pQuoteAction.Set("FrontID", ptrCfd_pQuoteAction->FrontID);
            js_pQuoteAction.Set("SessionID", ptrCfd_pQuoteAction->SessionID);
            js_pQuoteAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->ExchangeID, strlen(ptrCfd_pQuoteAction->ExchangeID)) );
            js_pQuoteAction.Set("QuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->QuoteSysID, strlen(ptrCfd_pQuoteAction->QuoteSysID)) );
            js_pQuoteAction.Set("ActionFlag", string(1u, ptrCfd_pQuoteAction->ActionFlag).c_str());
            js_pQuoteAction.Set("ActionDate", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->ActionDate, strlen(ptrCfd_pQuoteAction->ActionDate)) );
            js_pQuoteAction.Set("ActionTime", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->ActionTime, strlen(ptrCfd_pQuoteAction->ActionTime)) );
            js_pQuoteAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->TraderID, strlen(ptrCfd_pQuoteAction->TraderID)) );
            js_pQuoteAction.Set("InstallID", ptrCfd_pQuoteAction->InstallID);
            js_pQuoteAction.Set("QuoteLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->QuoteLocalID, strlen(ptrCfd_pQuoteAction->QuoteLocalID)) );
            js_pQuoteAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->ActionLocalID, strlen(ptrCfd_pQuoteAction->ActionLocalID)) );
            js_pQuoteAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->ParticipantID, strlen(ptrCfd_pQuoteAction->ParticipantID)) );
            js_pQuoteAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->ClientID, strlen(ptrCfd_pQuoteAction->ClientID)) );
            js_pQuoteAction.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->BusinessUnit, strlen(ptrCfd_pQuoteAction->BusinessUnit)) );
            js_pQuoteAction.Set("OrderActionStatus", string(1u, ptrCfd_pQuoteAction->OrderActionStatus).c_str());
            js_pQuoteAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->UserID, strlen(ptrCfd_pQuoteAction->UserID)) );
            js_pQuoteAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->StatusMsg, strlen(ptrCfd_pQuoteAction->StatusMsg)) );
            js_pQuoteAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->reserve1, strlen(ptrCfd_pQuoteAction->reserve1)) );
            js_pQuoteAction.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->BranchID, strlen(ptrCfd_pQuoteAction->BranchID)) );
            js_pQuoteAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->InvestUnitID, strlen(ptrCfd_pQuoteAction->InvestUnitID)) );
            js_pQuoteAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->reserve2, strlen(ptrCfd_pQuoteAction->reserve2)) );
            js_pQuoteAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->MacAddress, strlen(ptrCfd_pQuoteAction->MacAddress)) );
            js_pQuoteAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->InstrumentID, strlen(ptrCfd_pQuoteAction->InstrumentID)) );
            js_pQuoteAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pQuoteAction->IPAddress, strlen(ptrCfd_pQuoteAction->IPAddress)) );
            js_event_data.Set("pQuoteAction", js_pQuoteAction);
            delete ptrCfd_pQuoteAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField * pForQuoteRsp)
    {
        
        CThostFtdcForQuoteRspField *ptrCfd_pForQuoteRsp = new CThostFtdcForQuoteRspField();
        if(pForQuoteRsp)
        {
            memcpy(ptrCfd_pForQuoteRsp, pForQuoteRsp, sizeof(CThostFtdcForQuoteRspField));
        }
        else
        {
            memset(ptrCfd_pForQuoteRsp, 0, sizeof(CThostFtdcForQuoteRspField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnForQuoteRsp");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pForQuoteRsp = Napi::Object::New(env);
            js_pForQuoteRsp.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->TradingDay, strlen(ptrCfd_pForQuoteRsp->TradingDay)) );
            js_pForQuoteRsp.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->reserve1, strlen(ptrCfd_pForQuoteRsp->reserve1)) );
            js_pForQuoteRsp.Set("ForQuoteSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->ForQuoteSysID, strlen(ptrCfd_pForQuoteRsp->ForQuoteSysID)) );
            js_pForQuoteRsp.Set("ForQuoteTime", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->ForQuoteTime, strlen(ptrCfd_pForQuoteRsp->ForQuoteTime)) );
            js_pForQuoteRsp.Set("ActionDay", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->ActionDay, strlen(ptrCfd_pForQuoteRsp->ActionDay)) );
            js_pForQuoteRsp.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->ExchangeID, strlen(ptrCfd_pForQuoteRsp->ExchangeID)) );
            js_pForQuoteRsp.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pForQuoteRsp->InstrumentID, strlen(ptrCfd_pForQuoteRsp->InstrumentID)) );
            js_event_data.Set("pForQuoteRsp", js_pForQuoteRsp);
            delete ptrCfd_pForQuoteRsp;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField * pCFMMCTradingAccountToken)
    {
        
        CThostFtdcCFMMCTradingAccountTokenField *ptrCfd_pCFMMCTradingAccountToken = new CThostFtdcCFMMCTradingAccountTokenField();
        if(pCFMMCTradingAccountToken)
        {
            memcpy(ptrCfd_pCFMMCTradingAccountToken, pCFMMCTradingAccountToken, sizeof(CThostFtdcCFMMCTradingAccountTokenField));
        }
        else
        {
            memset(ptrCfd_pCFMMCTradingAccountToken, 0, sizeof(CThostFtdcCFMMCTradingAccountTokenField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnCFMMCTradingAccountToken");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCFMMCTradingAccountToken = Napi::Object::New(env);
            js_pCFMMCTradingAccountToken.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountToken->BrokerID, strlen(ptrCfd_pCFMMCTradingAccountToken->BrokerID)) );
            js_pCFMMCTradingAccountToken.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountToken->ParticipantID, strlen(ptrCfd_pCFMMCTradingAccountToken->ParticipantID)) );
            js_pCFMMCTradingAccountToken.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountToken->AccountID, strlen(ptrCfd_pCFMMCTradingAccountToken->AccountID)) );
            js_pCFMMCTradingAccountToken.Set("KeyID", ptrCfd_pCFMMCTradingAccountToken->KeyID);
            js_pCFMMCTradingAccountToken.Set("Token", Napi::Buffer<char>::Copy(env, ptrCfd_pCFMMCTradingAccountToken->Token, strlen(ptrCfd_pCFMMCTradingAccountToken->Token)) );
            js_event_data.Set("pCFMMCTradingAccountToken", js_pCFMMCTradingAccountToken);
            delete ptrCfd_pCFMMCTradingAccountToken;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField * pBatchOrderAction, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcBatchOrderActionField *ptrCfd_pBatchOrderAction = new CThostFtdcBatchOrderActionField();
        if(pBatchOrderAction)
        {
            memcpy(ptrCfd_pBatchOrderAction, pBatchOrderAction, sizeof(CThostFtdcBatchOrderActionField));
        }
        else
        {
            memset(ptrCfd_pBatchOrderAction, 0, sizeof(CThostFtdcBatchOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnBatchOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pBatchOrderAction = Napi::Object::New(env);
            js_pBatchOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->BrokerID, strlen(ptrCfd_pBatchOrderAction->BrokerID)) );
            js_pBatchOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->InvestorID, strlen(ptrCfd_pBatchOrderAction->InvestorID)) );
            js_pBatchOrderAction.Set("OrderActionRef", ptrCfd_pBatchOrderAction->OrderActionRef);
            js_pBatchOrderAction.Set("RequestID", ptrCfd_pBatchOrderAction->RequestID);
            js_pBatchOrderAction.Set("FrontID", ptrCfd_pBatchOrderAction->FrontID);
            js_pBatchOrderAction.Set("SessionID", ptrCfd_pBatchOrderAction->SessionID);
            js_pBatchOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->ExchangeID, strlen(ptrCfd_pBatchOrderAction->ExchangeID)) );
            js_pBatchOrderAction.Set("ActionDate", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->ActionDate, strlen(ptrCfd_pBatchOrderAction->ActionDate)) );
            js_pBatchOrderAction.Set("ActionTime", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->ActionTime, strlen(ptrCfd_pBatchOrderAction->ActionTime)) );
            js_pBatchOrderAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->TraderID, strlen(ptrCfd_pBatchOrderAction->TraderID)) );
            js_pBatchOrderAction.Set("InstallID", ptrCfd_pBatchOrderAction->InstallID);
            js_pBatchOrderAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->ActionLocalID, strlen(ptrCfd_pBatchOrderAction->ActionLocalID)) );
            js_pBatchOrderAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->ParticipantID, strlen(ptrCfd_pBatchOrderAction->ParticipantID)) );
            js_pBatchOrderAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->ClientID, strlen(ptrCfd_pBatchOrderAction->ClientID)) );
            js_pBatchOrderAction.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->BusinessUnit, strlen(ptrCfd_pBatchOrderAction->BusinessUnit)) );
            js_pBatchOrderAction.Set("OrderActionStatus", string(1u, ptrCfd_pBatchOrderAction->OrderActionStatus).c_str());
            js_pBatchOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->UserID, strlen(ptrCfd_pBatchOrderAction->UserID)) );
            js_pBatchOrderAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->StatusMsg, strlen(ptrCfd_pBatchOrderAction->StatusMsg)) );
            js_pBatchOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->InvestUnitID, strlen(ptrCfd_pBatchOrderAction->InvestUnitID)) );
            js_pBatchOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->reserve1, strlen(ptrCfd_pBatchOrderAction->reserve1)) );
            js_pBatchOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->MacAddress, strlen(ptrCfd_pBatchOrderAction->MacAddress)) );
            js_pBatchOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pBatchOrderAction->IPAddress, strlen(ptrCfd_pBatchOrderAction->IPAddress)) );
            js_event_data.Set("pBatchOrderAction", js_pBatchOrderAction);
            delete ptrCfd_pBatchOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField * pOptionSelfClose)
    {
        
        CThostFtdcOptionSelfCloseField *ptrCfd_pOptionSelfClose = new CThostFtdcOptionSelfCloseField();
        if(pOptionSelfClose)
        {
            memcpy(ptrCfd_pOptionSelfClose, pOptionSelfClose, sizeof(CThostFtdcOptionSelfCloseField));
        }
        else
        {
            memset(ptrCfd_pOptionSelfClose, 0, sizeof(CThostFtdcOptionSelfCloseField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnOptionSelfClose");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOptionSelfClose = Napi::Object::New(env);
            js_pOptionSelfClose.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->BrokerID, strlen(ptrCfd_pOptionSelfClose->BrokerID)) );
            js_pOptionSelfClose.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InvestorID, strlen(ptrCfd_pOptionSelfClose->InvestorID)) );
            js_pOptionSelfClose.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->reserve1, strlen(ptrCfd_pOptionSelfClose->reserve1)) );
            js_pOptionSelfClose.Set("OptionSelfCloseRef", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->OptionSelfCloseRef, strlen(ptrCfd_pOptionSelfClose->OptionSelfCloseRef)) );
            js_pOptionSelfClose.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->UserID, strlen(ptrCfd_pOptionSelfClose->UserID)) );
            js_pOptionSelfClose.Set("Volume", ptrCfd_pOptionSelfClose->Volume);
            js_pOptionSelfClose.Set("RequestID", ptrCfd_pOptionSelfClose->RequestID);
            js_pOptionSelfClose.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->BusinessUnit, strlen(ptrCfd_pOptionSelfClose->BusinessUnit)) );
            js_pOptionSelfClose.Set("HedgeFlag", string(1u, ptrCfd_pOptionSelfClose->HedgeFlag).c_str());
            js_pOptionSelfClose.Set("OptSelfCloseFlag", string(1u, ptrCfd_pOptionSelfClose->OptSelfCloseFlag).c_str());
            js_pOptionSelfClose.Set("OptionSelfCloseLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->OptionSelfCloseLocalID, strlen(ptrCfd_pOptionSelfClose->OptionSelfCloseLocalID)) );
            js_pOptionSelfClose.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ExchangeID, strlen(ptrCfd_pOptionSelfClose->ExchangeID)) );
            js_pOptionSelfClose.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ParticipantID, strlen(ptrCfd_pOptionSelfClose->ParticipantID)) );
            js_pOptionSelfClose.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ClientID, strlen(ptrCfd_pOptionSelfClose->ClientID)) );
            js_pOptionSelfClose.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->reserve2, strlen(ptrCfd_pOptionSelfClose->reserve2)) );
            js_pOptionSelfClose.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->TraderID, strlen(ptrCfd_pOptionSelfClose->TraderID)) );
            js_pOptionSelfClose.Set("InstallID", ptrCfd_pOptionSelfClose->InstallID);
            js_pOptionSelfClose.Set("OrderSubmitStatus", string(1u, ptrCfd_pOptionSelfClose->OrderSubmitStatus).c_str());
            js_pOptionSelfClose.Set("NotifySequence", ptrCfd_pOptionSelfClose->NotifySequence);
            js_pOptionSelfClose.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->TradingDay, strlen(ptrCfd_pOptionSelfClose->TradingDay)) );
            js_pOptionSelfClose.Set("SettlementID", ptrCfd_pOptionSelfClose->SettlementID);
            js_pOptionSelfClose.Set("OptionSelfCloseSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->OptionSelfCloseSysID, strlen(ptrCfd_pOptionSelfClose->OptionSelfCloseSysID)) );
            js_pOptionSelfClose.Set("InsertDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InsertDate, strlen(ptrCfd_pOptionSelfClose->InsertDate)) );
            js_pOptionSelfClose.Set("InsertTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InsertTime, strlen(ptrCfd_pOptionSelfClose->InsertTime)) );
            js_pOptionSelfClose.Set("CancelTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->CancelTime, strlen(ptrCfd_pOptionSelfClose->CancelTime)) );
            js_pOptionSelfClose.Set("ExecResult", string(1u, ptrCfd_pOptionSelfClose->ExecResult).c_str());
            js_pOptionSelfClose.Set("ClearingPartID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ClearingPartID, strlen(ptrCfd_pOptionSelfClose->ClearingPartID)) );
            js_pOptionSelfClose.Set("SequenceNo", ptrCfd_pOptionSelfClose->SequenceNo);
            js_pOptionSelfClose.Set("FrontID", ptrCfd_pOptionSelfClose->FrontID);
            js_pOptionSelfClose.Set("SessionID", ptrCfd_pOptionSelfClose->SessionID);
            js_pOptionSelfClose.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->UserProductInfo, strlen(ptrCfd_pOptionSelfClose->UserProductInfo)) );
            js_pOptionSelfClose.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->StatusMsg, strlen(ptrCfd_pOptionSelfClose->StatusMsg)) );
            js_pOptionSelfClose.Set("ActiveUserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ActiveUserID, strlen(ptrCfd_pOptionSelfClose->ActiveUserID)) );
            js_pOptionSelfClose.Set("BrokerOptionSelfCloseSeq", ptrCfd_pOptionSelfClose->BrokerOptionSelfCloseSeq);
            js_pOptionSelfClose.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->BranchID, strlen(ptrCfd_pOptionSelfClose->BranchID)) );
            js_pOptionSelfClose.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InvestUnitID, strlen(ptrCfd_pOptionSelfClose->InvestUnitID)) );
            js_pOptionSelfClose.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->AccountID, strlen(ptrCfd_pOptionSelfClose->AccountID)) );
            js_pOptionSelfClose.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->CurrencyID, strlen(ptrCfd_pOptionSelfClose->CurrencyID)) );
            js_pOptionSelfClose.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->reserve3, strlen(ptrCfd_pOptionSelfClose->reserve3)) );
            js_pOptionSelfClose.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->MacAddress, strlen(ptrCfd_pOptionSelfClose->MacAddress)) );
            js_pOptionSelfClose.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->InstrumentID, strlen(ptrCfd_pOptionSelfClose->InstrumentID)) );
            js_pOptionSelfClose.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->ExchangeInstID, strlen(ptrCfd_pOptionSelfClose->ExchangeInstID)) );
            js_pOptionSelfClose.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfClose->IPAddress, strlen(ptrCfd_pOptionSelfClose->IPAddress)) );
            js_event_data.Set("pOptionSelfClose", js_pOptionSelfClose);
            delete ptrCfd_pOptionSelfClose;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcInputOptionSelfCloseField *ptrCfd_pInputOptionSelfClose = new CThostFtdcInputOptionSelfCloseField();
        if(pInputOptionSelfClose)
        {
            memcpy(ptrCfd_pInputOptionSelfClose, pInputOptionSelfClose, sizeof(CThostFtdcInputOptionSelfCloseField));
        }
        else
        {
            memset(ptrCfd_pInputOptionSelfClose, 0, sizeof(CThostFtdcInputOptionSelfCloseField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnOptionSelfCloseInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputOptionSelfClose = Napi::Object::New(env);
            js_pInputOptionSelfClose.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->BrokerID, strlen(ptrCfd_pInputOptionSelfClose->BrokerID)) );
            js_pInputOptionSelfClose.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->InvestorID, strlen(ptrCfd_pInputOptionSelfClose->InvestorID)) );
            js_pInputOptionSelfClose.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->reserve1, strlen(ptrCfd_pInputOptionSelfClose->reserve1)) );
            js_pInputOptionSelfClose.Set("OptionSelfCloseRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->OptionSelfCloseRef, strlen(ptrCfd_pInputOptionSelfClose->OptionSelfCloseRef)) );
            js_pInputOptionSelfClose.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->UserID, strlen(ptrCfd_pInputOptionSelfClose->UserID)) );
            js_pInputOptionSelfClose.Set("Volume", ptrCfd_pInputOptionSelfClose->Volume);
            js_pInputOptionSelfClose.Set("RequestID", ptrCfd_pInputOptionSelfClose->RequestID);
            js_pInputOptionSelfClose.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->BusinessUnit, strlen(ptrCfd_pInputOptionSelfClose->BusinessUnit)) );
            js_pInputOptionSelfClose.Set("HedgeFlag", string(1u, ptrCfd_pInputOptionSelfClose->HedgeFlag).c_str());
            js_pInputOptionSelfClose.Set("OptSelfCloseFlag", string(1u, ptrCfd_pInputOptionSelfClose->OptSelfCloseFlag).c_str());
            js_pInputOptionSelfClose.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->ExchangeID, strlen(ptrCfd_pInputOptionSelfClose->ExchangeID)) );
            js_pInputOptionSelfClose.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->InvestUnitID, strlen(ptrCfd_pInputOptionSelfClose->InvestUnitID)) );
            js_pInputOptionSelfClose.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->AccountID, strlen(ptrCfd_pInputOptionSelfClose->AccountID)) );
            js_pInputOptionSelfClose.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->CurrencyID, strlen(ptrCfd_pInputOptionSelfClose->CurrencyID)) );
            js_pInputOptionSelfClose.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->ClientID, strlen(ptrCfd_pInputOptionSelfClose->ClientID)) );
            js_pInputOptionSelfClose.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->reserve2, strlen(ptrCfd_pInputOptionSelfClose->reserve2)) );
            js_pInputOptionSelfClose.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->MacAddress, strlen(ptrCfd_pInputOptionSelfClose->MacAddress)) );
            js_pInputOptionSelfClose.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->InstrumentID, strlen(ptrCfd_pInputOptionSelfClose->InstrumentID)) );
            js_pInputOptionSelfClose.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputOptionSelfClose->IPAddress, strlen(ptrCfd_pInputOptionSelfClose->IPAddress)) );
            js_event_data.Set("pInputOptionSelfClose", js_pInputOptionSelfClose);
            delete ptrCfd_pInputOptionSelfClose;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField * pOptionSelfCloseAction, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcOptionSelfCloseActionField *ptrCfd_pOptionSelfCloseAction = new CThostFtdcOptionSelfCloseActionField();
        if(pOptionSelfCloseAction)
        {
            memcpy(ptrCfd_pOptionSelfCloseAction, pOptionSelfCloseAction, sizeof(CThostFtdcOptionSelfCloseActionField));
        }
        else
        {
            memset(ptrCfd_pOptionSelfCloseAction, 0, sizeof(CThostFtdcOptionSelfCloseActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnOptionSelfCloseAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOptionSelfCloseAction = Napi::Object::New(env);
            js_pOptionSelfCloseAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->BrokerID, strlen(ptrCfd_pOptionSelfCloseAction->BrokerID)) );
            js_pOptionSelfCloseAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->InvestorID, strlen(ptrCfd_pOptionSelfCloseAction->InvestorID)) );
            js_pOptionSelfCloseAction.Set("OptionSelfCloseActionRef", ptrCfd_pOptionSelfCloseAction->OptionSelfCloseActionRef);
            js_pOptionSelfCloseAction.Set("OptionSelfCloseRef", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->OptionSelfCloseRef, strlen(ptrCfd_pOptionSelfCloseAction->OptionSelfCloseRef)) );
            js_pOptionSelfCloseAction.Set("RequestID", ptrCfd_pOptionSelfCloseAction->RequestID);
            js_pOptionSelfCloseAction.Set("FrontID", ptrCfd_pOptionSelfCloseAction->FrontID);
            js_pOptionSelfCloseAction.Set("SessionID", ptrCfd_pOptionSelfCloseAction->SessionID);
            js_pOptionSelfCloseAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->ExchangeID, strlen(ptrCfd_pOptionSelfCloseAction->ExchangeID)) );
            js_pOptionSelfCloseAction.Set("OptionSelfCloseSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->OptionSelfCloseSysID, strlen(ptrCfd_pOptionSelfCloseAction->OptionSelfCloseSysID)) );
            js_pOptionSelfCloseAction.Set("ActionFlag", string(1u, ptrCfd_pOptionSelfCloseAction->ActionFlag).c_str());
            js_pOptionSelfCloseAction.Set("ActionDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->ActionDate, strlen(ptrCfd_pOptionSelfCloseAction->ActionDate)) );
            js_pOptionSelfCloseAction.Set("ActionTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->ActionTime, strlen(ptrCfd_pOptionSelfCloseAction->ActionTime)) );
            js_pOptionSelfCloseAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->TraderID, strlen(ptrCfd_pOptionSelfCloseAction->TraderID)) );
            js_pOptionSelfCloseAction.Set("InstallID", ptrCfd_pOptionSelfCloseAction->InstallID);
            js_pOptionSelfCloseAction.Set("OptionSelfCloseLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->OptionSelfCloseLocalID, strlen(ptrCfd_pOptionSelfCloseAction->OptionSelfCloseLocalID)) );
            js_pOptionSelfCloseAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->ActionLocalID, strlen(ptrCfd_pOptionSelfCloseAction->ActionLocalID)) );
            js_pOptionSelfCloseAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->ParticipantID, strlen(ptrCfd_pOptionSelfCloseAction->ParticipantID)) );
            js_pOptionSelfCloseAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->ClientID, strlen(ptrCfd_pOptionSelfCloseAction->ClientID)) );
            js_pOptionSelfCloseAction.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->BusinessUnit, strlen(ptrCfd_pOptionSelfCloseAction->BusinessUnit)) );
            js_pOptionSelfCloseAction.Set("OrderActionStatus", string(1u, ptrCfd_pOptionSelfCloseAction->OrderActionStatus).c_str());
            js_pOptionSelfCloseAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->UserID, strlen(ptrCfd_pOptionSelfCloseAction->UserID)) );
            js_pOptionSelfCloseAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->StatusMsg, strlen(ptrCfd_pOptionSelfCloseAction->StatusMsg)) );
            js_pOptionSelfCloseAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->reserve1, strlen(ptrCfd_pOptionSelfCloseAction->reserve1)) );
            js_pOptionSelfCloseAction.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->BranchID, strlen(ptrCfd_pOptionSelfCloseAction->BranchID)) );
            js_pOptionSelfCloseAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->InvestUnitID, strlen(ptrCfd_pOptionSelfCloseAction->InvestUnitID)) );
            js_pOptionSelfCloseAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->reserve2, strlen(ptrCfd_pOptionSelfCloseAction->reserve2)) );
            js_pOptionSelfCloseAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->MacAddress, strlen(ptrCfd_pOptionSelfCloseAction->MacAddress)) );
            js_pOptionSelfCloseAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->InstrumentID, strlen(ptrCfd_pOptionSelfCloseAction->InstrumentID)) );
            js_pOptionSelfCloseAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pOptionSelfCloseAction->IPAddress, strlen(ptrCfd_pOptionSelfCloseAction->IPAddress)) );
            js_event_data.Set("pOptionSelfCloseAction", js_pOptionSelfCloseAction);
            delete ptrCfd_pOptionSelfCloseAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnCombAction(CThostFtdcCombActionField * pCombAction)
    {
        
        CThostFtdcCombActionField *ptrCfd_pCombAction = new CThostFtdcCombActionField();
        if(pCombAction)
        {
            memcpy(ptrCfd_pCombAction, pCombAction, sizeof(CThostFtdcCombActionField));
        }
        else
        {
            memset(ptrCfd_pCombAction, 0, sizeof(CThostFtdcCombActionField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnCombAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCombAction = Napi::Object::New(env);
            js_pCombAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->BrokerID, strlen(ptrCfd_pCombAction->BrokerID)) );
            js_pCombAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->InvestorID, strlen(ptrCfd_pCombAction->InvestorID)) );
            js_pCombAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->reserve1, strlen(ptrCfd_pCombAction->reserve1)) );
            js_pCombAction.Set("CombActionRef", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->CombActionRef, strlen(ptrCfd_pCombAction->CombActionRef)) );
            js_pCombAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->UserID, strlen(ptrCfd_pCombAction->UserID)) );
            js_pCombAction.Set("Direction", string(1u, ptrCfd_pCombAction->Direction).c_str());
            js_pCombAction.Set("Volume", ptrCfd_pCombAction->Volume);
            js_pCombAction.Set("CombDirection", string(1u, ptrCfd_pCombAction->CombDirection).c_str());
            js_pCombAction.Set("HedgeFlag", string(1u, ptrCfd_pCombAction->HedgeFlag).c_str());
            js_pCombAction.Set("ActionLocalID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ActionLocalID, strlen(ptrCfd_pCombAction->ActionLocalID)) );
            js_pCombAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ExchangeID, strlen(ptrCfd_pCombAction->ExchangeID)) );
            js_pCombAction.Set("ParticipantID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ParticipantID, strlen(ptrCfd_pCombAction->ParticipantID)) );
            js_pCombAction.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ClientID, strlen(ptrCfd_pCombAction->ClientID)) );
            js_pCombAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->reserve2, strlen(ptrCfd_pCombAction->reserve2)) );
            js_pCombAction.Set("TraderID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->TraderID, strlen(ptrCfd_pCombAction->TraderID)) );
            js_pCombAction.Set("InstallID", ptrCfd_pCombAction->InstallID);
            js_pCombAction.Set("ActionStatus", string(1u, ptrCfd_pCombAction->ActionStatus).c_str());
            js_pCombAction.Set("NotifySequence", ptrCfd_pCombAction->NotifySequence);
            js_pCombAction.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->TradingDay, strlen(ptrCfd_pCombAction->TradingDay)) );
            js_pCombAction.Set("SettlementID", ptrCfd_pCombAction->SettlementID);
            js_pCombAction.Set("SequenceNo", ptrCfd_pCombAction->SequenceNo);
            js_pCombAction.Set("FrontID", ptrCfd_pCombAction->FrontID);
            js_pCombAction.Set("SessionID", ptrCfd_pCombAction->SessionID);
            js_pCombAction.Set("UserProductInfo", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->UserProductInfo, strlen(ptrCfd_pCombAction->UserProductInfo)) );
            js_pCombAction.Set("StatusMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->StatusMsg, strlen(ptrCfd_pCombAction->StatusMsg)) );
            js_pCombAction.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->reserve3, strlen(ptrCfd_pCombAction->reserve3)) );
            js_pCombAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->MacAddress, strlen(ptrCfd_pCombAction->MacAddress)) );
            js_pCombAction.Set("ComTradeID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ComTradeID, strlen(ptrCfd_pCombAction->ComTradeID)) );
            js_pCombAction.Set("BranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->BranchID, strlen(ptrCfd_pCombAction->BranchID)) );
            js_pCombAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->InvestUnitID, strlen(ptrCfd_pCombAction->InvestUnitID)) );
            js_pCombAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->InstrumentID, strlen(ptrCfd_pCombAction->InstrumentID)) );
            js_pCombAction.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->ExchangeInstID, strlen(ptrCfd_pCombAction->ExchangeInstID)) );
            js_pCombAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pCombAction->IPAddress, strlen(ptrCfd_pCombAction->IPAddress)) );
            js_event_data.Set("pCombAction", js_pCombAction);
            delete ptrCfd_pCombAction;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField * pInputCombAction, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcInputCombActionField *ptrCfd_pInputCombAction = new CThostFtdcInputCombActionField();
        if(pInputCombAction)
        {
            memcpy(ptrCfd_pInputCombAction, pInputCombAction, sizeof(CThostFtdcInputCombActionField));
        }
        else
        {
            memset(ptrCfd_pInputCombAction, 0, sizeof(CThostFtdcInputCombActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnCombActionInsert");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInputCombAction = Napi::Object::New(env);
            js_pInputCombAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->BrokerID, strlen(ptrCfd_pInputCombAction->BrokerID)) );
            js_pInputCombAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->InvestorID, strlen(ptrCfd_pInputCombAction->InvestorID)) );
            js_pInputCombAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->reserve1, strlen(ptrCfd_pInputCombAction->reserve1)) );
            js_pInputCombAction.Set("CombActionRef", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->CombActionRef, strlen(ptrCfd_pInputCombAction->CombActionRef)) );
            js_pInputCombAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->UserID, strlen(ptrCfd_pInputCombAction->UserID)) );
            js_pInputCombAction.Set("Direction", string(1u, ptrCfd_pInputCombAction->Direction).c_str());
            js_pInputCombAction.Set("Volume", ptrCfd_pInputCombAction->Volume);
            js_pInputCombAction.Set("CombDirection", string(1u, ptrCfd_pInputCombAction->CombDirection).c_str());
            js_pInputCombAction.Set("HedgeFlag", string(1u, ptrCfd_pInputCombAction->HedgeFlag).c_str());
            js_pInputCombAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->ExchangeID, strlen(ptrCfd_pInputCombAction->ExchangeID)) );
            js_pInputCombAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->reserve2, strlen(ptrCfd_pInputCombAction->reserve2)) );
            js_pInputCombAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->MacAddress, strlen(ptrCfd_pInputCombAction->MacAddress)) );
            js_pInputCombAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->InvestUnitID, strlen(ptrCfd_pInputCombAction->InvestUnitID)) );
            js_pInputCombAction.Set("FrontID", ptrCfd_pInputCombAction->FrontID);
            js_pInputCombAction.Set("SessionID", ptrCfd_pInputCombAction->SessionID);
            js_pInputCombAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->InstrumentID, strlen(ptrCfd_pInputCombAction->InstrumentID)) );
            js_pInputCombAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pInputCombAction->IPAddress, strlen(ptrCfd_pInputCombAction->IPAddress)) );
            js_event_data.Set("pInputCombAction", js_pInputCombAction);
            delete ptrCfd_pInputCombAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryContractBank(CThostFtdcContractBankField * pContractBank, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcContractBankField *ptrCfd_pContractBank = new CThostFtdcContractBankField();
        if(pContractBank)
        {
            memcpy(ptrCfd_pContractBank, pContractBank, sizeof(CThostFtdcContractBankField));
        }
        else
        {
            memset(ptrCfd_pContractBank, 0, sizeof(CThostFtdcContractBankField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryContractBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pContractBank = Napi::Object::New(env);
            js_pContractBank.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pContractBank->BrokerID, strlen(ptrCfd_pContractBank->BrokerID)) );
            js_pContractBank.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pContractBank->BankID, strlen(ptrCfd_pContractBank->BankID)) );
            js_pContractBank.Set("BankBrchID", Napi::Buffer<char>::Copy(env, ptrCfd_pContractBank->BankBrchID, strlen(ptrCfd_pContractBank->BankBrchID)) );
            js_pContractBank.Set("BankName", Napi::Buffer<char>::Copy(env, ptrCfd_pContractBank->BankName, strlen(ptrCfd_pContractBank->BankName)) );
            js_event_data.Set("pContractBank", js_pContractBank);
            delete ptrCfd_pContractBank;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryParkedOrder(CThostFtdcParkedOrderField * pParkedOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcParkedOrderField *ptrCfd_pParkedOrder = new CThostFtdcParkedOrderField();
        if(pParkedOrder)
        {
            memcpy(ptrCfd_pParkedOrder, pParkedOrder, sizeof(CThostFtdcParkedOrderField));
        }
        else
        {
            memset(ptrCfd_pParkedOrder, 0, sizeof(CThostFtdcParkedOrderField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryParkedOrder");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pParkedOrder = Napi::Object::New(env);
            js_pParkedOrder.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->BrokerID, strlen(ptrCfd_pParkedOrder->BrokerID)) );
            js_pParkedOrder.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->InvestorID, strlen(ptrCfd_pParkedOrder->InvestorID)) );
            js_pParkedOrder.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->reserve1, strlen(ptrCfd_pParkedOrder->reserve1)) );
            js_pParkedOrder.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->OrderRef, strlen(ptrCfd_pParkedOrder->OrderRef)) );
            js_pParkedOrder.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->UserID, strlen(ptrCfd_pParkedOrder->UserID)) );
            js_pParkedOrder.Set("OrderPriceType", string(1u, ptrCfd_pParkedOrder->OrderPriceType).c_str());
            js_pParkedOrder.Set("Direction", string(1u, ptrCfd_pParkedOrder->Direction).c_str());
            js_pParkedOrder.Set("CombOffsetFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->CombOffsetFlag, strlen(ptrCfd_pParkedOrder->CombOffsetFlag)) );
            js_pParkedOrder.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->CombHedgeFlag, strlen(ptrCfd_pParkedOrder->CombHedgeFlag)) );
            js_pParkedOrder.Set("LimitPrice", ptrCfd_pParkedOrder->LimitPrice);
            js_pParkedOrder.Set("VolumeTotalOriginal", ptrCfd_pParkedOrder->VolumeTotalOriginal);
            js_pParkedOrder.Set("TimeCondition", string(1u, ptrCfd_pParkedOrder->TimeCondition).c_str());
            js_pParkedOrder.Set("GTDDate", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->GTDDate, strlen(ptrCfd_pParkedOrder->GTDDate)) );
            js_pParkedOrder.Set("VolumeCondition", string(1u, ptrCfd_pParkedOrder->VolumeCondition).c_str());
            js_pParkedOrder.Set("MinVolume", ptrCfd_pParkedOrder->MinVolume);
            js_pParkedOrder.Set("ContingentCondition", string(1u, ptrCfd_pParkedOrder->ContingentCondition).c_str());
            js_pParkedOrder.Set("StopPrice", ptrCfd_pParkedOrder->StopPrice);
            js_pParkedOrder.Set("ForceCloseReason", string(1u, ptrCfd_pParkedOrder->ForceCloseReason).c_str());
            js_pParkedOrder.Set("IsAutoSuspend", ptrCfd_pParkedOrder->IsAutoSuspend);
            js_pParkedOrder.Set("BusinessUnit", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->BusinessUnit, strlen(ptrCfd_pParkedOrder->BusinessUnit)) );
            js_pParkedOrder.Set("RequestID", ptrCfd_pParkedOrder->RequestID);
            js_pParkedOrder.Set("UserForceClose", ptrCfd_pParkedOrder->UserForceClose);
            js_pParkedOrder.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ExchangeID, strlen(ptrCfd_pParkedOrder->ExchangeID)) );
            js_pParkedOrder.Set("ParkedOrderID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ParkedOrderID, strlen(ptrCfd_pParkedOrder->ParkedOrderID)) );
            js_pParkedOrder.Set("UserType", string(1u, ptrCfd_pParkedOrder->UserType).c_str());
            js_pParkedOrder.Set("Status", string(1u, ptrCfd_pParkedOrder->Status).c_str());
            js_pParkedOrder.Set("ErrorID", ptrCfd_pParkedOrder->ErrorID);
            js_pParkedOrder.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ErrorMsg, strlen(ptrCfd_pParkedOrder->ErrorMsg)) );
            js_pParkedOrder.Set("IsSwapOrder", ptrCfd_pParkedOrder->IsSwapOrder);
            js_pParkedOrder.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->AccountID, strlen(ptrCfd_pParkedOrder->AccountID)) );
            js_pParkedOrder.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->CurrencyID, strlen(ptrCfd_pParkedOrder->CurrencyID)) );
            js_pParkedOrder.Set("ClientID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->ClientID, strlen(ptrCfd_pParkedOrder->ClientID)) );
            js_pParkedOrder.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->InvestUnitID, strlen(ptrCfd_pParkedOrder->InvestUnitID)) );
            js_pParkedOrder.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->reserve2, strlen(ptrCfd_pParkedOrder->reserve2)) );
            js_pParkedOrder.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->MacAddress, strlen(ptrCfd_pParkedOrder->MacAddress)) );
            js_pParkedOrder.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->InstrumentID, strlen(ptrCfd_pParkedOrder->InstrumentID)) );
            js_pParkedOrder.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrder->IPAddress, strlen(ptrCfd_pParkedOrder->IPAddress)) );
            js_event_data.Set("pParkedOrder", js_pParkedOrder);
            delete ptrCfd_pParkedOrder;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField * pParkedOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcParkedOrderActionField *ptrCfd_pParkedOrderAction = new CThostFtdcParkedOrderActionField();
        if(pParkedOrderAction)
        {
            memcpy(ptrCfd_pParkedOrderAction, pParkedOrderAction, sizeof(CThostFtdcParkedOrderActionField));
        }
        else
        {
            memset(ptrCfd_pParkedOrderAction, 0, sizeof(CThostFtdcParkedOrderActionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryParkedOrderAction");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pParkedOrderAction = Napi::Object::New(env);
            js_pParkedOrderAction.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->BrokerID, strlen(ptrCfd_pParkedOrderAction->BrokerID)) );
            js_pParkedOrderAction.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->InvestorID, strlen(ptrCfd_pParkedOrderAction->InvestorID)) );
            js_pParkedOrderAction.Set("OrderActionRef", ptrCfd_pParkedOrderAction->OrderActionRef);
            js_pParkedOrderAction.Set("OrderRef", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->OrderRef, strlen(ptrCfd_pParkedOrderAction->OrderRef)) );
            js_pParkedOrderAction.Set("RequestID", ptrCfd_pParkedOrderAction->RequestID);
            js_pParkedOrderAction.Set("FrontID", ptrCfd_pParkedOrderAction->FrontID);
            js_pParkedOrderAction.Set("SessionID", ptrCfd_pParkedOrderAction->SessionID);
            js_pParkedOrderAction.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->ExchangeID, strlen(ptrCfd_pParkedOrderAction->ExchangeID)) );
            js_pParkedOrderAction.Set("OrderSysID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->OrderSysID, strlen(ptrCfd_pParkedOrderAction->OrderSysID)) );
            js_pParkedOrderAction.Set("ActionFlag", string(1u, ptrCfd_pParkedOrderAction->ActionFlag).c_str());
            js_pParkedOrderAction.Set("LimitPrice", ptrCfd_pParkedOrderAction->LimitPrice);
            js_pParkedOrderAction.Set("VolumeChange", ptrCfd_pParkedOrderAction->VolumeChange);
            js_pParkedOrderAction.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->UserID, strlen(ptrCfd_pParkedOrderAction->UserID)) );
            js_pParkedOrderAction.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->reserve1, strlen(ptrCfd_pParkedOrderAction->reserve1)) );
            js_pParkedOrderAction.Set("ParkedOrderActionID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->ParkedOrderActionID, strlen(ptrCfd_pParkedOrderAction->ParkedOrderActionID)) );
            js_pParkedOrderAction.Set("UserType", string(1u, ptrCfd_pParkedOrderAction->UserType).c_str());
            js_pParkedOrderAction.Set("Status", string(1u, ptrCfd_pParkedOrderAction->Status).c_str());
            js_pParkedOrderAction.Set("ErrorID", ptrCfd_pParkedOrderAction->ErrorID);
            js_pParkedOrderAction.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->ErrorMsg, strlen(ptrCfd_pParkedOrderAction->ErrorMsg)) );
            js_pParkedOrderAction.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->InvestUnitID, strlen(ptrCfd_pParkedOrderAction->InvestUnitID)) );
            js_pParkedOrderAction.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->reserve2, strlen(ptrCfd_pParkedOrderAction->reserve2)) );
            js_pParkedOrderAction.Set("MacAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->MacAddress, strlen(ptrCfd_pParkedOrderAction->MacAddress)) );
            js_pParkedOrderAction.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->InstrumentID, strlen(ptrCfd_pParkedOrderAction->InstrumentID)) );
            js_pParkedOrderAction.Set("IPAddress", Napi::Buffer<char>::Copy(env, ptrCfd_pParkedOrderAction->IPAddress, strlen(ptrCfd_pParkedOrderAction->IPAddress)) );
            js_event_data.Set("pParkedOrderAction", js_pParkedOrderAction);
            delete ptrCfd_pParkedOrderAction;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryTradingNotice(CThostFtdcTradingNoticeField * pTradingNotice, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcTradingNoticeField *ptrCfd_pTradingNotice = new CThostFtdcTradingNoticeField();
        if(pTradingNotice)
        {
            memcpy(ptrCfd_pTradingNotice, pTradingNotice, sizeof(CThostFtdcTradingNoticeField));
        }
        else
        {
            memset(ptrCfd_pTradingNotice, 0, sizeof(CThostFtdcTradingNoticeField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryTradingNotice");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pTradingNotice = Napi::Object::New(env);
            js_pTradingNotice.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNotice->BrokerID, strlen(ptrCfd_pTradingNotice->BrokerID)) );
            js_pTradingNotice.Set("InvestorRange", string(1u, ptrCfd_pTradingNotice->InvestorRange).c_str());
            js_pTradingNotice.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNotice->InvestorID, strlen(ptrCfd_pTradingNotice->InvestorID)) );
            js_pTradingNotice.Set("SequenceSeries", ptrCfd_pTradingNotice->SequenceSeries);
            js_pTradingNotice.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNotice->UserID, strlen(ptrCfd_pTradingNotice->UserID)) );
            js_pTradingNotice.Set("SendTime", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNotice->SendTime, strlen(ptrCfd_pTradingNotice->SendTime)) );
            js_pTradingNotice.Set("SequenceNo", ptrCfd_pTradingNotice->SequenceNo);
            js_pTradingNotice.Set("FieldContent", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNotice->FieldContent, strlen(ptrCfd_pTradingNotice->FieldContent)) );
            js_pTradingNotice.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pTradingNotice->InvestUnitID, strlen(ptrCfd_pTradingNotice->InvestUnitID)) );
            js_event_data.Set("pTradingNotice", js_pTradingNotice);
            delete ptrCfd_pTradingNotice;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField * pBrokerTradingParams, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcBrokerTradingParamsField *ptrCfd_pBrokerTradingParams = new CThostFtdcBrokerTradingParamsField();
        if(pBrokerTradingParams)
        {
            memcpy(ptrCfd_pBrokerTradingParams, pBrokerTradingParams, sizeof(CThostFtdcBrokerTradingParamsField));
        }
        else
        {
            memset(ptrCfd_pBrokerTradingParams, 0, sizeof(CThostFtdcBrokerTradingParamsField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryBrokerTradingParams");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pBrokerTradingParams = Napi::Object::New(env);
            js_pBrokerTradingParams.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingParams->BrokerID, strlen(ptrCfd_pBrokerTradingParams->BrokerID)) );
            js_pBrokerTradingParams.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingParams->InvestorID, strlen(ptrCfd_pBrokerTradingParams->InvestorID)) );
            js_pBrokerTradingParams.Set("MarginPriceType", string(1u, ptrCfd_pBrokerTradingParams->MarginPriceType).c_str());
            js_pBrokerTradingParams.Set("Algorithm", string(1u, ptrCfd_pBrokerTradingParams->Algorithm).c_str());
            js_pBrokerTradingParams.Set("AvailIncludeCloseProfit", string(1u, ptrCfd_pBrokerTradingParams->AvailIncludeCloseProfit).c_str());
            js_pBrokerTradingParams.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingParams->CurrencyID, strlen(ptrCfd_pBrokerTradingParams->CurrencyID)) );
            js_pBrokerTradingParams.Set("OptionRoyaltyPriceType", string(1u, ptrCfd_pBrokerTradingParams->OptionRoyaltyPriceType).c_str());
            js_pBrokerTradingParams.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingParams->AccountID, strlen(ptrCfd_pBrokerTradingParams->AccountID)) );
            js_event_data.Set("pBrokerTradingParams", js_pBrokerTradingParams);
            delete ptrCfd_pBrokerTradingParams;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField * pBrokerTradingAlgos, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcBrokerTradingAlgosField *ptrCfd_pBrokerTradingAlgos = new CThostFtdcBrokerTradingAlgosField();
        if(pBrokerTradingAlgos)
        {
            memcpy(ptrCfd_pBrokerTradingAlgos, pBrokerTradingAlgos, sizeof(CThostFtdcBrokerTradingAlgosField));
        }
        else
        {
            memset(ptrCfd_pBrokerTradingAlgos, 0, sizeof(CThostFtdcBrokerTradingAlgosField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryBrokerTradingAlgos");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pBrokerTradingAlgos = Napi::Object::New(env);
            js_pBrokerTradingAlgos.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingAlgos->BrokerID, strlen(ptrCfd_pBrokerTradingAlgos->BrokerID)) );
            js_pBrokerTradingAlgos.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingAlgos->ExchangeID, strlen(ptrCfd_pBrokerTradingAlgos->ExchangeID)) );
            js_pBrokerTradingAlgos.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingAlgos->reserve1, strlen(ptrCfd_pBrokerTradingAlgos->reserve1)) );
            js_pBrokerTradingAlgos.Set("HandlePositionAlgoID", string(1u, ptrCfd_pBrokerTradingAlgos->HandlePositionAlgoID).c_str());
            js_pBrokerTradingAlgos.Set("FindMarginRateAlgoID", string(1u, ptrCfd_pBrokerTradingAlgos->FindMarginRateAlgoID).c_str());
            js_pBrokerTradingAlgos.Set("HandleTradingAccountAlgoID", string(1u, ptrCfd_pBrokerTradingAlgos->HandleTradingAccountAlgoID).c_str());
            js_pBrokerTradingAlgos.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pBrokerTradingAlgos->InstrumentID, strlen(ptrCfd_pBrokerTradingAlgos->InstrumentID)) );
            js_event_data.Set("pBrokerTradingAlgos", js_pBrokerTradingAlgos);
            delete ptrCfd_pBrokerTradingAlgos;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField * pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcQueryCFMMCTradingAccountTokenField *ptrCfd_pQueryCFMMCTradingAccountToken = new CThostFtdcQueryCFMMCTradingAccountTokenField();
        if(pQueryCFMMCTradingAccountToken)
        {
            memcpy(ptrCfd_pQueryCFMMCTradingAccountToken, pQueryCFMMCTradingAccountToken, sizeof(CThostFtdcQueryCFMMCTradingAccountTokenField));
        }
        else
        {
            memset(ptrCfd_pQueryCFMMCTradingAccountToken, 0, sizeof(CThostFtdcQueryCFMMCTradingAccountTokenField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQueryCFMMCTradingAccountToken");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pQueryCFMMCTradingAccountToken = Napi::Object::New(env);
            js_pQueryCFMMCTradingAccountToken.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pQueryCFMMCTradingAccountToken->BrokerID, strlen(ptrCfd_pQueryCFMMCTradingAccountToken->BrokerID)) );
            js_pQueryCFMMCTradingAccountToken.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pQueryCFMMCTradingAccountToken->InvestorID, strlen(ptrCfd_pQueryCFMMCTradingAccountToken->InvestorID)) );
            js_pQueryCFMMCTradingAccountToken.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pQueryCFMMCTradingAccountToken->InvestUnitID, strlen(ptrCfd_pQueryCFMMCTradingAccountToken->InvestUnitID)) );
            js_event_data.Set("pQueryCFMMCTradingAccountToken", js_pQueryCFMMCTradingAccountToken);
            delete ptrCfd_pQueryCFMMCTradingAccountToken;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField * pRspTransfer)
    {
        
        CThostFtdcRspTransferField *ptrCfd_pRspTransfer = new CThostFtdcRspTransferField();
        if(pRspTransfer)
        {
            memcpy(ptrCfd_pRspTransfer, pRspTransfer, sizeof(CThostFtdcRspTransferField));
        }
        else
        {
            memset(ptrCfd_pRspTransfer, 0, sizeof(CThostFtdcRspTransferField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnFromBankToFutureByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspTransfer = Napi::Object::New(env);
            js_pRspTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeCode, strlen(ptrCfd_pRspTransfer->TradeCode)) );
            js_pRspTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankID, strlen(ptrCfd_pRspTransfer->BankID)) );
            js_pRspTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankBranchID, strlen(ptrCfd_pRspTransfer->BankBranchID)) );
            js_pRspTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerID, strlen(ptrCfd_pRspTransfer->BrokerID)) );
            js_pRspTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerBranchID, strlen(ptrCfd_pRspTransfer->BrokerBranchID)) );
            js_pRspTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeDate, strlen(ptrCfd_pRspTransfer->TradeDate)) );
            js_pRspTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeTime, strlen(ptrCfd_pRspTransfer->TradeTime)) );
            js_pRspTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSerial, strlen(ptrCfd_pRspTransfer->BankSerial)) );
            js_pRspTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradingDay, strlen(ptrCfd_pRspTransfer->TradingDay)) );
            js_pRspTransfer.Set("PlateSerial", ptrCfd_pRspTransfer->PlateSerial);
            js_pRspTransfer.Set("LastFragment", string(1u, ptrCfd_pRspTransfer->LastFragment).c_str());
            js_pRspTransfer.Set("SessionID", ptrCfd_pRspTransfer->SessionID);
            js_pRspTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CustomerName, strlen(ptrCfd_pRspTransfer->CustomerName)) );
            js_pRspTransfer.Set("IdCardType", string(1u, ptrCfd_pRspTransfer->IdCardType).c_str());
            js_pRspTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->IdentifiedCardNo, strlen(ptrCfd_pRspTransfer->IdentifiedCardNo)) );
            js_pRspTransfer.Set("CustType", string(1u, ptrCfd_pRspTransfer->CustType).c_str());
            js_pRspTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankAccount, strlen(ptrCfd_pRspTransfer->BankAccount)) );
            js_pRspTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankPassWord, strlen(ptrCfd_pRspTransfer->BankPassWord)) );
            js_pRspTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->AccountID, strlen(ptrCfd_pRspTransfer->AccountID)) );
            js_pRspTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Password, strlen(ptrCfd_pRspTransfer->Password)) );
            js_pRspTransfer.Set("InstallID", ptrCfd_pRspTransfer->InstallID);
            js_pRspTransfer.Set("FutureSerial", ptrCfd_pRspTransfer->FutureSerial);
            js_pRspTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->UserID, strlen(ptrCfd_pRspTransfer->UserID)) );
            js_pRspTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspTransfer->VerifyCertNoFlag).c_str());
            js_pRspTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CurrencyID, strlen(ptrCfd_pRspTransfer->CurrencyID)) );
            js_pRspTransfer.Set("TradeAmount", ptrCfd_pRspTransfer->TradeAmount);
            js_pRspTransfer.Set("FutureFetchAmount", ptrCfd_pRspTransfer->FutureFetchAmount);
            js_pRspTransfer.Set("FeePayFlag", string(1u, ptrCfd_pRspTransfer->FeePayFlag).c_str());
            js_pRspTransfer.Set("CustFee", ptrCfd_pRspTransfer->CustFee);
            js_pRspTransfer.Set("BrokerFee", ptrCfd_pRspTransfer->BrokerFee);
            js_pRspTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Message, strlen(ptrCfd_pRspTransfer->Message)) );
            js_pRspTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Digest, strlen(ptrCfd_pRspTransfer->Digest)) );
            js_pRspTransfer.Set("BankAccType", string(1u, ptrCfd_pRspTransfer->BankAccType).c_str());
            js_pRspTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->DeviceID, strlen(ptrCfd_pRspTransfer->DeviceID)) );
            js_pRspTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pRspTransfer->BankSecuAccType).c_str());
            js_pRspTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerIDByBank, strlen(ptrCfd_pRspTransfer->BrokerIDByBank)) );
            js_pRspTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSecuAcc, strlen(ptrCfd_pRspTransfer->BankSecuAcc)) );
            js_pRspTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pRspTransfer->BankPwdFlag).c_str());
            js_pRspTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pRspTransfer->SecuPwdFlag).c_str());
            js_pRspTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->OperNo, strlen(ptrCfd_pRspTransfer->OperNo)) );
            js_pRspTransfer.Set("RequestID", ptrCfd_pRspTransfer->RequestID);
            js_pRspTransfer.Set("TID", ptrCfd_pRspTransfer->TID);
            js_pRspTransfer.Set("TransferStatus", string(1u, ptrCfd_pRspTransfer->TransferStatus).c_str());
            js_pRspTransfer.Set("ErrorID", ptrCfd_pRspTransfer->ErrorID);
            js_pRspTransfer.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->ErrorMsg, strlen(ptrCfd_pRspTransfer->ErrorMsg)) );
            js_pRspTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->LongCustomerName, strlen(ptrCfd_pRspTransfer->LongCustomerName)) );
            js_event_data.Set("pRspTransfer", js_pRspTransfer);
            delete ptrCfd_pRspTransfer;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField * pRspTransfer)
    {
        
        CThostFtdcRspTransferField *ptrCfd_pRspTransfer = new CThostFtdcRspTransferField();
        if(pRspTransfer)
        {
            memcpy(ptrCfd_pRspTransfer, pRspTransfer, sizeof(CThostFtdcRspTransferField));
        }
        else
        {
            memset(ptrCfd_pRspTransfer, 0, sizeof(CThostFtdcRspTransferField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnFromFutureToBankByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspTransfer = Napi::Object::New(env);
            js_pRspTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeCode, strlen(ptrCfd_pRspTransfer->TradeCode)) );
            js_pRspTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankID, strlen(ptrCfd_pRspTransfer->BankID)) );
            js_pRspTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankBranchID, strlen(ptrCfd_pRspTransfer->BankBranchID)) );
            js_pRspTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerID, strlen(ptrCfd_pRspTransfer->BrokerID)) );
            js_pRspTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerBranchID, strlen(ptrCfd_pRspTransfer->BrokerBranchID)) );
            js_pRspTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeDate, strlen(ptrCfd_pRspTransfer->TradeDate)) );
            js_pRspTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeTime, strlen(ptrCfd_pRspTransfer->TradeTime)) );
            js_pRspTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSerial, strlen(ptrCfd_pRspTransfer->BankSerial)) );
            js_pRspTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradingDay, strlen(ptrCfd_pRspTransfer->TradingDay)) );
            js_pRspTransfer.Set("PlateSerial", ptrCfd_pRspTransfer->PlateSerial);
            js_pRspTransfer.Set("LastFragment", string(1u, ptrCfd_pRspTransfer->LastFragment).c_str());
            js_pRspTransfer.Set("SessionID", ptrCfd_pRspTransfer->SessionID);
            js_pRspTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CustomerName, strlen(ptrCfd_pRspTransfer->CustomerName)) );
            js_pRspTransfer.Set("IdCardType", string(1u, ptrCfd_pRspTransfer->IdCardType).c_str());
            js_pRspTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->IdentifiedCardNo, strlen(ptrCfd_pRspTransfer->IdentifiedCardNo)) );
            js_pRspTransfer.Set("CustType", string(1u, ptrCfd_pRspTransfer->CustType).c_str());
            js_pRspTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankAccount, strlen(ptrCfd_pRspTransfer->BankAccount)) );
            js_pRspTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankPassWord, strlen(ptrCfd_pRspTransfer->BankPassWord)) );
            js_pRspTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->AccountID, strlen(ptrCfd_pRspTransfer->AccountID)) );
            js_pRspTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Password, strlen(ptrCfd_pRspTransfer->Password)) );
            js_pRspTransfer.Set("InstallID", ptrCfd_pRspTransfer->InstallID);
            js_pRspTransfer.Set("FutureSerial", ptrCfd_pRspTransfer->FutureSerial);
            js_pRspTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->UserID, strlen(ptrCfd_pRspTransfer->UserID)) );
            js_pRspTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspTransfer->VerifyCertNoFlag).c_str());
            js_pRspTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CurrencyID, strlen(ptrCfd_pRspTransfer->CurrencyID)) );
            js_pRspTransfer.Set("TradeAmount", ptrCfd_pRspTransfer->TradeAmount);
            js_pRspTransfer.Set("FutureFetchAmount", ptrCfd_pRspTransfer->FutureFetchAmount);
            js_pRspTransfer.Set("FeePayFlag", string(1u, ptrCfd_pRspTransfer->FeePayFlag).c_str());
            js_pRspTransfer.Set("CustFee", ptrCfd_pRspTransfer->CustFee);
            js_pRspTransfer.Set("BrokerFee", ptrCfd_pRspTransfer->BrokerFee);
            js_pRspTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Message, strlen(ptrCfd_pRspTransfer->Message)) );
            js_pRspTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Digest, strlen(ptrCfd_pRspTransfer->Digest)) );
            js_pRspTransfer.Set("BankAccType", string(1u, ptrCfd_pRspTransfer->BankAccType).c_str());
            js_pRspTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->DeviceID, strlen(ptrCfd_pRspTransfer->DeviceID)) );
            js_pRspTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pRspTransfer->BankSecuAccType).c_str());
            js_pRspTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerIDByBank, strlen(ptrCfd_pRspTransfer->BrokerIDByBank)) );
            js_pRspTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSecuAcc, strlen(ptrCfd_pRspTransfer->BankSecuAcc)) );
            js_pRspTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pRspTransfer->BankPwdFlag).c_str());
            js_pRspTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pRspTransfer->SecuPwdFlag).c_str());
            js_pRspTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->OperNo, strlen(ptrCfd_pRspTransfer->OperNo)) );
            js_pRspTransfer.Set("RequestID", ptrCfd_pRspTransfer->RequestID);
            js_pRspTransfer.Set("TID", ptrCfd_pRspTransfer->TID);
            js_pRspTransfer.Set("TransferStatus", string(1u, ptrCfd_pRspTransfer->TransferStatus).c_str());
            js_pRspTransfer.Set("ErrorID", ptrCfd_pRspTransfer->ErrorID);
            js_pRspTransfer.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->ErrorMsg, strlen(ptrCfd_pRspTransfer->ErrorMsg)) );
            js_pRspTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->LongCustomerName, strlen(ptrCfd_pRspTransfer->LongCustomerName)) );
            js_event_data.Set("pRspTransfer", js_pRspTransfer);
            delete ptrCfd_pRspTransfer;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField * pRspRepeal)
    {
        
        CThostFtdcRspRepealField *ptrCfd_pRspRepeal = new CThostFtdcRspRepealField();
        if(pRspRepeal)
        {
            memcpy(ptrCfd_pRspRepeal, pRspRepeal, sizeof(CThostFtdcRspRepealField));
        }
        else
        {
            memset(ptrCfd_pRspRepeal, 0, sizeof(CThostFtdcRspRepealField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnRepealFromBankToFutureByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspRepeal = Napi::Object::New(env);
            js_pRspRepeal.Set("RepealTimeInterval", ptrCfd_pRspRepeal->RepealTimeInterval);
            js_pRspRepeal.Set("RepealedTimes", ptrCfd_pRspRepeal->RepealedTimes);
            js_pRspRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pRspRepeal->BankRepealFlag).c_str());
            js_pRspRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pRspRepeal->BrokerRepealFlag).c_str());
            js_pRspRepeal.Set("PlateRepealSerial", ptrCfd_pRspRepeal->PlateRepealSerial);
            js_pRspRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankRepealSerial, strlen(ptrCfd_pRspRepeal->BankRepealSerial)) );
            js_pRspRepeal.Set("FutureRepealSerial", ptrCfd_pRspRepeal->FutureRepealSerial);
            js_pRspRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeCode, strlen(ptrCfd_pRspRepeal->TradeCode)) );
            js_pRspRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankID, strlen(ptrCfd_pRspRepeal->BankID)) );
            js_pRspRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankBranchID, strlen(ptrCfd_pRspRepeal->BankBranchID)) );
            js_pRspRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerID, strlen(ptrCfd_pRspRepeal->BrokerID)) );
            js_pRspRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerBranchID, strlen(ptrCfd_pRspRepeal->BrokerBranchID)) );
            js_pRspRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeDate, strlen(ptrCfd_pRspRepeal->TradeDate)) );
            js_pRspRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeTime, strlen(ptrCfd_pRspRepeal->TradeTime)) );
            js_pRspRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSerial, strlen(ptrCfd_pRspRepeal->BankSerial)) );
            js_pRspRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradingDay, strlen(ptrCfd_pRspRepeal->TradingDay)) );
            js_pRspRepeal.Set("PlateSerial", ptrCfd_pRspRepeal->PlateSerial);
            js_pRspRepeal.Set("LastFragment", string(1u, ptrCfd_pRspRepeal->LastFragment).c_str());
            js_pRspRepeal.Set("SessionID", ptrCfd_pRspRepeal->SessionID);
            js_pRspRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CustomerName, strlen(ptrCfd_pRspRepeal->CustomerName)) );
            js_pRspRepeal.Set("IdCardType", string(1u, ptrCfd_pRspRepeal->IdCardType).c_str());
            js_pRspRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->IdentifiedCardNo, strlen(ptrCfd_pRspRepeal->IdentifiedCardNo)) );
            js_pRspRepeal.Set("CustType", string(1u, ptrCfd_pRspRepeal->CustType).c_str());
            js_pRspRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankAccount, strlen(ptrCfd_pRspRepeal->BankAccount)) );
            js_pRspRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankPassWord, strlen(ptrCfd_pRspRepeal->BankPassWord)) );
            js_pRspRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->AccountID, strlen(ptrCfd_pRspRepeal->AccountID)) );
            js_pRspRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Password, strlen(ptrCfd_pRspRepeal->Password)) );
            js_pRspRepeal.Set("InstallID", ptrCfd_pRspRepeal->InstallID);
            js_pRspRepeal.Set("FutureSerial", ptrCfd_pRspRepeal->FutureSerial);
            js_pRspRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->UserID, strlen(ptrCfd_pRspRepeal->UserID)) );
            js_pRspRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspRepeal->VerifyCertNoFlag).c_str());
            js_pRspRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CurrencyID, strlen(ptrCfd_pRspRepeal->CurrencyID)) );
            js_pRspRepeal.Set("TradeAmount", ptrCfd_pRspRepeal->TradeAmount);
            js_pRspRepeal.Set("FutureFetchAmount", ptrCfd_pRspRepeal->FutureFetchAmount);
            js_pRspRepeal.Set("FeePayFlag", string(1u, ptrCfd_pRspRepeal->FeePayFlag).c_str());
            js_pRspRepeal.Set("CustFee", ptrCfd_pRspRepeal->CustFee);
            js_pRspRepeal.Set("BrokerFee", ptrCfd_pRspRepeal->BrokerFee);
            js_pRspRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Message, strlen(ptrCfd_pRspRepeal->Message)) );
            js_pRspRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Digest, strlen(ptrCfd_pRspRepeal->Digest)) );
            js_pRspRepeal.Set("BankAccType", string(1u, ptrCfd_pRspRepeal->BankAccType).c_str());
            js_pRspRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->DeviceID, strlen(ptrCfd_pRspRepeal->DeviceID)) );
            js_pRspRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pRspRepeal->BankSecuAccType).c_str());
            js_pRspRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerIDByBank, strlen(ptrCfd_pRspRepeal->BrokerIDByBank)) );
            js_pRspRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSecuAcc, strlen(ptrCfd_pRspRepeal->BankSecuAcc)) );
            js_pRspRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pRspRepeal->BankPwdFlag).c_str());
            js_pRspRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pRspRepeal->SecuPwdFlag).c_str());
            js_pRspRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->OperNo, strlen(ptrCfd_pRspRepeal->OperNo)) );
            js_pRspRepeal.Set("RequestID", ptrCfd_pRspRepeal->RequestID);
            js_pRspRepeal.Set("TID", ptrCfd_pRspRepeal->TID);
            js_pRspRepeal.Set("TransferStatus", string(1u, ptrCfd_pRspRepeal->TransferStatus).c_str());
            js_pRspRepeal.Set("ErrorID", ptrCfd_pRspRepeal->ErrorID);
            js_pRspRepeal.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->ErrorMsg, strlen(ptrCfd_pRspRepeal->ErrorMsg)) );
            js_pRspRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->LongCustomerName, strlen(ptrCfd_pRspRepeal->LongCustomerName)) );
            js_event_data.Set("pRspRepeal", js_pRspRepeal);
            delete ptrCfd_pRspRepeal;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField * pRspRepeal)
    {
        
        CThostFtdcRspRepealField *ptrCfd_pRspRepeal = new CThostFtdcRspRepealField();
        if(pRspRepeal)
        {
            memcpy(ptrCfd_pRspRepeal, pRspRepeal, sizeof(CThostFtdcRspRepealField));
        }
        else
        {
            memset(ptrCfd_pRspRepeal, 0, sizeof(CThostFtdcRspRepealField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnRepealFromFutureToBankByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspRepeal = Napi::Object::New(env);
            js_pRspRepeal.Set("RepealTimeInterval", ptrCfd_pRspRepeal->RepealTimeInterval);
            js_pRspRepeal.Set("RepealedTimes", ptrCfd_pRspRepeal->RepealedTimes);
            js_pRspRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pRspRepeal->BankRepealFlag).c_str());
            js_pRspRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pRspRepeal->BrokerRepealFlag).c_str());
            js_pRspRepeal.Set("PlateRepealSerial", ptrCfd_pRspRepeal->PlateRepealSerial);
            js_pRspRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankRepealSerial, strlen(ptrCfd_pRspRepeal->BankRepealSerial)) );
            js_pRspRepeal.Set("FutureRepealSerial", ptrCfd_pRspRepeal->FutureRepealSerial);
            js_pRspRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeCode, strlen(ptrCfd_pRspRepeal->TradeCode)) );
            js_pRspRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankID, strlen(ptrCfd_pRspRepeal->BankID)) );
            js_pRspRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankBranchID, strlen(ptrCfd_pRspRepeal->BankBranchID)) );
            js_pRspRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerID, strlen(ptrCfd_pRspRepeal->BrokerID)) );
            js_pRspRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerBranchID, strlen(ptrCfd_pRspRepeal->BrokerBranchID)) );
            js_pRspRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeDate, strlen(ptrCfd_pRspRepeal->TradeDate)) );
            js_pRspRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeTime, strlen(ptrCfd_pRspRepeal->TradeTime)) );
            js_pRspRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSerial, strlen(ptrCfd_pRspRepeal->BankSerial)) );
            js_pRspRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradingDay, strlen(ptrCfd_pRspRepeal->TradingDay)) );
            js_pRspRepeal.Set("PlateSerial", ptrCfd_pRspRepeal->PlateSerial);
            js_pRspRepeal.Set("LastFragment", string(1u, ptrCfd_pRspRepeal->LastFragment).c_str());
            js_pRspRepeal.Set("SessionID", ptrCfd_pRspRepeal->SessionID);
            js_pRspRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CustomerName, strlen(ptrCfd_pRspRepeal->CustomerName)) );
            js_pRspRepeal.Set("IdCardType", string(1u, ptrCfd_pRspRepeal->IdCardType).c_str());
            js_pRspRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->IdentifiedCardNo, strlen(ptrCfd_pRspRepeal->IdentifiedCardNo)) );
            js_pRspRepeal.Set("CustType", string(1u, ptrCfd_pRspRepeal->CustType).c_str());
            js_pRspRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankAccount, strlen(ptrCfd_pRspRepeal->BankAccount)) );
            js_pRspRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankPassWord, strlen(ptrCfd_pRspRepeal->BankPassWord)) );
            js_pRspRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->AccountID, strlen(ptrCfd_pRspRepeal->AccountID)) );
            js_pRspRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Password, strlen(ptrCfd_pRspRepeal->Password)) );
            js_pRspRepeal.Set("InstallID", ptrCfd_pRspRepeal->InstallID);
            js_pRspRepeal.Set("FutureSerial", ptrCfd_pRspRepeal->FutureSerial);
            js_pRspRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->UserID, strlen(ptrCfd_pRspRepeal->UserID)) );
            js_pRspRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspRepeal->VerifyCertNoFlag).c_str());
            js_pRspRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CurrencyID, strlen(ptrCfd_pRspRepeal->CurrencyID)) );
            js_pRspRepeal.Set("TradeAmount", ptrCfd_pRspRepeal->TradeAmount);
            js_pRspRepeal.Set("FutureFetchAmount", ptrCfd_pRspRepeal->FutureFetchAmount);
            js_pRspRepeal.Set("FeePayFlag", string(1u, ptrCfd_pRspRepeal->FeePayFlag).c_str());
            js_pRspRepeal.Set("CustFee", ptrCfd_pRspRepeal->CustFee);
            js_pRspRepeal.Set("BrokerFee", ptrCfd_pRspRepeal->BrokerFee);
            js_pRspRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Message, strlen(ptrCfd_pRspRepeal->Message)) );
            js_pRspRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Digest, strlen(ptrCfd_pRspRepeal->Digest)) );
            js_pRspRepeal.Set("BankAccType", string(1u, ptrCfd_pRspRepeal->BankAccType).c_str());
            js_pRspRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->DeviceID, strlen(ptrCfd_pRspRepeal->DeviceID)) );
            js_pRspRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pRspRepeal->BankSecuAccType).c_str());
            js_pRspRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerIDByBank, strlen(ptrCfd_pRspRepeal->BrokerIDByBank)) );
            js_pRspRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSecuAcc, strlen(ptrCfd_pRspRepeal->BankSecuAcc)) );
            js_pRspRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pRspRepeal->BankPwdFlag).c_str());
            js_pRspRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pRspRepeal->SecuPwdFlag).c_str());
            js_pRspRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->OperNo, strlen(ptrCfd_pRspRepeal->OperNo)) );
            js_pRspRepeal.Set("RequestID", ptrCfd_pRspRepeal->RequestID);
            js_pRspRepeal.Set("TID", ptrCfd_pRspRepeal->TID);
            js_pRspRepeal.Set("TransferStatus", string(1u, ptrCfd_pRspRepeal->TransferStatus).c_str());
            js_pRspRepeal.Set("ErrorID", ptrCfd_pRspRepeal->ErrorID);
            js_pRspRepeal.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->ErrorMsg, strlen(ptrCfd_pRspRepeal->ErrorMsg)) );
            js_pRspRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->LongCustomerName, strlen(ptrCfd_pRspRepeal->LongCustomerName)) );
            js_event_data.Set("pRspRepeal", js_pRspRepeal);
            delete ptrCfd_pRspRepeal;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField * pRspTransfer)
    {
        
        CThostFtdcRspTransferField *ptrCfd_pRspTransfer = new CThostFtdcRspTransferField();
        if(pRspTransfer)
        {
            memcpy(ptrCfd_pRspTransfer, pRspTransfer, sizeof(CThostFtdcRspTransferField));
        }
        else
        {
            memset(ptrCfd_pRspTransfer, 0, sizeof(CThostFtdcRspTransferField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnFromBankToFutureByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspTransfer = Napi::Object::New(env);
            js_pRspTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeCode, strlen(ptrCfd_pRspTransfer->TradeCode)) );
            js_pRspTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankID, strlen(ptrCfd_pRspTransfer->BankID)) );
            js_pRspTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankBranchID, strlen(ptrCfd_pRspTransfer->BankBranchID)) );
            js_pRspTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerID, strlen(ptrCfd_pRspTransfer->BrokerID)) );
            js_pRspTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerBranchID, strlen(ptrCfd_pRspTransfer->BrokerBranchID)) );
            js_pRspTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeDate, strlen(ptrCfd_pRspTransfer->TradeDate)) );
            js_pRspTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeTime, strlen(ptrCfd_pRspTransfer->TradeTime)) );
            js_pRspTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSerial, strlen(ptrCfd_pRspTransfer->BankSerial)) );
            js_pRspTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradingDay, strlen(ptrCfd_pRspTransfer->TradingDay)) );
            js_pRspTransfer.Set("PlateSerial", ptrCfd_pRspTransfer->PlateSerial);
            js_pRspTransfer.Set("LastFragment", string(1u, ptrCfd_pRspTransfer->LastFragment).c_str());
            js_pRspTransfer.Set("SessionID", ptrCfd_pRspTransfer->SessionID);
            js_pRspTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CustomerName, strlen(ptrCfd_pRspTransfer->CustomerName)) );
            js_pRspTransfer.Set("IdCardType", string(1u, ptrCfd_pRspTransfer->IdCardType).c_str());
            js_pRspTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->IdentifiedCardNo, strlen(ptrCfd_pRspTransfer->IdentifiedCardNo)) );
            js_pRspTransfer.Set("CustType", string(1u, ptrCfd_pRspTransfer->CustType).c_str());
            js_pRspTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankAccount, strlen(ptrCfd_pRspTransfer->BankAccount)) );
            js_pRspTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankPassWord, strlen(ptrCfd_pRspTransfer->BankPassWord)) );
            js_pRspTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->AccountID, strlen(ptrCfd_pRspTransfer->AccountID)) );
            js_pRspTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Password, strlen(ptrCfd_pRspTransfer->Password)) );
            js_pRspTransfer.Set("InstallID", ptrCfd_pRspTransfer->InstallID);
            js_pRspTransfer.Set("FutureSerial", ptrCfd_pRspTransfer->FutureSerial);
            js_pRspTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->UserID, strlen(ptrCfd_pRspTransfer->UserID)) );
            js_pRspTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspTransfer->VerifyCertNoFlag).c_str());
            js_pRspTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CurrencyID, strlen(ptrCfd_pRspTransfer->CurrencyID)) );
            js_pRspTransfer.Set("TradeAmount", ptrCfd_pRspTransfer->TradeAmount);
            js_pRspTransfer.Set("FutureFetchAmount", ptrCfd_pRspTransfer->FutureFetchAmount);
            js_pRspTransfer.Set("FeePayFlag", string(1u, ptrCfd_pRspTransfer->FeePayFlag).c_str());
            js_pRspTransfer.Set("CustFee", ptrCfd_pRspTransfer->CustFee);
            js_pRspTransfer.Set("BrokerFee", ptrCfd_pRspTransfer->BrokerFee);
            js_pRspTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Message, strlen(ptrCfd_pRspTransfer->Message)) );
            js_pRspTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Digest, strlen(ptrCfd_pRspTransfer->Digest)) );
            js_pRspTransfer.Set("BankAccType", string(1u, ptrCfd_pRspTransfer->BankAccType).c_str());
            js_pRspTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->DeviceID, strlen(ptrCfd_pRspTransfer->DeviceID)) );
            js_pRspTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pRspTransfer->BankSecuAccType).c_str());
            js_pRspTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerIDByBank, strlen(ptrCfd_pRspTransfer->BrokerIDByBank)) );
            js_pRspTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSecuAcc, strlen(ptrCfd_pRspTransfer->BankSecuAcc)) );
            js_pRspTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pRspTransfer->BankPwdFlag).c_str());
            js_pRspTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pRspTransfer->SecuPwdFlag).c_str());
            js_pRspTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->OperNo, strlen(ptrCfd_pRspTransfer->OperNo)) );
            js_pRspTransfer.Set("RequestID", ptrCfd_pRspTransfer->RequestID);
            js_pRspTransfer.Set("TID", ptrCfd_pRspTransfer->TID);
            js_pRspTransfer.Set("TransferStatus", string(1u, ptrCfd_pRspTransfer->TransferStatus).c_str());
            js_pRspTransfer.Set("ErrorID", ptrCfd_pRspTransfer->ErrorID);
            js_pRspTransfer.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->ErrorMsg, strlen(ptrCfd_pRspTransfer->ErrorMsg)) );
            js_pRspTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->LongCustomerName, strlen(ptrCfd_pRspTransfer->LongCustomerName)) );
            js_event_data.Set("pRspTransfer", js_pRspTransfer);
            delete ptrCfd_pRspTransfer;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField * pRspTransfer)
    {
        
        CThostFtdcRspTransferField *ptrCfd_pRspTransfer = new CThostFtdcRspTransferField();
        if(pRspTransfer)
        {
            memcpy(ptrCfd_pRspTransfer, pRspTransfer, sizeof(CThostFtdcRspTransferField));
        }
        else
        {
            memset(ptrCfd_pRspTransfer, 0, sizeof(CThostFtdcRspTransferField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnFromFutureToBankByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspTransfer = Napi::Object::New(env);
            js_pRspTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeCode, strlen(ptrCfd_pRspTransfer->TradeCode)) );
            js_pRspTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankID, strlen(ptrCfd_pRspTransfer->BankID)) );
            js_pRspTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankBranchID, strlen(ptrCfd_pRspTransfer->BankBranchID)) );
            js_pRspTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerID, strlen(ptrCfd_pRspTransfer->BrokerID)) );
            js_pRspTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerBranchID, strlen(ptrCfd_pRspTransfer->BrokerBranchID)) );
            js_pRspTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeDate, strlen(ptrCfd_pRspTransfer->TradeDate)) );
            js_pRspTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradeTime, strlen(ptrCfd_pRspTransfer->TradeTime)) );
            js_pRspTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSerial, strlen(ptrCfd_pRspTransfer->BankSerial)) );
            js_pRspTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->TradingDay, strlen(ptrCfd_pRspTransfer->TradingDay)) );
            js_pRspTransfer.Set("PlateSerial", ptrCfd_pRspTransfer->PlateSerial);
            js_pRspTransfer.Set("LastFragment", string(1u, ptrCfd_pRspTransfer->LastFragment).c_str());
            js_pRspTransfer.Set("SessionID", ptrCfd_pRspTransfer->SessionID);
            js_pRspTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CustomerName, strlen(ptrCfd_pRspTransfer->CustomerName)) );
            js_pRspTransfer.Set("IdCardType", string(1u, ptrCfd_pRspTransfer->IdCardType).c_str());
            js_pRspTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->IdentifiedCardNo, strlen(ptrCfd_pRspTransfer->IdentifiedCardNo)) );
            js_pRspTransfer.Set("CustType", string(1u, ptrCfd_pRspTransfer->CustType).c_str());
            js_pRspTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankAccount, strlen(ptrCfd_pRspTransfer->BankAccount)) );
            js_pRspTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankPassWord, strlen(ptrCfd_pRspTransfer->BankPassWord)) );
            js_pRspTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->AccountID, strlen(ptrCfd_pRspTransfer->AccountID)) );
            js_pRspTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Password, strlen(ptrCfd_pRspTransfer->Password)) );
            js_pRspTransfer.Set("InstallID", ptrCfd_pRspTransfer->InstallID);
            js_pRspTransfer.Set("FutureSerial", ptrCfd_pRspTransfer->FutureSerial);
            js_pRspTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->UserID, strlen(ptrCfd_pRspTransfer->UserID)) );
            js_pRspTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspTransfer->VerifyCertNoFlag).c_str());
            js_pRspTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->CurrencyID, strlen(ptrCfd_pRspTransfer->CurrencyID)) );
            js_pRspTransfer.Set("TradeAmount", ptrCfd_pRspTransfer->TradeAmount);
            js_pRspTransfer.Set("FutureFetchAmount", ptrCfd_pRspTransfer->FutureFetchAmount);
            js_pRspTransfer.Set("FeePayFlag", string(1u, ptrCfd_pRspTransfer->FeePayFlag).c_str());
            js_pRspTransfer.Set("CustFee", ptrCfd_pRspTransfer->CustFee);
            js_pRspTransfer.Set("BrokerFee", ptrCfd_pRspTransfer->BrokerFee);
            js_pRspTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Message, strlen(ptrCfd_pRspTransfer->Message)) );
            js_pRspTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->Digest, strlen(ptrCfd_pRspTransfer->Digest)) );
            js_pRspTransfer.Set("BankAccType", string(1u, ptrCfd_pRspTransfer->BankAccType).c_str());
            js_pRspTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->DeviceID, strlen(ptrCfd_pRspTransfer->DeviceID)) );
            js_pRspTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pRspTransfer->BankSecuAccType).c_str());
            js_pRspTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BrokerIDByBank, strlen(ptrCfd_pRspTransfer->BrokerIDByBank)) );
            js_pRspTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->BankSecuAcc, strlen(ptrCfd_pRspTransfer->BankSecuAcc)) );
            js_pRspTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pRspTransfer->BankPwdFlag).c_str());
            js_pRspTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pRspTransfer->SecuPwdFlag).c_str());
            js_pRspTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->OperNo, strlen(ptrCfd_pRspTransfer->OperNo)) );
            js_pRspTransfer.Set("RequestID", ptrCfd_pRspTransfer->RequestID);
            js_pRspTransfer.Set("TID", ptrCfd_pRspTransfer->TID);
            js_pRspTransfer.Set("TransferStatus", string(1u, ptrCfd_pRspTransfer->TransferStatus).c_str());
            js_pRspTransfer.Set("ErrorID", ptrCfd_pRspTransfer->ErrorID);
            js_pRspTransfer.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->ErrorMsg, strlen(ptrCfd_pRspTransfer->ErrorMsg)) );
            js_pRspTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspTransfer->LongCustomerName, strlen(ptrCfd_pRspTransfer->LongCustomerName)) );
            js_event_data.Set("pRspTransfer", js_pRspTransfer);
            delete ptrCfd_pRspTransfer;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField * pRspRepeal)
    {
        
        CThostFtdcRspRepealField *ptrCfd_pRspRepeal = new CThostFtdcRspRepealField();
        if(pRspRepeal)
        {
            memcpy(ptrCfd_pRspRepeal, pRspRepeal, sizeof(CThostFtdcRspRepealField));
        }
        else
        {
            memset(ptrCfd_pRspRepeal, 0, sizeof(CThostFtdcRspRepealField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnRepealFromBankToFutureByFutureManual");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspRepeal = Napi::Object::New(env);
            js_pRspRepeal.Set("RepealTimeInterval", ptrCfd_pRspRepeal->RepealTimeInterval);
            js_pRspRepeal.Set("RepealedTimes", ptrCfd_pRspRepeal->RepealedTimes);
            js_pRspRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pRspRepeal->BankRepealFlag).c_str());
            js_pRspRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pRspRepeal->BrokerRepealFlag).c_str());
            js_pRspRepeal.Set("PlateRepealSerial", ptrCfd_pRspRepeal->PlateRepealSerial);
            js_pRspRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankRepealSerial, strlen(ptrCfd_pRspRepeal->BankRepealSerial)) );
            js_pRspRepeal.Set("FutureRepealSerial", ptrCfd_pRspRepeal->FutureRepealSerial);
            js_pRspRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeCode, strlen(ptrCfd_pRspRepeal->TradeCode)) );
            js_pRspRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankID, strlen(ptrCfd_pRspRepeal->BankID)) );
            js_pRspRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankBranchID, strlen(ptrCfd_pRspRepeal->BankBranchID)) );
            js_pRspRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerID, strlen(ptrCfd_pRspRepeal->BrokerID)) );
            js_pRspRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerBranchID, strlen(ptrCfd_pRspRepeal->BrokerBranchID)) );
            js_pRspRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeDate, strlen(ptrCfd_pRspRepeal->TradeDate)) );
            js_pRspRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeTime, strlen(ptrCfd_pRspRepeal->TradeTime)) );
            js_pRspRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSerial, strlen(ptrCfd_pRspRepeal->BankSerial)) );
            js_pRspRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradingDay, strlen(ptrCfd_pRspRepeal->TradingDay)) );
            js_pRspRepeal.Set("PlateSerial", ptrCfd_pRspRepeal->PlateSerial);
            js_pRspRepeal.Set("LastFragment", string(1u, ptrCfd_pRspRepeal->LastFragment).c_str());
            js_pRspRepeal.Set("SessionID", ptrCfd_pRspRepeal->SessionID);
            js_pRspRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CustomerName, strlen(ptrCfd_pRspRepeal->CustomerName)) );
            js_pRspRepeal.Set("IdCardType", string(1u, ptrCfd_pRspRepeal->IdCardType).c_str());
            js_pRspRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->IdentifiedCardNo, strlen(ptrCfd_pRspRepeal->IdentifiedCardNo)) );
            js_pRspRepeal.Set("CustType", string(1u, ptrCfd_pRspRepeal->CustType).c_str());
            js_pRspRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankAccount, strlen(ptrCfd_pRspRepeal->BankAccount)) );
            js_pRspRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankPassWord, strlen(ptrCfd_pRspRepeal->BankPassWord)) );
            js_pRspRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->AccountID, strlen(ptrCfd_pRspRepeal->AccountID)) );
            js_pRspRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Password, strlen(ptrCfd_pRspRepeal->Password)) );
            js_pRspRepeal.Set("InstallID", ptrCfd_pRspRepeal->InstallID);
            js_pRspRepeal.Set("FutureSerial", ptrCfd_pRspRepeal->FutureSerial);
            js_pRspRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->UserID, strlen(ptrCfd_pRspRepeal->UserID)) );
            js_pRspRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspRepeal->VerifyCertNoFlag).c_str());
            js_pRspRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CurrencyID, strlen(ptrCfd_pRspRepeal->CurrencyID)) );
            js_pRspRepeal.Set("TradeAmount", ptrCfd_pRspRepeal->TradeAmount);
            js_pRspRepeal.Set("FutureFetchAmount", ptrCfd_pRspRepeal->FutureFetchAmount);
            js_pRspRepeal.Set("FeePayFlag", string(1u, ptrCfd_pRspRepeal->FeePayFlag).c_str());
            js_pRspRepeal.Set("CustFee", ptrCfd_pRspRepeal->CustFee);
            js_pRspRepeal.Set("BrokerFee", ptrCfd_pRspRepeal->BrokerFee);
            js_pRspRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Message, strlen(ptrCfd_pRspRepeal->Message)) );
            js_pRspRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Digest, strlen(ptrCfd_pRspRepeal->Digest)) );
            js_pRspRepeal.Set("BankAccType", string(1u, ptrCfd_pRspRepeal->BankAccType).c_str());
            js_pRspRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->DeviceID, strlen(ptrCfd_pRspRepeal->DeviceID)) );
            js_pRspRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pRspRepeal->BankSecuAccType).c_str());
            js_pRspRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerIDByBank, strlen(ptrCfd_pRspRepeal->BrokerIDByBank)) );
            js_pRspRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSecuAcc, strlen(ptrCfd_pRspRepeal->BankSecuAcc)) );
            js_pRspRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pRspRepeal->BankPwdFlag).c_str());
            js_pRspRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pRspRepeal->SecuPwdFlag).c_str());
            js_pRspRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->OperNo, strlen(ptrCfd_pRspRepeal->OperNo)) );
            js_pRspRepeal.Set("RequestID", ptrCfd_pRspRepeal->RequestID);
            js_pRspRepeal.Set("TID", ptrCfd_pRspRepeal->TID);
            js_pRspRepeal.Set("TransferStatus", string(1u, ptrCfd_pRspRepeal->TransferStatus).c_str());
            js_pRspRepeal.Set("ErrorID", ptrCfd_pRspRepeal->ErrorID);
            js_pRspRepeal.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->ErrorMsg, strlen(ptrCfd_pRspRepeal->ErrorMsg)) );
            js_pRspRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->LongCustomerName, strlen(ptrCfd_pRspRepeal->LongCustomerName)) );
            js_event_data.Set("pRspRepeal", js_pRspRepeal);
            delete ptrCfd_pRspRepeal;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField * pRspRepeal)
    {
        
        CThostFtdcRspRepealField *ptrCfd_pRspRepeal = new CThostFtdcRspRepealField();
        if(pRspRepeal)
        {
            memcpy(ptrCfd_pRspRepeal, pRspRepeal, sizeof(CThostFtdcRspRepealField));
        }
        else
        {
            memset(ptrCfd_pRspRepeal, 0, sizeof(CThostFtdcRspRepealField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnRepealFromFutureToBankByFutureManual");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspRepeal = Napi::Object::New(env);
            js_pRspRepeal.Set("RepealTimeInterval", ptrCfd_pRspRepeal->RepealTimeInterval);
            js_pRspRepeal.Set("RepealedTimes", ptrCfd_pRspRepeal->RepealedTimes);
            js_pRspRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pRspRepeal->BankRepealFlag).c_str());
            js_pRspRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pRspRepeal->BrokerRepealFlag).c_str());
            js_pRspRepeal.Set("PlateRepealSerial", ptrCfd_pRspRepeal->PlateRepealSerial);
            js_pRspRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankRepealSerial, strlen(ptrCfd_pRspRepeal->BankRepealSerial)) );
            js_pRspRepeal.Set("FutureRepealSerial", ptrCfd_pRspRepeal->FutureRepealSerial);
            js_pRspRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeCode, strlen(ptrCfd_pRspRepeal->TradeCode)) );
            js_pRspRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankID, strlen(ptrCfd_pRspRepeal->BankID)) );
            js_pRspRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankBranchID, strlen(ptrCfd_pRspRepeal->BankBranchID)) );
            js_pRspRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerID, strlen(ptrCfd_pRspRepeal->BrokerID)) );
            js_pRspRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerBranchID, strlen(ptrCfd_pRspRepeal->BrokerBranchID)) );
            js_pRspRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeDate, strlen(ptrCfd_pRspRepeal->TradeDate)) );
            js_pRspRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeTime, strlen(ptrCfd_pRspRepeal->TradeTime)) );
            js_pRspRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSerial, strlen(ptrCfd_pRspRepeal->BankSerial)) );
            js_pRspRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradingDay, strlen(ptrCfd_pRspRepeal->TradingDay)) );
            js_pRspRepeal.Set("PlateSerial", ptrCfd_pRspRepeal->PlateSerial);
            js_pRspRepeal.Set("LastFragment", string(1u, ptrCfd_pRspRepeal->LastFragment).c_str());
            js_pRspRepeal.Set("SessionID", ptrCfd_pRspRepeal->SessionID);
            js_pRspRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CustomerName, strlen(ptrCfd_pRspRepeal->CustomerName)) );
            js_pRspRepeal.Set("IdCardType", string(1u, ptrCfd_pRspRepeal->IdCardType).c_str());
            js_pRspRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->IdentifiedCardNo, strlen(ptrCfd_pRspRepeal->IdentifiedCardNo)) );
            js_pRspRepeal.Set("CustType", string(1u, ptrCfd_pRspRepeal->CustType).c_str());
            js_pRspRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankAccount, strlen(ptrCfd_pRspRepeal->BankAccount)) );
            js_pRspRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankPassWord, strlen(ptrCfd_pRspRepeal->BankPassWord)) );
            js_pRspRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->AccountID, strlen(ptrCfd_pRspRepeal->AccountID)) );
            js_pRspRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Password, strlen(ptrCfd_pRspRepeal->Password)) );
            js_pRspRepeal.Set("InstallID", ptrCfd_pRspRepeal->InstallID);
            js_pRspRepeal.Set("FutureSerial", ptrCfd_pRspRepeal->FutureSerial);
            js_pRspRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->UserID, strlen(ptrCfd_pRspRepeal->UserID)) );
            js_pRspRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspRepeal->VerifyCertNoFlag).c_str());
            js_pRspRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CurrencyID, strlen(ptrCfd_pRspRepeal->CurrencyID)) );
            js_pRspRepeal.Set("TradeAmount", ptrCfd_pRspRepeal->TradeAmount);
            js_pRspRepeal.Set("FutureFetchAmount", ptrCfd_pRspRepeal->FutureFetchAmount);
            js_pRspRepeal.Set("FeePayFlag", string(1u, ptrCfd_pRspRepeal->FeePayFlag).c_str());
            js_pRspRepeal.Set("CustFee", ptrCfd_pRspRepeal->CustFee);
            js_pRspRepeal.Set("BrokerFee", ptrCfd_pRspRepeal->BrokerFee);
            js_pRspRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Message, strlen(ptrCfd_pRspRepeal->Message)) );
            js_pRspRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Digest, strlen(ptrCfd_pRspRepeal->Digest)) );
            js_pRspRepeal.Set("BankAccType", string(1u, ptrCfd_pRspRepeal->BankAccType).c_str());
            js_pRspRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->DeviceID, strlen(ptrCfd_pRspRepeal->DeviceID)) );
            js_pRspRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pRspRepeal->BankSecuAccType).c_str());
            js_pRspRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerIDByBank, strlen(ptrCfd_pRspRepeal->BrokerIDByBank)) );
            js_pRspRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSecuAcc, strlen(ptrCfd_pRspRepeal->BankSecuAcc)) );
            js_pRspRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pRspRepeal->BankPwdFlag).c_str());
            js_pRspRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pRspRepeal->SecuPwdFlag).c_str());
            js_pRspRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->OperNo, strlen(ptrCfd_pRspRepeal->OperNo)) );
            js_pRspRepeal.Set("RequestID", ptrCfd_pRspRepeal->RequestID);
            js_pRspRepeal.Set("TID", ptrCfd_pRspRepeal->TID);
            js_pRspRepeal.Set("TransferStatus", string(1u, ptrCfd_pRspRepeal->TransferStatus).c_str());
            js_pRspRepeal.Set("ErrorID", ptrCfd_pRspRepeal->ErrorID);
            js_pRspRepeal.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->ErrorMsg, strlen(ptrCfd_pRspRepeal->ErrorMsg)) );
            js_pRspRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->LongCustomerName, strlen(ptrCfd_pRspRepeal->LongCustomerName)) );
            js_event_data.Set("pRspRepeal", js_pRspRepeal);
            delete ptrCfd_pRspRepeal;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField * pNotifyQueryAccount)
    {
        
        CThostFtdcNotifyQueryAccountField *ptrCfd_pNotifyQueryAccount = new CThostFtdcNotifyQueryAccountField();
        if(pNotifyQueryAccount)
        {
            memcpy(ptrCfd_pNotifyQueryAccount, pNotifyQueryAccount, sizeof(CThostFtdcNotifyQueryAccountField));
        }
        else
        {
            memset(ptrCfd_pNotifyQueryAccount, 0, sizeof(CThostFtdcNotifyQueryAccountField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnQueryBankBalanceByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pNotifyQueryAccount = Napi::Object::New(env);
            js_pNotifyQueryAccount.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->TradeCode, strlen(ptrCfd_pNotifyQueryAccount->TradeCode)) );
            js_pNotifyQueryAccount.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BankID, strlen(ptrCfd_pNotifyQueryAccount->BankID)) );
            js_pNotifyQueryAccount.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BankBranchID, strlen(ptrCfd_pNotifyQueryAccount->BankBranchID)) );
            js_pNotifyQueryAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BrokerID, strlen(ptrCfd_pNotifyQueryAccount->BrokerID)) );
            js_pNotifyQueryAccount.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BrokerBranchID, strlen(ptrCfd_pNotifyQueryAccount->BrokerBranchID)) );
            js_pNotifyQueryAccount.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->TradeDate, strlen(ptrCfd_pNotifyQueryAccount->TradeDate)) );
            js_pNotifyQueryAccount.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->TradeTime, strlen(ptrCfd_pNotifyQueryAccount->TradeTime)) );
            js_pNotifyQueryAccount.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BankSerial, strlen(ptrCfd_pNotifyQueryAccount->BankSerial)) );
            js_pNotifyQueryAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->TradingDay, strlen(ptrCfd_pNotifyQueryAccount->TradingDay)) );
            js_pNotifyQueryAccount.Set("PlateSerial", ptrCfd_pNotifyQueryAccount->PlateSerial);
            js_pNotifyQueryAccount.Set("LastFragment", string(1u, ptrCfd_pNotifyQueryAccount->LastFragment).c_str());
            js_pNotifyQueryAccount.Set("SessionID", ptrCfd_pNotifyQueryAccount->SessionID);
            js_pNotifyQueryAccount.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->CustomerName, strlen(ptrCfd_pNotifyQueryAccount->CustomerName)) );
            js_pNotifyQueryAccount.Set("IdCardType", string(1u, ptrCfd_pNotifyQueryAccount->IdCardType).c_str());
            js_pNotifyQueryAccount.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->IdentifiedCardNo, strlen(ptrCfd_pNotifyQueryAccount->IdentifiedCardNo)) );
            js_pNotifyQueryAccount.Set("CustType", string(1u, ptrCfd_pNotifyQueryAccount->CustType).c_str());
            js_pNotifyQueryAccount.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BankAccount, strlen(ptrCfd_pNotifyQueryAccount->BankAccount)) );
            js_pNotifyQueryAccount.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BankPassWord, strlen(ptrCfd_pNotifyQueryAccount->BankPassWord)) );
            js_pNotifyQueryAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->AccountID, strlen(ptrCfd_pNotifyQueryAccount->AccountID)) );
            js_pNotifyQueryAccount.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->Password, strlen(ptrCfd_pNotifyQueryAccount->Password)) );
            js_pNotifyQueryAccount.Set("FutureSerial", ptrCfd_pNotifyQueryAccount->FutureSerial);
            js_pNotifyQueryAccount.Set("InstallID", ptrCfd_pNotifyQueryAccount->InstallID);
            js_pNotifyQueryAccount.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->UserID, strlen(ptrCfd_pNotifyQueryAccount->UserID)) );
            js_pNotifyQueryAccount.Set("VerifyCertNoFlag", string(1u, ptrCfd_pNotifyQueryAccount->VerifyCertNoFlag).c_str());
            js_pNotifyQueryAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->CurrencyID, strlen(ptrCfd_pNotifyQueryAccount->CurrencyID)) );
            js_pNotifyQueryAccount.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->Digest, strlen(ptrCfd_pNotifyQueryAccount->Digest)) );
            js_pNotifyQueryAccount.Set("BankAccType", string(1u, ptrCfd_pNotifyQueryAccount->BankAccType).c_str());
            js_pNotifyQueryAccount.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->DeviceID, strlen(ptrCfd_pNotifyQueryAccount->DeviceID)) );
            js_pNotifyQueryAccount.Set("BankSecuAccType", string(1u, ptrCfd_pNotifyQueryAccount->BankSecuAccType).c_str());
            js_pNotifyQueryAccount.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BrokerIDByBank, strlen(ptrCfd_pNotifyQueryAccount->BrokerIDByBank)) );
            js_pNotifyQueryAccount.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->BankSecuAcc, strlen(ptrCfd_pNotifyQueryAccount->BankSecuAcc)) );
            js_pNotifyQueryAccount.Set("BankPwdFlag", string(1u, ptrCfd_pNotifyQueryAccount->BankPwdFlag).c_str());
            js_pNotifyQueryAccount.Set("SecuPwdFlag", string(1u, ptrCfd_pNotifyQueryAccount->SecuPwdFlag).c_str());
            js_pNotifyQueryAccount.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->OperNo, strlen(ptrCfd_pNotifyQueryAccount->OperNo)) );
            js_pNotifyQueryAccount.Set("RequestID", ptrCfd_pNotifyQueryAccount->RequestID);
            js_pNotifyQueryAccount.Set("TID", ptrCfd_pNotifyQueryAccount->TID);
            js_pNotifyQueryAccount.Set("BankUseAmount", ptrCfd_pNotifyQueryAccount->BankUseAmount);
            js_pNotifyQueryAccount.Set("BankFetchAmount", ptrCfd_pNotifyQueryAccount->BankFetchAmount);
            js_pNotifyQueryAccount.Set("ErrorID", ptrCfd_pNotifyQueryAccount->ErrorID);
            js_pNotifyQueryAccount.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->ErrorMsg, strlen(ptrCfd_pNotifyQueryAccount->ErrorMsg)) );
            js_pNotifyQueryAccount.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pNotifyQueryAccount->LongCustomerName, strlen(ptrCfd_pNotifyQueryAccount->LongCustomerName)) );
            js_event_data.Set("pNotifyQueryAccount", js_pNotifyQueryAccount);
            delete ptrCfd_pNotifyQueryAccount;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcReqTransferField *ptrCfd_pReqTransfer = new CThostFtdcReqTransferField();
        if(pReqTransfer)
        {
            memcpy(ptrCfd_pReqTransfer, pReqTransfer, sizeof(CThostFtdcReqTransferField));
        }
        else
        {
            memset(ptrCfd_pReqTransfer, 0, sizeof(CThostFtdcReqTransferField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnBankToFutureByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqTransfer = Napi::Object::New(env);
            js_pReqTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeCode, strlen(ptrCfd_pReqTransfer->TradeCode)) );
            js_pReqTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankID, strlen(ptrCfd_pReqTransfer->BankID)) );
            js_pReqTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankBranchID, strlen(ptrCfd_pReqTransfer->BankBranchID)) );
            js_pReqTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerID, strlen(ptrCfd_pReqTransfer->BrokerID)) );
            js_pReqTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerBranchID, strlen(ptrCfd_pReqTransfer->BrokerBranchID)) );
            js_pReqTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeDate, strlen(ptrCfd_pReqTransfer->TradeDate)) );
            js_pReqTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeTime, strlen(ptrCfd_pReqTransfer->TradeTime)) );
            js_pReqTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSerial, strlen(ptrCfd_pReqTransfer->BankSerial)) );
            js_pReqTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradingDay, strlen(ptrCfd_pReqTransfer->TradingDay)) );
            js_pReqTransfer.Set("PlateSerial", ptrCfd_pReqTransfer->PlateSerial);
            js_pReqTransfer.Set("LastFragment", string(1u, ptrCfd_pReqTransfer->LastFragment).c_str());
            js_pReqTransfer.Set("SessionID", ptrCfd_pReqTransfer->SessionID);
            js_pReqTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CustomerName, strlen(ptrCfd_pReqTransfer->CustomerName)) );
            js_pReqTransfer.Set("IdCardType", string(1u, ptrCfd_pReqTransfer->IdCardType).c_str());
            js_pReqTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->IdentifiedCardNo, strlen(ptrCfd_pReqTransfer->IdentifiedCardNo)) );
            js_pReqTransfer.Set("CustType", string(1u, ptrCfd_pReqTransfer->CustType).c_str());
            js_pReqTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankAccount, strlen(ptrCfd_pReqTransfer->BankAccount)) );
            js_pReqTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankPassWord, strlen(ptrCfd_pReqTransfer->BankPassWord)) );
            js_pReqTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->AccountID, strlen(ptrCfd_pReqTransfer->AccountID)) );
            js_pReqTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Password, strlen(ptrCfd_pReqTransfer->Password)) );
            js_pReqTransfer.Set("InstallID", ptrCfd_pReqTransfer->InstallID);
            js_pReqTransfer.Set("FutureSerial", ptrCfd_pReqTransfer->FutureSerial);
            js_pReqTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->UserID, strlen(ptrCfd_pReqTransfer->UserID)) );
            js_pReqTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqTransfer->VerifyCertNoFlag).c_str());
            js_pReqTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CurrencyID, strlen(ptrCfd_pReqTransfer->CurrencyID)) );
            js_pReqTransfer.Set("TradeAmount", ptrCfd_pReqTransfer->TradeAmount);
            js_pReqTransfer.Set("FutureFetchAmount", ptrCfd_pReqTransfer->FutureFetchAmount);
            js_pReqTransfer.Set("FeePayFlag", string(1u, ptrCfd_pReqTransfer->FeePayFlag).c_str());
            js_pReqTransfer.Set("CustFee", ptrCfd_pReqTransfer->CustFee);
            js_pReqTransfer.Set("BrokerFee", ptrCfd_pReqTransfer->BrokerFee);
            js_pReqTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Message, strlen(ptrCfd_pReqTransfer->Message)) );
            js_pReqTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Digest, strlen(ptrCfd_pReqTransfer->Digest)) );
            js_pReqTransfer.Set("BankAccType", string(1u, ptrCfd_pReqTransfer->BankAccType).c_str());
            js_pReqTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->DeviceID, strlen(ptrCfd_pReqTransfer->DeviceID)) );
            js_pReqTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pReqTransfer->BankSecuAccType).c_str());
            js_pReqTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerIDByBank, strlen(ptrCfd_pReqTransfer->BrokerIDByBank)) );
            js_pReqTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSecuAcc, strlen(ptrCfd_pReqTransfer->BankSecuAcc)) );
            js_pReqTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pReqTransfer->BankPwdFlag).c_str());
            js_pReqTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pReqTransfer->SecuPwdFlag).c_str());
            js_pReqTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->OperNo, strlen(ptrCfd_pReqTransfer->OperNo)) );
            js_pReqTransfer.Set("RequestID", ptrCfd_pReqTransfer->RequestID);
            js_pReqTransfer.Set("TID", ptrCfd_pReqTransfer->TID);
            js_pReqTransfer.Set("TransferStatus", string(1u, ptrCfd_pReqTransfer->TransferStatus).c_str());
            js_pReqTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->LongCustomerName, strlen(ptrCfd_pReqTransfer->LongCustomerName)) );
            js_event_data.Set("pReqTransfer", js_pReqTransfer);
            delete ptrCfd_pReqTransfer;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcReqTransferField *ptrCfd_pReqTransfer = new CThostFtdcReqTransferField();
        if(pReqTransfer)
        {
            memcpy(ptrCfd_pReqTransfer, pReqTransfer, sizeof(CThostFtdcReqTransferField));
        }
        else
        {
            memset(ptrCfd_pReqTransfer, 0, sizeof(CThostFtdcReqTransferField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnFutureToBankByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqTransfer = Napi::Object::New(env);
            js_pReqTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeCode, strlen(ptrCfd_pReqTransfer->TradeCode)) );
            js_pReqTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankID, strlen(ptrCfd_pReqTransfer->BankID)) );
            js_pReqTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankBranchID, strlen(ptrCfd_pReqTransfer->BankBranchID)) );
            js_pReqTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerID, strlen(ptrCfd_pReqTransfer->BrokerID)) );
            js_pReqTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerBranchID, strlen(ptrCfd_pReqTransfer->BrokerBranchID)) );
            js_pReqTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeDate, strlen(ptrCfd_pReqTransfer->TradeDate)) );
            js_pReqTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeTime, strlen(ptrCfd_pReqTransfer->TradeTime)) );
            js_pReqTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSerial, strlen(ptrCfd_pReqTransfer->BankSerial)) );
            js_pReqTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradingDay, strlen(ptrCfd_pReqTransfer->TradingDay)) );
            js_pReqTransfer.Set("PlateSerial", ptrCfd_pReqTransfer->PlateSerial);
            js_pReqTransfer.Set("LastFragment", string(1u, ptrCfd_pReqTransfer->LastFragment).c_str());
            js_pReqTransfer.Set("SessionID", ptrCfd_pReqTransfer->SessionID);
            js_pReqTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CustomerName, strlen(ptrCfd_pReqTransfer->CustomerName)) );
            js_pReqTransfer.Set("IdCardType", string(1u, ptrCfd_pReqTransfer->IdCardType).c_str());
            js_pReqTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->IdentifiedCardNo, strlen(ptrCfd_pReqTransfer->IdentifiedCardNo)) );
            js_pReqTransfer.Set("CustType", string(1u, ptrCfd_pReqTransfer->CustType).c_str());
            js_pReqTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankAccount, strlen(ptrCfd_pReqTransfer->BankAccount)) );
            js_pReqTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankPassWord, strlen(ptrCfd_pReqTransfer->BankPassWord)) );
            js_pReqTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->AccountID, strlen(ptrCfd_pReqTransfer->AccountID)) );
            js_pReqTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Password, strlen(ptrCfd_pReqTransfer->Password)) );
            js_pReqTransfer.Set("InstallID", ptrCfd_pReqTransfer->InstallID);
            js_pReqTransfer.Set("FutureSerial", ptrCfd_pReqTransfer->FutureSerial);
            js_pReqTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->UserID, strlen(ptrCfd_pReqTransfer->UserID)) );
            js_pReqTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqTransfer->VerifyCertNoFlag).c_str());
            js_pReqTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CurrencyID, strlen(ptrCfd_pReqTransfer->CurrencyID)) );
            js_pReqTransfer.Set("TradeAmount", ptrCfd_pReqTransfer->TradeAmount);
            js_pReqTransfer.Set("FutureFetchAmount", ptrCfd_pReqTransfer->FutureFetchAmount);
            js_pReqTransfer.Set("FeePayFlag", string(1u, ptrCfd_pReqTransfer->FeePayFlag).c_str());
            js_pReqTransfer.Set("CustFee", ptrCfd_pReqTransfer->CustFee);
            js_pReqTransfer.Set("BrokerFee", ptrCfd_pReqTransfer->BrokerFee);
            js_pReqTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Message, strlen(ptrCfd_pReqTransfer->Message)) );
            js_pReqTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Digest, strlen(ptrCfd_pReqTransfer->Digest)) );
            js_pReqTransfer.Set("BankAccType", string(1u, ptrCfd_pReqTransfer->BankAccType).c_str());
            js_pReqTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->DeviceID, strlen(ptrCfd_pReqTransfer->DeviceID)) );
            js_pReqTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pReqTransfer->BankSecuAccType).c_str());
            js_pReqTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerIDByBank, strlen(ptrCfd_pReqTransfer->BrokerIDByBank)) );
            js_pReqTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSecuAcc, strlen(ptrCfd_pReqTransfer->BankSecuAcc)) );
            js_pReqTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pReqTransfer->BankPwdFlag).c_str());
            js_pReqTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pReqTransfer->SecuPwdFlag).c_str());
            js_pReqTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->OperNo, strlen(ptrCfd_pReqTransfer->OperNo)) );
            js_pReqTransfer.Set("RequestID", ptrCfd_pReqTransfer->RequestID);
            js_pReqTransfer.Set("TID", ptrCfd_pReqTransfer->TID);
            js_pReqTransfer.Set("TransferStatus", string(1u, ptrCfd_pReqTransfer->TransferStatus).c_str());
            js_pReqTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->LongCustomerName, strlen(ptrCfd_pReqTransfer->LongCustomerName)) );
            js_event_data.Set("pReqTransfer", js_pReqTransfer);
            delete ptrCfd_pReqTransfer;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField * pReqRepeal, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcReqRepealField *ptrCfd_pReqRepeal = new CThostFtdcReqRepealField();
        if(pReqRepeal)
        {
            memcpy(ptrCfd_pReqRepeal, pReqRepeal, sizeof(CThostFtdcReqRepealField));
        }
        else
        {
            memset(ptrCfd_pReqRepeal, 0, sizeof(CThostFtdcReqRepealField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnRepealBankToFutureByFutureManual");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqRepeal = Napi::Object::New(env);
            js_pReqRepeal.Set("RepealTimeInterval", ptrCfd_pReqRepeal->RepealTimeInterval);
            js_pReqRepeal.Set("RepealedTimes", ptrCfd_pReqRepeal->RepealedTimes);
            js_pReqRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pReqRepeal->BankRepealFlag).c_str());
            js_pReqRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pReqRepeal->BrokerRepealFlag).c_str());
            js_pReqRepeal.Set("PlateRepealSerial", ptrCfd_pReqRepeal->PlateRepealSerial);
            js_pReqRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankRepealSerial, strlen(ptrCfd_pReqRepeal->BankRepealSerial)) );
            js_pReqRepeal.Set("FutureRepealSerial", ptrCfd_pReqRepeal->FutureRepealSerial);
            js_pReqRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradeCode, strlen(ptrCfd_pReqRepeal->TradeCode)) );
            js_pReqRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankID, strlen(ptrCfd_pReqRepeal->BankID)) );
            js_pReqRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankBranchID, strlen(ptrCfd_pReqRepeal->BankBranchID)) );
            js_pReqRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BrokerID, strlen(ptrCfd_pReqRepeal->BrokerID)) );
            js_pReqRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BrokerBranchID, strlen(ptrCfd_pReqRepeal->BrokerBranchID)) );
            js_pReqRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradeDate, strlen(ptrCfd_pReqRepeal->TradeDate)) );
            js_pReqRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradeTime, strlen(ptrCfd_pReqRepeal->TradeTime)) );
            js_pReqRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankSerial, strlen(ptrCfd_pReqRepeal->BankSerial)) );
            js_pReqRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradingDay, strlen(ptrCfd_pReqRepeal->TradingDay)) );
            js_pReqRepeal.Set("PlateSerial", ptrCfd_pReqRepeal->PlateSerial);
            js_pReqRepeal.Set("LastFragment", string(1u, ptrCfd_pReqRepeal->LastFragment).c_str());
            js_pReqRepeal.Set("SessionID", ptrCfd_pReqRepeal->SessionID);
            js_pReqRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->CustomerName, strlen(ptrCfd_pReqRepeal->CustomerName)) );
            js_pReqRepeal.Set("IdCardType", string(1u, ptrCfd_pReqRepeal->IdCardType).c_str());
            js_pReqRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->IdentifiedCardNo, strlen(ptrCfd_pReqRepeal->IdentifiedCardNo)) );
            js_pReqRepeal.Set("CustType", string(1u, ptrCfd_pReqRepeal->CustType).c_str());
            js_pReqRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankAccount, strlen(ptrCfd_pReqRepeal->BankAccount)) );
            js_pReqRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankPassWord, strlen(ptrCfd_pReqRepeal->BankPassWord)) );
            js_pReqRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->AccountID, strlen(ptrCfd_pReqRepeal->AccountID)) );
            js_pReqRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->Password, strlen(ptrCfd_pReqRepeal->Password)) );
            js_pReqRepeal.Set("InstallID", ptrCfd_pReqRepeal->InstallID);
            js_pReqRepeal.Set("FutureSerial", ptrCfd_pReqRepeal->FutureSerial);
            js_pReqRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->UserID, strlen(ptrCfd_pReqRepeal->UserID)) );
            js_pReqRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqRepeal->VerifyCertNoFlag).c_str());
            js_pReqRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->CurrencyID, strlen(ptrCfd_pReqRepeal->CurrencyID)) );
            js_pReqRepeal.Set("TradeAmount", ptrCfd_pReqRepeal->TradeAmount);
            js_pReqRepeal.Set("FutureFetchAmount", ptrCfd_pReqRepeal->FutureFetchAmount);
            js_pReqRepeal.Set("FeePayFlag", string(1u, ptrCfd_pReqRepeal->FeePayFlag).c_str());
            js_pReqRepeal.Set("CustFee", ptrCfd_pReqRepeal->CustFee);
            js_pReqRepeal.Set("BrokerFee", ptrCfd_pReqRepeal->BrokerFee);
            js_pReqRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->Message, strlen(ptrCfd_pReqRepeal->Message)) );
            js_pReqRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->Digest, strlen(ptrCfd_pReqRepeal->Digest)) );
            js_pReqRepeal.Set("BankAccType", string(1u, ptrCfd_pReqRepeal->BankAccType).c_str());
            js_pReqRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->DeviceID, strlen(ptrCfd_pReqRepeal->DeviceID)) );
            js_pReqRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pReqRepeal->BankSecuAccType).c_str());
            js_pReqRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BrokerIDByBank, strlen(ptrCfd_pReqRepeal->BrokerIDByBank)) );
            js_pReqRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankSecuAcc, strlen(ptrCfd_pReqRepeal->BankSecuAcc)) );
            js_pReqRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pReqRepeal->BankPwdFlag).c_str());
            js_pReqRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pReqRepeal->SecuPwdFlag).c_str());
            js_pReqRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->OperNo, strlen(ptrCfd_pReqRepeal->OperNo)) );
            js_pReqRepeal.Set("RequestID", ptrCfd_pReqRepeal->RequestID);
            js_pReqRepeal.Set("TID", ptrCfd_pReqRepeal->TID);
            js_pReqRepeal.Set("TransferStatus", string(1u, ptrCfd_pReqRepeal->TransferStatus).c_str());
            js_pReqRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->LongCustomerName, strlen(ptrCfd_pReqRepeal->LongCustomerName)) );
            js_event_data.Set("pReqRepeal", js_pReqRepeal);
            delete ptrCfd_pReqRepeal;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField * pReqRepeal, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcReqRepealField *ptrCfd_pReqRepeal = new CThostFtdcReqRepealField();
        if(pReqRepeal)
        {
            memcpy(ptrCfd_pReqRepeal, pReqRepeal, sizeof(CThostFtdcReqRepealField));
        }
        else
        {
            memset(ptrCfd_pReqRepeal, 0, sizeof(CThostFtdcReqRepealField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnRepealFutureToBankByFutureManual");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqRepeal = Napi::Object::New(env);
            js_pReqRepeal.Set("RepealTimeInterval", ptrCfd_pReqRepeal->RepealTimeInterval);
            js_pReqRepeal.Set("RepealedTimes", ptrCfd_pReqRepeal->RepealedTimes);
            js_pReqRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pReqRepeal->BankRepealFlag).c_str());
            js_pReqRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pReqRepeal->BrokerRepealFlag).c_str());
            js_pReqRepeal.Set("PlateRepealSerial", ptrCfd_pReqRepeal->PlateRepealSerial);
            js_pReqRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankRepealSerial, strlen(ptrCfd_pReqRepeal->BankRepealSerial)) );
            js_pReqRepeal.Set("FutureRepealSerial", ptrCfd_pReqRepeal->FutureRepealSerial);
            js_pReqRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradeCode, strlen(ptrCfd_pReqRepeal->TradeCode)) );
            js_pReqRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankID, strlen(ptrCfd_pReqRepeal->BankID)) );
            js_pReqRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankBranchID, strlen(ptrCfd_pReqRepeal->BankBranchID)) );
            js_pReqRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BrokerID, strlen(ptrCfd_pReqRepeal->BrokerID)) );
            js_pReqRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BrokerBranchID, strlen(ptrCfd_pReqRepeal->BrokerBranchID)) );
            js_pReqRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradeDate, strlen(ptrCfd_pReqRepeal->TradeDate)) );
            js_pReqRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradeTime, strlen(ptrCfd_pReqRepeal->TradeTime)) );
            js_pReqRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankSerial, strlen(ptrCfd_pReqRepeal->BankSerial)) );
            js_pReqRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->TradingDay, strlen(ptrCfd_pReqRepeal->TradingDay)) );
            js_pReqRepeal.Set("PlateSerial", ptrCfd_pReqRepeal->PlateSerial);
            js_pReqRepeal.Set("LastFragment", string(1u, ptrCfd_pReqRepeal->LastFragment).c_str());
            js_pReqRepeal.Set("SessionID", ptrCfd_pReqRepeal->SessionID);
            js_pReqRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->CustomerName, strlen(ptrCfd_pReqRepeal->CustomerName)) );
            js_pReqRepeal.Set("IdCardType", string(1u, ptrCfd_pReqRepeal->IdCardType).c_str());
            js_pReqRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->IdentifiedCardNo, strlen(ptrCfd_pReqRepeal->IdentifiedCardNo)) );
            js_pReqRepeal.Set("CustType", string(1u, ptrCfd_pReqRepeal->CustType).c_str());
            js_pReqRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankAccount, strlen(ptrCfd_pReqRepeal->BankAccount)) );
            js_pReqRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankPassWord, strlen(ptrCfd_pReqRepeal->BankPassWord)) );
            js_pReqRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->AccountID, strlen(ptrCfd_pReqRepeal->AccountID)) );
            js_pReqRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->Password, strlen(ptrCfd_pReqRepeal->Password)) );
            js_pReqRepeal.Set("InstallID", ptrCfd_pReqRepeal->InstallID);
            js_pReqRepeal.Set("FutureSerial", ptrCfd_pReqRepeal->FutureSerial);
            js_pReqRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->UserID, strlen(ptrCfd_pReqRepeal->UserID)) );
            js_pReqRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqRepeal->VerifyCertNoFlag).c_str());
            js_pReqRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->CurrencyID, strlen(ptrCfd_pReqRepeal->CurrencyID)) );
            js_pReqRepeal.Set("TradeAmount", ptrCfd_pReqRepeal->TradeAmount);
            js_pReqRepeal.Set("FutureFetchAmount", ptrCfd_pReqRepeal->FutureFetchAmount);
            js_pReqRepeal.Set("FeePayFlag", string(1u, ptrCfd_pReqRepeal->FeePayFlag).c_str());
            js_pReqRepeal.Set("CustFee", ptrCfd_pReqRepeal->CustFee);
            js_pReqRepeal.Set("BrokerFee", ptrCfd_pReqRepeal->BrokerFee);
            js_pReqRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->Message, strlen(ptrCfd_pReqRepeal->Message)) );
            js_pReqRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->Digest, strlen(ptrCfd_pReqRepeal->Digest)) );
            js_pReqRepeal.Set("BankAccType", string(1u, ptrCfd_pReqRepeal->BankAccType).c_str());
            js_pReqRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->DeviceID, strlen(ptrCfd_pReqRepeal->DeviceID)) );
            js_pReqRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pReqRepeal->BankSecuAccType).c_str());
            js_pReqRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BrokerIDByBank, strlen(ptrCfd_pReqRepeal->BrokerIDByBank)) );
            js_pReqRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->BankSecuAcc, strlen(ptrCfd_pReqRepeal->BankSecuAcc)) );
            js_pReqRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pReqRepeal->BankPwdFlag).c_str());
            js_pReqRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pReqRepeal->SecuPwdFlag).c_str());
            js_pReqRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->OperNo, strlen(ptrCfd_pReqRepeal->OperNo)) );
            js_pReqRepeal.Set("RequestID", ptrCfd_pReqRepeal->RequestID);
            js_pReqRepeal.Set("TID", ptrCfd_pReqRepeal->TID);
            js_pReqRepeal.Set("TransferStatus", string(1u, ptrCfd_pReqRepeal->TransferStatus).c_str());
            js_pReqRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqRepeal->LongCustomerName, strlen(ptrCfd_pReqRepeal->LongCustomerName)) );
            js_event_data.Set("pReqRepeal", js_pReqRepeal);
            delete ptrCfd_pReqRepeal;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField * pReqQueryAccount, CThostFtdcRspInfoField * pRspInfo)
    {
        
        CThostFtdcReqQueryAccountField *ptrCfd_pReqQueryAccount = new CThostFtdcReqQueryAccountField();
        if(pReqQueryAccount)
        {
            memcpy(ptrCfd_pReqQueryAccount, pReqQueryAccount, sizeof(CThostFtdcReqQueryAccountField));
        }
        else
        {
            memset(ptrCfd_pReqQueryAccount, 0, sizeof(CThostFtdcReqQueryAccountField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnErrRtnQueryBankBalanceByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqQueryAccount = Napi::Object::New(env);
            js_pReqQueryAccount.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradeCode, strlen(ptrCfd_pReqQueryAccount->TradeCode)) );
            js_pReqQueryAccount.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankID, strlen(ptrCfd_pReqQueryAccount->BankID)) );
            js_pReqQueryAccount.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankBranchID, strlen(ptrCfd_pReqQueryAccount->BankBranchID)) );
            js_pReqQueryAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BrokerID, strlen(ptrCfd_pReqQueryAccount->BrokerID)) );
            js_pReqQueryAccount.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BrokerBranchID, strlen(ptrCfd_pReqQueryAccount->BrokerBranchID)) );
            js_pReqQueryAccount.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradeDate, strlen(ptrCfd_pReqQueryAccount->TradeDate)) );
            js_pReqQueryAccount.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradeTime, strlen(ptrCfd_pReqQueryAccount->TradeTime)) );
            js_pReqQueryAccount.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankSerial, strlen(ptrCfd_pReqQueryAccount->BankSerial)) );
            js_pReqQueryAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradingDay, strlen(ptrCfd_pReqQueryAccount->TradingDay)) );
            js_pReqQueryAccount.Set("PlateSerial", ptrCfd_pReqQueryAccount->PlateSerial);
            js_pReqQueryAccount.Set("LastFragment", string(1u, ptrCfd_pReqQueryAccount->LastFragment).c_str());
            js_pReqQueryAccount.Set("SessionID", ptrCfd_pReqQueryAccount->SessionID);
            js_pReqQueryAccount.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->CustomerName, strlen(ptrCfd_pReqQueryAccount->CustomerName)) );
            js_pReqQueryAccount.Set("IdCardType", string(1u, ptrCfd_pReqQueryAccount->IdCardType).c_str());
            js_pReqQueryAccount.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->IdentifiedCardNo, strlen(ptrCfd_pReqQueryAccount->IdentifiedCardNo)) );
            js_pReqQueryAccount.Set("CustType", string(1u, ptrCfd_pReqQueryAccount->CustType).c_str());
            js_pReqQueryAccount.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankAccount, strlen(ptrCfd_pReqQueryAccount->BankAccount)) );
            js_pReqQueryAccount.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankPassWord, strlen(ptrCfd_pReqQueryAccount->BankPassWord)) );
            js_pReqQueryAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->AccountID, strlen(ptrCfd_pReqQueryAccount->AccountID)) );
            js_pReqQueryAccount.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->Password, strlen(ptrCfd_pReqQueryAccount->Password)) );
            js_pReqQueryAccount.Set("FutureSerial", ptrCfd_pReqQueryAccount->FutureSerial);
            js_pReqQueryAccount.Set("InstallID", ptrCfd_pReqQueryAccount->InstallID);
            js_pReqQueryAccount.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->UserID, strlen(ptrCfd_pReqQueryAccount->UserID)) );
            js_pReqQueryAccount.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqQueryAccount->VerifyCertNoFlag).c_str());
            js_pReqQueryAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->CurrencyID, strlen(ptrCfd_pReqQueryAccount->CurrencyID)) );
            js_pReqQueryAccount.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->Digest, strlen(ptrCfd_pReqQueryAccount->Digest)) );
            js_pReqQueryAccount.Set("BankAccType", string(1u, ptrCfd_pReqQueryAccount->BankAccType).c_str());
            js_pReqQueryAccount.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->DeviceID, strlen(ptrCfd_pReqQueryAccount->DeviceID)) );
            js_pReqQueryAccount.Set("BankSecuAccType", string(1u, ptrCfd_pReqQueryAccount->BankSecuAccType).c_str());
            js_pReqQueryAccount.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BrokerIDByBank, strlen(ptrCfd_pReqQueryAccount->BrokerIDByBank)) );
            js_pReqQueryAccount.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankSecuAcc, strlen(ptrCfd_pReqQueryAccount->BankSecuAcc)) );
            js_pReqQueryAccount.Set("BankPwdFlag", string(1u, ptrCfd_pReqQueryAccount->BankPwdFlag).c_str());
            js_pReqQueryAccount.Set("SecuPwdFlag", string(1u, ptrCfd_pReqQueryAccount->SecuPwdFlag).c_str());
            js_pReqQueryAccount.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->OperNo, strlen(ptrCfd_pReqQueryAccount->OperNo)) );
            js_pReqQueryAccount.Set("RequestID", ptrCfd_pReqQueryAccount->RequestID);
            js_pReqQueryAccount.Set("TID", ptrCfd_pReqQueryAccount->TID);
            js_pReqQueryAccount.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->LongCustomerName, strlen(ptrCfd_pReqQueryAccount->LongCustomerName)) );
            js_event_data.Set("pReqQueryAccount", js_pReqQueryAccount);
            delete ptrCfd_pReqQueryAccount;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField * pRspRepeal)
    {
        
        CThostFtdcRspRepealField *ptrCfd_pRspRepeal = new CThostFtdcRspRepealField();
        if(pRspRepeal)
        {
            memcpy(ptrCfd_pRspRepeal, pRspRepeal, sizeof(CThostFtdcRspRepealField));
        }
        else
        {
            memset(ptrCfd_pRspRepeal, 0, sizeof(CThostFtdcRspRepealField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnRepealFromBankToFutureByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspRepeal = Napi::Object::New(env);
            js_pRspRepeal.Set("RepealTimeInterval", ptrCfd_pRspRepeal->RepealTimeInterval);
            js_pRspRepeal.Set("RepealedTimes", ptrCfd_pRspRepeal->RepealedTimes);
            js_pRspRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pRspRepeal->BankRepealFlag).c_str());
            js_pRspRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pRspRepeal->BrokerRepealFlag).c_str());
            js_pRspRepeal.Set("PlateRepealSerial", ptrCfd_pRspRepeal->PlateRepealSerial);
            js_pRspRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankRepealSerial, strlen(ptrCfd_pRspRepeal->BankRepealSerial)) );
            js_pRspRepeal.Set("FutureRepealSerial", ptrCfd_pRspRepeal->FutureRepealSerial);
            js_pRspRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeCode, strlen(ptrCfd_pRspRepeal->TradeCode)) );
            js_pRspRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankID, strlen(ptrCfd_pRspRepeal->BankID)) );
            js_pRspRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankBranchID, strlen(ptrCfd_pRspRepeal->BankBranchID)) );
            js_pRspRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerID, strlen(ptrCfd_pRspRepeal->BrokerID)) );
            js_pRspRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerBranchID, strlen(ptrCfd_pRspRepeal->BrokerBranchID)) );
            js_pRspRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeDate, strlen(ptrCfd_pRspRepeal->TradeDate)) );
            js_pRspRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeTime, strlen(ptrCfd_pRspRepeal->TradeTime)) );
            js_pRspRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSerial, strlen(ptrCfd_pRspRepeal->BankSerial)) );
            js_pRspRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradingDay, strlen(ptrCfd_pRspRepeal->TradingDay)) );
            js_pRspRepeal.Set("PlateSerial", ptrCfd_pRspRepeal->PlateSerial);
            js_pRspRepeal.Set("LastFragment", string(1u, ptrCfd_pRspRepeal->LastFragment).c_str());
            js_pRspRepeal.Set("SessionID", ptrCfd_pRspRepeal->SessionID);
            js_pRspRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CustomerName, strlen(ptrCfd_pRspRepeal->CustomerName)) );
            js_pRspRepeal.Set("IdCardType", string(1u, ptrCfd_pRspRepeal->IdCardType).c_str());
            js_pRspRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->IdentifiedCardNo, strlen(ptrCfd_pRspRepeal->IdentifiedCardNo)) );
            js_pRspRepeal.Set("CustType", string(1u, ptrCfd_pRspRepeal->CustType).c_str());
            js_pRspRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankAccount, strlen(ptrCfd_pRspRepeal->BankAccount)) );
            js_pRspRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankPassWord, strlen(ptrCfd_pRspRepeal->BankPassWord)) );
            js_pRspRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->AccountID, strlen(ptrCfd_pRspRepeal->AccountID)) );
            js_pRspRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Password, strlen(ptrCfd_pRspRepeal->Password)) );
            js_pRspRepeal.Set("InstallID", ptrCfd_pRspRepeal->InstallID);
            js_pRspRepeal.Set("FutureSerial", ptrCfd_pRspRepeal->FutureSerial);
            js_pRspRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->UserID, strlen(ptrCfd_pRspRepeal->UserID)) );
            js_pRspRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspRepeal->VerifyCertNoFlag).c_str());
            js_pRspRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CurrencyID, strlen(ptrCfd_pRspRepeal->CurrencyID)) );
            js_pRspRepeal.Set("TradeAmount", ptrCfd_pRspRepeal->TradeAmount);
            js_pRspRepeal.Set("FutureFetchAmount", ptrCfd_pRspRepeal->FutureFetchAmount);
            js_pRspRepeal.Set("FeePayFlag", string(1u, ptrCfd_pRspRepeal->FeePayFlag).c_str());
            js_pRspRepeal.Set("CustFee", ptrCfd_pRspRepeal->CustFee);
            js_pRspRepeal.Set("BrokerFee", ptrCfd_pRspRepeal->BrokerFee);
            js_pRspRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Message, strlen(ptrCfd_pRspRepeal->Message)) );
            js_pRspRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Digest, strlen(ptrCfd_pRspRepeal->Digest)) );
            js_pRspRepeal.Set("BankAccType", string(1u, ptrCfd_pRspRepeal->BankAccType).c_str());
            js_pRspRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->DeviceID, strlen(ptrCfd_pRspRepeal->DeviceID)) );
            js_pRspRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pRspRepeal->BankSecuAccType).c_str());
            js_pRspRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerIDByBank, strlen(ptrCfd_pRspRepeal->BrokerIDByBank)) );
            js_pRspRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSecuAcc, strlen(ptrCfd_pRspRepeal->BankSecuAcc)) );
            js_pRspRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pRspRepeal->BankPwdFlag).c_str());
            js_pRspRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pRspRepeal->SecuPwdFlag).c_str());
            js_pRspRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->OperNo, strlen(ptrCfd_pRspRepeal->OperNo)) );
            js_pRspRepeal.Set("RequestID", ptrCfd_pRspRepeal->RequestID);
            js_pRspRepeal.Set("TID", ptrCfd_pRspRepeal->TID);
            js_pRspRepeal.Set("TransferStatus", string(1u, ptrCfd_pRspRepeal->TransferStatus).c_str());
            js_pRspRepeal.Set("ErrorID", ptrCfd_pRspRepeal->ErrorID);
            js_pRspRepeal.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->ErrorMsg, strlen(ptrCfd_pRspRepeal->ErrorMsg)) );
            js_pRspRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->LongCustomerName, strlen(ptrCfd_pRspRepeal->LongCustomerName)) );
            js_event_data.Set("pRspRepeal", js_pRspRepeal);
            delete ptrCfd_pRspRepeal;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField * pRspRepeal)
    {
        
        CThostFtdcRspRepealField *ptrCfd_pRspRepeal = new CThostFtdcRspRepealField();
        if(pRspRepeal)
        {
            memcpy(ptrCfd_pRspRepeal, pRspRepeal, sizeof(CThostFtdcRspRepealField));
        }
        else
        {
            memset(ptrCfd_pRspRepeal, 0, sizeof(CThostFtdcRspRepealField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnRepealFromFutureToBankByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRspRepeal = Napi::Object::New(env);
            js_pRspRepeal.Set("RepealTimeInterval", ptrCfd_pRspRepeal->RepealTimeInterval);
            js_pRspRepeal.Set("RepealedTimes", ptrCfd_pRspRepeal->RepealedTimes);
            js_pRspRepeal.Set("BankRepealFlag", string(1u, ptrCfd_pRspRepeal->BankRepealFlag).c_str());
            js_pRspRepeal.Set("BrokerRepealFlag", string(1u, ptrCfd_pRspRepeal->BrokerRepealFlag).c_str());
            js_pRspRepeal.Set("PlateRepealSerial", ptrCfd_pRspRepeal->PlateRepealSerial);
            js_pRspRepeal.Set("BankRepealSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankRepealSerial, strlen(ptrCfd_pRspRepeal->BankRepealSerial)) );
            js_pRspRepeal.Set("FutureRepealSerial", ptrCfd_pRspRepeal->FutureRepealSerial);
            js_pRspRepeal.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeCode, strlen(ptrCfd_pRspRepeal->TradeCode)) );
            js_pRspRepeal.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankID, strlen(ptrCfd_pRspRepeal->BankID)) );
            js_pRspRepeal.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankBranchID, strlen(ptrCfd_pRspRepeal->BankBranchID)) );
            js_pRspRepeal.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerID, strlen(ptrCfd_pRspRepeal->BrokerID)) );
            js_pRspRepeal.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerBranchID, strlen(ptrCfd_pRspRepeal->BrokerBranchID)) );
            js_pRspRepeal.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeDate, strlen(ptrCfd_pRspRepeal->TradeDate)) );
            js_pRspRepeal.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradeTime, strlen(ptrCfd_pRspRepeal->TradeTime)) );
            js_pRspRepeal.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSerial, strlen(ptrCfd_pRspRepeal->BankSerial)) );
            js_pRspRepeal.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->TradingDay, strlen(ptrCfd_pRspRepeal->TradingDay)) );
            js_pRspRepeal.Set("PlateSerial", ptrCfd_pRspRepeal->PlateSerial);
            js_pRspRepeal.Set("LastFragment", string(1u, ptrCfd_pRspRepeal->LastFragment).c_str());
            js_pRspRepeal.Set("SessionID", ptrCfd_pRspRepeal->SessionID);
            js_pRspRepeal.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CustomerName, strlen(ptrCfd_pRspRepeal->CustomerName)) );
            js_pRspRepeal.Set("IdCardType", string(1u, ptrCfd_pRspRepeal->IdCardType).c_str());
            js_pRspRepeal.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->IdentifiedCardNo, strlen(ptrCfd_pRspRepeal->IdentifiedCardNo)) );
            js_pRspRepeal.Set("CustType", string(1u, ptrCfd_pRspRepeal->CustType).c_str());
            js_pRspRepeal.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankAccount, strlen(ptrCfd_pRspRepeal->BankAccount)) );
            js_pRspRepeal.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankPassWord, strlen(ptrCfd_pRspRepeal->BankPassWord)) );
            js_pRspRepeal.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->AccountID, strlen(ptrCfd_pRspRepeal->AccountID)) );
            js_pRspRepeal.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Password, strlen(ptrCfd_pRspRepeal->Password)) );
            js_pRspRepeal.Set("InstallID", ptrCfd_pRspRepeal->InstallID);
            js_pRspRepeal.Set("FutureSerial", ptrCfd_pRspRepeal->FutureSerial);
            js_pRspRepeal.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->UserID, strlen(ptrCfd_pRspRepeal->UserID)) );
            js_pRspRepeal.Set("VerifyCertNoFlag", string(1u, ptrCfd_pRspRepeal->VerifyCertNoFlag).c_str());
            js_pRspRepeal.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->CurrencyID, strlen(ptrCfd_pRspRepeal->CurrencyID)) );
            js_pRspRepeal.Set("TradeAmount", ptrCfd_pRspRepeal->TradeAmount);
            js_pRspRepeal.Set("FutureFetchAmount", ptrCfd_pRspRepeal->FutureFetchAmount);
            js_pRspRepeal.Set("FeePayFlag", string(1u, ptrCfd_pRspRepeal->FeePayFlag).c_str());
            js_pRspRepeal.Set("CustFee", ptrCfd_pRspRepeal->CustFee);
            js_pRspRepeal.Set("BrokerFee", ptrCfd_pRspRepeal->BrokerFee);
            js_pRspRepeal.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Message, strlen(ptrCfd_pRspRepeal->Message)) );
            js_pRspRepeal.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->Digest, strlen(ptrCfd_pRspRepeal->Digest)) );
            js_pRspRepeal.Set("BankAccType", string(1u, ptrCfd_pRspRepeal->BankAccType).c_str());
            js_pRspRepeal.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->DeviceID, strlen(ptrCfd_pRspRepeal->DeviceID)) );
            js_pRspRepeal.Set("BankSecuAccType", string(1u, ptrCfd_pRspRepeal->BankSecuAccType).c_str());
            js_pRspRepeal.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BrokerIDByBank, strlen(ptrCfd_pRspRepeal->BrokerIDByBank)) );
            js_pRspRepeal.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->BankSecuAcc, strlen(ptrCfd_pRspRepeal->BankSecuAcc)) );
            js_pRspRepeal.Set("BankPwdFlag", string(1u, ptrCfd_pRspRepeal->BankPwdFlag).c_str());
            js_pRspRepeal.Set("SecuPwdFlag", string(1u, ptrCfd_pRspRepeal->SecuPwdFlag).c_str());
            js_pRspRepeal.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->OperNo, strlen(ptrCfd_pRspRepeal->OperNo)) );
            js_pRspRepeal.Set("RequestID", ptrCfd_pRspRepeal->RequestID);
            js_pRspRepeal.Set("TID", ptrCfd_pRspRepeal->TID);
            js_pRspRepeal.Set("TransferStatus", string(1u, ptrCfd_pRspRepeal->TransferStatus).c_str());
            js_pRspRepeal.Set("ErrorID", ptrCfd_pRspRepeal->ErrorID);
            js_pRspRepeal.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->ErrorMsg, strlen(ptrCfd_pRspRepeal->ErrorMsg)) );
            js_pRspRepeal.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pRspRepeal->LongCustomerName, strlen(ptrCfd_pRspRepeal->LongCustomerName)) );
            js_event_data.Set("pRspRepeal", js_pRspRepeal);
            delete ptrCfd_pRspRepeal;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcReqTransferField *ptrCfd_pReqTransfer = new CThostFtdcReqTransferField();
        if(pReqTransfer)
        {
            memcpy(ptrCfd_pReqTransfer, pReqTransfer, sizeof(CThostFtdcReqTransferField));
        }
        else
        {
            memset(ptrCfd_pReqTransfer, 0, sizeof(CThostFtdcReqTransferField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspFromBankToFutureByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqTransfer = Napi::Object::New(env);
            js_pReqTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeCode, strlen(ptrCfd_pReqTransfer->TradeCode)) );
            js_pReqTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankID, strlen(ptrCfd_pReqTransfer->BankID)) );
            js_pReqTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankBranchID, strlen(ptrCfd_pReqTransfer->BankBranchID)) );
            js_pReqTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerID, strlen(ptrCfd_pReqTransfer->BrokerID)) );
            js_pReqTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerBranchID, strlen(ptrCfd_pReqTransfer->BrokerBranchID)) );
            js_pReqTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeDate, strlen(ptrCfd_pReqTransfer->TradeDate)) );
            js_pReqTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeTime, strlen(ptrCfd_pReqTransfer->TradeTime)) );
            js_pReqTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSerial, strlen(ptrCfd_pReqTransfer->BankSerial)) );
            js_pReqTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradingDay, strlen(ptrCfd_pReqTransfer->TradingDay)) );
            js_pReqTransfer.Set("PlateSerial", ptrCfd_pReqTransfer->PlateSerial);
            js_pReqTransfer.Set("LastFragment", string(1u, ptrCfd_pReqTransfer->LastFragment).c_str());
            js_pReqTransfer.Set("SessionID", ptrCfd_pReqTransfer->SessionID);
            js_pReqTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CustomerName, strlen(ptrCfd_pReqTransfer->CustomerName)) );
            js_pReqTransfer.Set("IdCardType", string(1u, ptrCfd_pReqTransfer->IdCardType).c_str());
            js_pReqTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->IdentifiedCardNo, strlen(ptrCfd_pReqTransfer->IdentifiedCardNo)) );
            js_pReqTransfer.Set("CustType", string(1u, ptrCfd_pReqTransfer->CustType).c_str());
            js_pReqTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankAccount, strlen(ptrCfd_pReqTransfer->BankAccount)) );
            js_pReqTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankPassWord, strlen(ptrCfd_pReqTransfer->BankPassWord)) );
            js_pReqTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->AccountID, strlen(ptrCfd_pReqTransfer->AccountID)) );
            js_pReqTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Password, strlen(ptrCfd_pReqTransfer->Password)) );
            js_pReqTransfer.Set("InstallID", ptrCfd_pReqTransfer->InstallID);
            js_pReqTransfer.Set("FutureSerial", ptrCfd_pReqTransfer->FutureSerial);
            js_pReqTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->UserID, strlen(ptrCfd_pReqTransfer->UserID)) );
            js_pReqTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqTransfer->VerifyCertNoFlag).c_str());
            js_pReqTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CurrencyID, strlen(ptrCfd_pReqTransfer->CurrencyID)) );
            js_pReqTransfer.Set("TradeAmount", ptrCfd_pReqTransfer->TradeAmount);
            js_pReqTransfer.Set("FutureFetchAmount", ptrCfd_pReqTransfer->FutureFetchAmount);
            js_pReqTransfer.Set("FeePayFlag", string(1u, ptrCfd_pReqTransfer->FeePayFlag).c_str());
            js_pReqTransfer.Set("CustFee", ptrCfd_pReqTransfer->CustFee);
            js_pReqTransfer.Set("BrokerFee", ptrCfd_pReqTransfer->BrokerFee);
            js_pReqTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Message, strlen(ptrCfd_pReqTransfer->Message)) );
            js_pReqTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Digest, strlen(ptrCfd_pReqTransfer->Digest)) );
            js_pReqTransfer.Set("BankAccType", string(1u, ptrCfd_pReqTransfer->BankAccType).c_str());
            js_pReqTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->DeviceID, strlen(ptrCfd_pReqTransfer->DeviceID)) );
            js_pReqTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pReqTransfer->BankSecuAccType).c_str());
            js_pReqTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerIDByBank, strlen(ptrCfd_pReqTransfer->BrokerIDByBank)) );
            js_pReqTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSecuAcc, strlen(ptrCfd_pReqTransfer->BankSecuAcc)) );
            js_pReqTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pReqTransfer->BankPwdFlag).c_str());
            js_pReqTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pReqTransfer->SecuPwdFlag).c_str());
            js_pReqTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->OperNo, strlen(ptrCfd_pReqTransfer->OperNo)) );
            js_pReqTransfer.Set("RequestID", ptrCfd_pReqTransfer->RequestID);
            js_pReqTransfer.Set("TID", ptrCfd_pReqTransfer->TID);
            js_pReqTransfer.Set("TransferStatus", string(1u, ptrCfd_pReqTransfer->TransferStatus).c_str());
            js_pReqTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->LongCustomerName, strlen(ptrCfd_pReqTransfer->LongCustomerName)) );
            js_event_data.Set("pReqTransfer", js_pReqTransfer);
            delete ptrCfd_pReqTransfer;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcReqTransferField *ptrCfd_pReqTransfer = new CThostFtdcReqTransferField();
        if(pReqTransfer)
        {
            memcpy(ptrCfd_pReqTransfer, pReqTransfer, sizeof(CThostFtdcReqTransferField));
        }
        else
        {
            memset(ptrCfd_pReqTransfer, 0, sizeof(CThostFtdcReqTransferField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspFromFutureToBankByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqTransfer = Napi::Object::New(env);
            js_pReqTransfer.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeCode, strlen(ptrCfd_pReqTransfer->TradeCode)) );
            js_pReqTransfer.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankID, strlen(ptrCfd_pReqTransfer->BankID)) );
            js_pReqTransfer.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankBranchID, strlen(ptrCfd_pReqTransfer->BankBranchID)) );
            js_pReqTransfer.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerID, strlen(ptrCfd_pReqTransfer->BrokerID)) );
            js_pReqTransfer.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerBranchID, strlen(ptrCfd_pReqTransfer->BrokerBranchID)) );
            js_pReqTransfer.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeDate, strlen(ptrCfd_pReqTransfer->TradeDate)) );
            js_pReqTransfer.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradeTime, strlen(ptrCfd_pReqTransfer->TradeTime)) );
            js_pReqTransfer.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSerial, strlen(ptrCfd_pReqTransfer->BankSerial)) );
            js_pReqTransfer.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->TradingDay, strlen(ptrCfd_pReqTransfer->TradingDay)) );
            js_pReqTransfer.Set("PlateSerial", ptrCfd_pReqTransfer->PlateSerial);
            js_pReqTransfer.Set("LastFragment", string(1u, ptrCfd_pReqTransfer->LastFragment).c_str());
            js_pReqTransfer.Set("SessionID", ptrCfd_pReqTransfer->SessionID);
            js_pReqTransfer.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CustomerName, strlen(ptrCfd_pReqTransfer->CustomerName)) );
            js_pReqTransfer.Set("IdCardType", string(1u, ptrCfd_pReqTransfer->IdCardType).c_str());
            js_pReqTransfer.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->IdentifiedCardNo, strlen(ptrCfd_pReqTransfer->IdentifiedCardNo)) );
            js_pReqTransfer.Set("CustType", string(1u, ptrCfd_pReqTransfer->CustType).c_str());
            js_pReqTransfer.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankAccount, strlen(ptrCfd_pReqTransfer->BankAccount)) );
            js_pReqTransfer.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankPassWord, strlen(ptrCfd_pReqTransfer->BankPassWord)) );
            js_pReqTransfer.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->AccountID, strlen(ptrCfd_pReqTransfer->AccountID)) );
            js_pReqTransfer.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Password, strlen(ptrCfd_pReqTransfer->Password)) );
            js_pReqTransfer.Set("InstallID", ptrCfd_pReqTransfer->InstallID);
            js_pReqTransfer.Set("FutureSerial", ptrCfd_pReqTransfer->FutureSerial);
            js_pReqTransfer.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->UserID, strlen(ptrCfd_pReqTransfer->UserID)) );
            js_pReqTransfer.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqTransfer->VerifyCertNoFlag).c_str());
            js_pReqTransfer.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->CurrencyID, strlen(ptrCfd_pReqTransfer->CurrencyID)) );
            js_pReqTransfer.Set("TradeAmount", ptrCfd_pReqTransfer->TradeAmount);
            js_pReqTransfer.Set("FutureFetchAmount", ptrCfd_pReqTransfer->FutureFetchAmount);
            js_pReqTransfer.Set("FeePayFlag", string(1u, ptrCfd_pReqTransfer->FeePayFlag).c_str());
            js_pReqTransfer.Set("CustFee", ptrCfd_pReqTransfer->CustFee);
            js_pReqTransfer.Set("BrokerFee", ptrCfd_pReqTransfer->BrokerFee);
            js_pReqTransfer.Set("Message", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Message, strlen(ptrCfd_pReqTransfer->Message)) );
            js_pReqTransfer.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->Digest, strlen(ptrCfd_pReqTransfer->Digest)) );
            js_pReqTransfer.Set("BankAccType", string(1u, ptrCfd_pReqTransfer->BankAccType).c_str());
            js_pReqTransfer.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->DeviceID, strlen(ptrCfd_pReqTransfer->DeviceID)) );
            js_pReqTransfer.Set("BankSecuAccType", string(1u, ptrCfd_pReqTransfer->BankSecuAccType).c_str());
            js_pReqTransfer.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BrokerIDByBank, strlen(ptrCfd_pReqTransfer->BrokerIDByBank)) );
            js_pReqTransfer.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->BankSecuAcc, strlen(ptrCfd_pReqTransfer->BankSecuAcc)) );
            js_pReqTransfer.Set("BankPwdFlag", string(1u, ptrCfd_pReqTransfer->BankPwdFlag).c_str());
            js_pReqTransfer.Set("SecuPwdFlag", string(1u, ptrCfd_pReqTransfer->SecuPwdFlag).c_str());
            js_pReqTransfer.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->OperNo, strlen(ptrCfd_pReqTransfer->OperNo)) );
            js_pReqTransfer.Set("RequestID", ptrCfd_pReqTransfer->RequestID);
            js_pReqTransfer.Set("TID", ptrCfd_pReqTransfer->TID);
            js_pReqTransfer.Set("TransferStatus", string(1u, ptrCfd_pReqTransfer->TransferStatus).c_str());
            js_pReqTransfer.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqTransfer->LongCustomerName, strlen(ptrCfd_pReqTransfer->LongCustomerName)) );
            js_event_data.Set("pReqTransfer", js_pReqTransfer);
            delete ptrCfd_pReqTransfer;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField * pReqQueryAccount, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcReqQueryAccountField *ptrCfd_pReqQueryAccount = new CThostFtdcReqQueryAccountField();
        if(pReqQueryAccount)
        {
            memcpy(ptrCfd_pReqQueryAccount, pReqQueryAccount, sizeof(CThostFtdcReqQueryAccountField));
        }
        else
        {
            memset(ptrCfd_pReqQueryAccount, 0, sizeof(CThostFtdcReqQueryAccountField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQueryBankAccountMoneyByFuture");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pReqQueryAccount = Napi::Object::New(env);
            js_pReqQueryAccount.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradeCode, strlen(ptrCfd_pReqQueryAccount->TradeCode)) );
            js_pReqQueryAccount.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankID, strlen(ptrCfd_pReqQueryAccount->BankID)) );
            js_pReqQueryAccount.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankBranchID, strlen(ptrCfd_pReqQueryAccount->BankBranchID)) );
            js_pReqQueryAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BrokerID, strlen(ptrCfd_pReqQueryAccount->BrokerID)) );
            js_pReqQueryAccount.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BrokerBranchID, strlen(ptrCfd_pReqQueryAccount->BrokerBranchID)) );
            js_pReqQueryAccount.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradeDate, strlen(ptrCfd_pReqQueryAccount->TradeDate)) );
            js_pReqQueryAccount.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradeTime, strlen(ptrCfd_pReqQueryAccount->TradeTime)) );
            js_pReqQueryAccount.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankSerial, strlen(ptrCfd_pReqQueryAccount->BankSerial)) );
            js_pReqQueryAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->TradingDay, strlen(ptrCfd_pReqQueryAccount->TradingDay)) );
            js_pReqQueryAccount.Set("PlateSerial", ptrCfd_pReqQueryAccount->PlateSerial);
            js_pReqQueryAccount.Set("LastFragment", string(1u, ptrCfd_pReqQueryAccount->LastFragment).c_str());
            js_pReqQueryAccount.Set("SessionID", ptrCfd_pReqQueryAccount->SessionID);
            js_pReqQueryAccount.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->CustomerName, strlen(ptrCfd_pReqQueryAccount->CustomerName)) );
            js_pReqQueryAccount.Set("IdCardType", string(1u, ptrCfd_pReqQueryAccount->IdCardType).c_str());
            js_pReqQueryAccount.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->IdentifiedCardNo, strlen(ptrCfd_pReqQueryAccount->IdentifiedCardNo)) );
            js_pReqQueryAccount.Set("CustType", string(1u, ptrCfd_pReqQueryAccount->CustType).c_str());
            js_pReqQueryAccount.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankAccount, strlen(ptrCfd_pReqQueryAccount->BankAccount)) );
            js_pReqQueryAccount.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankPassWord, strlen(ptrCfd_pReqQueryAccount->BankPassWord)) );
            js_pReqQueryAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->AccountID, strlen(ptrCfd_pReqQueryAccount->AccountID)) );
            js_pReqQueryAccount.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->Password, strlen(ptrCfd_pReqQueryAccount->Password)) );
            js_pReqQueryAccount.Set("FutureSerial", ptrCfd_pReqQueryAccount->FutureSerial);
            js_pReqQueryAccount.Set("InstallID", ptrCfd_pReqQueryAccount->InstallID);
            js_pReqQueryAccount.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->UserID, strlen(ptrCfd_pReqQueryAccount->UserID)) );
            js_pReqQueryAccount.Set("VerifyCertNoFlag", string(1u, ptrCfd_pReqQueryAccount->VerifyCertNoFlag).c_str());
            js_pReqQueryAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->CurrencyID, strlen(ptrCfd_pReqQueryAccount->CurrencyID)) );
            js_pReqQueryAccount.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->Digest, strlen(ptrCfd_pReqQueryAccount->Digest)) );
            js_pReqQueryAccount.Set("BankAccType", string(1u, ptrCfd_pReqQueryAccount->BankAccType).c_str());
            js_pReqQueryAccount.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->DeviceID, strlen(ptrCfd_pReqQueryAccount->DeviceID)) );
            js_pReqQueryAccount.Set("BankSecuAccType", string(1u, ptrCfd_pReqQueryAccount->BankSecuAccType).c_str());
            js_pReqQueryAccount.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BrokerIDByBank, strlen(ptrCfd_pReqQueryAccount->BrokerIDByBank)) );
            js_pReqQueryAccount.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->BankSecuAcc, strlen(ptrCfd_pReqQueryAccount->BankSecuAcc)) );
            js_pReqQueryAccount.Set("BankPwdFlag", string(1u, ptrCfd_pReqQueryAccount->BankPwdFlag).c_str());
            js_pReqQueryAccount.Set("SecuPwdFlag", string(1u, ptrCfd_pReqQueryAccount->SecuPwdFlag).c_str());
            js_pReqQueryAccount.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->OperNo, strlen(ptrCfd_pReqQueryAccount->OperNo)) );
            js_pReqQueryAccount.Set("RequestID", ptrCfd_pReqQueryAccount->RequestID);
            js_pReqQueryAccount.Set("TID", ptrCfd_pReqQueryAccount->TID);
            js_pReqQueryAccount.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pReqQueryAccount->LongCustomerName, strlen(ptrCfd_pReqQueryAccount->LongCustomerName)) );
            js_event_data.Set("pReqQueryAccount", js_pReqQueryAccount);
            delete ptrCfd_pReqQueryAccount;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField * pOpenAccount)
    {
        
        CThostFtdcOpenAccountField *ptrCfd_pOpenAccount = new CThostFtdcOpenAccountField();
        if(pOpenAccount)
        {
            memcpy(ptrCfd_pOpenAccount, pOpenAccount, sizeof(CThostFtdcOpenAccountField));
        }
        else
        {
            memset(ptrCfd_pOpenAccount, 0, sizeof(CThostFtdcOpenAccountField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnOpenAccountByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pOpenAccount = Napi::Object::New(env);
            js_pOpenAccount.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->TradeCode, strlen(ptrCfd_pOpenAccount->TradeCode)) );
            js_pOpenAccount.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BankID, strlen(ptrCfd_pOpenAccount->BankID)) );
            js_pOpenAccount.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BankBranchID, strlen(ptrCfd_pOpenAccount->BankBranchID)) );
            js_pOpenAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BrokerID, strlen(ptrCfd_pOpenAccount->BrokerID)) );
            js_pOpenAccount.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BrokerBranchID, strlen(ptrCfd_pOpenAccount->BrokerBranchID)) );
            js_pOpenAccount.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->TradeDate, strlen(ptrCfd_pOpenAccount->TradeDate)) );
            js_pOpenAccount.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->TradeTime, strlen(ptrCfd_pOpenAccount->TradeTime)) );
            js_pOpenAccount.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BankSerial, strlen(ptrCfd_pOpenAccount->BankSerial)) );
            js_pOpenAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->TradingDay, strlen(ptrCfd_pOpenAccount->TradingDay)) );
            js_pOpenAccount.Set("PlateSerial", ptrCfd_pOpenAccount->PlateSerial);
            js_pOpenAccount.Set("LastFragment", string(1u, ptrCfd_pOpenAccount->LastFragment).c_str());
            js_pOpenAccount.Set("SessionID", ptrCfd_pOpenAccount->SessionID);
            js_pOpenAccount.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->CustomerName, strlen(ptrCfd_pOpenAccount->CustomerName)) );
            js_pOpenAccount.Set("IdCardType", string(1u, ptrCfd_pOpenAccount->IdCardType).c_str());
            js_pOpenAccount.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->IdentifiedCardNo, strlen(ptrCfd_pOpenAccount->IdentifiedCardNo)) );
            js_pOpenAccount.Set("Gender", string(1u, ptrCfd_pOpenAccount->Gender).c_str());
            js_pOpenAccount.Set("CountryCode", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->CountryCode, strlen(ptrCfd_pOpenAccount->CountryCode)) );
            js_pOpenAccount.Set("CustType", string(1u, ptrCfd_pOpenAccount->CustType).c_str());
            js_pOpenAccount.Set("Address", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->Address, strlen(ptrCfd_pOpenAccount->Address)) );
            js_pOpenAccount.Set("ZipCode", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->ZipCode, strlen(ptrCfd_pOpenAccount->ZipCode)) );
            js_pOpenAccount.Set("Telephone", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->Telephone, strlen(ptrCfd_pOpenAccount->Telephone)) );
            js_pOpenAccount.Set("MobilePhone", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->MobilePhone, strlen(ptrCfd_pOpenAccount->MobilePhone)) );
            js_pOpenAccount.Set("Fax", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->Fax, strlen(ptrCfd_pOpenAccount->Fax)) );
            js_pOpenAccount.Set("EMail", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->EMail, strlen(ptrCfd_pOpenAccount->EMail)) );
            js_pOpenAccount.Set("MoneyAccountStatus", string(1u, ptrCfd_pOpenAccount->MoneyAccountStatus).c_str());
            js_pOpenAccount.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BankAccount, strlen(ptrCfd_pOpenAccount->BankAccount)) );
            js_pOpenAccount.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BankPassWord, strlen(ptrCfd_pOpenAccount->BankPassWord)) );
            js_pOpenAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->AccountID, strlen(ptrCfd_pOpenAccount->AccountID)) );
            js_pOpenAccount.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->Password, strlen(ptrCfd_pOpenAccount->Password)) );
            js_pOpenAccount.Set("InstallID", ptrCfd_pOpenAccount->InstallID);
            js_pOpenAccount.Set("VerifyCertNoFlag", string(1u, ptrCfd_pOpenAccount->VerifyCertNoFlag).c_str());
            js_pOpenAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->CurrencyID, strlen(ptrCfd_pOpenAccount->CurrencyID)) );
            js_pOpenAccount.Set("CashExchangeCode", string(1u, ptrCfd_pOpenAccount->CashExchangeCode).c_str());
            js_pOpenAccount.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->Digest, strlen(ptrCfd_pOpenAccount->Digest)) );
            js_pOpenAccount.Set("BankAccType", string(1u, ptrCfd_pOpenAccount->BankAccType).c_str());
            js_pOpenAccount.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->DeviceID, strlen(ptrCfd_pOpenAccount->DeviceID)) );
            js_pOpenAccount.Set("BankSecuAccType", string(1u, ptrCfd_pOpenAccount->BankSecuAccType).c_str());
            js_pOpenAccount.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BrokerIDByBank, strlen(ptrCfd_pOpenAccount->BrokerIDByBank)) );
            js_pOpenAccount.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->BankSecuAcc, strlen(ptrCfd_pOpenAccount->BankSecuAcc)) );
            js_pOpenAccount.Set("BankPwdFlag", string(1u, ptrCfd_pOpenAccount->BankPwdFlag).c_str());
            js_pOpenAccount.Set("SecuPwdFlag", string(1u, ptrCfd_pOpenAccount->SecuPwdFlag).c_str());
            js_pOpenAccount.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->OperNo, strlen(ptrCfd_pOpenAccount->OperNo)) );
            js_pOpenAccount.Set("TID", ptrCfd_pOpenAccount->TID);
            js_pOpenAccount.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->UserID, strlen(ptrCfd_pOpenAccount->UserID)) );
            js_pOpenAccount.Set("ErrorID", ptrCfd_pOpenAccount->ErrorID);
            js_pOpenAccount.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->ErrorMsg, strlen(ptrCfd_pOpenAccount->ErrorMsg)) );
            js_pOpenAccount.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pOpenAccount->LongCustomerName, strlen(ptrCfd_pOpenAccount->LongCustomerName)) );
            js_event_data.Set("pOpenAccount", js_pOpenAccount);
            delete ptrCfd_pOpenAccount;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField * pCancelAccount)
    {
        
        CThostFtdcCancelAccountField *ptrCfd_pCancelAccount = new CThostFtdcCancelAccountField();
        if(pCancelAccount)
        {
            memcpy(ptrCfd_pCancelAccount, pCancelAccount, sizeof(CThostFtdcCancelAccountField));
        }
        else
        {
            memset(ptrCfd_pCancelAccount, 0, sizeof(CThostFtdcCancelAccountField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnCancelAccountByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCancelAccount = Napi::Object::New(env);
            js_pCancelAccount.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->TradeCode, strlen(ptrCfd_pCancelAccount->TradeCode)) );
            js_pCancelAccount.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BankID, strlen(ptrCfd_pCancelAccount->BankID)) );
            js_pCancelAccount.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BankBranchID, strlen(ptrCfd_pCancelAccount->BankBranchID)) );
            js_pCancelAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BrokerID, strlen(ptrCfd_pCancelAccount->BrokerID)) );
            js_pCancelAccount.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BrokerBranchID, strlen(ptrCfd_pCancelAccount->BrokerBranchID)) );
            js_pCancelAccount.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->TradeDate, strlen(ptrCfd_pCancelAccount->TradeDate)) );
            js_pCancelAccount.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->TradeTime, strlen(ptrCfd_pCancelAccount->TradeTime)) );
            js_pCancelAccount.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BankSerial, strlen(ptrCfd_pCancelAccount->BankSerial)) );
            js_pCancelAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->TradingDay, strlen(ptrCfd_pCancelAccount->TradingDay)) );
            js_pCancelAccount.Set("PlateSerial", ptrCfd_pCancelAccount->PlateSerial);
            js_pCancelAccount.Set("LastFragment", string(1u, ptrCfd_pCancelAccount->LastFragment).c_str());
            js_pCancelAccount.Set("SessionID", ptrCfd_pCancelAccount->SessionID);
            js_pCancelAccount.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->CustomerName, strlen(ptrCfd_pCancelAccount->CustomerName)) );
            js_pCancelAccount.Set("IdCardType", string(1u, ptrCfd_pCancelAccount->IdCardType).c_str());
            js_pCancelAccount.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->IdentifiedCardNo, strlen(ptrCfd_pCancelAccount->IdentifiedCardNo)) );
            js_pCancelAccount.Set("Gender", string(1u, ptrCfd_pCancelAccount->Gender).c_str());
            js_pCancelAccount.Set("CountryCode", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->CountryCode, strlen(ptrCfd_pCancelAccount->CountryCode)) );
            js_pCancelAccount.Set("CustType", string(1u, ptrCfd_pCancelAccount->CustType).c_str());
            js_pCancelAccount.Set("Address", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->Address, strlen(ptrCfd_pCancelAccount->Address)) );
            js_pCancelAccount.Set("ZipCode", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->ZipCode, strlen(ptrCfd_pCancelAccount->ZipCode)) );
            js_pCancelAccount.Set("Telephone", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->Telephone, strlen(ptrCfd_pCancelAccount->Telephone)) );
            js_pCancelAccount.Set("MobilePhone", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->MobilePhone, strlen(ptrCfd_pCancelAccount->MobilePhone)) );
            js_pCancelAccount.Set("Fax", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->Fax, strlen(ptrCfd_pCancelAccount->Fax)) );
            js_pCancelAccount.Set("EMail", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->EMail, strlen(ptrCfd_pCancelAccount->EMail)) );
            js_pCancelAccount.Set("MoneyAccountStatus", string(1u, ptrCfd_pCancelAccount->MoneyAccountStatus).c_str());
            js_pCancelAccount.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BankAccount, strlen(ptrCfd_pCancelAccount->BankAccount)) );
            js_pCancelAccount.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BankPassWord, strlen(ptrCfd_pCancelAccount->BankPassWord)) );
            js_pCancelAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->AccountID, strlen(ptrCfd_pCancelAccount->AccountID)) );
            js_pCancelAccount.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->Password, strlen(ptrCfd_pCancelAccount->Password)) );
            js_pCancelAccount.Set("InstallID", ptrCfd_pCancelAccount->InstallID);
            js_pCancelAccount.Set("VerifyCertNoFlag", string(1u, ptrCfd_pCancelAccount->VerifyCertNoFlag).c_str());
            js_pCancelAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->CurrencyID, strlen(ptrCfd_pCancelAccount->CurrencyID)) );
            js_pCancelAccount.Set("CashExchangeCode", string(1u, ptrCfd_pCancelAccount->CashExchangeCode).c_str());
            js_pCancelAccount.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->Digest, strlen(ptrCfd_pCancelAccount->Digest)) );
            js_pCancelAccount.Set("BankAccType", string(1u, ptrCfd_pCancelAccount->BankAccType).c_str());
            js_pCancelAccount.Set("DeviceID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->DeviceID, strlen(ptrCfd_pCancelAccount->DeviceID)) );
            js_pCancelAccount.Set("BankSecuAccType", string(1u, ptrCfd_pCancelAccount->BankSecuAccType).c_str());
            js_pCancelAccount.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BrokerIDByBank, strlen(ptrCfd_pCancelAccount->BrokerIDByBank)) );
            js_pCancelAccount.Set("BankSecuAcc", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->BankSecuAcc, strlen(ptrCfd_pCancelAccount->BankSecuAcc)) );
            js_pCancelAccount.Set("BankPwdFlag", string(1u, ptrCfd_pCancelAccount->BankPwdFlag).c_str());
            js_pCancelAccount.Set("SecuPwdFlag", string(1u, ptrCfd_pCancelAccount->SecuPwdFlag).c_str());
            js_pCancelAccount.Set("OperNo", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->OperNo, strlen(ptrCfd_pCancelAccount->OperNo)) );
            js_pCancelAccount.Set("TID", ptrCfd_pCancelAccount->TID);
            js_pCancelAccount.Set("UserID", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->UserID, strlen(ptrCfd_pCancelAccount->UserID)) );
            js_pCancelAccount.Set("ErrorID", ptrCfd_pCancelAccount->ErrorID);
            js_pCancelAccount.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->ErrorMsg, strlen(ptrCfd_pCancelAccount->ErrorMsg)) );
            js_pCancelAccount.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pCancelAccount->LongCustomerName, strlen(ptrCfd_pCancelAccount->LongCustomerName)) );
            js_event_data.Set("pCancelAccount", js_pCancelAccount);
            delete ptrCfd_pCancelAccount;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField * pChangeAccount)
    {
        
        CThostFtdcChangeAccountField *ptrCfd_pChangeAccount = new CThostFtdcChangeAccountField();
        if(pChangeAccount)
        {
            memcpy(ptrCfd_pChangeAccount, pChangeAccount, sizeof(CThostFtdcChangeAccountField));
        }
        else
        {
            memset(ptrCfd_pChangeAccount, 0, sizeof(CThostFtdcChangeAccountField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnChangeAccountByBank");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pChangeAccount = Napi::Object::New(env);
            js_pChangeAccount.Set("TradeCode", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->TradeCode, strlen(ptrCfd_pChangeAccount->TradeCode)) );
            js_pChangeAccount.Set("BankID", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BankID, strlen(ptrCfd_pChangeAccount->BankID)) );
            js_pChangeAccount.Set("BankBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BankBranchID, strlen(ptrCfd_pChangeAccount->BankBranchID)) );
            js_pChangeAccount.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BrokerID, strlen(ptrCfd_pChangeAccount->BrokerID)) );
            js_pChangeAccount.Set("BrokerBranchID", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BrokerBranchID, strlen(ptrCfd_pChangeAccount->BrokerBranchID)) );
            js_pChangeAccount.Set("TradeDate", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->TradeDate, strlen(ptrCfd_pChangeAccount->TradeDate)) );
            js_pChangeAccount.Set("TradeTime", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->TradeTime, strlen(ptrCfd_pChangeAccount->TradeTime)) );
            js_pChangeAccount.Set("BankSerial", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BankSerial, strlen(ptrCfd_pChangeAccount->BankSerial)) );
            js_pChangeAccount.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->TradingDay, strlen(ptrCfd_pChangeAccount->TradingDay)) );
            js_pChangeAccount.Set("PlateSerial", ptrCfd_pChangeAccount->PlateSerial);
            js_pChangeAccount.Set("LastFragment", string(1u, ptrCfd_pChangeAccount->LastFragment).c_str());
            js_pChangeAccount.Set("SessionID", ptrCfd_pChangeAccount->SessionID);
            js_pChangeAccount.Set("CustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->CustomerName, strlen(ptrCfd_pChangeAccount->CustomerName)) );
            js_pChangeAccount.Set("IdCardType", string(1u, ptrCfd_pChangeAccount->IdCardType).c_str());
            js_pChangeAccount.Set("IdentifiedCardNo", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->IdentifiedCardNo, strlen(ptrCfd_pChangeAccount->IdentifiedCardNo)) );
            js_pChangeAccount.Set("Gender", string(1u, ptrCfd_pChangeAccount->Gender).c_str());
            js_pChangeAccount.Set("CountryCode", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->CountryCode, strlen(ptrCfd_pChangeAccount->CountryCode)) );
            js_pChangeAccount.Set("CustType", string(1u, ptrCfd_pChangeAccount->CustType).c_str());
            js_pChangeAccount.Set("Address", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->Address, strlen(ptrCfd_pChangeAccount->Address)) );
            js_pChangeAccount.Set("ZipCode", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->ZipCode, strlen(ptrCfd_pChangeAccount->ZipCode)) );
            js_pChangeAccount.Set("Telephone", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->Telephone, strlen(ptrCfd_pChangeAccount->Telephone)) );
            js_pChangeAccount.Set("MobilePhone", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->MobilePhone, strlen(ptrCfd_pChangeAccount->MobilePhone)) );
            js_pChangeAccount.Set("Fax", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->Fax, strlen(ptrCfd_pChangeAccount->Fax)) );
            js_pChangeAccount.Set("EMail", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->EMail, strlen(ptrCfd_pChangeAccount->EMail)) );
            js_pChangeAccount.Set("MoneyAccountStatus", string(1u, ptrCfd_pChangeAccount->MoneyAccountStatus).c_str());
            js_pChangeAccount.Set("BankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BankAccount, strlen(ptrCfd_pChangeAccount->BankAccount)) );
            js_pChangeAccount.Set("BankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BankPassWord, strlen(ptrCfd_pChangeAccount->BankPassWord)) );
            js_pChangeAccount.Set("NewBankAccount", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->NewBankAccount, strlen(ptrCfd_pChangeAccount->NewBankAccount)) );
            js_pChangeAccount.Set("NewBankPassWord", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->NewBankPassWord, strlen(ptrCfd_pChangeAccount->NewBankPassWord)) );
            js_pChangeAccount.Set("AccountID", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->AccountID, strlen(ptrCfd_pChangeAccount->AccountID)) );
            js_pChangeAccount.Set("Password", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->Password, strlen(ptrCfd_pChangeAccount->Password)) );
            js_pChangeAccount.Set("BankAccType", string(1u, ptrCfd_pChangeAccount->BankAccType).c_str());
            js_pChangeAccount.Set("InstallID", ptrCfd_pChangeAccount->InstallID);
            js_pChangeAccount.Set("VerifyCertNoFlag", string(1u, ptrCfd_pChangeAccount->VerifyCertNoFlag).c_str());
            js_pChangeAccount.Set("CurrencyID", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->CurrencyID, strlen(ptrCfd_pChangeAccount->CurrencyID)) );
            js_pChangeAccount.Set("BrokerIDByBank", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->BrokerIDByBank, strlen(ptrCfd_pChangeAccount->BrokerIDByBank)) );
            js_pChangeAccount.Set("BankPwdFlag", string(1u, ptrCfd_pChangeAccount->BankPwdFlag).c_str());
            js_pChangeAccount.Set("SecuPwdFlag", string(1u, ptrCfd_pChangeAccount->SecuPwdFlag).c_str());
            js_pChangeAccount.Set("TID", ptrCfd_pChangeAccount->TID);
            js_pChangeAccount.Set("Digest", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->Digest, strlen(ptrCfd_pChangeAccount->Digest)) );
            js_pChangeAccount.Set("ErrorID", ptrCfd_pChangeAccount->ErrorID);
            js_pChangeAccount.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->ErrorMsg, strlen(ptrCfd_pChangeAccount->ErrorMsg)) );
            js_pChangeAccount.Set("LongCustomerName", Napi::Buffer<char>::Copy(env, ptrCfd_pChangeAccount->LongCustomerName, strlen(ptrCfd_pChangeAccount->LongCustomerName)) );
            js_event_data.Set("pChangeAccount", js_pChangeAccount);
            delete ptrCfd_pChangeAccount;
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField * pInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcInstrumentField *ptrCfd_pInstrument = new CThostFtdcInstrumentField();
        if(pInstrument)
        {
            memcpy(ptrCfd_pInstrument, pInstrument, sizeof(CThostFtdcInstrumentField));
        }
        else
        {
            memset(ptrCfd_pInstrument, 0, sizeof(CThostFtdcInstrumentField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryClassifiedInstrument");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pInstrument = Napi::Object::New(env);
            js_pInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve1, strlen(ptrCfd_pInstrument->reserve1)) );
            js_pInstrument.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ExchangeID, strlen(ptrCfd_pInstrument->ExchangeID)) );
            js_pInstrument.Set("InstrumentName", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->InstrumentName, strlen(ptrCfd_pInstrument->InstrumentName)) );
            js_pInstrument.Set("reserve2", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve2, strlen(ptrCfd_pInstrument->reserve2)) );
            js_pInstrument.Set("reserve3", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve3, strlen(ptrCfd_pInstrument->reserve3)) );
            js_pInstrument.Set("ProductClass", string(1u, ptrCfd_pInstrument->ProductClass).c_str());
            js_pInstrument.Set("DeliveryYear", ptrCfd_pInstrument->DeliveryYear);
            js_pInstrument.Set("DeliveryMonth", ptrCfd_pInstrument->DeliveryMonth);
            js_pInstrument.Set("MaxMarketOrderVolume", ptrCfd_pInstrument->MaxMarketOrderVolume);
            js_pInstrument.Set("MinMarketOrderVolume", ptrCfd_pInstrument->MinMarketOrderVolume);
            js_pInstrument.Set("MaxLimitOrderVolume", ptrCfd_pInstrument->MaxLimitOrderVolume);
            js_pInstrument.Set("MinLimitOrderVolume", ptrCfd_pInstrument->MinLimitOrderVolume);
            js_pInstrument.Set("VolumeMultiple", ptrCfd_pInstrument->VolumeMultiple);
            js_pInstrument.Set("PriceTick", ptrCfd_pInstrument->PriceTick);
            js_pInstrument.Set("CreateDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->CreateDate, strlen(ptrCfd_pInstrument->CreateDate)) );
            js_pInstrument.Set("OpenDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->OpenDate, strlen(ptrCfd_pInstrument->OpenDate)) );
            js_pInstrument.Set("ExpireDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ExpireDate, strlen(ptrCfd_pInstrument->ExpireDate)) );
            js_pInstrument.Set("StartDelivDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->StartDelivDate, strlen(ptrCfd_pInstrument->StartDelivDate)) );
            js_pInstrument.Set("EndDelivDate", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->EndDelivDate, strlen(ptrCfd_pInstrument->EndDelivDate)) );
            js_pInstrument.Set("InstLifePhase", string(1u, ptrCfd_pInstrument->InstLifePhase).c_str());
            js_pInstrument.Set("IsTrading", ptrCfd_pInstrument->IsTrading);
            js_pInstrument.Set("PositionType", string(1u, ptrCfd_pInstrument->PositionType).c_str());
            js_pInstrument.Set("PositionDateType", string(1u, ptrCfd_pInstrument->PositionDateType).c_str());
            js_pInstrument.Set("LongMarginRatio", ptrCfd_pInstrument->LongMarginRatio);
            js_pInstrument.Set("ShortMarginRatio", ptrCfd_pInstrument->ShortMarginRatio);
            js_pInstrument.Set("MaxMarginSideAlgorithm", string(1u, ptrCfd_pInstrument->MaxMarginSideAlgorithm).c_str());
            js_pInstrument.Set("reserve4", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->reserve4, strlen(ptrCfd_pInstrument->reserve4)) );
            js_pInstrument.Set("StrikePrice", ptrCfd_pInstrument->StrikePrice);
            js_pInstrument.Set("OptionsType", string(1u, ptrCfd_pInstrument->OptionsType).c_str());
            js_pInstrument.Set("UnderlyingMultiple", ptrCfd_pInstrument->UnderlyingMultiple);
            js_pInstrument.Set("CombinationType", string(1u, ptrCfd_pInstrument->CombinationType).c_str());
            js_pInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->InstrumentID, strlen(ptrCfd_pInstrument->InstrumentID)) );
            js_pInstrument.Set("ExchangeInstID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ExchangeInstID, strlen(ptrCfd_pInstrument->ExchangeInstID)) );
            js_pInstrument.Set("ProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->ProductID, strlen(ptrCfd_pInstrument->ProductID)) );
            js_pInstrument.Set("UnderlyingInstrID", Napi::Buffer<char>::Copy(env, ptrCfd_pInstrument->UnderlyingInstrID, strlen(ptrCfd_pInstrument->UnderlyingInstrID)) );
            js_event_data.Set("pInstrument", js_pInstrument);
            delete ptrCfd_pInstrument;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField * pCombPromotionParam, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcCombPromotionParamField *ptrCfd_pCombPromotionParam = new CThostFtdcCombPromotionParamField();
        if(pCombPromotionParam)
        {
            memcpy(ptrCfd_pCombPromotionParam, pCombPromotionParam, sizeof(CThostFtdcCombPromotionParamField));
        }
        else
        {
            memset(ptrCfd_pCombPromotionParam, 0, sizeof(CThostFtdcCombPromotionParamField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryCombPromotionParam");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pCombPromotionParam = Napi::Object::New(env);
            js_pCombPromotionParam.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombPromotionParam->ExchangeID, strlen(ptrCfd_pCombPromotionParam->ExchangeID)) );
            js_pCombPromotionParam.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pCombPromotionParam->InstrumentID, strlen(ptrCfd_pCombPromotionParam->InstrumentID)) );
            js_pCombPromotionParam.Set("CombHedgeFlag", Napi::Buffer<char>::Copy(env, ptrCfd_pCombPromotionParam->CombHedgeFlag, strlen(ptrCfd_pCombPromotionParam->CombHedgeFlag)) );
            js_pCombPromotionParam.Set("Xparameter", ptrCfd_pCombPromotionParam->Xparameter);
            js_event_data.Set("pCombPromotionParam", js_pCombPromotionParam);
            delete ptrCfd_pCombPromotionParam;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField * pRiskSettleInvstPosition, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRiskSettleInvstPositionField *ptrCfd_pRiskSettleInvstPosition = new CThostFtdcRiskSettleInvstPositionField();
        if(pRiskSettleInvstPosition)
        {
            memcpy(ptrCfd_pRiskSettleInvstPosition, pRiskSettleInvstPosition, sizeof(CThostFtdcRiskSettleInvstPositionField));
        }
        else
        {
            memset(ptrCfd_pRiskSettleInvstPosition, 0, sizeof(CThostFtdcRiskSettleInvstPositionField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryRiskSettleInvstPosition");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRiskSettleInvstPosition = Napi::Object::New(env);
            js_pRiskSettleInvstPosition.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleInvstPosition->InstrumentID, strlen(ptrCfd_pRiskSettleInvstPosition->InstrumentID)) );
            js_pRiskSettleInvstPosition.Set("BrokerID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleInvstPosition->BrokerID, strlen(ptrCfd_pRiskSettleInvstPosition->BrokerID)) );
            js_pRiskSettleInvstPosition.Set("InvestorID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleInvstPosition->InvestorID, strlen(ptrCfd_pRiskSettleInvstPosition->InvestorID)) );
            js_pRiskSettleInvstPosition.Set("PosiDirection", string(1u, ptrCfd_pRiskSettleInvstPosition->PosiDirection).c_str());
            js_pRiskSettleInvstPosition.Set("HedgeFlag", string(1u, ptrCfd_pRiskSettleInvstPosition->HedgeFlag).c_str());
            js_pRiskSettleInvstPosition.Set("PositionDate", string(1u, ptrCfd_pRiskSettleInvstPosition->PositionDate).c_str());
            js_pRiskSettleInvstPosition.Set("YdPosition", ptrCfd_pRiskSettleInvstPosition->YdPosition);
            js_pRiskSettleInvstPosition.Set("Position", ptrCfd_pRiskSettleInvstPosition->Position);
            js_pRiskSettleInvstPosition.Set("LongFrozen", ptrCfd_pRiskSettleInvstPosition->LongFrozen);
            js_pRiskSettleInvstPosition.Set("ShortFrozen", ptrCfd_pRiskSettleInvstPosition->ShortFrozen);
            js_pRiskSettleInvstPosition.Set("LongFrozenAmount", ptrCfd_pRiskSettleInvstPosition->LongFrozenAmount);
            js_pRiskSettleInvstPosition.Set("ShortFrozenAmount", ptrCfd_pRiskSettleInvstPosition->ShortFrozenAmount);
            js_pRiskSettleInvstPosition.Set("OpenVolume", ptrCfd_pRiskSettleInvstPosition->OpenVolume);
            js_pRiskSettleInvstPosition.Set("CloseVolume", ptrCfd_pRiskSettleInvstPosition->CloseVolume);
            js_pRiskSettleInvstPosition.Set("OpenAmount", ptrCfd_pRiskSettleInvstPosition->OpenAmount);
            js_pRiskSettleInvstPosition.Set("CloseAmount", ptrCfd_pRiskSettleInvstPosition->CloseAmount);
            js_pRiskSettleInvstPosition.Set("PositionCost", ptrCfd_pRiskSettleInvstPosition->PositionCost);
            js_pRiskSettleInvstPosition.Set("PreMargin", ptrCfd_pRiskSettleInvstPosition->PreMargin);
            js_pRiskSettleInvstPosition.Set("UseMargin", ptrCfd_pRiskSettleInvstPosition->UseMargin);
            js_pRiskSettleInvstPosition.Set("FrozenMargin", ptrCfd_pRiskSettleInvstPosition->FrozenMargin);
            js_pRiskSettleInvstPosition.Set("FrozenCash", ptrCfd_pRiskSettleInvstPosition->FrozenCash);
            js_pRiskSettleInvstPosition.Set("FrozenCommission", ptrCfd_pRiskSettleInvstPosition->FrozenCommission);
            js_pRiskSettleInvstPosition.Set("CashIn", ptrCfd_pRiskSettleInvstPosition->CashIn);
            js_pRiskSettleInvstPosition.Set("Commission", ptrCfd_pRiskSettleInvstPosition->Commission);
            js_pRiskSettleInvstPosition.Set("CloseProfit", ptrCfd_pRiskSettleInvstPosition->CloseProfit);
            js_pRiskSettleInvstPosition.Set("PositionProfit", ptrCfd_pRiskSettleInvstPosition->PositionProfit);
            js_pRiskSettleInvstPosition.Set("PreSettlementPrice", ptrCfd_pRiskSettleInvstPosition->PreSettlementPrice);
            js_pRiskSettleInvstPosition.Set("SettlementPrice", ptrCfd_pRiskSettleInvstPosition->SettlementPrice);
            js_pRiskSettleInvstPosition.Set("TradingDay", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleInvstPosition->TradingDay, strlen(ptrCfd_pRiskSettleInvstPosition->TradingDay)) );
            js_pRiskSettleInvstPosition.Set("SettlementID", ptrCfd_pRiskSettleInvstPosition->SettlementID);
            js_pRiskSettleInvstPosition.Set("OpenCost", ptrCfd_pRiskSettleInvstPosition->OpenCost);
            js_pRiskSettleInvstPosition.Set("ExchangeMargin", ptrCfd_pRiskSettleInvstPosition->ExchangeMargin);
            js_pRiskSettleInvstPosition.Set("CombPosition", ptrCfd_pRiskSettleInvstPosition->CombPosition);
            js_pRiskSettleInvstPosition.Set("CombLongFrozen", ptrCfd_pRiskSettleInvstPosition->CombLongFrozen);
            js_pRiskSettleInvstPosition.Set("CombShortFrozen", ptrCfd_pRiskSettleInvstPosition->CombShortFrozen);
            js_pRiskSettleInvstPosition.Set("CloseProfitByDate", ptrCfd_pRiskSettleInvstPosition->CloseProfitByDate);
            js_pRiskSettleInvstPosition.Set("CloseProfitByTrade", ptrCfd_pRiskSettleInvstPosition->CloseProfitByTrade);
            js_pRiskSettleInvstPosition.Set("TodayPosition", ptrCfd_pRiskSettleInvstPosition->TodayPosition);
            js_pRiskSettleInvstPosition.Set("MarginRateByMoney", ptrCfd_pRiskSettleInvstPosition->MarginRateByMoney);
            js_pRiskSettleInvstPosition.Set("MarginRateByVolume", ptrCfd_pRiskSettleInvstPosition->MarginRateByVolume);
            js_pRiskSettleInvstPosition.Set("StrikeFrozen", ptrCfd_pRiskSettleInvstPosition->StrikeFrozen);
            js_pRiskSettleInvstPosition.Set("StrikeFrozenAmount", ptrCfd_pRiskSettleInvstPosition->StrikeFrozenAmount);
            js_pRiskSettleInvstPosition.Set("AbandonFrozen", ptrCfd_pRiskSettleInvstPosition->AbandonFrozen);
            js_pRiskSettleInvstPosition.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleInvstPosition->ExchangeID, strlen(ptrCfd_pRiskSettleInvstPosition->ExchangeID)) );
            js_pRiskSettleInvstPosition.Set("YdStrikeFrozen", ptrCfd_pRiskSettleInvstPosition->YdStrikeFrozen);
            js_pRiskSettleInvstPosition.Set("InvestUnitID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleInvstPosition->InvestUnitID, strlen(ptrCfd_pRiskSettleInvstPosition->InvestUnitID)) );
            js_pRiskSettleInvstPosition.Set("PositionCostOffset", ptrCfd_pRiskSettleInvstPosition->PositionCostOffset);
            js_pRiskSettleInvstPosition.Set("TasPosition", ptrCfd_pRiskSettleInvstPosition->TasPosition);
            js_pRiskSettleInvstPosition.Set("TasPositionCost", ptrCfd_pRiskSettleInvstPosition->TasPositionCost);
            js_event_data.Set("pRiskSettleInvstPosition", js_pRiskSettleInvstPosition);
            delete ptrCfd_pRiskSettleInvstPosition;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }

    void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField * pRiskSettleProductStatus, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcRiskSettleProductStatusField *ptrCfd_pRiskSettleProductStatus = new CThostFtdcRiskSettleProductStatusField();
        if(pRiskSettleProductStatus)
        {
            memcpy(ptrCfd_pRiskSettleProductStatus, pRiskSettleProductStatus, sizeof(CThostFtdcRiskSettleProductStatusField));
        }
        else
        {
            memset(ptrCfd_pRiskSettleProductStatus, 0, sizeof(CThostFtdcRiskSettleProductStatusField));
        }
        CThostFtdcRspInfoField *ptrCfd_pRspInfo = new CThostFtdcRspInfoField();
        if(pRspInfo)
        {
            memcpy(ptrCfd_pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));
        }
        else
        {
            memset(ptrCfd_pRspInfo, 0, sizeof(CThostFtdcRspInfoField));
        }
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryRiskSettleProductStatus");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pRiskSettleProductStatus = Napi::Object::New(env);
            js_pRiskSettleProductStatus.Set("ExchangeID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleProductStatus->ExchangeID, strlen(ptrCfd_pRiskSettleProductStatus->ExchangeID)) );
            js_pRiskSettleProductStatus.Set("ProductID", Napi::Buffer<char>::Copy(env, ptrCfd_pRiskSettleProductStatus->ProductID, strlen(ptrCfd_pRiskSettleProductStatus->ProductID)) );
            js_pRiskSettleProductStatus.Set("ProductStatus", string(1u, ptrCfd_pRiskSettleProductStatus->ProductStatus).c_str());
            js_event_data.Set("pRiskSettleProductStatus", js_pRiskSettleProductStatus);
            delete ptrCfd_pRiskSettleProductStatus;
            Napi::Object js_pRspInfo = Napi::Object::New(env);
            js_pRspInfo.Set("ErrorID", ptrCfd_pRspInfo->ErrorID);
            js_pRspInfo.Set("ErrorMsg", Napi::Buffer<char>::Copy(env, ptrCfd_pRspInfo->ErrorMsg, strlen(ptrCfd_pRspInfo->ErrorMsg)) );
            js_event_data.Set("pRspInfo", js_pRspInfo);
            delete ptrCfd_pRspInfo;
            js_event_data.Set("nRequestID", nRequestID);
            js_event_data.Set("bIsLast", bIsLast);
            jsCallback.Call(jsthis_ref->Value(), {js_event_name, js_event_data});
        };
        if(this->emitter != nullptr)
        {
            this->emitter.Acquire();
            this->emitter.BlockingCall(&jsthis, callback);
            emitter.Release();
        }
    }



private:
    void getEmitter(const Napi::CallbackInfo &info)
    {
        jsthis = Napi::Reference<Napi::Object>::New(info.This().As<Napi::Object>(), 2);
        emitter = Napi::ThreadSafeFunction::New(
            info.Env(),
            jsthis.Get("emit").As<Napi::Function>(),
            "emit",
            0,
            1);
    }

    void closeEmitter(const Napi::CallbackInfo &info)
    {
        this->emitter.Abort();
        this->emitter.Unref(info.Env());
        this->emitter = nullptr; // important, avoid to call the lamdba function to prevent exception when emitter had been unref.
    }

    void Release(const Napi::CallbackInfo &info)
    {
        api->Release();
    }

    void Init(const Napi::CallbackInfo &info)
    {
        api->Init();
    }

    Napi::Value Join(const Napi::CallbackInfo &info)
    {
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->Join());
        return rtnValue;
    }

    Napi::Value GetTradingDay(const Napi::CallbackInfo &info)
    {
        Napi::Value rtnValue = Napi::String::New(info.Env(), api->GetTradingDay());
        return rtnValue;
    }

    void RegisterFront(const Napi::CallbackInfo &info)
    {
        api->RegisterFront((char*)info[0].As<Napi::String>().Utf8Value().c_str());
    }

    void RegisterNameServer(const Napi::CallbackInfo &info)
    {
        api->RegisterNameServer((char*)info[0].As<Napi::String>().Utf8Value().c_str());
    }

    void RegisterFensUserInfo(const Napi::CallbackInfo &info)
    {
        CThostFtdcFensUserInfoField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.LoginMode = jsObj.Get("LoginMode").As<Napi::String>().Utf8Value().c_str()[0];
        api->RegisterFensUserInfo(&cfd);
    }

    void RegisterSpi(const Napi::CallbackInfo &info)
    {
        api->RegisterSpi(this);
    }

    void SubscribePrivateTopic(const Napi::CallbackInfo &info)
    {
        api->SubscribePrivateTopic((THOST_TE_RESUME_TYPE)info[0].As<Napi::Number>().Int32Value());
    }

    void SubscribePublicTopic(const Napi::CallbackInfo &info)
    {
        api->SubscribePublicTopic((THOST_TE_RESUME_TYPE)info[0].As<Napi::Number>().Int32Value());
    }

    Napi::Value ReqAuthenticate(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqAuthenticateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserProductInfo, (const char*)jsObj.Get("UserProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AuthCode, (const char*)jsObj.Get("AuthCode").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AppID, (const char*)jsObj.Get("AppID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqAuthenticate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value RegisterUserSystemInfo(const Napi::CallbackInfo &info)
    {
        CThostFtdcUserSystemInfoField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientSystemInfoLen = jsObj.Get("ClientSystemInfoLen").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientSystemInfo, (const char*)jsObj.Get("ClientSystemInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIPPort = jsObj.Get("ClientIPPort").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientLoginTime, (const char*)jsObj.Get("ClientLoginTime").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientAppID, (const char*)jsObj.Get("ClientAppID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientPublicIP, (const char*)jsObj.Get("ClientPublicIP").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientLoginRemark, (const char*)jsObj.Get("ClientLoginRemark").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->RegisterUserSystemInfo(&cfd));
        return rtnValue;
    }

    Napi::Value SubmitUserSystemInfo(const Napi::CallbackInfo &info)
    {
        CThostFtdcUserSystemInfoField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientSystemInfoLen = jsObj.Get("ClientSystemInfoLen").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientSystemInfo, (const char*)jsObj.Get("ClientSystemInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIPPort = jsObj.Get("ClientIPPort").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientLoginTime, (const char*)jsObj.Get("ClientLoginTime").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientAppID, (const char*)jsObj.Get("ClientAppID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientPublicIP, (const char*)jsObj.Get("ClientPublicIP").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientLoginRemark, (const char*)jsObj.Get("ClientLoginRemark").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->SubmitUserSystemInfo(&cfd));
        return rtnValue;
    }

    Napi::Value ReqUserLogin(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqUserLoginField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserProductInfo, (const char*)jsObj.Get("UserProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InterfaceProductInfo, (const char*)jsObj.Get("InterfaceProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProtocolInfo, (const char*)jsObj.Get("ProtocolInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OneTimePassword, (const char*)jsObj.Get("OneTimePassword").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.LoginRemark, (const char*)jsObj.Get("LoginRemark").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIPPort = jsObj.Get("ClientIPPort").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientIPAddress, (const char*)jsObj.Get("ClientIPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserLogin(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqUserLogout(const Napi::CallbackInfo &info)
    {
        CThostFtdcUserLogoutField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserLogout(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqUserPasswordUpdate(const Napi::CallbackInfo &info)
    {
        CThostFtdcUserPasswordUpdateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OldPassword, (const char*)jsObj.Get("OldPassword").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.NewPassword, (const char*)jsObj.Get("NewPassword").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserPasswordUpdate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqTradingAccountPasswordUpdate(const Napi::CallbackInfo &info)
    {
        CThostFtdcTradingAccountPasswordUpdateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OldPassword, (const char*)jsObj.Get("OldPassword").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.NewPassword, (const char*)jsObj.Get("NewPassword").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqTradingAccountPasswordUpdate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqUserAuthMethod(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqUserAuthMethodField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserAuthMethod(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqGenUserCaptcha(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqGenUserCaptchaField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqGenUserCaptcha(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqGenUserText(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqGenUserTextField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqGenUserText(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqUserLoginWithCaptcha(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqUserLoginWithCaptchaField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserProductInfo, (const char*)jsObj.Get("UserProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InterfaceProductInfo, (const char*)jsObj.Get("InterfaceProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProtocolInfo, (const char*)jsObj.Get("ProtocolInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.LoginRemark, (const char*)jsObj.Get("LoginRemark").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Captcha, (const char*)jsObj.Get("Captcha").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIPPort = jsObj.Get("ClientIPPort").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientIPAddress, (const char*)jsObj.Get("ClientIPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserLoginWithCaptcha(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqUserLoginWithText(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqUserLoginWithTextField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserProductInfo, (const char*)jsObj.Get("UserProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InterfaceProductInfo, (const char*)jsObj.Get("InterfaceProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProtocolInfo, (const char*)jsObj.Get("ProtocolInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.LoginRemark, (const char*)jsObj.Get("LoginRemark").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Text, (const char*)jsObj.Get("Text").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIPPort = jsObj.Get("ClientIPPort").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientIPAddress, (const char*)jsObj.Get("ClientIPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserLoginWithText(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqUserLoginWithOTP(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqUserLoginWithOTPField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserProductInfo, (const char*)jsObj.Get("UserProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InterfaceProductInfo, (const char*)jsObj.Get("InterfaceProductInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProtocolInfo, (const char*)jsObj.Get("ProtocolInfo").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.LoginRemark, (const char*)jsObj.Get("LoginRemark").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OTPPassword, (const char*)jsObj.Get("OTPPassword").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIPPort = jsObj.Get("ClientIPPort").As<Napi::Number>().Int32Value();
        strcpy(cfd.ClientIPAddress, (const char*)jsObj.Get("ClientIPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqUserLoginWithOTP(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqOrderInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OrderRef, (const char*)jsObj.Get("OrderRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.OrderPriceType = jsObj.Get("OrderPriceType").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.Direction = jsObj.Get("Direction").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.CombOffsetFlag, (const char*)jsObj.Get("CombOffsetFlag").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CombHedgeFlag, (const char*)jsObj.Get("CombHedgeFlag").As<Napi::String>().Utf8Value().c_str() );
        cfd.LimitPrice = jsObj.Get("LimitPrice").As<Napi::Number>().DoubleValue();
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        cfd.VolumeTotalOriginal = jsObj.Get("VolumeTotalOriginal").As<Napi::Number>().Int32Value();
        cfd.TimeCondition = jsObj.Get("TimeCondition").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.GTDDate, (const char*)jsObj.Get("GTDDate").As<Napi::String>().Utf8Value().c_str() );
        cfd.VolumeCondition = jsObj.Get("VolumeCondition").As<Napi::String>().Utf8Value().c_str()[0];
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        cfd.MinVolume = jsObj.Get("MinVolume").As<Napi::Number>().Int32Value();
        cfd.ContingentCondition = jsObj.Get("ContingentCondition").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.StopPrice = jsObj.Get("StopPrice").As<Napi::Number>().DoubleValue();
        cfd.ForceCloseReason = jsObj.Get("ForceCloseReason").As<Napi::String>().Utf8Value().c_str()[0];
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        cfd.IsAutoSuspend = jsObj.Get("IsAutoSuspend").As<Napi::Number>().Int32Value();
        strcpy(cfd.BusinessUnit, (const char*)jsObj.Get("BusinessUnit").As<Napi::String>().Utf8Value().c_str() );
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        cfd.UserForceClose = jsObj.Get("UserForceClose").As<Napi::Number>().Int32Value();
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        cfd.IsSwapOrder = jsObj.Get("IsSwapOrder").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        cout << "ReqOrderInsert" << __LINE__ <<endl;
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqOrderInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqParkedOrderInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcParkedOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OrderRef, (const char*)jsObj.Get("OrderRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.OrderPriceType = jsObj.Get("OrderPriceType").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.Direction = jsObj.Get("Direction").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.CombOffsetFlag, (const char*)jsObj.Get("CombOffsetFlag").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CombHedgeFlag, (const char*)jsObj.Get("CombHedgeFlag").As<Napi::String>().Utf8Value().c_str() );
        cfd.LimitPrice = jsObj.Get("LimitPrice").As<Napi::Number>().DoubleValue();
        cfd.VolumeTotalOriginal = jsObj.Get("VolumeTotalOriginal").As<Napi::Number>().Int32Value();
        cfd.TimeCondition = jsObj.Get("TimeCondition").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.GTDDate, (const char*)jsObj.Get("GTDDate").As<Napi::String>().Utf8Value().c_str() );
        cfd.VolumeCondition = jsObj.Get("VolumeCondition").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.MinVolume = jsObj.Get("MinVolume").As<Napi::Number>().Int32Value();
        cfd.ContingentCondition = jsObj.Get("ContingentCondition").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.StopPrice = jsObj.Get("StopPrice").As<Napi::Number>().DoubleValue();
        cfd.ForceCloseReason = jsObj.Get("ForceCloseReason").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.IsAutoSuspend = jsObj.Get("IsAutoSuspend").As<Napi::Number>().Int32Value();
        strcpy(cfd.BusinessUnit, (const char*)jsObj.Get("BusinessUnit").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.UserForceClose = jsObj.Get("UserForceClose").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ParkedOrderID, (const char*)jsObj.Get("ParkedOrderID").As<Napi::String>().Utf8Value().c_str() );
        cfd.UserType = jsObj.Get("UserType").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.Status = jsObj.Get("Status").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.ErrorID = jsObj.Get("ErrorID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ErrorMsg, (const char*)jsObj.Get("ErrorMsg").As<Napi::String>().Utf8Value().c_str() );
        cfd.IsSwapOrder = jsObj.Get("IsSwapOrder").As<Napi::Number>().Int32Value();
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqParkedOrderInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqParkedOrderAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcParkedOrderActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        cfd.OrderActionRef = jsObj.Get("OrderActionRef").As<Napi::Number>().Int32Value();
        strcpy(cfd.OrderRef, (const char*)jsObj.Get("OrderRef").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OrderSysID, (const char*)jsObj.Get("OrderSysID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ActionFlag = jsObj.Get("ActionFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.LimitPrice = jsObj.Get("LimitPrice").As<Napi::Number>().DoubleValue();
        cfd.VolumeChange = jsObj.Get("VolumeChange").As<Napi::Number>().Int32Value();
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ParkedOrderActionID, (const char*)jsObj.Get("ParkedOrderActionID").As<Napi::String>().Utf8Value().c_str() );
        cfd.UserType = jsObj.Get("UserType").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.Status = jsObj.Get("Status").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.ErrorID = jsObj.Get("ErrorID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ErrorMsg, (const char*)jsObj.Get("ErrorMsg").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqParkedOrderAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqOrderAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputOrderActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        cfd.OrderActionRef = jsObj.Get("OrderActionRef").As<Napi::Number>().Int32Value();
        strcpy(cfd.OrderRef, (const char*)jsObj.Get("OrderRef").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OrderSysID, (const char*)jsObj.Get("OrderSysID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ActionFlag = jsObj.Get("ActionFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.LimitPrice = jsObj.Get("LimitPrice").As<Napi::Number>().DoubleValue();
        cfd.VolumeChange = jsObj.Get("VolumeChange").As<Napi::Number>().Int32Value();
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqOrderAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryMaxOrderVolume(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryMaxOrderVolumeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.Direction = jsObj.Get("Direction").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.OffsetFlag = jsObj.Get("OffsetFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.MaxVolume = jsObj.Get("MaxVolume").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryMaxOrderVolume(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqSettlementInfoConfirm(const Napi::CallbackInfo &info)
    {
        CThostFtdcSettlementInfoConfirmField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ConfirmDate, (const char*)jsObj.Get("ConfirmDate").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ConfirmTime, (const char*)jsObj.Get("ConfirmTime").As<Napi::String>().Utf8Value().c_str() );
        cfd.SettlementID = jsObj.Get("SettlementID").As<Napi::Number>().Int32Value();
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqSettlementInfoConfirm(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqRemoveParkedOrder(const Napi::CallbackInfo &info)
    {
        CThostFtdcRemoveParkedOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ParkedOrderID, (const char*)jsObj.Get("ParkedOrderID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqRemoveParkedOrder(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqRemoveParkedOrderAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcRemoveParkedOrderActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ParkedOrderActionID, (const char*)jsObj.Get("ParkedOrderActionID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqRemoveParkedOrderAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqExecOrderInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputExecOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExecOrderRef, (const char*)jsObj.Get("ExecOrderRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.Volume = jsObj.Get("Volume").As<Napi::Number>().Int32Value();
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        strcpy(cfd.BusinessUnit, (const char*)jsObj.Get("BusinessUnit").As<Napi::String>().Utf8Value().c_str() );
        cfd.OffsetFlag = jsObj.Get("OffsetFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.ActionType = jsObj.Get("ActionType").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.PosiDirection = jsObj.Get("PosiDirection").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.ReservePositionFlag = jsObj.Get("ReservePositionFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.CloseFlag = jsObj.Get("CloseFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqExecOrderInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqExecOrderAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputExecOrderActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ExecOrderActionRef = jsObj.Get("ExecOrderActionRef").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExecOrderRef, (const char*)jsObj.Get("ExecOrderRef").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExecOrderSysID, (const char*)jsObj.Get("ExecOrderSysID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ActionFlag = jsObj.Get("ActionFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqExecOrderAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqForQuoteInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputForQuoteField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ForQuoteRef, (const char*)jsObj.Get("ForQuoteRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqForQuoteInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQuoteInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputQuoteField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.QuoteRef, (const char*)jsObj.Get("QuoteRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.AskPrice = jsObj.Get("AskPrice").As<Napi::Number>().DoubleValue();
        cfd.BidPrice = jsObj.Get("BidPrice").As<Napi::Number>().DoubleValue();
        cfd.AskVolume = jsObj.Get("AskVolume").As<Napi::Number>().Int32Value();
        cfd.BidVolume = jsObj.Get("BidVolume").As<Napi::Number>().Int32Value();
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        strcpy(cfd.BusinessUnit, (const char*)jsObj.Get("BusinessUnit").As<Napi::String>().Utf8Value().c_str() );
        cfd.AskOffsetFlag = jsObj.Get("AskOffsetFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.BidOffsetFlag = jsObj.Get("BidOffsetFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.AskHedgeFlag = jsObj.Get("AskHedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.BidHedgeFlag = jsObj.Get("BidHedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.AskOrderRef, (const char*)jsObj.Get("AskOrderRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BidOrderRef, (const char*)jsObj.Get("BidOrderRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ForQuoteSysID, (const char*)jsObj.Get("ForQuoteSysID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ReplaceSysID, (const char*)jsObj.Get("ReplaceSysID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQuoteInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQuoteAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputQuoteActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        cfd.QuoteActionRef = jsObj.Get("QuoteActionRef").As<Napi::Number>().Int32Value();
        strcpy(cfd.QuoteRef, (const char*)jsObj.Get("QuoteRef").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.QuoteSysID, (const char*)jsObj.Get("QuoteSysID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ActionFlag = jsObj.Get("ActionFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQuoteAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqBatchOrderAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputBatchOrderActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        cfd.OrderActionRef = jsObj.Get("OrderActionRef").As<Napi::Number>().Int32Value();
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqBatchOrderAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqOptionSelfCloseInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputOptionSelfCloseField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OptionSelfCloseRef, (const char*)jsObj.Get("OptionSelfCloseRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.Volume = jsObj.Get("Volume").As<Napi::Number>().Int32Value();
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        strcpy(cfd.BusinessUnit, (const char*)jsObj.Get("BusinessUnit").As<Napi::String>().Utf8Value().c_str() );
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.OptSelfCloseFlag = jsObj.Get("OptSelfCloseFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqOptionSelfCloseInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqOptionSelfCloseAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputOptionSelfCloseActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        cfd.OptionSelfCloseActionRef = jsObj.Get("OptionSelfCloseActionRef").As<Napi::Number>().Int32Value();
        strcpy(cfd.OptionSelfCloseRef, (const char*)jsObj.Get("OptionSelfCloseRef").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OptionSelfCloseSysID, (const char*)jsObj.Get("OptionSelfCloseSysID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ActionFlag = jsObj.Get("ActionFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqOptionSelfCloseAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqCombActionInsert(const Napi::CallbackInfo &info)
    {
        CThostFtdcInputCombActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CombActionRef, (const char*)jsObj.Get("CombActionRef").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.Direction = jsObj.Get("Direction").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.Volume = jsObj.Get("Volume").As<Napi::Number>().Int32Value();
        cfd.CombDirection = jsObj.Get("CombDirection").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.MacAddress, (const char*)jsObj.Get("MacAddress").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        cfd.FrontID = jsObj.Get("FrontID").As<Napi::Number>().Int32Value();
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.IPAddress, (const char*)jsObj.Get("IPAddress").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqCombActionInsert(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryOrder(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OrderSysID, (const char*)jsObj.Get("OrderSysID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeStart, (const char*)jsObj.Get("InsertTimeStart").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeEnd, (const char*)jsObj.Get("InsertTimeEnd").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryOrder(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryTrade(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTradeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeID, (const char*)jsObj.Get("TradeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeTimeStart, (const char*)jsObj.Get("TradeTimeStart").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeTimeEnd, (const char*)jsObj.Get("TradeTimeEnd").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryTrade(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInvestorPosition(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInvestorPositionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInvestorPosition(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryTradingAccount(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTradingAccountField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        cfd.BizType = jsObj.Get("BizType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryTradingAccount(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInvestor(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInvestorField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInvestor(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryTradingCode(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTradingCodeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ClientID, (const char*)jsObj.Get("ClientID").As<Napi::String>().Utf8Value().c_str() );
        cfd.ClientIDType = jsObj.Get("ClientIDType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryTradingCode(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInstrumentMarginRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInstrumentMarginRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInstrumentMarginRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInstrumentCommissionRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInstrumentCommissionRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInstrumentCommissionRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryExchange(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryExchangeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryExchange(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryProduct(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryProductField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.ProductClass = jsObj.Get("ProductClass").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProductID, (const char*)jsObj.Get("ProductID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryProduct(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInstrument(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInstrumentField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve2, (const char*)jsObj.Get("reserve2").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve3, (const char*)jsObj.Get("reserve3").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeInstID, (const char*)jsObj.Get("ExchangeInstID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProductID, (const char*)jsObj.Get("ProductID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInstrument(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryDepthMarketData(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryDepthMarketDataField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryDepthMarketData(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQrySettlementInfo(const Napi::CallbackInfo &info)
    {
        CThostFtdcQrySettlementInfoField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQrySettlementInfo(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryTransferBank(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTransferBankField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankBrchID, (const char*)jsObj.Get("BankBrchID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryTransferBank(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInvestorPositionDetail(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInvestorPositionDetailField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInvestorPositionDetail(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryNotice(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryNoticeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryNotice(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQrySettlementInfoConfirm(const Napi::CallbackInfo &info)
    {
        CThostFtdcQrySettlementInfoConfirmField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQrySettlementInfoConfirm(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInvestorPositionCombineDetail(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInvestorPositionCombineDetailField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CombInstrumentID, (const char*)jsObj.Get("CombInstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInvestorPositionCombineDetail(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryCFMMCTradingAccountKey(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryCFMMCTradingAccountKeyField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryCFMMCTradingAccountKey(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryEWarrantOffset(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryEWarrantOffsetField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryEWarrantOffset(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInvestorProductGroupMargin(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInvestorProductGroupMarginField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProductGroupID, (const char*)jsObj.Get("ProductGroupID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInvestorProductGroupMargin(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryExchangeMarginRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryExchangeMarginRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryExchangeMarginRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryExchangeMarginRateAdjust(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryExchangeMarginRateAdjustField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryExchangeMarginRateAdjust(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryExchangeRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryExchangeRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.FromCurrencyID, (const char*)jsObj.Get("FromCurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ToCurrencyID, (const char*)jsObj.Get("ToCurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryExchangeRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQrySecAgentACIDMap(const Napi::CallbackInfo &info)
    {
        CThostFtdcQrySecAgentACIDMapField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQrySecAgentACIDMap(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryProductExchRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryProductExchRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProductID, (const char*)jsObj.Get("ProductID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryProductExchRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryProductGroup(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryProductGroupField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProductID, (const char*)jsObj.Get("ProductID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryProductGroup(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryMMInstrumentCommissionRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryMMInstrumentCommissionRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryMMInstrumentCommissionRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryMMOptionInstrCommRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryMMOptionInstrCommRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryMMOptionInstrCommRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInstrumentOrderCommRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInstrumentOrderCommRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInstrumentOrderCommRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQrySecAgentTradingAccount(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTradingAccountField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        cfd.BizType = jsObj.Get("BizType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQrySecAgentTradingAccount(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQrySecAgentCheckMode(const Napi::CallbackInfo &info)
    {
        CThostFtdcQrySecAgentCheckModeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQrySecAgentCheckMode(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQrySecAgentTradeInfo(const Napi::CallbackInfo &info)
    {
        CThostFtdcQrySecAgentTradeInfoField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerSecAgentID, (const char*)jsObj.Get("BrokerSecAgentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQrySecAgentTradeInfo(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryOptionInstrTradeCost(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryOptionInstrTradeCostField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        cfd.HedgeFlag = jsObj.Get("HedgeFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.InputPrice = jsObj.Get("InputPrice").As<Napi::Number>().DoubleValue();
        cfd.UnderlyingPrice = jsObj.Get("UnderlyingPrice").As<Napi::Number>().DoubleValue();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryOptionInstrTradeCost(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryOptionInstrCommRate(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryOptionInstrCommRateField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryOptionInstrCommRate(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryExecOrder(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryExecOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExecOrderSysID, (const char*)jsObj.Get("ExecOrderSysID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeStart, (const char*)jsObj.Get("InsertTimeStart").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeEnd, (const char*)jsObj.Get("InsertTimeEnd").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryExecOrder(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryForQuote(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryForQuoteField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeStart, (const char*)jsObj.Get("InsertTimeStart").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeEnd, (const char*)jsObj.Get("InsertTimeEnd").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryForQuote(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryQuote(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryQuoteField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.QuoteSysID, (const char*)jsObj.Get("QuoteSysID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeStart, (const char*)jsObj.Get("InsertTimeStart").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeEnd, (const char*)jsObj.Get("InsertTimeEnd").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryQuote(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryOptionSelfClose(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryOptionSelfCloseField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.OptionSelfCloseSysID, (const char*)jsObj.Get("OptionSelfCloseSysID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeStart, (const char*)jsObj.Get("InsertTimeStart").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InsertTimeEnd, (const char*)jsObj.Get("InsertTimeEnd").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryOptionSelfClose(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryInvestUnit(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryInvestUnitField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryInvestUnit(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryCombInstrumentGuard(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryCombInstrumentGuardField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryCombInstrumentGuard(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryCombAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryCombActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryCombAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryTransferSerial(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTransferSerialField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryTransferSerial(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryAccountregister(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryAccountregisterField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankBranchID, (const char*)jsObj.Get("BankBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryAccountregister(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryContractBank(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryContractBankField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankBrchID, (const char*)jsObj.Get("BankBrchID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryContractBank(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryParkedOrder(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryParkedOrderField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryParkedOrder(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryParkedOrderAction(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryParkedOrderActionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryParkedOrderAction(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryTradingNotice(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryTradingNoticeField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryTradingNotice(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryBrokerTradingParams(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryBrokerTradingParamsField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryBrokerTradingParams(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryBrokerTradingAlgos(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryBrokerTradingAlgosField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryBrokerTradingAlgos(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQueryCFMMCTradingAccountToken(const Napi::CallbackInfo &info)
    {
        CThostFtdcQueryCFMMCTradingAccountTokenField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestUnitID, (const char*)jsObj.Get("InvestUnitID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQueryCFMMCTradingAccountToken(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqFromBankToFutureByFuture(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqTransferField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradeCode, (const char*)jsObj.Get("TradeCode").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankBranchID, (const char*)jsObj.Get("BankBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerBranchID, (const char*)jsObj.Get("BrokerBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeDate, (const char*)jsObj.Get("TradeDate").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeTime, (const char*)jsObj.Get("TradeTime").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankSerial, (const char*)jsObj.Get("BankSerial").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        cfd.PlateSerial = jsObj.Get("PlateSerial").As<Napi::Number>().Int32Value();
        cfd.LastFragment = jsObj.Get("LastFragment").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.CustomerName, (const char*)jsObj.Get("CustomerName").As<Napi::String>().Utf8Value().c_str() );
        cfd.IdCardType = jsObj.Get("IdCardType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.IdentifiedCardNo, (const char*)jsObj.Get("IdentifiedCardNo").As<Napi::String>().Utf8Value().c_str() );
        cfd.CustType = jsObj.Get("CustType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.BankAccount, (const char*)jsObj.Get("BankAccount").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankPassWord, (const char*)jsObj.Get("BankPassWord").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        cfd.InstallID = jsObj.Get("InstallID").As<Napi::Number>().Int32Value();
        cfd.FutureSerial = jsObj.Get("FutureSerial").As<Napi::Number>().Int32Value();
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.VerifyCertNoFlag = jsObj.Get("VerifyCertNoFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        cfd.TradeAmount = jsObj.Get("TradeAmount").As<Napi::Number>().DoubleValue();
        cfd.FutureFetchAmount = jsObj.Get("FutureFetchAmount").As<Napi::Number>().DoubleValue();
        cfd.FeePayFlag = jsObj.Get("FeePayFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.CustFee = jsObj.Get("CustFee").As<Napi::Number>().DoubleValue();
        cfd.BrokerFee = jsObj.Get("BrokerFee").As<Napi::Number>().DoubleValue();
        strcpy(cfd.Message, (const char*)jsObj.Get("Message").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Digest, (const char*)jsObj.Get("Digest").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankAccType = jsObj.Get("BankAccType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.DeviceID, (const char*)jsObj.Get("DeviceID").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankSecuAccType = jsObj.Get("BankSecuAccType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.BrokerIDByBank, (const char*)jsObj.Get("BrokerIDByBank").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankSecuAcc, (const char*)jsObj.Get("BankSecuAcc").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankPwdFlag = jsObj.Get("BankPwdFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.SecuPwdFlag = jsObj.Get("SecuPwdFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.OperNo, (const char*)jsObj.Get("OperNo").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.TID = jsObj.Get("TID").As<Napi::Number>().Int32Value();
        cfd.TransferStatus = jsObj.Get("TransferStatus").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.LongCustomerName, (const char*)jsObj.Get("LongCustomerName").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqFromBankToFutureByFuture(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqFromFutureToBankByFuture(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqTransferField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradeCode, (const char*)jsObj.Get("TradeCode").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankBranchID, (const char*)jsObj.Get("BankBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerBranchID, (const char*)jsObj.Get("BrokerBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeDate, (const char*)jsObj.Get("TradeDate").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeTime, (const char*)jsObj.Get("TradeTime").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankSerial, (const char*)jsObj.Get("BankSerial").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        cfd.PlateSerial = jsObj.Get("PlateSerial").As<Napi::Number>().Int32Value();
        cfd.LastFragment = jsObj.Get("LastFragment").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.CustomerName, (const char*)jsObj.Get("CustomerName").As<Napi::String>().Utf8Value().c_str() );
        cfd.IdCardType = jsObj.Get("IdCardType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.IdentifiedCardNo, (const char*)jsObj.Get("IdentifiedCardNo").As<Napi::String>().Utf8Value().c_str() );
        cfd.CustType = jsObj.Get("CustType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.BankAccount, (const char*)jsObj.Get("BankAccount").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankPassWord, (const char*)jsObj.Get("BankPassWord").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        cfd.InstallID = jsObj.Get("InstallID").As<Napi::Number>().Int32Value();
        cfd.FutureSerial = jsObj.Get("FutureSerial").As<Napi::Number>().Int32Value();
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.VerifyCertNoFlag = jsObj.Get("VerifyCertNoFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        cfd.TradeAmount = jsObj.Get("TradeAmount").As<Napi::Number>().DoubleValue();
        cfd.FutureFetchAmount = jsObj.Get("FutureFetchAmount").As<Napi::Number>().DoubleValue();
        cfd.FeePayFlag = jsObj.Get("FeePayFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.CustFee = jsObj.Get("CustFee").As<Napi::Number>().DoubleValue();
        cfd.BrokerFee = jsObj.Get("BrokerFee").As<Napi::Number>().DoubleValue();
        strcpy(cfd.Message, (const char*)jsObj.Get("Message").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Digest, (const char*)jsObj.Get("Digest").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankAccType = jsObj.Get("BankAccType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.DeviceID, (const char*)jsObj.Get("DeviceID").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankSecuAccType = jsObj.Get("BankSecuAccType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.BrokerIDByBank, (const char*)jsObj.Get("BrokerIDByBank").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankSecuAcc, (const char*)jsObj.Get("BankSecuAcc").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankPwdFlag = jsObj.Get("BankPwdFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.SecuPwdFlag = jsObj.Get("SecuPwdFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.OperNo, (const char*)jsObj.Get("OperNo").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.TID = jsObj.Get("TID").As<Napi::Number>().Int32Value();
        cfd.TransferStatus = jsObj.Get("TransferStatus").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.LongCustomerName, (const char*)jsObj.Get("LongCustomerName").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqFromFutureToBankByFuture(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQueryBankAccountMoneyByFuture(const Napi::CallbackInfo &info)
    {
        CThostFtdcReqQueryAccountField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.TradeCode, (const char*)jsObj.Get("TradeCode").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankID, (const char*)jsObj.Get("BankID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankBranchID, (const char*)jsObj.Get("BankBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BrokerBranchID, (const char*)jsObj.Get("BrokerBranchID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeDate, (const char*)jsObj.Get("TradeDate").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradeTime, (const char*)jsObj.Get("TradeTime").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankSerial, (const char*)jsObj.Get("BankSerial").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.TradingDay, (const char*)jsObj.Get("TradingDay").As<Napi::String>().Utf8Value().c_str() );
        cfd.PlateSerial = jsObj.Get("PlateSerial").As<Napi::Number>().Int32Value();
        cfd.LastFragment = jsObj.Get("LastFragment").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.SessionID = jsObj.Get("SessionID").As<Napi::Number>().Int32Value();
        strcpy(cfd.CustomerName, (const char*)jsObj.Get("CustomerName").As<Napi::String>().Utf8Value().c_str() );
        cfd.IdCardType = jsObj.Get("IdCardType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.IdentifiedCardNo, (const char*)jsObj.Get("IdentifiedCardNo").As<Napi::String>().Utf8Value().c_str() );
        cfd.CustType = jsObj.Get("CustType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.BankAccount, (const char*)jsObj.Get("BankAccount").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankPassWord, (const char*)jsObj.Get("BankPassWord").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.AccountID, (const char*)jsObj.Get("AccountID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Password, (const char*)jsObj.Get("Password").As<Napi::String>().Utf8Value().c_str() );
        cfd.FutureSerial = jsObj.Get("FutureSerial").As<Napi::Number>().Int32Value();
        cfd.InstallID = jsObj.Get("InstallID").As<Napi::Number>().Int32Value();
        strcpy(cfd.UserID, (const char*)jsObj.Get("UserID").As<Napi::String>().Utf8Value().c_str() );
        cfd.VerifyCertNoFlag = jsObj.Get("VerifyCertNoFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.CurrencyID, (const char*)jsObj.Get("CurrencyID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.Digest, (const char*)jsObj.Get("Digest").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankAccType = jsObj.Get("BankAccType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.DeviceID, (const char*)jsObj.Get("DeviceID").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankSecuAccType = jsObj.Get("BankSecuAccType").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.BrokerIDByBank, (const char*)jsObj.Get("BrokerIDByBank").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.BankSecuAcc, (const char*)jsObj.Get("BankSecuAcc").As<Napi::String>().Utf8Value().c_str() );
        cfd.BankPwdFlag = jsObj.Get("BankPwdFlag").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.SecuPwdFlag = jsObj.Get("SecuPwdFlag").As<Napi::String>().Utf8Value().c_str()[0];
        strcpy(cfd.OperNo, (const char*)jsObj.Get("OperNo").As<Napi::String>().Utf8Value().c_str() );
        cfd.RequestID = jsObj.Get("RequestID").As<Napi::Number>().Int32Value();
        cfd.TID = jsObj.Get("TID").As<Napi::Number>().Int32Value();
        strcpy(cfd.LongCustomerName, (const char*)jsObj.Get("LongCustomerName").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQueryBankAccountMoneyByFuture(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryClassifiedInstrument(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryClassifiedInstrumentField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ExchangeInstID, (const char*)jsObj.Get("ExchangeInstID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.ProductID, (const char*)jsObj.Get("ProductID").As<Napi::String>().Utf8Value().c_str() );
        cfd.TradingType = jsObj.Get("TradingType").As<Napi::String>().Utf8Value().c_str()[0];
        cfd.ClassType = jsObj.Get("ClassType").As<Napi::String>().Utf8Value().c_str()[0];
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryClassifiedInstrument(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryCombPromotionParam(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryCombPromotionParamField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.ExchangeID, (const char*)jsObj.Get("ExchangeID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryCombPromotionParam(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryRiskSettleInvstPosition(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryRiskSettleInvstPositionField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.BrokerID, (const char*)jsObj.Get("BrokerID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InvestorID, (const char*)jsObj.Get("InvestorID").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryRiskSettleInvstPosition(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }

    Napi::Value ReqQryRiskSettleProductStatus(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryRiskSettleProductStatusField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        strcpy(cfd.ProductID, (const char*)jsObj.Get("ProductID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryRiskSettleProductStatus(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }



    void CreateFtdcTraderApi(const Napi::CallbackInfo &info)
    {
        string pszFlowPath = info[0].As<Napi::String>().Utf8Value();
        api = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath.c_str());
    }

    Napi::Value GetApiVersion(const Napi::CallbackInfo &info)
    {
        return Napi::String::New(info.Env(), CThostFtdcTraderApi::GetApiVersion());
    }

    Napi::ThreadSafeFunction emitter = nullptr;
    Napi::ObjectReference jsthis;

};

#endif //JTP_TDAPI_H