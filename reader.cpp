# include "client_generated.h"

# include <fstream>
# include <iostream>
# include <sstream>
# include <cstring>

using namespace Assignment;

void printPerson(const Person *personClient) {
    std::cout << "{" << personClient->name()->str();
    std::cout << ", " << unsigned(personClient->age());
    std::cout << ", " << personClient->weight();

    auto personGender = personClient->gender();

    std::cout << ", " << Assignment::EnumNameGenders(personGender);
    std::cout << "}" << std::endl;
}

void printGroup(const Group *groupClient) {
    std::cout << "{" << groupClient->group_name()->str();
    std::cout << ", " << groupClient->avg_age();
    std::cout << ", " << groupClient->avg_weight();

    std::cout << ", {";
    auto nameList = groupClient->name_list();
    if (nameList->size() != 0) {
      bool firstElement = true;

      for (auto name: *nameList) {
        if (firstElement) firstElement = false;
        else std::cout << ", ";
        std::cout << name->str();
      }
    }
    std::cout << "}}" << std::endl;
}

void processBuffer(const uint8_t* bf_ptr) {
  auto pOrGClient = GetSizePrefixedClient(bf_ptr);
  auto clientType = std::string(Assignment::EnumNamePersonOrGroup(pOrGClient->client_type()));

  if (clientType == "Person") {
    auto personClient = pOrGClient->client_as_Person();
    printPerson(personClient);

  } else {
    auto groupClient = pOrGClient->client_as_Group();
    printGroup(groupClient);
  }
}

int main(int argc, const char* argv[]) {
  std::string binPath = "fb_bytes.bin";
  if (argc >= 2) binPath = std::string(argv[1]);

  char* inData;
  unsigned int length;

  std::ifstream inFile;
  inFile.open(binPath);

  if (inFile) {
    inFile.seekg(0, inFile.end);
    length = inFile.tellg();
    inFile.seekg(0, inFile.beg);

    inData = new char[length];

    inFile.read (inData,length);
  }

  const uint8_t *bf_ptr = reinterpret_cast<const uint8_t*>(inData);
  int curOffset = 0;

  while (curOffset < length) {
    unsigned int curSize;
    for (int i=3; i>=0; i--) {
      curSize <<= 8;
      curSize += bf_ptr[i];
    }

    processBuffer(bf_ptr);
    bf_ptr += curSize + 4;
    curOffset += curSize + 4;
  }
 
  return 0;
}
