// Copyright (c) 2017 All Rights Reserved WestBot

#ifndef WESTBOT_MAINWINDOW_HPP
#define WESTBOT_MAINWINDOW_HPP

#include <QMainWindow>

#include <ConfigurationClient.hpp>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();
    void on_sendCommandButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    void on_ipAddressTxt_textChanged( const QString& arg1 );

private:
    void displayConnected();
    void displayDisconnected();

    Ui::MainWindow *ui;
    WestBot::ConfigurationClient _client;
};

#endif // WESTBOT_MAINWINDOW_HPP
