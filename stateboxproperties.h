#ifndef STATEBOXPROPERTIES_H
#define STATEBOXPROPERTIES_H

#include <QObject>

#define BOX_WIDTH 100
#define BOX_HEIGTH 50


typedef struct StateBoxMembers{
    int m_x, m_y, m_width = BOX_WIDTH, m_heigth = BOX_HEIGTH;
    QString name;
}StateBoxMembers;

class StateBoxProperties : public QObject
{
    Q_OBJECT

public:
    StateBoxProperties();

    Q_INVOKABLE int getX(const int index) const;
    Q_INVOKABLE int getY(const int index) const;
    Q_INVOKABLE int getWidth(const int index) const;
    Q_INVOKABLE int getHeigth(const int index) const;
    Q_INVOKABLE QString getName(const int index) const;
    Q_INVOKABLE int getNumber() const;
    Q_INVOKABLE void remove(const int index);
    void update();
    void resize(const int size);
private:
    QVector<StateBoxMembers> stateBoxMembers;

public slots:
    void setX(const int index, const int value);
    void setY(const int index, const int value);
    void setWidth(const int index, const int value);
    void setHeigth(const int index, const int value);
    void setName(const int index, const QString value);
    void newStateBox(const int x, const int y);

signals:
    void xChanged();
    void yChanged();
    void widthChanged();
    void heigthChanged();
    void nameChanged();
    void numberChanged();
};

#endif // STATEBOXPROPERTIES_H
