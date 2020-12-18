#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include <QSignalMapper>
#include <controller.h>
#include <QColor>
#include <gameBoard.h>
#include <QApplication>
#include <QWidget>
#include <QObject>
#include <token.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event) override;

public slots:
    void dropToken(const int, const int);
    void changeButtonsColor(QColor);
    void disableButtons();
    void resetGame();
    void updateScores(Player, Player);
signals:
    void resetBoard();

private:
    GameBoard *gameBoard;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QColor *currentPlayerColor;
    QPropertyAnimation *animation;
    QSignalMapper *signalMapper;
    Controller *controller;

    const int tokenSize = 500;
    void enableButtons(bool);
    void resetWindow();
    void changeButtonsColor();
    void resetScoreBoard();
};
#endif // MAINWINDOW_H
