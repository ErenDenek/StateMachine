#ifndef STATEBOXCONNECTIONS_H
#define STATEBOXCONNECTIONS_H

#include <QObject>
#include <QVector>

typedef struct StateBoxConnProperties{
    unsigned int parentIndex;
    QVector<int> childIndexs;
}StateBoxConnProperties;

extern QVector<StateBoxConnProperties> staBoxConnProp;

class StateBoxConnection : public QObject
{
    Q_OBJECT

public:
    StateBoxConnection();

    Q_INVOKABLE QString getParentName(const unsigned int index) const;
    Q_INVOKABLE QString getChildsNames(const unsigned int index) const;

    Q_INVOKABLE void nestedControl(const int index);
private:

public slots:

signals:
    void parentNameChanged();
    void childsNameChanged();
};

#endif // STATEBOXCONNECTIONS_H
