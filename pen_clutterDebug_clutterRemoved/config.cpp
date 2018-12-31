class CfgPatches
{
	class pen_clutterDebug_clutterRemoved
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredaddons[] = {"pen_clutterDebug"};
	};
};

class CfgSurfaces 
{
	class GdtAsphalt;
	class pen_clutterDebug_mlod: GdtAsphalt
	{	
		character = "Empty";
	};
	class pen_clutterDebug_odol: GdtAsphalt
	{	
		character = "Empty";
	};
	class pen_clutterDebug_large_mlod: GdtAsphalt
	{	
		character = "Empty";
	};
	class pen_clutterDebug_large_odol: GdtAsphalt
	{	
		character = "Empty";
	};
};