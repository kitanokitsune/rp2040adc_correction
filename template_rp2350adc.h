/* rp2350 adc correction: Individual C/C++ Code Template */

/*-----------------------------------------------------------------------------------*/
/* Replace the below rp2350adc_err[] with your own data                              */

int8_t rp2350adc_err[] = {
      0, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /*    0 -   15 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /*   16 -   31 */
     -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /*   32 -   47 */
     -2, -2, -2, -2, -2, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2,  /*   48 -   63 */
     -1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1, -1,  /*   64 -   79 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*   80 -   95 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*   96 -  111 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  112 -  127 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  128 -  143 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  144 -  159 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  160 -  175 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  176 -  191 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  192 -  207 */
     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  /*  208 -  223 */
     -1, -1,  0,  0, -1,  0,  0, -1, -1, -1, -1, -1, -1, -1,  0,  0,  /*  224 -  239 */
      0,  0,  0,  0,  0,  0,  0,  0, -1, -1, -1,  0,  0,  0,  0,  0,  /*  240 -  255 */
      0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  /*  256 -  271 */
      0,  0,  0,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  1,  1,  /*  272 -  287 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  288 -  303 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  304 -  319 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  320 -  335 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  336 -  351 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  352 -  367 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  368 -  383 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  384 -  399 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  400 -  415 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  416 -  431 */
      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  432 -  447 */
      1,  1,  1,  1,  1,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  /*  448 -  463 */
      1,  1,  1,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  /*  464 -  479 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  480 -  495 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  496 -  511 */
      1,  1,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  /*  512 -  527 */
      1,  2,  2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  2,  2,  2,  2,  /*  528 -  543 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  544 -  559 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  560 -  575 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  576 -  591 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  592 -  607 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  608 -  623 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  624 -  639 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  640 -  655 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  656 -  671 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  672 -  687 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  688 -  703 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  704 -  719 */
      2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  /*  720 -  735 */
      2,  3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  2,  3,  2,  3,  3,  /*  736 -  751 */
      3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  3,  3,  3,  3,  /*  752 -  767 */
      3,  3,  3,  3,  3,  3,  4,  3,  3,  3,  3,  3,  3,  3,  3,  3,  /*  768 -  783 */
      3,  4,  4,  4,  4,  4,  4,  4,  3,  3,  3,  3,  3,  3,  4,  4,  /*  784 -  799 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  800 -  815 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  816 -  831 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  832 -  847 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  848 -  863 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  864 -  879 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  880 -  895 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  896 -  911 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  912 -  927 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  928 -  943 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  944 -  959 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  960 -  975 */
      4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  976 -  991 */
      4,  4,  4,  4,  5,  5,  5,  4,  4,  4,  4,  4,  4,  4,  4,  4,  /*  992 - 1007 */
      4,  5,  5,  4,  5,  5,  5,  4,  4,  4,  4,  4,  5,  5,  4,  4,  /* 1008 - 1023 */
      4,  5,  5,  5,  5,  5,  5,  4,  4,  4,  4,  4,  5,  5,  5,  5,  /* 1024 - 1039 */
      5,  5,  5,  5,  5,  5,  5,  4,  5,  4,  5,  5,  5,  5,  5,  5,  /* 1040 - 1055 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1056 - 1071 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1072 - 1087 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1088 - 1103 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1104 - 1119 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1120 - 1135 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1136 - 1151 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1152 - 1167 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1168 - 1183 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1184 - 1199 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1200 - 1215 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1216 - 1231 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1232 - 1247 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1248 - 1263 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  /* 1264 - 1279 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1280 - 1295 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1296 - 1311 */
      6,  6,  6,  6,  6,  7,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1312 - 1327 */
      6,  7,  7,  6,  7,  7,  7,  6,  6,  6,  6,  6,  6,  6,  6,  7,  /* 1328 - 1343 */
      7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  7,  7,  7,  7,  7,  7,  /* 1344 - 1359 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1360 - 1375 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1376 - 1391 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1392 - 1407 */
      6,  6,  6,  6,  7,  6,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1408 - 1423 */
      6,  6,  7,  6,  7,  7,  7,  6,  6,  6,  6,  6,  6,  6,  7,  7,  /* 1424 - 1439 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1440 - 1455 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1456 - 1471 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1472 - 1487 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1488 - 1503 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1504 - 1519 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1520 - 1535 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1536 - 1551 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1552 - 1567 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1568 - 1583 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1584 - 1599 */
      5,  5,  5,  5,  5,  6,  6,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1600 - 1615 */
      5,  5,  5,  5,  6,  5,  6,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1616 - 1631 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1632 - 1647 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  5,  /* 1648 - 1663 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1664 - 1679 */
      5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1680 - 1695 */
      5,  5,  6,  6,  6,  6,  6,  5,  5,  5,  5,  5,  5,  5,  5,  5,  /* 1696 - 1711 */
      6,  6,  6,  5,  6,  6,  6,  5,  5,  5,  5,  5,  6,  6,  6,  6,  /* 1712 - 1727 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  5,  6,  6,  6,  6,  6,  6,  /* 1728 - 1743 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1744 - 1759 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1760 - 1775 */
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 1776 - 1791 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1792 - 1807 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1808 - 1823 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1824 - 1839 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1840 - 1855 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1856 - 1871 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1872 - 1887 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1888 - 1903 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1904 - 1919 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1920 - 1935 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1936 - 1951 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1952 - 1967 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1968 - 1983 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 1984 - 1999 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2000 - 2015 */
      8,  8,  8,  7,  8,  8,  8,  7,  7,  7,  7,  7,  8,  8,  8,  8,  /* 2016 - 2031 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  7,  7,  7,  8,  7,  7,  7,  /* 2032 - 2047 */
      6,  6,  6,  6,  6,  6,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 2048 - 2063 */
      7,  6,  7,  6,  7,  7,  7,  6,  6,  6,  6,  6,  6,  6,  6,  6,  /* 2064 - 2079 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  7,  7,  7,  /* 2080 - 2095 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  7,  6,  7,  7,  7,  7,  /* 2096 - 2111 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2112 - 2127 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2128 - 2143 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2144 - 2159 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2160 - 2175 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2176 - 2191 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2192 - 2207 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2208 - 2223 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2224 - 2239 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2240 - 2255 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2256 - 2271 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2272 - 2287 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8,  /* 2288 - 2303 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2304 - 2319 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2320 - 2335 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2336 - 2351 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2352 - 2367 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2368 - 2383 */
      8,  9,  8,  8,  9,  8,  9,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2384 - 2399 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2400 - 2415 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  8,  /* 2416 - 2431 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2432 - 2447 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2448 - 2463 */
      9,  9,  9,  8,  9,  9,  9,  8,  8,  8,  8,  8,  9,  9,  9,  8,  /* 2464 - 2479 */
      9,  9,  9,  9,  9,  9,  9,  8,  9,  8,  9,  8,  9,  9,  9,  9,  /* 2480 - 2495 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2496 - 2511 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2512 - 2527 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2528 - 2543 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2544 - 2559 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2560 - 2575 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2576 - 2591 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2592 - 2607 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2608 - 2623 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2624 - 2639 */
      7,  7,  7,  7,  7,  7,  8,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2640 - 2655 */
      8,  8,  8,  7,  8,  8,  8,  8,  7,  7,  8,  7,  8,  8,  8,  7,  /* 2656 - 2671 */
      8,  8,  8,  8,  8,  8,  8,  7,  8,  7,  8,  7,  8,  8,  8,  7,  /* 2672 - 2687 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2688 - 2703 */
      7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  /* 2704 - 2719 */
      7,  7,  7,  7,  8,  8,  8,  7,  7,  7,  7,  7,  8,  7,  8,  7,  /* 2720 - 2735 */
      8,  7,  8,  8,  8,  8,  8,  7,  7,  7,  7,  7,  8,  7,  8,  8,  /* 2736 - 2751 */
      8,  8,  8,  8,  8,  8,  8,  7,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2752 - 2767 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2768 - 2783 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2784 - 2799 */
      8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  /* 2800 - 2815 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2816 - 2831 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2832 - 2847 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2848 - 2863 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2864 - 2879 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2880 - 2895 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2896 - 2911 */
      9,  9,  9,  9, 10,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2912 - 2927 */
     10,  9,  9,  9, 10, 10, 10,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2928 - 2943 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2944 - 2959 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2960 - 2975 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2976 - 2991 */
      9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 2992 - 3007 */
     10, 10,  9,  9, 10, 10, 10,  9,  9,  9,  9,  9,  9,  9,  9,  9,  /* 3008 - 3023 */
     10, 10, 10, 10, 10, 10, 10,  9,  9,  9,  9,  9, 10, 10, 10, 10,  /* 3024 - 3039 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3040 - 3055 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  9,  /* 3056 - 3071 */
      9, 10, 10, 10, 10, 10, 10,  9, 10,  9, 10,  9, 10, 10, 10, 10,  /* 3072 - 3087 */
     10, 10, 10, 10, 10, 10, 10,  9, 10, 10, 10,  9, 10, 10, 10, 10,  /* 3088 - 3103 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3104 - 3119 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3120 - 3135 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3136 - 3151 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3152 - 3167 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3168 - 3183 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3184 - 3199 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3200 - 3215 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3216 - 3231 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3232 - 3247 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3248 - 3263 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3264 - 3279 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3280 - 3295 */
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  /* 3296 - 3311 */
     11, 11, 11, 10, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 11, 11,  /* 3312 - 3327 */
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,  /* 3328 - 3343 */
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,  /* 3344 - 3359 */
     12, 11, 12, 11, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,  /* 3360 - 3375 */
     12, 12, 12, 12, 12, 12, 12, 11, 12, 11, 11, 11, 12, 12, 12, 12,  /* 3376 - 3391 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3392 - 3407 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3408 - 3423 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3424 - 3439 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3440 - 3455 */
     11, 12, 12, 12, 12, 12, 12, 11, 11, 12, 11, 11, 12, 12, 11, 11,  /* 3456 - 3471 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 12, 11, 12, 12,  /* 3472 - 3487 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3488 - 3503 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3504 - 3519 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3520 - 3535 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3536 - 3551 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3552 - 3567 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3568 - 3583 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3584 - 3599 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3600 - 3615 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3616 - 3631 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3632 - 3647 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3648 - 3663 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3664 - 3679 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3680 - 3695 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3696 - 3711 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3712 - 3727 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3728 - 3743 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3744 - 3759 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3760 - 3775 */
     12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3776 - 3791 */
     12, 12, 12, 12, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,  /* 3792 - 3807 */
     13, 13, 13, 13, 13, 13, 13, 12, 13, 12, 13, 12, 12, 13, 12, 12,  /* 3808 - 3823 */
     13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 12, 12, 13, 13, 13, 13,  /* 3824 - 3839 */
     13, 13, 13, 13, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 3840 - 3855 */
     14, 14, 13, 13, 14, 14, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 3856 - 3871 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 13, 14, 14, 14, 14,  /* 3872 - 3887 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3888 - 3903 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3904 - 3919 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3920 - 3935 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3936 - 3951 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 3952 - 3967 */
     14, 13, 14, 14, 14, 14, 14, 13, 14, 13, 13, 13, 14, 14, 14, 13,  /* 3968 - 3983 */
     14, 14, 14, 14, 14, 14, 14, 13, 14, 14, 13, 13, 14, 13, 14, 13,  /* 3984 - 3999 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 13, 14, 14, 14, 14, 13,  /* 4000 - 4015 */
     14, 14, 14, 13, 14, 14, 14, 13, 14, 13, 13, 13, 14, 13, 14, 13,  /* 4016 - 4031 */
     14, 14, 14, 13, 14, 14, 14, 13, 13, 13, 13, 13, 13, 13, 13, 13,  /* 4032 - 4047 */
     14, 14, 13, 13, 14, 14, 14, 14, 14, 14, 13, 14, 14, 14, 14, 14,  /* 4048 - 4063 */
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  /* 4064 - 4079 */
     14, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0   /* 4080 - 4095 */
};

/*-----------------------------------------------------------------------------------*/

inline uint16_t rp2350adc_correction(uint16_t d)
{
    return d + rp2350adc_err[d];
};
