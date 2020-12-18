#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsItem>
#include <QRectF>
#include <QObject>
#include <QPainterPath>
#include <QPainter>

class GameBoard : public QGraphicsItem{
public:
    GameBoard(int tokenSize);
    ~GameBoard() {};
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;


private:

    int tokenSize;
    const int width = 7;
    const int height = 6;


};

#endif // GAMEBOARD_H
