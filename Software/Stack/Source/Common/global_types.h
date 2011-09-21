typedef unsigned char       UINT8;

typedef signed char         INT8;

typedef unsigned short      UINT16;

typedef signed short        INT16;

typedef unsigned long       UINT32;

typedef signed long         INT32;

typedef unsigned long long  UINT64;

typedef signed long long    INT64;

typedef unsigned char       BOOL;

#define TRUE    1

#define FALSE   0


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct
{
    /*Security level*/
    UINT8                        securityLevel;
    /*Key ID mode*/
    UINT8                        keyIdMode;
    /*Key source*/
    UINT8                        keySource[8];
    /*Key index*/
    UINT8                        keyIndex;
} SecurityContext;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum
{
    /*ED scan*/
    SCAN_TYPE_ED        = 0x00,
    /*Active scan*/
    SCAN_TYPE_ACTIVE    = 0x01,
    /*Passive scan*/
    SCAN_TYPE_PASSIVE   = 0x02,
    /*Orphan scan*/
    SCAN_TYPE_ORPHAN    = 0x03
} ScanType;
