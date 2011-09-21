#define ICM_CNF_MCM_SCAN(a_PAN_DescriptorList_Array_ptr, a_energyDetectedList_Array_ptr, a_resultListSize, a_unscannedChannels, a_channelPage, a_scanType, a_status)\
{                                                                                                  \
    ICM_Struct_CNF_MCM_Scan msgInfo;                                                               \
                                                                                                   \
    COMMON_MEMORY_COPY(&msgPAN_DescriptorList[0], a_PAN_DescriptorList_Array_ptr, (HAL_MAX_DESCRIPTORS_PER_CHANNEL * sizeof(*a_PAN_DescriptorList_Array_ptr)));\
    COMMON_MEMORY_COPY(&msgenergyDetectedList[0], a_energyDetectedList_Array_ptr, (HAL_MAX_CHANNELS_PER_PAGE * sizeof(*a_energyDetectedList_Array_ptr)));\
    msg.resultListSize =                                                          a_resultListSize;\
    msg.unscannedChannels =                                                    a_unscannedChannels;\
    msg.channelPage =                                                                a_channelPage;\
    msg.scanType =                                                                      a_scanType;\
    msg.status =                                                                          a_status;\
                                                                                                   \
    MCM_ICM_CNF_Scan(&msgInfo);                                                                    \
}


#define ICM_REQ_MCM_ASSOCIATE(a_securityContext, a_capabilityInformation, a_coordAddress, a_coordPAN_ID, a_coordAddrMode, a_logicalChannel, a_channelPage)\
{                                                                                                  \
    ICM_Struct_REQ_MCM_Associate msgInfo;                                                          \
                                                                                                   \
    msg.securityContext =                                                        a_securityContext;\
    msg.capabilityInformation =                                            a_capabilityInformation;\
    msg.coordAddress =                                                              a_coordAddress;\
    msg.coordPAN_ID =                                                                a_coordPAN_ID;\
    msg.coordAddrMode =                                                            a_coordAddrMode;\
    msg.logicalChannel =                                                          a_logicalChannel;\
    msg.channelPage =                                                                a_channelPage;\
                                                                                                   \
    MCM_ICM_REQ_Associate(&msgInfo);                                                               \
}


#define ICM_CNF_MCM_ASSOCIATE(a_securityContext, a_status, a_assocShortAddress)                    \
{                                                                                                  \
    ICM_Struct_CNF_MCM_Associate msgInfo;                                                          \
                                                                                                   \
    msg.securityContext =                                                        a_securityContext;\
    msg.status =                                                                          a_status;\
    msg.assocShortAddress =                                                    a_assocShortAddress;\
                                                                                                   \
    MCM_ICM_CNF_Associate(&msgInfo);                                                               \
}


#define ICM_REQ_MCM_SCAN(a_securityContext, a_channelPage, a_scanDuration, a_scanChannels, a_scanType)\
{                                                                                                  \
    ICM_Struct_REQ_MCM_Scan msgInfo;                                                               \
                                                                                                   \
    msg.securityContext =                                                        a_securityContext;\
    msg.channelPage =                                                                a_channelPage;\
    msg.scanDuration =                                                              a_scanDuration;\
    msg.scanChannels =                                                              a_scanChannels;\
    msg.scanType =                                                                      a_scanType;\
                                                                                                   \
    MCM_ICM_REQ_Scan(&msgInfo);                                                                    \
}


