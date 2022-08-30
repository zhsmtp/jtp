#ifndef JTP_MDAPI_H
#define JTP_MDAPI_H

#include <iostream>
#include <thread>

#include <napi.h>

#include "ThostFtdcMdApi.h"

using namespace std;

class MdApi : public CThostFtdcMdSpi, public Napi::ObjectWrap<MdApi>
{
private:
    CThostFtdcMdApi *api;

public:
    static Napi::Object AddonInit(Napi::Env env, Napi::Object exports)
    {
        Napi::Function func =
            DefineClass(env,
                        "MdApi",
                        {
                            InstanceMethod("getEmitter", &MdApi::getEmitter),
                            InstanceMethod("closeEmitter", &MdApi::closeEmitter),
                            InstanceMethod("CreateFtdcMdApi", &MdApi::CreateFtdcMdApi),
                            InstanceMethod("GetApiVersion", &MdApi::GetApiVersion),
                            InstanceMethod("Release", &MdApi::Release),
                            InstanceMethod("Init", &MdApi::Init),
                            InstanceMethod("Join", &MdApi::Join),
                            InstanceMethod("GetTradingDay", &MdApi::GetTradingDay),
                            InstanceMethod("RegisterFront", &MdApi::RegisterFront),
                            InstanceMethod("RegisterNameServer", &MdApi::RegisterNameServer),
                            InstanceMethod("RegisterFensUserInfo", &MdApi::RegisterFensUserInfo),
                            InstanceMethod("RegisterSpi", &MdApi::RegisterSpi),
                            InstanceMethod("SubscribeMarketData", &MdApi::SubscribeMarketData),
                            InstanceMethod("UnSubscribeMarketData", &MdApi::UnSubscribeMarketData),
                            InstanceMethod("SubscribeForQuoteRsp", &MdApi::SubscribeForQuoteRsp),
                            InstanceMethod("UnSubscribeForQuoteRsp", &MdApi::UnSubscribeForQuoteRsp),
                            InstanceMethod("ReqUserLogin", &MdApi::ReqUserLogin),
                            InstanceMethod("ReqUserLogout", &MdApi::ReqUserLogout),
                            InstanceMethod("ReqQryMulticastInstrument", &MdApi::ReqQryMulticastInstrument),

                        });

        Napi::FunctionReference *constructor = new Napi::FunctionReference();
        *constructor = Napi::Persistent(func);
        env.SetInstanceData(constructor);
        exports.Set("MdApi", func);
        return exports;
    }
    MdApi(const Napi::CallbackInfo &info) : Napi::ObjectWrap<MdApi>(info)
    {

    }
    ~MdApi()
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

    void OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField * pMulticastInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcMulticastInstrumentField *ptrCfd_pMulticastInstrument = new CThostFtdcMulticastInstrumentField();
        if(pMulticastInstrument)
        {
            memcpy(ptrCfd_pMulticastInstrument, pMulticastInstrument, sizeof(CThostFtdcMulticastInstrumentField));
        }
        else
        {
            memset(ptrCfd_pMulticastInstrument, 0, sizeof(CThostFtdcMulticastInstrumentField));
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
            Napi::String js_event_name = Napi::String::New(env, "OnRspQryMulticastInstrument");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pMulticastInstrument = Napi::Object::New(env);
            js_pMulticastInstrument.Set("TopicID", ptrCfd_pMulticastInstrument->TopicID);
            js_pMulticastInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pMulticastInstrument->reserve1, strlen(ptrCfd_pMulticastInstrument->reserve1)) );
            js_pMulticastInstrument.Set("InstrumentNo", ptrCfd_pMulticastInstrument->InstrumentNo);
            js_pMulticastInstrument.Set("CodePrice", ptrCfd_pMulticastInstrument->CodePrice);
            js_pMulticastInstrument.Set("VolumeMultiple", ptrCfd_pMulticastInstrument->VolumeMultiple);
            js_pMulticastInstrument.Set("PriceTick", ptrCfd_pMulticastInstrument->PriceTick);
            js_pMulticastInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pMulticastInstrument->InstrumentID, strlen(ptrCfd_pMulticastInstrument->InstrumentID)) );
            js_event_data.Set("pMulticastInstrument", js_pMulticastInstrument);
            delete ptrCfd_pMulticastInstrument;
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

    void OnRspSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSpecificInstrumentField *ptrCfd_pSpecificInstrument = new CThostFtdcSpecificInstrumentField();
        if(pSpecificInstrument)
        {
            memcpy(ptrCfd_pSpecificInstrument, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
        }
        else
        {
            memset(ptrCfd_pSpecificInstrument, 0, sizeof(CThostFtdcSpecificInstrumentField));
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
            Napi::String js_event_name = Napi::String::New(env, "OnRspSubMarketData");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSpecificInstrument = Napi::Object::New(env);
            js_pSpecificInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->reserve1, strlen(ptrCfd_pSpecificInstrument->reserve1)) );
            js_pSpecificInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->InstrumentID, strlen(ptrCfd_pSpecificInstrument->InstrumentID)) );
            js_event_data.Set("pSpecificInstrument", js_pSpecificInstrument);
            delete ptrCfd_pSpecificInstrument;
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

    void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSpecificInstrumentField *ptrCfd_pSpecificInstrument = new CThostFtdcSpecificInstrumentField();
        if(pSpecificInstrument)
        {
            memcpy(ptrCfd_pSpecificInstrument, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
        }
        else
        {
            memset(ptrCfd_pSpecificInstrument, 0, sizeof(CThostFtdcSpecificInstrumentField));
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
            Napi::String js_event_name = Napi::String::New(env, "OnRspUnSubMarketData");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSpecificInstrument = Napi::Object::New(env);
            js_pSpecificInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->reserve1, strlen(ptrCfd_pSpecificInstrument->reserve1)) );
            js_pSpecificInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->InstrumentID, strlen(ptrCfd_pSpecificInstrument->InstrumentID)) );
            js_event_data.Set("pSpecificInstrument", js_pSpecificInstrument);
            delete ptrCfd_pSpecificInstrument;
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

    void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSpecificInstrumentField *ptrCfd_pSpecificInstrument = new CThostFtdcSpecificInstrumentField();
        if(pSpecificInstrument)
        {
            memcpy(ptrCfd_pSpecificInstrument, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
        }
        else
        {
            memset(ptrCfd_pSpecificInstrument, 0, sizeof(CThostFtdcSpecificInstrumentField));
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
            Napi::String js_event_name = Napi::String::New(env, "OnRspSubForQuoteRsp");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSpecificInstrument = Napi::Object::New(env);
            js_pSpecificInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->reserve1, strlen(ptrCfd_pSpecificInstrument->reserve1)) );
            js_pSpecificInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->InstrumentID, strlen(ptrCfd_pSpecificInstrument->InstrumentID)) );
            js_event_data.Set("pSpecificInstrument", js_pSpecificInstrument);
            delete ptrCfd_pSpecificInstrument;
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

    void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
    {
        
        CThostFtdcSpecificInstrumentField *ptrCfd_pSpecificInstrument = new CThostFtdcSpecificInstrumentField();
        if(pSpecificInstrument)
        {
            memcpy(ptrCfd_pSpecificInstrument, pSpecificInstrument, sizeof(CThostFtdcSpecificInstrumentField));
        }
        else
        {
            memset(ptrCfd_pSpecificInstrument, 0, sizeof(CThostFtdcSpecificInstrumentField));
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
            Napi::String js_event_name = Napi::String::New(env, "OnRspUnSubForQuoteRsp");
            Napi::Object js_event_data = Napi::Object::New(env);
            Napi::Object js_pSpecificInstrument = Napi::Object::New(env);
            js_pSpecificInstrument.Set("reserve1", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->reserve1, strlen(ptrCfd_pSpecificInstrument->reserve1)) );
            js_pSpecificInstrument.Set("InstrumentID", Napi::Buffer<char>::Copy(env, ptrCfd_pSpecificInstrument->InstrumentID, strlen(ptrCfd_pSpecificInstrument->InstrumentID)) );
            js_event_data.Set("pSpecificInstrument", js_pSpecificInstrument);
            delete ptrCfd_pSpecificInstrument;
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

    void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketData)
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
        auto callback = [=](Napi::Env env, Napi::Function jsCallback, Napi::ObjectReference *jsthis_ref)
        {
            Napi::String js_event_name = Napi::String::New(env, "OnRtnDepthMarketData");
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

    void CreateFtdcMdApi(const Napi::CallbackInfo &info)
    {
        string pszFlowPath;
        bool bIsUsingUdp;
        bool bIsMulticast;
        switch (info.Length())
        {
        case 1:
            pszFlowPath = info[0].As<Napi::String>().Utf8Value();
            api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str());
            break;
        case 2:
            pszFlowPath = info[0].As<Napi::String>().Utf8Value();
            bIsUsingUdp = info[1].As<Napi::Boolean>().Value();
            api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str(), bIsUsingUdp);
            break;
        case 3:
            pszFlowPath = info[0].As<Napi::String>().Utf8Value();
            bIsUsingUdp = info[1].As<Napi::Boolean>().Value();
            bIsMulticast = info[2].As<Napi::Boolean>().Value();
            api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str(), bIsUsingUdp, bIsMulticast);
        default:
            break;
        }
    }

    Napi::Value GetApiVersion(const Napi::CallbackInfo &info)
    {
        return Napi::String::New(info.Env(), CThostFtdcMdApi::GetApiVersion());
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

    Napi::Value SubscribeMarketData(const Napi::CallbackInfo &info)
    {
        auto a = info[0].As<Napi::Array>();
        int nCount = a.Length();
        char ** ppList = new char* [nCount];
        for (int i = 0; i < nCount; i++)
        {
            ppList[i] = new char[31];
            strcpy(ppList[i], a.Get(i).As<Napi::String>().Utf8Value().c_str());
        }
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->SubscribeMarketData(ppList, info[1].As<Napi::Number>().Int32Value()));
        for (int i = 0; i < nCount; i++)
        {
            delete ppList[i];
        }
        delete[] ppList;
        return rtnValue;
    }

    Napi::Value UnSubscribeMarketData(const Napi::CallbackInfo &info)
    {
        auto a = info[0].As<Napi::Array>();
        int nCount = a.Length();
        char ** ppList = new char* [nCount];
        for (int i = 0; i < nCount; i++)
        {
            ppList[i] = new char[31];
            strcpy(ppList[i], a.Get(i).As<Napi::String>().Utf8Value().c_str());
        }
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->UnSubscribeMarketData(ppList, info[1].As<Napi::Number>().Int32Value()));
        for (int i = 0; i < nCount; i++)
        {
            delete ppList[i];
        }
        delete[] ppList;
        return rtnValue;
    }

    Napi::Value SubscribeForQuoteRsp(const Napi::CallbackInfo &info)
    {
        auto a = info[0].As<Napi::Array>();
        int nCount = a.Length();
        char ** ppList = new char* [nCount];
        for (int i = 0; i < nCount; i++)
        {
            ppList[i] = new char[31];
            strcpy(ppList[i], a.Get(i).As<Napi::String>().Utf8Value().c_str());
        }
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->SubscribeForQuoteRsp(ppList, info[1].As<Napi::Number>().Int32Value()));
        for (int i = 0; i < nCount; i++)
        {
            delete ppList[i];
        }
        delete[] ppList;
        return rtnValue;
    }

    Napi::Value UnSubscribeForQuoteRsp(const Napi::CallbackInfo &info)
    {
        auto a = info[0].As<Napi::Array>();
        int nCount = a.Length();
        char ** ppList = new char* [nCount];
        for (int i = 0; i < nCount; i++)
        {
            ppList[i] = new char[31];
            strcpy(ppList[i], a.Get(i).As<Napi::String>().Utf8Value().c_str());
        }
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->UnSubscribeForQuoteRsp(ppList, info[1].As<Napi::Number>().Int32Value()));
        for (int i = 0; i < nCount; i++)
        {
            delete ppList[i];
        }
        delete[] ppList;
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

    Napi::Value ReqQryMulticastInstrument(const Napi::CallbackInfo &info)
    {
        CThostFtdcQryMulticastInstrumentField cfd = { 0 };
        auto jsObj = info[0].As<Napi::Object>();
        cfd.TopicID = jsObj.Get("TopicID").As<Napi::Number>().Int32Value();
        strcpy(cfd.reserve1, (const char*)jsObj.Get("reserve1").As<Napi::String>().Utf8Value().c_str() );
        strcpy(cfd.InstrumentID, (const char*)jsObj.Get("InstrumentID").As<Napi::String>().Utf8Value().c_str() );
        Napi::Value rtnValue = Napi::Number::New(info.Env(), api->ReqQryMulticastInstrument(&cfd, info[1].As<Napi::Number>().Int32Value()));
        return rtnValue;
    }



    Napi::ThreadSafeFunction emitter = nullptr;
    Napi::ObjectReference jsthis;
};


#endif //JTP_MDAPI_H