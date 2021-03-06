// Copyright (c) 2017 All Rights Reserved WestBot

#include <QByteArray>
#include <QString>

#include "ConfigurationClient.hpp"

using namespace WestBot;

ConfigurationClient::ConfigurationClient( QObject* parent )
    : QObject( parent )
    , _isConnected( false )
{
    connect(
        & _clientSocket,
        & QAbstractSocket::stateChanged,
        this,
        & ConfigurationClient::handleStateChange );
}

bool ConfigurationClient::connectTo( const QString& ip )
{
    _clientSocket.connectToHost( ip, 57497 );

    if( ! _clientSocket.waitForConnected( 3000 ) )
    {
        _isConnected = false;
        return _isConnected;
    }

    _isConnected = true;
    return _isConnected;
}

void ConfigurationClient::disconnectFrom()
{
    _clientSocket.disconnectFromHost();
    _isConnected = false;
}

bool ConfigurationClient::isConnected() const
{
    return _isConnected;
}

void ConfigurationClient::send( const QByteArray& message )
{
    _clientSocket.write( message, message.length() );
    qDebug() << "Data" << message;
}

// Private methods
void ConfigurationClient::handleStateChange( QAbstractSocket::SocketState state )
{
    if( state == QAbstractSocket::ConnectedState )
    {
        emit ConfigurationClient::connected();
        _isConnected = true;
    }
    else
    {
        emit ConfigurationClient::disconnected();
        _isConnected = false;
    }
}
