/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
#define CODEC_BROADCAST_PAN_IDENTIFIER                                                       0xFFFF

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
#define CODEC_BROADCAST_ADDRESS                                                              0xFFFF

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum CODEC_FrameType
{
    /**/
    CODEC_FRAME_TYPE_BEACON             = 0,
    /**/
    CODEC_FRAME_TYPE_DATA               = 1,
    /**/
    CODEC_FRAME_TYPE_ACKNOWLEDGEMENT    = 2,
    /**/
    CODEC_FRAME_TYPE_MAC_COMMAND        = 3,
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum CODEC_AddressingMode
{
    /**/
    CODEC_ADDRESSING_MODE_NOT_PRESENT           = 0,
    /**/
    CODEC_ADDRESSING_MODE_SHORT_ADDRESS         = 2,
    /**/
    CODEC_ADDRESSING_MODE_EXTENDED_ADDRESS      = 3,
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum CODEC_FrameVersion
{
    /**/
    CODEC_FRAME_VERSION_2003    = 0,
    /**/
    CODEC_FRAME_VERSION_2006    = 1
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum CODEC_SecurityLevel
{
    /**/
    CODEC_SECURITY_LEVEL_NONE           = 0,
    /**/
    CODEC_SECURITY_LEVEL_MIC_32         = 1,
    /**/
    CODEC_SECURITY_LEVEL_MIC_64         = 2,
    /**/
    CODEC_SECURITY_LEVEL_MIC_128        = 3,
    /**/
    CODEC_SECURITY_LEVEL_ENC            = 4,
    /**/
    CODEC_SECURITY_LEVEL_ENC_MIC_32     = 5,
    /**/
    CODEC_SECURITY_LEVEL_ENC_MIC_64     = 6,
    /**/
    CODEC_SECURITY_LEVEL_ENC_MIC_128    = 7
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum CODEC_KeyIdentifierMode
{
    /**/
    CODEC_KEY_IDENTIFIER_MODE_IMPLICIT                      = 0,
    /**/
    CODEC_KEY_IDENTIFIER_MODE_1_OCTET_KEY_INDEX             = 1,
    /**/
    CODEC_KEY_IDENTIFIER_MODE_EXPLICIT_4_OCTET              = 2,
    /**/
    CODEC_KEY_IDENTIFIER_MODE_EXPLICIT_8_OCTET              = 1
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef union CODEC_KeySource
{
    /**/
    UINT32                      keySource_4_Octets;
    /**/
    UINT64                      keySource_8_Octets;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_SecurityControl
{
    /**/
    CODEC_SecurityLevel                         securityLevel;
    /**/
    CODEC_KeyIdentifierMode                     keyIdentifierMode;
};

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_KeyIdentifier
{
    /**/
    CODEC_KeySource             keySource;
    /**/
    UINT8                       keyIndex;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_AuxiliarySecurityHeader
{
    /**/
    CODEC_SecurityControl           securityControl;
    /**/
    UINT32                          counter;
    /**/
    CODEC_KeyIdentifier             keyIdentifier;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_FrameControl
{
    /**/
    CODEC_FrameType                     frameType;
    /**/
    BOOL                                securityEnable;
    /**/
    BOOL                                framePending;
    /**/
    BOOL                                AckRequest;
    /**/
    BOOL                                PAN_ID_Compression;
    /**/
    CODEC_AddressingMode                destinationAddressingMode;
    /**/
    CODEC_FrameVersion                  frameVersion;
    /**/
    CODEC_AddressingMode                sourceAddressingMode;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_MHR
{
    /**/
    CODEC_FrameControl                      framecontrol;
    /**/
    UINT8                                   sequenceNumber;
    /**/
    UINT16                                  destinationPAN_Identifier;
    /**/
    CODEC_Address                           destinationAddress;
    /**/
    UINT16                                  sourcePAN_Identifier;
    /**/
    CODEC_Address                           sourceAddress;
    /**/
    CODEC_AuxiliarySecurityHeader           auxiliarySecurityHeader;
};
