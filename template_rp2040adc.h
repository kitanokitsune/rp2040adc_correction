/* rp2040 adc correction: Individual C/C++ Code Template */

/*-----------------------------------------------------------------------------------*/
/* Replace the below rp2040adc_err[] with your own data                              */

int8_t rp2040adc_err[] = {
      0, -1, -2, -3, -4, -5, -6, -7, -8, -9,-10,-11,-12,-13,-14,-15,  /*    0 -   15 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*   16 -   31 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*   32 -   47 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*   48 -   63 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*   64 -   79 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*   80 -   95 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*   96 -  111 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  112 -  127 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  128 -  143 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  144 -  159 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  160 -  175 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  176 -  191 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  192 -  207 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  208 -  223 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  224 -  239 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  240 -  255 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  256 -  271 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  272 -  287 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  288 -  303 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  304 -  319 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  320 -  335 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  336 -  351 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  352 -  367 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  368 -  383 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  384 -  399 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  400 -  415 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  416 -  431 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  432 -  447 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  448 -  463 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  464 -  479 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,  /*  480 -  495 */
    -15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-10,  /*  496 -  511 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  512 -  527 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  528 -  543 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  544 -  559 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  560 -  575 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  576 -  591 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  592 -  607 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  608 -  623 */
     -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  /*  624 -  639 */
     -6, -6, -6, -5, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -6,  /*  640 -  655 */
     -6, -6, -6, -5, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -6,  /*  656 -  671 */
     -6, -6, -5, -5, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -6,  /*  672 -  687 */
     -6, -6, -6, -5, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -6,  /*  688 -  703 */
     -6, -6, -6, -6, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -6,  /*  704 -  719 */
     -6, -6, -6, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -5, -5, -6,  /*  720 -  735 */
     -6, -6, -6, -5, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -6,  /*  736 -  751 */
     -6, -6, -5, -5, -5, -5, -5, -6, -6, -6, -6, -6, -5, -5, -5, -5,  /*  752 -  767 */
     -6, -6, -5, -5, -5, -5, -5, -5, -6, -6, -5, -5, -5, -5, -5, -5,  /*  768 -  783 */
     -6, -5, -5, -5, -5, -5, -5, -5, -6, -6, -6, -5, -5, -5, -5, -5,  /*  784 -  799 */
     -6, -5, -5, -5, -5, -5, -5, -5, -6, -6, -5, -5, -5, -5, -5, -5,  /*  800 -  815 */
     -6, -5, -5, -5, -5, -5, -5, -5, -6, -6, -5, -5, -5, -5, -5, -5,  /*  816 -  831 */
     -6, -6, -5, -5, -5, -5, -5, -6, -6, -6, -5, -5, -5, -5, -5, -5,  /*  832 -  847 */
     -6, -6, -5, -5, -5, -5, -5, -6, -6, -6, -6, -5, -5, -5, -5, -5,  /*  848 -  863 */
     -6, -6, -5, -5, -5, -5, -5, -6, -6, -6, -5, -5, -5, -5, -5, -6,  /*  864 -  879 */
     -6, -6, -5, -5, -5, -5, -5, -5, -6, -6, -6, -6, -5, -5, -5, -6,  /*  880 -  895 */
     -6, -6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  896 -  911 */
     -6, -6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  912 -  927 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  928 -  943 */
     -6, -6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  944 -  959 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  960 -  975 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  976 -  991 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /*  992 - 1007 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1008 - 1023 */
     -6, -6, -6, -6, -6, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1024 - 1039 */
     -6, -6, -6, -6, -6, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1040 - 1055 */
     -6, -6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -6, -6, -6, -5, -6,  /* 1056 - 1071 */
     -6, -6, -6, -6, -6, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1072 - 1087 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -6,  /* 1088 - 1103 */
     -6, -6, -6, -6, -6, -6, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1104 - 1119 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -6,  /* 1120 - 1135 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1136 - 1151 */
     -7, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1152 - 1167 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  /* 1168 - 1183 */
     -7, -6, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1184 - 1199 */
     -6, -6, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1200 - 1215 */
     -7, -6, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1216 - 1231 */
     -6, -6, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1232 - 1247 */
     -7, -7, -6, -6, -6, -6, -6, -7, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1248 - 1263 */
     -7, -6, -6, -6, -6, -6, -6, -7, -7, -7, -7, -6, -6, -6, -6, -6,  /* 1264 - 1279 */
     -6, -6, -6, -6, -6, -6, -6, -6, -6, -7, -6, -6, -6, -6, -6, -6,  /* 1280 - 1295 */
     -6, -6, -6, -6, -6, -6, -6, -6, -7, -6, -6, -6, -6, -6, -6, -6,  /* 1296 - 1311 */
     -7, -6, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1312 - 1327 */
     -6, -7, -6, -6, -6, -6, -6, -6, -7, -7, -6, -6, -6, -6, -6, -6,  /* 1328 - 1343 */
     -7, -7, -6, -6, -6, -6, -6, -7, -7, -7, -7, -7, -6, -6, -6, -6,  /* 1344 - 1359 */
     -7, -7, -6, -6, -6, -6, -6, -7, -7, -7, -7, -6, -6, -6, -6, -7,  /* 1360 - 1375 */
     -7, -7, -6, -6, -6, -6, -6, -7, -7, -7, -7, -7, -6, -6, -6, -6,  /* 1376 - 1391 */
     -7, -6, -6, -6, -6, -6, -6, -7, -7, -7, -7, -6, -6, -6, -6, -7,  /* 1392 - 1407 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1408 - 1423 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1424 - 1439 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1440 - 1455 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1456 - 1471 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1472 - 1487 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1488 - 1503 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  /* 1504 - 1519 */
     -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -3,  /* 1520 - 1535 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1536 - 1551 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1552 - 1567 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1568 - 1583 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1584 - 1599 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1600 - 1615 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1616 - 1631 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1632 - 1647 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /* 1648 - 1663 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  2,  2,  2,  1,  /* 1664 - 1679 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  2,  2,  2,  1,  /* 1680 - 1695 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,  /* 1696 - 1711 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  2,  2,  2,  1,  /* 1712 - 1727 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1728 - 1743 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,  /* 1744 - 1759 */
      1,  1,  1,  1,  2,  1,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,  /* 1760 - 1775 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,  /* 1776 - 1791 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  2,  1,  2,  1,  /* 1792 - 1807 */
      1,  1,  2,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  1,  /* 1808 - 1823 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  1,  /* 1824 - 1839 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  1,  /* 1840 - 1855 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,  /* 1856 - 1871 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  2,  1,  /* 1872 - 1887 */
      1,  1,  1,  1,  1,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1888 - 1903 */
      1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1904 - 1919 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1920 - 1935 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1936 - 1951 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1952 - 1967 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1968 - 1983 */
      0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /* 1984 - 1999 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  /* 2000 - 2015 */
      1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  1,  1,  1,  1,  1,  1,  /* 2016 - 2031 */
      1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  0,  0,  /* 2032 - 2047 */
     -1, -1, -1, -1, -1,  0,  0, -1, -1, -1, -1, -1, -1, -1,  0, -1,  /* 2048 - 2063 */
     -1, -1, -1, -1, -1,  0,  0, -1, -1, -1, -1, -1, -1, -1,  0, -1,  /* 2064 - 2079 */
     -1, -1, -1, -1,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* 2080 - 2095 */
     -1, -1, -1, -1, -1,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* 2096 - 2111 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* 2112 - 2127 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* 2128 - 2143 */
     -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* 2144 - 2159 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /* 2160 - 2175 */
     -2, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1,  /* 2176 - 2191 */
     -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1,  /* 2192 - 2207 */
     -2, -1, -1, -1, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1, -1,  /* 2208 - 2223 */
     -2, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -2,  /* 2224 - 2239 */
     -2, -2, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1, -1, -1,  /* 2240 - 2255 */
     -2, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1, -1, -2,  /* 2256 - 2271 */
     -2, -2, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, -2,  /* 2272 - 2287 */
     -2, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, -1,  /* 2288 - 2303 */
     -2, -2, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1,  /* 2304 - 2319 */
     -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, -1, -2,  /* 2320 - 2335 */
     -2, -1, -1, -1, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1, -1,  /* 2336 - 2351 */
     -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -1, -2, -1, -1, -1, -2,  /* 2352 - 2367 */
     -2, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, -2,  /* 2368 - 2383 */
     -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -2, -1, -1, -1, -2,  /* 2384 - 2399 */
     -2, -2, -1, -1, -1, -1, -1, -2, -2, -2, -1, -2, -1, -1, -1, -2,  /* 2400 - 2415 */
     -2, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, -1, -2,  /* 2416 - 2431 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2432 - 2447 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2448 - 2463 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2464 - 2479 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2480 - 2495 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2496 - 2511 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2512 - 2527 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /* 2528 - 2543 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  2,  /* 2544 - 2559 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2560 - 2575 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2576 - 2591 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2592 - 2607 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2608 - 2623 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2624 - 2639 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2640 - 2655 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2656 - 2671 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2672 - 2687 */
      6,  6,  7,  7,  7,  7,  7,  6,  6,  6,  6,  6,  7,  7,  7,  7,  /* 2688 - 2703 */
      7,  6,  7,  7,  7,  7,  7,  6,  6,  6,  7,  7,  7,  7,  7,  7,  /* 2704 - 2719 */
      7,  7,  7,  7,  7,  7,  7,  6,  6,  7,  7,  7,  7,  7,  7,  6,  /* 2720 - 2735 */
      7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  7,  7,  7,  7,  7,  6,  /* 2736 - 2751 */
      6,  7,  7,  7,  7,  7,  7,  6,  6,  6,  6,  6,  7,  7,  7,  6,  /* 2752 - 2767 */
      7,  6,  7,  7,  7,  7,  7,  6,  6,  6,  6,  7,  7,  7,  7,  6,  /* 2768 - 2783 */
      6,  6,  7,  7,  7,  7,  7,  6,  6,  6,  7,  6,  7,  7,  7,  6,  /* 2784 - 2799 */
      6,  6,  7,  6,  7,  7,  7,  6,  6,  6,  7,  6,  7,  7,  7,  7,  /* 2800 - 2815 */
      6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2816 - 2831 */
      7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  7,  7,  7,  7,  7,  /* 2832 - 2847 */
      6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2848 - 2863 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  /* 2864 - 2879 */
      6,  7,  7,  7,  7,  7,  7,  7,  6,  6,  7,  7,  7,  7,  7,  7,  /* 2880 - 2895 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  7,  7,  7,  7,  /* 2896 - 2911 */
      7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  7,  7,  7,  7,  7,  7,  /* 2912 - 2927 */
      7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  6,  7,  7,  7,  6,  /* 2928 - 2943 */
      6,  6,  6,  6,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 2944 - 2959 */
      6,  6,  6,  6,  6,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 2960 - 2975 */
      6,  6,  6,  6,  6,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 2976 - 2991 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 2992 - 3007 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3008 - 3023 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3024 - 3039 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3040 - 3055 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  7,  6,  /* 3056 - 3071 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3072 - 3087 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3088 - 3103 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3104 - 3119 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3120 - 3135 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3136 - 3151 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3152 - 3167 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3168 - 3183 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 3184 - 3199 */
      5,  6,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3200 - 3215 */
      5,  6,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3216 - 3231 */
      5,  5,  6,  5,  6,  6,  6,  5,  5,  5,  6,  5,  6,  6,  6,  5,  /* 3232 - 3247 */
      6,  5,  6,  6,  6,  6,  6,  6,  5,  5,  6,  5,  6,  6,  6,  5,  /* 3248 - 3263 */
      5,  5,  6,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3264 - 3279 */
      5,  5,  6,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3280 - 3295 */
      5,  5,  6,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3296 - 3311 */
      5,  5,  5,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3312 - 3327 */
      5,  5,  6,  6,  6,  6,  6,  5,  5,  5,  6,  5,  6,  6,  6,  5,  /* 3328 - 3343 */
      5,  5,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3344 - 3359 */
      5,  5,  6,  6,  6,  6,  6,  5,  5,  5,  6,  5,  6,  6,  6,  5,  /* 3360 - 3375 */
      5,  6,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3376 - 3391 */
      5,  5,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  5,  /* 3392 - 3407 */
      5,  5,  6,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  5,  5,  /* 3408 - 3423 */
      5,  5,  6,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  5,  5,  /* 3424 - 3439 */
      5,  5,  5,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  5,  5,  /* 3440 - 3455 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3456 - 3471 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3472 - 3487 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3488 - 3503 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3504 - 3519 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3520 - 3535 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3536 - 3551 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 3552 - 3567 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5, 10,  /* 3568 - 3583 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3584 - 3599 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3600 - 3615 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3616 - 3631 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3632 - 3647 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3648 - 3663 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3664 - 3679 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,  /* 3680 - 3695 */
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14,  /* 3696 - 3711 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3712 - 3727 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3728 - 3743 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3744 - 3759 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3760 - 3775 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3776 - 3791 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3792 - 3807 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3808 - 3823 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3824 - 3839 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3840 - 3855 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3856 - 3871 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3872 - 3887 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3888 - 3903 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3904 - 3919 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3920 - 3935 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3936 - 3951 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3952 - 3967 */
     13, 14, 14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 14, 14, 14, 14,  /* 3968 - 3983 */
     13, 14, 14, 14, 14, 14, 14, 13, 13, 13, 14, 13, 14, 14, 13, 13,  /* 3984 - 3999 */
     13, 13, 14, 13, 14, 14, 14, 13, 13, 13, 14, 13, 14, 14, 13, 13,  /* 4000 - 4015 */
     13, 13, 13, 13, 14, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 4016 - 4031 */
     13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 4032 - 4047 */
     13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 4048 - 4063 */
     13, 13, 13, 13, 14, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 4064 - 4079 */
     13, 13, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0   /* 4080 - 4095 */
};

/*-----------------------------------------------------------------------------------*/

inline uint16_t rp2040adc_correction(uint16_t d)
{
    return d + rp2040adc_err[d];
};
