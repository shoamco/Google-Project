//
// Created by shoam on 12/10/19.
//

#ifndef AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
#define AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H

#include <string>

class AutoCompleteData {
public:
    AutoCompleteData(std::string completed_sentence, std::string source_text, int offset);

    int CalculateSource();
    friend std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData);

private:
    std::string completed_sentence;
    std::string source_text;
    int offset;
    int score;

};
inline int AutoCompleteData::CalculateSource(){
    return 1;
}
inline   AutoCompleteData::AutoCompleteData(std::string completed_sentence, std::string source_text, int offset)
        : completed_sentence(completed_sentence), source_text(source_text), offset(offset) {
    score=CalculateSource();

}
inline std::ostream &operator<<(std::ostream &ostream, const AutoCompleteData autoCompleteData){
    ostream << "AutoCompleteData: \n";
    ostream<<"completed_sentence: "<<autoCompleteData.completed_sentence;
    ostream<<"\nsource_text: "<<autoCompleteData.source_text;
    ostream<<"\noffset: "<<autoCompleteData.offset;
    ostream<<"\nscore: "<<autoCompleteData.score;

    return  ostream <<std::endl;
}
#endif //AUTOCOMPLETEGOOGLE_AUTOCOMPLETEDATA_H
