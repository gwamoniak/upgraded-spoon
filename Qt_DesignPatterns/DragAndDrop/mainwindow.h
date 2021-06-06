#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dragdroplabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mimeChanged(const QMimeData * mimedata);

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    DragDropLabel * dragDropLabel;

};
#endif // MAINWINDOW_H
