// Copyright (c) 2016-2017 All Rights Reserved WestBot

#ifndef WESTBOT_CONFIGURATIONCLIENT_HPP
#define WESTBOT_CONFIGURATIONCLIENT_HPP

#include <QTcpSocket>

class QString;

namespace WestBot {

class ConfigurationClient
{
public:
    ConfigurationClient();

    bool connect( const QString& ip );
    void disconnect();

    void send( const QString& message );

private:
    QTcpSocket _clientSocket;
};

}

#endif // WESTBOT_CONFIGURATIONCLIENT_HPP
