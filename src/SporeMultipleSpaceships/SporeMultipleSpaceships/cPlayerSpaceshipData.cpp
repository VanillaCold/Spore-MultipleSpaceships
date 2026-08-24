#include "stdafx.h"
#include "cPlayerSpaceshipData.h"
#include <Spore/Simulator/Serialization.h>
 

const char* cPlayerSpaceshipData::GetName() {
    return "VanillaCold::cPlayerSpaceshipData";
}

cPlayerSpaceshipData::cPlayerSpaceshipData()
{
    mbActive = false;
    mPosition = nullptr;
    mHealth = 0;
    mEnergy = 0;
}

bool cPlayerSpaceshipData::Write(Simulator::ISerializerStream* stream)
{
    return Simulator::ClassSerializer(this, ATTRIBUTES).Write(stream);
}

bool cPlayerSpaceshipData::Read(Simulator::ISerializerStream* stream)
{
    return Simulator::ClassSerializer(this, ATTRIBUTES).Read(stream);
}


bool cPlayerSpaceshipData::ISimulatorSerializable_func18h()
{
    return true;
}

bool cPlayerSpaceshipData::WriteToXML(Simulator::XmlSerializer* writexml)
{
    return writexml->AttributesToXml(ATTRIBUTES, this, GetName());
}

uint32_t cPlayerSpaceshipData::GetNounID() const
{
    return NOUN_ID;
}


//bool mbActive;
//cStarRecordPtr mPosition;
//vector<cSpaceInventoryItemPtr> mCargoItems;
//float mHealth;
//float mEnergy;


Simulator::Attribute cPlayerSpaceshipData::ATTRIBUTES[] = {
    // Add more attributes here
    // This one must always be at the end
    //SimAttribute(cPlayerSpaceshipData,Selection,1),
    SimAttribute(cPlayerSpaceshipData, mbActive, 1),
    SimAttribute(cPlayerSpaceshipData, mPosition, 2),
    SimAttribute(cPlayerSpaceshipData, mCargoItems, 3),
    SimAttribute(cPlayerSpaceshipData, mHealth, 4),
    SimAttribute(cPlayerSpaceshipData, mEnergy, 5),
    Simulator::Attribute()
};



// For internal use, do not modify.
int cPlayerSpaceshipData::AddRef()
{
    return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int cPlayerSpaceshipData::Release()
{
    return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* cPlayerSpaceshipData::Cast(uint32_t type) const
{
    CLASS_CAST(Object);
    CLASS_CAST(cPlayerSpaceshipData);
    return nullptr;
}
