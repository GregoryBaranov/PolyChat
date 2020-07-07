#include "emojis.h"
#include <QFile>

Emojis::Emojis(){}

Emojis* Emojis::instance()
{
    static Emojis provider;
    return &provider;
}

QStringList Emojis::getEmoji()
{
    QFile file(":/Emoji/emoji.txt");
    QString allEmoji;

    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
       allEmoji = file.readAll();
    }

    QStringList listEmoji = allEmoji.split(";");
    listEmoji.removeLast();

    return listEmoji;
}
