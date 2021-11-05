
#include "Hello.h"
#include <QSysInfo>
#include <iostream>

Hello::HOSTS Hello::host_  = Hello::HOSTS::LINUX;

Hello::Hello(QObject *parent) : QObject(parent)
{
    if(QSysInfo::productType() == "linux")
    {
        host_ = HOSTS::LINUX;
    }
    else if(QSysInfo::productType() == "windows")
    {
        host_ = HOSTS::WIN;
    }
    else if(QSysInfo::productType() == "darwin")
    {
        host_ = HOSTS::MACOSX;
    }
    else if(QSysInfo::productType() == "android")
    {
        host_ = HOSTS::ANDROIDD;
    }
}


int Hello::getHost(void) const
{
    return int(host_);
}