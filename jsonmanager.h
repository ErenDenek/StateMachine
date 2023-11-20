#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QVector>
#include <QPair>
#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

class ItemObject {
public:
    QJsonObject obj;
    QString objName;
};


class JsonManager : public QObject
{
    Q_OBJECT

public:
    explicit JsonManager(QObject *parent = nullptr);
    ~JsonManager();

    void setName(const QString projectName);
    void addItem(const QString itemName);
    void clear();
    void Open();
    void Close();
    bool save();
    bool load();

    void write(const QString itemName, const QString key, const QString value);
    void write(const QString itemName, const QString key, const int value);
    void write(const QString itemName, const QString key, const int* arr, const int size);
    void write(const QString itemName, const QString* childItemName, const QString key, const int* arr, const int size);

    int getArraySize(const QString arrKey);
    QString read(const QString itemName, const QString key);
    QString read(const QString arrKey, const QString *keys, int *retArr, const int arrIndex);
private:
    bool IsOpen();

    QString m_projectName = "designer.json";
    QJsonObject m_mainObject; //!This variable keeps all json datas
    QFile m_file;

    QVector<ItemObject *> itemVect;

    bool m_IsOpen = false;
};

#endif // JSONMANAGER_H
