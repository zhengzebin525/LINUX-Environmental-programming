#include "photoshow.h"
#include "ui_photoshow.h"
#include <QDebug>
#include <QFile>
#include <QDir>

PhotoShow::PhotoShow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PhotoShow)
{
    ui->setupUi(this);

    //将管理器与photo_list()关联
    //一旦管理器manager发送报文成功，就会产生一个finished信号，执行槽函数，显示图片列表
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(ptoto_list(QNetworkReply*)));

    //一运行程序立马出现图片列表
    QUrl url("http://192.168.90.210/photo/list");
    QNetworkRequest request(url);
    manager.get(request);


    //将管理器与read_data（）关联
    //一旦管理器datamanager发送报文成功，就会产生一个finished信号，执行槽函数，读取图片数据显示出来
    connect(&datamanager,SIGNAL(finished(QNetworkReply*)),this,SLOT(read_data(QNetworkReply*)));

}

PhotoShow::~PhotoShow()
{
    delete ui;
}

//文件夹中的图片列表
void PhotoShow::ptoto_list(QNetworkReply* reply)
{

    ui->Photolist->clear();        //清空列表
    while(reply->canReadLine())    //检测应答数据中是否有可读行，如果有，返回真
    {
        QString msg = reply->readLine();
        msg.remove("\n");               //删除可读行中的“\n”
        ui->Photolist->addItem(msg);    //将可读行添加到ui界面列表显示出来，即将jpg文件名一个一个列出来
    }

}

//点击图片列表中的某个jpg，将图片显示出来
//采用本地保存的方法将当前图片保存到当前工程文件中
void PhotoShow::on_Photolist_clicked(const QModelIndex &index)
{
    //获取图片列表中用户点击的图片文件名
    filename = ui->Photolist->currentItem()->text();


    QDir mdir;
    if(mdir.mkpath("photo"))         //mkpath（）函数自带了检测文件夹是否存在，如果存在了就不会创建
    {
        qDebug()<<"创建本地图片文件夹photo成功";
    }

    QFile file("photo/"+filename);

    if(file.exists())       //判断文件夹对象是否存在，即判断工程文件中有没有photo这个文件夹
    {
        read_data(NULL);    //执行read_data（）这个函数的时候就不用应答数据了，图片数据直接可以在本地文件中获取
    }
    else                    //如果没有photo这个文件夹，就直接发送http报文，去网络上获取图片
    {

        QUrl url(QString("http://192.168.90.210/photo/%1").arg(filename));
        QNetworkRequest request(url);
        datamanager.get(request);

    }
}


//读取图片数据，将图片显示出来
void PhotoShow::read_data(QNetworkReply* reply)
{
    QByteArray array;

    if(reply != NULL)
    {
        array = reply->readAll();

        QFile file("photo/"+filename);      //创建一个文件对象，即photo/xx.jpg

        file.open(QIODevice::WriteOnly);    //将photo/xx.jpg这个文件以只写形式打开

        file.write(array);            //将数组array中获取到的图片数据全部写进photo/xx.jpg中

        file.close();                //写完后关闭文件，至此这个xx.jpg图片就被保存到了photo文件夹中了
    }
    else
    {
        QFile file("photo/"+filename);    //创建一个文件对象，即photo/xx.jpg

        file.open(QIODevice::ReadOnly);    //将photo/xx.jpg这个文件以只读形式打开

        array = file.readAll();           //读取photo/xx.jpg这个文件所有数据，并放在数组array中

        file.close();                       //读取完后关闭文件
    }

    //将图片数据显示出来
    QPixmap pix;
    pix.loadFromData(array);

    pix = pix.scaled(ui->photolabel->size());

    ui->photolabel->setPixmap(pix);
}

//菜单中“clear”选项的槽函数
void PhotoShow::on_actionClear_triggered()
{
    QDir dir("photo");             //找到photo这个目录对象
    dir.removeRecursively();       //删除photo文件夹，包括里面的所有内容

    QDir mdir;
    mdir.mkpath("photo");          //然后再创建photo文件夹，就可以造成里面的所有图片被删除的现场
}

//菜单中“update”选项的槽函数
void PhotoShow::on_actionUpdata_triggered()
{
    //重新获取列表信息
    QUrl url("http://192.168.90.210/photo/list");
    QNetworkRequest request(url);
    manager.get(request);

}
