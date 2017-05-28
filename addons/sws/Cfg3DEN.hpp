class ctrlDefault;
class ctrlDefaultText: ctrlDefault {};
class ctrlStatic: ctrlDefaultText {};
class ctrlCombo: ctrlDefaultText {
	class ComboScrollBar;
};
class ctrlControlsGroup: ctrlDefault {};
class ctrlControlsGroupNoScrollbars: ctrlControlsGroup {};

class Cfg3DEN
{
	class Attributes
	{
		
		class Default: ctrlControlsGroupNoScrollbars {};
		class Title: Default
		{
			class Controls
			{
				class Title: ctrlStatic {};
			};
		};
		class Combo: Title
		{
			class Controls: Controls
			{
				class Title: Title {};
				class Value: ctrlCombo {};
			};
		};

		class ReviveUnconsciousStateMode: Combo
		{
			class Controls: Controls
			{
				class Title;
				class Value: Value
				{
					class Items
					{
						class Basic;
						class Advanced;
						class Realistic;
						class SWS
						{
							text = "SWS";
							tooltip = "Simple Wounding System";
							value = 3;
						};
					};
				};
			};
		};
	};
};