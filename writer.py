import flatbuffers
import sys
import os.path

import Assignment

import Assignment.Person
import Assignment.Genders
import Assignment.Client
import Assignment.Group
import Assignment.PersonOrGroup

binPath = "fb_bytes.bin"
if len(sys.argv) >= 2:
    binPath = sys.argv[1]

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

builder2 = flatbuffers.Builder(128)
group_name = builder2.CreateString("FightClub")

group_names = [builder2.CreateString(name) for name in ["Raghuveer", "Shayam", "Ram"]]

Assignment.Group.StartNameListVector(builder2, 3)
[builder2.PrependSOffsetTRelative(name) for name in group_names]
group_names_bf = builder2.EndVector()

Assignment.Group.Start(builder2)
Assignment.Group.AddGroupName(builder2, group_name)
Assignment.Group.AddAvgAge(builder2, 24.5)
Assignment.Group.AddAvgWeight(builder2, 66)
Assignment.Group.AddNameList(builder2, group_names_bf)
fightClub = Assignment.Group.End(builder2)

Assignment.Client.Start(builder2)
Assignment.Client.AddClient(builder2, fightClub)
Assignment.Client.AddClientType(builder2, Assignment.PersonOrGroup.PersonOrGroup.Group)
secondClient = Assignment.Client.End(builder2)
builder2.FinishSizePrefixed(secondClient)

buf = builder.Output()
buf2 = builder2.Output()

with open(binPath, "wb") as outFile:
    outFile.write(buf)
    outFile.write(buf2)

