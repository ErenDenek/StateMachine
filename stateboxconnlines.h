#ifndef STATEBOXCONNLINES_H
#define STATEBOXCONNLINES_H

#include <QObject>
#include <QVector>
#include <QPoint>

typedef struct lineProperties{
    int LStartX = -1, LStartY = -1, LWidth = -1, LHeight = -1;
}lineProperties;

typedef struct stateBoxTerminalProperties{
    int firstBoxIndex = -1, scndBoxIndex = -1, firstTerIndex = -1, scndTerIndex = -1, firstTerSide = -1, scndTerSide = -1;
    QVector <lineProperties> m_lines;
}stateBoxTerminalProperties;

extern QVector <stateBoxTerminalProperties> m_lineProperties;

class StateBoxConnLines : public QObject
{
    Q_OBJECT
public:
    StateBoxConnLines();

    void createConnectionLines();
    void linesCalculation(const int connectionLinesIndex);
    Q_INVOKABLE void lineReCalculation(const int movedStateBoxIndex);

    Q_INVOKABLE void markTerminal(const int boxIndex, const int terminalIndex, const int terminalSide);

    Q_INVOKABLE int getConnectionNumber()const;
    Q_INVOKABLE int getX(const int connIndex, const int lineIndex)const;
    Q_INVOKABLE int getY(const int connIndex, const int lineIndex)const;
    Q_INVOKABLE int getHeight(const int connIndex, const int lineIndex)const;
    Q_INVOKABLE int getWidth(const int connIndex, const int lineIndex)const;

    Q_INVOKABLE int getChangedConnLineIndex()const;

    void update();
    Q_INVOKABLE void remove(const int removedBoxIndex);
    Q_INVOKABLE void removeLines(const int linesIndex);
private:

    int changedConnectionLineIndex;

    QPoint calculateTermialPoint(const int boxIndex, const int terminalIndex, const int terminalSide);
public slots:

signals:
    void connectionNumberChanged();
    void lineUpdated();
};

#endif // STATEBOXLINES_H
