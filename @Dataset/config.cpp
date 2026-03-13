class CfgPatches
{
    class DatasetBot
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
};

class CfgMods
{
    class DatasetBot
    {
        dir = "@DatasetBot";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "DatasetBot";
        credits = "";
        author = "";
        authorID = "";
        version = "1.0";
        extra = 0;
        type = "mod";

        dependencies[] = {"Game", "World", "Mission"};

        class defs
        {
            class missionScriptModule
            {
                value = "";
                files[] = {"@DatasetBot/scripts/5_mission"};
            };
        };
    };
};
