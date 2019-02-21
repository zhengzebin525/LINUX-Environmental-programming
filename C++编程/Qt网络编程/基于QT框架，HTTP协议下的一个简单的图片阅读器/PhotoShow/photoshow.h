#ifndef PHOTOSHOW_H
#define PHOTOSHOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QFileDialog>
#include <QDir>
#include <QFile>

namespace Ui {
class PhotoShow;
}

class PhotoShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhotoShow(QWidget *parent = 0);
    ~PhotoShow();

protected slots:
    void ptoto_list(QNetworkReply *reply);


private slots:
    void on_Photolist_clicked(const QModelIndex &index);

    void read_data(QNetworkReply *reply);
    void on_actionClear_triggered();

    void on_actionUpdata_triggered();

private:
    Ui::PhotoShow *ui;

    //创建一个管理器对象
    QNetworkAccessManager manager;
    QNetworkAccessManager datamanager;

    QString filename;   //保存当前文件名
};

#endif // PHOTOSHOW_H
