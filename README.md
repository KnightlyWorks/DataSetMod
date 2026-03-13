# Dataset Mod for DayZ

This mod serves as the server-side component for an automated data collection system designed for neural network projects. It provides a non-invasive way to control player positioning via text files, facilitating geospatial analysis and AI navigation training.

## Disclaimer
>DayZ, Chernarus, ArmA, Bohemia Interactive and all related assets, trademarks, map data, game content, character models, and intellectual property are the sole property of [Bohemia Interactive](https://www.bohemia.net/). This project is not affiliated with, endorsed by, or sponsored by Bohemia Interactive in any way. This tool is intended for personal, non-commercial use only.

## Technical Overview
* **No Memory Injection:** This tool does not interact with the game's executable process, memory, or network traffic.
* **Autonomy:** The system uses the official `Enforce Script` API, ensuring full compatibility with the DayZ engine without unauthorized modifications.

## Installation
1. Place the `@Dataset` folder into your DayZ server root directory.
2. Ensure your server launch parameters include the `-filePatching` flag, which is required to load mods without packing them into PBO files.
3. Include `@Dataset` in your startup command line, for example:
   `./DayZServer -config=serverDZ.cfg -port=2302 -profiles=Profiles -mod="@CF;@VPPAdminTools;@Dataset" -filePatching`

## Usage
The system monitors the `$profile:dayz_tp.txt` file for teleport commands.
* **Input Format:** `x,z,yaw` (e.g., `5000.5, 6000.0, 90.0`)
* **Confirmation:** Once the teleport is executed, the mod creates a `$profile:dayz_tp_done.txt` file containing "ok".
* **Requirement:** Teleportation requires at least one active player to be present on the server.

## Related Projects
* [StreetViewInGame](https://github.com/KnightlyWorks/StreetViewInGame) — Python dataset collection and localization system that uses this mod.

## License
This content is released under the **DayZ Public License - No Derivatives (DPL-ND)**. 
You can view the full, legally binding text of the license here: [DAYZ_PUBLIC_LICENSE_ND.pdf](./DAYZ_PUBLIC_LICENSE_ND.pdf).


