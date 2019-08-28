
#include <QTableWidget>
#include <QTextCodec>
#include <QtGui>
#include "test.h"
#include "ControlCAN.h"

#include <QApplication> 
#include <QHBoxLayout> 
#include <Qpalette>
#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <Windows.h>
#include <iostream>

int chartoint(unsigned char chr, unsigned char *cint)
{
	unsigned char cTmp;
	cTmp = chr - 48;
	if (cTmp >= 0 && cTmp <= 9)
	{
		*cint = cTmp;
		return 0;
	}
	cTmp = chr - 65;
	if (cTmp >= 0 && cTmp <= 5)
	{
		*cint = (cTmp + 10);
		return 0;
	}
	cTmp = chr - 97;
	if (cTmp >= 0 && cTmp <= 5)
	{
		*cint = (cTmp + 10);
		return 0;
	}
	return 1;
}

int strtodata(unsigned char *str, unsigned char *data, int len, int flag)
{
	unsigned char cTmp = 0;
	int i = 0;
	for (int j = 0; j < len; j++)
	{
		if (chartoint(str[i++], &cTmp))
			return 1;
		data[j] = cTmp;
		if (chartoint(str[i++], &cTmp))
			return 1;
		data[j] = (data[j] << 4) + cTmp;
		if (flag == 1)
			i++;
	}
	return 0;
}

QTest::QTest(QObject *parent)
{

	int n = 0;
}

QTest::~QTest()
{

}

void QTest::abort()     //实现成员函数
{

}

QPushButton *pushButton;
test::test(QWidget *parent) : QDialog(parent), m_bFlag(1)

{
	ui.setupUi(this);
	m_devtype = 4;
	m_bExit = false;
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//setWindowFlags( Qt::ToolTip | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::WindowDoesNotAcceptFocus );
	//setStyleSheet( QString::fromUtf8("background-color:transparent;\n"
	//                                ) );

	QTableWidget *tableWidget = ui.tableWidget;

	//构造一个QTableWidget类的实体对象tableWidget
	tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QStringList() << tr("ID") << tr("Format") << tr("Type") << tr("Length") << tr("Data(HEX)"));

	tableWidget->setColumnWidth(0, 90);
	tableWidget->setColumnWidth(1, 70);
	tableWidget->setColumnWidth(2, 70);
	tableWidget->setColumnWidth(3, 80);

	tableWidget->horizontalHeader()->setStretchLastSection(true);//关键

	//QHeaderView* headerView = tableWidget->verticalHeader();
	//headerView->setHidden(true); //行名隐藏

	ui.comboBox_dev->setCurrentIndex(1);

	initCurve();
	//按钮操作
	connect(ui.BtnConnect, SIGNAL(clicked()), this, SLOT(connectOrDisconnect()));
	connect(ui.comboBox_dev, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSelchangeComboDevType(int)));
	connect(ui.BtnStart, SIGNAL(clicked()), this, SLOT(OnButtonStartcan()));
	connect(ui.BtnReset, SIGNAL(clicked()), this, SLOT(OnButtonResetcan()));
	connect(ui.BtnSend, SIGNAL(clicked()), this, SLOT(OnButtonSend()));
	connect(this, SIGNAL(showData(QString, QString, QString, QString, QString, QByteArray)), this, SLOT(onShowData(QString, QString, QString, QString, QString, QByteArray)));


	m_hThreadRecv = nullptr;

};

test::~test()
{
	m_bExit = true;
	if (m_hThreadRecv)
	{
		WaitForSingleObject(m_hThreadRecv, 1000);
		CloseHandle(m_hThreadRecv);
		m_hThreadRecv = nullptr;
	}
	
}


void test::connectOrDisconnect()
{
	if (m_bFlag)
	{
		qDebug() << "try to connect";
		m_t->abort();
		ui.BtnConnect->setText(tr("Disconnect"));
		m_bFlag = false;

		//获取变量值

		m_index = ui.comboBox_index->currentIndex();
		printf("index_no =%d\n", m_index);

		m_cannum = ui.comboBox_can->currentIndex();
		printf("CAN_no =%d\n", m_cannum);

		int nFilter_no = ui.comboBox_filter->currentIndex();
		printf("Filter_no =%d\n", nFilter_no);

		int nMode_no = ui.comboBox_mode->currentIndex();
		printf("Mode_no =%d\n", nMode_no);

		int nSendFormat_no = ui.comboBox_send->currentIndex();
		printf("SendFormat_no =%d\n", nSendFormat_no);

		int nType_no = ui.m_ComboSendFrmType->currentIndex();
		printf("Type_no =%d\n", nType_no);

		int nFormat_no = ui.comboBox_format->currentIndex();
		printf("Format_no =%d\n", nFormat_no);

		QString strAcc = ui.lineEdit_acc->text();
		printf("Acc =%s\n", qPrintable(strAcc));

		QString strMask = ui.lineEdit_mask->text();
		printf("Mask =%s\n", qPrintable(strMask));

		QString strBtr0 = ui.lineEdit_btr0->text();
		printf("Btr0 =%s\n", qPrintable(strBtr0));

		QString strBtr1 = ui.lineEdit_btr1->text();
		printf("Btr1 =%s\n", qPrintable(strBtr1));

		QString strID = ui.m_EditSendFrmID->text();
		printf("ID =%s\n", qPrintable(strID));

		QString strData = ui.m_EditSendData->text();
		printf("Data =%s\n", qPrintable(strData));


		//init_config

		VCI_INIT_CONFIG init_config;
		int index, filtertype, mode, cannum;
		char szAcc[20], szMask[20], szBtr0[20], szBtr1[20];
		unsigned char sztmp[4];
		DWORD Acc, Mask, Timing0, Timing1;
		QString str;

		sprintf(szAcc, "%s", strAcc.toLocal8Bit().constData());
		sprintf(szMask, "%s", strMask.toLocal8Bit().constData());
		sprintf(szBtr0, "%s", strBtr0.toLocal8Bit().constData());
		sprintf(szBtr1, "%s", strBtr1.toLocal8Bit().constData());

		if (strtodata((unsigned char*)szAcc, sztmp, 4, 0) != 0)
		{
			qDebug() << "try to connect err1";
			printf("szAcc is error\n");
		}

		Acc = (((DWORD)sztmp[0]) << 24) + (((DWORD)sztmp[1]) << 16) + (((DWORD)sztmp[2]) << 8) +
			((DWORD)sztmp[3]);

		if (strtodata((unsigned char*)szMask, sztmp, 4, 0) != 0)
		{
			// MessageBox("屏蔽码数据格式不对!","警告",MB_OK|MB_ICONQUESTION);
			// return;
			qDebug() << "try to connect err2";
			printf("szMask is error\n");
		}
		Mask = (((DWORD)sztmp[0]) << 24) + (((DWORD)sztmp[1]) << 16) + (((DWORD)sztmp[2]) << 8) +
			((DWORD)sztmp[3]);

		if (strtodata((unsigned char*)szBtr0, sztmp, 1, 0) != 0)
		{
			// MessageBox("定时器0数据格式不对!","警告",MB_OK|MB_ICONQUESTION);
			// return;
			qDebug() << "try to connect err3";
			printf("szstrBtr0 is error\n");
		}
		Timing0 = ((DWORD)sztmp[0]);

		if (strtodata((unsigned char*)szBtr1, sztmp, 1, 0) != 0)
		{
			// MessageBox("定时器1数据格式不对!","警告",MB_OK|MB_ICONQUESTION);
			// return;
			qDebug() << "try to connect err4";
			printf("szstrBtr1 is error\n");
		}
		Timing1 = ((DWORD)sztmp[0]);

		init_config.AccCode = Acc;
		init_config.AccMask = Mask;
		init_config.Timing0 = Timing0;
		init_config.Timing1 = Timing1;
		init_config.Filter = nFilter_no;
		init_config.Mode = nMode_no;
		printf("init_config.AccCode=%d\n", init_config.AccCode);
		printf("init_config.AccMask=%d\n", init_config.AccMask);
		printf("init_config.Timing0=%d\n", init_config.Timing0);
		printf("init_config.Timing1=%d\n", init_config.Timing1);

		int res;
		res = VCI_OpenDevice(m_devtype, m_index, 0);
		if(res != STATUS_OK)
		{
			// MessageBox("打开设备失败!","警告",MB_OK|MB_ICONQUESTION);
			// return;
			qDebug() << "failed to run o" << res;
			printf("打开设备失败!\n");
			return;
		}

		if (VCI_InitCAN(m_devtype, m_index, m_cannum, &init_config) != STATUS_OK)
		{
			// MessageBox("初始化CAN失败!","警告",MB_OK|MB_ICONQUESTION);
			m_bExit = true;
			if (m_hThreadRecv)
			{
				WaitForSingleObject(m_hThreadRecv, 1000);
				CloseHandle(m_hThreadRecv);
				m_hThreadRecv = nullptr;
			}
			printf("初始化CAN失败!\n");
			qDebug() << "failed to init";
			VCI_CloseDevice(m_devtype, m_index);
			return;
		}

		m_connect = 1;

		m_hThreadRecv = CreateThread(nullptr, 0, test::ReceiveThread, this, 0, nullptr);

		// m_index =index;
		//   m_cannum=cannum;
		//    GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText("断开");
		//AfxBeginThread(ReceiveThread,this);
	}
	else
	{
		ui.BtnConnect->setText(tr("Connect"));
		m_bFlag = true;
		VCI_CloseDevice(m_devtype, m_index);
	}

}

void test::OnButtonStartcan()
{
	// TODO: Add your control notification handler code here
	if (m_connect == 0) {
		qDebug() << "connect ==0";
		return;
	}
	
	if (VCI_StartCAN(m_devtype, m_index, m_cannum) == 1)
	{
		// ShowInfo("启动成功",0);	
		qDebug() << "start success";
		printf("启动成功\n");
	}
	else
	{
		QString str;
		str = "启动失败";
		//  ShowInfo(str,2);
		printf("启动失败\n");
		qDebug() << "start failed";
	}

}

void test::OnButtonResetcan()
{
	// TODO: Add your control notification handler code here
	if (m_connect == 0)
		return;
	if (VCI_ResetCAN(m_devtype, m_index, m_cannum) == 1)
	{
		// GetDlgItem(IDC_BUTTON_STARTCAN)->EnableWindow(true);
		//ShowInfo("复位成功",0);		
		printf("复位成功\n");
	}
	else
	{
		QString str;
		str = "复位失败";
		// ShowInfo(str,2);
		printf("复位失败\n");
	}

}

/*
void test::ShowInfo(QString str, int code)
{
m_ListInfo.InsertString(m_ListInfo.GetCount(),str);
m_ListInfo.SetCurSel(m_ListInfo.GetCount()-1);
}
*/
void test::OnSelchangeComboDevType(int nIndex)
{
	int index = ui.comboBox_index->currentIndex();

	switch (index)
	{
	case 0:
		m_devtype = VCI_USBCAN1;
		break;
	case 1:
		m_devtype = VCI_USBCAN2;
		break;
	case 2:
		m_devtype = VCI_USBCAN2;
		break;
	case 3:
		m_devtype = VCI_PCI9820;
		break;
	case 4:
		m_devtype = VCI_PCI9840;
		break;
	case 5:
		m_devtype = VCI_USBCAN1;
		break;
	case 6:
		m_devtype = VCI_PCI9820;
	case 7:
		m_devtype = VCI_PCIE9221;

		break;
	}
}

void test::OnButtonSend()
{
	// TODO: Add your control notification handler code here
	qDebug() << "jkjlkjlk";
	if (m_connect == 0) {
		qDebug() << "hehe";
		return;
	}

	VCI_CAN_OBJ frameinfo;
	char szFrameID[9];
	unsigned char FrameID[4] = { 0, 0, 0, 0 };
	memset(szFrameID, '0', 9);
	unsigned char Data[8];
	char szData[25];
	BYTE datalen = 0;

	memset((void*)&frameinfo, 0, sizeof(frameinfo));

	if (ui.m_EditSendFrmID->text().length() == 0)
	{
		//ShowInfo("请输入数据",1);
		//return;         
		qDebug() << "1";
		printf("请输入ID\n");
	}

	if (ui.m_EditSendData->text().length() == 0)
	{
		qDebug() << "11";
		printf("请输入数据\n");

	}

	QStringList list1 = ui.m_EditSendData->text().split(" ");

	for (int i = 0; i < list1.size(); i++)
	{
		printf("%d ", list1.at(i).toInt());
		frameinfo.Data[i] = list1.at(i).toInt();
	}

	printf("\n");


	if (ui.m_EditSendFrmID->text().length()>8)
	{
		// ShowInfo("ID值超过范围",1);
		// return;
		qDebug() << "111";
		printf("ID超过范围\n");
	}
	if (ui.m_EditSendData->text().length() > 24)
	{
		//ShowInfo("数据长度超过范围,最大为8个字节",1);
		//return;
		qDebug() << "1111";
		printf("数据长度超过范围,最大为8个字节\n");
	}
	if (ui.m_ComboSendFrmType->currentText() == 0)
	{
		if (ui.m_EditSendData->text().length() % 3 == 1)
		{
			// ShowInfo("数据格式不对,请重新输入",1);
			//return;
			qDebug() << "11111";
			printf("数据格式不对,请重新输入\n");
		}
	}

	//   memcpy(&szFrameID[8-ui.m_EditSendFrmID->text().length()],(LPCTSTR)ui.m_EditSendFrmID,ui.m_EditSendFrmID->text().length());
	strtodata((unsigned char*)szFrameID, FrameID, 4, 0);

	datalen = (ui.m_EditSendData->text().length() + 1) / 3;
	//  strncpy(szData,(LPCTSTR)ui.m_EditSendData);

	//strtodata((unsigned char*)szData,Data,datalen,1);


	frameinfo.DataLen = datalen;

	//memcpy(&frameinfo.Data,Data,datalen);

	frameinfo.RemoteFlag = ui.comboBox_format->currentText().toInt();
	frameinfo.ExternFlag = ui.m_ComboSendFrmType->currentText().toInt();
	if (frameinfo.ExternFlag == 1)
	{
		frameinfo.ID = ((DWORD)FrameID[0] << 24) + ((DWORD)FrameID[1] << 16) + ((DWORD)FrameID[2] << 8) +
			((DWORD)FrameID[3]);
	}
	else
	{
		frameinfo.ID = ((DWORD)FrameID[2] << 8) + ((DWORD)FrameID[3]);
	}
	frameinfo.SendType = ui.comboBox_send->currentIndex();

	int ret = VCI_Transmit(m_devtype, m_index, m_cannum, &frameinfo, 1);

	if (0 < ret)
	{
		//ShowInfo("写入成功",0);		
		qDebug() << "111112";
		printf("写入成功\n");
	}
	else
	{
		// ShowInfo("写入失败",2);	
		qDebug() << "111112333" << ret;
		//need to ask why failed to transimit, the erro code is ACK failed
		DWORD err = GetLastError();
		qDebug() << err;
		VCI_ERR_INFO errinfo;
		VCI_ReadErrInfo(m_devtype, m_index, m_cannum, &errinfo);

		printf("写入失败\n");
		qDebug() << errinfo.ErrCode << errinfo.ArLost_ErrData << errinfo.Passive_ErrData;

	}
	qDebug() << "jkjlkjlk55555";



}

int test::strtodata(unsigned char *str, unsigned char *data, int len, int flag)
{
	unsigned char cTmp = 0;
	int i = 0;
	for (int j = 0; j < len; j++)
	{
		if (chartoint(str[i++], &cTmp))
			return 1;
		data[j] = cTmp;
		if (chartoint(str[i++], &cTmp))
			return 1;
		data[j] = (data[j] << 4) + cTmp;
		if (flag == 1)
			i++;
	}
	return 0;
}

int test::chartoint(unsigned char chr, unsigned char *cint)
{
	unsigned char cTmp;
	cTmp = chr - 48;
	if (cTmp >= 0 && cTmp <= 9)
	{
		*cint = cTmp;
		return 0;
	}
	cTmp = chr - 65;
	if (cTmp >= 0 && cTmp <= 5)
	{
		*cint = (cTmp + 10);
		return 0;
	}
	cTmp = chr - 97;
	if (cTmp >= 0 && cTmp <= 5)
	{
		*cint = (cTmp + 10);
		return 0;
	}
	return 1;
}


void test::onShowData( QString strCANID, QString strFrameFormat, QString strFrameType, QString dataLen, QString strData, QByteArray array)
{
	static int key = 0;
	int y;
	y = array[3];
	qDebug() << "key = " << key;
	ui.curve->graph(0)->addData(key, y);
	ui.curve->graph(0)->rescaleAxes(true);
	ui.curve->xAxis->setRange(key, 160, Qt::AlignRight);
	ui.curve->replot();
	key++;
	int nCount = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(nCount);

	QTableWidgetItem  *pItem = new QTableWidgetItem;
	pItem->setText(strCANID);
	ui.tableWidget->setItem(nCount, 0, pItem);

	pItem = new QTableWidgetItem;
	pItem->setText(strFrameFormat);
	ui.tableWidget->setItem(nCount, 1, pItem);

	pItem = new QTableWidgetItem;
	pItem->setText(strFrameType);
	ui.tableWidget->setItem(nCount, 2, pItem);

	pItem = new QTableWidgetItem;
	pItem->setText(dataLen);
	ui.tableWidget->setItem(nCount, 3, pItem);

	pItem = new QTableWidgetItem;
	pItem->setText(strData);
	ui.tableWidget->setItem(nCount, 4, pItem);

	ui.tableWidget->setRowHeight(nCount,23);

}

DWORD test::ReceiveThread(LPVOID lpParam)
{
	test *dlg = (test*)lpParam;
	//CListBox *box=(CListBox *)dlg->GetDlgItem(IDC_LIST_INFO);
	VCI_CAN_OBJ frameinfo[50];
	VCI_ERR_INFO errinfo;
	int len = 1;
	int i = 0;
	QString str, tmpstr;
	while (true)
	{
		if (dlg->m_bExit)
			break;
		//qDebug() << "recevie thread";
		len = VCI_Receive(dlg->m_devtype, dlg->m_index, dlg->m_cannum, frameinfo, 50, 200);
		if (len <= 0)
		{
			//注意：如果没有读到数据则必须调用此函数来读取出当前的错误码，
			//千万不能省略这一步（即使你可能不想知道错误码是什么）
			VCI_ReadErrInfo(dlg->m_devtype, dlg->m_index, dlg->m_cannum, &errinfo);
			Sleep(200);
			continue;
		}
		else
		{
			QString strCANID;
			QString strFormat;
			QString strType;
			QString strLen;
			QString strData;
			QByteArray array;

			for (i = 0; i < len; i++)
			{

				strCANID.clear();
				strFormat.clear();
				strData.clear();
				strLen.clear();
				strType.clear();

				strCANID.sprintf("0X%08x ", frameinfo[i].ID);

				if (frameinfo[i].RemoteFlag == 0)
					strFormat = "数据帧 ";
				else
					strFormat = "远程帧 ";

				if (frameinfo[i].ExternFlag == 0)
					strType = "标准帧 ";
				else
					strType = "扩展帧 ";

				if (frameinfo[i].RemoteFlag == 0)
				{
					strLen.sprintf("%d", frameinfo[i].DataLen);
					for (int j = 0; j < frameinfo[i].DataLen; j++)
					{
						tmpstr.sprintf("%02x ", frameinfo[i].Data[j]);
						strData.append(QString().sprintf("%02x", frameinfo[i].Data[j]));
						strData.append(" ");
						array[j] = frameinfo[i].Data[j];
					}

				}


				emit dlg->showData(strCANID, strFormat, strType, strLen, strData, array);
			}

		}
	}
	return 0;
}

void test::initCurve(void)
{
	/*lry begin to init the plot*/
	ui.curve->xAxis->setRange(0, 10);
	ui.curve->xAxis->grid();
	ui.curve->addGraph();
	ui.curve->graph(0)->setPen(QPen(Qt::blue));
}

