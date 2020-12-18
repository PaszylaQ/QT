#include "token.h"

Token::Token(const QRectF& rect, const QColor& color, qreal stopPoint): rect(rect), color(color), stopPoint(stopPoint){}

QRectF Token::boundingRect() const
{
    return rect;
}

QPainterPath Token::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Token::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(color);
    painter->setBrush(color);

    QPainterPath rectangle, circle, piece;
    rectangle.addRect(rect);
    circle.addEllipse(rect.center(), rect.width()/2 - 5, rect.height()/2 - 5);
    painter->drawPath(circle);
    scene()->update();
}

QRectF Token::geometry() const
{
    return boundingRect();
}

void Token::setGeometry(const QRectF& rect)
{
    this->rect = rect;
}
