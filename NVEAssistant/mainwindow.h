#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

extern "C" {
    #include "LiteCAD.h"
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Quit_triggered();

    void on_actionOpen_triggered();

    void on_actionToolLine_triggered();

    void on_actionCmdExplode_triggered();

    void on_actionContext_help_triggered();

    void on_actionGrid_toggled(bool arg1);

    void on_actionCmdArc_triggered();

    void on_actionSave_triggered();

    void on_action_Configure_triggered();

private:
    Ui::MainWindow *ui;

    HANDLE m_hLcWnd;
    HANDLE g_hLcDrw;

    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent *event);
};

#endif // MAINWINDOW_H
