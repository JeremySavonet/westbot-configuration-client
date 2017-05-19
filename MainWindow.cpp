// Copyright (c) 2016-2017 All Rights Reserved WestBot

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "MainWindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _client( this )
{
    ui->setupUi(this);

    ui->sendCommandButton->setEnabled( false );
    ui->cliCommandTxt->setEnabled( false );
    ui->cliDebugTxt->setEnabled( false );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if( _client.isConnected() )
    {
        _client.disconnect();

        if( ! _client.isConnected() )
        {
            ui->connectButton->setText( "Connect" );
            ui->ipAddressTxt->setEnabled( true );

            ui->sendCommandButton->setEnabled( false );
            ui->cliCommandTxt->setEnabled( false );
            ui->cliDebugTxt->setEnabled( false );
        }

        return;
    }

    qDebug() << "Open tcp connection to";
    _client.connect( ui->ipAddressTxt->text() );

    if( ! _client.isConnected() )
    {
        qDebug() << "Failed to connect to Robot";
        return;
    }

    ui->connectButton->setText( "Disconnect" );
    ui->ipAddressTxt->setEnabled( false );
    ui->sendCommandButton->setEnabled( true );
    ui->cliCommandTxt->setEnabled( true );
    ui->cliDebugTxt->setEnabled( true );
}

void MainWindow::on_sendCommandButton_clicked()
{
    _client.send( ui->cliCommandTxt->text().toLatin1() );
}

void MainWindow::on_saveButton_clicked()
{
    QJsonObject recordObject;
    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonObject addressObject;
    addressObject.insert("Street", "Downing Street 10");
    addressObject.insert("City", "London");
    addressObject.insert("Country", "Great Britain");
    recordObject.insert("Address", addressObject);

    QJsonArray phoneNumbersArray;
    phoneNumbersArray.push_back("+44 1234567");
    phoneNumbersArray.push_back("+44 2345678");
    recordObject.insert("Phone Numbers", phoneNumbersArray);

    QJsonDocument doc(recordObject);
    qDebug() << doc.toJson();

    _client.send( doc.toJson() );
    qDebug() << "Save configuration parameters to robot";
}

void MainWindow::on_loadButton_clicked()
{
    qDebug() << "Load parameters configuration from robot";
}

void MainWindow::on_ipAddressTxt_textChanged( const QString& arg1 )
{
    qDebug() << "Text changed to" << arg1;
}
