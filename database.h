

//system_info

#define L0 "\n======================\n + Architecture + \n======================\n"
#define L1 "\n============================\n + List all env variables + \n============================\n"
#define L2 "\n=============================\n + List all drives + \n=============================\n"
#define L3 "\n===============================\n + Extract patchs and updates + \n==============================\n"
#define L30 "\n===============================\n + systeminfo + \n==============================\n"

//user Eunmrtion

#define L4 "\n===============================\n + List user privilege + \n================================\n"
#define L5 "\n===============================\n + List all users + \n===============================\n"
#define L6 "\n============================\n + Users Directory + \n=============================\n"
#define L7 "\n===============================\n +  logon requirements + \n================================\n"
#define L8 "\n=============================\n + Administrator account + \n=============================\n"
#define L9 "\n============================\n + User account + \n============================\n"
#define L10 "\n=================================\n + localgroup administrators + \n=================================\n"

//network Eunmrtion

#define L11 "\n===============================\n + router tabel + \n================================\n"
#define L12 "\n===============================\n + ARP table + \n===============================\n"
#define L13 "\n============================\n + Current connections + \n=============================\n"
#define L14 "\n===============================\n + firewall state & configuration + \n================================\n"
#define L15 "\n=============================\n + Disable firewall + \n=============================\n"
#define L16 "\n=================================\n + SNMP Configurations + \n=================================\n"
#define L17 "\n============================\n + List all network shares + \n============================\n"
#define L18 "\n============================\n + Host file Configuration + \n============================\n"

//password  Enumeration

#define L19 "\n===============================\n +find password in file + \n================================\n"
#define L20 "\n===============================\n + find Password sysprep.nif + \n===============================\n"
#define L21 "\n===============================\n + Wi-fi password + \n===============================\n"
//procce and fole 
#define L22 "\n============================\n + haredware drives + \n=============================\n"
#define L23 "\n===============================\n + test CVE-2019-1322 UsoSvc  + \n================================\n"
#define L24 "\n=============================\n + programfile(64\\86) + \n=============================\n"
#define L25 "\n=================================\n + service list brief + \n=================================\n"
#define L26 "\n============================\n + Task list + \n============================\n"
#define L27 "\n============================\n + start up programs + \n============================\n"
#define L28 "\n============================\n + scheduled tasks + \n============================\n"

#define PATH "%SYSTEMROOT%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"

char buf[BUFSIZ];
FILE *file ;
FILE *ptr;



char  *end   = "________________________END________________________";
char  *end1  = "___________________________________________________";
char  *line0 = "=================================================";
char  *line  = "==================================";
