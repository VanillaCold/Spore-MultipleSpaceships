#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Simulator\Serialization.h>
#include <Spore/Simulator/cSpaceInventory.h>
#include <Spore/Simulator/SubSystem/SpaceTrading.h>
#include <vector>
#include <set>

#define MultiSpaceshipManagerPtr intrusive_ptr<MultiSpaceshipManager>

///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new MultiSpaceshipManager(), MultiSpaceshipManager::NOUN_ID);
///

struct PlayerSpaceshipData
{
    bool mbActive;
    cStarRecordPtr mPosition;
    vector<cSpaceInventoryItemPtr> mCargoItems;
    float mHealth;
    float mEnergy;

    PlayerSpaceshipData()
    {
        mbActive = false;
        mPosition = nullptr;
        mHealth = 0;
        mEnergy = 0;
    }
};

class MultiSpaceshipManager
: public Simulator::cStrategy
{
    vector<PlayerSpaceshipData> mStoredSpaceships;
    int mCurrentIndex;
public:
    static const uint32_t TYPE = id("MultiSpaceshipManager");
    static const uint32_t NOUN_ID = TYPE;

    int AddRef() override;
    int Release() override;
    void Initialize() override;
    void Dispose() override;
    const char* GetName() const override;
    virtual bool Write(Simulator::ISerializerStream* stream) override;
    virtual bool Read(Simulator::ISerializerStream* stream) override;
    void Update(int deltaTime, int deltaGameTime) override;
    virtual bool WriteToXML( Simulator::XmlSerializer* writexml);
    virtual void OnModeEntered(uint32_t previousModeID,
                               uint32_t newModeID) override;

    bool SwitchSpaceship(int _index);
    int CreateSpaceship();
    bool DestroySpaceship(bool _keepCargo);

    //
    // You can add more methods here
    //
     static MultiSpaceshipManager* Get();
     static Simulator::Attribute ATTRIBUTES[];

private:
    static MultiSpaceshipManager* sInstance;
    //
    // You can add members here
    //
};
