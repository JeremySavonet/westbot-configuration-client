#include <QDebug>

#include "MainWindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    qDebug() << "Open tcp connection to";


}

void MainWindow::on_sendCommandButton_clicked()
{
    qDebug() << "Send cli command";

    // TODO: check connection
    // Evaluate command string
    // Format
    // Send
    // Handle response

    /*
    void sendMessage(QString msgToSend){
    QByteArray l_vDataToBeSent;
    QDataStream l_vStream(&l_vDataToBeSent, QIODevice::WriteOnly);
    l_vStream.setByteOrder(QDataStream::LittleEndian);
    l_vStream << msgToSend.length();
    l_vDataToBeSent.append(msgToSend);

    m_pTcpSocket->write(l_vDataToBeSent, l_vDataToBeSent.length());
    }
    */
}

void MainWindow::on_saveButton_clicked()
{
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
