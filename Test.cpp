#include "FamilyTree.hpp"
#include <iostream>
#include "doctest.h"

using namespace family;
using namespace std;

//First Family

TEST_CASE("Check the relationship between the family - jewish")
{
    family::Tree T ("Ali"); 
	CHECK(T.relation("Ali" ) == string("me"));   
    CHECK(T.relation("Muhammad" ) == string("father"));
    CHECK(T.relation("Muhammad" ) == string("mother"));
    CHECK(T.relation("Muhammad" ) == string("grandmother"));
    CHECK(T.relation("Muhammad" ) == string("grandfather"));
    CHECK(T.relation("Muhammad" ) == string("great-grandfather"));
    CHECK(T.relation("Muhammad" ) == string("great-grandmather"));
    CHECK(T.relation("Muhammad" ) == string("great-great-grandmother"));
    CHECK(T.relation("Muhammad" ) == string("great-great-grandfather"));
    CHECK(T.relation("Muhammad" ) == string("unrelated"));

    CHECK(T.relation("Samer" ) == string("me"));
    CHECK(T.relation("Samer" ) == string("father"));
    CHECK(T.relation("Samer" ) == string("mother"));
    CHECK(T.relation("Samer"  ) == string("grandmother"));
    CHECK(T.relation("Samer"  ) == string("grandfather"));
    CHECK(T.relation("Samer" ) == string("great-grandfather"));
    CHECK(T.relation("Samer" ) == string("great-grandmather"));
    CHECK(T.relation("Samer"  ) == string("great-great-grandmother"));
    CHECK(T.relation("Samer"  ) == string("great-great-grandfather"));
    CHECK(T.relation("Samer") == string("unrelated"));

    CHECK(T.relation("Fared" ) == string("me"));
    CHECK(T.relation("Fared" ) == string("father"));
    CHECK(T.relation("Fared" ) == string("mother"));
    CHECK(T.relation("Fared"   ) == string("grandmother"));
    CHECK(T.relation("Fared"   ) == string("grandfather"));
    CHECK(T.relation("Fared" ) == string("great-grandfather"));
    CHECK(T.relation("Fared") == string("great-grandmather"));
    CHECK(T.relation("Fared") == string("great-great-grandmother"));
    CHECK(T.relation("Fared") == string("great-great-grandfather"));
    CHECK(T.relation("Fared") == string("unrelated"));

    CHECK(T.relation("Layal" ) == string("me"));
    CHECK(T.relation("Layal" ) == string("father"));
    CHECK(T.relation("Layal"  ) == string("mother"));
    CHECK(T.relation("Layal"   ) == string("grandmother"));
    CHECK(T.relation("Layal" ) == string("grandfather"));
    CHECK(T.relation("Layal" ) == string("great-grandfather"));
    CHECK(T.relation("Layal" ) == string("great-grandmather"));
    CHECK(T.relation("Layal" ) == string("great-great-grandmother"));
    CHECK(T.relation("Layal" ) == string("great-great-grandfather"));
    CHECK(T.relation("Layal" ) == string("unrelated"));

    CHECK(T.relation("Emad" ) == string("me"));
    CHECK(T.relation("Emad"  ) == string("father"));
    CHECK(T.relation("Emad"   ) == string("mother"));
    CHECK(T.relation("Emad"   ) == string("grandmother"));
    CHECK(T.relation("Emad" ) == string("grandfather"));
    CHECK(T.relation("Emad"  ) == string("great-grandfather"));
    CHECK(T.relation("Emad"  ) == string("great-grandmather"));
    CHECK(T.relation("Emad" ) == string("great-great-grandmother"));
    CHECK(T.relation("Emad"  ) == string("great-great-grandfather"));
    CHECK(T.relation("Emad"  ) == string("unrelated"));
}
TEST_CASE("testing relation"){
family::Tree T("Ali");

    CHECK(T.find("me" ) == string("Eyal"));
    CHECK(T.find("father" ) == string("Eyal"));
    CHECK(T.find("mother" ) == string("Eyal"));
    CHECK(T.find("grandmother" ) == string("Eyal"));
    CHECK(T.find("grandfather") == string("Eyal"));
    CHECK(T.find("great-grandfather") == string("Eyal"));
    CHECK(T.find("great-grandmather") == string("Eyal"));
    CHECK(T.find("great-great-grandmother" ) == string("Eyal"));
    CHECK(T.find("great-great-grandfather" ) == string("Eyal"));
    CHECK(T.find("great-great-great-grandfather" ) == string("Eyal"));

    CHECK_THROWS(T.find("uncle"));
    CHECK_THROWS(T.find("unt"));
    CHECK_THROWS(T.find("nothing"));
    CHECK_THROWS(T.find("brother"));
    CHECK_THROWS(T.find("sister"));
    CHECK_THROWS(T.find("cousin"));
    CHECK_THROWS(T.find("nephew"));


    CHECK(T.find("me" ) == string("Eyad"));
    CHECK(T.find("father" ) == string("Eyad"));
    CHECK(T.find("mother" ) == string("Eyad"));
    CHECK(T.find("grandmother" ) == string("Eyad"));
    CHECK(T.find("grandfather") == string("Eyad"));
    CHECK(T.find("great-grandfather") == string("Eyad"));
    CHECK(T.find("great-grandmather") == string("Eyad"));
    CHECK(T.find("great-great-grandmother" ) == string("Eyad"));
    CHECK(T.find("great-great-grandfather" ) == string("Eyad"));
    CHECK(T.find("great-great-great-grandfather" ) == string("Eyad"));


    CHECK(T.find("me" ) == string("Ronit"));
    CHECK(T.find("father" ) == string("Ronit"));
    CHECK(T.find("mother" ) == string("Ronit"));
    CHECK(T.find("grandmother" ) == string("Ronit"));
    CHECK(T.find("grandfather") == string("Ronit"));
    CHECK(T.find("great-grandfather") == string("Ronit"));
    CHECK(T.find("great-grandmather") == string("Ronit"));
    CHECK(T.find("great-great-grandmother" ) == string("Ronit"));
    CHECK(T.find("great-great-grandfather" ) == string("Ronit"));
    CHECK(T.find("great-great-great-grandfather" ) == string("Ronit"));

    CHECK(T.find("me" ) == string("Ali"));
    CHECK(T.find("father" ) == string("Ali"));
    CHECK(T.find("mother" ) == string("Ali"));
    CHECK(T.find("grandmother" ) == string("Ali"));
    CHECK(T.find("grandfather") == string("Ali"));
    CHECK(T.find("great-grandfather") == string("Ali"));
    CHECK(T.find("great-grandmather") == string("Ali"));
    CHECK(T.find("great-great-grandmother" ) == string("Ali"));
    CHECK(T.find("great-great-grandfather" ) == string("Ali"));
    CHECK(T.find("great-great-great-grandfather" ) == string("Ali"));


    CHECK(T.find("me" ) == string("Faris"));
    CHECK(T.find("father" ) == string("Faris"));
    CHECK(T.find("mother" ) == string("Faris"));


}