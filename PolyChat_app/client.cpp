#include "client.h"
#include <QInputDialog>
#include "mainwindow.h"
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkAccessManager>


Client::Client(QObject *parent) : QObject(parent)
{
    clientSocket = new QWebSocket();
    connect(clientSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(onReceiveMessage(QString)));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));


    QNetworkRequest request(QUrl("https://ip.up66.ru/"));
        QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
        connect(mngr, SIGNAL(finished(QNetworkReply*)), SLOT(getResponse(QNetworkReply*)));
        connect(downloader, SIGNAL(onReady(QString)), this, SLOT(readFile(QString)));
        mngr->get(request);

}

/* Сокет для обработки разьединения с сервером
 */
void Client::onDisconnected()
{
    clientSocket->deleteLater();
}

/* Соединяется с сервером
 */
void Client::connectSocket(const QString& host, unsigned int port)
{
    if (clientSocket != NULL && clientSocket->isValid())
    {
        return; // Necessary to check and close (or return) connection if it is open
    }

    _port = port;
    _host = host;

    QUrl qUrl;
    qUrl.setPort(_port);
    qUrl.setHost(_host);
    qUrl.setScheme("ws");

//    connect(clientSocket, SIGNAL(connected()), SLOT(slotConnected()));

    clientSocket->open(qUrl);
}

// Отправляет текстовое сообщение

void Client::sendMessage(const QString& message)
{

    clientSocket->sendTextMessage(message);

}



void Client::getResponse(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
    ip = reply->readAll();
    emit onReady(ip);
}

void Client::requestExternalAddress(){
    /////////////////////
}

// Слот для приема сообщений

void Client::onReceiveMessage(QString message)
{

        emit receiveMessage(message);

}