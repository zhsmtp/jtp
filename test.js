'use strict';
const jtp = require('./jtp')
const iconv = require('iconv-lite');


var td_front_addr = "tcp://180.168.146.187:10201"; //simnow
var md_front_addr = "tcp://180.168.146.187:10211"; //simnow
var nRequestID = 0;

var mdapi = new jtp.MdApi();
var tdapi = new jtp.TdApi();

var UserID = '11111'
var BrokerID = '9999'
var Password = '11111'
const AppID = 'simnow_client_test';
const AuthCode = '0000000000000000';


var instruments = [];

mdapi.getEmitter();
mdapi.on('OnFrontConnected', () => {
    console.log('js OnFrontConnected');
    var req = new jtp.CThostFtdcReqUserLoginField();
    req.UserID = UserID;
    req.BrokerID = BrokerID;
    req.Password = Password;
    mdapi.ReqUserLogin(req, nRequestID++);
});
mdapi.on('OnRspUserLogin', (msg) => {
    console.log('js OnRspUserLogin');
    console.log(msg);
});
mdapi.CreateFtdcMdApi('./conData/md/');
mdapi.RegisterSpi();
mdapi.RegisterFront(md_front_addr);
mdapi.Init();

console.log(mdapi.GetApiVersion());

tdapi.getEmitter();
tdapi.CreateFtdcTraderApi('./conData/td/');
console.log(tdapi.GetApiVersion());

function ReqQryClassifiedInstrument() {
    console.log('ReqQryClassifiedInstrument');
    var req = new jtp.CThostFtdcQryClassifiedInstrumentField();
    // req.ExchangeID = 'SHFE';
    req.TradingType = jtp.constant.THOST_FTDC_TD_ALL;
    req.ClassType = jtp.constant.THOST_FTDC_INS_FUTURE;
    tdapi.ReqQryClassifiedInstrument(req, nRequestID++);
}

tdapi.on('OnFrontConnected', () => {
    var req = new jtp.CThostFtdcReqAuthenticateField();
    req.AppID = AppID;
    req.AuthCode = AuthCode;
    req.UserProductInfo = "ctp trader";
    req.BrokerID = BrokerID;
    tdapi.ReqAuthenticate(req, nRequestID++);
});
tdapi.on('OnRspAuthenticate', (msg) => {
    jtp.g2u(msg)
    console.log('OnRspAuthenticate');
    var req = new jtp.CThostFtdcReqUserLoginField();
    req.UserID = UserID
    req.Password = Password
    req.BrokerID = BrokerID
    var ret = tdapi.ReqUserLogin(req, nRequestID++);
});
tdapi.on('OnRspUserLogin', (msg) => {
    jtp.g2u(msg)
    console.log('td: OnRspUserLogin');
    console.log(msg);


    //这里需要延时，否则会异常退出。
    setTimeout(() => { ReqQryClassifiedInstrument(); }, 100);

    // req = new jtp.CThostFtdcQrySettlementInfoField()
    // req.AccountID = UserID
    // req.BrokerID = BrokerID
    // req.InvestorID = UserID
    // tdapi.ReqQrySettlementInfo(req, nRequestID++);
});

tdapi.on('OnRspQryClassifiedInstrument', (msg) => {
    jtp.g2u(msg)
    if ('pInstrument' in msg) {
        instruments.push(msg['pInstrument']);
        console.log(msg['pInstrument'].InstrumentID);
        // console.log(msg);
    }
    if (msg['bIsLast']) {
        // console.log(msg['pInstrument'].InstrumentID);
        console.log('==================================');
        console.log(instruments.length);
    }
});




tdapi.RegisterSpi();
tdapi.SubscribePublicTopic(2); //THOST_TERT_QUICK
tdapi.SubscribePrivateTopic(2); // THOST_TERT_QUICK
tdapi.RegisterFront(td_front_addr);
tdapi.Init();


setTimeout(() => {
    mdapi.closeEmitter();
    tdapi.closeEmitter();
    console.log('bye.....................................');
}, 10000);