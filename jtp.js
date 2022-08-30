'use strict';

const EventEmitter = require('events').EventEmitter;
const jtp = require('./build/Release/jtp');
const iconv = require('iconv-lite');

const inherits = require('util').inherits;

inherits(jtp.MdApi, EventEmitter);
inherits(jtp.TdApi, EventEmitter);

jtp.g2u = function(obj) {
    if (Buffer.isBuffer(obj)) {
        return iconv.decode(obj, 'gb2312')
    } else {
        for (var m in obj) {
            if (Buffer.isBuffer(obj[m])) {
                obj[m] = iconv.decode(obj[m], 'gb2312')
            } else {
                for (var n in obj[m]) {
                    if (Buffer.isBuffer(obj[m][n])) {
                        obj[m][n] = iconv.decode(obj[m][n], 'gb2312')
                    }
                }
            }
        }
    }
}

jtp.constant = new Object();
jtp.constant.THOST_FTDC_EXP_Normal = '0';
jtp.constant.THOST_FTDC_EXP_GenOrderByTrade = '1';
jtp.constant.THOST_FTDC_ICT_EID = '0';
jtp.constant.THOST_FTDC_ICT_IDCard = '1';
jtp.constant.THOST_FTDC_ICT_OfficerIDCard = '2';
jtp.constant.THOST_FTDC_ICT_PoliceIDCard = '3';
jtp.constant.THOST_FTDC_ICT_SoldierIDCard = '4';
jtp.constant.THOST_FTDC_ICT_HouseholdRegister = '5';
jtp.constant.THOST_FTDC_ICT_Passport = '6';
jtp.constant.THOST_FTDC_ICT_TaiwanCompatriotIDCard = '7';
jtp.constant.THOST_FTDC_ICT_HomeComingCard = '8';
jtp.constant.THOST_FTDC_ICT_LicenseNo = '9';
jtp.constant.THOST_FTDC_ICT_TaxNo = 'A';
jtp.constant.THOST_FTDC_ICT_HMMainlandTravelPermit = 'B';
jtp.constant.THOST_FTDC_ICT_TwMainlandTravelPermit = 'C';
jtp.constant.THOST_FTDC_ICT_DrivingLicense = 'D';
jtp.constant.THOST_FTDC_ICT_SocialID = 'F';
jtp.constant.THOST_FTDC_ICT_LocalID = 'G';
jtp.constant.THOST_FTDC_ICT_BusinessRegistration = 'H';
jtp.constant.THOST_FTDC_ICT_HKMCIDCard = 'I';
jtp.constant.THOST_FTDC_ICT_AccountsPermits = 'J';
jtp.constant.THOST_FTDC_ICT_FrgPrmtRdCard = 'K';
jtp.constant.THOST_FTDC_ICT_CptMngPrdLetter = 'L';
jtp.constant.THOST_FTDC_ICT_UniformSocialCreditCode = 'N';
jtp.constant.THOST_FTDC_ICT_CorporationCertNo = 'O';
jtp.constant.THOST_FTDC_ICT_OtherCard = 'x';
jtp.constant.THOST_FTDC_IR_All = '1';
jtp.constant.THOST_FTDC_IR_Group = '2';
jtp.constant.THOST_FTDC_IR_Single = '3';
jtp.constant.THOST_FTDC_DR_All = '1';
jtp.constant.THOST_FTDC_DR_Group = '2';
jtp.constant.THOST_FTDC_DR_Single = '3';
jtp.constant.THOST_FTDC_DS_Asynchronous = '1';
jtp.constant.THOST_FTDC_DS_Synchronizing = '2';
jtp.constant.THOST_FTDC_DS_Synchronized = '3';
jtp.constant.THOST_FTDC_BDS_Synchronized = '1';
jtp.constant.THOST_FTDC_BDS_Synchronizing = '2';
jtp.constant.THOST_FTDC_ECS_NoConnection = '1';
jtp.constant.THOST_FTDC_ECS_QryInstrumentSent = '2';
jtp.constant.THOST_FTDC_ECS_GotInformation = '9';
jtp.constant.THOST_FTDC_TCS_NotConnected = '1';
jtp.constant.THOST_FTDC_TCS_Connected = '2';
jtp.constant.THOST_FTDC_TCS_QryInstrumentSent = '3';
jtp.constant.THOST_FTDC_TCS_SubPrivateFlow = '4';
jtp.constant.THOST_FTDC_FC_DataAsync = '1';
jtp.constant.THOST_FTDC_FC_ForceUserLogout = '2';
jtp.constant.THOST_FTDC_FC_UserPasswordUpdate = '3';
jtp.constant.THOST_FTDC_FC_BrokerPasswordUpdate = '4';
jtp.constant.THOST_FTDC_FC_InvestorPasswordUpdate = '5';
jtp.constant.THOST_FTDC_FC_OrderInsert = '6';
jtp.constant.THOST_FTDC_FC_OrderAction = '7';
jtp.constant.THOST_FTDC_FC_SyncSystemData = '8';
jtp.constant.THOST_FTDC_FC_SyncBrokerData = '9';
jtp.constant.THOST_FTDC_FC_BachSyncBrokerData = 'A';
jtp.constant.THOST_FTDC_FC_SuperQuery = 'B';
jtp.constant.THOST_FTDC_FC_ParkedOrderInsert = 'C';
jtp.constant.THOST_FTDC_FC_ParkedOrderAction = 'D';
jtp.constant.THOST_FTDC_FC_SyncOTP = 'E';
jtp.constant.THOST_FTDC_FC_DeleteOrder = 'F';
jtp.constant.THOST_FTDC_BFC_ForceUserLogout = '1';
jtp.constant.THOST_FTDC_BFC_UserPasswordUpdate = '2';
jtp.constant.THOST_FTDC_BFC_SyncBrokerData = '3';
jtp.constant.THOST_FTDC_BFC_BachSyncBrokerData = '4';
jtp.constant.THOST_FTDC_BFC_OrderInsert = '5';
jtp.constant.THOST_FTDC_BFC_OrderAction = '6';
jtp.constant.THOST_FTDC_BFC_AllQuery = '7';
jtp.constant.THOST_FTDC_BFC_log = 'a';
jtp.constant.THOST_FTDC_BFC_BaseQry = 'b';
jtp.constant.THOST_FTDC_BFC_TradeQry = 'c';
jtp.constant.THOST_FTDC_BFC_Trade = 'd';
jtp.constant.THOST_FTDC_BFC_Virement = 'e';
jtp.constant.THOST_FTDC_BFC_Risk = 'f';
jtp.constant.THOST_FTDC_BFC_Session = 'g';
jtp.constant.THOST_FTDC_BFC_RiskNoticeCtl = 'h';
jtp.constant.THOST_FTDC_BFC_RiskNotice = 'i';
jtp.constant.THOST_FTDC_BFC_BrokerDeposit = 'j';
jtp.constant.THOST_FTDC_BFC_QueryFund = 'k';
jtp.constant.THOST_FTDC_BFC_QueryOrder = 'l';
jtp.constant.THOST_FTDC_BFC_QueryTrade = 'm';
jtp.constant.THOST_FTDC_BFC_QueryPosition = 'n';
jtp.constant.THOST_FTDC_BFC_QueryMarketData = 'o';
jtp.constant.THOST_FTDC_BFC_QueryUserEvent = 'p';
jtp.constant.THOST_FTDC_BFC_QueryRiskNotify = 'q';
jtp.constant.THOST_FTDC_BFC_QueryFundChange = 'r';
jtp.constant.THOST_FTDC_BFC_QueryInvestor = 's';
jtp.constant.THOST_FTDC_BFC_QueryTradingCode = 't';
jtp.constant.THOST_FTDC_BFC_ForceClose = 'u';
jtp.constant.THOST_FTDC_BFC_PressTest = 'v';
jtp.constant.THOST_FTDC_BFC_RemainCalc = 'w';
jtp.constant.THOST_FTDC_BFC_NetPositionInd = 'x';
jtp.constant.THOST_FTDC_BFC_RiskPredict = 'y';
jtp.constant.THOST_FTDC_BFC_DataExport = 'z';
jtp.constant.THOST_FTDC_BFC_RiskTargetSetup = 'A';
jtp.constant.THOST_FTDC_BFC_MarketDataWarn = 'B';
jtp.constant.THOST_FTDC_BFC_QryBizNotice = 'C';
jtp.constant.THOST_FTDC_BFC_CfgBizNotice = 'D';
jtp.constant.THOST_FTDC_BFC_SyncOTP = 'E';
jtp.constant.THOST_FTDC_BFC_SendBizNotice = 'F';
jtp.constant.THOST_FTDC_BFC_CfgRiskLevelStd = 'G';
jtp.constant.THOST_FTDC_BFC_TbCommand = 'H';
jtp.constant.THOST_FTDC_BFC_DeleteOrder = 'J';
jtp.constant.THOST_FTDC_BFC_ParkedOrderInsert = 'K';
jtp.constant.THOST_FTDC_BFC_ParkedOrderAction = 'L';
jtp.constant.THOST_FTDC_BFC_ExecOrderNoCheck = 'M';
jtp.constant.THOST_FTDC_BFC_Designate = 'N';
jtp.constant.THOST_FTDC_BFC_StockDisposal = 'O';
jtp.constant.THOST_FTDC_BFC_BrokerDepositWarn = 'Q';
jtp.constant.THOST_FTDC_BFC_CoverWarn = 'S';
jtp.constant.THOST_FTDC_BFC_PreExecOrder = 'T';
jtp.constant.THOST_FTDC_BFC_ExecOrderRisk = 'P';
jtp.constant.THOST_FTDC_BFC_PosiLimitWarn = 'U';
jtp.constant.THOST_FTDC_BFC_QryPosiLimit = 'V';
jtp.constant.THOST_FTDC_BFC_FBSign = 'W';
jtp.constant.THOST_FTDC_BFC_FBAccount = 'X';
jtp.constant.THOST_FTDC_OAS_Submitted = 'a';
jtp.constant.THOST_FTDC_OAS_Accepted = 'b';
jtp.constant.THOST_FTDC_OAS_Rejected = 'c';
jtp.constant.THOST_FTDC_OST_AllTraded = '0';
jtp.constant.THOST_FTDC_OST_PartTradedQueueing = '1';
jtp.constant.THOST_FTDC_OST_PartTradedNotQueueing = '2';
jtp.constant.THOST_FTDC_OST_NoTradeQueueing = '3';
jtp.constant.THOST_FTDC_OST_NoTradeNotQueueing = '4';
jtp.constant.THOST_FTDC_OST_Canceled = '5';
jtp.constant.THOST_FTDC_OST_Unknown = 'a';
jtp.constant.THOST_FTDC_OST_NotTouched = 'b';
jtp.constant.THOST_FTDC_OST_Touched = 'c';
jtp.constant.THOST_FTDC_OSS_InsertSubmitted = '0';
jtp.constant.THOST_FTDC_OSS_CancelSubmitted = '1';
jtp.constant.THOST_FTDC_OSS_ModifySubmitted = '2';
jtp.constant.THOST_FTDC_OSS_Accepted = '3';
jtp.constant.THOST_FTDC_OSS_InsertRejected = '4';
jtp.constant.THOST_FTDC_OSS_CancelRejected = '5';
jtp.constant.THOST_FTDC_OSS_ModifyRejected = '6';
jtp.constant.THOST_FTDC_PSD_Today = '1';
jtp.constant.THOST_FTDC_PSD_History = '2';
jtp.constant.THOST_FTDC_PDT_UseHistory = '1';
jtp.constant.THOST_FTDC_PDT_NoUseHistory = '2';
jtp.constant.THOST_FTDC_ER_Broker = '1';
jtp.constant.THOST_FTDC_ER_Host = '2';
jtp.constant.THOST_FTDC_ER_Maker = '3';
jtp.constant.THOST_FTDC_PC_Futures = '1';
jtp.constant.THOST_FTDC_PC_Options = '2';
jtp.constant.THOST_FTDC_PC_Combination = '3';
jtp.constant.THOST_FTDC_PC_Spot = '4';
jtp.constant.THOST_FTDC_PC_EFP = '5';
jtp.constant.THOST_FTDC_PC_SpotOption = '6';
jtp.constant.THOST_FTDC_PC_TAS = '7';
jtp.constant.THOST_FTDC_PC_MI = 'I';
jtp.constant.THOST_FTDC_APC_FutureSingle = '1';
jtp.constant.THOST_FTDC_APC_OptionSingle = '2';
jtp.constant.THOST_FTDC_APC_Futures = '3';
jtp.constant.THOST_FTDC_APC_Options = '4';
jtp.constant.THOST_FTDC_APC_TradingComb = '5';
jtp.constant.THOST_FTDC_APC_UnTradingComb = '6';
jtp.constant.THOST_FTDC_APC_AllTrading = '7';
jtp.constant.THOST_FTDC_APC_All = '8';
jtp.constant.THOST_FTDC_IP_NotStart = '0';
jtp.constant.THOST_FTDC_IP_Started = '1';
jtp.constant.THOST_FTDC_IP_Pause = '2';
jtp.constant.THOST_FTDC_IP_Expired = '3';
jtp.constant.THOST_FTDC_D_Buy = '0';
jtp.constant.THOST_FTDC_D_Sell = '1';
jtp.constant.THOST_FTDC_PT_Net = '1';
jtp.constant.THOST_FTDC_PT_Gross = '2';
jtp.constant.THOST_FTDC_PD_Net = '1';
jtp.constant.THOST_FTDC_PD_Long = '2';
jtp.constant.THOST_FTDC_PD_Short = '3';
jtp.constant.THOST_FTDC_SS_NonActive = '1';
jtp.constant.THOST_FTDC_SS_Startup = '2';
jtp.constant.THOST_FTDC_SS_Operating = '3';
jtp.constant.THOST_FTDC_SS_Settlement = '4';
jtp.constant.THOST_FTDC_SS_SettlementFinished = '5';
jtp.constant.THOST_FTDC_RA_Trade = '0';
jtp.constant.THOST_FTDC_RA_Settlement = '1';
jtp.constant.THOST_FTDC_HF_Speculation = '1';
jtp.constant.THOST_FTDC_HF_Arbitrage = '2';
jtp.constant.THOST_FTDC_HF_Hedge = '3';
jtp.constant.THOST_FTDC_HF_MarketMaker = '5';
jtp.constant.THOST_FTDC_HF_SpecHedge = '6';
jtp.constant.THOST_FTDC_HF_HedgeSpec = '7';
jtp.constant.THOST_FTDC_BHF_Speculation = '1';
jtp.constant.THOST_FTDC_BHF_Arbitrage = '2';
jtp.constant.THOST_FTDC_BHF_Hedge = '3';
jtp.constant.THOST_FTDC_CIDT_Speculation = '1';
jtp.constant.THOST_FTDC_CIDT_Arbitrage = '2';
jtp.constant.THOST_FTDC_CIDT_Hedge = '3';
jtp.constant.THOST_FTDC_CIDT_MarketMaker = '5';
jtp.constant.THOST_FTDC_OPT_AnyPrice = '1';
jtp.constant.THOST_FTDC_OPT_LimitPrice = '2';
jtp.constant.THOST_FTDC_OPT_BestPrice = '3';
jtp.constant.THOST_FTDC_OPT_LastPrice = '4';
jtp.constant.THOST_FTDC_OPT_LastPricePlusOneTicks = '5';
jtp.constant.THOST_FTDC_OPT_LastPricePlusTwoTicks = '6';
jtp.constant.THOST_FTDC_OPT_LastPricePlusThreeTicks = '7';
jtp.constant.THOST_FTDC_OPT_AskPrice1 = '8';
jtp.constant.THOST_FTDC_OPT_AskPrice1PlusOneTicks = '9';
jtp.constant.THOST_FTDC_OPT_AskPrice1PlusTwoTicks = 'A';
jtp.constant.THOST_FTDC_OPT_AskPrice1PlusThreeTicks = 'B';
jtp.constant.THOST_FTDC_OPT_BidPrice1 = 'C';
jtp.constant.THOST_FTDC_OPT_BidPrice1PlusOneTicks = 'D';
jtp.constant.THOST_FTDC_OPT_BidPrice1PlusTwoTicks = 'E';
jtp.constant.THOST_FTDC_OPT_BidPrice1PlusThreeTicks = 'F';
jtp.constant.THOST_FTDC_OPT_FiveLevelPrice = 'G';
jtp.constant.THOST_FTDC_OF_Open = '0';
jtp.constant.THOST_FTDC_OF_Close = '1';
jtp.constant.THOST_FTDC_OF_ForceClose = '2';
jtp.constant.THOST_FTDC_OF_CloseToday = '3';
jtp.constant.THOST_FTDC_OF_CloseYesterday = '4';
jtp.constant.THOST_FTDC_OF_ForceOff = '5';
jtp.constant.THOST_FTDC_OF_LocalForceClose = '6';
jtp.constant.THOST_FTDC_FCC_NotForceClose = '0';
jtp.constant.THOST_FTDC_FCC_LackDeposit = '1';
jtp.constant.THOST_FTDC_FCC_ClientOverPositionLimit = '2';
jtp.constant.THOST_FTDC_FCC_MemberOverPositionLimit = '3';
jtp.constant.THOST_FTDC_FCC_NotMultiple = '4';
jtp.constant.THOST_FTDC_FCC_Violation = '5';
jtp.constant.THOST_FTDC_FCC_Other = '6';
jtp.constant.THOST_FTDC_FCC_PersonDeliv = '7';
jtp.constant.THOST_FTDC_ORDT_Normal = '0';
jtp.constant.THOST_FTDC_ORDT_DeriveFromQuote = '1';
jtp.constant.THOST_FTDC_ORDT_DeriveFromCombination = '2';
jtp.constant.THOST_FTDC_ORDT_Combination = '3';
jtp.constant.THOST_FTDC_ORDT_ConditionalOrder = '4';
jtp.constant.THOST_FTDC_ORDT_Swap = '5';
jtp.constant.THOST_FTDC_ORDT_DeriveFromBlockTrade = '6';
jtp.constant.THOST_FTDC_ORDT_DeriveFromEFPTrade = '7';
jtp.constant.THOST_FTDC_TC_IOC = '1';
jtp.constant.THOST_FTDC_TC_GFS = '2';
jtp.constant.THOST_FTDC_TC_GFD = '3';
jtp.constant.THOST_FTDC_TC_GTD = '4';
jtp.constant.THOST_FTDC_TC_GTC = '5';
jtp.constant.THOST_FTDC_TC_GFA = '6';
jtp.constant.THOST_FTDC_VC_AV = '1';
jtp.constant.THOST_FTDC_VC_MV = '2';
jtp.constant.THOST_FTDC_VC_CV = '3';
jtp.constant.THOST_FTDC_CC_Immediately = '1';
jtp.constant.THOST_FTDC_CC_Touch = '2';
jtp.constant.THOST_FTDC_CC_TouchProfit = '3';
jtp.constant.THOST_FTDC_CC_ParkedOrder = '4';
jtp.constant.THOST_FTDC_CC_LastPriceGreaterThanStopPrice = '5';
jtp.constant.THOST_FTDC_CC_LastPriceGreaterEqualStopPrice = '6';
jtp.constant.THOST_FTDC_CC_LastPriceLesserThanStopPrice = '7';
jtp.constant.THOST_FTDC_CC_LastPriceLesserEqualStopPrice = '8';
jtp.constant.THOST_FTDC_CC_AskPriceGreaterThanStopPrice = '9';
jtp.constant.THOST_FTDC_CC_AskPriceGreaterEqualStopPrice = 'A';
jtp.constant.THOST_FTDC_CC_AskPriceLesserThanStopPrice = 'B';
jtp.constant.THOST_FTDC_CC_AskPriceLesserEqualStopPrice = 'C';
jtp.constant.THOST_FTDC_CC_BidPriceGreaterThanStopPrice = 'D';
jtp.constant.THOST_FTDC_CC_BidPriceGreaterEqualStopPrice = 'E';
jtp.constant.THOST_FTDC_CC_BidPriceLesserThanStopPrice = 'F';
jtp.constant.THOST_FTDC_CC_BidPriceLesserEqualStopPrice = 'H';
jtp.constant.THOST_FTDC_AF_Delete = '0';
jtp.constant.THOST_FTDC_AF_Modify = '3';
jtp.constant.THOST_FTDC_TR_Allow = '0';
jtp.constant.THOST_FTDC_TR_CloseOnly = '1';
jtp.constant.THOST_FTDC_TR_Forbidden = '2';
jtp.constant.THOST_FTDC_OSRC_Participant = '0';
jtp.constant.THOST_FTDC_OSRC_Administrator = '1';
jtp.constant.THOST_FTDC_TRDT_SplitCombination = '#';
jtp.constant.THOST_FTDC_TRDT_Common = '0';
jtp.constant.THOST_FTDC_TRDT_OptionsExecution = '1';
jtp.constant.THOST_FTDC_TRDT_OTC = '2';
jtp.constant.THOST_FTDC_TRDT_EFPDerived = '3';
jtp.constant.THOST_FTDC_TRDT_CombinationDerived = '4';
jtp.constant.THOST_FTDC_TRDT_BlockTrade = '5';
jtp.constant.THOST_FTDC_SPOST_Common = '#';
jtp.constant.THOST_FTDC_SPOST_Tas = '0';
jtp.constant.THOST_FTDC_PSRC_LastPrice = '0';
jtp.constant.THOST_FTDC_PSRC_Buy = '1';
jtp.constant.THOST_FTDC_PSRC_Sell = '2';
jtp.constant.THOST_FTDC_PSRC_OTC = '3';
jtp.constant.THOST_FTDC_IS_BeforeTrading = '0';
jtp.constant.THOST_FTDC_IS_NoTrading = '1';
jtp.constant.THOST_FTDC_IS_Continous = '2';
jtp.constant.THOST_FTDC_IS_AuctionOrdering = '3';
jtp.constant.THOST_FTDC_IS_AuctionBalance = '4';
jtp.constant.THOST_FTDC_IS_AuctionMatch = '5';
jtp.constant.THOST_FTDC_IS_Closed = '6';
jtp.constant.THOST_FTDC_IER_Automatic = '1';
jtp.constant.THOST_FTDC_IER_Manual = '2';
jtp.constant.THOST_FTDC_IER_Fuse = '3';
jtp.constant.THOST_FTDC_BS_NoUpload = '1';
jtp.constant.THOST_FTDC_BS_Uploaded = '2';
jtp.constant.THOST_FTDC_BS_Failed = '3';
jtp.constant.THOST_FTDC_RS_All = '1';
jtp.constant.THOST_FTDC_RS_ByProduct = '2';
jtp.constant.THOST_FTDC_RP_ByVolume = '1';
jtp.constant.THOST_FTDC_RP_ByFeeOnHand = '2';
jtp.constant.THOST_FTDC_RL_Level1 = '1';
jtp.constant.THOST_FTDC_RL_Level2 = '2';
jtp.constant.THOST_FTDC_RL_Level3 = '3';
jtp.constant.THOST_FTDC_RL_Level4 = '4';
jtp.constant.THOST_FTDC_RL_Level5 = '5';
jtp.constant.THOST_FTDC_RL_Level6 = '6';
jtp.constant.THOST_FTDC_RL_Level7 = '7';
jtp.constant.THOST_FTDC_RL_Level8 = '8';
jtp.constant.THOST_FTDC_RL_Level9 = '9';
jtp.constant.THOST_FTDC_RSD_ByPeriod = '1';
jtp.constant.THOST_FTDC_RSD_ByStandard = '2';
jtp.constant.THOST_FTDC_MT_Out = '0';
jtp.constant.THOST_FTDC_MT_In = '1';
jtp.constant.THOST_FTDC_ISPI_MortgageRatio = '4';
jtp.constant.THOST_FTDC_ISPI_MarginWay = '5';
jtp.constant.THOST_FTDC_ISPI_BillDeposit = '9';
jtp.constant.THOST_FTDC_ESPI_MortgageRatio = '1';
jtp.constant.THOST_FTDC_ESPI_OtherFundItem = '2';
jtp.constant.THOST_FTDC_ESPI_OtherFundImport = '3';
jtp.constant.THOST_FTDC_ESPI_CFFEXMinPrepa = '6';
jtp.constant.THOST_FTDC_ESPI_CZCESettlementType = '7';
jtp.constant.THOST_FTDC_ESPI_ExchDelivFeeMode = '9';
jtp.constant.THOST_FTDC_ESPI_DelivFeeMode = '0';
jtp.constant.THOST_FTDC_ESPI_CZCEComMarginType = 'A';
jtp.constant.THOST_FTDC_ESPI_DceComMarginType = 'B';
jtp.constant.THOST_FTDC_ESPI_OptOutDisCountRate = 'a';
jtp.constant.THOST_FTDC_ESPI_OptMiniGuarantee = 'b';
jtp.constant.THOST_FTDC_SPI_InvestorIDMinLength = '1';
jtp.constant.THOST_FTDC_SPI_AccountIDMinLength = '2';
jtp.constant.THOST_FTDC_SPI_UserRightLogon = '3';
jtp.constant.THOST_FTDC_SPI_SettlementBillTrade = '4';
jtp.constant.THOST_FTDC_SPI_TradingCode = '5';
jtp.constant.THOST_FTDC_SPI_CheckFund = '6';
jtp.constant.THOST_FTDC_SPI_CommModelRight = '7';
jtp.constant.THOST_FTDC_SPI_MarginModelRight = '9';
jtp.constant.THOST_FTDC_SPI_IsStandardActive = '8';
jtp.constant.THOST_FTDC_SPI_UploadSettlementFile = 'U';
jtp.constant.THOST_FTDC_SPI_DownloadCSRCFile = 'D';
jtp.constant.THOST_FTDC_SPI_SettlementBillFile = 'S';
jtp.constant.THOST_FTDC_SPI_CSRCOthersFile = 'C';
jtp.constant.THOST_FTDC_SPI_InvestorPhoto = 'P';
jtp.constant.THOST_FTDC_SPI_CSRCData = 'R';
jtp.constant.THOST_FTDC_SPI_InvestorPwdModel = 'I';
jtp.constant.THOST_FTDC_SPI_CFFEXInvestorSettleFile = 'F';
jtp.constant.THOST_FTDC_SPI_InvestorIDType = 'a';
jtp.constant.THOST_FTDC_SPI_FreezeMaxReMain = 'r';
jtp.constant.THOST_FTDC_SPI_IsSync = 'A';
jtp.constant.THOST_FTDC_SPI_RelieveOpenLimit = 'O';
jtp.constant.THOST_FTDC_SPI_IsStandardFreeze = 'X';
jtp.constant.THOST_FTDC_SPI_CZCENormalProductHedge = 'B';
jtp.constant.THOST_FTDC_TPID_EncryptionStandard = 'E';
jtp.constant.THOST_FTDC_TPID_RiskMode = 'R';
jtp.constant.THOST_FTDC_TPID_RiskModeGlobal = 'G';
jtp.constant.THOST_FTDC_TPID_modeEncode = 'P';
jtp.constant.THOST_FTDC_TPID_tickMode = 'T';
jtp.constant.THOST_FTDC_TPID_SingleUserSessionMaxNum = 'S';
jtp.constant.THOST_FTDC_TPID_LoginFailMaxNum = 'L';
jtp.constant.THOST_FTDC_TPID_IsAuthForce = 'A';
jtp.constant.THOST_FTDC_TPID_IsPosiFreeze = 'F';
jtp.constant.THOST_FTDC_TPID_IsPosiLimit = 'M';
jtp.constant.THOST_FTDC_TPID_ForQuoteTimeInterval = 'Q';
jtp.constant.THOST_FTDC_TPID_IsFuturePosiLimit = 'B';
jtp.constant.THOST_FTDC_TPID_IsFutureOrderFreq = 'C';
jtp.constant.THOST_FTDC_TPID_IsExecOrderProfit = 'H';
jtp.constant.THOST_FTDC_TPID_IsCheckBankAcc = 'I';
jtp.constant.THOST_FTDC_TPID_PasswordDeadLine = 'J';
jtp.constant.THOST_FTDC_TPID_IsStrongPassword = 'K';
jtp.constant.THOST_FTDC_TPID_BalanceMorgage = 'a';
jtp.constant.THOST_FTDC_TPID_MinPwdLen = 'O';
jtp.constant.THOST_FTDC_TPID_LoginFailMaxNumForIP = 'U';
jtp.constant.THOST_FTDC_TPID_PasswordPeriod = 'V';
jtp.constant.THOST_FTDC_FI_SettlementFund = 'F';
jtp.constant.THOST_FTDC_FI_Trade = 'T';
jtp.constant.THOST_FTDC_FI_InvestorPosition = 'P';
jtp.constant.THOST_FTDC_FI_SubEntryFund = 'O';
jtp.constant.THOST_FTDC_FI_CZCECombinationPos = 'C';
jtp.constant.THOST_FTDC_FI_CSRCData = 'R';
jtp.constant.THOST_FTDC_FI_CZCEClose = 'L';
jtp.constant.THOST_FTDC_FI_CZCENoClose = 'N';
jtp.constant.THOST_FTDC_FI_PositionDtl = 'D';
jtp.constant.THOST_FTDC_FI_OptionStrike = 'S';
jtp.constant.THOST_FTDC_FI_SettlementPriceComparison = 'M';
jtp.constant.THOST_FTDC_FI_NonTradePosChange = 'B';
jtp.constant.THOST_FTDC_FUT_Settlement = '0';
jtp.constant.THOST_FTDC_FUT_Check = '1';
jtp.constant.THOST_FTDC_FFT_Txt = '0';
jtp.constant.THOST_FTDC_FFT_Zip = '1';
jtp.constant.THOST_FTDC_FFT_DBF = '2';
jtp.constant.THOST_FTDC_FUS_SucceedUpload = '1';
jtp.constant.THOST_FTDC_FUS_FailedUpload = '2';
jtp.constant.THOST_FTDC_FUS_SucceedLoad = '3';
jtp.constant.THOST_FTDC_FUS_PartSucceedLoad = '4';
jtp.constant.THOST_FTDC_FUS_FailedLoad = '5';
jtp.constant.THOST_FTDC_TD_Out = '0';
jtp.constant.THOST_FTDC_TD_In = '1';
jtp.constant.THOST_FTDC_SC_NoSpecialRule = '0';
jtp.constant.THOST_FTDC_SC_NoSpringFestival = '1';
jtp.constant.THOST_FTDC_IPT_LastSettlement = '1';
jtp.constant.THOST_FTDC_IPT_LaseClose = '2';
jtp.constant.THOST_FTDC_PLP_Active = '1';
jtp.constant.THOST_FTDC_PLP_NonActive = '2';
jtp.constant.THOST_FTDC_PLP_Canceled = '3';
jtp.constant.THOST_FTDC_DM_CashDeliv = '1';
jtp.constant.THOST_FTDC_DM_CommodityDeliv = '2';
jtp.constant.THOST_FTDC_FIOT_FundIO = '1';
jtp.constant.THOST_FTDC_FIOT_Transfer = '2';
jtp.constant.THOST_FTDC_FIOT_SwapCurrency = '3';
jtp.constant.THOST_FTDC_FT_Deposite = '1';
jtp.constant.THOST_FTDC_FT_ItemFund = '2';
jtp.constant.THOST_FTDC_FT_Company = '3';
jtp.constant.THOST_FTDC_FT_InnerTransfer = '4';
jtp.constant.THOST_FTDC_FD_In = '1';
jtp.constant.THOST_FTDC_FD_Out = '2';
jtp.constant.THOST_FTDC_FS_Record = '1';
jtp.constant.THOST_FTDC_FS_Check = '2';
jtp.constant.THOST_FTDC_FS_Charge = '3';
jtp.constant.THOST_FTDC_PS_None = '1';
jtp.constant.THOST_FTDC_PS_Publishing = '2';
jtp.constant.THOST_FTDC_PS_Published = '3';
jtp.constant.THOST_FTDC_ES_NonActive = '1';
jtp.constant.THOST_FTDC_ES_Startup = '2';
jtp.constant.THOST_FTDC_ES_Initialize = '3';
jtp.constant.THOST_FTDC_ES_Initialized = '4';
jtp.constant.THOST_FTDC_ES_Close = '5';
jtp.constant.THOST_FTDC_ES_Closed = '6';
jtp.constant.THOST_FTDC_ES_Settlement = '7';
jtp.constant.THOST_FTDC_STS_Initialize = '0';
jtp.constant.THOST_FTDC_STS_Settlementing = '1';
jtp.constant.THOST_FTDC_STS_Settlemented = '2';
jtp.constant.THOST_FTDC_STS_Finished = '3';
jtp.constant.THOST_FTDC_CT_Person = '0';
jtp.constant.THOST_FTDC_CT_Company = '1';
jtp.constant.THOST_FTDC_CT_Fund = '2';
jtp.constant.THOST_FTDC_CT_SpecialOrgan = '3';
jtp.constant.THOST_FTDC_CT_Asset = '4';
jtp.constant.THOST_FTDC_BT_Trade = '0';
jtp.constant.THOST_FTDC_BT_TradeSettle = '1';
jtp.constant.THOST_FTDC_FAS_Low = '1';
jtp.constant.THOST_FTDC_FAS_Normal = '2';
jtp.constant.THOST_FTDC_FAS_Focus = '3';
jtp.constant.THOST_FTDC_FAS_Risk = '4';
jtp.constant.THOST_FTDC_FAS_ByTrade = '1';
jtp.constant.THOST_FTDC_FAS_ByDeliv = '2';
jtp.constant.THOST_FTDC_FAS_None = '3';
jtp.constant.THOST_FTDC_FAS_FixFee = '4';
jtp.constant.THOST_FTDC_PWDT_Trade = '1';
jtp.constant.THOST_FTDC_PWDT_Account = '2';
jtp.constant.THOST_FTDC_AG_All = '1';
jtp.constant.THOST_FTDC_AG_OnlyLost = '2';
jtp.constant.THOST_FTDC_AG_OnlyGain = '3';
jtp.constant.THOST_FTDC_AG_None = '4';
jtp.constant.THOST_FTDC_ICP_Include = '0';
jtp.constant.THOST_FTDC_ICP_NotInclude = '2';
jtp.constant.THOST_FTDC_AWT_Enable = '0';
jtp.constant.THOST_FTDC_AWT_Disable = '2';
jtp.constant.THOST_FTDC_AWT_NoHoldEnable = '3';
jtp.constant.THOST_FTDC_FPWD_UnCheck = '0';
jtp.constant.THOST_FTDC_FPWD_Check = '1';
jtp.constant.THOST_FTDC_TT_BankToFuture = '0';
jtp.constant.THOST_FTDC_TT_FutureToBank = '1';
jtp.constant.THOST_FTDC_TVF_Invalid = '0';
jtp.constant.THOST_FTDC_TVF_Valid = '1';
jtp.constant.THOST_FTDC_TVF_Reverse = '2';
jtp.constant.THOST_FTDC_RN_CD = '0';
jtp.constant.THOST_FTDC_RN_ZT = '1';
jtp.constant.THOST_FTDC_RN_QT = '2';
jtp.constant.THOST_FTDC_SEX_None = '0';
jtp.constant.THOST_FTDC_SEX_Man = '1';
jtp.constant.THOST_FTDC_SEX_Woman = '2';
jtp.constant.THOST_FTDC_UT_Investor = '0';
jtp.constant.THOST_FTDC_UT_Operator = '1';
jtp.constant.THOST_FTDC_UT_SuperUser = '2';
jtp.constant.THOST_FTDC_RATETYPE_MarginRate = '2';
jtp.constant.THOST_FTDC_NOTETYPE_TradeSettleBill = '1';
jtp.constant.THOST_FTDC_NOTETYPE_TradeSettleMonth = '2';
jtp.constant.THOST_FTDC_NOTETYPE_CallMarginNotes = '3';
jtp.constant.THOST_FTDC_NOTETYPE_ForceCloseNotes = '4';
jtp.constant.THOST_FTDC_NOTETYPE_TradeNotes = '5';
jtp.constant.THOST_FTDC_NOTETYPE_DelivNotes = '6';
jtp.constant.THOST_FTDC_SBS_Day = '1';
jtp.constant.THOST_FTDC_SBS_Volume = '2';
jtp.constant.THOST_FTDC_ST_Day = '0';
jtp.constant.THOST_FTDC_ST_Month = '1';
jtp.constant.THOST_FTDC_URT_Logon = '1';
jtp.constant.THOST_FTDC_URT_Transfer = '2';
jtp.constant.THOST_FTDC_URT_EMail = '3';
jtp.constant.THOST_FTDC_URT_Fax = '4';
jtp.constant.THOST_FTDC_URT_ConditionOrder = '5';
jtp.constant.THOST_FTDC_MPT_PreSettlementPrice = '1';
jtp.constant.THOST_FTDC_MPT_SettlementPrice = '2';
jtp.constant.THOST_FTDC_MPT_AveragePrice = '3';
jtp.constant.THOST_FTDC_MPT_OpenPrice = '4';
jtp.constant.THOST_FTDC_BGS_None = '0';
jtp.constant.THOST_FTDC_BGS_NoGenerated = '1';
jtp.constant.THOST_FTDC_BGS_Generated = '2';
jtp.constant.THOST_FTDC_AT_HandlePositionAlgo = '1';
jtp.constant.THOST_FTDC_AT_FindMarginRateAlgo = '2';
jtp.constant.THOST_FTDC_HPA_Base = '1';
jtp.constant.THOST_FTDC_HPA_DCE = '2';
jtp.constant.THOST_FTDC_HPA_CZCE = '3';
jtp.constant.THOST_FTDC_FMRA_Base = '1';
jtp.constant.THOST_FTDC_FMRA_DCE = '2';
jtp.constant.THOST_FTDC_FMRA_CZCE = '3';
jtp.constant.THOST_FTDC_HTAA_Base = '1';
jtp.constant.THOST_FTDC_HTAA_DCE = '2';
jtp.constant.THOST_FTDC_HTAA_CZCE = '3';
jtp.constant.THOST_FTDC_PST_Order = '1';
jtp.constant.THOST_FTDC_PST_Open = '2';
jtp.constant.THOST_FTDC_PST_Fund = '3';
jtp.constant.THOST_FTDC_PST_Settlement = '4';
jtp.constant.THOST_FTDC_PST_Company = '5';
jtp.constant.THOST_FTDC_PST_Corporation = '6';
jtp.constant.THOST_FTDC_PST_LinkMan = '7';
jtp.constant.THOST_FTDC_PST_Ledger = '8';
jtp.constant.THOST_FTDC_PST_Trustee = '9';
jtp.constant.THOST_FTDC_PST_TrusteeCorporation = 'A';
jtp.constant.THOST_FTDC_PST_TrusteeOpen = 'B';
jtp.constant.THOST_FTDC_PST_TrusteeContact = 'C';
jtp.constant.THOST_FTDC_PST_ForeignerRefer = 'D';
jtp.constant.THOST_FTDC_PST_CorporationRefer = 'E';
jtp.constant.THOST_FTDC_QIR_All = '1';
jtp.constant.THOST_FTDC_QIR_Group = '2';
jtp.constant.THOST_FTDC_QIR_Single = '3';
jtp.constant.THOST_FTDC_IRS_Normal = '1';
jtp.constant.THOST_FTDC_IRS_Warn = '2';
jtp.constant.THOST_FTDC_IRS_Call = '3';
jtp.constant.THOST_FTDC_IRS_Force = '4';
jtp.constant.THOST_FTDC_IRS_Exception = '5';
jtp.constant.THOST_FTDC_UET_Login = '1';
jtp.constant.THOST_FTDC_UET_Logout = '2';
jtp.constant.THOST_FTDC_UET_Trading = '3';
jtp.constant.THOST_FTDC_UET_TradingError = '4';
jtp.constant.THOST_FTDC_UET_UpdatePassword = '5';
jtp.constant.THOST_FTDC_UET_Authenticate = '6';
jtp.constant.THOST_FTDC_UET_SubmitSysInfo = '7';
jtp.constant.THOST_FTDC_UET_Transfer = '8';
jtp.constant.THOST_FTDC_UET_Other = '9';
jtp.constant.THOST_FTDC_ICS_Close = '0';
jtp.constant.THOST_FTDC_ICS_CloseToday = '1';
jtp.constant.THOST_FTDC_SM_Non = '0';
jtp.constant.THOST_FTDC_SM_Instrument = '1';
jtp.constant.THOST_FTDC_SM_Product = '2';
jtp.constant.THOST_FTDC_SM_Investor = '3';
jtp.constant.THOST_FTDC_PAOS_NotSend = '1';
jtp.constant.THOST_FTDC_PAOS_Send = '2';
jtp.constant.THOST_FTDC_PAOS_Deleted = '3';
jtp.constant.THOST_FTDC_VDS_Dealing = '1';
jtp.constant.THOST_FTDC_VDS_DeaclSucceed = '2';
jtp.constant.THOST_FTDC_ORGS_Standard = '0';
jtp.constant.THOST_FTDC_ORGS_ESunny = '1';
jtp.constant.THOST_FTDC_ORGS_KingStarV6 = '2';
jtp.constant.THOST_FTDC_VTS_NaturalDeal = '0';
jtp.constant.THOST_FTDC_VTS_SucceedEnd = '1';
jtp.constant.THOST_FTDC_VTS_FailedEND = '2';
jtp.constant.THOST_FTDC_VTS_Exception = '3';
jtp.constant.THOST_FTDC_VTS_ManualDeal = '4';
jtp.constant.THOST_FTDC_VTS_MesException = '5';
jtp.constant.THOST_FTDC_VTS_SysException = '6';
jtp.constant.THOST_FTDC_VBAT_BankBook = '1';
jtp.constant.THOST_FTDC_VBAT_BankCard = '2';
jtp.constant.THOST_FTDC_VBAT_CreditCard = '3';
jtp.constant.THOST_FTDC_VMS_Natural = '0';
jtp.constant.THOST_FTDC_VMS_Canceled = '9';
jtp.constant.THOST_FTDC_VAA_NoAvailAbility = '0';
jtp.constant.THOST_FTDC_VAA_AvailAbility = '1';
jtp.constant.THOST_FTDC_VAA_Repeal = '2';
jtp.constant.THOST_FTDC_VTC_BankBankToFuture = '102001';
jtp.constant.THOST_FTDC_VTC_BankFutureToBank = '102002';
jtp.constant.THOST_FTDC_VTC_FutureBankToFuture = '202001';
jtp.constant.THOST_FTDC_VTC_FutureFutureToBank = '202002';
jtp.constant.THOST_FTDC_GEN_Program = '0';
jtp.constant.THOST_FTDC_GEN_HandWork = '1';
jtp.constant.THOST_FTDC_CFMMCKK_REQUEST = 'R';
jtp.constant.THOST_FTDC_CFMMCKK_AUTO = 'A';
jtp.constant.THOST_FTDC_CFMMCKK_MANUAL = 'M';
jtp.constant.THOST_FTDC_CFT_IDCard = '0';
jtp.constant.THOST_FTDC_CFT_Passport = '1';
jtp.constant.THOST_FTDC_CFT_OfficerIDCard = '2';
jtp.constant.THOST_FTDC_CFT_SoldierIDCard = '3';
jtp.constant.THOST_FTDC_CFT_HomeComingCard = '4';
jtp.constant.THOST_FTDC_CFT_HouseholdRegister = '5';
jtp.constant.THOST_FTDC_CFT_LicenseNo = '6';
jtp.constant.THOST_FTDC_CFT_InstitutionCodeCard = '7';
jtp.constant.THOST_FTDC_CFT_TempLicenseNo = '8';
jtp.constant.THOST_FTDC_CFT_NoEnterpriseLicenseNo = '9';
jtp.constant.THOST_FTDC_CFT_OtherCard = 'x';
jtp.constant.THOST_FTDC_CFT_SuperDepAgree = 'a';
jtp.constant.THOST_FTDC_FBC_Others = '0';
jtp.constant.THOST_FTDC_FBC_TransferDetails = '1';
jtp.constant.THOST_FTDC_FBC_CustAccStatus = '2';
jtp.constant.THOST_FTDC_FBC_AccountTradeDetails = '3';
jtp.constant.THOST_FTDC_FBC_FutureAccountChangeInfoDetails = '4';
jtp.constant.THOST_FTDC_FBC_CustMoneyDetail = '5';
jtp.constant.THOST_FTDC_FBC_CustCancelAccountInfo = '6';
jtp.constant.THOST_FTDC_FBC_CustMoneyResult = '7';
jtp.constant.THOST_FTDC_FBC_OthersExceptionResult = '8';
jtp.constant.THOST_FTDC_FBC_CustInterestNetMoneyDetails = '9';
jtp.constant.THOST_FTDC_FBC_CustMoneySendAndReceiveDetails = 'a';
jtp.constant.THOST_FTDC_FBC_CorporationMoneyTotal = 'b';
jtp.constant.THOST_FTDC_FBC_MainbodyMoneyTotal = 'c';
jtp.constant.THOST_FTDC_FBC_MainPartMonitorData = 'd';
jtp.constant.THOST_FTDC_FBC_PreparationMoney = 'e';
jtp.constant.THOST_FTDC_FBC_BankMoneyMonitorData = 'f';
jtp.constant.THOST_FTDC_CEC_Exchange = '1';
jtp.constant.THOST_FTDC_CEC_Cash = '2';
jtp.constant.THOST_FTDC_YNI_Yes = '0';
jtp.constant.THOST_FTDC_YNI_No = '1';
jtp.constant.THOST_FTDC_BLT_CurrentMoney = '0';
jtp.constant.THOST_FTDC_BLT_UsableMoney = '1';
jtp.constant.THOST_FTDC_BLT_FetchableMoney = '2';
jtp.constant.THOST_FTDC_BLT_FreezeMoney = '3';
jtp.constant.THOST_FTDC_GD_Unknown = '0';
jtp.constant.THOST_FTDC_GD_Male = '1';
jtp.constant.THOST_FTDC_GD_Female = '2';
jtp.constant.THOST_FTDC_FPF_BEN = '0';
jtp.constant.THOST_FTDC_FPF_OUR = '1';
jtp.constant.THOST_FTDC_FPF_SHA = '2';
jtp.constant.THOST_FTDC_PWKT_ExchangeKey = '0';
jtp.constant.THOST_FTDC_PWKT_PassWordKey = '1';
jtp.constant.THOST_FTDC_PWKT_MACKey = '2';
jtp.constant.THOST_FTDC_PWKT_MessageKey = '3';
jtp.constant.THOST_FTDC_PWT_Query = '0';
jtp.constant.THOST_FTDC_PWT_Fetch = '1';
jtp.constant.THOST_FTDC_PWT_Transfer = '2';
jtp.constant.THOST_FTDC_PWT_Trade = '3';
jtp.constant.THOST_FTDC_EM_NoEncry = '0';
jtp.constant.THOST_FTDC_EM_DES = '1';
jtp.constant.THOST_FTDC_EM_3DES = '2';
jtp.constant.THOST_FTDC_BRF_BankNotNeedRepeal = '0';
jtp.constant.THOST_FTDC_BRF_BankWaitingRepeal = '1';
jtp.constant.THOST_FTDC_BRF_BankBeenRepealed = '2';
jtp.constant.THOST_FTDC_BRORF_BrokerNotNeedRepeal = '0';
jtp.constant.THOST_FTDC_BRORF_BrokerWaitingRepeal = '1';
jtp.constant.THOST_FTDC_BRORF_BrokerBeenRepealed = '2';
jtp.constant.THOST_FTDC_TS_Bank = '0';
jtp.constant.THOST_FTDC_TS_Future = '1';
jtp.constant.THOST_FTDC_TS_Store = '2';
jtp.constant.THOST_FTDC_LF_Yes = '0';
jtp.constant.THOST_FTDC_LF_No = '1';
jtp.constant.THOST_FTDC_BAS_Normal = '0';
jtp.constant.THOST_FTDC_BAS_Freeze = '1';
jtp.constant.THOST_FTDC_BAS_ReportLoss = '2';
jtp.constant.THOST_FTDC_MAS_Normal = '0';
jtp.constant.THOST_FTDC_MAS_Cancel = '1';
jtp.constant.THOST_FTDC_MSS_Point = '0';
jtp.constant.THOST_FTDC_MSS_PrePoint = '1';
jtp.constant.THOST_FTDC_MSS_CancelPoint = '2';
jtp.constant.THOST_FTDC_SYT_FutureBankTransfer = '0';
jtp.constant.THOST_FTDC_SYT_StockBankTransfer = '1';
jtp.constant.THOST_FTDC_SYT_TheThirdPartStore = '2';
jtp.constant.THOST_FTDC_TEF_NormalProcessing = '0';
jtp.constant.THOST_FTDC_TEF_Success = '1';
jtp.constant.THOST_FTDC_TEF_Failed = '2';
jtp.constant.THOST_FTDC_TEF_Abnormal = '3';
jtp.constant.THOST_FTDC_TEF_ManualProcessedForException = '4';
jtp.constant.THOST_FTDC_TEF_CommuFailedNeedManualProcess = '5';
jtp.constant.THOST_FTDC_TEF_SysErrorNeedManualProcess = '6';
jtp.constant.THOST_FTDC_PSS_NotProcess = '0';
jtp.constant.THOST_FTDC_PSS_StartProcess = '1';
jtp.constant.THOST_FTDC_PSS_Finished = '2';
jtp.constant.THOST_FTDC_CUSTT_Person = '0';
jtp.constant.THOST_FTDC_CUSTT_Institution = '1';
jtp.constant.THOST_FTDC_FBTTD_FromBankToFuture = '1';
jtp.constant.THOST_FTDC_FBTTD_FromFutureToBank = '2';
jtp.constant.THOST_FTDC_OOD_Open = '1';
jtp.constant.THOST_FTDC_OOD_Destroy = '0';
jtp.constant.THOST_FTDC_AVAF_Invalid = '0';
jtp.constant.THOST_FTDC_AVAF_Valid = '1';
jtp.constant.THOST_FTDC_AVAF_Repeal = '2';
jtp.constant.THOST_FTDC_OT_Bank = '1';
jtp.constant.THOST_FTDC_OT_Future = '2';
jtp.constant.THOST_FTDC_OT_PlateForm = '9';
jtp.constant.THOST_FTDC_OL_HeadQuarters = '1';
jtp.constant.THOST_FTDC_OL_Branch = '2';
jtp.constant.THOST_FTDC_PID_FutureProtocal = '0';
jtp.constant.THOST_FTDC_PID_ICBCProtocal = '1';
jtp.constant.THOST_FTDC_PID_ABCProtocal = '2';
jtp.constant.THOST_FTDC_PID_CBCProtocal = '3';
jtp.constant.THOST_FTDC_PID_CCBProtocal = '4';
jtp.constant.THOST_FTDC_PID_BOCOMProtocal = '5';
jtp.constant.THOST_FTDC_PID_FBTPlateFormProtocal = 'X';
jtp.constant.THOST_FTDC_CM_ShortConnect = '0';
jtp.constant.THOST_FTDC_CM_LongConnect = '1';
jtp.constant.THOST_FTDC_SRM_ASync = '0';
jtp.constant.THOST_FTDC_SRM_Sync = '1';
jtp.constant.THOST_FTDC_BAT_BankBook = '1';
jtp.constant.THOST_FTDC_BAT_SavingCard = '2';
jtp.constant.THOST_FTDC_BAT_CreditCard = '3';
jtp.constant.THOST_FTDC_FAT_BankBook = '1';
jtp.constant.THOST_FTDC_FAT_SavingCard = '2';
jtp.constant.THOST_FTDC_FAT_CreditCard = '3';
jtp.constant.THOST_FTDC_OS_Ready = '0';
jtp.constant.THOST_FTDC_OS_CheckIn = '1';
jtp.constant.THOST_FTDC_OS_CheckOut = '2';
jtp.constant.THOST_FTDC_OS_CheckFileArrived = '3';
jtp.constant.THOST_FTDC_OS_CheckDetail = '4';
jtp.constant.THOST_FTDC_OS_DayEndClean = '5';
jtp.constant.THOST_FTDC_OS_Invalid = '9';
jtp.constant.THOST_FTDC_CCBFM_ByAmount = '1';
jtp.constant.THOST_FTDC_CCBFM_ByMonth = '2';
jtp.constant.THOST_FTDC_CAPIT_Client = '1';
jtp.constant.THOST_FTDC_CAPIT_Server = '2';
jtp.constant.THOST_FTDC_CAPIT_UserApi = '3';
jtp.constant.THOST_FTDC_LS_Connected = '1';
jtp.constant.THOST_FTDC_LS_Disconnected = '2';
jtp.constant.THOST_FTDC_BPWDF_NoCheck = '0';
jtp.constant.THOST_FTDC_BPWDF_BlankCheck = '1';
jtp.constant.THOST_FTDC_BPWDF_EncryptCheck = '2';
jtp.constant.THOST_FTDC_SAT_AccountID = '1';
jtp.constant.THOST_FTDC_SAT_CardID = '2';
jtp.constant.THOST_FTDC_SAT_SHStockholderID = '3';
jtp.constant.THOST_FTDC_SAT_SZStockholderID = '4';
jtp.constant.THOST_FTDC_TRFS_Normal = '0';
jtp.constant.THOST_FTDC_TRFS_Repealed = '1';
jtp.constant.THOST_FTDC_SPTYPE_Broker = '0';
jtp.constant.THOST_FTDC_SPTYPE_Bank = '1';
jtp.constant.THOST_FTDC_REQRSP_Request = '0';
jtp.constant.THOST_FTDC_REQRSP_Response = '1';
jtp.constant.THOST_FTDC_FBTUET_SignIn = '0';
jtp.constant.THOST_FTDC_FBTUET_FromBankToFuture = '1';
jtp.constant.THOST_FTDC_FBTUET_FromFutureToBank = '2';
jtp.constant.THOST_FTDC_FBTUET_OpenAccount = '3';
jtp.constant.THOST_FTDC_FBTUET_CancelAccount = '4';
jtp.constant.THOST_FTDC_FBTUET_ChangeAccount = '5';
jtp.constant.THOST_FTDC_FBTUET_RepealFromBankToFuture = '6';
jtp.constant.THOST_FTDC_FBTUET_RepealFromFutureToBank = '7';
jtp.constant.THOST_FTDC_FBTUET_QueryBankAccount = '8';
jtp.constant.THOST_FTDC_FBTUET_QueryFutureAccount = '9';
jtp.constant.THOST_FTDC_FBTUET_SignOut = 'A';
jtp.constant.THOST_FTDC_FBTUET_SyncKey = 'B';
jtp.constant.THOST_FTDC_FBTUET_ReserveOpenAccount = 'C';
jtp.constant.THOST_FTDC_FBTUET_CancelReserveOpenAccount = 'D';
jtp.constant.THOST_FTDC_FBTUET_ReserveOpenAccountConfirm = 'E';
jtp.constant.THOST_FTDC_FBTUET_Other = 'Z';
jtp.constant.THOST_FTDC_DBOP_Insert = '0';
jtp.constant.THOST_FTDC_DBOP_Update = '1';
jtp.constant.THOST_FTDC_DBOP_Delete = '2';
jtp.constant.THOST_FTDC_SYNF_Yes = '0';
jtp.constant.THOST_FTDC_SYNF_No = '1';
jtp.constant.THOST_FTDC_SYNT_OneOffSync = '0';
jtp.constant.THOST_FTDC_SYNT_TimerSync = '1';
jtp.constant.THOST_FTDC_SYNT_TimerFullSync = '2';
jtp.constant.THOST_FTDC_FBEDIR_Settlement = '0';
jtp.constant.THOST_FTDC_FBEDIR_Sale = '1';
jtp.constant.THOST_FTDC_FBERES_Success = '0';
jtp.constant.THOST_FTDC_FBERES_InsufficientBalance = '1';
jtp.constant.THOST_FTDC_FBERES_UnknownTrading = '8';
jtp.constant.THOST_FTDC_FBERES_Fail = 'x';
jtp.constant.THOST_FTDC_FBEES_Normal = '0';
jtp.constant.THOST_FTDC_FBEES_ReExchange = '1';
jtp.constant.THOST_FTDC_FBEFG_DataPackage = '0';
jtp.constant.THOST_FTDC_FBEFG_File = '1';
jtp.constant.THOST_FTDC_FBEAT_NotTrade = '0';
jtp.constant.THOST_FTDC_FBEAT_Trade = '1';
jtp.constant.THOST_FTDC_FBEUET_SignIn = '0';
jtp.constant.THOST_FTDC_FBEUET_Exchange = '1';
jtp.constant.THOST_FTDC_FBEUET_ReExchange = '2';
jtp.constant.THOST_FTDC_FBEUET_QueryBankAccount = '3';
jtp.constant.THOST_FTDC_FBEUET_QueryExchDetial = '4';
jtp.constant.THOST_FTDC_FBEUET_QueryExchSummary = '5';
jtp.constant.THOST_FTDC_FBEUET_QueryExchRate = '6';
jtp.constant.THOST_FTDC_FBEUET_CheckBankAccount = '7';
jtp.constant.THOST_FTDC_FBEUET_SignOut = '8';
jtp.constant.THOST_FTDC_FBEUET_Other = 'Z';
jtp.constant.THOST_FTDC_FBERF_UnProcessed = '0';
jtp.constant.THOST_FTDC_FBERF_WaitSend = '1';
jtp.constant.THOST_FTDC_FBERF_SendSuccess = '2';
jtp.constant.THOST_FTDC_FBERF_SendFailed = '3';
jtp.constant.THOST_FTDC_FBERF_WaitReSend = '4';
jtp.constant.THOST_FTDC_NC_NOERROR = '0';
jtp.constant.THOST_FTDC_NC_Warn = '1';
jtp.constant.THOST_FTDC_NC_Call = '2';
jtp.constant.THOST_FTDC_NC_Force = '3';
jtp.constant.THOST_FTDC_NC_CHUANCANG = '4';
jtp.constant.THOST_FTDC_NC_Exception = '5';
jtp.constant.THOST_FTDC_FCT_Manual = '0';
jtp.constant.THOST_FTDC_FCT_Single = '1';
jtp.constant.THOST_FTDC_FCT_Group = '2';
jtp.constant.THOST_FTDC_RNM_System = '0';
jtp.constant.THOST_FTDC_RNM_SMS = '1';
jtp.constant.THOST_FTDC_RNM_EMail = '2';
jtp.constant.THOST_FTDC_RNM_Manual = '3';
jtp.constant.THOST_FTDC_RNS_NotGen = '0';
jtp.constant.THOST_FTDC_RNS_Generated = '1';
jtp.constant.THOST_FTDC_RNS_SendError = '2';
jtp.constant.THOST_FTDC_RNS_SendOk = '3';
jtp.constant.THOST_FTDC_RNS_Received = '4';
jtp.constant.THOST_FTDC_RNS_Confirmed = '5';
jtp.constant.THOST_FTDC_RUE_ExportData = '0';
jtp.constant.THOST_FTDC_COST_LastPriceAsc = '0';
jtp.constant.THOST_FTDC_COST_LastPriceDesc = '1';
jtp.constant.THOST_FTDC_COST_AskPriceAsc = '2';
jtp.constant.THOST_FTDC_COST_AskPriceDesc = '3';
jtp.constant.THOST_FTDC_COST_BidPriceAsc = '4';
jtp.constant.THOST_FTDC_COST_BidPriceDesc = '5';
jtp.constant.THOST_FTDC_UOAST_NoSend = '0';
jtp.constant.THOST_FTDC_UOAST_Sended = '1';
jtp.constant.THOST_FTDC_UOAST_Generated = '2';
jtp.constant.THOST_FTDC_UOAST_SendFail = '3';
jtp.constant.THOST_FTDC_UOAST_Success = '4';
jtp.constant.THOST_FTDC_UOAST_Fail = '5';
jtp.constant.THOST_FTDC_UOAST_Cancel = '6';
jtp.constant.THOST_FTDC_UOACS_NoApply = '1';
jtp.constant.THOST_FTDC_UOACS_Submited = '2';
jtp.constant.THOST_FTDC_UOACS_Sended = '3';
jtp.constant.THOST_FTDC_UOACS_Success = '4';
jtp.constant.THOST_FTDC_UOACS_Refuse = '5';
jtp.constant.THOST_FTDC_UOACS_Cancel = '6';
jtp.constant.THOST_FTDC_QT_Radio = '1';
jtp.constant.THOST_FTDC_QT_Option = '2';
jtp.constant.THOST_FTDC_QT_Blank = '3';
jtp.constant.THOST_FTDC_BT_Request = '1';
jtp.constant.THOST_FTDC_BT_Response = '2';
jtp.constant.THOST_FTDC_BT_Notice = '3';
jtp.constant.THOST_FTDC_CRC_Success = '0';
jtp.constant.THOST_FTDC_CRC_Working = '1';
jtp.constant.THOST_FTDC_CRC_InfoFail = '2';
jtp.constant.THOST_FTDC_CRC_IDCardFail = '3';
jtp.constant.THOST_FTDC_CRC_OtherFail = '4';
jtp.constant.THOST_FTDC_CfMMCCT_All = '0';
jtp.constant.THOST_FTDC_CfMMCCT_Person = '1';
jtp.constant.THOST_FTDC_CfMMCCT_Company = '2';
jtp.constant.THOST_FTDC_CfMMCCT_Other = '3';
jtp.constant.THOST_FTDC_CfMMCCT_SpecialOrgan = '4';
jtp.constant.THOST_FTDC_CfMMCCT_Asset = '5';
jtp.constant.THOST_FTDC_EIDT_SHFE = 'S';
jtp.constant.THOST_FTDC_EIDT_CZCE = 'Z';
jtp.constant.THOST_FTDC_EIDT_DCE = 'D';
jtp.constant.THOST_FTDC_EIDT_CFFEX = 'J';
jtp.constant.THOST_FTDC_EIDT_INE = 'N';
jtp.constant.THOST_FTDC_ECIDT_Hedge = '1';
jtp.constant.THOST_FTDC_ECIDT_Arbitrage = '2';
jtp.constant.THOST_FTDC_ECIDT_Speculation = '3';
jtp.constant.THOST_FTDC_UF_NoUpdate = '0';
jtp.constant.THOST_FTDC_UF_Success = '1';
jtp.constant.THOST_FTDC_UF_Fail = '2';
jtp.constant.THOST_FTDC_UF_TCSuccess = '3';
jtp.constant.THOST_FTDC_UF_TCFail = '4';
jtp.constant.THOST_FTDC_UF_Cancel = '5';
jtp.constant.THOST_FTDC_AOID_OpenInvestor = '1';
jtp.constant.THOST_FTDC_AOID_ModifyIDCard = '2';
jtp.constant.THOST_FTDC_AOID_ModifyNoIDCard = '3';
jtp.constant.THOST_FTDC_AOID_ApplyTradingCode = '4';
jtp.constant.THOST_FTDC_AOID_CancelTradingCode = '5';
jtp.constant.THOST_FTDC_AOID_CancelInvestor = '6';
jtp.constant.THOST_FTDC_AOID_FreezeAccount = '8';
jtp.constant.THOST_FTDC_AOID_ActiveFreezeAccount = '9';
jtp.constant.THOST_FTDC_ASID_NoComplete = '1';
jtp.constant.THOST_FTDC_ASID_Submited = '2';
jtp.constant.THOST_FTDC_ASID_Checked = '3';
jtp.constant.THOST_FTDC_ASID_Refused = '4';
jtp.constant.THOST_FTDC_ASID_Deleted = '5';
jtp.constant.THOST_FTDC_UOASM_ByAPI = '1';
jtp.constant.THOST_FTDC_UOASM_ByFile = '2';
jtp.constant.THOST_FTDC_EvM_ADD = '1';
jtp.constant.THOST_FTDC_EvM_UPDATE = '2';
jtp.constant.THOST_FTDC_EvM_DELETE = '3';
jtp.constant.THOST_FTDC_EvM_CHECK = '4';
jtp.constant.THOST_FTDC_EvM_COPY = '5';
jtp.constant.THOST_FTDC_EvM_CANCEL = '6';
jtp.constant.THOST_FTDC_EvM_Reverse = '7';
jtp.constant.THOST_FTDC_UOAA_ASR = '1';
jtp.constant.THOST_FTDC_UOAA_ASNR = '2';
jtp.constant.THOST_FTDC_UOAA_NSAR = '3';
jtp.constant.THOST_FTDC_UOAA_NSR = '4';
jtp.constant.THOST_FTDC_EvM_InvestorGroupFlow = '1';
jtp.constant.THOST_FTDC_EvM_InvestorRate = '2';
jtp.constant.THOST_FTDC_EvM_InvestorCommRateModel = '3';
jtp.constant.THOST_FTDC_CL_Zero = '0';
jtp.constant.THOST_FTDC_CL_One = '1';
jtp.constant.THOST_FTDC_CL_Two = '2';
jtp.constant.THOST_FTDC_CHS_Init = '0';
jtp.constant.THOST_FTDC_CHS_Checking = '1';
jtp.constant.THOST_FTDC_CHS_Checked = '2';
jtp.constant.THOST_FTDC_CHS_Refuse = '3';
jtp.constant.THOST_FTDC_CHS_Cancel = '4';
jtp.constant.THOST_FTDC_CHU_Unused = '0';
jtp.constant.THOST_FTDC_CHU_Used = '1';
jtp.constant.THOST_FTDC_CHU_Fail = '2';
jtp.constant.THOST_FTDC_BAO_ByAccProperty = '0';
jtp.constant.THOST_FTDC_BAO_ByFBTransfer = '1';
jtp.constant.THOST_FTDC_MBTS_ByInstrument = '0';
jtp.constant.THOST_FTDC_MBTS_ByDayInsPrc = '1';
jtp.constant.THOST_FTDC_MBTS_ByDayIns = '2';
jtp.constant.THOST_FTDC_FTC_BankLaunchBankToBroker = '102001';
jtp.constant.THOST_FTDC_FTC_BrokerLaunchBankToBroker = '202001';
jtp.constant.THOST_FTDC_FTC_BankLaunchBrokerToBank = '102002';
jtp.constant.THOST_FTDC_FTC_BrokerLaunchBrokerToBank = '202002';
jtp.constant.THOST_FTDC_OTP_NONE = '0';
jtp.constant.THOST_FTDC_OTP_TOTP = '1';
jtp.constant.THOST_FTDC_OTPS_Unused = '0';
jtp.constant.THOST_FTDC_OTPS_Used = '1';
jtp.constant.THOST_FTDC_OTPS_Disuse = '2';
jtp.constant.THOST_FTDC_BUT_Investor = '1';
jtp.constant.THOST_FTDC_BUT_BrokerUser = '2';
jtp.constant.THOST_FTDC_FUTT_Commodity = '1';
jtp.constant.THOST_FTDC_FUTT_Financial = '2';
jtp.constant.THOST_FTDC_FET_Restriction = '0';
jtp.constant.THOST_FTDC_FET_TodayRestriction = '1';
jtp.constant.THOST_FTDC_FET_Transfer = '2';
jtp.constant.THOST_FTDC_FET_Credit = '3';
jtp.constant.THOST_FTDC_FET_InvestorWithdrawAlm = '4';
jtp.constant.THOST_FTDC_FET_BankRestriction = '5';
jtp.constant.THOST_FTDC_FET_Accountregister = '6';
jtp.constant.THOST_FTDC_FET_ExchangeFundIO = '7';
jtp.constant.THOST_FTDC_FET_InvestorFundIO = '8';
jtp.constant.THOST_FTDC_AST_FBTransfer = '0';
jtp.constant.THOST_FTDC_AST_ManualEntry = '1';
jtp.constant.THOST_FTDC_CST_UnifyAccount = '0';
jtp.constant.THOST_FTDC_CST_ManualEntry = '1';
jtp.constant.THOST_FTDC_UR_All = '0';
jtp.constant.THOST_FTDC_UR_Single = '1';
jtp.constant.THOST_FTDC_BG_Investor = '2';
jtp.constant.THOST_FTDC_BG_Group = '1';
jtp.constant.THOST_FTDC_TSSM_Instrument = '1';
jtp.constant.THOST_FTDC_TSSM_Product = '2';
jtp.constant.THOST_FTDC_TSSM_Exchange = '3';
jtp.constant.THOST_FTDC_ESM_Relative = '1';
jtp.constant.THOST_FTDC_ESM_Typical = '2';
jtp.constant.THOST_FTDC_RIR_All = '1';
jtp.constant.THOST_FTDC_RIR_Model = '2';
jtp.constant.THOST_FTDC_RIR_Single = '3';
jtp.constant.THOST_FTDC_SDS_Initialize = '0';
jtp.constant.THOST_FTDC_SDS_Settlementing = '1';
jtp.constant.THOST_FTDC_SDS_Settlemented = '2';
jtp.constant.THOST_FTDC_TSRC_NORMAL = '0';
jtp.constant.THOST_FTDC_TSRC_QUERY = '1';
jtp.constant.THOST_FTDC_FSM_Product = '1';
jtp.constant.THOST_FTDC_FSM_Exchange = '2';
jtp.constant.THOST_FTDC_FSM_All = '3';
jtp.constant.THOST_FTDC_BIR_Property = '1';
jtp.constant.THOST_FTDC_BIR_All = '2';
jtp.constant.THOST_FTDC_PIR_All = '1';
jtp.constant.THOST_FTDC_PIR_Property = '2';
jtp.constant.THOST_FTDC_PIR_Single = '3';
jtp.constant.THOST_FTDC_FIS_NoCreate = '0';
jtp.constant.THOST_FTDC_FIS_Created = '1';
jtp.constant.THOST_FTDC_FIS_Failed = '2';
jtp.constant.THOST_FTDC_FGS_FileTransmit = '0';
jtp.constant.THOST_FTDC_FGS_FileGen = '1';
jtp.constant.THOST_FTDC_SoM_Add = '1';
jtp.constant.THOST_FTDC_SoM_Update = '2';
jtp.constant.THOST_FTDC_SoM_Delete = '3';
jtp.constant.THOST_FTDC_SoM_Copy = '4';
jtp.constant.THOST_FTDC_SoM_AcTive = '5';
jtp.constant.THOST_FTDC_SoM_CanCel = '6';
jtp.constant.THOST_FTDC_SoM_ReSet = '7';
jtp.constant.THOST_FTDC_SoT_UpdatePassword = '0';
jtp.constant.THOST_FTDC_SoT_UserDepartment = '1';
jtp.constant.THOST_FTDC_SoT_RoleManager = '2';
jtp.constant.THOST_FTDC_SoT_RoleFunction = '3';
jtp.constant.THOST_FTDC_SoT_BaseParam = '4';
jtp.constant.THOST_FTDC_SoT_SetUserID = '5';
jtp.constant.THOST_FTDC_SoT_SetUserRole = '6';
jtp.constant.THOST_FTDC_SoT_UserIpRestriction = '7';
jtp.constant.THOST_FTDC_SoT_DepartmentManager = '8';
jtp.constant.THOST_FTDC_SoT_DepartmentCopy = '9';
jtp.constant.THOST_FTDC_SoT_Tradingcode = 'A';
jtp.constant.THOST_FTDC_SoT_InvestorStatus = 'B';
jtp.constant.THOST_FTDC_SoT_InvestorAuthority = 'C';
jtp.constant.THOST_FTDC_SoT_PropertySet = 'D';
jtp.constant.THOST_FTDC_SoT_ReSetInvestorPasswd = 'E';
jtp.constant.THOST_FTDC_SoT_InvestorPersonalityInfo = 'F';
jtp.constant.THOST_FTDC_CSRCQ_Current = '0';
jtp.constant.THOST_FTDC_CSRCQ_History = '1';
jtp.constant.THOST_FTDC_FRS_Normal = '1';
jtp.constant.THOST_FTDC_FRS_Freeze = '0';
jtp.constant.THOST_FTDC_STST_Standard = '0';
jtp.constant.THOST_FTDC_STST_NonStandard = '1';
jtp.constant.THOST_FTDC_RPT_Freeze = '1';
jtp.constant.THOST_FTDC_RPT_FreezeActive = '2';
jtp.constant.THOST_FTDC_RPT_OpenLimit = '3';
jtp.constant.THOST_FTDC_RPT_RelieveOpenLimit = '4';
jtp.constant.THOST_FTDC_AMLDS_Normal = '0';
jtp.constant.THOST_FTDC_AMLDS_Deleted = '1';
jtp.constant.THOST_FTDC_AMLCHS_Init = '0';
jtp.constant.THOST_FTDC_AMLCHS_Checking = '1';
jtp.constant.THOST_FTDC_AMLCHS_Checked = '2';
jtp.constant.THOST_FTDC_AMLCHS_RefuseReport = '3';
jtp.constant.THOST_FTDC_AMLDT_DrawDay = '0';
jtp.constant.THOST_FTDC_AMLDT_TouchDay = '1';
jtp.constant.THOST_FTDC_AMLCL_CheckLevel0 = '0';
jtp.constant.THOST_FTDC_AMLCL_CheckLevel1 = '1';
jtp.constant.THOST_FTDC_AMLCL_CheckLevel2 = '2';
jtp.constant.THOST_FTDC_AMLCL_CheckLevel3 = '3';
jtp.constant.THOST_FTDC_EFT_CSV = '0';
jtp.constant.THOST_FTDC_EFT_EXCEL = '1';
jtp.constant.THOST_FTDC_EFT_DBF = '2';
jtp.constant.THOST_FTDC_SMT_Before = '1';
jtp.constant.THOST_FTDC_SMT_Settlement = '2';
jtp.constant.THOST_FTDC_SMT_After = '3';
jtp.constant.THOST_FTDC_SMT_Settlemented = '4';
jtp.constant.THOST_FTDC_SML_Must = '1';
jtp.constant.THOST_FTDC_SML_Alarm = '2';
jtp.constant.THOST_FTDC_SML_Prompt = '3';
jtp.constant.THOST_FTDC_SML_Ignore = '4';
jtp.constant.THOST_FTDC_SMG_Exhcange = '1';
jtp.constant.THOST_FTDC_SMG_ASP = '2';
jtp.constant.THOST_FTDC_SMG_CSRC = '3';
jtp.constant.THOST_FTDC_LUT_Repeatable = '1';
jtp.constant.THOST_FTDC_LUT_Unrepeatable = '2';
jtp.constant.THOST_FTDC_DAR_Settle = '1';
jtp.constant.THOST_FTDC_DAR_Exchange = '2';
jtp.constant.THOST_FTDC_DAR_CSRC = '3';
jtp.constant.THOST_FTDC_MGT_ExchMarginRate = '0';
jtp.constant.THOST_FTDC_MGT_InstrMarginRate = '1';
jtp.constant.THOST_FTDC_MGT_InstrMarginRateTrade = '2';
jtp.constant.THOST_FTDC_ACT_Intraday = '1';
jtp.constant.THOST_FTDC_ACT_Long = '2';
jtp.constant.THOST_FTDC_MRT_Exchange = '1';
jtp.constant.THOST_FTDC_MRT_Investor = '2';
jtp.constant.THOST_FTDC_MRT_InvestorTrade = '3';
jtp.constant.THOST_FTDC_BUS_UnBak = '0';
jtp.constant.THOST_FTDC_BUS_BakUp = '1';
jtp.constant.THOST_FTDC_BUS_BakUped = '2';
jtp.constant.THOST_FTDC_BUS_BakFail = '3';
jtp.constant.THOST_FTDC_SIS_UnInitialize = '0';
jtp.constant.THOST_FTDC_SIS_Initialize = '1';
jtp.constant.THOST_FTDC_SIS_Initialized = '2';
jtp.constant.THOST_FTDC_SRS_NoCreate = '0';
jtp.constant.THOST_FTDC_SRS_Create = '1';
jtp.constant.THOST_FTDC_SRS_Created = '2';
jtp.constant.THOST_FTDC_SRS_CreateFail = '3';
jtp.constant.THOST_FTDC_SSS_UnSaveData = '0';
jtp.constant.THOST_FTDC_SSS_SaveDatad = '1';
jtp.constant.THOST_FTDC_SAS_UnArchived = '0';
jtp.constant.THOST_FTDC_SAS_Archiving = '1';
jtp.constant.THOST_FTDC_SAS_Archived = '2';
jtp.constant.THOST_FTDC_SAS_ArchiveFail = '3';
jtp.constant.THOST_FTDC_CTPT_Unkown = '0';
jtp.constant.THOST_FTDC_CTPT_MainCenter = '1';
jtp.constant.THOST_FTDC_CTPT_BackUp = '2';
jtp.constant.THOST_FTDC_CDT_Normal = '0';
jtp.constant.THOST_FTDC_CDT_SpecFirst = '1';
jtp.constant.THOST_FTDC_MFUR_None = '0';
jtp.constant.THOST_FTDC_MFUR_Margin = '1';
jtp.constant.THOST_FTDC_MFUR_All = '2';
jtp.constant.THOST_FTDC_MFUR_CNY3 = '3';
jtp.constant.THOST_FTDC_SPT_CzceHedge = '1';
jtp.constant.THOST_FTDC_SPT_IneForeignCurrency = '2';
jtp.constant.THOST_FTDC_SPT_DceOpenClose = '3';
jtp.constant.THOST_FTDC_FMT_Mortgage = '1';
jtp.constant.THOST_FTDC_FMT_Redemption = '2';
jtp.constant.THOST_FTDC_ASPI_BaseMargin = '1';
jtp.constant.THOST_FTDC_ASPI_LowestInterest = '2';
jtp.constant.THOST_FTDC_FMD_In = '1';
jtp.constant.THOST_FTDC_FMD_Out = '2';
jtp.constant.THOST_FTDC_BT_Profit = '0';
jtp.constant.THOST_FTDC_BT_Loss = '1';
jtp.constant.THOST_FTDC_BT_Other = 'Z';
jtp.constant.THOST_FTDC_SST_Manual = '0';
jtp.constant.THOST_FTDC_SST_Automatic = '1';
jtp.constant.THOST_FTDC_CED_Settlement = '0';
jtp.constant.THOST_FTDC_CED_Sale = '1';
jtp.constant.THOST_FTDC_CSS_Entry = '1';
jtp.constant.THOST_FTDC_CSS_Approve = '2';
jtp.constant.THOST_FTDC_CSS_Refuse = '3';
jtp.constant.THOST_FTDC_CSS_Revoke = '4';
jtp.constant.THOST_FTDC_CSS_Send = '5';
jtp.constant.THOST_FTDC_CSS_Success = '6';
jtp.constant.THOST_FTDC_CSS_Failure = '7';
jtp.constant.THOST_FTDC_REQF_NoSend = '0';
jtp.constant.THOST_FTDC_REQF_SendSuccess = '1';
jtp.constant.THOST_FTDC_REQF_SendFailed = '2';
jtp.constant.THOST_FTDC_REQF_WaitReSend = '3';
jtp.constant.THOST_FTDC_RESF_Success = '0';
jtp.constant.THOST_FTDC_RESF_InsuffiCient = '1';
jtp.constant.THOST_FTDC_RESF_UnKnown = '8';
jtp.constant.THOST_FTDC_EXS_Before = '0';
jtp.constant.THOST_FTDC_EXS_After = '1';
jtp.constant.THOST_FTDC_CR_Domestic = '1';
jtp.constant.THOST_FTDC_CR_GMT = '2';
jtp.constant.THOST_FTDC_CR_Foreign = '3';
jtp.constant.THOST_FTDC_HB_No = '0';
jtp.constant.THOST_FTDC_HB_Yes = '1';
jtp.constant.THOST_FTDC_SM_Normal = '1';
jtp.constant.THOST_FTDC_SM_Emerge = '2';
jtp.constant.THOST_FTDC_SM_Restore = '3';
jtp.constant.THOST_FTDC_TPT_Full = '1';
jtp.constant.THOST_FTDC_TPT_Increment = '2';
jtp.constant.THOST_FTDC_TPT_BackUp = '3';
jtp.constant.THOST_FTDC_LM_Trade = '0';
jtp.constant.THOST_FTDC_LM_Transfer = '1';
jtp.constant.THOST_FTDC_CPT_Instrument = '1';
jtp.constant.THOST_FTDC_CPT_Margin = '2';
jtp.constant.THOST_FTDC_HT_Yes = '1';
jtp.constant.THOST_FTDC_HT_No = '0';
jtp.constant.THOST_FTDC_AMT_Bank = '1';
jtp.constant.THOST_FTDC_AMT_Securities = '2';
jtp.constant.THOST_FTDC_AMT_Fund = '3';
jtp.constant.THOST_FTDC_AMT_Insurance = '4';
jtp.constant.THOST_FTDC_AMT_Trust = '5';
jtp.constant.THOST_FTDC_AMT_Other = '9';
jtp.constant.THOST_FTDC_CFIOT_FundIO = '0';
jtp.constant.THOST_FTDC_CFIOT_SwapCurrency = '1';
jtp.constant.THOST_FTDC_CAT_Futures = '1';
jtp.constant.THOST_FTDC_CAT_AssetmgrFuture = '2';
jtp.constant.THOST_FTDC_CAT_AssetmgrTrustee = '3';
jtp.constant.THOST_FTDC_CAT_AssetmgrTransfer = '4';
jtp.constant.THOST_FTDC_LT_Chinese = '1';
jtp.constant.THOST_FTDC_LT_English = '2';
jtp.constant.THOST_FTDC_AMCT_Person = '1';
jtp.constant.THOST_FTDC_AMCT_Organ = '2';
jtp.constant.THOST_FTDC_AMCT_SpecialOrgan = '4';
jtp.constant.THOST_FTDC_ASST_Futures = '3';
jtp.constant.THOST_FTDC_ASST_SpecialOrgan = '4';
jtp.constant.THOST_FTDC_CIT_HasExch = '0';
jtp.constant.THOST_FTDC_CIT_HasATP = '1';
jtp.constant.THOST_FTDC_CIT_HasDiff = '2';
jtp.constant.THOST_FTDC_DT_HandDeliv = '1';
jtp.constant.THOST_FTDC_DT_PersonDeliv = '2';
jtp.constant.THOST_FTDC_MMSA_NO = '0';
jtp.constant.THOST_FTDC_MMSA_YES = '1';
jtp.constant.THOST_FTDC_CACT_Person = '0';
jtp.constant.THOST_FTDC_CACT_Company = '1';
jtp.constant.THOST_FTDC_CACT_Other = '2';
jtp.constant.THOST_FTDC_UOAAT_Futures = '1';
jtp.constant.THOST_FTDC_UOAAT_SpecialOrgan = '2';
jtp.constant.THOST_FTDC_DEN_Buy = '0';
jtp.constant.THOST_FTDC_DEN_Sell = '1';
jtp.constant.THOST_FTDC_OFEN_Open = '0';
jtp.constant.THOST_FTDC_OFEN_Close = '1';
jtp.constant.THOST_FTDC_OFEN_ForceClose = '2';
jtp.constant.THOST_FTDC_OFEN_CloseToday = '3';
jtp.constant.THOST_FTDC_OFEN_CloseYesterday = '4';
jtp.constant.THOST_FTDC_OFEN_ForceOff = '5';
jtp.constant.THOST_FTDC_OFEN_LocalForceClose = '6';
jtp.constant.THOST_FTDC_HFEN_Speculation = '1';
jtp.constant.THOST_FTDC_HFEN_Arbitrage = '2';
jtp.constant.THOST_FTDC_HFEN_Hedge = '3';
jtp.constant.THOST_FTDC_FIOTEN_FundIO = '1';
jtp.constant.THOST_FTDC_FIOTEN_Transfer = '2';
jtp.constant.THOST_FTDC_FIOTEN_SwapCurrency = '3';
jtp.constant.THOST_FTDC_FTEN_Deposite = '1';
jtp.constant.THOST_FTDC_FTEN_ItemFund = '2';
jtp.constant.THOST_FTDC_FTEN_Company = '3';
jtp.constant.THOST_FTDC_FTEN_InnerTransfer = '4';
jtp.constant.THOST_FTDC_FDEN_In = '1';
jtp.constant.THOST_FTDC_FDEN_Out = '2';
jtp.constant.THOST_FTDC_FMDEN_In = '1';
jtp.constant.THOST_FTDC_FMDEN_Out = '2';
jtp.constant.THOST_FTDC_CP_CallOptions = '1';
jtp.constant.THOST_FTDC_CP_PutOptions = '2';
jtp.constant.THOST_FTDC_STM_Continental = '0';
jtp.constant.THOST_FTDC_STM_American = '1';
jtp.constant.THOST_FTDC_STM_Bermuda = '2';
jtp.constant.THOST_FTDC_STT_Hedge = '0';
jtp.constant.THOST_FTDC_STT_Match = '1';
jtp.constant.THOST_FTDC_APPT_NotStrikeNum = '4';
jtp.constant.THOST_FTDC_GUDS_Gen = '0';
jtp.constant.THOST_FTDC_GUDS_Hand = '1';
jtp.constant.THOST_FTDC_OER_NoExec = 'n';
jtp.constant.THOST_FTDC_OER_Canceled = 'c';
jtp.constant.THOST_FTDC_OER_OK = '0';
jtp.constant.THOST_FTDC_OER_NoPosition = '1';
jtp.constant.THOST_FTDC_OER_NoDeposit = '2';
jtp.constant.THOST_FTDC_OER_NoParticipant = '3';
jtp.constant.THOST_FTDC_OER_NoClient = '4';
jtp.constant.THOST_FTDC_OER_NoInstrument = '6';
jtp.constant.THOST_FTDC_OER_NoRight = '7';
jtp.constant.THOST_FTDC_OER_InvalidVolume = '8';
jtp.constant.THOST_FTDC_OER_NoEnoughHistoryTrade = '9';
jtp.constant.THOST_FTDC_OER_Unknown = 'a';
jtp.constant.THOST_FTDC_COMBT_Future = '0';
jtp.constant.THOST_FTDC_COMBT_BUL = '1';
jtp.constant.THOST_FTDC_COMBT_BER = '2';
jtp.constant.THOST_FTDC_COMBT_STD = '3';
jtp.constant.THOST_FTDC_COMBT_STG = '4';
jtp.constant.THOST_FTDC_COMBT_PRT = '5';
jtp.constant.THOST_FTDC_COMBT_CAS = '6';
jtp.constant.THOST_FTDC_COMBT_OPL = '7';
jtp.constant.THOST_FTDC_COMBT_BFO = '8';
jtp.constant.THOST_FTDC_COMBT_BLS = '9';
jtp.constant.THOST_FTDC_COMBT_BES = 'a';
jtp.constant.THOST_FTDC_DCECOMBT_SPL = '0';
jtp.constant.THOST_FTDC_DCECOMBT_OPL = '1';
jtp.constant.THOST_FTDC_DCECOMBT_SP = '2';
jtp.constant.THOST_FTDC_DCECOMBT_SPC = '3';
jtp.constant.THOST_FTDC_DCECOMBT_BLS = '4';
jtp.constant.THOST_FTDC_DCECOMBT_BES = '5';
jtp.constant.THOST_FTDC_DCECOMBT_CAS = '6';
jtp.constant.THOST_FTDC_DCECOMBT_STD = '7';
jtp.constant.THOST_FTDC_DCECOMBT_STG = '8';
jtp.constant.THOST_FTDC_DCECOMBT_BFO = '9';
jtp.constant.THOST_FTDC_DCECOMBT_SFO = 'a';
jtp.constant.THOST_FTDC_ORPT_PreSettlementPrice = '1';
jtp.constant.THOST_FTDC_ORPT_OpenPrice = '4';
jtp.constant.THOST_FTDC_ORPT_MaxPreSettlementPrice = '5';
jtp.constant.THOST_FTDC_BLAG_Default = '1';
jtp.constant.THOST_FTDC_BLAG_IncludeOptValLost = '2';
jtp.constant.THOST_FTDC_ACTP_Exec = '1';
jtp.constant.THOST_FTDC_ACTP_Abandon = '2';
jtp.constant.THOST_FTDC_FQST_Submitted = 'a';
jtp.constant.THOST_FTDC_FQST_Accepted = 'b';
jtp.constant.THOST_FTDC_FQST_Rejected = 'c';
jtp.constant.THOST_FTDC_VM_Absolute = '0';
jtp.constant.THOST_FTDC_VM_Ratio = '1';
jtp.constant.THOST_FTDC_EOPF_Reserve = '0';
jtp.constant.THOST_FTDC_EOPF_UnReserve = '1';
jtp.constant.THOST_FTDC_EOCF_AutoClose = '0';
jtp.constant.THOST_FTDC_EOCF_NotToClose = '1';
jtp.constant.THOST_FTDC_PTE_Futures = '1';
jtp.constant.THOST_FTDC_PTE_Options = '2';
jtp.constant.THOST_FTDC_CUFN_CUFN_O = 'O';
jtp.constant.THOST_FTDC_CUFN_CUFN_T = 'T';
jtp.constant.THOST_FTDC_CUFN_CUFN_P = 'P';
jtp.constant.THOST_FTDC_CUFN_CUFN_N = 'N';
jtp.constant.THOST_FTDC_CUFN_CUFN_L = 'L';
jtp.constant.THOST_FTDC_CUFN_CUFN_F = 'F';
jtp.constant.THOST_FTDC_CUFN_CUFN_C = 'C';
jtp.constant.THOST_FTDC_CUFN_CUFN_M = 'M';
jtp.constant.THOST_FTDC_DUFN_DUFN_O = 'O';
jtp.constant.THOST_FTDC_DUFN_DUFN_T = 'T';
jtp.constant.THOST_FTDC_DUFN_DUFN_P = 'P';
jtp.constant.THOST_FTDC_DUFN_DUFN_F = 'F';
jtp.constant.THOST_FTDC_DUFN_DUFN_C = 'C';
jtp.constant.THOST_FTDC_DUFN_DUFN_D = 'D';
jtp.constant.THOST_FTDC_DUFN_DUFN_M = 'M';
jtp.constant.THOST_FTDC_DUFN_DUFN_S = 'S';
jtp.constant.THOST_FTDC_SUFN_SUFN_O = 'O';
jtp.constant.THOST_FTDC_SUFN_SUFN_T = 'T';
jtp.constant.THOST_FTDC_SUFN_SUFN_P = 'P';
jtp.constant.THOST_FTDC_SUFN_SUFN_F = 'F';
jtp.constant.THOST_FTDC_CFUFN_SUFN_T = 'T';
jtp.constant.THOST_FTDC_CFUFN_SUFN_P = 'P';
jtp.constant.THOST_FTDC_CFUFN_SUFN_F = 'F';
jtp.constant.THOST_FTDC_CFUFN_SUFN_S = 'S';
jtp.constant.THOST_FTDC_CMDR_Comb = '0';
jtp.constant.THOST_FTDC_CMDR_UnComb = '1';
jtp.constant.THOST_FTDC_CMDR_DelComb = '2';
jtp.constant.THOST_FTDC_STOV_RealValue = '1';
jtp.constant.THOST_FTDC_STOV_ProfitValue = '2';
jtp.constant.THOST_FTDC_STOV_RealRatio = '3';
jtp.constant.THOST_FTDC_STOV_ProfitRatio = '4';
jtp.constant.THOST_FTDC_ROAST_Processing = '0';
jtp.constant.THOST_FTDC_ROAST_Cancelled = '1';
jtp.constant.THOST_FTDC_ROAST_Opened = '2';
jtp.constant.THOST_FTDC_ROAST_Invalid = '3';
jtp.constant.THOST_FTDC_WPSR_Lib = '1';
jtp.constant.THOST_FTDC_WPSR_Manual = '2';
jtp.constant.THOST_FTDC_OSCF_CloseSelfOptionPosition = '1';
jtp.constant.THOST_FTDC_OSCF_ReserveOptionPosition = '2';
jtp.constant.THOST_FTDC_OSCF_SellCloseSelfFuturePosition = '3';
jtp.constant.THOST_FTDC_OSCF_ReserveFuturePosition = '4';
jtp.constant.THOST_FTDC_BZTP_Future = '1';
jtp.constant.THOST_FTDC_BZTP_Stock = '2';
jtp.constant.THOST_FTDC_APP_TYPE_Investor = '1';
jtp.constant.THOST_FTDC_APP_TYPE_InvestorRelay = '2';
jtp.constant.THOST_FTDC_APP_TYPE_OperatorRelay = '3';
jtp.constant.THOST_FTDC_APP_TYPE_UnKnown = '4';
jtp.constant.THOST_FTDC_RV_Right = '0';
jtp.constant.THOST_FTDC_RV_Refuse = '1';
jtp.constant.THOST_FTDC_OTC_TRDT_Block = '0';
jtp.constant.THOST_FTDC_OTC_TRDT_EFP = '1';
jtp.constant.THOST_FTDC_OTC_MT_DV01 = '1';
jtp.constant.THOST_FTDC_OTC_MT_ParValue = '2';
jtp.constant.THOST_FTDC_AU_WHITE = '0';
jtp.constant.THOST_FTDC_AU_BLACK = '1';
jtp.constant.THOST_FTDC_INS_ALL = '0';
jtp.constant.THOST_FTDC_INS_FUTURE = '1';
jtp.constant.THOST_FTDC_INS_OPTION = '2';
jtp.constant.THOST_FTDC_INS_COMB = '3';
jtp.constant.THOST_FTDC_TD_ALL = '0';
jtp.constant.THOST_FTDC_TD_TRADE = '1';
jtp.constant.THOST_FTDC_TD_UNTRADE = '2';
jtp.constant.THOST_FTDC_PS_tradeable = '1';
jtp.constant.THOST_FTDC_PS_untradeable = '2';
jtp.constant.THOST_FTDC_SDS_Readable = '1';
jtp.constant.THOST_FTDC_SDS_Reading = '2';
jtp.constant.THOST_FTDC_SDS_Readend = '3';
jtp.constant.THOST_FTDC_SDS_OptErr = 'e';
jtp.constant.THOST_FTDC_ACD_Add = '1';
jtp.constant.THOST_FTDC_ACD_Del = '2';
jtp.constant.THOST_FTDC_ACD_Upd = '3';


class CThostFtdcDisseminationField{
    SequenceSeries = 0;
    SequenceNo = 0;
}
jtp.CThostFtdcDisseminationField=CThostFtdcDisseminationField;

class CThostFtdcReqUserLoginField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
    Password = '';
    UserProductInfo = '';
    InterfaceProductInfo = '';
    ProtocolInfo = '';
    MacAddress = '';
    OneTimePassword = '';
    reserve1 = '';
    LoginRemark = '';
    ClientIPPort = 0;
    ClientIPAddress = '';
}
jtp.CThostFtdcReqUserLoginField=CThostFtdcReqUserLoginField;

class CThostFtdcRspUserLoginField{
    TradingDay = '';
    LoginTime = '';
    BrokerID = '';
    UserID = '';
    SystemName = '';
    FrontID = 0;
    SessionID = 0;
    MaxOrderRef = '';
    SHFETime = '';
    DCETime = '';
    CZCETime = '';
    FFEXTime = '';
    INETime = '';
}
jtp.CThostFtdcRspUserLoginField=CThostFtdcRspUserLoginField;

class CThostFtdcUserLogoutField{
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcUserLogoutField=CThostFtdcUserLogoutField;

class CThostFtdcForceUserLogoutField{
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcForceUserLogoutField=CThostFtdcForceUserLogoutField;

class CThostFtdcReqAuthenticateField{
    BrokerID = '';
    UserID = '';
    UserProductInfo = '';
    AuthCode = '';
    AppID = '';
}
jtp.CThostFtdcReqAuthenticateField=CThostFtdcReqAuthenticateField;

class CThostFtdcRspAuthenticateField{
    BrokerID = '';
    UserID = '';
    UserProductInfo = '';
    AppID = '';
    AppType = '';
}
jtp.CThostFtdcRspAuthenticateField=CThostFtdcRspAuthenticateField;

class CThostFtdcAuthenticationInfoField{
    BrokerID = '';
    UserID = '';
    UserProductInfo = '';
    AuthInfo = '';
    IsResult = 0;
    AppID = '';
    AppType = '';
    reserve1 = '';
    ClientIPAddress = '';
}
jtp.CThostFtdcAuthenticationInfoField=CThostFtdcAuthenticationInfoField;

class CThostFtdcRspUserLogin2Field{
    TradingDay = '';
    LoginTime = '';
    BrokerID = '';
    UserID = '';
    SystemName = '';
    FrontID = 0;
    SessionID = 0;
    MaxOrderRef = '';
    SHFETime = '';
    DCETime = '';
    CZCETime = '';
    FFEXTime = '';
    INETime = '';
    RandomString = '';
}
jtp.CThostFtdcRspUserLogin2Field=CThostFtdcRspUserLogin2Field;

class CThostFtdcTransferHeaderField{
    Version = '';
    TradeCode = '';
    TradeDate = '';
    TradeTime = '';
    TradeSerial = '';
    FutureID = '';
    BankID = '';
    BankBrchID = '';
    OperNo = '';
    DeviceID = '';
    RecordNum = '';
    SessionID = 0;
    RequestID = 0;
}
jtp.CThostFtdcTransferHeaderField=CThostFtdcTransferHeaderField;

class CThostFtdcTransferBankToFutureReqField{
    FutureAccount = '';
    FuturePwdFlag = '';
    FutureAccPwd = '';
    TradeAmt = 0.0;
    CustFee = 0.0;
    CurrencyCode = '';
}
jtp.CThostFtdcTransferBankToFutureReqField=CThostFtdcTransferBankToFutureReqField;

class CThostFtdcTransferBankToFutureRspField{
    RetCode = '';
    RetInfo = '';
    FutureAccount = '';
    TradeAmt = 0.0;
    CustFee = 0.0;
    CurrencyCode = '';
}
jtp.CThostFtdcTransferBankToFutureRspField=CThostFtdcTransferBankToFutureRspField;

class CThostFtdcTransferFutureToBankReqField{
    FutureAccount = '';
    FuturePwdFlag = '';
    FutureAccPwd = '';
    TradeAmt = 0.0;
    CustFee = 0.0;
    CurrencyCode = '';
}
jtp.CThostFtdcTransferFutureToBankReqField=CThostFtdcTransferFutureToBankReqField;

class CThostFtdcTransferFutureToBankRspField{
    RetCode = '';
    RetInfo = '';
    FutureAccount = '';
    TradeAmt = 0.0;
    CustFee = 0.0;
    CurrencyCode = '';
}
jtp.CThostFtdcTransferFutureToBankRspField=CThostFtdcTransferFutureToBankRspField;

class CThostFtdcTransferQryBankReqField{
    FutureAccount = '';
    FuturePwdFlag = '';
    FutureAccPwd = '';
    CurrencyCode = '';
}
jtp.CThostFtdcTransferQryBankReqField=CThostFtdcTransferQryBankReqField;

class CThostFtdcTransferQryBankRspField{
    RetCode = '';
    RetInfo = '';
    FutureAccount = '';
    TradeAmt = 0.0;
    UseAmt = 0.0;
    FetchAmt = 0.0;
    CurrencyCode = '';
}
jtp.CThostFtdcTransferQryBankRspField=CThostFtdcTransferQryBankRspField;

class CThostFtdcTransferQryDetailReqField{
    FutureAccount = '';
}
jtp.CThostFtdcTransferQryDetailReqField=CThostFtdcTransferQryDetailReqField;

class CThostFtdcTransferQryDetailRspField{
    TradeDate = '';
    TradeTime = '';
    TradeCode = '';
    FutureSerial = 0;
    FutureID = '';
    FutureAccount = '';
    BankSerial = 0;
    BankID = '';
    BankBrchID = '';
    BankAccount = '';
    CertCode = '';
    CurrencyCode = '';
    TxAmount = 0.0;
    Flag = '';
}
jtp.CThostFtdcTransferQryDetailRspField=CThostFtdcTransferQryDetailRspField;

class CThostFtdcRspInfoField{
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcRspInfoField=CThostFtdcRspInfoField;

class CThostFtdcExchangeField{
    ExchangeID = '';
    ExchangeName = '';
    ExchangeProperty = '';
}
jtp.CThostFtdcExchangeField=CThostFtdcExchangeField;

class CThostFtdcProductField{
    reserve1 = '';
    ProductName = '';
    ExchangeID = '';
    ProductClass = '';
    VolumeMultiple = 0;
    PriceTick = 0.0;
    MaxMarketOrderVolume = 0;
    MinMarketOrderVolume = 0;
    MaxLimitOrderVolume = 0;
    MinLimitOrderVolume = 0;
    PositionType = '';
    PositionDateType = '';
    CloseDealType = '';
    TradeCurrencyID = '';
    MortgageFundUseRange = '';
    reserve2 = '';
    UnderlyingMultiple = 0.0;
    ProductID = '';
    ExchangeProductID = '';
}
jtp.CThostFtdcProductField=CThostFtdcProductField;

class CThostFtdcInstrumentField{
    reserve1 = '';
    ExchangeID = '';
    InstrumentName = '';
    reserve2 = '';
    reserve3 = '';
    ProductClass = '';
    DeliveryYear = 0;
    DeliveryMonth = 0;
    MaxMarketOrderVolume = 0;
    MinMarketOrderVolume = 0;
    MaxLimitOrderVolume = 0;
    MinLimitOrderVolume = 0;
    VolumeMultiple = 0;
    PriceTick = 0.0;
    CreateDate = '';
    OpenDate = '';
    ExpireDate = '';
    StartDelivDate = '';
    EndDelivDate = '';
    InstLifePhase = '';
    IsTrading = 0;
    PositionType = '';
    PositionDateType = '';
    LongMarginRatio = 0.0;
    ShortMarginRatio = 0.0;
    MaxMarginSideAlgorithm = '';
    reserve4 = '';
    StrikePrice = 0.0;
    OptionsType = '';
    UnderlyingMultiple = 0.0;
    CombinationType = '';
    InstrumentID = '';
    ExchangeInstID = '';
    ProductID = '';
    UnderlyingInstrID = '';
}
jtp.CThostFtdcInstrumentField=CThostFtdcInstrumentField;

class CThostFtdcBrokerField{
    BrokerID = '';
    BrokerAbbr = '';
    BrokerName = '';
    IsActive = 0;
}
jtp.CThostFtdcBrokerField=CThostFtdcBrokerField;

class CThostFtdcTraderField{
    ExchangeID = '';
    TraderID = '';
    ParticipantID = '';
    Password = '';
    InstallCount = 0;
    BrokerID = '';
}
jtp.CThostFtdcTraderField=CThostFtdcTraderField;

class CThostFtdcInvestorField{
    InvestorID = '';
    BrokerID = '';
    InvestorGroupID = '';
    InvestorName = '';
    IdentifiedCardType = '';
    IdentifiedCardNo = '';
    IsActive = 0;
    Telephone = '';
    Address = '';
    OpenDate = '';
    Mobile = '';
    CommModelID = '';
    MarginModelID = '';
}
jtp.CThostFtdcInvestorField=CThostFtdcInvestorField;

class CThostFtdcTradingCodeField{
    InvestorID = '';
    BrokerID = '';
    ExchangeID = '';
    ClientID = '';
    IsActive = 0;
    ClientIDType = '';
    BranchID = '';
    BizType = '';
    InvestUnitID = '';
}
jtp.CThostFtdcTradingCodeField=CThostFtdcTradingCodeField;

class CThostFtdcPartBrokerField{
    BrokerID = '';
    ExchangeID = '';
    ParticipantID = '';
    IsActive = 0;
}
jtp.CThostFtdcPartBrokerField=CThostFtdcPartBrokerField;

class CThostFtdcSuperUserField{
    UserID = '';
    UserName = '';
    Password = '';
    IsActive = 0;
}
jtp.CThostFtdcSuperUserField=CThostFtdcSuperUserField;

class CThostFtdcSuperUserFunctionField{
    UserID = '';
    FunctionCode = '';
}
jtp.CThostFtdcSuperUserFunctionField=CThostFtdcSuperUserFunctionField;

class CThostFtdcInvestorGroupField{
    BrokerID = '';
    InvestorGroupID = '';
    InvestorGroupName = '';
}
jtp.CThostFtdcInvestorGroupField=CThostFtdcInvestorGroupField;

class CThostFtdcTradingAccountField{
    BrokerID = '';
    AccountID = '';
    PreMortgage = 0.0;
    PreCredit = 0.0;
    PreDeposit = 0.0;
    PreBalance = 0.0;
    PreMargin = 0.0;
    InterestBase = 0.0;
    Interest = 0.0;
    Deposit = 0.0;
    Withdraw = 0.0;
    FrozenMargin = 0.0;
    FrozenCash = 0.0;
    FrozenCommission = 0.0;
    CurrMargin = 0.0;
    CashIn = 0.0;
    Commission = 0.0;
    CloseProfit = 0.0;
    PositionProfit = 0.0;
    Balance = 0.0;
    Available = 0.0;
    WithdrawQuota = 0.0;
    Reserve = 0.0;
    TradingDay = '';
    SettlementID = 0;
    Credit = 0.0;
    Mortgage = 0.0;
    ExchangeMargin = 0.0;
    DeliveryMargin = 0.0;
    ExchangeDeliveryMargin = 0.0;
    ReserveBalance = 0.0;
    CurrencyID = '';
    PreFundMortgageIn = 0.0;
    PreFundMortgageOut = 0.0;
    FundMortgageIn = 0.0;
    FundMortgageOut = 0.0;
    FundMortgageAvailable = 0.0;
    MortgageableFund = 0.0;
    SpecProductMargin = 0.0;
    SpecProductFrozenMargin = 0.0;
    SpecProductCommission = 0.0;
    SpecProductFrozenCommission = 0.0;
    SpecProductPositionProfit = 0.0;
    SpecProductCloseProfit = 0.0;
    SpecProductPositionProfitByAlg = 0.0;
    SpecProductExchangeMargin = 0.0;
    BizType = '';
    FrozenSwap = 0.0;
    RemainSwap = 0.0;
}
jtp.CThostFtdcTradingAccountField=CThostFtdcTradingAccountField;

class CThostFtdcInvestorPositionField{
    reserve1 = '';
    BrokerID = '';
    InvestorID = '';
    PosiDirection = '';
    HedgeFlag = '';
    PositionDate = '';
    YdPosition = 0;
    Position = 0;
    LongFrozen = 0;
    ShortFrozen = 0;
    LongFrozenAmount = 0.0;
    ShortFrozenAmount = 0.0;
    OpenVolume = 0;
    CloseVolume = 0;
    OpenAmount = 0.0;
    CloseAmount = 0.0;
    PositionCost = 0.0;
    PreMargin = 0.0;
    UseMargin = 0.0;
    FrozenMargin = 0.0;
    FrozenCash = 0.0;
    FrozenCommission = 0.0;
    CashIn = 0.0;
    Commission = 0.0;
    CloseProfit = 0.0;
    PositionProfit = 0.0;
    PreSettlementPrice = 0.0;
    SettlementPrice = 0.0;
    TradingDay = '';
    SettlementID = 0;
    OpenCost = 0.0;
    ExchangeMargin = 0.0;
    CombPosition = 0;
    CombLongFrozen = 0;
    CombShortFrozen = 0;
    CloseProfitByDate = 0.0;
    CloseProfitByTrade = 0.0;
    TodayPosition = 0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    StrikeFrozen = 0;
    StrikeFrozenAmount = 0.0;
    AbandonFrozen = 0;
    ExchangeID = '';
    YdStrikeFrozen = 0;
    InvestUnitID = '';
    PositionCostOffset = 0.0;
    TasPosition = 0;
    TasPositionCost = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcInvestorPositionField=CThostFtdcInvestorPositionField;

class CThostFtdcInstrumentMarginRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    IsRelative = 0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcInstrumentMarginRateField=CThostFtdcInstrumentMarginRateField;

class CThostFtdcInstrumentCommissionRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    ExchangeID = '';
    BizType = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcInstrumentCommissionRateField=CThostFtdcInstrumentCommissionRateField;

class CThostFtdcDepthMarketDataField{
    TradingDay = '';
    reserve1 = '';
    ExchangeID = '';
    reserve2 = '';
    LastPrice = 0.0;
    PreSettlementPrice = 0.0;
    PreClosePrice = 0.0;
    PreOpenInterest = 0.0;
    OpenPrice = 0.0;
    HighestPrice = 0.0;
    LowestPrice = 0.0;
    Volume = 0;
    Turnover = 0.0;
    OpenInterest = 0.0;
    ClosePrice = 0.0;
    SettlementPrice = 0.0;
    UpperLimitPrice = 0.0;
    LowerLimitPrice = 0.0;
    PreDelta = 0.0;
    CurrDelta = 0.0;
    UpdateTime = '';
    UpdateMillisec = 0;
    BidPrice1 = 0.0;
    BidVolume1 = 0;
    AskPrice1 = 0.0;
    AskVolume1 = 0;
    BidPrice2 = 0.0;
    BidVolume2 = 0;
    AskPrice2 = 0.0;
    AskVolume2 = 0;
    BidPrice3 = 0.0;
    BidVolume3 = 0;
    AskPrice3 = 0.0;
    AskVolume3 = 0;
    BidPrice4 = 0.0;
    BidVolume4 = 0;
    AskPrice4 = 0.0;
    AskVolume4 = 0;
    BidPrice5 = 0.0;
    BidVolume5 = 0;
    AskPrice5 = 0.0;
    AskVolume5 = 0;
    AveragePrice = 0.0;
    ActionDay = '';
    InstrumentID = '';
    ExchangeInstID = '';
    BandingUpperPrice = 0.0;
    BandingLowerPrice = 0.0;
}
jtp.CThostFtdcDepthMarketDataField=CThostFtdcDepthMarketDataField;

class CThostFtdcInstrumentTradingRightField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    TradingRight = '';
    InstrumentID = '';
}
jtp.CThostFtdcInstrumentTradingRightField=CThostFtdcInstrumentTradingRightField;

class CThostFtdcBrokerUserField{
    BrokerID = '';
    UserID = '';
    UserName = '';
    UserType = '';
    IsActive = 0;
    IsUsingOTP = 0;
    IsAuthForce = 0;
}
jtp.CThostFtdcBrokerUserField=CThostFtdcBrokerUserField;

class CThostFtdcBrokerUserPasswordField{
    BrokerID = '';
    UserID = '';
    Password = '';
    LastUpdateTime = '';
    LastLoginTime = '';
    ExpireDate = '';
    WeakExpireDate = '';
}
jtp.CThostFtdcBrokerUserPasswordField=CThostFtdcBrokerUserPasswordField;

class CThostFtdcBrokerUserFunctionField{
    BrokerID = '';
    UserID = '';
    BrokerFunctionCode = '';
}
jtp.CThostFtdcBrokerUserFunctionField=CThostFtdcBrokerUserFunctionField;

class CThostFtdcTraderOfferField{
    ExchangeID = '';
    TraderID = '';
    ParticipantID = '';
    Password = '';
    InstallID = 0;
    OrderLocalID = '';
    TraderConnectStatus = '';
    ConnectRequestDate = '';
    ConnectRequestTime = '';
    LastReportDate = '';
    LastReportTime = '';
    ConnectDate = '';
    ConnectTime = '';
    StartDate = '';
    StartTime = '';
    TradingDay = '';
    BrokerID = '';
    MaxTradeID = '';
    MaxOrderMessageReference = '';
}
jtp.CThostFtdcTraderOfferField=CThostFtdcTraderOfferField;

class CThostFtdcSettlementInfoField{
    TradingDay = '';
    SettlementID = 0;
    BrokerID = '';
    InvestorID = '';
    SequenceNo = 0;
    Content = '';
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcSettlementInfoField=CThostFtdcSettlementInfoField;

class CThostFtdcInstrumentMarginRateAdjustField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    IsRelative = 0;
    InstrumentID = '';
}
jtp.CThostFtdcInstrumentMarginRateAdjustField=CThostFtdcInstrumentMarginRateAdjustField;

class CThostFtdcExchangeMarginRateField{
    BrokerID = '';
    reserve1 = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcExchangeMarginRateField=CThostFtdcExchangeMarginRateField;

class CThostFtdcExchangeMarginRateAdjustField{
    BrokerID = '';
    reserve1 = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    ExchLongMarginRatioByMoney = 0.0;
    ExchLongMarginRatioByVolume = 0.0;
    ExchShortMarginRatioByMoney = 0.0;
    ExchShortMarginRatioByVolume = 0.0;
    NoLongMarginRatioByMoney = 0.0;
    NoLongMarginRatioByVolume = 0.0;
    NoShortMarginRatioByMoney = 0.0;
    NoShortMarginRatioByVolume = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcExchangeMarginRateAdjustField=CThostFtdcExchangeMarginRateAdjustField;

class CThostFtdcExchangeRateField{
    BrokerID = '';
    FromCurrencyID = '';
    FromCurrencyUnit = 0.0;
    ToCurrencyID = '';
    ExchangeRate = 0.0;
}
jtp.CThostFtdcExchangeRateField=CThostFtdcExchangeRateField;

class CThostFtdcSettlementRefField{
    TradingDay = '';
    SettlementID = 0;
}
jtp.CThostFtdcSettlementRefField=CThostFtdcSettlementRefField;

class CThostFtdcCurrentTimeField{
    CurrDate = '';
    CurrTime = '';
    CurrMillisec = 0;
    ActionDay = '';
}
jtp.CThostFtdcCurrentTimeField=CThostFtdcCurrentTimeField;

class CThostFtdcCommPhaseField{
    TradingDay = '';
    CommPhaseNo = 0;
    SystemID = '';
}
jtp.CThostFtdcCommPhaseField=CThostFtdcCommPhaseField;

class CThostFtdcLoginInfoField{
    FrontID = 0;
    SessionID = 0;
    BrokerID = '';
    UserID = '';
    LoginDate = '';
    LoginTime = '';
    reserve1 = '';
    UserProductInfo = '';
    InterfaceProductInfo = '';
    ProtocolInfo = '';
    SystemName = '';
    PasswordDeprecated = '';
    MaxOrderRef = '';
    SHFETime = '';
    DCETime = '';
    CZCETime = '';
    FFEXTime = '';
    MacAddress = '';
    OneTimePassword = '';
    INETime = '';
    IsQryControl = 0;
    LoginRemark = '';
    Password = '';
    IPAddress = '';
}
jtp.CThostFtdcLoginInfoField=CThostFtdcLoginInfoField;

class CThostFtdcLogoutAllField{
    FrontID = 0;
    SessionID = 0;
    SystemName = '';
}
jtp.CThostFtdcLogoutAllField=CThostFtdcLogoutAllField;

class CThostFtdcFrontStatusField{
    FrontID = 0;
    LastReportDate = '';
    LastReportTime = '';
    IsActive = 0;
}
jtp.CThostFtdcFrontStatusField=CThostFtdcFrontStatusField;

class CThostFtdcUserPasswordUpdateField{
    BrokerID = '';
    UserID = '';
    OldPassword = '';
    NewPassword = '';
}
jtp.CThostFtdcUserPasswordUpdateField=CThostFtdcUserPasswordUpdateField;

class CThostFtdcInputOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OrderRef = '';
    UserID = '';
    OrderPriceType = '';
    Direction = '';
    CombOffsetFlag = '';
    CombHedgeFlag = '';
    LimitPrice = 0.0;
    VolumeTotalOriginal = 0;
    TimeCondition = '';
    GTDDate = '';
    VolumeCondition = '';
    MinVolume = 0;
    ContingentCondition = '';
    StopPrice = 0.0;
    ForceCloseReason = '';
    IsAutoSuspend = 0;
    BusinessUnit = '';
    RequestID = 0;
    UserForceClose = 0;
    IsSwapOrder = 0;
    ExchangeID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputOrderField=CThostFtdcInputOrderField;

class CThostFtdcOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OrderRef = '';
    UserID = '';
    OrderPriceType = '';
    Direction = '';
    CombOffsetFlag = '';
    CombHedgeFlag = '';
    LimitPrice = 0.0;
    VolumeTotalOriginal = 0;
    TimeCondition = '';
    GTDDate = '';
    VolumeCondition = '';
    MinVolume = 0;
    ContingentCondition = '';
    StopPrice = 0.0;
    ForceCloseReason = '';
    IsAutoSuspend = 0;
    BusinessUnit = '';
    RequestID = 0;
    OrderLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    OrderSysID = '';
    OrderSource = '';
    OrderStatus = '';
    OrderType = '';
    VolumeTraded = 0;
    VolumeTotal = 0;
    InsertDate = '';
    InsertTime = '';
    ActiveTime = '';
    SuspendTime = '';
    UpdateTime = '';
    CancelTime = '';
    ActiveTraderID = '';
    ClearingPartID = '';
    SequenceNo = 0;
    FrontID = 0;
    SessionID = 0;
    UserProductInfo = '';
    StatusMsg = '';
    UserForceClose = 0;
    ActiveUserID = '';
    BrokerOrderSeq = 0;
    RelativeOrderSysID = '';
    ZCETotalTradedVolume = 0;
    IsSwapOrder = 0;
    BranchID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    reserve3 = '';
    MacAddress = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcOrderField=CThostFtdcOrderField;

class CThostFtdcExchangeOrderField{
    OrderPriceType = '';
    Direction = '';
    CombOffsetFlag = '';
    CombHedgeFlag = '';
    LimitPrice = 0.0;
    VolumeTotalOriginal = 0;
    TimeCondition = '';
    GTDDate = '';
    VolumeCondition = '';
    MinVolume = 0;
    ContingentCondition = '';
    StopPrice = 0.0;
    ForceCloseReason = '';
    IsAutoSuspend = 0;
    BusinessUnit = '';
    RequestID = 0;
    OrderLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    OrderSysID = '';
    OrderSource = '';
    OrderStatus = '';
    OrderType = '';
    VolumeTraded = 0;
    VolumeTotal = 0;
    InsertDate = '';
    InsertTime = '';
    ActiveTime = '';
    SuspendTime = '';
    UpdateTime = '';
    CancelTime = '';
    ActiveTraderID = '';
    ClearingPartID = '';
    SequenceNo = 0;
    BranchID = '';
    reserve2 = '';
    MacAddress = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeOrderField=CThostFtdcExchangeOrderField;

class CThostFtdcExchangeOrderInsertErrorField{
    ExchangeID = '';
    ParticipantID = '';
    TraderID = '';
    InstallID = 0;
    OrderLocalID = '';
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcExchangeOrderInsertErrorField=CThostFtdcExchangeOrderInsertErrorField;

class CThostFtdcInputOrderActionField{
    BrokerID = '';
    InvestorID = '';
    OrderActionRef = 0;
    OrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    OrderSysID = '';
    ActionFlag = '';
    LimitPrice = 0.0;
    VolumeChange = 0;
    UserID = '';
    reserve1 = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputOrderActionField=CThostFtdcInputOrderActionField;

class CThostFtdcOrderActionField{
    BrokerID = '';
    InvestorID = '';
    OrderActionRef = 0;
    OrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    OrderSysID = '';
    ActionFlag = '';
    LimitPrice = 0.0;
    VolumeChange = 0;
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    OrderLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    StatusMsg = '';
    reserve1 = '';
    BranchID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcOrderActionField=CThostFtdcOrderActionField;

class CThostFtdcExchangeOrderActionField{
    ExchangeID = '';
    OrderSysID = '';
    ActionFlag = '';
    LimitPrice = 0.0;
    VolumeChange = 0;
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    OrderLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    BranchID = '';
    reserve1 = '';
    MacAddress = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeOrderActionField=CThostFtdcExchangeOrderActionField;

class CThostFtdcExchangeOrderActionErrorField{
    ExchangeID = '';
    OrderSysID = '';
    TraderID = '';
    InstallID = 0;
    OrderLocalID = '';
    ActionLocalID = '';
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcExchangeOrderActionErrorField=CThostFtdcExchangeOrderActionErrorField;

class CThostFtdcExchangeTradeField{
    ExchangeID = '';
    TradeID = '';
    Direction = '';
    OrderSysID = '';
    ParticipantID = '';
    ClientID = '';
    TradingRole = '';
    reserve1 = '';
    OffsetFlag = '';
    HedgeFlag = '';
    Price = 0.0;
    Volume = 0;
    TradeDate = '';
    TradeTime = '';
    TradeType = '';
    PriceSource = '';
    TraderID = '';
    OrderLocalID = '';
    ClearingPartID = '';
    BusinessUnit = '';
    SequenceNo = 0;
    TradeSource = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcExchangeTradeField=CThostFtdcExchangeTradeField;

class CThostFtdcTradeField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OrderRef = '';
    UserID = '';
    ExchangeID = '';
    TradeID = '';
    Direction = '';
    OrderSysID = '';
    ParticipantID = '';
    ClientID = '';
    TradingRole = '';
    reserve2 = '';
    OffsetFlag = '';
    HedgeFlag = '';
    Price = 0.0;
    Volume = 0;
    TradeDate = '';
    TradeTime = '';
    TradeType = '';
    PriceSource = '';
    TraderID = '';
    OrderLocalID = '';
    ClearingPartID = '';
    BusinessUnit = '';
    SequenceNo = 0;
    TradingDay = '';
    SettlementID = 0;
    BrokerOrderSeq = 0;
    TradeSource = '';
    InvestUnitID = '';
    InstrumentID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcTradeField=CThostFtdcTradeField;

class CThostFtdcUserSessionField{
    FrontID = 0;
    SessionID = 0;
    BrokerID = '';
    UserID = '';
    LoginDate = '';
    LoginTime = '';
    reserve1 = '';
    UserProductInfo = '';
    InterfaceProductInfo = '';
    ProtocolInfo = '';
    MacAddress = '';
    LoginRemark = '';
    IPAddress = '';
}
jtp.CThostFtdcUserSessionField=CThostFtdcUserSessionField;

class CThostFtdcQryMaxOrderVolumeField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    Direction = '';
    OffsetFlag = '';
    HedgeFlag = '';
    MaxVolume = 0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryMaxOrderVolumeField=CThostFtdcQryMaxOrderVolumeField;

class CThostFtdcSettlementInfoConfirmField{
    BrokerID = '';
    InvestorID = '';
    ConfirmDate = '';
    ConfirmTime = '';
    SettlementID = 0;
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcSettlementInfoConfirmField=CThostFtdcSettlementInfoConfirmField;

class CThostFtdcSyncDepositField{
    DepositSeqNo = '';
    BrokerID = '';
    InvestorID = '';
    Deposit = 0.0;
    IsForce = 0;
    CurrencyID = '';
    IsFromSopt = 0;
    TradingPassword = '';
}
jtp.CThostFtdcSyncDepositField=CThostFtdcSyncDepositField;

class CThostFtdcSyncFundMortgageField{
    MortgageSeqNo = '';
    BrokerID = '';
    InvestorID = '';
    FromCurrencyID = '';
    MortgageAmount = 0.0;
    ToCurrencyID = '';
}
jtp.CThostFtdcSyncFundMortgageField=CThostFtdcSyncFundMortgageField;

class CThostFtdcBrokerSyncField{
    BrokerID = '';
}
jtp.CThostFtdcBrokerSyncField=CThostFtdcBrokerSyncField;

class CThostFtdcSyncingInvestorField{
    InvestorID = '';
    BrokerID = '';
    InvestorGroupID = '';
    InvestorName = '';
    IdentifiedCardType = '';
    IdentifiedCardNo = '';
    IsActive = 0;
    Telephone = '';
    Address = '';
    OpenDate = '';
    Mobile = '';
    CommModelID = '';
    MarginModelID = '';
}
jtp.CThostFtdcSyncingInvestorField=CThostFtdcSyncingInvestorField;

class CThostFtdcSyncingTradingCodeField{
    InvestorID = '';
    BrokerID = '';
    ExchangeID = '';
    ClientID = '';
    IsActive = 0;
    ClientIDType = '';
}
jtp.CThostFtdcSyncingTradingCodeField=CThostFtdcSyncingTradingCodeField;

class CThostFtdcSyncingInvestorGroupField{
    BrokerID = '';
    InvestorGroupID = '';
    InvestorGroupName = '';
}
jtp.CThostFtdcSyncingInvestorGroupField=CThostFtdcSyncingInvestorGroupField;

class CThostFtdcSyncingTradingAccountField{
    BrokerID = '';
    AccountID = '';
    PreMortgage = 0.0;
    PreCredit = 0.0;
    PreDeposit = 0.0;
    PreBalance = 0.0;
    PreMargin = 0.0;
    InterestBase = 0.0;
    Interest = 0.0;
    Deposit = 0.0;
    Withdraw = 0.0;
    FrozenMargin = 0.0;
    FrozenCash = 0.0;
    FrozenCommission = 0.0;
    CurrMargin = 0.0;
    CashIn = 0.0;
    Commission = 0.0;
    CloseProfit = 0.0;
    PositionProfit = 0.0;
    Balance = 0.0;
    Available = 0.0;
    WithdrawQuota = 0.0;
    Reserve = 0.0;
    TradingDay = '';
    SettlementID = 0;
    Credit = 0.0;
    Mortgage = 0.0;
    ExchangeMargin = 0.0;
    DeliveryMargin = 0.0;
    ExchangeDeliveryMargin = 0.0;
    ReserveBalance = 0.0;
    CurrencyID = '';
    PreFundMortgageIn = 0.0;
    PreFundMortgageOut = 0.0;
    FundMortgageIn = 0.0;
    FundMortgageOut = 0.0;
    FundMortgageAvailable = 0.0;
    MortgageableFund = 0.0;
    SpecProductMargin = 0.0;
    SpecProductFrozenMargin = 0.0;
    SpecProductCommission = 0.0;
    SpecProductFrozenCommission = 0.0;
    SpecProductPositionProfit = 0.0;
    SpecProductCloseProfit = 0.0;
    SpecProductPositionProfitByAlg = 0.0;
    SpecProductExchangeMargin = 0.0;
    FrozenSwap = 0.0;
    RemainSwap = 0.0;
}
jtp.CThostFtdcSyncingTradingAccountField=CThostFtdcSyncingTradingAccountField;

class CThostFtdcSyncingInvestorPositionField{
    reserve1 = '';
    BrokerID = '';
    InvestorID = '';
    PosiDirection = '';
    HedgeFlag = '';
    PositionDate = '';
    YdPosition = 0;
    Position = 0;
    LongFrozen = 0;
    ShortFrozen = 0;
    LongFrozenAmount = 0.0;
    ShortFrozenAmount = 0.0;
    OpenVolume = 0;
    CloseVolume = 0;
    OpenAmount = 0.0;
    CloseAmount = 0.0;
    PositionCost = 0.0;
    PreMargin = 0.0;
    UseMargin = 0.0;
    FrozenMargin = 0.0;
    FrozenCash = 0.0;
    FrozenCommission = 0.0;
    CashIn = 0.0;
    Commission = 0.0;
    CloseProfit = 0.0;
    PositionProfit = 0.0;
    PreSettlementPrice = 0.0;
    SettlementPrice = 0.0;
    TradingDay = '';
    SettlementID = 0;
    OpenCost = 0.0;
    ExchangeMargin = 0.0;
    CombPosition = 0;
    CombLongFrozen = 0;
    CombShortFrozen = 0;
    CloseProfitByDate = 0.0;
    CloseProfitByTrade = 0.0;
    TodayPosition = 0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    StrikeFrozen = 0;
    StrikeFrozenAmount = 0.0;
    AbandonFrozen = 0;
    ExchangeID = '';
    YdStrikeFrozen = 0;
    InvestUnitID = '';
    PositionCostOffset = 0.0;
    TasPosition = 0;
    TasPositionCost = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcSyncingInvestorPositionField=CThostFtdcSyncingInvestorPositionField;

class CThostFtdcSyncingInstrumentMarginRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    IsRelative = 0;
    InstrumentID = '';
}
jtp.CThostFtdcSyncingInstrumentMarginRateField=CThostFtdcSyncingInstrumentMarginRateField;

class CThostFtdcSyncingInstrumentCommissionRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcSyncingInstrumentCommissionRateField=CThostFtdcSyncingInstrumentCommissionRateField;

class CThostFtdcSyncingInstrumentTradingRightField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    TradingRight = '';
    InstrumentID = '';
}
jtp.CThostFtdcSyncingInstrumentTradingRightField=CThostFtdcSyncingInstrumentTradingRightField;

class CThostFtdcQryOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    OrderSysID = '';
    InsertTimeStart = '';
    InsertTimeEnd = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryOrderField=CThostFtdcQryOrderField;

class CThostFtdcQryTradeField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    TradeID = '';
    TradeTimeStart = '';
    TradeTimeEnd = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryTradeField=CThostFtdcQryTradeField;

class CThostFtdcQryInvestorPositionField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryInvestorPositionField=CThostFtdcQryInvestorPositionField;

class CThostFtdcQryTradingAccountField{
    BrokerID = '';
    InvestorID = '';
    CurrencyID = '';
    BizType = '';
    AccountID = '';
}
jtp.CThostFtdcQryTradingAccountField=CThostFtdcQryTradingAccountField;

class CThostFtdcQryInvestorField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryInvestorField=CThostFtdcQryInvestorField;

class CThostFtdcQryTradingCodeField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
    ClientID = '';
    ClientIDType = '';
    InvestUnitID = '';
}
jtp.CThostFtdcQryTradingCodeField=CThostFtdcQryTradingCodeField;

class CThostFtdcQryInvestorGroupField{
    BrokerID = '';
}
jtp.CThostFtdcQryInvestorGroupField=CThostFtdcQryInvestorGroupField;

class CThostFtdcQryInstrumentMarginRateField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    HedgeFlag = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryInstrumentMarginRateField=CThostFtdcQryInstrumentMarginRateField;

class CThostFtdcQryInstrumentCommissionRateField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryInstrumentCommissionRateField=CThostFtdcQryInstrumentCommissionRateField;

class CThostFtdcQryInstrumentTradingRightField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryInstrumentTradingRightField=CThostFtdcQryInstrumentTradingRightField;

class CThostFtdcQryBrokerField{
    BrokerID = '';
}
jtp.CThostFtdcQryBrokerField=CThostFtdcQryBrokerField;

class CThostFtdcQryTraderField{
    ExchangeID = '';
    ParticipantID = '';
    TraderID = '';
}
jtp.CThostFtdcQryTraderField=CThostFtdcQryTraderField;

class CThostFtdcQrySuperUserFunctionField{
    UserID = '';
}
jtp.CThostFtdcQrySuperUserFunctionField=CThostFtdcQrySuperUserFunctionField;

class CThostFtdcQryUserSessionField{
    FrontID = 0;
    SessionID = 0;
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcQryUserSessionField=CThostFtdcQryUserSessionField;

class CThostFtdcQryPartBrokerField{
    ExchangeID = '';
    BrokerID = '';
    ParticipantID = '';
}
jtp.CThostFtdcQryPartBrokerField=CThostFtdcQryPartBrokerField;

class CThostFtdcQryFrontStatusField{
    FrontID = 0;
}
jtp.CThostFtdcQryFrontStatusField=CThostFtdcQryFrontStatusField;

class CThostFtdcQryExchangeOrderField{
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    ExchangeID = '';
    TraderID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcQryExchangeOrderField=CThostFtdcQryExchangeOrderField;

class CThostFtdcQryOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
}
jtp.CThostFtdcQryOrderActionField=CThostFtdcQryOrderActionField;

class CThostFtdcQryExchangeOrderActionField{
    ParticipantID = '';
    ClientID = '';
    ExchangeID = '';
    TraderID = '';
}
jtp.CThostFtdcQryExchangeOrderActionField=CThostFtdcQryExchangeOrderActionField;

class CThostFtdcQrySuperUserField{
    UserID = '';
}
jtp.CThostFtdcQrySuperUserField=CThostFtdcQrySuperUserField;

class CThostFtdcQryExchangeField{
    ExchangeID = '';
}
jtp.CThostFtdcQryExchangeField=CThostFtdcQryExchangeField;

class CThostFtdcQryProductField{
    reserve1 = '';
    ProductClass = '';
    ExchangeID = '';
    ProductID = '';
}
jtp.CThostFtdcQryProductField=CThostFtdcQryProductField;

class CThostFtdcQryInstrumentField{
    reserve1 = '';
    ExchangeID = '';
    reserve2 = '';
    reserve3 = '';
    InstrumentID = '';
    ExchangeInstID = '';
    ProductID = '';
}
jtp.CThostFtdcQryInstrumentField=CThostFtdcQryInstrumentField;

class CThostFtdcQryDepthMarketDataField{
    reserve1 = '';
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryDepthMarketDataField=CThostFtdcQryDepthMarketDataField;

class CThostFtdcQryBrokerUserField{
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcQryBrokerUserField=CThostFtdcQryBrokerUserField;

class CThostFtdcQryBrokerUserFunctionField{
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcQryBrokerUserFunctionField=CThostFtdcQryBrokerUserFunctionField;

class CThostFtdcQryTraderOfferField{
    ExchangeID = '';
    ParticipantID = '';
    TraderID = '';
}
jtp.CThostFtdcQryTraderOfferField=CThostFtdcQryTraderOfferField;

class CThostFtdcQrySyncDepositField{
    BrokerID = '';
    DepositSeqNo = '';
}
jtp.CThostFtdcQrySyncDepositField=CThostFtdcQrySyncDepositField;

class CThostFtdcQrySettlementInfoField{
    BrokerID = '';
    InvestorID = '';
    TradingDay = '';
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcQrySettlementInfoField=CThostFtdcQrySettlementInfoField;

class CThostFtdcQryExchangeMarginRateField{
    BrokerID = '';
    reserve1 = '';
    HedgeFlag = '';
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryExchangeMarginRateField=CThostFtdcQryExchangeMarginRateField;

class CThostFtdcQryExchangeMarginRateAdjustField{
    BrokerID = '';
    reserve1 = '';
    HedgeFlag = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryExchangeMarginRateAdjustField=CThostFtdcQryExchangeMarginRateAdjustField;

class CThostFtdcQryExchangeRateField{
    BrokerID = '';
    FromCurrencyID = '';
    ToCurrencyID = '';
}
jtp.CThostFtdcQryExchangeRateField=CThostFtdcQryExchangeRateField;

class CThostFtdcQrySyncFundMortgageField{
    BrokerID = '';
    MortgageSeqNo = '';
}
jtp.CThostFtdcQrySyncFundMortgageField=CThostFtdcQrySyncFundMortgageField;

class CThostFtdcQryHisOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    OrderSysID = '';
    InsertTimeStart = '';
    InsertTimeEnd = '';
    TradingDay = '';
    SettlementID = 0;
    InstrumentID = '';
}
jtp.CThostFtdcQryHisOrderField=CThostFtdcQryHisOrderField;

class CThostFtdcOptionInstrMiniMarginField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    MinMargin = 0.0;
    ValueMethod = '';
    IsRelative = 0;
    InstrumentID = '';
}
jtp.CThostFtdcOptionInstrMiniMarginField=CThostFtdcOptionInstrMiniMarginField;

class CThostFtdcOptionInstrMarginAdjustField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    SShortMarginRatioByMoney = 0.0;
    SShortMarginRatioByVolume = 0.0;
    HShortMarginRatioByMoney = 0.0;
    HShortMarginRatioByVolume = 0.0;
    AShortMarginRatioByMoney = 0.0;
    AShortMarginRatioByVolume = 0.0;
    IsRelative = 0;
    MShortMarginRatioByMoney = 0.0;
    MShortMarginRatioByVolume = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcOptionInstrMarginAdjustField=CThostFtdcOptionInstrMarginAdjustField;

class CThostFtdcOptionInstrCommRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    StrikeRatioByMoney = 0.0;
    StrikeRatioByVolume = 0.0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcOptionInstrCommRateField=CThostFtdcOptionInstrCommRateField;

class CThostFtdcOptionInstrTradeCostField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    HedgeFlag = '';
    FixedMargin = 0.0;
    MiniMargin = 0.0;
    Royalty = 0.0;
    ExchFixedMargin = 0.0;
    ExchMiniMargin = 0.0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcOptionInstrTradeCostField=CThostFtdcOptionInstrTradeCostField;

class CThostFtdcQryOptionInstrTradeCostField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    HedgeFlag = '';
    InputPrice = 0.0;
    UnderlyingPrice = 0.0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryOptionInstrTradeCostField=CThostFtdcQryOptionInstrTradeCostField;

class CThostFtdcQryOptionInstrCommRateField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryOptionInstrCommRateField=CThostFtdcQryOptionInstrCommRateField;

class CThostFtdcIndexPriceField{
    BrokerID = '';
    reserve1 = '';
    ClosePrice = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcIndexPriceField=CThostFtdcIndexPriceField;

class CThostFtdcInputExecOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExecOrderRef = '';
    UserID = '';
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    OffsetFlag = '';
    HedgeFlag = '';
    ActionType = '';
    PosiDirection = '';
    ReservePositionFlag = '';
    CloseFlag = '';
    ExchangeID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputExecOrderField=CThostFtdcInputExecOrderField;

class CThostFtdcInputExecOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ExecOrderActionRef = 0;
    ExecOrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    ExecOrderSysID = '';
    ActionFlag = '';
    UserID = '';
    reserve1 = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputExecOrderActionField=CThostFtdcInputExecOrderActionField;

class CThostFtdcExecOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExecOrderRef = '';
    UserID = '';
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    OffsetFlag = '';
    HedgeFlag = '';
    ActionType = '';
    PosiDirection = '';
    ReservePositionFlag = '';
    CloseFlag = '';
    ExecOrderLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    ExecOrderSysID = '';
    InsertDate = '';
    InsertTime = '';
    CancelTime = '';
    ExecResult = '';
    ClearingPartID = '';
    SequenceNo = 0;
    FrontID = 0;
    SessionID = 0;
    UserProductInfo = '';
    StatusMsg = '';
    ActiveUserID = '';
    BrokerExecOrderSeq = 0;
    BranchID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    reserve3 = '';
    MacAddress = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExecOrderField=CThostFtdcExecOrderField;

class CThostFtdcExecOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ExecOrderActionRef = 0;
    ExecOrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    ExecOrderSysID = '';
    ActionFlag = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    ExecOrderLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    ActionType = '';
    StatusMsg = '';
    reserve1 = '';
    BranchID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcExecOrderActionField=CThostFtdcExecOrderActionField;

class CThostFtdcQryExecOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    ExecOrderSysID = '';
    InsertTimeStart = '';
    InsertTimeEnd = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryExecOrderField=CThostFtdcQryExecOrderField;

class CThostFtdcExchangeExecOrderField{
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    OffsetFlag = '';
    HedgeFlag = '';
    ActionType = '';
    PosiDirection = '';
    ReservePositionFlag = '';
    CloseFlag = '';
    ExecOrderLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    ExecOrderSysID = '';
    InsertDate = '';
    InsertTime = '';
    CancelTime = '';
    ExecResult = '';
    ClearingPartID = '';
    SequenceNo = 0;
    BranchID = '';
    reserve2 = '';
    MacAddress = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeExecOrderField=CThostFtdcExchangeExecOrderField;

class CThostFtdcQryExchangeExecOrderField{
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    ExchangeID = '';
    TraderID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcQryExchangeExecOrderField=CThostFtdcQryExchangeExecOrderField;

class CThostFtdcQryExecOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
}
jtp.CThostFtdcQryExecOrderActionField=CThostFtdcQryExecOrderActionField;

class CThostFtdcExchangeExecOrderActionField{
    ExchangeID = '';
    ExecOrderSysID = '';
    ActionFlag = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    ExecOrderLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    ActionType = '';
    BranchID = '';
    reserve1 = '';
    MacAddress = '';
    reserve2 = '';
    Volume = 0;
    IPAddress = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcExchangeExecOrderActionField=CThostFtdcExchangeExecOrderActionField;

class CThostFtdcQryExchangeExecOrderActionField{
    ParticipantID = '';
    ClientID = '';
    ExchangeID = '';
    TraderID = '';
}
jtp.CThostFtdcQryExchangeExecOrderActionField=CThostFtdcQryExchangeExecOrderActionField;

class CThostFtdcErrExecOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExecOrderRef = '';
    UserID = '';
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    OffsetFlag = '';
    HedgeFlag = '';
    ActionType = '';
    PosiDirection = '';
    ReservePositionFlag = '';
    CloseFlag = '';
    ExchangeID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    ErrorID = 0;
    ErrorMsg = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcErrExecOrderField=CThostFtdcErrExecOrderField;

class CThostFtdcQryErrExecOrderField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryErrExecOrderField=CThostFtdcQryErrExecOrderField;

class CThostFtdcErrExecOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ExecOrderActionRef = 0;
    ExecOrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    ExecOrderSysID = '';
    ActionFlag = '';
    UserID = '';
    reserve1 = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    ErrorID = 0;
    ErrorMsg = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcErrExecOrderActionField=CThostFtdcErrExecOrderActionField;

class CThostFtdcQryErrExecOrderActionField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryErrExecOrderActionField=CThostFtdcQryErrExecOrderActionField;

class CThostFtdcOptionInstrTradingRightField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    Direction = '';
    TradingRight = '';
    InstrumentID = '';
}
jtp.CThostFtdcOptionInstrTradingRightField=CThostFtdcOptionInstrTradingRightField;

class CThostFtdcQryOptionInstrTradingRightField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    Direction = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryOptionInstrTradingRightField=CThostFtdcQryOptionInstrTradingRightField;

class CThostFtdcInputForQuoteField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ForQuoteRef = '';
    UserID = '';
    ExchangeID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputForQuoteField=CThostFtdcInputForQuoteField;

class CThostFtdcForQuoteField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ForQuoteRef = '';
    UserID = '';
    ForQuoteLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    InsertDate = '';
    InsertTime = '';
    ForQuoteStatus = '';
    FrontID = 0;
    SessionID = 0;
    StatusMsg = '';
    ActiveUserID = '';
    BrokerForQutoSeq = 0;
    InvestUnitID = '';
    reserve3 = '';
    MacAddress = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcForQuoteField=CThostFtdcForQuoteField;

class CThostFtdcQryForQuoteField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InsertTimeStart = '';
    InsertTimeEnd = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryForQuoteField=CThostFtdcQryForQuoteField;

class CThostFtdcExchangeForQuoteField{
    ForQuoteLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    TraderID = '';
    InstallID = 0;
    InsertDate = '';
    InsertTime = '';
    ForQuoteStatus = '';
    reserve2 = '';
    MacAddress = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeForQuoteField=CThostFtdcExchangeForQuoteField;

class CThostFtdcQryExchangeForQuoteField{
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    ExchangeID = '';
    TraderID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcQryExchangeForQuoteField=CThostFtdcQryExchangeForQuoteField;

class CThostFtdcInputQuoteField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    QuoteRef = '';
    UserID = '';
    AskPrice = 0.0;
    BidPrice = 0.0;
    AskVolume = 0;
    BidVolume = 0;
    RequestID = 0;
    BusinessUnit = '';
    AskOffsetFlag = '';
    BidOffsetFlag = '';
    AskHedgeFlag = '';
    BidHedgeFlag = '';
    AskOrderRef = '';
    BidOrderRef = '';
    ForQuoteSysID = '';
    ExchangeID = '';
    InvestUnitID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
    ReplaceSysID = '';
}
jtp.CThostFtdcInputQuoteField=CThostFtdcInputQuoteField;

class CThostFtdcInputQuoteActionField{
    BrokerID = '';
    InvestorID = '';
    QuoteActionRef = 0;
    QuoteRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    QuoteSysID = '';
    ActionFlag = '';
    UserID = '';
    reserve1 = '';
    InvestUnitID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputQuoteActionField=CThostFtdcInputQuoteActionField;

class CThostFtdcQuoteField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    QuoteRef = '';
    UserID = '';
    AskPrice = 0.0;
    BidPrice = 0.0;
    AskVolume = 0;
    BidVolume = 0;
    RequestID = 0;
    BusinessUnit = '';
    AskOffsetFlag = '';
    BidOffsetFlag = '';
    AskHedgeFlag = '';
    BidHedgeFlag = '';
    QuoteLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    NotifySequence = 0;
    OrderSubmitStatus = '';
    TradingDay = '';
    SettlementID = 0;
    QuoteSysID = '';
    InsertDate = '';
    InsertTime = '';
    CancelTime = '';
    QuoteStatus = '';
    ClearingPartID = '';
    SequenceNo = 0;
    AskOrderSysID = '';
    BidOrderSysID = '';
    FrontID = 0;
    SessionID = 0;
    UserProductInfo = '';
    StatusMsg = '';
    ActiveUserID = '';
    BrokerQuoteSeq = 0;
    AskOrderRef = '';
    BidOrderRef = '';
    ForQuoteSysID = '';
    BranchID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    reserve3 = '';
    MacAddress = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
    ReplaceSysID = '';
}
jtp.CThostFtdcQuoteField=CThostFtdcQuoteField;

class CThostFtdcQuoteActionField{
    BrokerID = '';
    InvestorID = '';
    QuoteActionRef = 0;
    QuoteRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    QuoteSysID = '';
    ActionFlag = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    QuoteLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    StatusMsg = '';
    reserve1 = '';
    BranchID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcQuoteActionField=CThostFtdcQuoteActionField;

class CThostFtdcQryQuoteField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    QuoteSysID = '';
    InsertTimeStart = '';
    InsertTimeEnd = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryQuoteField=CThostFtdcQryQuoteField;

class CThostFtdcExchangeQuoteField{
    AskPrice = 0.0;
    BidPrice = 0.0;
    AskVolume = 0;
    BidVolume = 0;
    RequestID = 0;
    BusinessUnit = '';
    AskOffsetFlag = '';
    BidOffsetFlag = '';
    AskHedgeFlag = '';
    BidHedgeFlag = '';
    QuoteLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    TraderID = '';
    InstallID = 0;
    NotifySequence = 0;
    OrderSubmitStatus = '';
    TradingDay = '';
    SettlementID = 0;
    QuoteSysID = '';
    InsertDate = '';
    InsertTime = '';
    CancelTime = '';
    QuoteStatus = '';
    ClearingPartID = '';
    SequenceNo = 0;
    AskOrderSysID = '';
    BidOrderSysID = '';
    ForQuoteSysID = '';
    BranchID = '';
    reserve2 = '';
    MacAddress = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeQuoteField=CThostFtdcExchangeQuoteField;

class CThostFtdcQryExchangeQuoteField{
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    ExchangeID = '';
    TraderID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcQryExchangeQuoteField=CThostFtdcQryExchangeQuoteField;

class CThostFtdcQryQuoteActionField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
}
jtp.CThostFtdcQryQuoteActionField=CThostFtdcQryQuoteActionField;

class CThostFtdcExchangeQuoteActionField{
    ExchangeID = '';
    QuoteSysID = '';
    ActionFlag = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    QuoteLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    reserve1 = '';
    MacAddress = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeQuoteActionField=CThostFtdcExchangeQuoteActionField;

class CThostFtdcQryExchangeQuoteActionField{
    ParticipantID = '';
    ClientID = '';
    ExchangeID = '';
    TraderID = '';
}
jtp.CThostFtdcQryExchangeQuoteActionField=CThostFtdcQryExchangeQuoteActionField;

class CThostFtdcOptionInstrDeltaField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    Delta = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcOptionInstrDeltaField=CThostFtdcOptionInstrDeltaField;

class CThostFtdcForQuoteRspField{
    TradingDay = '';
    reserve1 = '';
    ForQuoteSysID = '';
    ForQuoteTime = '';
    ActionDay = '';
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcForQuoteRspField=CThostFtdcForQuoteRspField;

class CThostFtdcStrikeOffsetField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    Offset = 0.0;
    OffsetType = '';
    InstrumentID = '';
}
jtp.CThostFtdcStrikeOffsetField=CThostFtdcStrikeOffsetField;

class CThostFtdcQryStrikeOffsetField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryStrikeOffsetField=CThostFtdcQryStrikeOffsetField;

class CThostFtdcInputBatchOrderActionField{
    BrokerID = '';
    InvestorID = '';
    OrderActionRef = 0;
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    UserID = '';
    InvestUnitID = '';
    reserve1 = '';
    MacAddress = '';
    IPAddress = '';
}
jtp.CThostFtdcInputBatchOrderActionField=CThostFtdcInputBatchOrderActionField;

class CThostFtdcBatchOrderActionField{
    BrokerID = '';
    InvestorID = '';
    OrderActionRef = 0;
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    StatusMsg = '';
    InvestUnitID = '';
    reserve1 = '';
    MacAddress = '';
    IPAddress = '';
}
jtp.CThostFtdcBatchOrderActionField=CThostFtdcBatchOrderActionField;

class CThostFtdcExchangeBatchOrderActionField{
    ExchangeID = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    reserve1 = '';
    MacAddress = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeBatchOrderActionField=CThostFtdcExchangeBatchOrderActionField;

class CThostFtdcQryBatchOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
}
jtp.CThostFtdcQryBatchOrderActionField=CThostFtdcQryBatchOrderActionField;

class CThostFtdcCombInstrumentGuardField{
    BrokerID = '';
    reserve1 = '';
    GuarantRatio = 0.0;
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcCombInstrumentGuardField=CThostFtdcCombInstrumentGuardField;

class CThostFtdcQryCombInstrumentGuardField{
    BrokerID = '';
    reserve1 = '';
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryCombInstrumentGuardField=CThostFtdcQryCombInstrumentGuardField;

class CThostFtdcInputCombActionField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    CombActionRef = '';
    UserID = '';
    Direction = '';
    Volume = 0;
    CombDirection = '';
    HedgeFlag = '';
    ExchangeID = '';
    reserve2 = '';
    MacAddress = '';
    InvestUnitID = '';
    FrontID = 0;
    SessionID = 0;
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputCombActionField=CThostFtdcInputCombActionField;

class CThostFtdcCombActionField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    CombActionRef = '';
    UserID = '';
    Direction = '';
    Volume = 0;
    CombDirection = '';
    HedgeFlag = '';
    ActionLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    ActionStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    SequenceNo = 0;
    FrontID = 0;
    SessionID = 0;
    UserProductInfo = '';
    StatusMsg = '';
    reserve3 = '';
    MacAddress = '';
    ComTradeID = '';
    BranchID = '';
    InvestUnitID = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcCombActionField=CThostFtdcCombActionField;

class CThostFtdcQryCombActionField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryCombActionField=CThostFtdcQryCombActionField;

class CThostFtdcExchangeCombActionField{
    Direction = '';
    Volume = 0;
    CombDirection = '';
    HedgeFlag = '';
    ActionLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    TraderID = '';
    InstallID = 0;
    ActionStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    SequenceNo = 0;
    reserve2 = '';
    MacAddress = '';
    ComTradeID = '';
    BranchID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeCombActionField=CThostFtdcExchangeCombActionField;

class CThostFtdcQryExchangeCombActionField{
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    ExchangeID = '';
    TraderID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcQryExchangeCombActionField=CThostFtdcQryExchangeCombActionField;

class CThostFtdcProductExchRateField{
    reserve1 = '';
    QuoteCurrencyID = '';
    ExchangeRate = 0.0;
    ExchangeID = '';
    ProductID = '';
}
jtp.CThostFtdcProductExchRateField=CThostFtdcProductExchRateField;

class CThostFtdcQryProductExchRateField{
    reserve1 = '';
    ExchangeID = '';
    ProductID = '';
}
jtp.CThostFtdcQryProductExchRateField=CThostFtdcQryProductExchRateField;

class CThostFtdcQryForQuoteParamField{
    BrokerID = '';
    reserve1 = '';
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryForQuoteParamField=CThostFtdcQryForQuoteParamField;

class CThostFtdcForQuoteParamField{
    BrokerID = '';
    reserve1 = '';
    ExchangeID = '';
    LastPrice = 0.0;
    PriceInterval = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcForQuoteParamField=CThostFtdcForQuoteParamField;

class CThostFtdcMMOptionInstrCommRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    StrikeRatioByMoney = 0.0;
    StrikeRatioByVolume = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcMMOptionInstrCommRateField=CThostFtdcMMOptionInstrCommRateField;

class CThostFtdcQryMMOptionInstrCommRateField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryMMOptionInstrCommRateField=CThostFtdcQryMMOptionInstrCommRateField;

class CThostFtdcMMInstrumentCommissionRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcMMInstrumentCommissionRateField=CThostFtdcMMInstrumentCommissionRateField;

class CThostFtdcQryMMInstrumentCommissionRateField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryMMInstrumentCommissionRateField=CThostFtdcQryMMInstrumentCommissionRateField;

class CThostFtdcInstrumentOrderCommRateField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    OrderCommByVolume = 0.0;
    OrderActionCommByVolume = 0.0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
    OrderCommByTrade = 0.0;
    OrderActionCommByTrade = 0.0;
}
jtp.CThostFtdcInstrumentOrderCommRateField=CThostFtdcInstrumentOrderCommRateField;

class CThostFtdcQryInstrumentOrderCommRateField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryInstrumentOrderCommRateField=CThostFtdcQryInstrumentOrderCommRateField;

class CThostFtdcTradeParamField{
    BrokerID = '';
    TradeParamID = '';
    TradeParamValue = '';
    Memo = '';
}
jtp.CThostFtdcTradeParamField=CThostFtdcTradeParamField;

class CThostFtdcInstrumentMarginRateULField{
    reserve1 = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcInstrumentMarginRateULField=CThostFtdcInstrumentMarginRateULField;

class CThostFtdcFutureLimitPosiParamField{
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    SpecOpenVolume = 0;
    ArbiOpenVolume = 0;
    OpenVolume = 0;
    ProductID = '';
}
jtp.CThostFtdcFutureLimitPosiParamField=CThostFtdcFutureLimitPosiParamField;

class CThostFtdcLoginForbiddenIPField{
    reserve1 = '';
    IPAddress = '';
}
jtp.CThostFtdcLoginForbiddenIPField=CThostFtdcLoginForbiddenIPField;

class CThostFtdcIPListField{
    reserve1 = '';
    IsWhite = 0;
    IPAddress = '';
}
jtp.CThostFtdcIPListField=CThostFtdcIPListField;

class CThostFtdcInputOptionSelfCloseField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OptionSelfCloseRef = '';
    UserID = '';
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    HedgeFlag = '';
    OptSelfCloseFlag = '';
    ExchangeID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputOptionSelfCloseField=CThostFtdcInputOptionSelfCloseField;

class CThostFtdcInputOptionSelfCloseActionField{
    BrokerID = '';
    InvestorID = '';
    OptionSelfCloseActionRef = 0;
    OptionSelfCloseRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    OptionSelfCloseSysID = '';
    ActionFlag = '';
    UserID = '';
    reserve1 = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcInputOptionSelfCloseActionField=CThostFtdcInputOptionSelfCloseActionField;

class CThostFtdcOptionSelfCloseField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OptionSelfCloseRef = '';
    UserID = '';
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    HedgeFlag = '';
    OptSelfCloseFlag = '';
    OptionSelfCloseLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    OptionSelfCloseSysID = '';
    InsertDate = '';
    InsertTime = '';
    CancelTime = '';
    ExecResult = '';
    ClearingPartID = '';
    SequenceNo = 0;
    FrontID = 0;
    SessionID = 0;
    UserProductInfo = '';
    StatusMsg = '';
    ActiveUserID = '';
    BrokerOptionSelfCloseSeq = 0;
    BranchID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    reserve3 = '';
    MacAddress = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcOptionSelfCloseField=CThostFtdcOptionSelfCloseField;

class CThostFtdcOptionSelfCloseActionField{
    BrokerID = '';
    InvestorID = '';
    OptionSelfCloseActionRef = 0;
    OptionSelfCloseRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    OptionSelfCloseSysID = '';
    ActionFlag = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    OptionSelfCloseLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    StatusMsg = '';
    reserve1 = '';
    BranchID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcOptionSelfCloseActionField=CThostFtdcOptionSelfCloseActionField;

class CThostFtdcQryOptionSelfCloseField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    OptionSelfCloseSysID = '';
    InsertTimeStart = '';
    InsertTimeEnd = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryOptionSelfCloseField=CThostFtdcQryOptionSelfCloseField;

class CThostFtdcExchangeOptionSelfCloseField{
    Volume = 0;
    RequestID = 0;
    BusinessUnit = '';
    HedgeFlag = '';
    OptSelfCloseFlag = '';
    OptionSelfCloseLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve1 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    OptionSelfCloseSysID = '';
    InsertDate = '';
    InsertTime = '';
    CancelTime = '';
    ExecResult = '';
    ClearingPartID = '';
    SequenceNo = 0;
    BranchID = '';
    reserve2 = '';
    MacAddress = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcExchangeOptionSelfCloseField=CThostFtdcExchangeOptionSelfCloseField;

class CThostFtdcQryOptionSelfCloseActionField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
}
jtp.CThostFtdcQryOptionSelfCloseActionField=CThostFtdcQryOptionSelfCloseActionField;

class CThostFtdcExchangeOptionSelfCloseActionField{
    ExchangeID = '';
    OptionSelfCloseSysID = '';
    ActionFlag = '';
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    OptionSelfCloseLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    BranchID = '';
    reserve1 = '';
    MacAddress = '';
    reserve2 = '';
    OptSelfCloseFlag = '';
    IPAddress = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcExchangeOptionSelfCloseActionField=CThostFtdcExchangeOptionSelfCloseActionField;

class CThostFtdcSyncDelaySwapField{
    DelaySwapSeqNo = '';
    BrokerID = '';
    InvestorID = '';
    FromCurrencyID = '';
    FromAmount = 0.0;
    FromFrozenSwap = 0.0;
    FromRemainSwap = 0.0;
    ToCurrencyID = '';
    ToAmount = 0.0;
    IsManualSwap = 0;
    IsAllRemainSetZero = 0;
}
jtp.CThostFtdcSyncDelaySwapField=CThostFtdcSyncDelaySwapField;

class CThostFtdcQrySyncDelaySwapField{
    BrokerID = '';
    DelaySwapSeqNo = '';
}
jtp.CThostFtdcQrySyncDelaySwapField=CThostFtdcQrySyncDelaySwapField;

class CThostFtdcInvestUnitField{
    BrokerID = '';
    InvestorID = '';
    InvestUnitID = '';
    InvestorUnitName = '';
    InvestorGroupID = '';
    CommModelID = '';
    MarginModelID = '';
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcInvestUnitField=CThostFtdcInvestUnitField;

class CThostFtdcQryInvestUnitField{
    BrokerID = '';
    InvestorID = '';
    InvestUnitID = '';
}
jtp.CThostFtdcQryInvestUnitField=CThostFtdcQryInvestUnitField;

class CThostFtdcSecAgentCheckModeField{
    InvestorID = '';
    BrokerID = '';
    CurrencyID = '';
    BrokerSecAgentID = '';
    CheckSelfAccount = 0;
}
jtp.CThostFtdcSecAgentCheckModeField=CThostFtdcSecAgentCheckModeField;

class CThostFtdcSecAgentTradeInfoField{
    BrokerID = '';
    BrokerSecAgentID = '';
    InvestorID = '';
    LongCustomerName = '';
}
jtp.CThostFtdcSecAgentTradeInfoField=CThostFtdcSecAgentTradeInfoField;

class CThostFtdcMarketDataField{
    TradingDay = '';
    reserve1 = '';
    ExchangeID = '';
    reserve2 = '';
    LastPrice = 0.0;
    PreSettlementPrice = 0.0;
    PreClosePrice = 0.0;
    PreOpenInterest = 0.0;
    OpenPrice = 0.0;
    HighestPrice = 0.0;
    LowestPrice = 0.0;
    Volume = 0;
    Turnover = 0.0;
    OpenInterest = 0.0;
    ClosePrice = 0.0;
    SettlementPrice = 0.0;
    UpperLimitPrice = 0.0;
    LowerLimitPrice = 0.0;
    PreDelta = 0.0;
    CurrDelta = 0.0;
    UpdateTime = '';
    UpdateMillisec = 0;
    ActionDay = '';
    InstrumentID = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcMarketDataField=CThostFtdcMarketDataField;

class CThostFtdcMarketDataBaseField{
    TradingDay = '';
    PreSettlementPrice = 0.0;
    PreClosePrice = 0.0;
    PreOpenInterest = 0.0;
    PreDelta = 0.0;
}
jtp.CThostFtdcMarketDataBaseField=CThostFtdcMarketDataBaseField;

class CThostFtdcMarketDataStaticField{
    OpenPrice = 0.0;
    HighestPrice = 0.0;
    LowestPrice = 0.0;
    ClosePrice = 0.0;
    UpperLimitPrice = 0.0;
    LowerLimitPrice = 0.0;
    SettlementPrice = 0.0;
    CurrDelta = 0.0;
}
jtp.CThostFtdcMarketDataStaticField=CThostFtdcMarketDataStaticField;

class CThostFtdcMarketDataLastMatchField{
    LastPrice = 0.0;
    Volume = 0;
    Turnover = 0.0;
    OpenInterest = 0.0;
}
jtp.CThostFtdcMarketDataLastMatchField=CThostFtdcMarketDataLastMatchField;

class CThostFtdcMarketDataBestPriceField{
    BidPrice1 = 0.0;
    BidVolume1 = 0;
    AskPrice1 = 0.0;
    AskVolume1 = 0;
}
jtp.CThostFtdcMarketDataBestPriceField=CThostFtdcMarketDataBestPriceField;

class CThostFtdcMarketDataBid23Field{
    BidPrice2 = 0.0;
    BidVolume2 = 0;
    BidPrice3 = 0.0;
    BidVolume3 = 0;
}
jtp.CThostFtdcMarketDataBid23Field=CThostFtdcMarketDataBid23Field;

class CThostFtdcMarketDataAsk23Field{
    AskPrice2 = 0.0;
    AskVolume2 = 0;
    AskPrice3 = 0.0;
    AskVolume3 = 0;
}
jtp.CThostFtdcMarketDataAsk23Field=CThostFtdcMarketDataAsk23Field;

class CThostFtdcMarketDataBid45Field{
    BidPrice4 = 0.0;
    BidVolume4 = 0;
    BidPrice5 = 0.0;
    BidVolume5 = 0;
}
jtp.CThostFtdcMarketDataBid45Field=CThostFtdcMarketDataBid45Field;

class CThostFtdcMarketDataAsk45Field{
    AskPrice4 = 0.0;
    AskVolume4 = 0;
    AskPrice5 = 0.0;
    AskVolume5 = 0;
}
jtp.CThostFtdcMarketDataAsk45Field=CThostFtdcMarketDataAsk45Field;

class CThostFtdcMarketDataUpdateTimeField{
    reserve1 = '';
    UpdateTime = '';
    UpdateMillisec = 0;
    ActionDay = '';
    InstrumentID = '';
}
jtp.CThostFtdcMarketDataUpdateTimeField=CThostFtdcMarketDataUpdateTimeField;

class CThostFtdcMarketDataBandingPriceField{
    BandingUpperPrice = 0.0;
    BandingLowerPrice = 0.0;
}
jtp.CThostFtdcMarketDataBandingPriceField=CThostFtdcMarketDataBandingPriceField;

class CThostFtdcMarketDataExchangeField{
    ExchangeID = '';
}
jtp.CThostFtdcMarketDataExchangeField=CThostFtdcMarketDataExchangeField;

class CThostFtdcSpecificInstrumentField{
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcSpecificInstrumentField=CThostFtdcSpecificInstrumentField;

class CThostFtdcInstrumentStatusField{
    ExchangeID = '';
    reserve1 = '';
    SettlementGroupID = '';
    reserve2 = '';
    InstrumentStatus = '';
    TradingSegmentSN = 0;
    EnterTime = '';
    EnterReason = '';
    ExchangeInstID = '';
    InstrumentID = '';
}
jtp.CThostFtdcInstrumentStatusField=CThostFtdcInstrumentStatusField;

class CThostFtdcQryInstrumentStatusField{
    ExchangeID = '';
    reserve1 = '';
    ExchangeInstID = '';
}
jtp.CThostFtdcQryInstrumentStatusField=CThostFtdcQryInstrumentStatusField;

class CThostFtdcInvestorAccountField{
    BrokerID = '';
    InvestorID = '';
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcInvestorAccountField=CThostFtdcInvestorAccountField;

class CThostFtdcPositionProfitAlgorithmField{
    BrokerID = '';
    AccountID = '';
    Algorithm = '';
    Memo = '';
    CurrencyID = '';
}
jtp.CThostFtdcPositionProfitAlgorithmField=CThostFtdcPositionProfitAlgorithmField;

class CThostFtdcDiscountField{
    BrokerID = '';
    InvestorRange = '';
    InvestorID = '';
    Discount = 0.0;
}
jtp.CThostFtdcDiscountField=CThostFtdcDiscountField;

class CThostFtdcQryTransferBankField{
    BankID = '';
    BankBrchID = '';
}
jtp.CThostFtdcQryTransferBankField=CThostFtdcQryTransferBankField;

class CThostFtdcTransferBankField{
    BankID = '';
    BankBrchID = '';
    BankName = '';
    IsActive = 0;
}
jtp.CThostFtdcTransferBankField=CThostFtdcTransferBankField;

class CThostFtdcQryInvestorPositionDetailField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryInvestorPositionDetailField=CThostFtdcQryInvestorPositionDetailField;

class CThostFtdcInvestorPositionDetailField{
    reserve1 = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    Direction = '';
    OpenDate = '';
    TradeID = '';
    Volume = 0;
    OpenPrice = 0.0;
    TradingDay = '';
    SettlementID = 0;
    TradeType = '';
    reserve2 = '';
    ExchangeID = '';
    CloseProfitByDate = 0.0;
    CloseProfitByTrade = 0.0;
    PositionProfitByDate = 0.0;
    PositionProfitByTrade = 0.0;
    Margin = 0.0;
    ExchMargin = 0.0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    LastSettlementPrice = 0.0;
    SettlementPrice = 0.0;
    CloseVolume = 0;
    CloseAmount = 0.0;
    TimeFirstVolume = 0;
    InvestUnitID = '';
    SpecPosiType = '';
    InstrumentID = '';
    CombInstrumentID = '';
}
jtp.CThostFtdcInvestorPositionDetailField=CThostFtdcInvestorPositionDetailField;

class CThostFtdcTradingAccountPasswordField{
    BrokerID = '';
    AccountID = '';
    Password = '';
    CurrencyID = '';
}
jtp.CThostFtdcTradingAccountPasswordField=CThostFtdcTradingAccountPasswordField;

class CThostFtdcMDTraderOfferField{
    ExchangeID = '';
    TraderID = '';
    ParticipantID = '';
    Password = '';
    InstallID = 0;
    OrderLocalID = '';
    TraderConnectStatus = '';
    ConnectRequestDate = '';
    ConnectRequestTime = '';
    LastReportDate = '';
    LastReportTime = '';
    ConnectDate = '';
    ConnectTime = '';
    StartDate = '';
    StartTime = '';
    TradingDay = '';
    BrokerID = '';
    MaxTradeID = '';
    MaxOrderMessageReference = '';
}
jtp.CThostFtdcMDTraderOfferField=CThostFtdcMDTraderOfferField;

class CThostFtdcQryMDTraderOfferField{
    ExchangeID = '';
    ParticipantID = '';
    TraderID = '';
}
jtp.CThostFtdcQryMDTraderOfferField=CThostFtdcQryMDTraderOfferField;

class CThostFtdcQryNoticeField{
    BrokerID = '';
}
jtp.CThostFtdcQryNoticeField=CThostFtdcQryNoticeField;

class CThostFtdcNoticeField{
    BrokerID = '';
    Content = '';
    SequenceLabel = '';
}
jtp.CThostFtdcNoticeField=CThostFtdcNoticeField;

class CThostFtdcUserRightField{
    BrokerID = '';
    UserID = '';
    UserRightType = '';
    IsForbidden = 0;
}
jtp.CThostFtdcUserRightField=CThostFtdcUserRightField;

class CThostFtdcQrySettlementInfoConfirmField{
    BrokerID = '';
    InvestorID = '';
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcQrySettlementInfoConfirmField=CThostFtdcQrySettlementInfoConfirmField;

class CThostFtdcLoadSettlementInfoField{
    BrokerID = '';
}
jtp.CThostFtdcLoadSettlementInfoField=CThostFtdcLoadSettlementInfoField;

class CThostFtdcBrokerWithdrawAlgorithmField{
    BrokerID = '';
    WithdrawAlgorithm = '';
    UsingRatio = 0.0;
    IncludeCloseProfit = '';
    AllWithoutTrade = '';
    AvailIncludeCloseProfit = '';
    IsBrokerUserEvent = 0;
    CurrencyID = '';
    FundMortgageRatio = 0.0;
    BalanceAlgorithm = '';
}
jtp.CThostFtdcBrokerWithdrawAlgorithmField=CThostFtdcBrokerWithdrawAlgorithmField;

class CThostFtdcTradingAccountPasswordUpdateV1Field{
    BrokerID = '';
    InvestorID = '';
    OldPassword = '';
    NewPassword = '';
}
jtp.CThostFtdcTradingAccountPasswordUpdateV1Field=CThostFtdcTradingAccountPasswordUpdateV1Field;

class CThostFtdcTradingAccountPasswordUpdateField{
    BrokerID = '';
    AccountID = '';
    OldPassword = '';
    NewPassword = '';
    CurrencyID = '';
}
jtp.CThostFtdcTradingAccountPasswordUpdateField=CThostFtdcTradingAccountPasswordUpdateField;

class CThostFtdcQryCombinationLegField{
    reserve1 = '';
    LegID = 0;
    reserve2 = '';
    CombInstrumentID = '';
    LegInstrumentID = '';
}
jtp.CThostFtdcQryCombinationLegField=CThostFtdcQryCombinationLegField;

class CThostFtdcQrySyncStatusField{
    TradingDay = '';
}
jtp.CThostFtdcQrySyncStatusField=CThostFtdcQrySyncStatusField;

class CThostFtdcCombinationLegField{
    reserve1 = '';
    LegID = 0;
    reserve2 = '';
    Direction = '';
    LegMultiple = 0;
    ImplyLevel = 0;
    CombInstrumentID = '';
    LegInstrumentID = '';
}
jtp.CThostFtdcCombinationLegField=CThostFtdcCombinationLegField;

class CThostFtdcSyncStatusField{
    TradingDay = '';
    DataSyncStatus = '';
}
jtp.CThostFtdcSyncStatusField=CThostFtdcSyncStatusField;

class CThostFtdcQryLinkManField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryLinkManField=CThostFtdcQryLinkManField;

class CThostFtdcLinkManField{
    BrokerID = '';
    InvestorID = '';
    PersonType = '';
    IdentifiedCardType = '';
    IdentifiedCardNo = '';
    PersonName = '';
    Telephone = '';
    Address = '';
    ZipCode = '';
    Priority = 0;
    UOAZipCode = '';
    PersonFullName = '';
}
jtp.CThostFtdcLinkManField=CThostFtdcLinkManField;

class CThostFtdcQryBrokerUserEventField{
    BrokerID = '';
    UserID = '';
    UserEventType = '';
}
jtp.CThostFtdcQryBrokerUserEventField=CThostFtdcQryBrokerUserEventField;

class CThostFtdcBrokerUserEventField{
    BrokerID = '';
    UserID = '';
    UserEventType = '';
    EventSequenceNo = 0;
    EventDate = '';
    EventTime = '';
    UserEventInfo = '';
    InvestorID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcBrokerUserEventField=CThostFtdcBrokerUserEventField;

class CThostFtdcQryContractBankField{
    BrokerID = '';
    BankID = '';
    BankBrchID = '';
}
jtp.CThostFtdcQryContractBankField=CThostFtdcQryContractBankField;

class CThostFtdcContractBankField{
    BrokerID = '';
    BankID = '';
    BankBrchID = '';
    BankName = '';
}
jtp.CThostFtdcContractBankField=CThostFtdcContractBankField;

class CThostFtdcInvestorPositionCombineDetailField{
    TradingDay = '';
    OpenDate = '';
    ExchangeID = '';
    SettlementID = 0;
    BrokerID = '';
    InvestorID = '';
    ComTradeID = '';
    TradeID = '';
    reserve1 = '';
    HedgeFlag = '';
    Direction = '';
    TotalAmt = 0;
    Margin = 0.0;
    ExchMargin = 0.0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    LegID = 0;
    LegMultiple = 0;
    reserve2 = '';
    TradeGroupID = 0;
    InvestUnitID = '';
    InstrumentID = '';
    CombInstrumentID = '';
}
jtp.CThostFtdcInvestorPositionCombineDetailField=CThostFtdcInvestorPositionCombineDetailField;

class CThostFtdcParkedOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OrderRef = '';
    UserID = '';
    OrderPriceType = '';
    Direction = '';
    CombOffsetFlag = '';
    CombHedgeFlag = '';
    LimitPrice = 0.0;
    VolumeTotalOriginal = 0;
    TimeCondition = '';
    GTDDate = '';
    VolumeCondition = '';
    MinVolume = 0;
    ContingentCondition = '';
    StopPrice = 0.0;
    ForceCloseReason = '';
    IsAutoSuspend = 0;
    BusinessUnit = '';
    RequestID = 0;
    UserForceClose = 0;
    ExchangeID = '';
    ParkedOrderID = '';
    UserType = '';
    Status = '';
    ErrorID = 0;
    ErrorMsg = '';
    IsSwapOrder = 0;
    AccountID = '';
    CurrencyID = '';
    ClientID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcParkedOrderField=CThostFtdcParkedOrderField;

class CThostFtdcParkedOrderActionField{
    BrokerID = '';
    InvestorID = '';
    OrderActionRef = 0;
    OrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    OrderSysID = '';
    ActionFlag = '';
    LimitPrice = 0.0;
    VolumeChange = 0;
    UserID = '';
    reserve1 = '';
    ParkedOrderActionID = '';
    UserType = '';
    Status = '';
    ErrorID = 0;
    ErrorMsg = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcParkedOrderActionField=CThostFtdcParkedOrderActionField;

class CThostFtdcQryParkedOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryParkedOrderField=CThostFtdcQryParkedOrderField;

class CThostFtdcQryParkedOrderActionField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryParkedOrderActionField=CThostFtdcQryParkedOrderActionField;

class CThostFtdcRemoveParkedOrderField{
    BrokerID = '';
    InvestorID = '';
    ParkedOrderID = '';
    InvestUnitID = '';
}
jtp.CThostFtdcRemoveParkedOrderField=CThostFtdcRemoveParkedOrderField;

class CThostFtdcRemoveParkedOrderActionField{
    BrokerID = '';
    InvestorID = '';
    ParkedOrderActionID = '';
    InvestUnitID = '';
}
jtp.CThostFtdcRemoveParkedOrderActionField=CThostFtdcRemoveParkedOrderActionField;

class CThostFtdcInvestorWithdrawAlgorithmField{
    BrokerID = '';
    InvestorRange = '';
    InvestorID = '';
    UsingRatio = 0.0;
    CurrencyID = '';
    FundMortgageRatio = 0.0;
}
jtp.CThostFtdcInvestorWithdrawAlgorithmField=CThostFtdcInvestorWithdrawAlgorithmField;

class CThostFtdcQryInvestorPositionCombineDetailField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    ExchangeID = '';
    InvestUnitID = '';
    CombInstrumentID = '';
}
jtp.CThostFtdcQryInvestorPositionCombineDetailField=CThostFtdcQryInvestorPositionCombineDetailField;

class CThostFtdcMarketDataAveragePriceField{
    AveragePrice = 0.0;
}
jtp.CThostFtdcMarketDataAveragePriceField=CThostFtdcMarketDataAveragePriceField;

class CThostFtdcVerifyInvestorPasswordField{
    BrokerID = '';
    InvestorID = '';
    Password = '';
}
jtp.CThostFtdcVerifyInvestorPasswordField=CThostFtdcVerifyInvestorPasswordField;

class CThostFtdcUserIPField{
    BrokerID = '';
    UserID = '';
    reserve1 = '';
    reserve2 = '';
    MacAddress = '';
    IPAddress = '';
    IPMask = '';
}
jtp.CThostFtdcUserIPField=CThostFtdcUserIPField;

class CThostFtdcTradingNoticeInfoField{
    BrokerID = '';
    InvestorID = '';
    SendTime = '';
    FieldContent = '';
    SequenceSeries = 0;
    SequenceNo = 0;
    InvestUnitID = '';
}
jtp.CThostFtdcTradingNoticeInfoField=CThostFtdcTradingNoticeInfoField;

class CThostFtdcTradingNoticeField{
    BrokerID = '';
    InvestorRange = '';
    InvestorID = '';
    SequenceSeries = 0;
    UserID = '';
    SendTime = '';
    SequenceNo = 0;
    FieldContent = '';
    InvestUnitID = '';
}
jtp.CThostFtdcTradingNoticeField=CThostFtdcTradingNoticeField;

class CThostFtdcQryTradingNoticeField{
    BrokerID = '';
    InvestorID = '';
    InvestUnitID = '';
}
jtp.CThostFtdcQryTradingNoticeField=CThostFtdcQryTradingNoticeField;

class CThostFtdcQryErrOrderField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryErrOrderField=CThostFtdcQryErrOrderField;

class CThostFtdcErrOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OrderRef = '';
    UserID = '';
    OrderPriceType = '';
    Direction = '';
    CombOffsetFlag = '';
    CombHedgeFlag = '';
    LimitPrice = 0.0;
    VolumeTotalOriginal = 0;
    TimeCondition = '';
    GTDDate = '';
    VolumeCondition = '';
    MinVolume = 0;
    ContingentCondition = '';
    StopPrice = 0.0;
    ForceCloseReason = '';
    IsAutoSuspend = 0;
    BusinessUnit = '';
    RequestID = 0;
    UserForceClose = 0;
    ErrorID = 0;
    ErrorMsg = '';
    IsSwapOrder = 0;
    ExchangeID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    ClientID = '';
    reserve2 = '';
    MacAddress = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcErrOrderField=CThostFtdcErrOrderField;

class CThostFtdcErrorConditionalOrderField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    OrderRef = '';
    UserID = '';
    OrderPriceType = '';
    Direction = '';
    CombOffsetFlag = '';
    CombHedgeFlag = '';
    LimitPrice = 0.0;
    VolumeTotalOriginal = 0;
    TimeCondition = '';
    GTDDate = '';
    VolumeCondition = '';
    MinVolume = 0;
    ContingentCondition = '';
    StopPrice = 0.0;
    ForceCloseReason = '';
    IsAutoSuspend = 0;
    BusinessUnit = '';
    RequestID = 0;
    OrderLocalID = '';
    ExchangeID = '';
    ParticipantID = '';
    ClientID = '';
    reserve2 = '';
    TraderID = '';
    InstallID = 0;
    OrderSubmitStatus = '';
    NotifySequence = 0;
    TradingDay = '';
    SettlementID = 0;
    OrderSysID = '';
    OrderSource = '';
    OrderStatus = '';
    OrderType = '';
    VolumeTraded = 0;
    VolumeTotal = 0;
    InsertDate = '';
    InsertTime = '';
    ActiveTime = '';
    SuspendTime = '';
    UpdateTime = '';
    CancelTime = '';
    ActiveTraderID = '';
    ClearingPartID = '';
    SequenceNo = 0;
    FrontID = 0;
    SessionID = 0;
    UserProductInfo = '';
    StatusMsg = '';
    UserForceClose = 0;
    ActiveUserID = '';
    BrokerOrderSeq = 0;
    RelativeOrderSysID = '';
    ZCETotalTradedVolume = 0;
    ErrorID = 0;
    ErrorMsg = '';
    IsSwapOrder = 0;
    BranchID = '';
    InvestUnitID = '';
    AccountID = '';
    CurrencyID = '';
    reserve3 = '';
    MacAddress = '';
    InstrumentID = '';
    ExchangeInstID = '';
    IPAddress = '';
}
jtp.CThostFtdcErrorConditionalOrderField=CThostFtdcErrorConditionalOrderField;

class CThostFtdcQryErrOrderActionField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryErrOrderActionField=CThostFtdcQryErrOrderActionField;

class CThostFtdcErrOrderActionField{
    BrokerID = '';
    InvestorID = '';
    OrderActionRef = 0;
    OrderRef = '';
    RequestID = 0;
    FrontID = 0;
    SessionID = 0;
    ExchangeID = '';
    OrderSysID = '';
    ActionFlag = '';
    LimitPrice = 0.0;
    VolumeChange = 0;
    ActionDate = '';
    ActionTime = '';
    TraderID = '';
    InstallID = 0;
    OrderLocalID = '';
    ActionLocalID = '';
    ParticipantID = '';
    ClientID = '';
    BusinessUnit = '';
    OrderActionStatus = '';
    UserID = '';
    StatusMsg = '';
    reserve1 = '';
    BranchID = '';
    InvestUnitID = '';
    reserve2 = '';
    MacAddress = '';
    ErrorID = 0;
    ErrorMsg = '';
    InstrumentID = '';
    IPAddress = '';
}
jtp.CThostFtdcErrOrderActionField=CThostFtdcErrOrderActionField;

class CThostFtdcQryExchangeSequenceField{
    ExchangeID = '';
}
jtp.CThostFtdcQryExchangeSequenceField=CThostFtdcQryExchangeSequenceField;

class CThostFtdcExchangeSequenceField{
    ExchangeID = '';
    SequenceNo = 0;
    MarketStatus = '';
}
jtp.CThostFtdcExchangeSequenceField=CThostFtdcExchangeSequenceField;

class CThostFtdcQryMaxOrderVolumeWithPriceField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    Direction = '';
    OffsetFlag = '';
    HedgeFlag = '';
    MaxVolume = 0;
    Price = 0.0;
    ExchangeID = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryMaxOrderVolumeWithPriceField=CThostFtdcQryMaxOrderVolumeWithPriceField;

class CThostFtdcQryBrokerTradingParamsField{
    BrokerID = '';
    InvestorID = '';
    CurrencyID = '';
    AccountID = '';
}
jtp.CThostFtdcQryBrokerTradingParamsField=CThostFtdcQryBrokerTradingParamsField;

class CThostFtdcBrokerTradingParamsField{
    BrokerID = '';
    InvestorID = '';
    MarginPriceType = '';
    Algorithm = '';
    AvailIncludeCloseProfit = '';
    CurrencyID = '';
    OptionRoyaltyPriceType = '';
    AccountID = '';
}
jtp.CThostFtdcBrokerTradingParamsField=CThostFtdcBrokerTradingParamsField;

class CThostFtdcQryBrokerTradingAlgosField{
    BrokerID = '';
    ExchangeID = '';
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryBrokerTradingAlgosField=CThostFtdcQryBrokerTradingAlgosField;

class CThostFtdcBrokerTradingAlgosField{
    BrokerID = '';
    ExchangeID = '';
    reserve1 = '';
    HandlePositionAlgoID = '';
    FindMarginRateAlgoID = '';
    HandleTradingAccountAlgoID = '';
    InstrumentID = '';
}
jtp.CThostFtdcBrokerTradingAlgosField=CThostFtdcBrokerTradingAlgosField;

class CThostFtdcQueryBrokerDepositField{
    BrokerID = '';
    ExchangeID = '';
}
jtp.CThostFtdcQueryBrokerDepositField=CThostFtdcQueryBrokerDepositField;

class CThostFtdcBrokerDepositField{
    TradingDay = '';
    BrokerID = '';
    ParticipantID = '';
    ExchangeID = '';
    PreBalance = 0.0;
    CurrMargin = 0.0;
    CloseProfit = 0.0;
    Balance = 0.0;
    Deposit = 0.0;
    Withdraw = 0.0;
    Available = 0.0;
    Reserve = 0.0;
    FrozenMargin = 0.0;
}
jtp.CThostFtdcBrokerDepositField=CThostFtdcBrokerDepositField;

class CThostFtdcQryCFMMCBrokerKeyField{
    BrokerID = '';
}
jtp.CThostFtdcQryCFMMCBrokerKeyField=CThostFtdcQryCFMMCBrokerKeyField;

class CThostFtdcCFMMCBrokerKeyField{
    BrokerID = '';
    ParticipantID = '';
    CreateDate = '';
    CreateTime = '';
    KeyID = 0;
    CurrentKey = '';
    KeyKind = '';
}
jtp.CThostFtdcCFMMCBrokerKeyField=CThostFtdcCFMMCBrokerKeyField;

class CThostFtdcCFMMCTradingAccountKeyField{
    BrokerID = '';
    ParticipantID = '';
    AccountID = '';
    KeyID = 0;
    CurrentKey = '';
}
jtp.CThostFtdcCFMMCTradingAccountKeyField=CThostFtdcCFMMCTradingAccountKeyField;

class CThostFtdcQryCFMMCTradingAccountKeyField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQryCFMMCTradingAccountKeyField=CThostFtdcQryCFMMCTradingAccountKeyField;

class CThostFtdcBrokerUserOTPParamField{
    BrokerID = '';
    UserID = '';
    OTPVendorsID = '';
    SerialNumber = '';
    AuthKey = '';
    LastDrift = 0;
    LastSuccess = 0;
    OTPType = '';
}
jtp.CThostFtdcBrokerUserOTPParamField=CThostFtdcBrokerUserOTPParamField;

class CThostFtdcManualSyncBrokerUserOTPField{
    BrokerID = '';
    UserID = '';
    OTPType = '';
    FirstOTP = '';
    SecondOTP = '';
}
jtp.CThostFtdcManualSyncBrokerUserOTPField=CThostFtdcManualSyncBrokerUserOTPField;

class CThostFtdcCommRateModelField{
    BrokerID = '';
    CommModelID = '';
    CommModelName = '';
}
jtp.CThostFtdcCommRateModelField=CThostFtdcCommRateModelField;

class CThostFtdcQryCommRateModelField{
    BrokerID = '';
    CommModelID = '';
}
jtp.CThostFtdcQryCommRateModelField=CThostFtdcQryCommRateModelField;

class CThostFtdcMarginModelField{
    BrokerID = '';
    MarginModelID = '';
    MarginModelName = '';
}
jtp.CThostFtdcMarginModelField=CThostFtdcMarginModelField;

class CThostFtdcQryMarginModelField{
    BrokerID = '';
    MarginModelID = '';
}
jtp.CThostFtdcQryMarginModelField=CThostFtdcQryMarginModelField;

class CThostFtdcEWarrantOffsetField{
    TradingDay = '';
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
    reserve1 = '';
    Direction = '';
    HedgeFlag = '';
    Volume = 0;
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcEWarrantOffsetField=CThostFtdcEWarrantOffsetField;

class CThostFtdcQryEWarrantOffsetField{
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
    reserve1 = '';
    InvestUnitID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryEWarrantOffsetField=CThostFtdcQryEWarrantOffsetField;

class CThostFtdcQryInvestorProductGroupMarginField{
    BrokerID = '';
    InvestorID = '';
    reserve1 = '';
    HedgeFlag = '';
    ExchangeID = '';
    InvestUnitID = '';
    ProductGroupID = '';
}
jtp.CThostFtdcQryInvestorProductGroupMarginField=CThostFtdcQryInvestorProductGroupMarginField;

class CThostFtdcInvestorProductGroupMarginField{
    reserve1 = '';
    BrokerID = '';
    InvestorID = '';
    TradingDay = '';
    SettlementID = 0;
    FrozenMargin = 0.0;
    LongFrozenMargin = 0.0;
    ShortFrozenMargin = 0.0;
    UseMargin = 0.0;
    LongUseMargin = 0.0;
    ShortUseMargin = 0.0;
    ExchMargin = 0.0;
    LongExchMargin = 0.0;
    ShortExchMargin = 0.0;
    CloseProfit = 0.0;
    FrozenCommission = 0.0;
    Commission = 0.0;
    FrozenCash = 0.0;
    CashIn = 0.0;
    PositionProfit = 0.0;
    OffsetAmount = 0.0;
    LongOffsetAmount = 0.0;
    ShortOffsetAmount = 0.0;
    ExchOffsetAmount = 0.0;
    LongExchOffsetAmount = 0.0;
    ShortExchOffsetAmount = 0.0;
    HedgeFlag = '';
    ExchangeID = '';
    InvestUnitID = '';
    ProductGroupID = '';
}
jtp.CThostFtdcInvestorProductGroupMarginField=CThostFtdcInvestorProductGroupMarginField;

class CThostFtdcQueryCFMMCTradingAccountTokenField{
    BrokerID = '';
    InvestorID = '';
    InvestUnitID = '';
}
jtp.CThostFtdcQueryCFMMCTradingAccountTokenField=CThostFtdcQueryCFMMCTradingAccountTokenField;

class CThostFtdcCFMMCTradingAccountTokenField{
    BrokerID = '';
    ParticipantID = '';
    AccountID = '';
    KeyID = 0;
    Token = '';
}
jtp.CThostFtdcCFMMCTradingAccountTokenField=CThostFtdcCFMMCTradingAccountTokenField;

class CThostFtdcQryProductGroupField{
    reserve1 = '';
    ExchangeID = '';
    ProductID = '';
}
jtp.CThostFtdcQryProductGroupField=CThostFtdcQryProductGroupField;

class CThostFtdcProductGroupField{
    reserve1 = '';
    ExchangeID = '';
    reserve2 = '';
    ProductID = '';
    ProductGroupID = '';
}
jtp.CThostFtdcProductGroupField=CThostFtdcProductGroupField;

class CThostFtdcBulletinField{
    ExchangeID = '';
    TradingDay = '';
    BulletinID = 0;
    SequenceNo = 0;
    NewsType = '';
    NewsUrgency = '';
    SendTime = '';
    Abstract = '';
    ComeFrom = '';
    Content = '';
    URLLink = '';
    MarketID = '';
}
jtp.CThostFtdcBulletinField=CThostFtdcBulletinField;

class CThostFtdcQryBulletinField{
    ExchangeID = '';
    BulletinID = 0;
    SequenceNo = 0;
    NewsType = '';
    NewsUrgency = '';
}
jtp.CThostFtdcQryBulletinField=CThostFtdcQryBulletinField;

class CThostFtdcMulticastInstrumentField{
    TopicID = 0;
    reserve1 = '';
    InstrumentNo = 0;
    CodePrice = 0.0;
    VolumeMultiple = 0;
    PriceTick = 0.0;
    InstrumentID = '';
}
jtp.CThostFtdcMulticastInstrumentField=CThostFtdcMulticastInstrumentField;

class CThostFtdcQryMulticastInstrumentField{
    TopicID = 0;
    reserve1 = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryMulticastInstrumentField=CThostFtdcQryMulticastInstrumentField;

class CThostFtdcAppIDAuthAssignField{
    BrokerID = '';
    AppID = '';
    DRIdentityID = 0;
}
jtp.CThostFtdcAppIDAuthAssignField=CThostFtdcAppIDAuthAssignField;

class CThostFtdcReqOpenAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    CashExchangeCode = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    TID = 0;
    UserID = '';
    LongCustomerName = '';
}
jtp.CThostFtdcReqOpenAccountField=CThostFtdcReqOpenAccountField;

class CThostFtdcReqCancelAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    CashExchangeCode = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    TID = 0;
    UserID = '';
    LongCustomerName = '';
}
jtp.CThostFtdcReqCancelAccountField=CThostFtdcReqCancelAccountField;

class CThostFtdcReqChangeAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    NewBankAccount = '';
    NewBankPassWord = '';
    AccountID = '';
    Password = '';
    BankAccType = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    BrokerIDByBank = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    TID = 0;
    Digest = '';
    LongCustomerName = '';
}
jtp.CThostFtdcReqChangeAccountField=CThostFtdcReqChangeAccountField;

class CThostFtdcReqTransferField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    FutureSerial = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    FutureFetchAmount = 0.0;
    FeePayFlag = '';
    CustFee = 0.0;
    BrokerFee = 0.0;
    Message = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    TransferStatus = '';
    LongCustomerName = '';
}
jtp.CThostFtdcReqTransferField=CThostFtdcReqTransferField;

class CThostFtdcRspTransferField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    FutureSerial = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    FutureFetchAmount = 0.0;
    FeePayFlag = '';
    CustFee = 0.0;
    BrokerFee = 0.0;
    Message = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    TransferStatus = '';
    ErrorID = 0;
    ErrorMsg = '';
    LongCustomerName = '';
}
jtp.CThostFtdcRspTransferField=CThostFtdcRspTransferField;

class CThostFtdcReqRepealField{
    RepealTimeInterval = 0;
    RepealedTimes = 0;
    BankRepealFlag = '';
    BrokerRepealFlag = '';
    PlateRepealSerial = 0;
    BankRepealSerial = '';
    FutureRepealSerial = 0;
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    FutureSerial = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    FutureFetchAmount = 0.0;
    FeePayFlag = '';
    CustFee = 0.0;
    BrokerFee = 0.0;
    Message = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    TransferStatus = '';
    LongCustomerName = '';
}
jtp.CThostFtdcReqRepealField=CThostFtdcReqRepealField;

class CThostFtdcRspRepealField{
    RepealTimeInterval = 0;
    RepealedTimes = 0;
    BankRepealFlag = '';
    BrokerRepealFlag = '';
    PlateRepealSerial = 0;
    BankRepealSerial = '';
    FutureRepealSerial = 0;
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    FutureSerial = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    FutureFetchAmount = 0.0;
    FeePayFlag = '';
    CustFee = 0.0;
    BrokerFee = 0.0;
    Message = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    TransferStatus = '';
    ErrorID = 0;
    ErrorMsg = '';
    LongCustomerName = '';
}
jtp.CThostFtdcRspRepealField=CThostFtdcRspRepealField;

class CThostFtdcReqQueryAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    FutureSerial = 0;
    InstallID = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    LongCustomerName = '';
}
jtp.CThostFtdcReqQueryAccountField=CThostFtdcReqQueryAccountField;

class CThostFtdcRspQueryAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    FutureSerial = 0;
    InstallID = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    BankUseAmount = 0.0;
    BankFetchAmount = 0.0;
    LongCustomerName = '';
}
jtp.CThostFtdcRspQueryAccountField=CThostFtdcRspQueryAccountField;

class CThostFtdcFutureSignIOField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Digest = '';
    CurrencyID = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
}
jtp.CThostFtdcFutureSignIOField=CThostFtdcFutureSignIOField;

class CThostFtdcRspFutureSignInField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Digest = '';
    CurrencyID = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    ErrorID = 0;
    ErrorMsg = '';
    PinKey = '';
    MacKey = '';
}
jtp.CThostFtdcRspFutureSignInField=CThostFtdcRspFutureSignInField;

class CThostFtdcReqFutureSignOutField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Digest = '';
    CurrencyID = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
}
jtp.CThostFtdcReqFutureSignOutField=CThostFtdcReqFutureSignOutField;

class CThostFtdcRspFutureSignOutField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Digest = '';
    CurrencyID = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcRspFutureSignOutField=CThostFtdcRspFutureSignOutField;

class CThostFtdcReqQueryTradeResultBySerialField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    Reference = 0;
    RefrenceIssureType = '';
    RefrenceIssure = '';
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    Digest = '';
    LongCustomerName = '';
}
jtp.CThostFtdcReqQueryTradeResultBySerialField=CThostFtdcReqQueryTradeResultBySerialField;

class CThostFtdcRspQueryTradeResultBySerialField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    ErrorID = 0;
    ErrorMsg = '';
    Reference = 0;
    RefrenceIssureType = '';
    RefrenceIssure = '';
    OriginReturnCode = '';
    OriginDescrInfoForReturnCode = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    Digest = '';
}
jtp.CThostFtdcRspQueryTradeResultBySerialField=CThostFtdcRspQueryTradeResultBySerialField;

class CThostFtdcReqDayEndFileReadyField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    FileBusinessCode = '';
    Digest = '';
}
jtp.CThostFtdcReqDayEndFileReadyField=CThostFtdcReqDayEndFileReadyField;

class CThostFtdcReturnResultField{
    ReturnCode = '';
    DescrInfoForReturnCode = '';
}
jtp.CThostFtdcReturnResultField=CThostFtdcReturnResultField;

class CThostFtdcVerifyFuturePasswordField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    AccountID = '';
    Password = '';
    BankAccount = '';
    BankPassWord = '';
    InstallID = 0;
    TID = 0;
    CurrencyID = '';
}
jtp.CThostFtdcVerifyFuturePasswordField=CThostFtdcVerifyFuturePasswordField;

class CThostFtdcVerifyCustInfoField{
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    LongCustomerName = '';
}
jtp.CThostFtdcVerifyCustInfoField=CThostFtdcVerifyCustInfoField;

class CThostFtdcVerifyFuturePasswordAndCustInfoField{
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    AccountID = '';
    Password = '';
    CurrencyID = '';
    LongCustomerName = '';
}
jtp.CThostFtdcVerifyFuturePasswordAndCustInfoField=CThostFtdcVerifyFuturePasswordAndCustInfoField;

class CThostFtdcDepositResultInformField{
    DepositSeqNo = '';
    BrokerID = '';
    InvestorID = '';
    Deposit = 0.0;
    RequestID = 0;
    ReturnCode = '';
    DescrInfoForReturnCode = '';
}
jtp.CThostFtdcDepositResultInformField=CThostFtdcDepositResultInformField;

class CThostFtdcReqSyncKeyField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Message = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
}
jtp.CThostFtdcReqSyncKeyField=CThostFtdcReqSyncKeyField;

class CThostFtdcRspSyncKeyField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Message = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcRspSyncKeyField=CThostFtdcRspSyncKeyField;

class CThostFtdcNotifyQueryAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustType = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    FutureSerial = 0;
    InstallID = 0;
    UserID = '';
    VerifyCertNoFlag = '';
    CurrencyID = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    BankUseAmount = 0.0;
    BankFetchAmount = 0.0;
    ErrorID = 0;
    ErrorMsg = '';
    LongCustomerName = '';
}
jtp.CThostFtdcNotifyQueryAccountField=CThostFtdcNotifyQueryAccountField;

class CThostFtdcTransferSerialField{
    PlateSerial = 0;
    TradeDate = '';
    TradingDay = '';
    TradeTime = '';
    TradeCode = '';
    SessionID = 0;
    BankID = '';
    BankBranchID = '';
    BankAccType = '';
    BankAccount = '';
    BankSerial = '';
    BrokerID = '';
    BrokerBranchID = '';
    FutureAccType = '';
    AccountID = '';
    InvestorID = '';
    FutureSerial = 0;
    IdCardType = '';
    IdentifiedCardNo = '';
    CurrencyID = '';
    TradeAmount = 0.0;
    CustFee = 0.0;
    BrokerFee = 0.0;
    AvailabilityFlag = '';
    OperatorCode = '';
    BankNewAccount = '';
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcTransferSerialField=CThostFtdcTransferSerialField;

class CThostFtdcQryTransferSerialField{
    BrokerID = '';
    AccountID = '';
    BankID = '';
    CurrencyID = '';
}
jtp.CThostFtdcQryTransferSerialField=CThostFtdcQryTransferSerialField;

class CThostFtdcNotifyFutureSignInField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Digest = '';
    CurrencyID = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    ErrorID = 0;
    ErrorMsg = '';
    PinKey = '';
    MacKey = '';
}
jtp.CThostFtdcNotifyFutureSignInField=CThostFtdcNotifyFutureSignInField;

class CThostFtdcNotifyFutureSignOutField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Digest = '';
    CurrencyID = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcNotifyFutureSignOutField=CThostFtdcNotifyFutureSignOutField;

class CThostFtdcNotifySyncKeyField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    InstallID = 0;
    UserID = '';
    Message = '';
    DeviceID = '';
    BrokerIDByBank = '';
    OperNo = '';
    RequestID = 0;
    TID = 0;
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcNotifySyncKeyField=CThostFtdcNotifySyncKeyField;

class CThostFtdcQryAccountregisterField{
    BrokerID = '';
    AccountID = '';
    BankID = '';
    BankBranchID = '';
    CurrencyID = '';
}
jtp.CThostFtdcQryAccountregisterField=CThostFtdcQryAccountregisterField;

class CThostFtdcAccountregisterField{
    TradeDay = '';
    BankID = '';
    BankBranchID = '';
    BankAccount = '';
    BrokerID = '';
    BrokerBranchID = '';
    AccountID = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    CustomerName = '';
    CurrencyID = '';
    OpenOrDestroy = '';
    RegDate = '';
    OutDate = '';
    TID = 0;
    CustType = '';
    BankAccType = '';
    LongCustomerName = '';
}
jtp.CThostFtdcAccountregisterField=CThostFtdcAccountregisterField;

class CThostFtdcOpenAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    CashExchangeCode = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    TID = 0;
    UserID = '';
    ErrorID = 0;
    ErrorMsg = '';
    LongCustomerName = '';
}
jtp.CThostFtdcOpenAccountField=CThostFtdcOpenAccountField;

class CThostFtdcCancelAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    AccountID = '';
    Password = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    CashExchangeCode = '';
    Digest = '';
    BankAccType = '';
    DeviceID = '';
    BankSecuAccType = '';
    BrokerIDByBank = '';
    BankSecuAcc = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    OperNo = '';
    TID = 0;
    UserID = '';
    ErrorID = 0;
    ErrorMsg = '';
    LongCustomerName = '';
}
jtp.CThostFtdcCancelAccountField=CThostFtdcCancelAccountField;

class CThostFtdcChangeAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    NewBankAccount = '';
    NewBankPassWord = '';
    AccountID = '';
    Password = '';
    BankAccType = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    BrokerIDByBank = '';
    BankPwdFlag = '';
    SecuPwdFlag = '';
    TID = 0;
    Digest = '';
    ErrorID = 0;
    ErrorMsg = '';
    LongCustomerName = '';
}
jtp.CThostFtdcChangeAccountField=CThostFtdcChangeAccountField;

class CThostFtdcSecAgentACIDMapField{
    BrokerID = '';
    UserID = '';
    AccountID = '';
    CurrencyID = '';
    BrokerSecAgentID = '';
}
jtp.CThostFtdcSecAgentACIDMapField=CThostFtdcSecAgentACIDMapField;

class CThostFtdcQrySecAgentACIDMapField{
    BrokerID = '';
    UserID = '';
    AccountID = '';
    CurrencyID = '';
}
jtp.CThostFtdcQrySecAgentACIDMapField=CThostFtdcQrySecAgentACIDMapField;

class CThostFtdcUserRightsAssignField{
    BrokerID = '';
    UserID = '';
    DRIdentityID = 0;
}
jtp.CThostFtdcUserRightsAssignField=CThostFtdcUserRightsAssignField;

class CThostFtdcBrokerUserRightAssignField{
    BrokerID = '';
    DRIdentityID = 0;
    Tradeable = 0;
}
jtp.CThostFtdcBrokerUserRightAssignField=CThostFtdcBrokerUserRightAssignField;

class CThostFtdcDRTransferField{
    OrigDRIdentityID = 0;
    DestDRIdentityID = 0;
    OrigBrokerID = '';
    DestBrokerID = '';
}
jtp.CThostFtdcDRTransferField=CThostFtdcDRTransferField;

class CThostFtdcFensUserInfoField{
    BrokerID = '';
    UserID = '';
    LoginMode = '';
}
jtp.CThostFtdcFensUserInfoField=CThostFtdcFensUserInfoField;

class CThostFtdcCurrTransferIdentityField{
    IdentityID = 0;
}
jtp.CThostFtdcCurrTransferIdentityField=CThostFtdcCurrTransferIdentityField;

class CThostFtdcLoginForbiddenUserField{
    BrokerID = '';
    UserID = '';
    reserve1 = '';
    IPAddress = '';
}
jtp.CThostFtdcLoginForbiddenUserField=CThostFtdcLoginForbiddenUserField;

class CThostFtdcQryLoginForbiddenUserField{
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcQryLoginForbiddenUserField=CThostFtdcQryLoginForbiddenUserField;

class CThostFtdcTradingAccountReserveField{
    BrokerID = '';
    AccountID = '';
    Reserve = 0.0;
    CurrencyID = '';
}
jtp.CThostFtdcTradingAccountReserveField=CThostFtdcTradingAccountReserveField;

class CThostFtdcQryLoginForbiddenIPField{
    reserve1 = '';
    IPAddress = '';
}
jtp.CThostFtdcQryLoginForbiddenIPField=CThostFtdcQryLoginForbiddenIPField;

class CThostFtdcQryIPListField{
    reserve1 = '';
    IPAddress = '';
}
jtp.CThostFtdcQryIPListField=CThostFtdcQryIPListField;

class CThostFtdcQryUserRightsAssignField{
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcQryUserRightsAssignField=CThostFtdcQryUserRightsAssignField;

class CThostFtdcReserveOpenAccountConfirmField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    Digest = '';
    BankAccType = '';
    BrokerIDByBank = '';
    TID = 0;
    AccountID = '';
    Password = '';
    BankReserveOpenSeq = '';
    BookDate = '';
    BookPsw = '';
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcReserveOpenAccountConfirmField=CThostFtdcReserveOpenAccountConfirmField;

class CThostFtdcReserveOpenAccountField{
    TradeCode = '';
    BankID = '';
    BankBranchID = '';
    BrokerID = '';
    BrokerBranchID = '';
    TradeDate = '';
    TradeTime = '';
    BankSerial = '';
    TradingDay = '';
    PlateSerial = 0;
    LastFragment = '';
    SessionID = 0;
    CustomerName = '';
    IdCardType = '';
    IdentifiedCardNo = '';
    Gender = '';
    CountryCode = '';
    CustType = '';
    Address = '';
    ZipCode = '';
    Telephone = '';
    MobilePhone = '';
    Fax = '';
    EMail = '';
    MoneyAccountStatus = '';
    BankAccount = '';
    BankPassWord = '';
    InstallID = 0;
    VerifyCertNoFlag = '';
    CurrencyID = '';
    Digest = '';
    BankAccType = '';
    BrokerIDByBank = '';
    TID = 0;
    ReserveOpenAccStas = '';
    ErrorID = 0;
    ErrorMsg = '';
}
jtp.CThostFtdcReserveOpenAccountField=CThostFtdcReserveOpenAccountField;

class CThostFtdcAccountPropertyField{
    BrokerID = '';
    AccountID = '';
    BankID = '';
    BankAccount = '';
    OpenName = '';
    OpenBank = '';
    IsActive = 0;
    AccountSourceType = '';
    OpenDate = '';
    CancelDate = '';
    OperatorID = '';
    OperateDate = '';
    OperateTime = '';
    CurrencyID = '';
}
jtp.CThostFtdcAccountPropertyField=CThostFtdcAccountPropertyField;

class CThostFtdcQryCurrDRIdentityField{
    DRIdentityID = 0;
}
jtp.CThostFtdcQryCurrDRIdentityField=CThostFtdcQryCurrDRIdentityField;

class CThostFtdcCurrDRIdentityField{
    DRIdentityID = 0;
}
jtp.CThostFtdcCurrDRIdentityField=CThostFtdcCurrDRIdentityField;

class CThostFtdcQrySecAgentCheckModeField{
    BrokerID = '';
    InvestorID = '';
}
jtp.CThostFtdcQrySecAgentCheckModeField=CThostFtdcQrySecAgentCheckModeField;

class CThostFtdcQrySecAgentTradeInfoField{
    BrokerID = '';
    BrokerSecAgentID = '';
}
jtp.CThostFtdcQrySecAgentTradeInfoField=CThostFtdcQrySecAgentTradeInfoField;

class CThostFtdcReqUserAuthMethodField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcReqUserAuthMethodField=CThostFtdcReqUserAuthMethodField;

class CThostFtdcRspUserAuthMethodField{
    UsableAuthMethod = 0;
}
jtp.CThostFtdcRspUserAuthMethodField=CThostFtdcRspUserAuthMethodField;

class CThostFtdcReqGenUserCaptchaField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcReqGenUserCaptchaField=CThostFtdcReqGenUserCaptchaField;

class CThostFtdcRspGenUserCaptchaField{
    BrokerID = '';
    UserID = '';
    CaptchaInfoLen = 0;
    CaptchaInfo = '';
}
jtp.CThostFtdcRspGenUserCaptchaField=CThostFtdcRspGenUserCaptchaField;

class CThostFtdcReqGenUserTextField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
}
jtp.CThostFtdcReqGenUserTextField=CThostFtdcReqGenUserTextField;

class CThostFtdcRspGenUserTextField{
    UserTextSeq = 0;
}
jtp.CThostFtdcRspGenUserTextField=CThostFtdcRspGenUserTextField;

class CThostFtdcReqUserLoginWithCaptchaField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
    Password = '';
    UserProductInfo = '';
    InterfaceProductInfo = '';
    ProtocolInfo = '';
    MacAddress = '';
    reserve1 = '';
    LoginRemark = '';
    Captcha = '';
    ClientIPPort = 0;
    ClientIPAddress = '';
}
jtp.CThostFtdcReqUserLoginWithCaptchaField=CThostFtdcReqUserLoginWithCaptchaField;

class CThostFtdcReqUserLoginWithTextField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
    Password = '';
    UserProductInfo = '';
    InterfaceProductInfo = '';
    ProtocolInfo = '';
    MacAddress = '';
    reserve1 = '';
    LoginRemark = '';
    Text = '';
    ClientIPPort = 0;
    ClientIPAddress = '';
}
jtp.CThostFtdcReqUserLoginWithTextField=CThostFtdcReqUserLoginWithTextField;

class CThostFtdcReqUserLoginWithOTPField{
    TradingDay = '';
    BrokerID = '';
    UserID = '';
    Password = '';
    UserProductInfo = '';
    InterfaceProductInfo = '';
    ProtocolInfo = '';
    MacAddress = '';
    reserve1 = '';
    LoginRemark = '';
    OTPPassword = '';
    ClientIPPort = 0;
    ClientIPAddress = '';
}
jtp.CThostFtdcReqUserLoginWithOTPField=CThostFtdcReqUserLoginWithOTPField;

class CThostFtdcReqApiHandshakeField{
    CryptoKeyVersion = '';
}
jtp.CThostFtdcReqApiHandshakeField=CThostFtdcReqApiHandshakeField;

class CThostFtdcRspApiHandshakeField{
    FrontHandshakeDataLen = 0;
    FrontHandshakeData = '';
    IsApiAuthEnabled = 0;
}
jtp.CThostFtdcRspApiHandshakeField=CThostFtdcRspApiHandshakeField;

class CThostFtdcReqVerifyApiKeyField{
    ApiHandshakeDataLen = 0;
    ApiHandshakeData = '';
}
jtp.CThostFtdcReqVerifyApiKeyField=CThostFtdcReqVerifyApiKeyField;

class CThostFtdcDepartmentUserField{
    BrokerID = '';
    UserID = '';
    InvestorRange = '';
    InvestorID = '';
}
jtp.CThostFtdcDepartmentUserField=CThostFtdcDepartmentUserField;

class CThostFtdcQueryFreqField{
    QueryFreq = 0;
}
jtp.CThostFtdcQueryFreqField=CThostFtdcQueryFreqField;

class CThostFtdcAuthForbiddenIPField{
    IPAddress = '';
}
jtp.CThostFtdcAuthForbiddenIPField=CThostFtdcAuthForbiddenIPField;

class CThostFtdcQryAuthForbiddenIPField{
    IPAddress = '';
}
jtp.CThostFtdcQryAuthForbiddenIPField=CThostFtdcQryAuthForbiddenIPField;

class CThostFtdcSyncDelaySwapFrozenField{
    DelaySwapSeqNo = '';
    BrokerID = '';
    InvestorID = '';
    FromCurrencyID = '';
    FromRemainSwap = 0.0;
    IsManualSwap = 0;
}
jtp.CThostFtdcSyncDelaySwapFrozenField=CThostFtdcSyncDelaySwapFrozenField;

class CThostFtdcUserSystemInfoField{
    BrokerID = '';
    UserID = '';
    ClientSystemInfoLen = 0;
    ClientSystemInfo = '';
    reserve1 = '';
    ClientIPPort = 0;
    ClientLoginTime = '';
    ClientAppID = '';
    ClientPublicIP = '';
    ClientLoginRemark = '';
}
jtp.CThostFtdcUserSystemInfoField=CThostFtdcUserSystemInfoField;

class CThostFtdcAuthUserIDField{
    BrokerID = '';
    AppID = '';
    UserID = '';
    AuthType = '';
}
jtp.CThostFtdcAuthUserIDField=CThostFtdcAuthUserIDField;

class CThostFtdcAuthIPField{
    BrokerID = '';
    AppID = '';
    IPAddress = '';
}
jtp.CThostFtdcAuthIPField=CThostFtdcAuthIPField;

class CThostFtdcQryClassifiedInstrumentField{
    InstrumentID = '';
    ExchangeID = '';
    ExchangeInstID = '';
    ProductID = '';
    TradingType = '';
    ClassType = '';
}
jtp.CThostFtdcQryClassifiedInstrumentField=CThostFtdcQryClassifiedInstrumentField;

class CThostFtdcQryCombPromotionParamField{
    ExchangeID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryCombPromotionParamField=CThostFtdcQryCombPromotionParamField;

class CThostFtdcCombPromotionParamField{
    ExchangeID = '';
    InstrumentID = '';
    CombHedgeFlag = '';
    Xparameter = 0.0;
}
jtp.CThostFtdcCombPromotionParamField=CThostFtdcCombPromotionParamField;

class CThostFtdcQryRiskSettleInvstPositionField{
    BrokerID = '';
    InvestorID = '';
    InstrumentID = '';
}
jtp.CThostFtdcQryRiskSettleInvstPositionField=CThostFtdcQryRiskSettleInvstPositionField;

class CThostFtdcQryRiskSettleProductStatusField{
    ProductID = '';
}
jtp.CThostFtdcQryRiskSettleProductStatusField=CThostFtdcQryRiskSettleProductStatusField;

class CThostFtdcRiskSettleInvstPositionField{
    InstrumentID = '';
    BrokerID = '';
    InvestorID = '';
    PosiDirection = '';
    HedgeFlag = '';
    PositionDate = '';
    YdPosition = 0;
    Position = 0;
    LongFrozen = 0;
    ShortFrozen = 0;
    LongFrozenAmount = 0.0;
    ShortFrozenAmount = 0.0;
    OpenVolume = 0;
    CloseVolume = 0;
    OpenAmount = 0.0;
    CloseAmount = 0.0;
    PositionCost = 0.0;
    PreMargin = 0.0;
    UseMargin = 0.0;
    FrozenMargin = 0.0;
    FrozenCash = 0.0;
    FrozenCommission = 0.0;
    CashIn = 0.0;
    Commission = 0.0;
    CloseProfit = 0.0;
    PositionProfit = 0.0;
    PreSettlementPrice = 0.0;
    SettlementPrice = 0.0;
    TradingDay = '';
    SettlementID = 0;
    OpenCost = 0.0;
    ExchangeMargin = 0.0;
    CombPosition = 0;
    CombLongFrozen = 0;
    CombShortFrozen = 0;
    CloseProfitByDate = 0.0;
    CloseProfitByTrade = 0.0;
    TodayPosition = 0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    StrikeFrozen = 0;
    StrikeFrozenAmount = 0.0;
    AbandonFrozen = 0;
    ExchangeID = '';
    YdStrikeFrozen = 0;
    InvestUnitID = '';
    PositionCostOffset = 0.0;
    TasPosition = 0;
    TasPositionCost = 0.0;
}
jtp.CThostFtdcRiskSettleInvstPositionField=CThostFtdcRiskSettleInvstPositionField;

class CThostFtdcRiskSettleProductStatusField{
    ExchangeID = '';
    ProductID = '';
    ProductStatus = '';
}
jtp.CThostFtdcRiskSettleProductStatusField=CThostFtdcRiskSettleProductStatusField;

class CThostFtdcSyncDeltaInfoField{
    SyncDeltaSequenceNo = 0;
    SyncDeltaStatus = '';
    SyncDescription = '';
    IsOnlyTrdDelta = 0;
}
jtp.CThostFtdcSyncDeltaInfoField=CThostFtdcSyncDeltaInfoField;

class CThostFtdcSyncDeltaProductStatusField{
    SyncDeltaSequenceNo = 0;
    ExchangeID = '';
    ProductID = '';
    ProductStatus = '';
}
jtp.CThostFtdcSyncDeltaProductStatusField=CThostFtdcSyncDeltaProductStatusField;

class CThostFtdcSyncDeltaInvstPosDtlField{
    InstrumentID = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    Direction = '';
    OpenDate = '';
    TradeID = '';
    Volume = 0;
    OpenPrice = 0.0;
    TradingDay = '';
    SettlementID = 0;
    TradeType = '';
    CombInstrumentID = '';
    ExchangeID = '';
    CloseProfitByDate = 0.0;
    CloseProfitByTrade = 0.0;
    PositionProfitByDate = 0.0;
    PositionProfitByTrade = 0.0;
    Margin = 0.0;
    ExchMargin = 0.0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    LastSettlementPrice = 0.0;
    SettlementPrice = 0.0;
    CloseVolume = 0;
    CloseAmount = 0.0;
    TimeFirstVolume = 0;
    SpecPosiType = '';
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaInvstPosDtlField=CThostFtdcSyncDeltaInvstPosDtlField;

class CThostFtdcSyncDeltaInvstPosCombDtlField{
    TradingDay = '';
    OpenDate = '';
    ExchangeID = '';
    SettlementID = 0;
    BrokerID = '';
    InvestorID = '';
    ComTradeID = '';
    TradeID = '';
    InstrumentID = '';
    HedgeFlag = '';
    Direction = '';
    TotalAmt = 0;
    Margin = 0.0;
    ExchMargin = 0.0;
    MarginRateByMoney = 0.0;
    MarginRateByVolume = 0.0;
    LegID = 0;
    LegMultiple = 0;
    TradeGroupID = 0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaInvstPosCombDtlField=CThostFtdcSyncDeltaInvstPosCombDtlField;

class CThostFtdcSyncDeltaTradingAccountField{
    BrokerID = '';
    AccountID = '';
    PreMortgage = 0.0;
    PreCredit = 0.0;
    PreDeposit = 0.0;
    PreBalance = 0.0;
    PreMargin = 0.0;
    InterestBase = 0.0;
    Interest = 0.0;
    Deposit = 0.0;
    Withdraw = 0.0;
    FrozenMargin = 0.0;
    FrozenCash = 0.0;
    FrozenCommission = 0.0;
    CurrMargin = 0.0;
    CashIn = 0.0;
    Commission = 0.0;
    CloseProfit = 0.0;
    PositionProfit = 0.0;
    Balance = 0.0;
    Available = 0.0;
    WithdrawQuota = 0.0;
    Reserve = 0.0;
    TradingDay = '';
    SettlementID = 0;
    Credit = 0.0;
    Mortgage = 0.0;
    ExchangeMargin = 0.0;
    DeliveryMargin = 0.0;
    ExchangeDeliveryMargin = 0.0;
    ReserveBalance = 0.0;
    CurrencyID = '';
    PreFundMortgageIn = 0.0;
    PreFundMortgageOut = 0.0;
    FundMortgageIn = 0.0;
    FundMortgageOut = 0.0;
    FundMortgageAvailable = 0.0;
    MortgageableFund = 0.0;
    SpecProductMargin = 0.0;
    SpecProductFrozenMargin = 0.0;
    SpecProductCommission = 0.0;
    SpecProductFrozenCommission = 0.0;
    SpecProductPositionProfit = 0.0;
    SpecProductCloseProfit = 0.0;
    SpecProductPositionProfitByAlg = 0.0;
    SpecProductExchangeMargin = 0.0;
    FrozenSwap = 0.0;
    RemainSwap = 0.0;
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaTradingAccountField=CThostFtdcSyncDeltaTradingAccountField;

class CThostFtdcSyncDeltaInitInvstMarginField{
    BrokerID = '';
    InvestorID = '';
    LastRiskTotalInvstMargin = 0.0;
    LastRiskTotalExchMargin = 0.0;
    ThisSyncInvstMargin = 0.0;
    ThisSyncExchMargin = 0.0;
    RemainRiskInvstMargin = 0.0;
    RemainRiskExchMargin = 0.0;
    LastRiskSpecTotalInvstMargin = 0.0;
    LastRiskSpecTotalExchMargin = 0.0;
    ThisSyncSpecInvstMargin = 0.0;
    ThisSyncSpecExchMargin = 0.0;
    RemainRiskSpecInvstMargin = 0.0;
    RemainRiskSpecExchMargin = 0.0;
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaInitInvstMarginField=CThostFtdcSyncDeltaInitInvstMarginField;

class CThostFtdcSyncDeltaDceCombInstrumentField{
    CombInstrumentID = '';
    ExchangeID = '';
    ExchangeInstID = '';
    TradeGroupID = 0;
    CombHedgeFlag = '';
    CombinationType = '';
    Direction = '';
    ProductID = '';
    Xparameter = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaDceCombInstrumentField=CThostFtdcSyncDeltaDceCombInstrumentField;

class CThostFtdcSyncDeltaInvstMarginRateField{
    InstrumentID = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    IsRelative = 0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaInvstMarginRateField=CThostFtdcSyncDeltaInvstMarginRateField;

class CThostFtdcSyncDeltaExchMarginRateField{
    BrokerID = '';
    InstrumentID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaExchMarginRateField=CThostFtdcSyncDeltaExchMarginRateField;

class CThostFtdcSyncDeltaOptExchMarginField{
    BrokerID = '';
    InstrumentID = '';
    SShortMarginRatioByMoney = 0.0;
    SShortMarginRatioByVolume = 0.0;
    HShortMarginRatioByMoney = 0.0;
    HShortMarginRatioByVolume = 0.0;
    AShortMarginRatioByMoney = 0.0;
    AShortMarginRatioByVolume = 0.0;
    MShortMarginRatioByMoney = 0.0;
    MShortMarginRatioByVolume = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaOptExchMarginField=CThostFtdcSyncDeltaOptExchMarginField;

class CThostFtdcSyncDeltaOptInvstMarginField{
    InstrumentID = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    SShortMarginRatioByMoney = 0.0;
    SShortMarginRatioByVolume = 0.0;
    HShortMarginRatioByMoney = 0.0;
    HShortMarginRatioByVolume = 0.0;
    AShortMarginRatioByMoney = 0.0;
    AShortMarginRatioByVolume = 0.0;
    IsRelative = 0;
    MShortMarginRatioByMoney = 0.0;
    MShortMarginRatioByVolume = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaOptInvstMarginField=CThostFtdcSyncDeltaOptInvstMarginField;

class CThostFtdcSyncDeltaInvstMarginRateULField{
    InstrumentID = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    HedgeFlag = '';
    LongMarginRatioByMoney = 0.0;
    LongMarginRatioByVolume = 0.0;
    ShortMarginRatioByMoney = 0.0;
    ShortMarginRatioByVolume = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaInvstMarginRateULField=CThostFtdcSyncDeltaInvstMarginRateULField;

class CThostFtdcSyncDeltaOptInvstCommRateField{
    InstrumentID = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    StrikeRatioByMoney = 0.0;
    StrikeRatioByVolume = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaOptInvstCommRateField=CThostFtdcSyncDeltaOptInvstCommRateField;

class CThostFtdcSyncDeltaInvstCommRateField{
    InstrumentID = '';
    InvestorRange = '';
    BrokerID = '';
    InvestorID = '';
    OpenRatioByMoney = 0.0;
    OpenRatioByVolume = 0.0;
    CloseRatioByMoney = 0.0;
    CloseRatioByVolume = 0.0;
    CloseTodayRatioByMoney = 0.0;
    CloseTodayRatioByVolume = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaInvstCommRateField=CThostFtdcSyncDeltaInvstCommRateField;

class CThostFtdcSyncDeltaProductExchRateField{
    ProductID = '';
    QuoteCurrencyID = '';
    ExchangeRate = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaProductExchRateField=CThostFtdcSyncDeltaProductExchRateField;

class CThostFtdcSyncDeltaDepthMarketDataField{
    TradingDay = '';
    InstrumentID = '';
    ExchangeID = '';
    ExchangeInstID = '';
    LastPrice = 0.0;
    PreSettlementPrice = 0.0;
    PreClosePrice = 0.0;
    PreOpenInterest = 0.0;
    OpenPrice = 0.0;
    HighestPrice = 0.0;
    LowestPrice = 0.0;
    Volume = 0;
    Turnover = 0.0;
    OpenInterest = 0.0;
    ClosePrice = 0.0;
    SettlementPrice = 0.0;
    UpperLimitPrice = 0.0;
    LowerLimitPrice = 0.0;
    PreDelta = 0.0;
    CurrDelta = 0.0;
    UpdateTime = '';
    UpdateMillisec = 0;
    BidPrice1 = 0.0;
    BidVolume1 = 0;
    AskPrice1 = 0.0;
    AskVolume1 = 0;
    BidPrice2 = 0.0;
    BidVolume2 = 0;
    AskPrice2 = 0.0;
    AskVolume2 = 0;
    BidPrice3 = 0.0;
    BidVolume3 = 0;
    AskPrice3 = 0.0;
    AskVolume3 = 0;
    BidPrice4 = 0.0;
    BidVolume4 = 0;
    AskPrice4 = 0.0;
    AskVolume4 = 0;
    BidPrice5 = 0.0;
    BidVolume5 = 0;
    AskPrice5 = 0.0;
    AskVolume5 = 0;
    AveragePrice = 0.0;
    ActionDay = '';
    BandingUpperPrice = 0.0;
    BandingLowerPrice = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaDepthMarketDataField=CThostFtdcSyncDeltaDepthMarketDataField;

class CThostFtdcSyncDeltaIndexPriceField{
    BrokerID = '';
    InstrumentID = '';
    ClosePrice = 0.0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaIndexPriceField=CThostFtdcSyncDeltaIndexPriceField;

class CThostFtdcSyncDeltaEWarrantOffsetField{
    TradingDay = '';
    BrokerID = '';
    InvestorID = '';
    ExchangeID = '';
    InstrumentID = '';
    Direction = '';
    HedgeFlag = '';
    Volume = 0;
    ActionDirection = '';
    SyncDeltaSequenceNo = 0;
}
jtp.CThostFtdcSyncDeltaEWarrantOffsetField=CThostFtdcSyncDeltaEWarrantOffsetField;



module.exports = jtp;