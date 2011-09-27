#define CODEC_MAX_NUMBER_OF_GTS_DESCRIPTORS                                                        7

#define CODEC_MAX_PENDING_ADRESSES_NUMBER                                                          7


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_SuperFrameSpecification
{
    /**/
    UINT8                   beaconOrder;
    /**/
    UINT8                   superFrameOrder;
    /**/
    UINT8                   finalCAP_Slot;
    /**/
    BOOL                    batteryLifeExtension;
    /**/
    BOOL                    PAN_Coordinator;
    /**/
    BOOL                    associationPermit;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_GTS_Specification
{
    /**/
    UINT8                   descriptorCount;
    /**/
    BOOL                    GTS_Permit;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_GTS_Directions
{
    /**/
    UINT8                   GTS_DirectionsMask;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_GTS_Descriptor
{
    /**/
    UINT16                  deviceShortAddress;
    /**/
    UINT8                   startingSlot;
    /**/
    UINT8                   length;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_GTS_Information
{
    /**/
    CODEC_GTS_Specification             GTS_Specification;
    /**/
    CODEC_GTS_Directions                GTS_Directions;
    /**/
    CODEC_GTS_Descriptor                descriptorList[CODEC_MAX_NUMBER_OF_GTS_DESCRIPTORS];
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_PendingAddressSpecification
{
    /**/
    UINT8                   numberOfShortAdresses;
    /**/
    UINT8                   numberOfExtendedAdresses;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_PendingAddressesInformation
{
    /**/
    CODEC_PendingAddressSpecification       pendingAddressSpecification;
    /**/
    CODEC_Address                           pendingAddressesList[CODEC_MAX_PENDING_ADRESSES_NUMBER];
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct CODEC_BEACON
{
    /**/
    CODEC_MHR                                   MAC_Header;
    /**/
    CODEC_SuperFrameSpecification               superFrameSpecification;
    /**/
    CODEC_GTS_Information                       GTS_Information;
    /**/
    CODEC_PendingAddressesInformation           pendingAddressesInformation;
    /**/
    UINT8                                       payload[STD_MAX_BEACON_PAYLOAD_LENGTH];
    /**/
    UINT16                                      MAC_Footer;
};
