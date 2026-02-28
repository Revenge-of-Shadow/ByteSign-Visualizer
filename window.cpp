#include "window.h"
#include "renderarea.h"
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>

const int IdRole = Qt::UserRole;
Window::Window()
{
    ra = new RenderArea;

    l_L = new QLabel(tr("ASCII Symbol:"));
    l_B = new QLabel(tr("Binary:"));
    l_D = new QLabel(tr("Decimal:"));
    e_L = new QTextEdit();
    e_B = new QTextEdit();
    e_D = new QTextEdit();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(ra, 0,0,1,3);
    mainLayout->addWidget(l_L, 2,0, Qt::AlignLeft);
    mainLayout->addWidget(l_B, 2,1, Qt::AlignLeft);
    mainLayout->addWidget(l_D, 2,2, Qt::AlignLeft);
    mainLayout->addWidget(e_L, 3,0, Qt::AlignRight);
    mainLayout->addWidget(e_B, 3,1, Qt::AlignRight);
    mainLayout->addWidget(e_D, 3,2, Qt::AlignRight);

    connect(e_L, &QTextEdit::textChanged, this, &Window::changed);

    setLayout(mainLayout);

    setWindowTitle(tr("Oscilloscope simulation"));
}

void Window::changed(){
    int ch = e_L->toPlainText().toStdString()[0];
    e_D->setPlainText(QString(std::to_string(ch).c_str()));
    QString bin = "";
    for(int i = 0; i<8; ++i){
        bin.insert(0, QChar('0'+((ch>>i)&1)));
    }
    e_B->setPlainText(bin);
    ra->set(bin);
    ra->update();
}
