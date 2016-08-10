/* See LICENSE file for copyright and license details. */

/* alsa sound */
static const char channel[]   = "Master";

/* battery */
static const char batterypath[] = "/sys/class/power_supply/";
static const char batterynow[]  = "energy_now";
static const char batteryfull[] = "energy_full_design";

/* bar update interval in seconds (smallest value = 1) */
static unsigned int update_interval = 1;

/* statusbar
- battery_perc (battery percentage) [argument: battery name(s)]
- cpu_perc (cpu usage in percent) [argument: NULL]
- datetime (date and time) [argument: format]
- disk_free (disk usage in percent) [argument: mountpoint]
- disk_perc (disk usage in percent) [argument: mountpoint]
- disk_total (disk usage in percent) [argument: mountpoint]
- disk_used (disk usage in percent) [argument: mountpoint]
- entropy (available entropy) [argument: NULL]
- gid (gid of current user) [argument: NULL]
- hostname [argument: NULL]
- ip (ip address) [argument: interface]
- ram_free (ram usage in percent) [argument: NULL]
- ram_perc (ram usage in percent) [argument: NULL]
- ram_total (ram usage in percent) [argument: NULL]
- ram_used (ram usage in percent) [argument: NULL]
- temp (temperature in degrees) [argument: temperature file]
- uid (uid of current user) [argument: NULL]
- username (username of current user) [argument: NULL]
- vol_perc (alsa volume and mute status in percent) [argument: soundcard]
- wifi_perc (wifi signal in percent) [argument: wifi card interface name] */
static const struct arg args[] = {
    /* function     format          argument */
    { wifi_perc,    "wifi %4s | ",  "wlp3s0" },
    { battery_perc, "bat %4s | ",   "BAT0" },
    { cpu_perc,     "cpu %4s ",     NULL },
    { temp,         "%3s | ",       "/sys/devices/platform/coretemp.0/hwmon/hwmon2/temp1_input" },
    { ram_perc,     "ram %3s | ",   NULL },
    { vol_perc,     "vol %4s | ",   "default" },
    { disk_perc,    "ssd %3s | ",   "/" },
    { datetime,     "%s",           "%y-%m-%d %H:%M:%S" },
};
