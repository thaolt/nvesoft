#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QResizeEvent>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    int style = LC_WS_HSCROLL | LC_WS_VSCROLL | LC_WS_BORDER | LC_WS_VIEWTABS;
    int style = LC_WS_DEFAULT | LC_WS_RULERS;
    this->lcHWND = lcCreateWindow((HWND)ui->lcFrame->winId(),style);
    if (lcHWND == 0) {
        QMessageBox::critical(this, "Error!", "Can not create drawing canvas");
    }
    ui->statusBar->hide();
    this->showMaximized();

    // Create LiteCAD drawing
    g_hLcDrw = lcCreateDrawing();
    lcDrwNew( g_hLcDrw, L"", lcHWND);
    // Set background color for Model space
//    lcPropPutInt( g_hLcDrw, LC_PROP_DRW_COLORBACKM, RGB(120,120,120) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    lcUninitialize(true);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    lcWndResize(this->lcHWND,ui->lcFrame->frameRect().x(),
                ui->lcFrame->frameRect().y(),
                ui->lcFrame->frameRect().width(),
                ui->lcFrame->frameRect().height());
    lcWndRedraw(this->lcHWND);
}

void MainWindow::on_action_Quit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open file"));
    lcDrwLoad(this->g_hLcDrw,(const wchar_t*)filename.utf16(),this->lcHWND);
}

void MainWindow::on_actionToolLine_triggered()
{

}
