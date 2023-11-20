#include "projesettings.h"
#include "jsonmanager.h"
#include "stateboxproperties.h"
#include "stateboxconnlines.h"
#include <QDebug>

extern StateBoxProperties stateBoxProperties;
extern StateBoxConnLines stateBoxConnLines;

const QString stateConnectionName = "StateBoxConnections";
const QString stateConnectionKeys[] = {"firstBoxIndex", "firstTerIndex", "firstTerminalSide", "secondBoxIndex", "secondTerIndex", "secondTerSide"};
const QString stateBoxMembersName = "StateBoxProperties";
const QString stateBoxMembersKeys[] = {"height", "width", "x", "y"};

JsonManager json;

ProjeSettings::ProjeSettings()
{

}

void ProjeSettings::save()
{
    json.Open();

    json.clear();

    json.addItem(stateBoxMembersName);
    for(int i = 0; i < stateBoxProperties.getNumber(); i++)
    {
        int tempArr[] = {stateBoxProperties.getHeigth(i), stateBoxProperties.getWidth(i), stateBoxProperties.getX(i), stateBoxProperties.getY(i)};
        json.write(stateBoxMembersName, stateBoxMembersKeys, stateBoxProperties.getName(i), tempArr, sizeof(tempArr)/sizeof(tempArr[0]));
    }

    json.addItem(stateConnectionName);
    for(int i = 0; i < m_lineProperties.length(); i++)
    {
        int tempArr[] = {
            m_lineProperties[i].firstBoxIndex, m_lineProperties[i].firstTerIndex, m_lineProperties[i].firstTerSide,
            m_lineProperties[i].scndBoxIndex, m_lineProperties[i].scndTerIndex, m_lineProperties[i].scndTerSide
        };

        QString connectionName = (stateBoxProperties.getName(m_lineProperties[i].firstBoxIndex) + "<->" +  stateBoxProperties.getName(m_lineProperties[i].scndBoxIndex));
        json.write(stateConnectionName, stateConnectionKeys, connectionName, tempArr, sizeof(tempArr)/sizeof(tempArr[0]));
    }

    json.save();
    json.Close();
}

void ProjeSettings::load()
{
    json.Open();
    int connectionArr[6];

    m_lineProperties.resize(json.getArraySize(stateConnectionName));

    for(int i = 0; i < json.getArraySize(stateConnectionName); i++)
    {
        json.read(stateConnectionName, stateConnectionKeys ,connectionArr, i);
        m_lineProperties[i].firstBoxIndex = connectionArr[0];
        m_lineProperties[i].firstTerIndex = connectionArr[1];
        m_lineProperties[i].firstTerSide = connectionArr[2];
        m_lineProperties[i].scndBoxIndex = connectionArr[3];
        m_lineProperties[i].scndTerIndex = connectionArr[4];
        m_lineProperties[i].scndTerSide = connectionArr[5];
    }

    int stateBoxMembersTempArr[4];

    stateBoxProperties.resize(json.getArraySize(stateBoxMembersName));

    for(int i = 0; i < json.getArraySize(stateBoxMembersName); i++)
    {
        stateBoxProperties.setName(i, json.read(stateBoxMembersName, stateBoxMembersKeys,stateBoxMembersTempArr, i));

        stateBoxProperties.setHeigth(i, stateBoxMembersTempArr[0]);
        stateBoxProperties.setWidth(i, stateBoxMembersTempArr[1]);
        stateBoxProperties.setX(i, stateBoxMembersTempArr[2]);
        stateBoxProperties.setY(i, stateBoxMembersTempArr[3]);
    }

    stateBoxProperties.update();
    stateBoxConnLines.update();
}

void ProjeSettings::setName(const QString projectName)
{
    json.setName(projectName);
}


