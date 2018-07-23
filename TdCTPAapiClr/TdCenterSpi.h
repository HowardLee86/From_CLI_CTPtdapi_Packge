#pragma once
#include "TdApiClr.h"
#include<queue>
#include<boost/any.hpp>        //������е�����ʵ��
#include<boost/bind.hpp>      //������е��̹߳���
#include<boost/thread.hpp>   //������е��̹߳���
#include<gcroot.h>

using namespace boost;

//����
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONHEARTBEATWARNING 3
#define ONRSPAUTHENTICATE 4
#define ONRSPUSERLOGIN 5
#define ONRSPUSERLOGOUT 6
#define ONRSPUSERPASSWORDUPDATE 7
#define ONRSPTRADINGACCOUNTPASSWORDUPDATE 8
#define ONRSPORDERINSERT 9
#define ONRSPPARKEDORDERINSERT 10
#define ONRSPPARKEDORDERACTION 11
#define ONRSPORDERACTION 12
#define ONRSPQUERYMAXORDERVOLUME 13
#define ONRSPSETTLEMENTINFOCONFIRM 14
#define ONRSPREMOVEPARKEDORDER 15
#define ONRSPREMOVEPARKEDORDERACTION 16
#define ONRSPEXECORDERINSERT 17
#define ONRSPEXECORDERACTION 18
#define ONRSPFORQUOTEINSERT 19
#define ONRSPQUOTEINSERT 20
#define ONRSPQUOTEACTION 21
#define ONRSPLOCKINSERT 22
#define ONRSPCOMBACTIONINSERT 23
#define ONRSPQRYORDER 24
#define ONRSPQRYTRADE 25
#define ONRSPQRYINVESTORPOSITION 26
#define ONRSPQRYTRADINGACCOUNT 27
#define ONRSPQRYINVESTOR 28
#define ONRSPQRYTRADINGCODE 29
#define ONRSPQRYINSTRUMENTMARGINRATE 30
#define ONRSPQRYINSTRUMENTCOMMISSIONRATE 31
#define ONRSPQRYEXCHANGE 32
#define ONRSPQRYPRODUCT 33
#define ONRSPQRYINSTRUMENT 34
#define ONRSPQRYDEPTHMARKETDATA 35
#define ONRSPQRYSETTLEMENTINFO 36
#define ONRSPQRYTRANSFERBANK 37
#define ONRSPQRYINVESTORPOSITIONDETAIL 38
#define ONRSPQRYNOTICE 39
#define ONRSPQRYSETTLEMENTINFOCONFIRM 40
#define ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL 41
#define ONRSPQRYCFMMCTRADINGACCOUNTKEY 42
#define ONRSPQRYEWARRANTOFFSET 43
#define ONRSPQRYINVESTORPRODUCTGROUPMARGIN 44
#define ONRSPQRYEXCHANGEMARGINRATE 45
#define ONRSPQRYEXCHANGEMARGINRATEADJUST 46
#define ONRSPQRYEXCHANGERATE 47
#define ONRSPQRYSECAGENTACIDMAP 48
#define ONRSPQRYPRODUCTEXCHRATE 49
#define ONRSPQRYPRODUCTGROUP 50
#define ONRSPQRYOPTIONINSTRTRADECOST 51
#define ONRSPQRYOPTIONINSTRCOMMRATE 52
#define ONRSPQRYEXECORDER 53
#define ONRSPQRYFORQUOTE 54
#define ONRSPQRYQUOTE 55
#define ONRSPQRYLOCK 56
#define ONRSPQRYLOCKPOSITION 57
#define ONRSPQRYINVESTORLEVEL 58
#define ONRSPQRYEXECFREEZE 59
#define ONRSPQRYCOMBINSTRUMENTGUARD 60
#define ONRSPQRYCOMBACTION 61
#define ONRSPQRYTRANSFERSERIAL 62
#define ONRSPQRYACCOUNTREGISTER 63
#define ONRSPERROR 64
#define ONRTNORDER 65
#define ONRTNTRADE 66
#define ONERRRTNORDERINSERT 67
#define ONERRRTNORDERACTION 68
#define ONRTNINSTRUMENTSTATUS 69
#define ONRTNTRADINGNOTICE 70
#define ONRTNERRORCONDITIONALORDER 71
#define ONRTNEXECORDER 72
#define ONERRRTNEXECORDERINSERT 73
#define ONERRRTNEXECORDERACTION 74
#define ONERRRTNFORQUOTEINSERT 75
#define ONRTNQUOTE 76
#define ONERRRTNQUOTEINSERT 77
#define ONERRRTNQUOTEACTION 78
#define ONRTNFORQUOTERSP 79
#define ONRTNCFMMCTRADINGACCOUNTTOKEN 80
#define ONRTNLOCK 81
#define ONERRRTNLOCKINSERT 82
#define ONRTNCOMBACTION 83
#define ONERRRTNCOMBACTIONINSERT 84
#define ONRSPQRYCONTRACTBANK 85
#define ONRSPQRYPARKEDORDER 86
#define ONRSPQRYPARKEDORDERACTION 87
#define ONRSPQRYTRADINGNOTICE 88
#define ONRSPQRYBROKERTRADINGPARAMS 89
#define ONRSPQRYBROKERTRADINGALGOS 90
#define ONRSPQUERYCFMMCTRADINGACCOUNTTOKEN 91
#define ONRTNFROMBANKTOFUTUREBYBANK 92
#define ONRTNFROMFUTURETOBANKBYBANK 93
#define ONRTNREPEALFROMBANKTOFUTUREBYBANK 94
#define ONRTNREPEALFROMFUTURETOBANKBYBANK 95
#define ONRTNFROMBANKTOFUTUREBYFUTURE 96
#define ONRTNFROMFUTURETOBANKBYFUTURE 97
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTUREMANUAL 98
#define ONRTNREPEALFROMFUTURETOBANKBYFUTUREMANUAL 99
#define ONRTNQUERYBANKBALANCEBYFUTURE 100
#define ONERRRTNBANKTOFUTUREBYFUTURE 101
#define ONERRRTNFUTURETOBANKBYFUTURE 102
#define ONERRRTNREPEALBANKTOFUTUREBYFUTUREMANUAL 103
#define ONERRRTNREPEALFUTURETOBANKBYFUTUREMANUAL 104
#define ONERRRTNQUERYBANKBALANCEBYFUTURE 105
#define ONRTNREPEALFROMBANKTOFUTUREBYFUTURE 106
#define ONRTNREPEALFROMFUTURETOBANKBYFUTURE 107
#define ONRSPFROMBANKTOFUTUREBYFUTURE 108
#define ONRSPFROMFUTURETOBANKBYFUTURE 109
#define ONRSPQUERYBANKACCOUNTMONEYBYFUTURE 110
#define ONRTNOPENACCOUNTBYBANK 111
#define ONRTNCANCELACCOUNTBYBANK 112
#define ONRTNCHANGEACCOUNTBYBANK 113
namespace TdCTP
{
	public struct Task
	{
		int task_name;
		any task_data;
		any task_error;
		int task_id;
		bool task_last;
	};
	///�̰߳�ȫ�Ķ���
	template<typename Data>

	class ConcurrentQueue
	{
	private:
		std::queue<Data> the_queue;							//��׼�����
		mutable mutex the_mutex;							//boost������
		condition_variable the_condition_variable;			//boost��������

	public:

		//�����µ�����
		void push(Data const& data)
		{
			mutex::scoped_lock lock(the_mutex);				//��ȡ������
			the_queue.push(data);							//������д�������
			lock.unlock();									//�ͷ���
			the_condition_variable.notify_one();			//֪ͨ���������ȴ����߳�
		}

		//�������Ƿ�Ϊ��
		bool empty() const
		{
			mutex::scoped_lock lock(the_mutex);
			return the_queue.empty();
		}

		//ȡ��
		Data wait_and_pop()
		{
			mutex::scoped_lock lock(the_mutex);

			while (the_queue.empty())						//������Ϊ��ʱ
			{
				the_condition_variable.wait(lock);			//�ȴ���������֪ͨ
			}

			Data popped_value = the_queue.front();			//��ȡ�����е����һ������
			the_queue.pop();								//ɾ��������
			return popped_value;							//���ظ�����
		}

	};
	public class TdCenterSpi :public CThostFtdcTraderSpi
	{
	private:
		void* m_ptdapiClr;
		ConcurrentQueue<Task> task_queue;
		thread* task_thread;

	public:
		TdCenterSpi(TdApiClr^ clr);
		~TdCenterSpi();
		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected();
		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		virtual void OnFrontDisconnected(int nReason);
		///�ͻ�����֤��Ӧ
		virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///��¼������Ӧ
		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�ǳ�������Ӧ
		virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///����¼��������Ӧ
		virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///��������������Ӧ
		virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///Ͷ���߽�����ȷ����Ӧ
		virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///����¼��������Ӧ
		virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///���۲���������Ӧ
		virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯͶ���ֲ߳���Ӧ
		virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯ�ʽ��˻���Ӧ
		virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯͶ������Ӧ
		virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯ��Լ��Ӧ
		virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯͶ���߽�������Ӧ
		virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯͶ���ֲ߳���ϸ��Ӧ
		virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯ������Ϣȷ����Ӧ
		virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///�����ѯͶ���ֲ߳���ϸ��Ӧ
		virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///����Ӧ��
		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		///����֪ͨ
		virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
		///�ɽ�֪ͨ
		virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);


		///�������б�
		void processTask();
		void processOnFrontConnected(Task task);
		void processOnFrontDisconnected(Task task);
		void processOnRspUserLogin(Task task);
		void processOnRspUserLogout(Task task);
		void processOnRspAuthenticate(Task task);///�ͻ�����֤�ر�
		void processOnRspError(Task task);
		void processOnRspOrderInsert(Task task);///��������ر�
		void processOnRspOrderAction(Task task);///��������ر�
		void processOnRspQryInvestorPosition(Task task); ///��ѯͶ���ֲֻ߳ر�
		void processOnRspQryTradingAccount(Task task);///��ѯ�ʽ��ʺŻر�
		void processOnRspQryInvestor(Task task); ///��ѯͶ���߻ر�
		void processOnRspQryInstrument(Task task);///��ѯ��Լ�ر�
		void processOnRspQrySettlementInfo(Task task);///��ѯ����ر�
		void processOnRspQryInvestorPositionDetail(Task task);///��ѯ�ֲ���ϸ�ر�
		void processOnRspQrySettlementInfoConfirm(Task task);///��ѯ������Ϣȷ�ϻر�
		void processOnRspQryInvestorPositionCombineDetail(Task task);///��ѯ�ֲ���ϸ�ر�
		void processOnRtnOrder(Task task);
		void processOnRtnTrade(Task task);
	};
}

