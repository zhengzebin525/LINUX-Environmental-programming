注意事项：

1、因为要用到TCP，所以必须在.pro文件中添加QT  +=  network
2、将QTcpServer对象信号与客户端关联起来的操作，要在监听操作之前完成（代码中有注释）

制作TCP协议服务器的流程：（以下都在代码中有注释声明）
(1)创建QTcpServer对象， 用于监听客户端链接；

(2)监听，通过对象方法listen；

(3)当有客户端链接，QTcpServer对象会发送newConnection信号，关联槽函数；

(4)在槽函数中接收链接（得到与客户端通信的套接字QTcpSocket对象）；

(5)如果向客户端发送， 通过QTcpSocket对象的write方法发送数据；

(6)如果服务器收到客户端的数据， QTcpSocket会发送readyRead读数据信号， 关联槽函数；

(7)在槽函数中读取数据，通过QTcpSocket的read方法读取；
