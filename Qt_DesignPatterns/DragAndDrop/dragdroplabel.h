#ifndef DRAGDROPLABEL_H
#define DRAGDROPLABEL_H

#include <QLabel>
#include <QMimeData>
#include <QFileInfo>

class DragDropLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DragDropLabel(QWidget *parent = nullptr);
        bool isImage(QString fullPath);

signals:
    void mimeChanged(const QMimeData * mimeData = nullptr);

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    void clear();


};

#endif // DRAGDROPLABEL_H
