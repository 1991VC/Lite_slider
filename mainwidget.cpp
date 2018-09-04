#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    size = 0;
    setGeometry(400, 400, 350, 200);
    setFixedSize(350,200);
    setWindowTitle("Test2");
    createWidgets();
}

MainWidget::~MainWidget()
{
    freeMem();
}

void MainWidget::createWidgets()
{
    pushButtonDown = new QPushButton(this);
    pushButtonDown->setGeometry(100, 20, 100, 30);
    pushButtonDown->setText("Down");

    pushButtonUp = new QPushButton(this);
    pushButtonUp->setGeometry(220, 20, 100, 30);
    pushButtonUp->setText("Up");

    slider = new QSlider(this);
    slider->setGeometry(40, 20, 30, 160);
//    slider->setOrientation(Qt::Horizontal); // Ориетнация виджетов!!!
//    slider->setMinimum(0);
//    slider->setMaximum(100);
    slider->setRange(0, 100);

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(100, 150, 220, 30);
//    progressBar->setOrientation(Qt::Vertical); // Ориетнация виджетов!!!
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(size);
}

void MainWidget::freeMem()
{
    delete pushButtonDown;
    pushButtonDown = nullptr;

    delete pushButtonUp;
    pushButtonUp = nullptr;

    delete progressBar;
    progressBar = nullptr;
}

void MainWidget::run()
{
    connect(pushButtonDown, SIGNAL(clicked()), this, SLOT(slotDownVal()));
    connect(pushButtonUp, SIGNAL(clicked()), this, SLOT(slotUpVal()));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slotSliderVal(int)));
}

void MainWidget::slotUpVal()
{
    if(!(size>=100)) size+=10;
    progressBar->setValue(size);
    slider->setValue(size);
}

void MainWidget::slotDownVal()
{
    if(!(size<=0)) size-=10;
    progressBar->setValue(size);
    slider->setValue(size);
}

void MainWidget::slotSliderVal(int val)
{
    if(!(size<0)&&!(size>100))
    progressBar->setValue(size=val);
}
