#include "renderarea.h"

#include <QPainter>
#include <QPainterPath>
#include <QPainterStateGuard>


RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(false);
    set(0);
}

QSize RenderArea::minimumSizeHint() const{
    return QSize(100, 100);
}
QSize RenderArea::sizeHint() const{
    return QSize(800, 600);
}

void RenderArea::set(QString b){
    bitstring = b;
    bits[0] = 1;
    if(b.isEmpty() || !b.contains('1')){
        bits[1] = 1;
        for(int i = 0; i<8;++i){
            bits[i+2] = 1;
        }
    }
    else{
        bits[1] = 0;
        for(int i = 0; i<8;++i){
            bits[i+2] = b.at(7-i)=='1';
        }
    }
    bits[10] = 1; bits[11] = 1;
}

void RenderArea::paintEvent(QPaintEvent *e){
    QBrush brush(Qt::GlobalColor::black, Qt::BrushStyle::SolidPattern);
    QRect canvas(10, 20, width()-10, height()-40);

    QPainter painter(this);
    painter.setPen(palette().dark().color());
    painter.setBrush(brush);
    painter.drawRect(QRect(0,0, width()-1, height()-1));

    brush.setColor(Qt::GlobalColor::yellow);
    painter.setPen(QPen(brush,2));

    float v_offset = canvas.height()/10.F;
    float h_step = canvas.width()/12.F;


    QPoint points[24];
    QPainterPath path;
    for(int i = 0; i<12; ++i){
        float height =
            !bits[i] ? v_offset : canvas.height()-v_offset;
        points[i*2] = QPoint(h_step*i, height);
        points[i*2+1] = QPoint(h_step*(i+1), height);
    }
    path.moveTo(points[0]);
    for(int i = 1; i<24; ++i){
        path.lineTo(points[i]);
    }


    painter.drawPath(path);

    if(showBits){
        painter.setFont(painter.font());
        painter.drawText(QPoint(1.25*h_step, canvas.height()-v_offset/2), "Stop");
        for(int i = 0; i<8; ++i){
            painter.drawText(QPoint((2.5+i)*h_step, canvas.height()-v_offset/2), bitstring.at(7-i));
        }
        painter.drawText(QPoint(canvas.width()-1.75*h_step, canvas.height()-v_offset/2), "Start");
    }

    brush.setColor(Qt::GlobalColor::black);
    painter.setPen(QPen(brush,2));
    painter.drawPoints(points, 24);



}

