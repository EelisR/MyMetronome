#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , metronome_(new QTimer)
    , tempo_(120)
    , isRunning_(false)
{
    ui->setupUi(this);
    ui->tempoNumber->setDecMode();
    updateDisplay();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::startStop(){
    if (isRunning_){
        metronome_.stop();
    } else {
        // Laske metronomin matikka
    }
}

void MainWindow::moreTempo(){

    if (tempo_ == 0){
        ui->tempoMinus5->setDisabled(false);
    }

    tempo_ += 5;
    updateDisplay();
}

void MainWindow::lessTempo(){

    if (tempo_ - 5 == 0){
        ui->tempoMinus5->setDisabled(true);
    }

    tempo_ -= 5;
    updateDisplay();
}

void MainWindow::updateDisplay(){

    ui->tempoNumber->display(tempo_);
}

