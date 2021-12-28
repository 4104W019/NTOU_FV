#include "boundaryvalue.h"
#include <iostream>

using namespace std;

int BoundaryValue::testBoundaryValue(int current_temperature)
{
        // config
        int temperature_thresh_cold = 16;
        int temperature_thresh_hot = 28;
        int status = -1;
        
        if(current_temperature <= temperature_thresh_cold){
                cout << '溫度過冷, 啟動暖氣' << endl;
                status = 1;
        }else if(current_temperature >= temperature_thresh_hot){
                cout << '溫度過熱, 啟動冷氣' << endl;
                status = 2;
        }else{
                cout << '溫度正常...' << endl;
                status = 0;
        }

        return status;
}
