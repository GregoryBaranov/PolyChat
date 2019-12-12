#include "messageviewdelegate.h"
#include <QApplication>
#include <QPushButton>
#include <QPainter>
#include <styleapp.h>
#include <QComboBox>
#include <QDateTime>
#include <QDebug>
#include <QLabel>

#define ICON_SIZE 32
#define OFFSET_H 16
#define CHECK_WIDTH 50
#define PROGRESS_HEIGHT 21
#define OFFSET_BUTTON 5
#define DETAIL_OFFSET 30

#define ITEM_HEIGHT 64
#define HEADER_HEIGHT 64

#define STRIPE_WIDTH 30

MessageViewDelegate::MessageViewDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

QWidget *MessageViewDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
    return nullptr;
}
void MessageViewDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
}
void MessageViewDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
}
void MessageViewDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}


void MessageViewDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setBackground(QBrush(QColor(51,50,51)));
    painter->restore();

    painter->save();
    paintObject(painter, option, index);
    painter->restore();

    painter->save();
    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
    painter->restore();
}

void MessageViewDelegate::paintObject(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    QString name = index.data(ListMessageModel::DetailRole).toString();
    QString description = index.data(ListMessageModel::DescriptionRole).toString();

    QRect rect(option.rect.topLeft(), option.rect.bottomRight());

    QPainter &p = *painter;
    p.save();
    paintSetIcon(painter, option, index);
    p.restore();

    rect.setLeft(rect.left() + 68);

    p.save();
    rect.setTop(rect.top() + 5);
    rect.setRight(rect.right());
    p.drawText(rect, Qt::TextWordWrap , name);
    p.restore();

    rect.setTop(rect.top() + 30);
    rect.setRight(rect.right());

    p.drawText(rect, Qt::TextWordWrap, description);
}

void MessageViewDelegate::paintSetIcon( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    QPainter &p = *painter;
    p.translate(option.rect.topLeft());
    if(index.data(Qt::DecorationRole) != ListMessageModel::RoleStudent)
    {
        p.drawImage(0,5, QImage(":/image/techer.png"));
    }
    else
    {
        p.drawImage(0,5, QImage(":/image/lerner.png"));
    }
}

QSize MessageViewDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QFontMetrics fm(option.font);
    const QAbstractItemModel* model = index.model();
    QString Text = model->data(index, ListMessageModel::DescriptionRole ).toString();
    QRect neededsize = fm.boundingRect( option.rect, Qt::TextWordWrap, Text);

    return QSize(option.rect.width(), neededsize.height()+50);
}


void MessageViewDelegate::drawButton( QStyleOptionButton &option, const QPoint &point, QPainter * painter ) const
{
    if(option.rect.contains(point))
        option.state |= QStyle::State_Sunken;

    QStyle * style = QApplication::style();
    if(style)
        style->drawControl(QStyle::CE_PushButton, &option, painter);
    option.state &= ~QStyle::State_Sunken;
    option.rect.translate(option.rect.width() + OFFSET_BUTTON, 0);
}

