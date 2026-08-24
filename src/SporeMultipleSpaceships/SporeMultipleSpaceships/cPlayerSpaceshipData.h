#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Simulator\ISimulatorSerializable.h>

#define cPlayerSpaceshipDataPtr intrusive_ptr<cPlayerSpaceshipData>

class cPlayerSpaceshipData
: public Simulator::ISimulatorSerializable
, public DefaultRefCounted
{




    virtual bool Write(Simulator::ISerializerStream* stream) override;
    virtual bool Read(Simulator::ISerializerStream* stream) override;
    virtual bool ISimulatorSerializable_func18h() override;
    virtual bool WriteToXML( Simulator::XmlSerializer* writexml) override;
    virtual uint32_t GetNounID() const override;


    static Simulator::Attribute ATTRIBUTES[];
public:
    static const uint32_t TYPE = id("VanillaCold::cPlayerSpaceshipData");
    static const uint32_t NOUN_ID = TYPE;
    static const char* GetName();

    cPlayerSpaceshipData();

    bool mbActive;
    cStarRecordPtr mPosition;
    vector<cSpaceInventoryItemPtr> mCargoItems;
    float mHealth;
    float mEnergy;

    int AddRef() override;
    int Release() override;
    void* Cast(uint32_t type) const override;
};
