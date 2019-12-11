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
typedef std::unordered_map<std::string, VectorCompletion> MapComplete;

/**

     OffLineData

 hold the hash table that holds all possible completions calculated offline
 * */
class OffLineData {
public:
    OffLineData(MapComplete offline_table);

    MapComplete GetMap() const;

    VectorCompletion GetVectorCompletion(const std::string key);

    int *GetAllCompletion(const std::string key);

private:
    MapComplete offline_table;
//    json offline_data;

};
inline json openFileToJson(std::string file_name){

}
inline OffLineData::OffLineData( MapComplete mapComplete):offline_table(mapComplete) {
//    int score;
//    std::string completed_sentence;
//    std::string source_text;
//    json offline_data;
//    std::string file_name("../test.json");
//    std::ifstream file(file_name);
//    if (file.is_open()) {
//        offline_data = json::parse(file);
//
//        for (json::iterator it = offline_data.begin(); it != offline_data.end(); ++it) {
//          completed_sentence=it.key();
//
//            score = it.value()[1];
//            source_text = it.value()[0];
//            int x = it.value()[2][0];
//            int line;
//
//            VectorCompletion vectorComplete;
//            for (int i = 0; i < it.value()[2].size(); ++i) {//enter to vector  all completed sentence
//                line = it.value()[2][i];
//                AutoCompleteData autoCompleteData(source_text,line,completed_sentence,score);
//                vectorComplete.push_back(autoCompleteData);
//            }
//
//            std::pair<std::string,VectorCompletion> pair_data (completed_sentence,vectorComplete);
//            offline_table.insert(pair_data);
//        }
//    } else { throw "Unable to open file"; }


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
    for (int i = 0; i < vec.size(); i++) {
//        std::cout << vec.at(i).GetCompletedSentence()<<"\n\n";
        std::cout << vec.at(i).GetCompletedSentence() << " (score: " << vec.at(i).GetScore() << " )" << "\n\n";
    }
}

inline void printOfflineData(json offline_data) {
    for (json::iterator it = offline_data.begin(); it != offline_data.end(); ++it) {
//          offline_table.insert ( std::make_pair<std::string,double>>(it.key(),it.value()))
        std::cout << it.key() << " : " << it.value() << std::endl;
        std::cout << it.key() << " : " << it.value() << std::endl;
    }

}

#endif //AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
