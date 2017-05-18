// Copyright (c) 2017 All Rights Reserved WestBot

#include <QByteArray>

#include "ConfigurationClient.hpp"

using namespace WestBot;

ConfigurationClient::ConfigurationClient()
{

}

bool ConfigurationClient::connect( const QString& ip )
{
    _clientSocket.connectToHost( "127.0.0.1", 9000 );
}

void ConfigurationClient::disconnect()
{
    _clientSocket.disconnectFromHost();
}

void ConfigurationClient::send( const QString& message )
{
//    QByteArray l_vDataToBeSent;
//    QDataStream l_vStream(&l_vDataToBeSent, QIODevice::WriteOnly);
//    l_vStream.setByteOrder(QDataStream::LittleEndian);
//    l_vStream << msgToSend.length();
//    l_vDataToBeSent.append(msgToSend);

//    m_pTcpSocket->write(l_vDataToBeSent, l_vDataToBeSent.length());
}
