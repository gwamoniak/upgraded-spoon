#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    for (auto i =0; i < 10 ; i++ ) {
        QState *state = new QState();
        state->setObjectName("State" + QString::number(i));
        addState(state);
    }
    // states added as children
    qInfo() << "Children: " << m_statemachine.children().length();

    // add final state
    QFinalState *final = new QFinalState();
    QState *p = qobject_cast<QState*>(m_states.last());
     p->addTransition(ui->pushButton,&QPushButton::clicked,final);

     connect(&m_statemachine,&QStateMachine::finished,this,&Dialog::stateFinished);

     m_statemachine.addState(final);
     m_statemachine.setInitialState(m_states.at(0));
     m_statemachine.start();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    if(m_statemachine.isRunning()) qInfo() <<"Clicked";
}

void Dialog::stateEntered()
{
        qInfo() << sender() <<"Entered";
}

void Dialog::stateExited()
{
        qInfo() << sender() <<"Exited";
}

void Dialog::stateFinished()
{
        qInfo() << sender() <<"Finished";
        ui->lineEdit->setText("Completed");
        ui->pushButton->setEnabled(false);
        QMessageBox::information(this,"Finished", "The state machine has finished");
}

void Dialog::addState(QState *state)
{
    state->assignProperty(ui->lineEdit,"text",state->objectName());
    auto i = m_states.length();
    if(i >0)
    {
        QState *p = qobject_cast<QState*>(m_states.at(i-1));
        p->addTransition(ui->pushButton,&QPushButton::clicked,state);

    }

    connect(state,&QState::entered,this,&Dialog::stateEntered);
    connect(state,&QState::exited,this,&Dialog::stateExited);
    connect(state,&QState::finished,this,&Dialog::stateFinished);
    m_states.append(state);
    m_statemachine.addState(state);
}
