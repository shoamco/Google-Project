//
// Created by shoam on 12/10/19.
//

#include "TestAutoComplete.h"
//*********** GOOGLE TEST************
//TEST(AutoCompleteDataTests, ctor) {
//
//}

//std::string file_name("../test.json");
std::string file_name("../Adventures_of_Huckleberry_Finn.json");
HandleFile handleFile;

//std::vector<std::string> lines=handleFile.FileToArray("../t.txt");
std::vector<std::string> lines=handleFile.FileToArray("../outputAdventures_of_Huckleberry_Finn.txt");
MapComplete mapComplete=handleFile.JsonFileToMap(file_name);

/***************   Test Class GoogleSearch  *************/
void testRunSearch() {
    std::cout << "\n******test run search *****\n\n" << std::endl;
    OffLineData offLineData(mapComplete,lines);
    GoogleCompletion googleSearch(offLineData);
    googleSearch.Run();
}

/***************  Test Class   GoogleSearch  *************/
void testCreateAutoCompleteData() {
    std::cout << "\n******test  testCreateAutoCompleteData *****\n\n" << std::endl;
    AutoCompleteData autoCompleteData("Moses_and_the_Sages__Bibl",15750,28);
    std::cout<<autoCompleteData;

}

/***************  Test Class  OffLineData  *************/
void test_init_offline_data() {
    std::cout << "\n******  test_init_offline_data *****\n\n" << std::endl;

    OffLineData offLineData(mapComplete,lines);
    VectorCompletion vectorCompletion=offLineData.GetVectorCompletion("twelve");
    printVectorCompletion(vectorCompletion);



}
/***************  Test Class HandleFile *************/
void test_open_json_file(){
    HandleFile handleFile;
    std::string file_name("../test.json");
    MapComplete mapComplete=handleFile.JsonFileToMap(file_name);
    std::cout<<"mapComplete"<<mapComplete.size();
    OffLineData offLineData(mapComplete,lines);


}
void test_file_to_array(){
  HandleFile handleFile;
  std::vector<std::string> lines=handleFile.FileToArray("../t.txt");
  std::cout<<"size vector "<<lines.size()<<std::endl;
    for (auto i = lines.begin(); i != lines.end(); ++i)
        std::cout << *i << ' ';
}