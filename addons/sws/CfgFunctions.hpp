class cfgFunctions {
    class ADDON {
        class COMPONENT {
            file = QPATHTO_FOLDER(functions);
            class SWSInit {
                  postInit = 1;
            };
            class SetDowned {};
            class WoundedEffect {};
            class HasWounded {};
            class EjectWounded {};
            class OnDrag {};
            class LifeTick {};
            class OnDeath {};
            class OnHeal {};
            class OnDamage {};
            class SetBleeding {};
            class GetAnimation {};
        };
    };
    class A3_Mark
    {
        class Revive
        {
            class reviveInit
            {
                postInit = 0;
            };
            
        };
    };
};
