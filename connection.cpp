#include "connection.h"

connection::connection(QObject *parent) : QObject(parent)
{

}

void connection::checkConnection()
{
    QStringList parameters;
// #if defined(WIN32)
//    parameters << "-n" << "1";
// #else
    parameters << "-c 1";
// #endif

    parameters << "localhost";

    int exitCode = QProcess::execute("ping", parameters);
    if (exitCode==0) {
        // it's alive
        emit isConnected(true);
    } else {
        // it's dead
        emit isConnected(false);
    }
}
