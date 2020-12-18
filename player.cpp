#include "player.h"


Player::Player()
{
    color = Qt::black;
}

Player::Player(const Qt::GlobalColor& color)
{
    this->color = color;
    this->score = 0;
}

QColor Player::getColor() const
{
    return this->color;
}

int Player::getScore() const
{
    return score;
}

void Player::resetScore()
{
    score = 0;
}

void Player::win()
{
    score += 1;
}
