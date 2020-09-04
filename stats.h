#include <vector>

namespace Statistics {
    
    struct Stats {
        float average;
        float max;
        float min;
    };
    extern struct Stats statsObj;
    Stats ComputeStatistics(const std::vector<float>& );
    std::vector<float> RemoveNANElements(const std::vector<float>& );
}
