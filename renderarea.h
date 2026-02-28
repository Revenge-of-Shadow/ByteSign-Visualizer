#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    bool bits[12];

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void set(QString bits);
    void paintEvent(QPaintEvent *event) override;
private:

signals:
};

#endif // RENDERAREA_H
