typedef struct
{
    PAN_Descriptor                                PAN_DescriptorList[MAX_DESCRIPTORS_PER_CHANNEL];
    UINT8                                energyDetectedList[MAX_CHANNELS_PER_PAGE];
    UINT8                                resultListSize;
    UINT32                                unscannedChannels;
    UINT8                                channelPage;
    ScanType                                scanType;
    ScanConfirmStatus                                status;
} ICM_Struct_CNF_MCM_Scan;


typedef struct
{
    SecurityContext                                securityContext;
    UINT8                                capabilityInformation;
    Address                                coordAddress;
    UINT16                                coordPAN_ID;
    CoordAddrMode                                coordAddrMode;
    UINT32                                logicalChannel;
    UINT32                                channelPage;
} ICM_Struct_REQ_MCM_Associate;


typedef struct
{
    SecurityContext                                securityContext;
    AssociateConfirmStatus                                status;
    UINT16                                assocShortAddress;
} ICM_Struct_CNF_MCM_Associate;


typedef struct
{
    SecurityContext                                securityContext;
    UINT8                                channelPage;
    UINT8                                scanDuration;
    UINT32                                scanChannels;
    ScanType                                scanType;
} ICM_Struct_REQ_MCM_Scan;


