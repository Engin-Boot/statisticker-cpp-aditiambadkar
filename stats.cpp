#include "stats.h"
#include <bits/stdc++.h>
#include <math.h>
namespace Statistics {
    
    std::vector<float> RemoveNANElements(const std::vector<float>& floatVector) {
        std::vector<float> floatVectorWithoutNAN = {};
        std::vector<float>::const_iterator itr = floatVector.begin();
        while(itr != floatVector.end())
        {
            if(!isnan(*itr))
                floatVectorWithoutNAN.push_back(*itr);
            itr++;
        }
        return floatVectorWithoutNAN;
    }
    
    Stats ComputeStatistics(const std::vector<float>& floatVector) {
        struct Stats statsObj = {NAN, NAN, NAN};
        if(floatVector.size() == 0)
            return statsObj;
        std::vector<float> floatVectorWithoutNAN = RemoveNANElements(floatVector);
        if(floatVectorWithoutNAN.size() == 0)
            return statsObj;
        statsObj.average = accumulate(floatVectorWithoutNAN.begin(), floatVectorWithoutNAN.end(), 0.0) / floatVectorWithoutNAN.size();
        statsObj.max = *max_element(floatVectorWithoutNAN.begin(), floatVectorWithoutNAN.end());
        statsObj.min = *min_element(floatVectorWithoutNAN.begin(), floatVectorWithoutNAN.end());
        std::cout<<statsObj.average<<" "<< tatsObj.max<<" "<<statsObj.min<<std::endl;
        
        return statsObj;
    }
    
}
