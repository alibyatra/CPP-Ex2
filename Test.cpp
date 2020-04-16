#include "FamilyTree.hpp"
#include <iostream>
#include "doctest.h"

using namespace family;
using namespace std;

//First Family

TEST_CASE("Check the relationship between the family - jewish")
{
    family::Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov")   
	 .addMother("Yosef", "Rachel")

	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
     .addFather("Rachel","Cohen")
     .addMother("Rachel", "Yamit")

	 .addFather("Isaac", "Avraham")
     .addMother("Isaac", "Ronit")
     .addFather("Rivka", "Yossi")
     .addMother("Rivka", "Yolet")
     .addFather("Cohen", "Raphael")
     .addMother("Cohen", "Alla")
     .addFather("Yamit", "Menahim")
     .addMother("Yamit", "Rvital")

	 .addFather("Avraham", "Terah")
     .addMother("Avraham", "Taair")
     .addFather("Ronit", "Mosa")
     .addMother("Ronit", "Dalit")
     .addFather("Yossi", "Omer")
     .addMother("Yossi", "Yasmine")
     .addFather("Yolet", "Eyal")
     .addMother("Yolet", "Anahel")
     .addFather("Raphael", "Itay")
     .addMother("Raphael", "Aodilia")
     .addFather("Alla", "Avi")
     .addMother("Alla", "Tom")
     .addFather("Menahim", "Tomer")
     .addMother("Menahim", "Avital")
     .addFather("Rvital", "Maxim")
     .addMother("Rvital", "Hila");

	T.display();                    
    CHECK(T.relation("Yosef") == "me");
    CHECK(T.relation("Yaakov") == "father");
    CHECK(T.relation("Rachel") == "mother");

    CHECK(T.relation("Isaac") == "grandfather");
    CHECK(T.relation("Rivka") == "grandmother");
    CHECK(T.relation("Cohen") == "grandfather");
    CHECK(T.relation("Yamit") == "grandmother");

    CHECK(T.relation("Avraham") == "great-grandfather");
    CHECK(T.relation("Ronit") == "great-grandmother");
    CHECK(T.relation("Yossi") == "great-grandfather");
    CHECK(T.relation("Yolet") == "great-grandmother");
    CHECK(T.relation("Raphael") == "great-grandfather");
    CHECK(T.relation("Alla") == "great-grandmother");
    CHECK(T.relation("Menahim") == "great-grandfather");
    CHECK(T.relation("Rvital") == "great-grandmother");

    CHECK(T.relation("Terah") == "great-great-grandfather");
    CHECK(T.relation("Taair") == "great-great-grandmother");
    CHECK(T.relation("Mosa") == "great-great-grandfather");
    CHECK(T.relation("Dalit") == "great-great-grandmother");
    CHECK(T.relation("Omer") == "great-great-grandfather");
    CHECK(T.relation("Yasmine") == "great-great-grandmother");
    CHECK(T.relation("Eyal") == "great-great-grandfather");
    CHECK(T.relation("Anahel") == "great-great-grandmother");
    CHECK(T.relation("Itay") == "great-great-grandfather");
    CHECK(T.relation("Aodilia") == "great-great-grandmother");
    CHECK(T.relation("Avi") == "great-great-grandfather");
    CHECK(T.relation("Tom") == "great-great-grandmother");
    CHECK(T.relation("Tomer") == "great-great-grandfather");
    CHECK(T.relation("Avital") == "great-great-grandmother");
    CHECK(T.relation("Maxim") == "great-great-grandfather");
    CHECK(T.relation("Hila") == "great-great-grandmother");

    CHECK(T.relation("Adam") == "unrelated");

    T.remove("Avraham");
    CHECK(T.relation("Avraham") == "unrelated");
    CHECK(T.relation("Terah") == "unrelated");
    CHECK(T.relation("Taair") == "unrelated");    

    T.remove("Rvital");
    CHECK(T.relation("Rvital") == "unrelated");
    CHECK(T.relation("Maxim") == "unrelated");
    CHECK(T.relation("Hila") == "unrelated");

    T.remove("Cohen");
    CHECK(T.relation("Cohen") == "unrelated");
    CHECK(T.relation("Raphael") == "unrelated");
    CHECK(T.relation("Alla") == "unrelated");
    CHECK(T.relation("Itay") == "unrelated");
    CHECK(T.relation("Aodilia") == "unrelated");
    CHECK(T.relation("Avi") == "unrelated");
    CHECK(T.relation("Tom") == "unrelated");

    CHECK(T.find("me") == "Yosef");
    CHECK(T.find("mother") == "Rachel");
    CHECK(T.find("father") == "Yaakov");
    CHECK(T.find("grandfather") == "Isaac");
    CHECK(T.find("grandmother") == "Yamit");
    CHECK(T.find("great-grandfather") == "Yossi");
    CHECK(T.find("great-grandmother") == "Yolet");
    CHECK(T.find("great-great-grandfather") == "Eyal");
    CHECK(T.find("great-great-grandmother") == "Anahel");
}
//Second Family
TEST_CASE("Check the relationship between the family - Arabic")
{
    family::Tree T2 ("Ali"); 
	T2.addFather("Ali", "Muhammad")   
	 .addMother("Ali", "Angham")

	 .addFather("Muhammad", "Ismael")
	 .addMother("Muhammad", "Ahlam")
     .addFather("Angham","Rami")
     .addMother("Angham", "Tala")

	 .addFather("Ismael", "Fared")
     .addMother("Ismael", "Nagham")
     .addFather("Ahlam", "Fares")
     .addMother("Ahlam", "Hala")
     .addFather("Rami", "Ahmad")
     .addMother("Rami", "Monaia")
     .addFather("Tala", "Samer")
     .addMother("Tala", "Timaa")

	 .addFather("Fared", "Ameer")
     .addMother("Fared", "Rima")
     .addFather("Nagham", "Mohanad")
     .addMother("Nagham", "Layal")
     .addFather("Fares", "Omair")
     .addMother("Fares", "Layal")
     .addFather("Hala", "Eyad")
     .addMother("Hala", "Rana")
     .addFather("Ahmad", "Ziad")
     .addMother("Ahmad", "Rwan")
     .addFather("Monaia", "Montaser")
     .addMother("Monaia", "Leen")
     .addFather("Samer", "Fadi")
     .addMother("Samer", "Aseel")
     .addFather("Timaa", "Malik")
     .addMother("Timaa", "Rahaf");

	T2.display();               

    CHECK(T2.relation("Ali") == "me");
    CHECK(T2.relation("Muhammad") == "father");
    CHECK(T2.relation("Angham") == "mother");

    CHECK(T2.relation("Ismael") == "grandfather");
    CHECK(T2.relation("Ahlam") == "grandmother");
    CHECK(T2.relation("Rami") == "grandfather");
    CHECK(T2.relation("Tala") == "grandmother");

    CHECK(T2.relation("Fared") == "great-grandfather");
    CHECK(T2.relation("Nagham") == "great-grandmother");
    CHECK(T2.relation("Fares") == "great-grandfather");
    CHECK(T2.relation("Hala") == "great-grandmother");
    CHECK(T2.relation("Ahmad") == "great-grandfather");
    CHECK(T2.relation("Monaia") == "great-grandmother");
    CHECK(T2.relation("Samer") == "great-grandfather");
    CHECK(T2.relation("Timaa") == "great-grandmother");

    CHECK(T2.relation("Ameer") == "great-great-grandfather");
    CHECK(T2.relation("Rima") == "great-great-grandmother");
    CHECK(T2.relation("Mohanad") == "great-great-grandfather");
    CHECK(T2.relation("Layal") == "great-great-grandmother");
    CHECK(T2.relation("Omair") == "great-great-grandfather");
    CHECK(T2.relation("Layal") == "great-great-grandmother");
    CHECK(T2.relation("Eyad") == "great-great-grandfather");
    CHECK(T2.relation("Rana") == "great-great-grandmother");
    CHECK(T2.relation("Ziad") == "great-great-grandfather");
    CHECK(T2.relation("Rwan") == "great-great-grandmother");
    CHECK(T2.relation("Montaser") == "great-great-grandfather");
    CHECK(T2.relation("Leen") == "great-great-grandmother");
    CHECK(T2.relation("Fadi") == "great-great-grandfather");
    CHECK(T2.relation("Aseel") == "great-great-grandmother");
    CHECK(T2.relation("Malik") == "great-great-grandfather");
    CHECK(T2.relation("Rahaf") == "great-great-grandmother");

    CHECK(T2.relation("Saeed") == "unrelated");

    T2.remove("Fared");
    CHECK(T2.relation("Fared") == "unrelated");
    CHECK(T2.relation("Ameer") == "unrelated");
    CHECK(T2.relation("Rima") == "unrelated");    

    T2.remove("Timaa");
    CHECK(T2.relation("Timaa") == "unrelated");
    CHECK(T2.relation("Malik") == "unrelated");
    CHECK(T2.relation("Rahaf") == "unrelated");

    T2.remove("Rami");
    CHECK(T2.relation("Rami") == "unrelated");
    CHECK(T2.relation("Ahmad") == "unrelated");
    CHECK(T2.relation("Monaia") == "unrelated");
    CHECK(T2.relation("Ziad") == "unrelated");
    CHECK(T2.relation("Rwan") == "unrelated");
    CHECK(T2.relation("Montaser") == "unrelated");
    CHECK(T2.relation("Leen") == "unrelated");

    CHECK(T2.find("me") == "Ali");
    CHECK(T2.find("mother") == "Angham");
    CHECK(T2.find("father") == "Muhammad");
    CHECK(T2.find("grandfather") == "Isamel");
    CHECK(T2.find("grandmother") == "Ahlam");
    CHECK(T2.find("great-grandfather") == "Fares");
    CHECK(T2.find("great-grandmother") == "Hala");
    CHECK(T2.find("great-great-grandfather") == "Omair");
    CHECK(T2.find("great-great-grandmother") == "Layal");
}
