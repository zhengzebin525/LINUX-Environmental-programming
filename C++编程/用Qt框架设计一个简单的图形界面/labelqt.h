#ifndef LABELQT_H
#define LABELQT_H

#include <QMainWindow>

namespace Ui {
class labelQt;
}

class labelQt : public QMainWindow
{
    Q_OBJECT

public:
    explicit labelQt(QWidget *parent = 0);
    ~labelQt();

private slots:
    void on_pushButton_clicked();

    void on_login_clicked();

private:
    Ui::labelQt *ui;
};

#endif // LABELQT_H
