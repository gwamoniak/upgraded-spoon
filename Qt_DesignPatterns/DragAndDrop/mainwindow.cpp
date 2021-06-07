#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dragDropLabel = new DragDropLabel(this);
    connect(dragDropLabel,&DragDropLabel::mimeChanged,this,&MainWindow::mimeChanged);
    ui->labelLayout->addWidget(dragDropLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mimeChanged(const QMimeData *mimedata)
{
    ui->textEdit->clear();
    if(!mimedata)
        return;

    if(mimedata->hasImage() && mimedata->hasUrls())
    {
        QList<QUrl> urls = mimedata->urls();
              if(urls.count() > 1)
                   return;

        QFileInfo file(urls.at(0).toLocalFile());
               QPixmap mPixmap;
               if(dragDropLabel->isImage(file.absoluteFilePath()) && (mPixmap.load(file.absoluteFilePath()))){
                  ui->picture->setPixmap(mPixmap.scaled(ui->picture->size())) ;
               }

    }

    QStringList formats = mimedata->formats();
    for( int i= 0; i < formats.size();i++)
    {

        QString text;
        if (formats[i] == QString("text/plain"))
        {
            text = mimedata->text().simplified();
        }
        else if (formats[i] == QString("text/html"))
        {
            text = mimedata->html().simplified();
        }
        else if (formats[i] == QString("text/uri-list"))
        {
            QList<QUrl> urlList = mimedata->urls();
            for (int i = 0; i < urlList.size(); ++i)
                text.append(urlList.at(i).toString() + " -/- ");
        }
        else
        {
            QByteArray data = mimedata->data(formats[i]);
            for (int i = 0; i < data.size() ; ++i)
                text.append(QString("%1 ").arg(uchar(data[i])));
        }

        QString dataString = QString("%1 | Format : %2 \n    | Data : %3 \n------------")
                .arg(i)
                .arg(formats[i])
                .arg(text);

        ui->textEdit->append(dataString);
    }

}

void MainWindow::on_clearButton_clicked()
{

}


