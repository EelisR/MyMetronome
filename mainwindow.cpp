/***
 * This linux thing sure is hard amirite
 * HEYHEY my QtCreator works again!!
 *
 *
 * */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , metronome_(new QTimer)
    , tick_(new QSound("/home/eelisroininen/Repos/MyMetronome/tick.wav"))
    , tempo_(120)
    , isRunning_(false)
{
    ui->setupUi(this);
    ui->tempoNumber->setDecMode();
    updateDisplay();

    tick_->setLoops(1);
    connect(metronome_, &QTimer::timeout, this, &MainWindow::playTick);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up){
        moreTempo();
    }
    if (event->key() == Qt::Key_Down){
        lessTempo();
    }
    if (event->key() == Qt::Key_Space){
        startStop();
    }
}

void MainWindow::startStop(){
    if (isRunning_){
        metronome_->stop();
        isRunning_ = false;
    } else {
        updateTempo();
        isRunning_ = true;
        metronome_->start();
    }
}

void MainWindow::moreTempo(){

    if (tempo_ == 0){
        ui->tempoMinus5->setDisabled(false);
    }

    tempo_ += 5;
    updateTempo();
    updateDisplay();
}

void MainWindow::lessTempo(){

    if (tempo_ - 5 == 0){
        ui->tempoMinus5->setDisabled(true);
    }

    tempo_ -= 5;
    updateTempo();
    updateDisplay();
}

void MainWindow::updateTempo()
{
    unsigned int realTempo = (60/tempo_) * 1000;
    metronome_->setInterval(realTempo);
}

void MainWindow::updateDisplay(){

    ui->tempoNumber->display(tempo_);
}

void MainWindow::playTick(){
    tick_->play();
}
