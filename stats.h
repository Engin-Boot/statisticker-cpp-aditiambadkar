#include <vector>

namespace Statistics {
    
    struct Stats {
        float average;
        float max;
        float min;
    };
    extern struct Stats statsObj;
    Stats ComputeStatistics(const std::vector<float>& );
    float ComputeAverage(std::vector<float>& );
}
