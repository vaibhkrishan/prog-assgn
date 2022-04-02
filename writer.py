import flatbuffers
import sys
import os.path

import Assignment

import Assignment.Person
import Assignment.Genders
import Assignment.Client
import Assignment.Group
import Assignment.PersonOrGroup

def CreatePerson():
    builder = flatbuffers.Builder(128)

    person_name = builder.CreateString("Ram")

    Assignment.Person.Start(builder)
    Assignment.Person.AddName(builder, person_name)
    Assignment.Person.AddAge(builder, 21)
    Assignment.Person.AddWeight(builder, 76.5)
    Assignment.Person.AddGender(builder, Assignment.Genders.Genders().Male)
    ram = Assignment.Person.End(builder)

    Assignment.Client.Start(builder)
    Assignment.Client.AddClientType(builder, Assignment.PersonOrGroup.PersonOrGroup.Person)
    Assignment.Client.AddClient(builder, ram)
    firstClient = Assignment.Client.End(builder)

    builder.FinishSizePrefixed(firstClient)

    return builder.Output()


def CreateGroup():
    builder = flatbuffers.Builder(128)
    group_name = builder.CreateString("FightClub")

    group_names = [builder.CreateString(name) for name in ["Raghuveer", "Shayam", "Ram"]]

    Assignment.Group.StartNameListVector(builder, 3)
    [builder.PrependSOffsetTRelative(name) for name in group_names]
    group_names_bf = builder.EndVector()

    Assignment.Group.Start(builder)
    Assignment.Group.AddGroupName(builder, group_name)
    Assignment.Group.AddAvgAge(builder, 24.5)
    Assignment.Group.AddAvgWeight(builder, 66)
    Assignment.Group.AddNameList(builder, group_names_bf)
    fightClub = Assignment.Group.End(builder)

    Assignment.Client.Start(builder)
    Assignment.Client.AddClient(builder, fightClub)
    Assignment.Client.AddClientType(builder, Assignment.PersonOrGroup.PersonOrGroup.Group)
    secondClient = Assignment.Client.End(builder)

    builder.FinishSizePrefixed(secondClient)

    return builder.Output()

def main(binPath):
    bufPerson = CreatePerson()
    bufGroup = CreateGroup()

    with open(binPath, "wb") as outFile:
        outFile.write(bufPerson)
        outFile.write(bufGroup)

if __name__ == "__main__":
    binPath = "fb_bytes.bin"
    if len(sys.argv) >= 2:
        binPath = sys.argv[1]

    main(binPath)

