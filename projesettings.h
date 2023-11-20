#ifndef PROJESETTINGS_H
#define PROJESETTINGS_H

#include <QObject>
#include "jsonmanager.h"
#include <QVector>

class ProjeSettings : public QObject
{
    Q_OBJECT
public:
    ProjeSettings();

    Q_INVOKABLE void save();
    Q_INVOKABLE void load();
    Q_INVOKABLE void setName(const QString projectName);
private:

};

extern JsonManager json;

#endif // PROJESETTINGS_H
