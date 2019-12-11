//
// Created by shoam on 12/10/19.
//

#include "TestAutoComplete.h"
//*********** GOOGLE TEST************
//TEST(AutoCompleteDataTests, ctor) {
//
//}
/***************   Test Class GoogleSearch  *************/
void testRunSearch() {
    std::cout << "\n******test run search *****\n\n" << std::endl;
    GoogleSearch googleSearch;
    googleSearch.Run();
}

/***************  Test Class   GoogleSearch  *************/
void testCreateAutoCompleteData() {
    std::cout << "\n******test  testCreateAutoCompleteData *****\n\n" << std::endl;
    AutoCompleteData autoCompleteData("Moses_and_the_Sages__Bibl",15750," And the saying pleased me well: and I took twelve men of you, one",28);
    std::cout<<autoCompleteData;

}

/***************  Test Class  OffLineData  *************/
void test_init_offline_data() {
    std::cout << "\n******  test_init_offline_data *****\n\n" << std::endl;

    OffLineData offLineData;
    VectorCompletion vectorCompletion=offLineData.GetVectorCompletion("twelve");
    printVectorCompletion(vectorCompletion);



}

void test_open_json_file(){
    //    std::ifstream file("offline_result.json");
////    json j;
//    json data_json;
//    file >> data_json;
//std::string file_path("offline_result.json");
//std::string file_name("outputWilliam_Shakespeare__Hamlet.txt");
    std::string file_name("../profile.json");
//    std::string file_name("offline_result.json");
//    std::ifstream ifs{"offline_result.json"};


    std::ifstream file(file_name);
    if (file.is_open()) {
        json data_json = json::parse(file);
        for (json::iterator it = data_json.begin(); it != data_json.end(); ++it) {
            std::cout << it.key() << " : " << it.value() << std::endl;
        }
    }
    else
    { throw "Unable to open file";}
}