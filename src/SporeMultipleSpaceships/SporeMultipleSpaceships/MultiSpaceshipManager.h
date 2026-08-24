#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Simulator\Serialization.h>
#include <Spore/Simulator/cSpaceInventory.h>
#include <Spore/Simulator/SubSystem/SpaceTrading.h>
#include "cPlayerSpaceshipData.h"
#include <vector>
#include <set>

#define cMultiSpaceshipManagerPtr intrusive_ptr<cMultiSpaceshipManager>

#define MultiSpaceshipManager (cMultiSpaceshipManager::Get())[0]

///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new MultiSpaceshipManager(), MultiSpaceshipManager::NOUN_ID);
///





class cMultiSpaceshipManager
: public Simulator::cStrategy
{
public:
    static const uint32_t TYPE = id("VanillaCold::MultiSpaceshipManager");
    static const uint32_t NOUN_ID = TYPE;

    int AddRef() override;
    int Release() override;
    void Initialize() override;
    void Dispose() override;
    const char* GetName() const override;
    virtual bool Write(Simulator::ISerializerStream* stream) override;
    virtual bool Read(Simulator::ISerializerStream* stream) override;
    void Update(int deltaTime, int deltaGameTime) override;
    virtual bool WriteToXML( Simulator::XmlSerializer* writexml) override;
    virtual void OnModeEntered(uint32_t previousModeID,
                               uint32_t newModeID) override;

    bool SwitchSpaceship(int _index);
    uint32_t CreateSpaceship();
    bool DestroySpaceship(bool _keepCargo);
    uint32_t GetSpaceshipCount();
    uint32_t GetActiveSpaceship();

    static Simulator::Attribute ATTRIBUTES[];
    static cMultiSpaceshipManager* Get();

    int mCurrentIndex;
    vector<cPlayerSpaceshipDataPtr> mStoredSpaceships;
    //
    // You can add more methods here
    //

private:
    static cMultiSpaceshipManager* sInstance;
    //
    // You can add members here
    //
};
