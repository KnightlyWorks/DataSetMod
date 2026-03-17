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
        dir = "@Dataset";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Dataset";
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
                files[] = {"@Dataset/scripts/5_mission"};
            };
        };
    };
};
