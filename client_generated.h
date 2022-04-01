// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENT_ASSIGNMENT_H_
#define FLATBUFFERS_GENERATED_CLIENT_ASSIGNMENT_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 2 &&
              FLATBUFFERS_VERSION_MINOR == 0 &&
              FLATBUFFERS_VERSION_REVISION == 6,
             "Non-compatible flatbuffers version included");

namespace Assignment {

struct Person;
struct PersonBuilder;

struct Group;
struct GroupBuilder;

struct Client;
struct ClientBuilder;

enum Genders : int8_t {
  Genders_Male = 0,
  Genders_Female = 1,
  Genders_MIN = Genders_Male,
  Genders_MAX = Genders_Female
};

inline const Genders (&EnumValuesGenders())[2] {
  static const Genders values[] = {
    Genders_Male,
    Genders_Female
  };
  return values;
}

inline const char * const *EnumNamesGenders() {
  static const char * const names[3] = {
    "Male",
    "Female",
    nullptr
  };
  return names;
}

inline const char *EnumNameGenders(Genders e) {
  if (flatbuffers::IsOutRange(e, Genders_Male, Genders_Female)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesGenders()[index];
}

enum PersonOrGroup : uint8_t {
  PersonOrGroup_NONE = 0,
  PersonOrGroup_Person = 1,
  PersonOrGroup_Group = 2,
  PersonOrGroup_MIN = PersonOrGroup_NONE,
  PersonOrGroup_MAX = PersonOrGroup_Group
};

inline const PersonOrGroup (&EnumValuesPersonOrGroup())[3] {
  static const PersonOrGroup values[] = {
    PersonOrGroup_NONE,
    PersonOrGroup_Person,
    PersonOrGroup_Group
  };
  return values;
}

inline const char * const *EnumNamesPersonOrGroup() {
  static const char * const names[4] = {
    "NONE",
    "Person",
    "Group",
    nullptr
  };
  return names;
}

inline const char *EnumNamePersonOrGroup(PersonOrGroup e) {
  if (flatbuffers::IsOutRange(e, PersonOrGroup_NONE, PersonOrGroup_Group)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesPersonOrGroup()[index];
}

template<typename T> struct PersonOrGroupTraits {
  static const PersonOrGroup enum_value = PersonOrGroup_NONE;
};

template<> struct PersonOrGroupTraits<Assignment::Person> {
  static const PersonOrGroup enum_value = PersonOrGroup_Person;
};

template<> struct PersonOrGroupTraits<Assignment::Group> {
  static const PersonOrGroup enum_value = PersonOrGroup_Group;
};

bool VerifyPersonOrGroup(flatbuffers::Verifier &verifier, const void *obj, PersonOrGroup type);
bool VerifyPersonOrGroupVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Person FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_AGE = 6,
    VT_WEIGHT = 8,
    VT_GENDER = 10
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  uint8_t age() const {
    return GetField<uint8_t>(VT_AGE, 0);
  }
  float weight() const {
    return GetField<float>(VT_WEIGHT, 0.0f);
  }
  Assignment::Genders gender() const {
    return static_cast<Assignment::Genders>(GetField<int8_t>(VT_GENDER, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint8_t>(verifier, VT_AGE, 1) &&
           VerifyField<float>(verifier, VT_WEIGHT, 4) &&
           VerifyField<int8_t>(verifier, VT_GENDER, 1) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Person::VT_NAME, name);
  }
  void add_age(uint8_t age) {
    fbb_.AddElement<uint8_t>(Person::VT_AGE, age, 0);
  }
  void add_weight(float weight) {
    fbb_.AddElement<float>(Person::VT_WEIGHT, weight, 0.0f);
  }
  void add_gender(Assignment::Genders gender) {
    fbb_.AddElement<int8_t>(Person::VT_GENDER, static_cast<int8_t>(gender), 0);
  }
  explicit PersonBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline flatbuffers::Offset<Person> CreatePerson(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    uint8_t age = 0,
    float weight = 0.0f,
    Assignment::Genders gender = Assignment::Genders_Male) {
  PersonBuilder builder_(_fbb);
  builder_.add_weight(weight);
  builder_.add_name(name);
  builder_.add_gender(gender);
  builder_.add_age(age);
  return builder_.Finish();
}

inline flatbuffers::Offset<Person> CreatePersonDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    uint8_t age = 0,
    float weight = 0.0f,
    Assignment::Genders gender = Assignment::Genders_Male) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return Assignment::CreatePerson(
      _fbb,
      name__,
      age,
      weight,
      gender);
}

struct Group FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GroupBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GROUP_NAME = 4,
    VT_AVG_AGE = 6,
    VT_AVG_WEIGHT = 8,
    VT_NAME_LIST = 10
  };
  const flatbuffers::String *group_name() const {
    return GetPointer<const flatbuffers::String *>(VT_GROUP_NAME);
  }
  float avg_age() const {
    return GetField<float>(VT_AVG_AGE, 0.0f);
  }
  float avg_weight() const {
    return GetField<float>(VT_AVG_WEIGHT, 0.0f);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *name_list() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_NAME_LIST);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GROUP_NAME) &&
           verifier.VerifyString(group_name()) &&
           VerifyField<float>(verifier, VT_AVG_AGE, 4) &&
           VerifyField<float>(verifier, VT_AVG_WEIGHT, 4) &&
           VerifyOffset(verifier, VT_NAME_LIST) &&
           verifier.VerifyVector(name_list()) &&
           verifier.VerifyVectorOfStrings(name_list()) &&
           verifier.EndTable();
  }
};

struct GroupBuilder {
  typedef Group Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_group_name(flatbuffers::Offset<flatbuffers::String> group_name) {
    fbb_.AddOffset(Group::VT_GROUP_NAME, group_name);
  }
  void add_avg_age(float avg_age) {
    fbb_.AddElement<float>(Group::VT_AVG_AGE, avg_age, 0.0f);
  }
  void add_avg_weight(float avg_weight) {
    fbb_.AddElement<float>(Group::VT_AVG_WEIGHT, avg_weight, 0.0f);
  }
  void add_name_list(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> name_list) {
    fbb_.AddOffset(Group::VT_NAME_LIST, name_list);
  }
  explicit GroupBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Group> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Group>(end);
    return o;
  }
};

inline flatbuffers::Offset<Group> CreateGroup(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> group_name = 0,
    float avg_age = 0.0f,
    float avg_weight = 0.0f,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> name_list = 0) {
  GroupBuilder builder_(_fbb);
  builder_.add_name_list(name_list);
  builder_.add_avg_weight(avg_weight);
  builder_.add_avg_age(avg_age);
  builder_.add_group_name(group_name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Group> CreateGroupDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *group_name = nullptr,
    float avg_age = 0.0f,
    float avg_weight = 0.0f,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *name_list = nullptr) {
  auto group_name__ = group_name ? _fbb.CreateString(group_name) : 0;
  auto name_list__ = name_list ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*name_list) : 0;
  return Assignment::CreateGroup(
      _fbb,
      group_name__,
      avg_age,
      avg_weight,
      name_list__);
}

struct Client FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ClientBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT_TYPE = 4,
    VT_CLIENT = 6
  };
  Assignment::PersonOrGroup client_type() const {
    return static_cast<Assignment::PersonOrGroup>(GetField<uint8_t>(VT_CLIENT_TYPE, 0));
  }
  const void *client() const {
    return GetPointer<const void *>(VT_CLIENT);
  }
  template<typename T> const T *client_as() const;
  const Assignment::Person *client_as_Person() const {
    return client_type() == Assignment::PersonOrGroup_Person ? static_cast<const Assignment::Person *>(client()) : nullptr;
  }
  const Assignment::Group *client_as_Group() const {
    return client_type() == Assignment::PersonOrGroup_Group ? static_cast<const Assignment::Group *>(client()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_CLIENT_TYPE, 1) &&
           VerifyOffset(verifier, VT_CLIENT) &&
           VerifyPersonOrGroup(verifier, client(), client_type()) &&
           verifier.EndTable();
  }
};

template<> inline const Assignment::Person *Client::client_as<Assignment::Person>() const {
  return client_as_Person();
}

template<> inline const Assignment::Group *Client::client_as<Assignment::Group>() const {
  return client_as_Group();
}

struct ClientBuilder {
  typedef Client Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_client_type(Assignment::PersonOrGroup client_type) {
    fbb_.AddElement<uint8_t>(Client::VT_CLIENT_TYPE, static_cast<uint8_t>(client_type), 0);
  }
  void add_client(flatbuffers::Offset<void> client) {
    fbb_.AddOffset(Client::VT_CLIENT, client);
  }
  explicit ClientBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Client> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Client>(end);
    return o;
  }
};

inline flatbuffers::Offset<Client> CreateClient(
    flatbuffers::FlatBufferBuilder &_fbb,
    Assignment::PersonOrGroup client_type = Assignment::PersonOrGroup_NONE,
    flatbuffers::Offset<void> client = 0) {
  ClientBuilder builder_(_fbb);
  builder_.add_client(client);
  builder_.add_client_type(client_type);
  return builder_.Finish();
}

inline bool VerifyPersonOrGroup(flatbuffers::Verifier &verifier, const void *obj, PersonOrGroup type) {
  switch (type) {
    case PersonOrGroup_NONE: {
      return true;
    }
    case PersonOrGroup_Person: {
      auto ptr = reinterpret_cast<const Assignment::Person *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case PersonOrGroup_Group: {
      auto ptr = reinterpret_cast<const Assignment::Group *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return true;
  }
}

inline bool VerifyPersonOrGroupVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyPersonOrGroup(
        verifier,  values->Get(i), types->GetEnum<PersonOrGroup>(i))) {
      return false;
    }
  }
  return true;
}

inline const Assignment::Client *GetClient(const void *buf) {
  return flatbuffers::GetRoot<Assignment::Client>(buf);
}

inline const Assignment::Client *GetSizePrefixedClient(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Assignment::Client>(buf);
}

inline bool VerifyClientBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Assignment::Client>(nullptr);
}

inline bool VerifySizePrefixedClientBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Assignment::Client>(nullptr);
}

inline void FinishClientBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Assignment::Client> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedClientBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Assignment::Client> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Assignment

#endif  // FLATBUFFERS_GENERATED_CLIENT_ASSIGNMENT_H_
