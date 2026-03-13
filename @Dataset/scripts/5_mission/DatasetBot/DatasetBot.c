modded class MissionServer
{
    static string TP_FILE  = "$profile:dayz_tp.txt";
    static string TP_DONE  = "$profile:dayz_tp_done.txt";

    override void OnInit()
    {
        super.OnInit();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.CheckTeleportFile, 100, true);
        Print("[DatasetBot] Запущен");
    }

    void CheckTeleportFile()
    {
        if (!FileExist(TP_FILE))
            return;

        FileHandle fh = OpenFile(TP_FILE, FileMode.READ);
        if (fh == 0)
            return;

        string line;
        FGets(fh, line);
        CloseFile(fh);

        // Очищаем файл
        FileHandle fhw = OpenFile(TP_FILE, FileMode.WRITE);
        if (fhw != 0) CloseFile(fhw);

        line.TrimInPlace();

        autoptr TStringArray parts = new TStringArray;
        line.Split(",", parts);

        if (parts.Count() < 2)
        {
            Print("[DatasetBot] Неверный формат: " + line);
            return;
        }

        float tx   = parts.Get(0).ToFloat();
        float tz   = parts.Get(1).ToFloat();
        float tyaw = 0.0;
        if (parts.Count() >= 3)
            tyaw = parts.Get(2).ToFloat();
        float ty   = GetGame().SurfaceY(tx, tz) + 1.5;

        autoptr array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);

        if (players.Count() == 0)
        {
            Print("[DatasetBot] Нет игроков!");
            return;
        }

        Man player = players.Get(0);
        player.SetPosition(Vector(tx, ty, tz));
        player.SetOrientation(Vector(tyaw, 0, 0));

        Print("[DatasetBot] ТП → " + tx + " " + ty + " " + tz + " YAW → " + tyaw);

        FileHandle fd = OpenFile(TP_DONE, FileMode.WRITE);
        if (fd != 0)
        {
            FPrint(fd, "ok");
            CloseFile(fd);
        }
    }
}
