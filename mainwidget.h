#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QProgressBar>
#include<QSlider>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

protected:
    QPushButton *pushButtonDown;
    QPushButton *pushButtonUp;
    QProgressBar *progressBar;
    QSlider *slider;

    qint32 size;

    void createWidgets();
    void freeMem();
public:
    void run();

//signals:

protected slots:
    void slotUpVal();
    void slotDownVal();
    void slotSliderVal(int val);

};

#endif // MAINWIDGET_H
