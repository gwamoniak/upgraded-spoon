#ifndef PIXMAPMIME_H
#define PIXMAPMIME_H

#include <QMimeData>
#include <QPixmap>

class PixmapMime : public QMimeData
{
    Q_OBJECT
public:
    explicit PixmapMime(QPixmap pixmap, QPoint offset, QString description);

    QPixmap pixmap() const;

    QPoint offset() const;

    QString description() const;

signals:

private:
    QPixmap mPixmap;
    QPoint  mOffset;
    QString mDescription;
    QStringList mimeFormats;

    // QMimeData interface
public:
    QStringList formats() const override;

    QStringList getMimeFormats() const;

protected:
    QVariant retrieveData(const QString &mimetype, QVariant::Type preferredType) const override;
};

#endif // PIXMAPMIME_H
