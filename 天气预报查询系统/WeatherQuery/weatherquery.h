#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

#include <QMainWindow>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QGraphicsBlurEffect>

#include <QMap>

namespace Ui {
class WeatherQuery;
}

class WeatherQuery : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeatherQuery(QWidget *parent = 0);
    ~WeatherQuery();

    QString WeatherType(QString intype);


private slots:

    void update_time();

    void read_cjson(QNetworkReply *repay);

    void on_SkinBt_clicked();

    void on_CheckBt_clicked();

    //事件过滤器
    bool eventFilter(QObject *watched, QEvent *event );   //参数1：过滤哪个对象  参数2：过滤对象的哪个事件

    void on_CloseBt_clicked();


private:
    Ui::WeatherQuery *ui;

    QNetworkAccessManager manager;   //管理器对象
    QTimer mtime;                    //时间对象

    QString city;
    QString date;
    QString high;
    QString low;
    QString fengxiang;
    QString fengli;
    QString type;
    QString ganmao;
    QString temperature;

    QMap<QString,QString> Citys;    //QMap<name,id> Citys


};

#endif // WEATHERQUERY_H
