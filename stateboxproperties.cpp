#include "stateboxproperties.h"
#include "stateboxconnections.h"
#include <QDebug>

StateBoxProperties::StateBoxProperties()
{

}

int StateBoxProperties::getX(const int index) const{
    if(index < getNumber()) return stateBoxMembers[index].m_x;
    else return 0;
}

int StateBoxProperties::getY(const int index) const{
    if(index < getNumber()) return stateBoxMembers[index].m_y;
    else return 0;
}

int StateBoxProperties::getWidth(const int index) const{
    if(index < getNumber()) return stateBoxMembers[index].m_width;
    else return 0;
}

int StateBoxProperties::getHeigth(const int index) const{
    if(index < getNumber()) return stateBoxMembers[index].m_heigth;
    else return 0;
}

QString StateBoxProperties::getName(const int index) const{
    if(index < getNumber()) return stateBoxMembers[index].name;
    else return "";
}

int StateBoxProperties::getNumber() const{
    return stateBoxMembers.length();
}

void StateBoxProperties::remove(const int index)
{
    stateBoxMembers.remove(index);
    qDebug() << "State :" << stateBoxMembers.length();
    update();
}

void StateBoxProperties::setX(const int index, const int value){
    if(value>0)
        stateBoxMembers[index].m_x = value;
    emit xChanged();
}

void StateBoxProperties::setY(const int index, const int value){
    if(value>0)
        stateBoxMembers[index].m_y = value;
    emit yChanged();
}

void StateBoxProperties::setWidth(const int index, const int value){
    stateBoxMembers[index].m_width = value;
    emit widthChanged();
}

void StateBoxProperties::setHeigth(const int index, const int value){
    stateBoxMembers[index].m_heigth = value;
    emit heigthChanged();
}

void StateBoxProperties::setName(const int index, const QString value){
    stateBoxMembers[index].name = value;
    emit nameChanged();
}

void StateBoxProperties::update()
{
    emit numberChanged();
    emit widthChanged();
    emit heigthChanged();
    emit yChanged();
    emit xChanged();
    emit nameChanged();
}

void StateBoxProperties::resize(const int size)
{
    stateBoxMembers.resize(size);
}

void StateBoxProperties::newStateBox(const int x, const int y)
{
    stateBoxMembers.append({x, y, BOX_WIDTH, BOX_HEIGTH, "State"});
    stateBoxMembers.back().name = "State" + QString::number(getNumber() - 1);
    staBoxConnProp.append(StateBoxConnProperties{});
    update();
}
