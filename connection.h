#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QProcess>

class connection : public QObject
{
    Q_OBJECT
public:
    explicit connection(QObject *parent = nullptr);

signals:
    void isConnected(bool val);

public slots:
    void checkConnection();

};

#endif // CONNECTION_H
