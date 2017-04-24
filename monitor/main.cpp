#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::addLibraryPath("./plugins");

	//QTextCodec *pCodec = QTextCodec::codecForName("GB2312");// "UTF-8", "UTF-16"
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));

    QTranslator translator;
    translator.load("language/language_cn.qm");
    app.installTranslator(&translator);

	QFile file("config/style.qss");
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet = QLatin1String(file.readAll());

		app.setStyleSheet(styleSheet);
		file.close();
	}

    MainWindow w;
	w.showMaximized();

    return app.exec();
}

