#ifndef STYLEDATA_H
#define STYLEDATA_H

#include <iostream>
#include <string.h>
#include <QString>

using namespace std;


class StyleData
{
private:
    QString styleNo;
    QString styleValue;
    QString size;
    QString material;

    int foldWidth;

    int tension_1;
    int tension_2;
    int tension_3;
    int tension_4;

    int speed_1;
    int speed_2;
    int speed_3;
    int speed_4;

    int rgb;

   int dynamicFoldwidth;

    QString view;

public:
    StyleData();
    ~ StyleData();
    QString getStyleNo();
    void setStyleNo(QString styleNo_local);

    QString getStyleValue();
    void setStyleValue(QString styleValue_local);

    QString getSize();
    void setSize(QString size_local);

    QString getMaterial();
    void setMaterial(QString material_local);

    int getFoldWidth();
    void setFoldWidth(int foldWidth_local);
    int getRGB();
    void setRGB(int rgb_local);


    int getTension_1();
    void setTension_1(int tension_1_local);
    int getTension_2();
    void setTension_2(int tension_2_local);
    int getTension_3();
    void setTension_3(int tension_3_local);
    int getTension_4();
    void setTension_4(int tension_4_local);

    int getSpeed_1();
    void setSpeed_1(int speed_1_local);
    int getSpeed_2();
    void setSpeed_2(int speed_2_local);
    int getSpeed_3();
    void setSpeed_3(int speed_3_local);
    int getSpeed_4();
    void setSpeed_4(int speed_4_local);

    void display();
    QString toString();

    void setDynamicFoldwidth(int readVal);

    int getDynamicFoldwidth();
};

#endif // STYLEDATA_H
