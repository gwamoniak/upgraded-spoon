#include "pixmapmime.h"



PixmapMime::PixmapMime(QPixmap pixmap, QPoint offset, QString description):
    mPixmap(pixmap),
    mOffset(offset),
    mDescription(description)
{
    mimeFormats << "text/html" << "text/plain";

}

QPixmap PixmapMime::pixmap() const
{
    return mPixmap;
}

QPoint PixmapMime::offset() const
{
    return mOffset;
}

QString PixmapMime::description() const
{
    return mDescription;
}

QStringList PixmapMime::getMimeFormats() const
{
    return mimeFormats;
}

QStringList PixmapMime::formats() const
{
    return  mimeFormats;
}

QVariant PixmapMime::retrieveData(const QString &mimetype, QVariant::Type preferredType) const
{
    if(mimetype == "text/plain")
    {
        return  mDescription;
    }
    else if(mimetype == "text/html")
    {
        QString htmlString ;
        htmlString.append( "<html><p>" );
        htmlString.append(mDescription) ;
        htmlString.append("</p></html>");

        return  htmlString;

    }
    else
    {
        return  QMimeData::retrieveData(mimetype,preferredType);

    }

}
