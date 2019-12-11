//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
#define AUTOCOMPLETEGOOGLE_OFFLINEDATA_H

#include <unordered_map>
#include "Model/AutoCompleteData.h"
#include "vector"
#include <json.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json;
typedef std::vector<AutoCompleteData> VectorCompletion;
typedef std::vector<std::string> VectorString;
typedef std::unordered_map<std::string, VectorCompletion> MapComplete;

/**

     OffLineData

 hold the hash table that holds all possible completions calculated offline
 * */
class OffLineData {
public:
    OffLineData(MapComplete offline_table,VectorString all_source_text);

    MapComplete GetMap() const;

    VectorCompletion GetVectorCompletion(const std::string key);

    int *GetAllCompletion(const std::string key);
    std::string getLineByOffset(int offset);

private:
    MapComplete offline_table;
     VectorString lines;

//    json offline_data;

};
inline std::string OffLineData::getLineByOffset(int offset){
    return lines[offset-1];

}

inline OffLineData::OffLineData( MapComplete mapComplete,VectorString lines):offline_table(mapComplete),lines(lines) {


}

inline VectorCompletion OffLineData::GetVectorCompletion(const std::string key) {
    return offline_table[key];

}



inline MapComplete OffLineData::GetMap() const {
    return offline_table;

}

inline void printVectorCompletion(VectorCompletion vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << std::endl;
    }
}

inline void printAllCompletion(VectorCompletion vec) {
//    for (int i = 0; i < vec.size(); i++) {
////        std::cout << vec.at(i).GetCompletedSentence()<<"\n\n";
//        std::cout << getLineByOffset(vec.at(i).GetOffset()) << " (score: " << vec.at(i).GetScore() << " )" << "\n\n";
//    }
}

inline void printOfflineData(json offline_data) {
    for (json::iterator it = offline_data.begin(); it != offline_data.end(); ++it) {
         std::cout << it.key() << " : " << it.value() << std::endl;
    }

}

#endif //AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
