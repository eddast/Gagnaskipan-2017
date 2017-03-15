#include <iostream>
#include <vector>
#include <queue>
#include <set>
// + multiset and pairs + map
#include "measurement.h"

int main()
{
    std:: cout << "-------------" << std::endl;
    std::cout << "STL Program" << std::endl;
    std:: cout << "-------------" << std::endl;

    std::set<int> set;
    set.insert(2);
    set.insert(1);
    set.insert(1);
    set.insert(4);
    set.insert(3);
    set.insert(3);
    set.insert(5);


    std::cout << "Set: " << std::endl;
    for (std::set<int>::iterator p = set.begin(); p != set.end();p++){
        std::cout << *p << " ";
    }
    std:: cout << std::endl;

    set.erase(3);

    std::cout << "Removed 3: " << std::endl;
    for (std::set<int>::iterator p = set.begin(); p != set.end();p++){
        std::cout << *p << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;





    std::cout << "Vector of ADT Measurement: " << std::endl;
    std::vector<Measurement> vector;

    Measurement m;
    m.address = "Holar 3";
    m.value = 3.3;

    vector.push_back(m);

    m.address = "Vogar 3";
    m.value = 3.7;

    vector.push_back(m);

    m.address = "Holt 10";
    m.value = 3.23;

    vector.push_back(m);

    m.address = "Hlidar 5";
    m.value = 3.4;

    vector.push_back(m);

    m.address = "Vogar 3";
    m.value = 3.7;

    vector.push_back(m);

    for(std::vector<Measurement>::iterator it = vector.begin(); it != vector.end(); it++){
        std::cout << it->address << ": " << it->value << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;




    std::cout << "Set of ADT Measurement: " << std::endl;
    std::set<Measurement> messet;

    Measurement m1;
    m1.address = "Holar 3";
    m1.value = 3.3;

    messet.insert(m1);

    m1.address = "Vogar 3";
    m1.value = 3.7;

    messet.insert(m1);

    m1.address = "Holt 10";
    m1.value = 3.7;

    messet.insert(m1);

    m1.address = "Hlidar 5";
    m1.value = 3.4;

    messet.insert(m1);

    m1.address = "Vogar 3";
    m1.value = 3.7;

    messet.insert(m1);

    for(std::set<Measurement>::iterator it = messet.begin(); it != messet.end(); it++){
        std::cout << it->address << ": " << it->value << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;




    std::cout << "Multiset of ADT Measurement: " << std::endl;
    std::multiset<Measurement> multiset;

    Measurement m2;
    m2.address = "Holar 3";
    m2.value = 3.3;

    multiset.insert(m1);

    m2.address = "Vogar 3";
    m2.value = 3.7;

    multiset.insert(m1);

    m2.address = "Holt 10";
    m2.value = 3.7;

    multiset.insert(m2);

    m2.address = "Hlidar 5";
    m2.value = 3.4;

    multiset.insert(m2);

    for(std::multiset<Measurement>::iterator it = multiset.begin(); it != multiset.end(); it++){
        std::cout << it->address << ": " << it->value << std::endl;
    }

    std::pair<std::multiset<Measurement>::iterator, std::multiset<Measurement>::iterator> iteratorpair;
    iteratorpair = multiset.equal_range(m);

    std::cout << "Using iterator pair: " << std::endl;
    for(std::multiset<Measurement>::iterator it = iteratorpair.first; it != iteratorpair.second; it++){
            std::cout << it->address << ": " << it->value << std::endl;
    }

    return 0;
}


