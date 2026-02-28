#ifndef WINDOW_H
#define WINDOW_H

#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QTextEdit;
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
    QTextEdit *e_B;
    QTextEdit *e_D;
    QTextEdit *e_L;

};
#endif // WINDOW_H
