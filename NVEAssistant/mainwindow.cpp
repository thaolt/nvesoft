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
    this->m_hLcWnd = lcCreateWindow((HWND)ui->lcFrame->winId(),style);
    if (m_hLcWnd == 0) {
        QMessageBox::critical(this, "Error!", "Can not create drawing canvas");
    }
    ui->statusBar->hide();



    // Create LiteCAD drawing
    g_hLcDrw = lcCreateDrawing();
    lcDrwNew( g_hLcDrw, L"", m_hLcWnd);
    // Set background color for Model space
//    lcPropPutInt( g_hLcDrw, LC_PROP_DRW_COLORBACKM, RGB(120,120,120) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED( event );
    lcUninitialize(true);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED( event );
    lcWndResize(this->m_hLcWnd,ui->lcFrame->frameRect().x(),
                ui->lcFrame->frameRect().y(),
                ui->lcFrame->frameRect().width(),
                ui->lcFrame->frameRect().height());
    lcWndRedraw(this->m_hLcWnd);
}

void MainWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED( event );
    lcWndResize(this->m_hLcWnd,ui->lcFrame->frameRect().x(),
                ui->lcFrame->frameRect().y(),
                ui->lcFrame->frameRect().width(),
                ui->lcFrame->frameRect().height());
    lcWndRedraw(this->m_hLcWnd);
}

void MainWindow::on_action_Quit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open file"));
    lcDrwLoad(this->g_hLcDrw,(const wchar_t*)filename.utf16(),this->m_hLcWnd);
}

void MainWindow::on_actionToolLine_triggered()
{
    lcWndExeCommand(this->m_hLcWnd, LC_CMD_LINE, 0);
}

void MainWindow::on_actionCmdExplode_triggered()
{
    lcWndExeCommand(this->m_hLcWnd, LC_CMD_EXPLODE, 0);
}

void MainWindow::on_actionContext_help_triggered()
{
    lcWndExeCommand(this->m_hLcWnd, LC_CMD_HELP, 0);
}

void MainWindow::on_actionGrid_toggled(bool arg1)
{
    Q_UNUSED( arg1 );
    lcWndExeCommand(this->m_hLcWnd, LC_CMD_SW_GRID, 0);
}

void MainWindow::on_actionCmdArc_triggered()
{
    lcWndExeCommand(this->m_hLcWnd, LC_CMD_ARC, LC_ARC_SME);
}

void MainWindow::on_actionSave_triggered()
{
    lcDrwSave(this->g_hLcDrw, L"D:\\test.lcd", false, this->m_hLcWnd);
}

void MainWindow::on_action_Configure_triggered()
{

}
