#pragma once

#include "stdafx.h"
#include"ThostFtdcTraderApi.h"
#include<string>
#include<typeinfo.h>
#include<msclr/marshal.h>
#include<msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;
using namespace System::Text;
using namespace System::IO;
///using namespace msclr::interop;  //msclr::interop����ʵ���й����ͺͱ������͵�ת��
#pragma comment (lib,"thosttraderapi.lib")
namespace TdCTP
{
	///����ر���Ϣ
	public ref struct ErrorInfo
	{
		///�������
		int ErrorID;
		///������Ϣ //Ϊ��ʾString���������ͣ����Ժ������һ��^ 
		String^ ErrorMsg; //^��ʾ���:ָ���й���Դ,���Ա������ռ������ն�����Ҫ�ֶ��ͷš�
	};
	///�û���¼Ӧ��
	public ref struct RspUserLogin
	{
		///������
		String^	TradingDay;
		///��¼�ɹ�ʱ��
		String^	LoginTime;
		///���͹�˾����
		String^ BrokerID;
		///�û�����
		String^	UserID;
		///����ϵͳ����
		String^	SystemName;
		///ǰ�ñ��
		int	FrontID;
		///�Ự���
		int	SessionID;
		///��󱨵�����
		String^	MaxOrderRef;
		///������ʱ��
		String^	SHFETime;
		///������ʱ��
		String^	DCETime;
		///֣����ʱ��
		String^	CZCETime;
		///�н���ʱ��
		String^	FFEXTime;
		///��Դ����ʱ��
		String^	INETime;
	};
	///�û��ǳ�����
	public ref struct RspUserLogout
	{
		///���͹�˾����
		String^	BrokerID;
		///�û�����
		String^	UserID;
	};
	///����¼������[OderInsert]
	public ref struct OrderInsert
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��Լ����
		String^	InstrumentID;
		///��������
		String^	OrderRef;
		///�û�����
		String^	UserID;
		///�����۸�����
		String^	OrderPriceType;
		///��������
		String^	Direction;
		///��Ͽ�ƽ��־
		String^	CombOffsetFlag;
		///���Ͷ���ױ���־
		String^	CombHedgeFlag;
		///�۸�
		double	LimitPrice;
		///����
		int	VolumeTotalOriginal;
		///��Ч������
		String^	TimeCondition;
		///GTD����
		String^	GTDDate;
		///�ɽ�������
		String^	VolumeCondition;
		///��С�ɽ���
		int	MinVolume;
		///��������
		String^	ContingentCondition;
		///ֹ���
		double	StopPrice;
		///ǿƽԭ��
		String^	ForceCloseReason;
		///�Զ������־
		int	IsAutoSuspend;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///������
		int	RequestID;
		///�û�ǿ����־
		int	UserForceClose;
		///��������־
		int	IsSwapOrder;
		///����������
		String^	ExchangeID;
	};
	///��������
	public ref struct OrderAction
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///������������
		int	OrderActionRef;
		///��������
		String^	OrderRef;
		///������
		int	RequestID;
		///ǰ�ñ��
		int	FrontID;
		///�Ự���
		int	SessionID;
		///����������
		String^	ExchangeID;
		///�������
		String^	OrderSysID;
		///������־
		String^	ActionFlag;
		///�۸�
		double	LimitPrice;
		///�����仯
		int	VolumeChange;
		///�û�����
		String^	UserID;
		///��Լ����
		String^	InstrumentID;
	};
	///Ͷ���߽�����ȷ����Ϣ
	public ref struct RspSettlementInfoConfirm
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///ȷ������
		String^	ConfirmDate;
		///ȷ��ʱ��
		String^	ConfirmTime;
	};
	///����ı���
	public ref struct RspInputQuoteField
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��Լ����
		String^	InstrumentID;
		///��������
		String^	QuoteRef;
		///�û�����
		String^	UserID;
		///���۸�
		double	AskPrice;
		///��۸�
		double	BidPrice;
		///������
		int	AskVolume;
		///������
		int	BidVolume;
		///������
		int	RequestID;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///����ƽ��־
		String^	AskOffsetFlag;
		///��ƽ��־
		String^	BidOffsetFlag;
		///��Ͷ���ױ���־
		String^	AskHedgeFlag;
		///��Ͷ���ױ���־
		String^	BidHedgeFlag;
		///��������������
		String^	AskOrderRef;
		///�����򱨵�����
		String^	BidOrderRef;
		///Ӧ�۱��
		String^	ForQuoteSysID;
		///����������
		String^	ExchangeID;
	};
	///���۲���
	public ref struct RspQuoteActionField
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///���۲�������
		int	QuoteActionRef;
		///��������
		String^	QuoteRef;
		///������
		int	RequestID;
		///ǰ�ñ��
		int	FrontID;
		///�Ự���
		int	SessionID;
		///����������
		String^	ExchangeID;
		///���۲������
		String^	QuoteSysID;
		///������־
		String^	ActionFlag;
		///��������
		String^	ActionDate;
		///����ʱ��
		String^	ActionTime;
		///����������Ա����
		String^	TraderID;
		///��װ���
		int	InstallID;
		///���ر��۱��
		String^	QuoteLocalID;
		///�������ر��
		String^	ActionLocalID;
		///��Ա����
		String^	ParticipantID;
		///�ͻ�����
		String^	ClientID;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///��������״̬
		String^	OrderActionStatus;
		///�û�����
		String^	UserID;
		///״̬��Ϣ
		String^	StatusMsg;
		///��Լ����
		String^	InstrumentID;
		///Ӫҵ�����
		String^	BranchID;
	};
	///�����ѯͶ���ֲ߳���Ӧ
	public ref struct RspInvestorPositionField
	{
		///��Լ����
		String^	InstrumentID;
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///�ֲֶ�շ���
		String^	PosiDirection;
		///Ͷ���ױ���־
		String^	HedgeFlag;
		///�ֲ�����
		String^	PositionDate;
		///���ճֲ�
		int	YdPosition;
		///���ճֲ�
		int	Position;
		///��ͷ����
		int	LongFrozen;
		///��ͷ����
		int	ShortFrozen;
		///���ֶ�����
		double	LongFrozenAmount;
		///���ֶ�����
		double	ShortFrozenAmount;
		///������
		int	OpenVolume;
		///ƽ����
		int	CloseVolume;
		///���ֽ��
		double	OpenAmount;
		///ƽ�ֽ��
		double	CloseAmount;
		///�ֲֳɱ�
		double	PositionCost;
		///�ϴ�ռ�õı�֤��
		double	PreMargin;
		///ռ�õı�֤��
		double	UseMargin;
		///����ı�֤��
		double	FrozenMargin;
		///������ʽ�
		double	FrozenCash;
		///�����������
		double	FrozenCommission;
		///�ʽ���
		double	CashIn;
		///������
		double	Commission;
		///ƽ��ӯ��
		double	CloseProfit;
		///�ֲ�ӯ��
		double	PositionProfit;
		///�ϴν����
		double	PreSettlementPrice;
		///���ν����
		double	SettlementPrice;
		///������
		String^	TradingDay;
		///������
		String^	SettlementID;
		///���ֳɱ�
		double	OpenCost;
		///��������֤��
		double	ExchangeMargin;
		///��ϳɽ��γɵĳֲ�
		int	CombPosition;
		///��϶�ͷ����
		int	CombLongFrozen;
		///��Ͽ�ͷ����
		int	CombShortFrozen;
		///���ն���ƽ��ӯ��
		double	CloseProfitByDate;
		///��ʶԳ�ƽ��ӯ��
		double	CloseProfitByTrade;
		///���ճֲ�
		int	TodayPosition;
		///��֤����
		double	MarginRateByMoney;
		///��֤����(������)
		double	MarginRateByVolume;
		///ִ�ж���
		int	StrikeFrozen;
		///ִ�ж�����
		int	StrikeFrozenAmount;
		///����ִ�ж���
		int	AbandonFrozen;
		///����������
		String^	ExchangeID;
		///ִ�ж�������
		int	YdStrikeFrozen;
	};
	///�ʽ��˻���ѯ
	public ref struct RspTradingAccountField
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ�����ʺ�
		String^	AccountID;
		///�ϴ���Ѻ���
		double	PreMortgage;
		///�ϴ����ö��
		double	PreCredit;
		///�ϴδ���
		double	PreDeposit;
		///�ϴν���׼����
		double	PreBalance;
		///�ϴ�ռ�õı�֤��
		double	PreMargin;
		///��Ϣ����
		double	InterestBase;
		///��Ϣ����
		double	Interest;
		///�����
		double	Deposit;
		///������
		double	Withdraw;
		///����ı�֤��
		double	FrozenMargin;
		///������ʽ�
		double	FrozenCash;
		///�����������
		double	FrozenCommission;
		///��ǰ��֤���ܶ�
		double	CurrMargin;
		///�ʽ���
		double	CashIn;
		///������
		double	Commission;
		///ƽ��ӯ��
		double	CloseProfit;
		///�ֲ�ӯ��
		double	PositionProfit;
		///�ڻ�����׼����
		double	Balance;
		///�����ʽ�
		double	Available;
		///��ȡ�ʽ�
		double	WithdrawQuota;
		///����׼����
		double	Reserve;
		///������
		String^	TradingDay;
		///������
		String^	SettlementID;
		///���ö��
		double	Credit;
		///��Ѻ���
		double	Mortgage;
		///��������֤��
		double	ExchangeMargin;
		///Ͷ���߽��֤��
		double	DeliveryMargin;
		///���������֤��
		double	ExchangeDeliveryMargin;
		///�����ڻ�����׼����
		double	ReserveBalance;
		///���ִ���
		String^	CurrencyID;
		///�ϴλ���������
		double	PreFundMortgageIn;
		///�ϴλ����ʳ����
		double	PreFundMortgageOut;
		///����������
		double	FundMortgageIn;
		///�����ʳ����
		double	FundMortgageOut;
		///������Ѻ���
		double	FundMortgageAvailable;
		///����Ѻ���ҽ��
		double	MortgageableFund;
		///�����Ʒռ�ñ�֤��
		double	SpecProductMargin;
		///�����Ʒ���ᱣ֤��
		double	SpecProductFrozenMargin;
		///�����Ʒ������
		double	SpecProductCommission;
		///�����Ʒ����������
		double	SpecProductFrozenCommission;
		///�����Ʒ�ֲ�ӯ��
		double	SpecProductPositionProfit;
		///�����Ʒƽ��ӯ��
		double	SpecProductCloseProfit;
		///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
		double	SpecProductPositionProfitByAlg;
		///�����Ʒ��������֤��
		double	SpecProductExchangeMargin;
		///ҵ������
		String^	BizType;
	};
	///Ͷ���߲�ѯ
	public ref struct RspInvestorField
	{
		///Ͷ���ߴ���
		String^	InvestorID;
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���߷������
		String^	InvestorGroupID;
		///Ͷ��������
		String^	InvestorName;
		///֤������
		String^	IdentifiedCardType;
		///֤������
		String^	IdentifiedCardNo;
		///�Ƿ��Ծ
		int	IsActive;
		///��ϵ�绰
		String^	Telephone;
		///ͨѶ��ַ
		String^	Address;
		///��������
		String^	OpenDate;
		///�ֻ�
		String^	Mobile;
		///��������ģ�����
		String^	CommModelID;
		///��֤����ģ�����
		String^	MarginModelID;
	};
	///Ͷ���߽�����
	public ref struct RspSettlementInfoField
	{
		///������
		String^	TradingDay;
		///������
		int	SettlementID;
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///���
		int	SequenceNo;
		///��Ϣ����
		String^	Content;
	};
	///Ͷ���ֲ߳���ϸ
	public ref struct RspInvestorPositionDelailField
	{
		///��Լ����
		String^	InstrumentID;
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///Ͷ���ױ���־
		String^	HedgeFlag;
		///����
		String^	Direction;
		///��������
		String^	OpenDate;
		///�ɽ����
		String^	TradeID;
		///����
		int	Volume;
		///���ּ�
		double	OpenPrice;
		///������
		String^	TradingDay;
		///������
		int	SettlementID;
		///�ɽ�����
		String^	TradeType;
		///��Ϻ�Լ����
		String^	CombInstrumentID;
		///����������
		String^	ExchangeID;
		///���ն���ƽ��ӯ��
		double	CloseProfitByDate;
		///��ʶԳ�ƽ��ӯ��
		double	CloseProfitByTrade;
		///���ն��гֲ�ӯ��
		double	PositionProfitByDate;
		///��ʶԳ�ֲ�ӯ��
		double	PositionProfitByTrade;
		///Ͷ���߱�֤��
		double	Margin;
		///��������֤��
		double	ExchMargin;
		///��֤����
		double	MarginRateByMoney;
		///��֤����(������)
		double	MarginRateByVolume;
		///������
		double	LastSettlementPrice;
		///�����
		double	SettlementPrice;
		///ƽ����
		int	CloseVolume;
		///ƽ�ֽ��
		double	CloseAmount;
	};
	///Ͷ������ϳֲ���ϸ
	public ref struct RspInvestorPositionCombineDetailField
	{
		///������
		String^	TradingDay;
		///��������
		String^	OpenDate;
		///����������
		String^	ExchangeID;
		///������
		int	SettlementID;
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��ϱ��
		String^	ComTradeID;
		///��ϱ��
		String^	TradeID;
		///��Լ����
		String^	InstrumentID;
		///Ͷ���ױ���־
		String^	HedgeFlag;
		///����
		String^	Direction;
		///�ֲ���
		int	TotalAmt;
		///Ͷ���߱�֤��
		double	Margin;
		///��������֤��
		double	ExchMargin;
		///��֤����
		double	MarginRateByMoney;
		///��֤����(������)
		double	MarginRateByVolume;
		///���ȱ��
		int	LegID;
		///���ȳ���
		int	LegMultiple;
		///��ϳֲֺ�Լ����
		String^	CombInstrumentID;
		///�ɽ����
		int	TradeGroupID;
	};
	///�ͻ�����֤��Ӧ
	public ref struct RspAuthenticateField
	{
		///���͹�˾����
		String^	BrokerID;
		///�û�����
		String^	UserID;
		///�û��˲�Ʒ��Ϣ
		String^	UserProductInfo;
	};
	///�����ѯ��Լ��Ӧ
	public ref struct RspInstrumentField
	{
		///��Լ����
		String^	InstrumentID;
		///����������
		String^	ExchangeID;
		///��Լ����
		String^	InstrumentName;
		///��Լ�ڽ������Ĵ���
		String^	ExchangeInstID;
		///��Ʒ����
		String^	ProductID;
		///��Ʒ����
		String^	ProductClass;
		///�������
		int	DeliveryYear;
		///������
		int	DeliveryMonth;
		///�м۵�����µ���
		int	MaxMarketOrderVolume;
		///�м۵���С�µ���
		int	MinMarketOrderVolume;
		///�޼۵�����µ���
		int	MaxLimitOrderVolume;
		///�޼۵���С�µ���
		int	MinLimitOrderVolume;
		///��Լ��������
		int	VolumeMultiple;
		///��С�䶯��λ
		double	PriceTick;
		///������
		String^	CreateDate;
		///������
		String^	OpenDate;
		///������
		String^	ExpireDate;
		///��ʼ������
		String^	StartDelivDate;
		///����������
		String^	EndDelivDate;
		///��Լ��������״̬
		String^	InstLifePhase;
		///��ǰ�Ƿ���
		int	IsTrading;
		///�ֲ�����
		String^	PositionType;
		///�ֲ���������
		String^	PositionDateType;
		///��ͷ��֤����
		double	LongMarginRatio;
		///��ͷ��֤����
		double	ShortMarginRatio;
		///�Ƿ�ʹ�ô��߱�֤���㷨
		String^	MaxMarginSideAlgorithm;
		///������Ʒ����
		String^	UnderlyingInstrID;
		///ִ�м�
		double	StrikePrice;
		///��Ȩ����
		String^	OptionsType;
		///��Լ������Ʒ����
		double	UnderlyingMultiple;
		///�������
		String^	CombinationType;
		///��С���µ���λ
		int	MinBuyVolume;
		///��С���µ���λ
		int	MinSellVolume;
		///��Լ��ʶ��
		String^	InstrumentCode;
	};
	///RtnOrder(ί�лر�)
	public ref struct RtnOrderField
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��Լ����
		String^	InstrumentID;
		///��������
		String^	OrderRef;
		///�û�����
		String^	UserID;
		///�����۸�����
		String^	OrderPriceType;
		///��������
		String^	Direction;
		///��Ͽ�ƽ��־
		String^	CombOffsetFlag;
		///���Ͷ���ױ���־
		String^	CombHedgeFlag;
		///�۸�
		double	LimitPrice;
		///����
		int	VolumeTotalOriginal;
		///��Ч������
		String^	TimeCondition;
		///GTD����
		String^	GTDDate;
		///�ɽ�������
		String^	VolumeCondition;
		///��С�ɽ���
		int	MinVolume;
		///��������
		String^	ContingentCondition;
		///ֹ���
		double	StopPrice;
		///ǿƽԭ��
		String^	ForceCloseReason;
		///�Զ������־
		int	IsAutoSuspend;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///������
		int	RequestID;
		///���ر������
		String^	OrderLocalID;
		///����������
		String^	ExchangeID;
		///��Ա����
		String^	ParticipantID;
		///�ͻ�����
		String^	ClientID;
		///��Լ�ڽ������Ĵ���
		String^	ExchangeInstID;
		///����������Ա����
		String^	TraderID;
		///��װ���
		int	InstallID;
		///�����ύ״̬
		String^	OrderSubmitStatus;
		///������ʾ���
		int	NotifySequence;
		///������
		String^	TradingDay;
		///������
		int	SettlementID;
		///�������
		String^	OrderSysID;
		///������Դ
		String^	OrderSource;
		///����״̬
		String^	OrderStatus;
		///��������
		String^	OrderType;
		///��ɽ�����
		int	VolumeTraded;
		///ʣ������
		int	VolumeTotal;
		///��������
		String^	InsertDate;
		///ί��ʱ��
		String^	InsertTime;
		///����ʱ��
		String^	ActiveTime;
		///����ʱ��
		String^	SuspendTime;
		///����޸�ʱ��
		String^	UpdateTime;
		///����ʱ��
		String^	CancelTime;
		///����޸Ľ���������Ա����
		String^	ActiveTraderID;
		///�����Ա���
		String^	ClearingPartID;
		///���
		int	SequenceNo;
		///ǰ�ñ��
		int	FrontID;
		///�Ự���
		int	SessionID;
		///�û��˲�Ʒ��Ϣ
		String^	UserProductInfo;
		///״̬��Ϣ
		String^	StatusMsg;
		///�û�ǿ����־
		int	UserForceClose;
		///�����û�����
		String^	ActiveUserID;
		///���͹�˾�������
		int	BrokerOrderSeq;
		///��ر���
		String^	RelativeOrderSysID;
		///֣�����ɽ�����
		int	ZCETotalTradedVolume;
		///��������־
		int	IsSwapOrder;
		///Ӫҵ�����
		String^	BranchID;
	};
	///RtnTrade(�ɽ��ر�)
	public ref struct RtnTradeField
	{
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��Լ����
		String^	InstrumentID;
		///��������
		String^	OrderRef;
		///�û�����
		String^	UserID;
		///����������
		String^	ExchangeID;
		///�ɽ����
		String^	TradeID;
		///��������
		String^	Direction;
		///�������
		String^	OrderSysID;
		///��Ա����
		String^	ParticipantID;
		///�ͻ�����
		String^	ClientID;
		///���׽�ɫ
		String^	TradingRole;
		///��Լ�ڽ������Ĵ���
		String^	ExchangeInstID;
		///��ƽ��־
		String^	OffsetFlag;
		///Ͷ���ױ���־
		String^	HedgeFlag;
		///�۸�
		double	Price;
		///����
		int	Volume;
		///�ɽ�ʱ��
		String^	TradeDate;
		///�ɽ�ʱ��
		String^	TradeTime;
		///�ɽ�����
		String^	TradeType;
		///�ɽ�����Դ
		String^	PriceSource;
		///����������Ա����
		String^	TraderID;
		///���ر������
		String^	OrderLocalID;
		///�����Ա���
		String^	ClearingPartID;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///���
		int	SequenceNo;
		///������
		String^	TradingDay;
		///������
		int	SettlementID;
		///���͹�˾�������
		int	BrokerOrderSeq;
		///�ɽ���Դ
		String^	TradeSource;
	};

	//////////����ί��=>ί�е�ǩ����Spi�еĻص�����һ��
	public delegate void OnFrontConnectedDelegate();
	public delegate void OnFrontDisconnectedDelegate(int n);
	public delegate void OnAuthenticateDelegate(RspAuthenticateField^ authen, ErrorInfo ^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspUserLoginDelegate(RspUserLogin^ pRspUserLogin, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspUserLogoutDelegate(RspUserLogout^ pUserLogout, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspErrorDelegate(ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspOrderInsertDelegate(OrderInsert^ orderInsert, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspOrderActionDelegate(OrderAction^ orderAction, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspSettlementInfoConfirmDelegate(RspSettlementInfoConfirm^ settelment, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQuoteInsertDelegate(RspInputQuoteField^ inputQuote, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQuoteActionDelegate(RspQuoteActionField^ action, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQryInvestorPositionDelegate(RspInvestorPositionField^ investorPosition, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQryTradingAccountDelegate(RspTradingAccountField^ tradingAccount, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQryInvestorDelegate(RspInvestorField^ investor, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQryInstrumentDelegate(RspInstrumentField^ code, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQrySettlementInfoDelegate(RspSettlementInfoField^ settlementInfo, ErrorInfo^ pRspInfo, int pResquesID, bool bIsLast);
	public delegate void OnRspQryInvestorPositionDetailDelegate(RspInvestorPositionDelailField^ investorPositionDelail, ErrorInfo^ pRspInfo, int pRequestID, bool bIsLast);
	public delegate void OnRspQrySettlementInfoConfirmDelegate(RspSettlementInfoConfirm^ settelment, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
	public delegate void OnRspQryInvestorPositionCombineDetailDelegate(RspInvestorPositionCombineDetailField^ investorPositionCombineDetail, ErrorInfo^ pRequestID, int nRequestID, bool bIsLast);
	public delegate void OnRtnOrderDelegate(RtnOrderField^ rtnOrder);
	public delegate void OnRtnTradeDelegate(RtnTradeField^ rtnTrade);

	class TdCenterSpi;
	public ref class TdApiClr
	{
	private:
		static TdApiClr^ clrTdExsample; ///�����˽��ʵ��
		CThostFtdcTraderApi* api;
		TdCenterSpi* tdcspi;
	public:
		TdApiClr();
		~TdApiClr();
		OnFrontConnectedDelegate^ onFrontConnectDelegate;
		OnFrontDisconnectedDelegate^ onFrontDisConnectDelegate;
		OnAuthenticateDelegate^ onAuthenDelegate;
		OnRspUserLoginDelegate^ onRspLoginDelegate;
		OnRspUserLogoutDelegate^ onRspLogoutDelegate;
		OnRspErrorDelegate^ onErrorDelegate;
		OnRspOrderInsertDelegate^ onRspOrderInsertDelegate;
		OnRspOrderActionDelegate^ onOrderActionDelegate;
		OnRspQuoteInsertDelegate^ onQuoteInsertDelegate;
		OnRspQuoteActionDelegate^ onQuoteActionDelegate;
		OnRspQryInvestorPositionDelegate^ onRspQryInvestorPositionDelegate;
		OnRspQryTradingAccountDelegate^ onRspQryTradingAccountDelegate;
		OnRspQryInvestorDelegate^ onRspQryInvestorDelegate;
		OnRspQryInstrumentDelegate^ onRspQryInstrumentDelegate;
		OnRspSettlementInfoConfirmDelegate^ onRspSettlementInfoConfirmDelegate;
		OnRspQrySettlementInfoDelegate^ onRspQrySettlementInfoDelegate;
		OnRspQryInvestorPositionDetailDelegate^ onRspQryInvestorPositionDetailDelegate;
		OnRspQryInvestorPositionCombineDetailDelegate^ onRspQryInvestorPositionCombineDetailDelegate;
		OnRspQrySettlementInfoConfirmDelegate^ onRspQrySettlementInfoConfirmDelegate;
		OnRtnOrderDelegate^ onRtnOrderDelegate;
		OnRtnTradeDelegate^ onRtnTradeDelegate;

		void SetOnFrontConnectedDelegate(OnFrontConnectedDelegate^ connected);
		void SetOnFrontDisconnectedDelegate(OnFrontDisconnectedDelegate^ disConnected);
		void SetOnRspUserLoginDelegate(OnRspUserLoginDelegate^ login);
		void SetOnRspUserLogoutDelegate(OnRspUserLogoutDelegate^ logout);
		void SetAuthenDelegate(OnAuthenticateDelegate^ authen);
		void SetOnRspErrorDelegate(OnRspErrorDelegate^ error);
		void SetOnRspOrderInsertDelegate(OnRspOrderInsertDelegate^ orderInsert);
		void SetOnRspOrderActionDelegate(OnRspOrderActionDelegate^ orderAction);
		void SetOnRspQuoteInsertDelegate(OnRspQuoteInsertDelegate^ quoteInsert);
		void SetOnRspQuoteActionDelegate(OnRspQuoteActionDelegate^ quoteaction);
		void SetOnRspQryInvestorPositionDelegate(OnRspQryInvestorPositionDelegate^ investorPosition);
		void SetOnRspQryTradingAccountDelegate(OnRspQryTradingAccountDelegate^ tradingAccount);
		void SetOnRspQryInvestorDelegate(OnRspQryInvestorDelegate^ investor);
		void SetOnRspQryInstrumentDelegate(OnRspQryInstrumentDelegate^ instrument);
		void SetOnRspSettlementInfoConfirmDelegate(OnRspSettlementInfoConfirmDelegate^ settlementInfoConfirm);
		void SetOnRspQrySettlementInfoDelegate(OnRspQrySettlementInfoDelegate^ settlementInfo);
		void SetOnRspQryInvestorPositionDetailDelegate(OnRspQryInvestorPositionDetailDelegate^ investorPositionDetail);
		void SetOnRspQryInvestorPositionCombineDetailDelegate(OnRspQryInvestorPositionCombineDetailDelegate^ onInvestorPositionCombineDetail);
		void SetOnRspQrySettlementInfoConfirmDelegate(OnRspQrySettlementInfoConfirmDelegate^ onRspQrySettlementInfoConfirm);
		void SetOnRtnOrderDelegate(OnRtnOrderDelegate^ rtnOrder);
		void SetOnRtnTradeDelegate(OnRtnTradeDelegate^ rtnTrade);

		///Ͷ���߽�����ȷ����Ϣ
		ref struct ReqSettlementInfoConfirmField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
		};
		///��ѯͶ���ֲ߳�
		ref struct ReqInvestorPositionField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
			///��Լ����
			String^	InstrumentID;
			///����������
			String^	ExchangeID;
		};
		///��ѯ�ʽ��˻�
		ref struct ReqTradingAccountField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
			///���ִ���
			String^	CurrencyID;
			///ҵ������
			String^	BizType;
		};
		///��ѯͶ����
		ref struct ReqInvestorField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
		};
		///��ѯͶ���߽�����
		ref struct ReqSettlementInfoField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
			///������
			String^	TradingDay;
		};
		///��ѯͶ���ֲ߳�����
		ref struct ReqInvestorPositionDetailField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
			///��Լ����
			String^	InstrumentID;
			///����������
			String^	ExchangeID;
		};
		///��ѯ��ϳֲ���ϸ
		ref struct ReqInvestorPositionCombineDetailField
		{
			///���͹�˾����
			String^	BrokerID;
			///Ͷ���ߴ���
			String^	InvestorID;
			///��ϳֲֺ�Լ����
			String^	CombInstrumentID;
		};
		///�û���¼����
		ref struct ReqUserLoginField
		{
			///������
			String^ TradingDay;
			///���͹�˾����
			String^ BrokerID;
			///�û�����
			String^ UserID;
			///����
			String^ Password;
			///�û��˲�Ʒ��Ϣ
			String^ UserProductInfo;
			///�ӿڶ˲�Ʒ��Ϣ
			String^ InterfaceProductInfo;
			///Э����Ϣ
			String^ ProtocolInfo;
			///Mac��ַ
			String^ MacAddress;
			///��̬����
			String^ OneTimePassword;
			///�ն�IP��ַ
			String^ ClientIPAddress;
		};
		///�û��ǳ�����
		ref struct ReqUserLogoutField
		{
			///���͹�˾����
			String^	BrokerID;
			///�û�����
			String^	UserID;
		};
		///�����ѯ��Լ
		ref struct ReqInstrumentField
		{
			///��Լ����
			String^	InstrumentID;
			///����������
			String^	ExchangeID;
			///��Լ�ڽ������Ĵ���
			String^	ExchangeInstID;
			///��Ʒ����
			String^	ProductID;
		};
		///�ͻ�����֤
		ref struct ReqAuthenticateField
		{
			///���͹�˾����
			String^	BrokerID;
			///�û�����
			String^	UserID;
			///�û��˲�Ʒ��Ϣ
			String^	UserProductInfo;
			///��֤��
			String^	AuthCode;
		};
		///�����ѯ��Լ
		ref struct ReqInstrument
		{
			///��Լ����
			String^	InstrumentID;
			///����������
			String^	ExchangeID;
			///��Լ�ڽ������Ĵ���
			String^	ExchangeInstID;
			///��Ʒ����
			String^	ProductID;
		};

		static TdApiClr^ GetInstance();  ///����һ������ֵ�Ǳ������ķ���GetInstance

										 ///�ص�����
		void OnFrontConnected_();
		void OnFrontDisconnected_(int nReason);
		void OnRspAuthenticate_(RspAuthenticateField^ pRspAuthenticateField, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspUserLogin_(RspUserLogin^ pRspUserLogin, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspUserLogout_(RspUserLogout^ pUserLogout, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspOrderInsert_(OrderInsert^ pInputOrder, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspOrderAction_(OrderAction^ pInputOrderAction, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspSettlementInfoConfirm_(RspSettlementInfoConfirm^ pSettlementInfoConfirm, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQuoteInsert_(RspInputQuoteField^ pInputQuote, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQuoteAction_(RspQuoteActionField^ pInputQuoteAction, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQryInvestorPosition_(RspInvestorPositionField^ pInvestorPosition, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQryTradingAccount_(RspTradingAccountField^ pTradingAccount, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQryInvestor_(RspInvestorField^ pInvestor, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQryInstrument_(RspInstrumentField^ pInstrument, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQrySettlementInfo_(RspSettlementInfoField^ pSettlementInfo, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQryInvestorPositionDetail_(RspInvestorPositionDelailField^ pInvestorPositionDetail, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQrySettlementInfoConfirm_(RspSettlementInfoConfirm^ pSettlementInfoConfirm, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspQryInvestorPositionCombineDetail_(RspInvestorPositionCombineDetailField^ pInvestorPositionCombineDetail, ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRspError_(ErrorInfo^ pRspInfo, int nRequestID, bool bIsLast);
		void OnRtnOrder_(RtnOrderField^ pOrder);
		void OnRtnTrade_(RtnTradeField^ pTrade);

		//////////////////��������///////////////////////////
		///����TraderApi
		void CreateTdApi_(char *pszFlowPath);
		const char* GetApiVersion_();
		void Init_();
		void Release_();
		int Join_();
		const char* GetTradingDay_();
		///ע��ǰ�û������ַ
		///@param pszFrontAddress��ǰ�û������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
		void RegisterFront_(char *pszFrontAddress);
		///ע�����ַ����������ַ
		///@param pszNsAddress�����ַ����������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
		///@remark RegisterNameServer������RegisterFront
		void RegisterNameServer_(char *pszNsAddress);
		/////ע�����ַ������û���Ϣ
		/////@param pFensUserInfo���û���Ϣ��
		// void RegisterFensUserInfo(Login pFensUserInfo);
		///����˽������
		///@param nResumeType ˽�����ش���ʽ  
		///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        THOST_TERT_RESUME:���ϴ��յ�������
		///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
		void SubscribePrivateTopic_();
		///���Ĺ�������
		///@param nResumeType �������ش���ʽ  
		///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        THOST_TERT_RESUME:���ϴ��յ�������
		///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
		void SubscribePublicTopic_();
		///�ͻ�����֤����
		int ReqAuthenticate_(ReqAuthenticateField^ pReqAuthenticateField, int nRequestID);
		///�û���¼����
		int ReqUserLogin_(ReqUserLoginField^ pReqUserLoginField, int nRequestID);
		///�ǳ�����
		int ReqUserLogout_(ReqUserLogoutField^ pUserLogout, int nRequestID);
		///����¼������
		int ReqOrderInsert_(OrderInsert^ pInputOrder, int nRequestID);
		///������������
		int ReqOrderAction_(OrderAction^ pInputOrderAction, int nRequestID);
		///Ͷ���߽�����ȷ��
		int ReqSettlementInfoConfirm_(ReqSettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID);
		///�����ѯͶ���ֲ߳�
		int ReqQryInvestorPosition_(ReqInvestorPositionField^ pQryInvestorPosition, int nRequestID);
		///�����ѯ�ʽ��˻�
		int ReqQryTradingAccount_(ReqTradingAccountField^ pQryTradingAccount, int nRequestID);
		///�����ѯͶ����
		int ReqQryInvestor_(ReqInvestorField^ pQryInvestor, int nRequestID);
		///�����ѯ��Լ
		int ReqQryInstrument_(ReqInstrumentField^ pQryInstrument, int nRequestID);
		///�����ѯͶ���߽�����
		int ReqQrySettlementInfo_(ReqSettlementInfoField^ pQrySettlementInfo, int nRequestID);
		///�����ѯͶ���ֲ߳���ϸ
		int ReqQryInvestorPositionDetail_(ReqInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID);
		///�����ѯ������Ϣȷ��
		int ReqQrySettlementInfoConfirm_(ReqSettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID);
		///�����ѯͶ���ֲ߳���ϸ
		int ReqQryInvestorPositionCombineDetail_(ReqInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID);
		//////////////////��������///////////////////////////

		///����
		void CreateCenter();
	};

}