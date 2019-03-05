#ifndef SOFTKEY_H
#define SOFTKEY_H

#include <QWidget>

namespace Ui {
class softkey;
}

class softkey : public QWidget
{
    Q_OBJECT

public:
    explicit softkey(QWidget *parent = 0);
    ~softkey();

private:
    Ui::softkey *ui;
};

#endif // SOFTKEY_H
