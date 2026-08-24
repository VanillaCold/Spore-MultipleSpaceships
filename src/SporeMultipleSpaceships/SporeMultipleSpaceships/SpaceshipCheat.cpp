#include "stdafx.h"
#include "SpaceshipCheat.h"
#include "MultiSpaceshipManager.h"

SpaceshipCheat::SpaceshipCheat()
{
}


SpaceshipCheat::~SpaceshipCheat()
{
}


void SpaceshipCheat::ParseLine(const ArgScript::Line& line)
{
    // This method is called when your cheat is invoked.
    // Put your cheat code here.
    App::ConsolePrintF("%x", MultiSpaceshipManager.GetActiveSpaceship());
    if (MultiSpaceshipManager.GetSpaceshipCount() == 0)
    {

        App::ConsolePrintF("this should appear once, mew");
        MultiSpaceshipManager.SwitchSpaceship(MultiSpaceshipManager.CreateSpaceship());
    }

    else
    {
        if (MultiSpaceshipManager.GetActiveSpaceship() == 0)
        {
            App::ConsolePrintF("switch to 1");
            MultiSpaceshipManager.SwitchSpaceship(1);
        }
        else
        {
            App::ConsolePrintF("switch to 0");
            MultiSpaceshipManager.SwitchSpaceship(0);
        }
    }
    App::ConsolePrintF("nyaaa2");
}

const char* SpaceshipCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
    if (mode == ArgScript::DescriptionMode::Basic) {
        return "This cheat does something.";
    }
    else {
        return "SpaceshipCheat: Elaborate description of what this cheat does.";
    }
}
