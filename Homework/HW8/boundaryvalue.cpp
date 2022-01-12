#include "boundaryvalue.h"
#include <iostream>

using namespace std;

int BoundaryValue::testBoundaryValue(int current_temperature)
{
        // config
        int temperature_thresh_cold = 16;
        int temperature_thresh_hot = 28;
        int status = -1;
//        char *status_[3]={ "the temperature is suitable.",
//                          ,"too cold, turn on the heating."
//                          ,"too hot, turn on the air condition."
//                         };
        if(current_temperature <= temperature_thresh_cold){
                status = 1;
        }else if(current_temperature >= temperature_thresh_hot){
                status = 2;
        }else{
                status = 0;
        }

        return status;
}
