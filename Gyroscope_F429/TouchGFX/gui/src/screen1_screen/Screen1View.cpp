#include <gui/screen1_screen/Screen1View.hpp>
#include <math.h>
#include <stdlib.h>

extern float Gyro_Value[3];
extern int tickCounter;
static int Update_Graph_Data;

static uint16_t randomish(int32_t seed)
{
    static uint16_t last = 0;
    const uint16_t num = (seed * (1337 + last)) % 0xFFFF;
    last = num;
    return num;
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::Update_Graph()
{
//	float X_yMax = X_Rotation.getGraphRangeYMaxAsFloat();
//	float Y_yMax = Y_Rotation.getGraphRangeYMaxAsFloat();
//	float Z_yMax = Z_Rotation.getGraphRangeYMaxAsFloat();

//	X_Rotation.addDataPoint(((sinf(tickCounter * .2f) + 1) * (X_yMax / 20.2f)) + randomish(tickCounter) % (int)(X_yMax / 10.f));
//	Y_Rotation.addDataPoint(((sinf(tickCounter * .02f) + 1) * (Y_yMax / 30.2f)) + randomish(tickCounter) % (int)(Y_yMax / 10.f));
//	Z_Rotation.addDataPoint(((sinf(tickCounter * .002f) + 1) * (Z_yMax / 40.2f)) + randomish(tickCounter) % (int)(Z_yMax / 10.f));

	X_Rotation.addDataPoint(Gyro_Value[0]);
	Y_Rotation.addDataPoint(Gyro_Value[1]);
	Z_Rotation.addDataPoint(Gyro_Value[2]);

}
