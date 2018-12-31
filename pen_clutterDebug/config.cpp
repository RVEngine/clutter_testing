class CfgPatches
{
	class pen_clutterDebug
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredaddons[] = {"A3_Map_Stratis", "A3_Map_Tanoabuka", "pen_clutterDebug_models"};
	};
};
class CfgWorlds
{
	class CAWorld;
	class Stratis: CAWorld
	{
		class Grid;
		class DefaultClutter;
	};
	class pen_clutterDebug: Stratis
	{
		clutterGrid = 0.7;
		clutterDistance = 195;
		noDetailDist = 65;
		fullDetailDist = 10;
		clutterRoadwayCheckRadiusCoef = 0.2;
		maxClutterColoringCoef = "1.35f";
		interpolateClutterColoring = 1;
		clutterColoringFarCoef = 15.0;
		clutterColoringFarStart = 20.0;
		clutterColoringFarSpeed = 1.0;
		cutscenes[] = {};
		author = "Pennyworth";
		description = "Clutter Debug Map";
		pictureMap = ""; 
		worldName = "pen_clutterDebug\pen_clutterDebug.wrp";
		startTime = "11:00";
		startDate = "05/03/2001";
		startWeather = 0.2;
		startFog = 0.0;
		forecastWeather = 0.6;
		forecastFog = 0.0;
		centerPosition[] = {1024,1024,500};
		seagullPos[] = {1024,1024,500};
		longitude = 65;
		latitude = -34;
		elevationOffset = 5;
		envTexture = "A3\Data_f\env_land_ca.tga";
		minTreesInForestSquare = 2;
		minRocksInRockSquare = 2;
		newRoadsShape = "";
		ilsPosition[] = {1024,1024};
		ilsDirection[] = {0.5075,0.08,-0.8616};
		ilsTaxiIn[] = {};
		ilsTaxiOff[] = {};
		drawTaxiway = 0;
		class SecondaryAirports {};
		class Sea
		{
			seaTexture = "a3\data_f\seatexture_co.paa";
			seaMaterial = "#water";
			shoreMaterial = "#shore";
			shoreFoamMaterial = "#shorefoam";
			shoreWetMaterial = "#shorewet";
			WaterMapScale = 20;
			WaterGrid = 50;
			MaxTide = 0;
			MaxWave = 0;
			SeaWaveXScale = "2.0/50";
			SeaWaveZScale = "1.0/50";
			SeaWaveHScale = 2.0;
			SeaWaveXDuration = 5000;
			SeaWaveZDuration = 10000;
		};
		class Grid: Grid
		{
			offsetX = 0;
			offsetY = 1024;
			class Zoom1
			{
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom2
			{
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
			class Zoom3
			{
				zoomMax = 1e+030.0;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = -10000;
			};
		};
		class Names {};
		class Clutter	
		{
			class pen_clutterDebug_mlod_clutter: DefaultClutter
			{
				model = "pen_clutterDebug_models\pen_clutterDebug_mlod.p3d";
				affectedByWind = 0.0;
				swLighting = 0;
				scaleMin = 0.7;
				scaleMax = 1.3;
			};
			class pen_clutterDebug_odol_clutter: DefaultClutter
			{
				model = "pen_clutterDebug_models\pen_clutterDebug_odol.p3d";
				affectedByWind = 0.0;
				swLighting = 0;
				scaleMin = 0.7;
				scaleMax = 1.3;
			};
			class pen_clutterDebug_large_mlod_clutter: DefaultClutter
			{
				model = "pen_clutterDebug_models\pen_clutterDebug_large_mlod.p3d";
				affectedByWind = 0.0;
				swLighting = 0;
				scaleMin = 0.7;
				scaleMax = 1.3;
			};
			class pen_clutterDebug_large_odol_clutter: DefaultClutter
			{
				model = "pen_clutterDebug_models\pen_clutterDebug_large_odol.p3d";
				affectedByWind = 0.0;
				swLighting = 0;
				scaleMin = 0.7;
				scaleMax = 1.3;
			};
		};
	};
};
class CfgWorldList
{
	class pen_clutterDebug{};
};

class CfgSurfaces 
{
	class GdtAsphalt;
	class pen_clutterDebug_mlod: GdtAsphalt
	{	
		files = "pen_clutterdebug_mlod_*";
		character = "pen_clutterdebug_mlod_character";
		grassCover = 0.4;
	};
	class pen_clutterDebug_odol: GdtAsphalt
	{	
		files = "pen_clutterdebug_odol_*";
		character = "pen_clutterdebug_odol_character";
	};
	class pen_clutterDebug_large_mlod: GdtAsphalt
	{	
		files = "pen_clutterdebug_large_mlod_*";
		character = "pen_clutterdebug_large_mlod_character";
	};
	class pen_clutterDebug_large_odol: GdtAsphalt
	{	
		files = "pen_clutterdebug_large_odol_*";
		character = "pen_clutterdebug_large_odol_character";
	};
	class pen_clutterDebug_empty: GdtAsphalt
	{	
		files = "pen_clutterdebug_empty_*";
		character = "Empty";
	};
};

class CfgSurfaceCharacters
{
	class pen_clutterdebug_mlod_character
	{
		probability[] = {0.5};
		names[] = {"pen_clutterDebug_mlod_clutter"};
	};
	class pen_clutterdebug_odol_character
	{
		probability[] = {0.5};
		names[] = {"pen_clutterDebug_odol_clutter"};
	};
	class pen_clutterdebug_large_mlod_character
	{
		probability[] = {0.5};
		names[] = {"pen_clutterDebug_large_mlod_clutter"};
	};
	class pen_clutterdebug_large_odol_character
	{
		probability[] = {0.5};
		names[] = {"pen_clutterDebug_large_odol_clutter"};
	};
};