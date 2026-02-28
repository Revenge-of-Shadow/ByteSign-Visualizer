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
    l_S = new QLabel(tr("Show bits:"));
    e_L = new QTextEdit();
    e_B = new QTextEdit();
    e_D = new QTextEdit();
    cb_S = new QCheckBox();
    e_L->setMaximumHeight(20);
    e_B->setMaximumHeight(20);
    e_D->setMaximumHeight(20);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(ra, 0,0,1,8);
    mainLayout->addWidget(l_L, 2,0, Qt::AlignLeft);
    mainLayout->addWidget(e_L, 2,1, Qt::AlignRight);

    mainLayout->addWidget(l_B, 2,2, Qt::AlignLeft);
    mainLayout->addWidget(e_B, 2,3, Qt::AlignRight);

    mainLayout->addWidget(l_D, 2,4, Qt::AlignLeft);
    mainLayout->addWidget(e_D, 2,5, Qt::AlignRight);

    mainLayout->addWidget(l_S, 2,6, Qt::AlignLeft);
    mainLayout->addWidget(cb_S, 2,7, Qt::AlignRight);

    connect(e_L, &QTextEdit::textChanged, this, &Window::changed);
    connect(cb_S, &QCheckBox::checkStateChanged, this, &Window::changed);

    setLayout(mainLayout);

    setWindowTitle(tr("Oscilloscope simulation"));
}

void Window::changed(){
    ra->showBits = cb_S->checkState();

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
