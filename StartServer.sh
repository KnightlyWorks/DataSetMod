#!/bin/bash
# Move this file to your DayZ server root directory
# Build server via SteamCMD: steamcmd +force_install_dir ./DayZServer_native +login YOURLOGIN +app_update 1042420 validate +quit

./DayZServer -config=serverDZ.cfg -port=2302 -profiles=Profiles \
  -mod="@CF;@VPPAdminTools;@DatasetBot" -filePatching
