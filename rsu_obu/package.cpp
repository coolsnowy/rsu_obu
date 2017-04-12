#include "package.h"
#include "bsm.h"
#include "map.h"
#include "trafficlight.h"
#include <iostream>
#include <vector>

using namespace std;

void type_distinguish(char recv_buf[], const std::vector<uint8_t> recv_vector,uint8_t buf[],uint8_t *frametype)
{
    extern BsmBlob bsm;
    memset(&bsm,0,sizeof(bsm));
    extern TrafficLight spat;
    memset(&spat,0,sizeof(spat));
    extern Map light;
    memset(&light,0,sizeof(light));
    cout<<"start distinguish"<<endl;
    switch (recv_buf[5])
    {
    case 2:
        cout<<"BSM message\n";
        bsmpack(BsmDecode(recv_vector),buf);
        *frametype = 0x01;
        break;
    case 13:
        cout<<"SPAT message\n";
        cout<<"content";
        for(int i=0;i<strlen(recv_buf);i++)
            printf("%x ",recv_buf[i]);
        cout<<endl;
        spatpack(SpatDecode(recv_vector),buf);
        *frametype = 0x03;
        break;

    case 07:
        cout<<"MAP message\n";
         mappack(MapDecode(recv_vector),buf);
        *frametype = 0x02;
        break;
    }
    switch (recv_buf[4])
    {
    case 2:
        cout<<"BSM message\n";
         bsmpack(BsmDecode(recv_vector),buf);
        *frametype = 0x01;
        break;
    case 13:
        cout<<"SPAT message\n";
        cout<<"content";
        for(int i=0;i<strlen(recv_buf);i++)
            printf("%x ",recv_buf[i]);
        cout<<endl;
         spatpack(SpatDecode(recv_vector),buf);
        *frametype = 0x03;
        break;

    case 07:
        cout<<"MAP message\n";
        mappack(MapDecode(recv_vector),buf);
        *frametype = 0x02;
        break;

    }
}
void  bsmpack(BsmBlob blob,uint8_t buf[])
{
    cout<<"start bsmpack\n";
    int32_t carId = blob.carId;
    int32_t latitude = blob.latitude;
    int32_t longitude = blob.longitude;
    int16_t speed = blob.speed;
    int16_t heading = blob.heading;
    int32_t wheelAngle = blob.wheelAngle;
    int16_t acceleration = blob.acceleration;
    bool carBrake = blob.carBrake;

    int32_t newcarID = carId;
    int32_t newlatitude = (int32_t) round(latitude * 1000000);
    int32_t newlongitude = (int32_t) round(longitude * 1000000);
    int16_t newspeed = (int16_t) round(speed / 3.6 * 50);
    int16_t newheading = (int16_t) round(heading / 0.0125);
    int32_t newwheelAngle = (int32_t) round(wheelAngle / 1.5);
    int16_t newacceleration = (int16_t) round(acceleration * 100);

    //big endian
	//carid (0 - 3)
	buf[3] = newcarID & 0xFF;
	buf[2] = (newcarID & 0xFF00) >> 8;
	buf[1] = (newcarID & 0xFF0000) >> 16;
	buf[0] = (newcarID & 0xFF000000) >> 24;

	//latitude (4 - 7)
	if (newlatitude > 900000000 || newlatitude < -900000000) //range: -900000000 ~ 900000000,unavailable:900000001
	{
		newlatitude = 900000001;
	}
	buf[7] = newlatitude & 0xFF;
	buf[6] = (newlatitude & 0xFF00) >> 8;
	buf[5] = (newlatitude & 0xFF0000) >> 16;
	buf[4] = (newlatitude & 0xFF000000) >> 24;

	//longitude (8 - 11)
	if (newlongitude > 1800000000 || newlongitude < -1800000000) //range: -1800000000 ~ 1800000000,unavailable:1800000001
	{
		newlongitude = 1800000001;
	}
	buf[11] = newlongitude & 0xFF;
	buf[10] = (newlongitude & 0xFF00) >> 8;
	buf[9] = (newlongitude & 0xFF0000) >> 16;
	buf[8] = (newlongitude & 0xFF000000) >> 24;
	//speed (12 - 13)                //range: 0 ~ 8192
	buf[13] = newspeed & 0xFF;
	buf[12] = (newspeed & 0x1F00) >> 8;
	//Heading (14 - 15)
	if (newheading < 0 || newheading > 28799) //range:0 ~ 28799,unavailable:28800
	{
		newheading = 28800;
	}
	buf[15] = newheading & 0xFF;
	buf[14] = (newheading & 0xFF00) >> 8;
	//wheelangle (16)
	if (newwheelAngle < -126 || newwheelAngle > 126) //range: -126 ~ 126,unavailable:127
	{
		newwheelAngle = 127;
	}
	buf[16] = newwheelAngle & 0xFF;
	//acceleration(17 - 18)
	if (newacceleration < 0 || newacceleration > 5000)
	{
		newacceleration = -1;
	}
	buf[18] = newacceleration & 0xFF;
	buf[17] = (newacceleration & 0xFF00) >> 8;
	//carBrake(19)
	buf[19] = carBrake & 0xFF;
	time_t t;
	time(&t);
	buf[23] = t & 0xFF;
	buf[22] = (t & 0xFF00) >> 8;
	buf[21] = (t & 0xFF0000) >> 16;
	buf[20] = (t & 0xFF000000) >> 24;
    buf[24] = ',';
    cout<<"BSM message package suceess\n";
    cout<<"buf[24]"<<buf[24]<<endl;
}
void spatpack(TrafficLight light,uint8_t buf[])
{

    int32_t newmapId = light.mapId;
    list<SpatMovementState>::iterator iter= light.states.begin();
	list<int>::size_type spat_num;
	spat_num = light.states.size();
    cout<<"spatnum="<<spat_num<<endl;
    //mapId 0-3
    buf[0] = (newmapId & 0xFF000000) >> 24;

    buf[1] = (newmapId & 0xFF0000) >> 16;

    buf[2] = (newmapId & 0xFF00) >> 8;

    buf[3] = (newmapId & 0xFF);

    buf +=3;
    int num=0;

    while (num<spat_num)
	{
        num++;
		buf++;
		*buf++ = (iter->laneId & 0xFF000000) >> 24;
		*buf++ = (iter->laneId & 0xFF0000) >> 16;
		*buf++ = (iter->laneId & 0xFF00) >> 8;
		*buf++ = (iter->laneId & 0xFF);

		*buf++ = (iter->rightTimeToChange & 0xFF000000) >> 24;
		*buf++ = (iter->rightTimeToChange & 0xFF0000) >> 16;
		*buf++ = (iter->rightTimeToChange & 0xFF00) >> 8;
        *buf++ = (iter->rightTimeToChange & 0xFF);

		*buf++ = (iter->straightTimeToChange & 0xFF000000) >> 24;
		*buf++ = (iter->straightTimeToChange & 0xFF0000) >> 16;
		*buf++ = (iter->straightTimeToChange & 0xFF00) >> 8;
		*buf++ = (iter->straightTimeToChange & 0xFF);

		*buf++ = (iter->leftTimeToChange & 0xFF000000) >> 24;
		*buf++ = (iter->leftTimeToChange & 0xFF0000) >> 16;
		*buf++ = (iter->leftTimeToChange & 0xFF00) >> 8;
		*buf++ = (iter->leftTimeToChange & 0xFF);

		*buf++ = (iter->rightState & 0xFF000000) >> 24;
		*buf++ = (iter->rightState & 0xFF0000) >> 16;
		*buf++ = (iter->rightState & 0xFF00) >> 8;
		*buf++ = (iter->rightState & 0xFF);

		*buf++ = (iter->straightState & 0xFF000000) >> 24;
		*buf++ = (iter->straightState & 0xFF0000) >> 16;
		*buf++ = (iter->straightState & 0xFF00) >> 8;
		*buf++ = (iter->straightState & 0xFF);

		*buf++ = (iter->leftState & 0xFF000000) >> 24;
		*buf++ = (iter->leftState & 0xFF0000) >> 16;
		*buf++ = (iter->leftState & 0xFF00) >> 8;
		*buf++ = (iter->leftState & 0xFF);

		*buf++ = (iter->rightTime[0] & 0xFF000000) >> 24;
		*buf++ = (iter->rightTime[0] & 0xFF0000) >> 16;
		*buf++ = (iter->rightTime[0] & 0xFF00) >> 8;
		*buf++ = (iter->rightTime[0] & 0xFF);

		*buf++ = (iter->rightTime[1] & 0xFF000000) >> 24;
		*buf++ = (iter->rightTime[1] & 0xFF0000) >> 16;
		*buf++ = (iter->rightTime[1] & 0xFF00) >> 8;
		*buf++ = (iter->rightTime[1] & 0xFF);

		*buf++ = (iter->rightTime[2] & 0xFF000000) >> 24;
		*buf++ = (iter->rightTime[2] & 0xFF0000) >> 16;
		*buf++ = (iter->rightTime[2] & 0xFF00) >> 8;
		*buf++ = (iter->rightTime[2] & 0xFF);

		*buf++ = (iter->straightTime[0] & 0xFF000000) >> 24;
		*buf++ = (iter->straightTime[0] & 0xFF0000) >> 16;
		*buf++ = (iter->straightTime[0] & 0xFF00) >> 8;
		*buf++ = (iter->straightTime[0] & 0xFF);

		*buf++ = (iter->straightTime[1] & 0xFF000000) >> 24;
		*buf++ = (iter->straightTime[1] & 0xFF0000) >> 16;
		*buf++ = (iter->straightTime[1] & 0xFF00) >> 8;
		*buf++ = (iter->straightTime[1] & 0xFF);

		*buf++ = (iter->straightTime[2] & 0xFF000000) >> 24;
		*buf++ = (iter->straightTime[2] & 0xFF0000) >> 16;
		*buf++ = (iter->straightTime[2] & 0xFF00) >> 8;
		*buf++ = (iter->straightTime[2] & 0xFF);

		*buf++ = (iter->leftTime[0] & 0xFF000000) >> 24;
		*buf++ = (iter->leftTime[0] & 0xFF0000) >> 16;
		*buf++ = (iter->leftTime[0] & 0xFF00) >> 8;
		*buf++ = (iter->leftTime[0] & 0xFF);

		*buf++ = (iter->leftTime[1] & 0xFF000000) >> 24;
		*buf++ = (iter->leftTime[1] & 0xFF0000) >> 16;
		*buf++ = (iter->leftTime[1] & 0xFF00) >> 8;
		*buf++ = (iter->leftTime[1] & 0xFF);

		*buf++ = (iter->leftTime[2] & 0xFF000000) >> 24;
		*buf++ = (iter->leftTime[2] & 0xFF0000) >> 16;
		*buf++ = (iter->leftTime[2] & 0xFF00) >> 8;
        *buf = (iter->leftTime[2] & 0xFF);
        iter++;
	}

    *++buf = ',';
}
void mappack(Map map,uint8_t buf[])
{
    list<Lane>::size_type lane_num ;
    lane_num= map.lanes.size();
    cout<<"map lane num="<<lane_num<<endl;
    list<Lane>::iterator iter = map.lanes.begin();
    buf[0] = (map.mapId & 0xFF000000) >> 24;
    buf[1] = (map.mapId & 0xFF0000) >> 16;
    buf[2] = (map.mapId & 0xFF00) >> 8;
    buf[3] = (map.mapId & 0xFF);

    buf[4] = (map.mapCenter.latitude & 0xFF00000000000000) >> 56;
    buf[5] = (map.mapCenter.latitude & 0xFF000000000000) >> 48;
    buf[6] = (map.mapCenter.latitude & 0xFF0000000000) >> 40;
    buf[7] = (map.mapCenter.latitude & 0xFF00000000) >> 32;
    buf[8] = (map.mapCenter.latitude & 0xFF000000) >> 24;
    buf[9] = (map.mapCenter.latitude & 0xFF0000) >> 16;
    buf[10] = (map.mapCenter.latitude & 0xFF00) >> 8;
    buf[11] = (map.mapCenter.latitude & 0xFF);

    buf[12] = (map.mapCenter.longitude & 0xFF00000000000000) >> 56;
    buf[13] = (map.mapCenter.longitude & 0xFF000000000000) >> 48;
    buf[14] = (map.mapCenter.longitude & 0xFF0000000000) >> 40;
    buf[15] = (map.mapCenter.longitude & 0xFF00000000) >> 32;
    buf[16] = (map.mapCenter.longitude & 0xFF000000) >> 24;
    buf[17] = (map.mapCenter.longitude & 0xFF0000) >> 16;
    buf[18] = (map.mapCenter.longitude & 0xFF00) >> 8;
    buf[19] = (map.mapCenter.longitude & 0xFF);
    buf+= 19;
    int num=0;
    while (num<lane_num)
	{
        num++;
		buf++;
		*buf++ = (iter->laneId & 0xFF00000000000000) >> 56;
		*buf++ = (iter->laneId & 0xFF000000000000) >> 48;
		*buf++ = (iter->laneId & 0xFF0000000000) >> 40;
		*buf++ = (iter->laneId & 0xFF00000000) >> 32;
		*buf++ = (iter->laneId & 0xFF000000) >> 24;
		*buf++ = (iter->laneId & 0xFF0000) >> 16;
		*buf++ = (iter->laneId & 0xFF00) >> 8;
		*buf++ = (iter->laneId & 0xFF);

		*buf++ = (iter->laneCenter.latitude & 0xFF00000000000000) >> 56;
		*buf++ = (iter->laneCenter.latitude & 0xFF000000000000) >> 48;
		*buf++ = (iter->laneCenter.latitude & 0xFF0000000000) >> 40;
		*buf++ = (iter->laneCenter.latitude & 0xFF00000000) >> 32;
		*buf++ = (iter->laneCenter.latitude & 0xFF000000) >> 24;
		*buf++ = (iter->laneCenter.latitude & 0xFF0000) >> 16;
		*buf++ = (iter->laneCenter.latitude & 0xFF00) >> 8;
		*buf++ = (iter->laneCenter.latitude & 0xFF);

		*buf++ = (iter->laneCenter.longitude & 0xFF00000000000000) >> 56;
		*buf++ = (iter->laneCenter.longitude & 0xFF000000000000) >> 48;
		*buf++ = (iter->laneCenter.longitude & 0xFF0000000000) >> 40;
		*buf++ = (iter->laneCenter.longitude & 0xFF00000000) >> 32;
		*buf++ = (iter->laneCenter.longitude & 0xFF000000) >> 24;
		*buf++ = (iter->laneCenter.longitude & 0xFF0000) >> 16;
		*buf++ = (iter->laneCenter.longitude & 0xFF00) >> 8;
        *buf = (iter->laneCenter.longitude & 0xFF);
        iter ++;
	}
    *++buf = ',';
}
