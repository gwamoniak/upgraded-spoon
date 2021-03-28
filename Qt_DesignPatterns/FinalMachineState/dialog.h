#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFinalState>
#include <QState>
#include <QStateMachine>
#include <QAbstractState>
#include <QMessageBox>
#include <QDebug>
// state machine example

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void stateEntered();
    void stateExited();
    void stateFinished();
private:
    Ui::Dialog *ui;
    QStateMachine m_statemachine;
    QList<QAbstractState*> m_states;
    void addState(QState *state);
};

#endif // DIALOG_H
