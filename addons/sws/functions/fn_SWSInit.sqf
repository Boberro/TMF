#include "defines.inc"
systemChat "fn_SWSInit.sqf";
// F3 - SimpleWoundingSystem
// Credits: Please see the F3 online manual (http://www.ferstaberinde.com/f3/en/)
// ====================================================================================

//load 'mode' but prioritize the server param
private _paramMode = missionNamespace getVariable["bis_reviveParam_mode",-100];
private _mode = if (_paramMode == -100) then {getMissionConfigValue ["ReviveMode",REVIVE_MODE_DISABLED]} else {_paramMode};
if (!IS_MP || {_mode == REVIVE_MODE_DISABLED}) exitWith {};
// if (!REVIVE_ENABLED(player)) exitWith {};

// We're only interested in SWS mode here
systemChat "trying to start SWS...";
bis_revive_unconsciousStateMode = if ((missionNamespace getVariable["bis_reviveParam_unconsciousStateMode",-100]) == -100) then {getMissionConfigValue ["ReviveUnconsciousStateMode",0]} else {missionNamespace getVariable["bis_reviveParam_unconsciousStateMode",-100]};
if (bis_revive_unconsciousStateMode != 3) exitWith {};
systemChat "Starting SWS!";

//exit if dedicated server, headless client or spectator detected
if (!hasInterface || {side player == sideLogic}) exitWith {};
//make sure player exists
if (isNull player) then {waitUntil{!isNull player}};
//exit if spectator is detected
if (side player == sideLogic) exitWith {};

sleep 1;

// default variables.
player setVariable ["f_wound_down",false];
player setVariable ["f_wound_bleeding",false];
player setVariable ["f_wound_blood",100]; // other player dont need know this
player setVariable ["f_wound_dragging",nil];
f_wound_healAnimations = ["ainvpknlmstpslaywpstdnon_medic","ainvpknlmstpslaywrfldnon_medic","ainvpknlmstpslaywnondnon_medic","ainvppnemstpslaywnondnon_medic","AinvPpneMstpSlayWnonDnon_medic","AinvPpneMstpSlayWpstDnon_medic","AinvPpneMstpSlayWrflDnon_medic",""];

/// Lifeticker, manages bleeding and blood values.
player spawn tmf_sws_fnc_LifeTick;


// HandleHeal needs to be one the player you heal.
{
	_x setVariable ["f_wound_down",false];
	_x setVariable ["f_wound_bleeding",false];
	_x addEventHandler ["HandleHeal",{_this call tmf_sws_fnc_OnHeal}];
		// Drag Action.
	_addIndex = _x addAction [format ["Drag %1", name _x],{[_this, "tmf_sws_fnc_OnDrag", [_this select 0,_this select 1],false] spawn BIS_fnc_MP;}, nil, 6, false, true, "", "_var = _this getVariable ['f_wound_dragging',nil];_target distance _this < 2 && isNil '_var' && _target getVariable['f_wound_down',false] && !(_this getVariable ['f_wound_down',false])"];
} foreach playableUnits;

// defines the PP effects for the downed effect.
F_UncCC = ppEffectCreate ["ColorCorrections", 1603];
F_UncRadialBlur = ppEffectCreate ["RadialBlur", 280];
F_UncBlur = ppEffectCreate ["DynamicBlur", 180];
F_UncToggle = false;
f_damage_effect = 1.1;

// Eventhandlers for the player.
player addEventHandler ["killed", {_this call tmf_sws_fnc_OnDeath}];
player addEventHandler ["HandleDamage",{_this call tmf_sws_fnc_OnDamage}];
