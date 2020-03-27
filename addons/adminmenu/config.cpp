#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = "TMF: Admin Menu";
        author = "Bear, Snippers";
        url = "http://www.teamonetactical.com";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"tmf_common", "A3_UI_F", "cba_diagnostic"};
        VERSION_CONFIG;
    };
};

GVAR(authorized_uids)[] = {
// SteamID64 of players authorized to access admin tools (matches against getPlayerUID)
    "76561197975964276",
    "76561198002563273",
    "76561198060093093"
};

#include "CfgDebriefing.hpp"
#include "CfgFunctions.hpp"
#include "CfgEventHandlers.hpp"

#include "gui\adminMenu.hpp"
