typedef struct
{
    HAL_PAN_Descriptor                                PAN_DescriptorList[HAL_MAX_DESCRIPTORS_PER_CHANNEL];
    UINT8                                energyDetectedList[HAL_MAX_CHANNELS_PER_PAGE];
    UINT8                                resultListSize;
    UINT32                                unscannedChannels;
    UINT8                                channelPage;
    HAL_ScanType                                scanType;
    HAL_ScanConfirmStatus                                status;
} ICM_Struct_CNF_MCM_Scan;


typedef struct
{
    HAL_SecurityContext                                securityContext;
    UINT8                                capabilityInformation;
    HAL_Address                                coordAddress;
    UINT16                                coordPAN_ID;
    HAL_CoordAddrMode                                coordAddrMode;
    UINT32                                logicalChannel;
    UINT32                                channelPage;
} ICM_Struct_REQ_MCM_Associate;



typedef struct
{
    HAL_SecurityContext                                securityContext;
    HAL_AssociateConfirmStatus                                status;
    UINT16                                assocShortAddress;
} ICM_Struct_CNF_MCM_Associate;


typedef struct
{
    HAL_SecurityContext                                securityContext;
    UINT8                                channelPage;
    UINT8                                scanDuration;
    UINT32                                scanChannels;
    HAL_ScanType                                scanType;
} ICM_Struct_REQ_MCM_Scan;


