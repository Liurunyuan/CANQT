#ifndef TEST_H
#define TEST_H
#include <QObject>
#include <QDialog>
#include <QByteArray>
#include "ui_test.h"
#include <windows.h>
#include "ControlCAN.h"
//#pragma comment(lib,"ControlCAN.lib")
#pragma execution_character_set("UTF-8")//vs解决汉字乱码

class QTest: public QObject
{
     
public:
	QTest(QObject *parent = 0);     //explicit 只对构造函数起作用，抑制隐式转换
	virtual ~QTest();         //virtual 虚函数   析构函数
    void abort();
};


class test : public QDialog
{
     Q_OBJECT
public:
    test(QWidget *parent = 0);  
	~test();


    int m_connect;
    int m_devtype;
    int m_cannum;
    int m_index;
	static DWORD WINAPI ReceiveThread(LPVOID lpParam);
    void ShowInfo(QString str,int code);

signals:
	void showData(QString strID, QString strFormat, QString strType, QString strLen, QString strData, QByteArray array);

private slots:
		void connectOrDisconnect();
        void OnButtonStartcan();
        void OnButtonResetcan();
        void OnButtonSend();
		
        void OnSelchangeComboDevType(int nIndex);
        int strtodata(unsigned char *str, unsigned char *data,int len,int flag);
        int chartoint(unsigned char chr, unsigned char *cint);
		void onShowData(QString strID, QString strFormat, QString strType, QString strLen, QString strData, QByteArray array);

private:
    Ui::Dialog ui;
	
	  QPushButton *connectButton;
	  QTest *m_t;
      bool m_bFlag;

	  HANDLE  m_hThreadRecv;
	  bool  m_bExit;
};


#endif // TEST_H
