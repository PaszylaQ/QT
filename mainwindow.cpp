#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameBoard = new GameBoard(tokenSize);
    scene = new QGraphicsScene();
    controller = new Controller();
    currentPlayerColor = new QColor(Qt::red);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
     scene->addItem(gameBoard);

     view = ui->graphicsView;
     view->setScene(scene);
    //connect drop buttons
    signalMapper = new QSignalMapper(this);

    connect(ui->button1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button1, 0);

    connect(ui->button2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button2, 1);

    connect(ui->button3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button3, 2);

    connect(ui->button4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button4, 3);

    connect(ui->button5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button5, 4);

    connect(ui->button6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button6, 5);

    connect(ui->button7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button7, 6);

    connect(signalMapper, SIGNAL(mapped(int)), controller, SLOT(tryToDropTokenInColumn(int)));

    //connect reset button
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(resetGame()));
    connect(this, SIGNAL(resetBoard()), controller, SLOT(reset()));

    connect(ui->continueButton, SIGNAL(clicked()), controller, SLOT(continueGame()));

    connect(controller, SIGNAL(dropToken(int, int)), this, SLOT(dropToken(int, int)));

    connect(controller, SIGNAL(playerChanged(QColor)), this, SLOT(changeButtonsColor(QColor)));

    connect(controller, SIGNAL(gameStopped()), this, SLOT(disableButtons()));

    connect(controller, SIGNAL(updateScores(Player, Player)), this, SLOT(updateScores(Player, Player)));
}
void MainWindow::enableButtons(bool enable){
    ui->button1->setEnabled(enable);
    ui->button2->setEnabled(enable);
    ui->button3->setEnabled(enable);
    ui->button4->setEnabled(enable);
    ui->button5->setEnabled(enable);
    ui->button6->setEnabled(enable);
    ui->button7->setEnabled(enable);

}
void MainWindow::disableButtons(){
    this->enableButtons(false);
    ui->continueButton->setEnabled(true);

}

void MainWindow::changeButtonsColor(QColor playerColor){
    this->currentPlayerColor = new QColor(playerColor);
    this->changeButtonsColor();
}
void MainWindow::changeButtonsColor()
{
    QString dropButtonStyleShit = QString("background-color: %1").arg(currentPlayerColor->name());
    ui->button1->setStyleSheet(dropButtonStyleShit);
    ui->button2->setStyleSheet(dropButtonStyleShit);
    ui->button3->setStyleSheet(dropButtonStyleShit);
    ui->button4->setStyleSheet(dropButtonStyleShit);
    ui->button5->setStyleSheet(dropButtonStyleShit);
    ui->button6->setStyleSheet(dropButtonStyleShit);
    ui->button7->setStyleSheet(dropButtonStyleShit);
}

void MainWindow::resetScoreBoard(){
    ui->score1->setText("0");
    ui->score2->setText("0");

}

void MainWindow::resetGame()
{
    scene->clear();
    scene->addItem(new GameBoard(tokenSize));
    changeButtonsColor(Qt::red);
    enableButtons(true);
    ui->continueButton->setEnabled(false);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    view->fitInView(scene->sceneRect());
}
void MainWindow::dropToken(const int row , const int column){
    QRect rect(column*tokenSize, 0, tokenSize, tokenSize);
    Token* token = new Token(rect, *currentPlayerColor, row*tokenSize);
    token->setZValue(-1);
    scene->addItem(token);
    animation = new QPropertyAnimation(token, "geometry");
    animation->setDuration(150 * row);
    animation->setStartValue(rect);
    animation->setEndValue(QRect(column*tokenSize, row*tokenSize, tokenSize, tokenSize));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::updateScores(Player player1, Player player2)
{
    ui->score1->setText(std::to_string(player1.getScore()).c_str());
    ui->score2->setText(std::to_string(player2.getScore()).c_str());
    resetGame();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameBoard;
    delete scene;
    delete animation;
    delete signalMapper;
    delete currentPlayerColor;
}

