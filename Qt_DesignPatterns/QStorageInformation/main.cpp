#include <QCoreApplication>
#include <QList>
#include <QStorageInfo>
#include <QDebug>


void display(QStorageInfo &storage, QString title)
{
    qInfo() << "----" << title << "------";
    qInfo() << "Name: " << storage.name();
    qInfo() << "Display: " << storage.displayName();
    qInfo() << "Root: " << storage.isRoot();
    qInfo() << "Path: " << storage.rootPath();
    qInfo() << "Device: " << storage.device();
    qInfo() << "File System: " << storage.fileSystemType();
    qInfo() << "ReadOnly: " << storage.isReadOnly();
    qInfo() << "Ready: " << storage.isReady();
    qInfo() << "Size: " << storage.bytesTotal()/1000/1000<< "MB";
    qInfo() << "Avalible: " << storage.bytesAvailable()/1000/1000 <<"MB";
    qInfo() << "Free: " << storage.bytesFree()/1000/1000 << "MB";
    qInfo() << "---------------";

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //  getting to the root (/ or C:\)
    // root is always mounted
    QStorageInfo root = QStorageInfo::root();
    display(root,"Root");

    // mounted Devices
    QList<QStorageInfo> devices = QStorageInfo::mountedVolumes();
    foreach(QStorageInfo device, devices)
    {
        display(device,device.name());
    }

    return a.exec();
}
