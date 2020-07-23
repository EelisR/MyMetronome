#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSound>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // Start the metronome
    void startStop();

    // Add tempo to the metronome
    void moreTempo();
    // Decrease the tempo of the metronome
    void lessTempo();

    void updateTempo();

    // Update the display whenever something changes
    void updateDisplay();
    void playTick();

    void keyPressEvent(QKeyEvent *event) override;
private:
    Ui::MainWindow *ui;
    QTimer *metronome_;
    QSound *tick_;
    qreal tempo_;
    bool isRunning_;
};
#endif // MAINWINDOW_H
