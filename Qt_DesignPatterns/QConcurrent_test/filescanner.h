#ifndef FILESCANNER_H
#define FILESCANNER_H

#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QtConcurrent>
#include <QFuture>

class FileScanner : public QObject
{
    Q_OBJECT
public:
    explicit FileScanner(QObject *parent = nullptr);
    ~FileScanner() = default;

    void scan(QString path);


    qint64 count() const;
    void setCount(const qint64 &count);

signals:
    void updated(int count);

private:
    int performScan(QString path);
    qint64 m_count;
};

#endif // FILESCANNER_H
