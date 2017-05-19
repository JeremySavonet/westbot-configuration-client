// Copyright (c) 2016-2017 All Rights Reserved WestBot

#ifndef WESTBOT_CONFIGURATIONCLIENT_HPP
#define WESTBOT_CONFIGURATIONCLIENT_HPP

#include <QObject>
#include <QTcpSocket>

class QByteArray;
class QString;

namespace WestBot {

class ConfigurationClient : public QObject
{
public:
    ConfigurationClient( QObject* parent = nullptr );
    ~ConfigurationClient() override = default;

    bool connect( const QString& ip );
    void disconnect();

    void send( const QByteArray& message );

    bool isConnected() const;

private:
    void handleStateChange( QAbstractSocket::SocketState state );

    QTcpSocket _clientSocket;
    bool _isConnected;
};

}

#endif // WESTBOT_CONFIGURATIONCLIENT_HPP
