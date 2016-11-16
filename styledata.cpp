#include "styledata.h"

StyleData::StyleData()
{

}

StyleData::~StyleData(){}

QString StyleData::getStyleNo()
{
    return styleNo;
}

void StyleData::setStyleNo(QString styleNo_local)
{
    styleNo = styleNo_local;
}

QString StyleData::getStyleValue()
{
    return styleValue;
}

void StyleData::setStyleValue(QString styleValue_local)
{
    styleValue = styleValue_local;
}

QString StyleData::getSize()
{
    return size;
}

void StyleData::setSize(QString size_local)
{
    size = size_local;
}

QString StyleData::getMaterial()
{
    return material;
}

void StyleData::setMaterial(QString material_local)
{
    material = material_local;
}

int StyleData::getFoldWidth()
{
    return foldWidth;
}

void StyleData::setFoldWidth(int foldWidth_local)
{
    foldWidth = foldWidth_local;
}

int StyleData::getRGB()
{
    return rgb;
}

void StyleData::setRGB(int rgb_local)
{
    rgb = rgb_local;
}

int StyleData::getTension_1()
{
    return tension_1;
}

void StyleData::setTension_1(int tension_1_local)
{
    tension_1 = tension_1_local;
}

int StyleData::getTension_2()
{
    return tension_2;
}

void StyleData::setTension_2(int tension_2_local)
{
    tension_2 = tension_2_local;
}

int StyleData::getTension_3()
{
    return tension_3;
}

void StyleData::setTension_3(int tension_3_local)
{
    tension_3 = tension_3_local;
}

int StyleData::getTension_4()
{
    return tension_4;
}

void StyleData::setTension_4(int tension_4_local)
{
    tension_4 = tension_4_local;
}

int StyleData::getSpeed_1()
{
    return speed_1;
}

void StyleData::setSpeed_1(int speed_1_local)
{
    speed_1 = speed_1_local;
}

int StyleData::getSpeed_2()
{
    return speed_2;
}

void StyleData::setSpeed_2(int speed_2_local)
{
    speed_2 = speed_2_local;
}

int StyleData::getSpeed_3()
{
    return speed_3;
}

void StyleData::setSpeed_3(int speed_3_local)
{
    speed_3 = speed_3_local;
}

int StyleData::getSpeed_4()
{
    return speed_4;
}

void StyleData::setSpeed_4(int speed_4_local)
{
    speed_4 = speed_4_local;
}

void StyleData::display()
{
   cout<<"RPM_1 : "<< speed_1 << "\nRPM_2 : " <<speed_2 << "\nRPM_3 : "<<speed_3<< "\nRPM_4 : "<<speed_4<<"\nTension_1 : "<<tension_1
      <<"\nTension_2 : "<<tension_2<< "\nTension_3 : "<<tension_3<< "\nTension_4 : "<<tension_4
     << "\nFold Width : "<<foldWidth<<"\nRGB value : "<<rgb<<endl;
}

QString StyleData::toString(){
    view = "RPM_1 : "+ QString::number(speed_1) + "\nRPM_2 :"+ QString::number(speed_2) +"\nRPM_3 :"+QString::number(speed_3)+"\nRPM_4 :"
            +QString::number(speed_4)+"\nTension_1 :"+QString::number(tension_1)+"\nTension_2 :"+QString::number(tension_2)+
            "\nTension_3 :"+QString::number(tension_3)+"\nTension_4 :"+QString::number(tension_4)+"\nFold Width :"+QString::number(foldWidth)
            +"\nRGB :"+QString::number(rgb);
    return view;
}
void StyleData::setDynamicFoldwidth(int readVal){
    dynamicFoldwidth = readVal;
}

int StyleData::getDynamicFoldwidth(){
    return dynamicFoldwidth;
}
