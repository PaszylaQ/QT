#include "gameBoard.h"

GameBoard::GameBoard(int tokenSize)
{
    this->tokenSize = tokenSize;
}

QRectF GameBoard::boundingRect() const
{
    return QRectF(0, 0, width*tokenSize,height*tokenSize);
}

QPainterPath GameBoard::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void GameBoard::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::blue);

    for(int i = 0; i < this->width; ++i)
    {
        for(int j = 0; j < this->height; ++j)
        {
            QPainterPath rectangle, circle, piece;
            QRect rect(i*tokenSize, j*tokenSize, tokenSize, tokenSize);
            rectangle.addRect(rect);
            circle.addEllipse(rect.center(), rect.width()/2 - 5, rect.height()/2 - 5);
            piece = rectangle - circle;
            painter->drawPath(piece);
        }
    }
}


