#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QColor>
#include <player.h>
#include <QVector>

class Controller : public QObject
{
        Q_OBJECT
public:
    Controller();

public slots:
    void continueGame();
    void reset();
    void tryToDropTokenInColumn(const int column);

signals:
    void playerChanged(QColor);
    void updateScores(Player, Player);
    void gameStopped();
    void dropToken(const int row , const int);

private:
    enum { BoardWidth = 7, BoardHeight = 6};
    const int WIN_CELLS = 4;
    const QColor BACKGROND_COLOR = Qt::white;
    bool isStopped;
    QPair<Player, Player> players;
    int curPlayer;
    QVector<QVector<QColor>> board;


    void clearBoard();
    bool checkIfWin();
    bool tryHorizontal(int row, int column, QColor color);
    bool tryVetical(int row, int column, QColor color);
    bool tryLeftDiag(int row, int column, QColor color);
    bool tryRightDiag(int row, int column, QColor color);
    bool tryMove();
    QColor getCurrPlayerColor();
    void playerWin();
    void noMoreMoves();


};

#endif // CONTROLLER_H
