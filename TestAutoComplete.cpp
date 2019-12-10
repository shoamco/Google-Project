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
    AutoCompleteData autoCompleteData(" And the saying pleased me well: and I took twelve men of you, one",
                                      "Moses_and_the_Sages__Bibl", 8);
    std::cout<<autoCompleteData;

}

/***************  Test Class  OffLineData  *************/
void test_init_offline_data() {

}