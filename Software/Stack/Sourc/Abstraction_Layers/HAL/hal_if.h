#define HAL_MAX_CHANNELS_PER_PAGE                                                               27

#define HAL_MAX_DESCRIPTORS_PER_CHANNEL                                                         10

#define HAL_MAX_DATA_PACKET_SIZE                                                               128

/* ************************************************************************************************
 * Description
 *		Status variable, used in confirmations and some return values.
 * ***********************************************************************************************/
typedef enum HAL_Status
{
	/*Indicates failure*/
	HAL_STATUS_FAILURE,
	/*Indicates success*/
	HAL_STATUS_SUCCESS
} HAL_Status;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_ScanType
{
    /*ED scan*/
    HAL_SCAN_TYPE_ED        = 0x00,
    /*Active scan*/
    HAL_SCAN_TYPE_ACTIVE    = 0x01,
    /*Passive scan*/
    HAL_SCAN_TYPE_PASSIVE   = 0x02,
    /*Orphan scan*/
    HAL_SCAN_TYPE_ORPHAN    = 0x03
} HAL_ScanType;

/* ************************************************************************************************
 * Description
 *      This enum is used in the scanConfirm interface info structure.
 * ***********************************************************************************************/
typedef enum HAL_ScanConfirmStatus
{
    /*Success*/
    HAL_SCAN_CONFIRM_SUCCESS,
    /*Limit reached*/
    HAL_SCAN_CONFIRM_LIMIT_REACHED,
    /*No beacon*/
    HAL_SCAN_CONFIRM_NO_BEACON,
    /*Scan in progress*/
    HAL_SCAN_CONFIRM_SCAN_IN_PROGRESS,
    /*Counter error*/
    HAL_SCAN_CONFIRM_COUNTER_ERROR,
    /*Frame too long*/
    HAL_SCAN_CONFIRM_FRAME_TOO_LONG,
    /*Unavailable key*/
    HAL_SCAN_CONFIRM_UNAVAILABLE_KEY,
    /*Unsupported security*/
    HAL_SCAN_CONFIRM_UNSUPPORTED_SECURITY,
    /*Invalid parameter*/
    HAL_SCAN_CONFIRM_INVALID_PARAMETER,
} HAL_ScanConfirmStatus;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_CoordinatorAddressingMode
{
    /*16-bit Short address*/
    HAL_COORDINATOR_ADDRESSING_MODE_SHORT       = 0x02,
    /*64-bit Extended address*/
    HAL_COORDINATOR_ADDRESSING_MODE_EXTENDED    = 0x03
} HAL_CoordAddrMode;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_SecurityFailure
{
    /*Success*/
    HAL_SECURITY_FAILURE_SUCESS,
    /*Counter error*/
    HAL_SECURITY_FAILURE_COUNTER_ERROR,
    /*Improper key type*/
    HAL_SECURITY_FAILURE_IMPROPER_KEY_TYPE,
    /*Improper security level*/
    HAL_SECURITY_FAILURE_IMPROPER_SECURITY_LEVEL,
    /*Security error*/
    HAL_SECURITY_FAILURE_SECURITY_ERROR,
    /*Unavailable key*/
    HAL_SECURITY_FAILURE_UNAVAILABLE_Key,
    /*Unsupported legacy*/
    HAL_SECURITY_FAILURE_UNSUPPORTED_LEGACY,
    /*Unsupported security*/
    HAL_SECURITY_FAILURE_UNSUPPORTED_SECURITY,
} HAL_SecurityFailure;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_AssociationResponseStatus
{
    /**/
    HAL_ASSOCIATION_RESPONSE_STATUS_SUCCESS              = 0x00,
    /**/
    HAL_ASSOCIATION_RESPONSE_STATUS_PAN_AT_CAPACITY      = 0x01,
    /**/
    HAL_ASSOCIATION_RESPONSE_STATUS_PAN_ACCESS_DENIED    = 0x02,
    /**/
    HAL_ASSOCIATION_RESPONSE_STATUS_RESERVED             = 0x03,
    /**/
    HAL_ASSOCIATION_RESPONSE_STATUS_PRIMITIVE_RESERVED   = 0x80,
} HAL_AssociationResponseStatus;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_AssociateConfirmStatus
{
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_SUCCESS,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_CHANNEL_ACCESS_FAILURE,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_NO_ACK,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_NO_DATA,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_COUNTER_ERROR,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_FRAME_TOO_LONG,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_IMPROPER_KEY_TYPE,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_IMPROPER_SECURITY_LEVEL,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_SECURITY_ERROR,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_UNAVAILABLE_KEY,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_UNSUPPORTED_LEGACY,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_UNSUPPORTED_SECURITY,
    /**/
    HAL_ASSOCIATE_CONFIRM_STATUS_INVALID_PARAMETER,
} HAL_AssociateConfirmStatus;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_AddressMode
{
    /**/
    HAL_ADDRESS_MODE_NO_ADDRESS     = 0x00,
    /**/
    HAL_ADDRESS_MODE_RESERVED       = 0x01,
    /**/
    HAL_ADDRESS_MODE_SHORT          = 0x02,
    /**/
    HAL_ADDRESS_MODE_EXTENDED       = 0x03
} HAL_AddressMode;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_DataConfirmStatus
{
    /**/
    HAL_DATA_CONFIRM_STATUS_SUCCESS,
    /**/
    HAL_DATA_CONFIRM_STATUS_TRANSACTION_OVERFLOW,
    /**/
    HAL_DATA_CONFIRM_STATUS_TRANSACTION_EXPIRED,
    /**/
    HAL_DATA_CONFIRM_STATUS_CHANNEL_ACCESS_FAILURE,
    /**/
    HAL_DATA_CONFIRM_STATUS_INVALID_ADDRESS,
    /**/
    HAL_DATA_CONFIRM_STATUS_INVALID_GTS,
    /**/
    HAL_DATA_CONFIRM_STATUS_NO_ACK,
    /**/
    HAL_DATA_CONFIRM_STATUS_COUNTER_ERROR,
    /**/
    HAL_DATA_CONFIRM_STATUS_FRAME_TOO_LONG,
    /**/
    HAL_DATA_CONFIRM_STATUS_UNAVAILABLE_KEY,
    /**/
    HAL_DATA_CONFIRM_STATUS_UNSUPPORTED_SECURITY,
    /**/
    HAL_DATA_CONFIRM_STATUS_INVALID_PARAMETER,
} HAL_DataConfirmStatus;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_DeviceAddressMode
{
    /**/
    HAL_DEVICE_ADDRESS_MODE_SHORT       = 0x02,
    /**/
    HAL_DEVICE_ADDRESS_MODE_EXTENDED    = 0x03
} HAL_DeviceAddressMode;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_DisassociationReasonCode
{
    /**/
    HAL_DISASSOCIATION_REASON_RESERVED_1                    = 0x00,
    /**/
    HAL_DISASSOCIATION_REASON_COORDINATOR_REQUEST_LEAVE     = 0x01,
    /**/
    HAL_DISASSOCIATION_REASON_DEVICE_REQUEST_LEAVE          = 0x02,
    /**/
    HAL_DISASSOCIATION_REASON_RESERVED_2                    = 0x03,
    /**/
    HAL_DISASSOCIATION_REASON_MAC_RESERVED                  = 0x80,
} HAL_DisassociationReason;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum HAL_DisassociateConfirmStatus
{
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_SUCCESS,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_TRANSACTION_OVERFLOW,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_TRANSACTION_EXPIRED,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_NO_ACK,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_CHANNEL_ACCESS_FAILURE,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_COUNTER_ERROR,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_FRAME_TOO_LONG,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_UNAVAILABLE_KEY,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_UNSUPPORTED_SECURITY,
    /**/
    HAL_DISASSOCIATE_CONFIRM_STATUS_INVALID_PARAMETER,
} HAL_DisassociateConfirmStatus;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_SecurityContext
{
    /*Security level*/
    UINT8                        securityLevel;
    /*Key ID mode*/
    UINT8                        keyIdMode;
    /*Key source*/
    UINT8                        keySource[8];
    /*Key index*/
    UINT8                        keyIndex;
} HAL_SecurityContext;

/* ************************************************************************************************
 * Description
 *      This structure contains information of the ScanRequest interface called by higher layer.
 * ***********************************************************************************************/
typedef struct HAL_IF_ScanReqInfo
{
	/*Type of requested scan*/
    HAL_ScanType        scanType;
	/*27 bit field indicating which channels required to be scanned where 0 = don't_scan and 1 = scan. */
	UINT32              scanChannels;
	/*Time required to scan on each channel. Range: [0 - 14]*/
	UINT8               scanDuration;
	/*Channel page required to scan on. Range: [0 - 31]*/
	UINT8               channelPage;
	/**/
	HAL_SecurityContext securityContext;
} HAL_IF_ScanReqInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef union HAL_Address
{
    /*Short address*/
    UINT16    shortCoordAddress;
    /*Extended address*/
    UINT64    extendedCoordAddress;
} HAL_Address;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_PAN_Descriptor
{
    /*Coordinator addressing mode*/
    HAL_CoordAddrMode		coordAddrMode;
    /*Coordinator PAN ID*/
    UINT16          		coordPAN_Id;
    /*Coordinator address*/
    HAL_Address        coordAddress;
    /*Logical channel number*/
    UINT32                  logicalChannel;
    /*Channel page*/
    UINT32                  channelPage;
    /*Super frame specifications*/
    UINT16                  superFrameSpec;
    /*GTS permit*/
    BOOL                    GTS_Permit;
    /*Link quality*/
    UINT8                   linkQuality;
    /*time stamp*/
    UINT32                  timeStamp;
    /*Security failure*/
    HAL_SecurityFailure     securityFailure;
    /**/
    HAL_SecurityContext     securityContext;
} HAL_PAN_Descriptor;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_ScanCnfInfo
{
    /*Status*/
    HAL_ScanConfirmStatus		  status;
    /*Required scan type*/
    HAL_ScanType		          scanType;
    /*Required channel page to be scanned*/
    UINT8                         channelPage;
    /*27-bit bitmap with the un-scanned channels where bit set to zero means that this channel
     * was scanned and set to one when it was scanned*/
    UINT32                        unscannedChannels;
    /*Result list size*/
    UINT8                         resultListSize;
    /*Energy detected list*/
    UINT8                         energyDetectedList[HAL_MAX_CHANNELS_PER_PAGE];
    /*PAN descriptor list*/
    HAL_PAN_Descriptor            PAN_DescriptorList[HAL_MAX_DESCRIPTORS_PER_CHANNEL];
} HAL_IF_ScanCnfInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_AssociateReqInfo
{
    /*Logical channel*/
    UINT32                       logicalChannel;
    /*Channel page*/
    UINT32                       channelPage;
    /*Coordinator addressing mode*/
    HAL_CoordAddrMode            coordAddrMode;
    /*Coordinator PAN ID*/
    UINT16                       coordPAN_ID;
    /*Coordinator address*/
    HAL_Address             coordAddress;
    /*Capability information*/
    UINT8                        capabilityInformation;
    /**/
    HAL_SecurityContext          securityContext;
} HAL_IF_AssociateReqInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_AssociateIndInfo
{
    /*Device address*/
    UINT64                       deviceAddress;
    /*Capability information*/
    UINT8                        capabilityInformation;
    /**/
    HAL_SecurityContext          securityContext;
} HAL_IF_AssociateIndInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_AssociateRspInfo
{
    /*Device address*/
    UINT64                          deviceAddress;
    /*Association short address*/
    UINT16                          assocShortAddress;
    /*Association status*/
    HAL_AssociationResponseStatus   status;
    /**/
    HAL_SecurityContext             securityContext;
} HAL_IF_AssociateRspInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_AssociateCnfInfo
{
    /*Association short address*/
    UINT16                          assocShortAddress;
    /*Status*/
    HAL_AssociateConfirmStatus      status;
    /**/
    HAL_SecurityContext             securityContext;
} HAL_IF_AssociateCnfInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_DataReqInfo
{
    /**/
    HAL_AddressMode       srcAddrMode;
    /**/
    HAL_AddressMode       dstAddrMode;
    /**/
    UINT16                dstPAN_Id;
    /**/
    HAL_Address      dstAddress;
    /**/
    UINT32                msduLength;
    /**/
    UINT8                 msdu[HAL_MAX_DATA_PACKET_SIZE];
    /**/
    UINT8                 msduHandle;
    /**/
    UINT8                 TX_Options;
    /**/
    HAL_SecurityContext   securityContext;
} HAL_IF_DataReqInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_DataCnfInfo
{
    /**/
    UINT8                       msduHandle;
    /**/
    HAL_DataConfirmStatus       status;
    /**/
    UINT32                      timeStamp;
} HAL_IF_DataCnfInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_DataIndInfo
{
    /**/
    HAL_AddressMode         srcAddrMode;
    /**/
    UINT16                  srcPAN_Id;
    /**/
    HAL_Address        srcAddress;
    /**/
    HAL_AddressMode         dstAddrMode;
    /**/
    UINT16                  dstPAN_Id;
    /**/
    HAL_Address        dstAddress;
    /**/
    UINT32                  msduLength;
    /**/
    UINT8                   msdu[HAL_MAX_DATA_PACKET_SIZE];
    /**/
    UINT8                   mpduLinkQuality;
    /**/
    UINT8                   DSN;
    /**/
    UINT32                  timeStamp;
    /**/
    HAL_SecurityContext     securityContext;
} HAL_IF_DataIndInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_DisassociateReqInfo
{
    /**/
    HAL_DeviceAddressMode           deviceAddrMode;
    /**/
    UINT16                          devicePAN_Id;
    /**/
    HAL_Address                     deviceAddress;
    /**/
    HAL_DisassociationReason        disassociationReason;
    /**/
    BOOL                            TX_Indirect;
    /**/
    HAL_SecurityContext             securityContext;
} HAL_IF_DisassociateReqInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_DisassociateIndInfo
{
    /**/
    HAL_Address                     deviceAddress;
    /**/
    HAL_DisassociationReason        disassociationReason;
    /**/
    HAL_SecurityContext             securityContext;
} HAL_IF_DisassociateIndInfo;

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef struct HAL_IF_DisassociateCnfInfo
{
    /**/
    HAL_DisassociateConfirmStatus       status;
    /**/
    HAL_DeviceAddressMode               deviceAddressMode;
    /**/
    UINT16                              devicePAN_Id;
    /**/
    HAL_Address                         deviceAddress;
} HAL_IF_DisassociateCnfInfo;




HAL_Status HAL_IF_Scan_req(HAL_IF_ScanReqInfo*  a_scanReqInfo_Ptr);

HAL_Status HAL_IF_Scan_cnf(HAL_IF_ScanCnfInfo*  a_scanCnfInfo_Ptr);



HAL_Status HAL_IF_Associate_req(HAL_IF_AssociateReqInfo*  a_associateReqInfo_Ptr);

HAL_Status HAL_IF_Associate_ind(HAL_IF_AssociateIndInfo*  a_associateIndInfo_Ptr);

HAL_Status HAL_IF_Associate_rsp(HAL_IF_AssociateRspInfo*  a_associateRspInfo_Ptr);

HAL_Status HAL_IF_Associate_cnf(HAL_IF_AssociateCnfInfo*  a_associateCnfInfo_Ptr);



HAL_Status HAL_IF_Disassociate_req(HAL_IF_DisassociateReqInfo*  a_disassociateReqInfo_Ptr);

HAL_Status HAL_IF_Disassociate_ind(HAL_IF_DisassociateIndInfo*  a_disassociateIndInfo_Ptr);

HAL_Status HAL_IF_Disassociate_cnf(HAL_IF_DisassociateCnfInfo*  a_disassociateCnfInfo_Ptr);


HAL_Status HAL_IF_Data_req(HAL_IF_DataReqInfo*  a_dataReqInfo_Ptr);

HAL_Status HAL_IF_Data_cnf(HAL_IF_DataCnfInfo*  a_dataCnfInfo_Ptr);

HAL_Status HAL_IF_Data_ind(HAL_IF_DataIndInfo*  a_dataIndInfo_Ptr);
