#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

/**
 * @brief Main entry point of the application
 * @param argc Command line argument count
 * @param argv Command line argument values
 * @return Application exit code
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "WinSelector_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
