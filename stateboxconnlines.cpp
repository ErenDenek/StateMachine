#include "stateboxconnlines.h"
#include "stateboxproperties.h"

QVector <stateBoxTerminalProperties> m_lineProperties;
extern StateBoxProperties stateBoxProperties;

StateBoxConnLines::StateBoxConnLines()
{

}

void StateBoxConnLines::linesCalculation(const int connectionLinesIndex)
{
    lineProperties tempLines[7];

    QPoint firstPoint = calculateTermialPoint(m_lineProperties[connectionLinesIndex].firstBoxIndex,
                                              m_lineProperties[connectionLinesIndex].firstTerIndex,
                                              m_lineProperties[connectionLinesIndex].firstTerSide);
    QPoint scndPoint = calculateTermialPoint(m_lineProperties[connectionLinesIndex].scndBoxIndex,
                                             m_lineProperties[connectionLinesIndex].scndTerIndex,
                                             m_lineProperties[connectionLinesIndex].scndTerSide);

    if(m_lineProperties[connectionLinesIndex].firstTerSide != m_lineProperties[connectionLinesIndex].scndTerSide)
    {
        if(m_lineProperties[connectionLinesIndex].firstTerSide == 1 && m_lineProperties[connectionLinesIndex].scndTerSide == 2){
            QPoint swapTemp;
            swapTemp = scndPoint;
            scndPoint = firstPoint;
            firstPoint = swapTemp;
        }

        tempLines[0].LStartX = firstPoint.x();
        tempLines[0].LStartY = firstPoint.y();
        tempLines[0].LWidth = (scndPoint.x() - tempLines[0].LStartX) / 2;
        tempLines[0].LHeight = 2;

        if(scndPoint.y() < firstPoint.y()){
            tempLines[1].LStartX = firstPoint.x() + tempLines[0].LWidth;
            tempLines[1].LStartY = scndPoint.y();
            tempLines[1].LHeight = (firstPoint.y() - scndPoint.y());
            tempLines[1].LWidth = 2;
        }else{
            tempLines[1].LStartX = firstPoint.x() + tempLines[0].LWidth;
            tempLines[1].LStartY = firstPoint.y();
            tempLines[1].LHeight = (scndPoint.y() - firstPoint.y());
            tempLines[1].LWidth = 2;
        }

        tempLines[2].LStartX = firstPoint.x() + tempLines[0].LWidth;
        tempLines[2].LStartY = scndPoint.y();
        tempLines[2].LWidth = (scndPoint.x() - tempLines[2].LStartX);
        tempLines[2].LHeight = 2;
    }
    //    else if(m_lineProperties[connectionLinesIndex].firstTerSide == 2 && m_lineProperties[connectionLinesIndex].scndTerSide == 2)
    //    {


    //        if(firstPoint.x() < scndPoint.y())
    //        {
    //            tempLines[0].LStartX = firstPoint.x();
    //            tempLines[0].LStartY = firstPoint.y();
    //            tempLines[0].LWidth = 50; //!Todo sonradan başka bir şey bağlayabiliriz.
    //            tempLines[0].LHeight = 2;

    //            if(scndPoint.y() < firstPoint.y()){
    //                tempLines[1].LStartX = firstPoint.x() + tempLines[0].LWidth;
    //                tempLines[1].LStartY = scndPoint.y();
    //                tempLines[1].LHeight = (firstPoint.y() - scndPoint.y());
    //                tempLines[1].LWidth = 2;
    //            }else{
    //                tempLines[1].LStartX = firstPoint.x() + tempLines[0].LWidth;
    //                tempLines[1].LStartY = firstPoint.y();
    //                tempLines[1].LHeight = (scndPoint.y() - firstPoint.y());
    //                tempLines[1].LWidth = 2;
    //            }

    //            tempLines[2].LStartX = scndPoint.x();
    //            tempLines[2].LStartY = scndPoint.y();
    //            tempLines[2].LWidth = (firstPoint.x() - scndPoint.x() + tempLines[0].LWidth);
    //            tempLines[2].LHeight = 2;
    //        }else{
    //            if(scndPoint.y() < firstPoint.y()){
    //                QPoint swapTemp;
    //                swapTemp = scndPoint;
    //                scndPoint = firstPoint;
    //                firstPoint = swapTemp;
    //            }
    //            tempLines[0].LStartX = firstPoint.x();
    //            tempLines[0].LStartY = firstPoint.y();
    //            tempLines[0].LWidth = 25; //!Todo sonradan başka bir şey bağlayabiliriz.
    //            tempLines[0].LHeight = 2;

    //            if(scndPoint.y() < firstPoint.y()){
    //                tempLines[1].LStartX = firstPoint.x() + tempLines[0].LWidth;
    //                tempLines[1].LStartY = scndPoint.y();
    //                tempLines[1].LHeight = (firstPoint.y() - scndPoint.y());
    //                tempLines[1].LWidth = 2;
    //            }else{
    //                tempLines[1].LStartX = firstPoint.x() + tempLines[0].LWidth;
    //                tempLines[1].LStartY = firstPoint.y();
    //                tempLines[1].LHeight = (scndPoint.y() - firstPoint.y());
    //                tempLines[1].LWidth = 2;
    //            }

    //            tempLines[2].LStartX = scndPoint.x();
    //            tempLines[2].LStartY = scndPoint.y();
    //            tempLines[2].LWidth = (firstPoint.x() - scndPoint.x() + tempLines[0].LWidth);
    //            tempLines[2].LHeight = 2;
    //        }

    //    }
    else if(m_lineProperties[connectionLinesIndex].firstTerSide == 1 && m_lineProperties[connectionLinesIndex].scndTerSide == 1)
    {
        tempLines[0].LStartX = firstPoint.x() - 25;
        tempLines[0].LStartY = firstPoint.y();
        tempLines[0].LWidth = 25; //!Todo sonradan başka bir şey bağlayabiliriz.
        tempLines[0].LHeight = 2;

        if(firstPoint.y() < scndPoint.y()){
            tempLines[1].LStartX = tempLines[0].LStartX;
            tempLines[1].LStartY = firstPoint.y();
            tempLines[1].LHeight = (scndPoint.y() - firstPoint.y());
            tempLines[1].LWidth = 2;
        }else{
            tempLines[1].LStartX = tempLines[0].LStartX;
            tempLines[1].LStartY = scndPoint.y();
            tempLines[1].LHeight = (firstPoint.y() - scndPoint.y());
            tempLines[1].LWidth = 2;
        }

        tempLines[2].LStartX = tempLines[0].LStartX;
        tempLines[2].LStartY = scndPoint.y();
        tempLines[2].LWidth = (scndPoint.x() - tempLines[0].LStartX);
        tempLines[2].LHeight = 2;
    }



    m_lineProperties[connectionLinesIndex].m_lines.clear();

    for(int i = 0; i < 7; i++)
    {
        if(tempLines[i].LWidth != -1)
        {
            m_lineProperties[connectionLinesIndex].m_lines.append(lineProperties{tempLines[i].LStartX, tempLines[i].LStartY, tempLines[i].LWidth, tempLines[i].LHeight});
        }
    }
}

void StateBoxConnLines::createConnectionLines()
{
    linesCalculation(m_lineProperties.length() - 1); //!Son index'e göre hesaplama yap. Çünkü en son eklendi.

    emit connectionNumberChanged();
}

void StateBoxConnLines::lineReCalculation(const int movedStateBoxIndex)
{
    for(int i = 0; i < m_lineProperties.length(); i++)
    {
        if(movedStateBoxIndex == m_lineProperties[i].firstBoxIndex || movedStateBoxIndex == m_lineProperties[i].scndBoxIndex)
        {
            linesCalculation(i);
            changedConnectionLineIndex = i;
            emit lineUpdated();
        }
    }
}

QPoint StateBoxConnLines::calculateTermialPoint(const int boxIndex, const int terminalIndex, const int terminalSide)
{
    QPoint retPoint;

    if(terminalSide == 1)//Left
    {
        retPoint.setX(stateBoxProperties.getX(boxIndex));
        retPoint.setY(stateBoxProperties.getY(boxIndex) + (terminalIndex * (stateBoxProperties.getHeigth(boxIndex)/4.1)) + (stateBoxProperties.getHeigth(boxIndex)/4.1));
    }
    else if(terminalSide == 2)
    {
        retPoint.setX(stateBoxProperties.getX(boxIndex) + stateBoxProperties.getWidth(boxIndex));
        retPoint.setY(stateBoxProperties.getY(boxIndex) + (terminalIndex * (stateBoxProperties.getHeigth(boxIndex)/4.1)) + (stateBoxProperties.getHeigth(boxIndex)/4.1));
    }
    else if(terminalSide == 3)
    {

    }
    else if(terminalSide == 4)
    {

    }
    return retPoint;
}

void StateBoxConnLines::markTerminal(const int index, const int terminalIndex, const int terminalSide)
{
    static bool firstStateBoxMarked = false;
    static int tempFirstStateBoxIndex = - 1, tempFirstTerSide = -1, tempFirstTerIndex = -1;
    //!todo ekle : eğer aynı iki kutu ve taraf seçildiyse problemdir engelle.
    if(firstStateBoxMarked == false)
    {
        tempFirstStateBoxIndex = index;
        tempFirstTerSide = terminalSide;
        tempFirstTerIndex = terminalIndex;

        firstStateBoxMarked = true;
    }
    else if(firstStateBoxMarked == true && tempFirstStateBoxIndex == index)
    {
        firstStateBoxMarked = false, tempFirstStateBoxIndex = -1, tempFirstTerSide = -1;
    }
    else{
        firstStateBoxMarked = false;
        m_lineProperties.append(stateBoxTerminalProperties{tempFirstStateBoxIndex, index, tempFirstTerIndex, terminalIndex, tempFirstTerSide, terminalSide});
        createConnectionLines();
    }
}

int StateBoxConnLines::getConnectionNumber()const
{
    return m_lineProperties.length();
}

int StateBoxConnLines::getX(const int connIndex, const int lineIndex)const
{
    if(lineIndex > m_lineProperties[connIndex].m_lines.length() - 1){
        return 0;
    }
    return m_lineProperties[connIndex].m_lines[lineIndex].LStartX;
}

int StateBoxConnLines::getY(const int connIndex, const int lineIndex)const
{
    if(lineIndex > m_lineProperties[connIndex].m_lines.length() - 1){
        return 0;
    }
    return m_lineProperties[connIndex].m_lines[lineIndex].LStartY;
}

int StateBoxConnLines::getHeight(const int connIndex, const int lineIndex)const
{
    if(lineIndex > m_lineProperties[connIndex].m_lines.length() - 1){
        return 0;
    }
    return m_lineProperties[connIndex].m_lines[lineIndex].LHeight;
}

int StateBoxConnLines::getWidth(const int connIndex, const int lineIndex)const
{
    if(lineIndex > m_lineProperties[connIndex].m_lines.length() - 1){
        return 0;
    }
    return m_lineProperties[connIndex].m_lines[lineIndex].LWidth;
}

int StateBoxConnLines::getChangedConnLineIndex() const{
    return changedConnectionLineIndex;
}

void StateBoxConnLines::update()
{
    connectionNumberChanged();
    lineUpdated();
}

void StateBoxConnLines::remove(const int removedBoxIndex)
{
    int i = 0;

    while(i < m_lineProperties.length())
    {
        if(removedBoxIndex == m_lineProperties[i].firstBoxIndex || removedBoxIndex == m_lineProperties[i].scndBoxIndex){
            m_lineProperties.remove(i);
            update();
            i = 0;
        }else{
            i++;
        }
    }
}

void StateBoxConnLines::removeLines(const int linesIndex)
{
    m_lineProperties.remove(linesIndex);
    update();
}




