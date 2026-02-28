#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
class QLabel;
class QTextEdit;
class QCheckBox;
QT_END_NAMESPACE
class RenderArea;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
private slots:
    void changed();
private:
    RenderArea * ra;
    QLabel *l_L;
    QLabel *l_B;
    QLabel *l_D;
    QLabel *l_S;
    QTextEdit *e_B;
    QTextEdit *e_D;
    QTextEdit *e_L;
    QCheckBox *cb_S;

};
#endif // WINDOW_H
