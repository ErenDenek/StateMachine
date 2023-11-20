#include "stateboxconnections.h"
#include "stateboxproperties.h"

extern StateBoxProperties stateBoxProperties;
QVector<StateBoxConnProperties> staBoxConnProp;

StateBoxConnection::StateBoxConnection()
{

}

QString StateBoxConnection::getParentName(const unsigned int index) const{
    QString parentName;

    parentName += " ";
    parentName += stateBoxProperties.getName(staBoxConnProp[index].parentIndex);
    return parentName;
}

QString StateBoxConnection::getChildsNames(const unsigned int index) const{
    QString childsName = "-";

    for(int i = 0; i < staBoxConnProp[index].childIndexs.length(); i++)
    {
        if(staBoxConnProp[index].childIndexs[i] != 0)
        {
            childsName += " ";
            childsName += stateBoxProperties.getName(staBoxConnProp[index].childIndexs[i]);
        }
    }
    return childsName;
}

void StateBoxConnection::nestedControl(const int index)
{
    int centerX = (stateBoxProperties.getX(index) + stateBoxProperties.getWidth(index) * 0.5),
        centerY = (stateBoxProperties.getY(index) + stateBoxProperties.getHeigth(index) * 0.5);
    bool newChildDetect = false;

    for(int i = 0; i < staBoxConnProp.length(); i++)
    {
        if(i != index)
        {
            if(centerX > stateBoxProperties.getX(i) &&
                centerX < stateBoxProperties.getX(i) +stateBoxProperties.getWidth(i) &&
                centerY > stateBoxProperties.getY(i) &&
                centerY < stateBoxProperties.getY(i) + stateBoxProperties.getHeigth(i))
            {
                for(int j = 0; j < staBoxConnProp[i].childIndexs.length(); j++)
                {
                    if(staBoxConnProp[i].childIndexs[j] == index)
                    {

                        newChildDetect = true;
                    }
                }

                if(!newChildDetect){
                    staBoxConnProp[i].childIndexs.append({index});
                }

                staBoxConnProp[index].parentIndex = i;

            }

            emit parentNameChanged();
            emit childsNameChanged();
        }
    }
}
