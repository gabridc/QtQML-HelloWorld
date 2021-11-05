#ifndef BROKER_BROKER_H
#define BROKER_BROKER_H
#include <QObject>

class Hello : public QObject
{
    Q_OBJECT

public:
    explicit Hello(QObject *parent = nullptr);


    enum class HOSTS{
        WIN = 0,
        MACOSX = 1,
        LINUX = 2,
        ANDROIDD = 3,
        IOS = 4
    };

public slots:
    int getHost(void) const;

private:
    static HOSTS host_;
};


#endif //BROKER_BROKER_H