#include "TestZLG.h"
#include <QtWidgets/QApplication>
#include "test.h"
#include <QTranslator>
#include <string>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"version.lib")

typedef struct _CANFRAME{
	BYTE b0;
	BYTE b1;
	BYTE b2;
	BYTE b3;
	BYTE b4;
	BYTE b5;
	BYTE b6;
	DWORD id;
	BYTE data[8];
}CanFrame;
QString getFileVertion()
{
	QString result;
	char* pData = nullptr;

	TCHAR szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, szFilePath, MAX_PATH);

	do
	{
		DWORD dwLen = GetFileVersionInfoSize(szFilePath, 0);
		if (0 == dwLen)
		{
			break;
		}

		pData = new char[dwLen + 1];
		BOOL bSuccess = GetFileVersionInfo(szFilePath, 0, dwLen, pData);
		if (!bSuccess)
		{
			break;
		}
		struct LANGANDCODEPAGE
		{
			WORD wLanguage;
			WORD wCodePage;
		} *lpTranslate;
		LPVOID lpBuffer = nullptr;
		UINT uLen = 0;
		bSuccess = VerQueryValue(pData, (TEXT("\\VarFileInfo\\Translation")), (LPVOID*)&lpTranslate, &uLen);
		if (!bSuccess)
		{
			break;
		}
		QString str1, str2;
		str1.setNum(lpTranslate->wLanguage, 16);
		str2.setNum(lpTranslate->wCodePage, 16);
		str1 = "000" + str1;
		str2 = "000" + str2;
		QString verPath = "\\StringFileInfo\\" + str1.right(4) + str2.right(4) + "\\FileVersion";
		bSuccess = VerQueryValue(pData, (verPath.toStdWString()).c_str(), &lpBuffer, &uLen);
		if (!bSuccess)
		{
			break;
		}
		result = QString::fromUtf16((const unsigned short int *)lpBuffer);
	} while (false);

	if (nullptr != pData)
	{
		delete[] pData;
	}

	return result;
}
int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
	//QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);//支持高分辨率
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

	int nnn = sizeof(CanFrame);

	QString str = "12334";
	wchar_t  tt[12];
	int n = str.toWCharArray(tt);
	tt[n] = '\0';
	QApplication a(argc, argv);
	QTranslator translator;

	translator.load(":/TestZLG/Resources/test_cn.qm");
	//	translator.load(":/translations/test_en.qm");

	a.installTranslator(&translator);

	test t;
	
	t.show();
	return a.exec();
}
