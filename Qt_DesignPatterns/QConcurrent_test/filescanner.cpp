#include "filescanner.h"

FileScanner::FileScanner(QObject *parent) : QObject(parent)
{

}

void FileScanner::scan(QString path)
{

    qInfo() << "Scan on: " << QThread::currentThread();
    m_count = 0;


    QFuture<int> future = QtConcurrent::run(this,&FileScanner::performScan, path);

    //Main thread isn't  blocked, we can do what to desire
    qInfo() << "Main thread is free to do what you desire...";


    qInfo() << "Result: " << future.result(); //get the result from the Concurrent thread


}

qint64 FileScanner::count() const
{
    return m_count;
}

void FileScanner::setCount(const qint64 &count)
{
    m_count = count;
}

int FileScanner::performScan(QString path)
{
    // Runs on the ThreadPool

        int value = 0;
        QDir dir(path);
        if(!dir.exists()) return -1;

        QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);
        value = list.length();

        emit updated(value);

        foreach(QFileInfo item, list)
        {
            value = value + performScan(item.filePath());
        }

        return value;
}
