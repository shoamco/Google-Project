//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
#define AUTOCOMPLETEGOOGLE_OFFLINEDATA_H

#include <unordered_map>
#include "AutoCompleteData.h"
#include "vector"
typedef std::vector<AutoCompleteData> VectorCompletion;
typedef std::unordered_map<std::string, VectorCompletion> MapComplete;

/**

     OffLineData

 hold the hash table that holds all possible completions calculated offline
 * */
class OffLineData {
public:
    OffLineData();
    MapComplete GetMap()const ;
    VectorCompletion GetVectorCompletion(const std::string key) ;

private:
    MapComplete offline_table;

};

inline OffLineData::OffLineData() {
    AutoCompleteData autoCompleteData1("Moses_and_the_Sages__Bibl", 15750,
                                       " And the saying pleased me well: and I took twelve men of you, one");

    AutoCompleteData autoCompleteData2("Moses_and_the_Sages__Bibl", 7039,
                                       "gaping mouths, the staring lustreless eyes, fascinated him. He knew in"
    );
    VectorCompletion vectorComplete{autoCompleteData1, autoCompleteData2};
    offline_table = {
            {"twelve",     vectorComplete},
            {
             "And twelve", vectorComplete
            },{
                "I took twelve",vectorComplete
            }
    };

}
inline VectorCompletion OffLineData::GetVectorCompletion(const std::string key ){
    return offline_table[key];

}
inline MapComplete OffLineData::GetMap() const {
    return offline_table;

}
inline void printVectorCompletion(VectorCompletion vec){
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i)<<std::endl;
    }
}
inline void printAllCompletion(VectorCompletion vec){
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i).GetCompletedSentence()<<"\n\n";
    }
}
#endif //AUTOCOMPLETEGOOGLE_OFFLINEDATA_H
