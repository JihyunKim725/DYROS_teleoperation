 #include <new>
#include <QCoreApplication>

#include <QTextCodec>

#include <QSslSocket>

#include <QLockFile>

#include <QProcess>

#include <QElapsedTimer>

#include "commonutils.h"

#include "business.h"

#include "singleapplication.h"

#include "PXREAGRPCServer.h"



#define STR(R) #R

#define STRVALUE(R) STR(R)


Q_DECLARE_METATYPE(QSharedPointer<QImage>)


enum PlatformType

{

    WINDOWS_X86 = 0,

    LINUX_X86,

    LINUX_AARCH64

};




#include <iostream>
#include "PXREARobotSDK.h"

void OnPXREAClientCallback(void* context, PXREAClientCallbackType type, int status, void* userData)
{
    switch (type)
    {
    case PXREADeviceStateJson:
    {
        auto* dsj = static_cast<PXREADevStateJson*>(userData);
        if (dsj)
        {
            std::cout << "\033[1;32m[DATA RECEIVED]\033[0m " << dsj->stateJson << std::endl;
        }
        break;
    }
    default:
        break;
    }
}

int main(int argc, char *argv[])

{

    SingleApplication app(argc, argv);


    QElapsedTimer ElapsedTimer;

    ElapsedTimer.start();


#ifdef QT_NO_DEBUG

    qDebug() << "release mode";

    //CommonUtils::installLogHandler();

#else

    qDebug() << "debug mode";

    program = "./LoadingPorcessDebug.exe";

#endif


    if(app.isStartUp())

    {

        app.connectLocalServer();

        return 0;

    }

    else

    {

        app.initLocalServer();

    }


    QTextCodec* codec = QTextCodec::codecForName("utf-8");

    QTextCodec::setCodecForLocale(codec);


    app.setOrganizationDomain("picoxr.com");

    app.setApplicationName("RoboticsServiceProcess");


    auto sdk = new PXREAServerAPI(&app);



#ifdef WINDOWS_x86

    quint32 platformType = WINDOWS_X86;

#endif


#ifdef LINUX_x86

    quint32 platformType = LINUX_X86;

#endif


#ifdef LINUX_aarch64

    quint32 platformType = LINUX_AARCH64;

#endif

    DeviceManagement deviceManage;

    Business business;

    business.setDeviceManager(deviceManage.getThisPoint());

    business.init();


    sdk->init(deviceManage.getThisPoint(), true, true);

    qDebug() << "소요 시간: " <<ElapsedTimer.elapsed() << "msec" << Qt::endl;

    PXREAInit(nullptr, OnPXREAClientCallback, PXREAFullMask);

    app.exec();

    sdk->deinit();

    app.release();



    return 0;

} 
