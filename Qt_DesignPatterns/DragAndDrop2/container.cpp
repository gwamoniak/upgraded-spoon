#include "container.h"
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include <QDataStream>
#include <QMimeData>
#include <QDrag>
#include <QDebug>


Container::Container(QWidget *parent) : QWidget(parent)
{

    setMinimumSize(150,150);

    setAcceptDrops(true);

    QLabel * qtIcon = new QLabel(this);
    qtIcon->setPixmap(QPixmap(":/images/qt.png"));
    qtIcon->move(20,20);
    qtIcon->show();
    qtIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel * cppIcon = new QLabel(this);
    cppIcon->setPixmap(QPixmap(":/images/cpp.png"));
    cppIcon->move(150,20);
    cppIcon->show();
    cppIcon->setAttribute(Qt::WA_DeleteOnClose);

    QLabel * terminalIcon = new QLabel(this);
    terminalIcon->setPixmap(QPixmap(":/images/terminal.png"));
    terminalIcon->move(20,150);
    terminalIcon->show();
    terminalIcon->setAttribute(Qt::WA_DeleteOnClose);

}

void Container::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        startPos = event->pos();

    QWidget::mousePressEvent(event);

}

void Container::mouseMoveEvent(QMouseEvent *event)
{

    if (event->buttons() & Qt::LeftButton)
    {
        int distance =(event->pos() - startPos).manhattanLength();

        if(distance >= QApplication::startDragDistance())
        {
            QLabel *child = dynamic_cast<QLabel*>(childAt(event->pos()));

            if(!child)
                return;

            QPixmap cPixmap = *child->pixmap(); // need a fix ?
            QByteArray byteArray;
            QDataStream dataStream(&byteArray,QIODevice::WriteOnly);
            dataStream << cPixmap << QPoint(event->pos() - child->pos());

            QMimeData * mimeData = new QMimeData;

            mimeData->setData("application/x-qtcustomitem",byteArray);

            QDrag * drag = new QDrag(this);
            drag->setMimeData(mimeData);
            drag->setPixmap(cPixmap);
            drag->setHotSpot(event->pos() - child->pos());

            //Call to drag->exec() is blocking
            if(drag->exec(Qt::MoveAction | Qt::CopyAction,Qt::CopyAction)
                    == Qt::MoveAction)
            {
                //Move data
                qDebug()<< "Moving data";
                child->close();
            }
            else
            {
                //Copy action
                child->setPixmap(cPixmap);
                qDebug() << "Copying data";
            }

        }
    }

}

void Container::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qtcustomitem"))
    {


        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();

        }
        else
        {
            event->acceptProposedAction();
        }

    }
    else
    {
        event->ignore();
    }
}

void Container::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qtcustomitem"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }

    }
    else
    {
        event->ignore();
    }

}

void Container::dragLeaveEvent(QDragLeaveEvent *event)
{
    QWidget::dragLeaveEvent(event);

}

void Container::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qtcustomitem")) {

        QByteArray ba = event->mimeData()->data("application/x-qtcustomitem");
        QDataStream dataStream(&ba,QIODevice::ReadOnly);

        QPixmap mPixmap;
        QPoint offset;

        dataStream >> mPixmap >> offset;

        QLabel * newLabel = new QLabel(this);
        newLabel->setPixmap(mPixmap);
        newLabel->move(event->pos() - offset);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();

        }
        else
        {
            event->acceptProposedAction();
        }

    }
    else
    {
        event->ignore();
    }


}

void Container::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawRoundedRect(0,5,width()-10,height()-10,3,3);
    QWidget::paintEvent(event);
}
