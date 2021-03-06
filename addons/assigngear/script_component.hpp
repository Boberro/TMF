#define COMPONENT assignGear

#include "\x\tmf\addons\main\script_mod.hpp"
#include "\x\tmf\addons\main\script_macros.hpp"

#define CURUNIT (call CBA_fnc_currentUnit)

/* RscGearSelector*/
#define IDD_RSCGEARSELECTOR             832400
#define IDC_RSCGEARSELECTOR_CATEGORY    832401
#define IDC_RSCGEARSELECTOR_FACTION     832402
#define IDC_RSCGEARSELECTOR_ROLE        832403
#define IDC_RSCGEARSELECTOR_SUBMIT      832404
#define IDC_RSCGEARSELECTOR_RANDOM      832405

/* RscAttributeLoadout */
#define IDC_RSCATTRIBUTELOADOUT_TITLE       833400
#define IDC_RSCATTRIBUTELOADOUT_COMBO       833401
#define IDC_RSCATTRIBUTELOADOUT_RSCATTRIBUTELOADOUT 833402

/* RscAttributeFaction */
#define IDC_RSCATTRIBUTEFACTION_TITLE       834400
#define IDC_RSCATTRIBUTEFACTION_COMBO       834401
#define IDC_RSCATTRIBUTEFACTION_RSCATTRIBUTEFACTION 834402

/* RscAttributeRetroactive */
#define IDC_RSCATTRIBUTERETROACTIVE_TITLE       835400
#define IDC_RSCATTRIBUTERETROACTIVE_BCG         835401
#define IDC_RSCATTRIBUTERETROACTIVE_TOOLBOX     835402
#define IDC_RSCATTRIBUTERETROACTIVE_RSCATTRIBUTERETROACTIVE 835403

/* AssignGear Vehicle */
#define IDC_VEHICLEGEAR_CATEGORY 666434
#define IDC_VEHICLEGEAR_FACTION 666343
#define IDC_VEHICLEGEAR_FILTER 666964
#define IDC_VEHICLEGEAR_LIST 666344
#define IDC_VEHICLEGEAR_CLEAR 666656
#define IDC_VEHICLEGEAR_ADD 666777
#define IDC_VEHICLEGEAR_SUBTRACT 666888

/* assignGear specific macros */
#define GETGEAR(var) [_cfg >> var] call CFUNC(getCfgEntryFromPath)
#define LIST_2(var1) var1,var1
#define LIST_3(var1) var1,var1,var1
#define LIST_4(var1) var1,var1,var1,var1
#define LIST_5(var1) var1,var1,var1,var1,var1
#define LIST_6(var1) var1,var1,var1,var1,var1,var1
#define LIST_7(var1) var1,var1,var1,var1,var1,var1,var1
#define LIST_8(var1) var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_9(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_10(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_11(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_12(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_13(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_14(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_15(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_16(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_17(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_18(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_19(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1
#define LIST_20(var1) var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1,var1

#define DEF_LOADOUTS ["baseMan","r","g","car","m","smg","ftl","sl","co","fac","ar","aar","rat","dm","mmgg","mmgac","mmgag","hmgg","hmgac","matg","matac","matag","hatg","hatac","hatag","mtrg","mtrac","mtrag","samg","samag","sn","sp","vc","vd","vg","pp","pcc","pc","eng","engm","UAV","jp"]

/* assignGear cache indexes */
#define IDX_DISPLAY_NAME 0
#define IDX_UNIFORM 1
#define IDX_VEST 2
#define IDX_BACKPACK 3
#define IDX_HEADGEAR 4
#define IDX_GOGGLES 5
#define IDX_HMD 6
#define IDX_FACES 7
#define IDX_INSIGNIAS 8
#define IDX_BACKPACK_ITEMS 9
#define IDX_ITEMS 10
#define IDX_MAGAZINES 11
#define IDX_LINKED_ITEMS 12
#define IDX_PRIMARY_WEAPON 13
#define IDX_SCOPE 14
#define IDX_BIPOD 15
#define IDX_ATTACHMENT 16
#define IDX_SILENCER 17
#define IDX_SECONDARY_WEAPON 18
#define IDX_SECONDARY_ATTACHMENTS 19
#define IDX_SIDEARM_WEAPON 20
#define IDX_SIDEARM_ATTACHMENTS 21
#define IDX_TRAITS 22
#define IDX_PRIMARY_MAGAZINE 23
#define IDX_PRIMARY_GRENADE 24
#define IDX_SECONDARY_MAGAZINE 25
#define IDX_SIDEARM_MAGAZINE 26
#define IDX_CODE 27

#define FILTER_WEAPON 0
#define FILTER_GEAR 1
#define FILTER_ITEMS 2
