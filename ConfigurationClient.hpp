// Copyright (c) 2017 All Rights Reserved WestBot

#ifndef WESTBOT_CONFIGURATIONCLIENT_HPP
#define WESTBOT_CONFIGURATIONCLIENT_HPP

#include <QObject>
#include <QTcpSocket>

class QByteArray;
class QString;

namespace WestBot {

class ConfigurationClient : public QObject
{
    Q_OBJECT

public:
    ConfigurationClient( QObject* parent = nullptr );
    ~ConfigurationClient() override = default;

    bool connectTo( const QString& ip );
    void disconnectFrom();

    void send( const QByteArray& message );

    bool isConnected() const;

signals:
    void connected();
    void disconnected();

private:
    void handleStateChange( QAbstractSocket::SocketState state );

    QTcpSocket _clientSocket;
    bool _isConnected;
};

}

#endif // WESTBOT_CONFIGURATIONCLIENT_HPP
