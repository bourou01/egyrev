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
typedef enum ScanType
{
    /*ED scan*/
    SCAN_TYPE_ED        = 0x00,
    /*Active scan*/
    SCAN_TYPE_ACTIVE    = 0x01,
    /*Passive scan*/
    SCAN_TYPE_PASSIVE   = 0x02,
    /*Orphan scan*/
    SCAN_TYPE_ORPHAN    = 0x03
};

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum PHY_AttributeType
{
    /**/
    PHY_ATTRIBUTE_TYPE_CURRENT_CHANNEL          = 0x00,
    /**/
    PHY_ATTRIBUTE_TYPE_CHANNELS_SUPPORTED       = 0x01,
    /**/
    PHY_ATTRIBUTE_TYPE_TRANSMIT_POWER           = 0x02,
    /**/
    PHY_ATTRIBUTE_TYPE_CCA_MODE                 = 0x03,
    /**/
    PHY_ATTRIBUTE_TYPE_CURRENT_PAGE             = 0x04,
    /**/
    PHY_ATTRIBUTE_TYPE_MAX_FRAME_DURATION       = 0x05,
    /**/
    PHY_ATTRIBUTE_TYPE_MAX_SHR_DURATION         = 0x06,
    /**/
    PHY_ATTRIBUTE_TYPE_SYMBOLS_PER_OCTET        = 0x07
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum PHY_SetAttributeStatus
{
    /**/
    PHY_SET_ATTRIBUTE_STATUS_SUCCESS                    = 0x00,
    /**/
    PHY_SET_ATTRIBUTE_STATUS_UNSUPPORTED_ATTRIBUTE      = 0x01,
    /**/
    PHY_SET_ATTRIBUTE_STATUS_INVALID_PARAMETER          = 0x02,
    /**/
    PHY_SET_ATTRIBUTE_STATUS_READ_ONLY                  = 0x03
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum FilterType
{
    /**/
    FILTER_TYPE_BEACONS_ONLY                    = 0x00
};

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct SecurityContext
{
    /*Security level*/
    UINT8                        securityLevel;
    /*Key ID mode*/
    UINT8                        keyIdMode;
    /*Key source*/
    UINT8                        keySource[8];
    /*Key index*/
    UINT8                        keyIndex;
};
