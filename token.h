#ifndef TOKEN_H
#define TOKEN_H

#include <QGraphicsObject>
#include <QRectF>
#include <QColor>
#include <QPainter>
#include <QGraphicsScene>


class Token : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)
public:

    Token(const QRectF& start, const QColor& color, const qreal stopPoint);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF geometry() const;
    void setGeometry(const QRectF& rect);

private:
    QRectF rect;
    QColor color;
    qreal stopPoint;
};

#endif // TOKEN_H
