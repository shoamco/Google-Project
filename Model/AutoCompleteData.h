//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
#define AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H

#include <string>
#include<string.h>
class AutoCompleteData {
public:
    AutoCompleteData(std::string source_text, int offset, std::string completed_sentence,int score);

    int CalculateSource();

    friend std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData);

    std::string GetCompletedSentence();
    int GetScore();

private:
    std::string source_text;
    int offset;
    std::string completed_sentence;
    int score;

};

inline std::string AutoCompleteData::GetCompletedSentence() {
    return completed_sentence;

}
inline int AutoCompleteData::GetScore() {
    return score;

}

inline int AutoCompleteData::CalculateSource() {
    return strlen(completed_sentence.c_str())*2 ;
}

inline   AutoCompleteData::AutoCompleteData(std::string source_text, int offset, std::string completed_sentence,int score)
        : source_text(source_text), offset(offset), completed_sentence(completed_sentence),score(score) {


}

inline std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData) {
    ostream << "\n\nAutoCompleteData: \n";
    ostream << "source_text: " << autoCompleteData.source_text;
    ostream << "\noffset: " << autoCompleteData.offset;
    ostream << "\ncompleted_sentence: " << autoCompleteData.completed_sentence;
    ostream << "\nscore: " << autoCompleteData.score;

    return ostream << std::endl;
}

#endif //AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
