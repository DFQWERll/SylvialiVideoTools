#include "mainwindow.h"
#include "./ui_mainwindow.h"
extern "C"
{
   #include <libavutil/log.h>
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   av_log_set_level(AV_LOG_DEBUG);
   av_log(NULL,AV_LOG_DEBUG,"extern c!!!!!\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

