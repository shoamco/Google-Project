//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
#define AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
#include <unordered_map>
class OffLineData{
public:
    OffLineData();
    // Create an unordered_map of three strings (that map to strings)
std::unordered_map<std::string, std::string> offline_table;
};
inline OffLineData::OffLineData() {
    offline_table= {
            {"RED","#FF0000"},
            {"GREEN","#00FF00"},
            {"BLUE","#0000FF"}
    };
}
#endif //AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
