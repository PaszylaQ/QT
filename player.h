#ifndef PLAYER_H
#define PLAYER_H

#include <QColor>

class Player
{
public:
    Player();
    Player(const Qt::GlobalColor& color);
    QColor getColor() const;


    int getScore() const;
    void resetScore();
    void win();

private:
    int score;
    QColor color;
};

#endif // PLAYER_H
