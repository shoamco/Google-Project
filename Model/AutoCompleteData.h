//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
#define AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H

#include <string>
#include<string.h>

class AutoCompleteData {
public:
    AutoCompleteData(std::string source_text, size_t offset, int score);

    int CalculateSource();

    friend std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData);

    size_t GetOffset();

//    size_t GetCompletedSentenceLine();

    int GetScore();

private:
    std::string source_text;
    size_t offset;
    int score;

};
inline size_t AutoCompleteData::GetOffset(){
    return offset;
}
//inline int AutoCompleteData::GetCompletedSentenceLine() {
//    return completed_sentence;
//
//}
inline int AutoCompleteData::GetScore() {
    return score;

}


inline   AutoCompleteData::AutoCompleteData(std::string source_text, size_t offset, int score)
        : source_text(source_text), offset(offset), score(score) {


}

inline std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData) {
    ostream << "\n\nAutoCompleteData: \n";
    ostream << "source_text: " << autoCompleteData.source_text;
    ostream << "\noffset: " << autoCompleteData.offset;
//    ostream << "\ncompleted_sentence: " << autoCompleteData.completed_sentence;
    ostream << "\nscore: " << autoCompleteData.score;

    return ostream << std::endl;
}

#endif //AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
