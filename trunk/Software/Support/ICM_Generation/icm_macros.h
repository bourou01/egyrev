#define ICM_CNF_MCM_SCAN(a_, a_, a_, a_, a_, a_, a_)                                               \
{                                                                                                  \
    ICM_Struct_CNF_MCM_Scan msgInfo;                                                               \
                                                                                                   \
    msg.PAN_DescriptorList[HAL_MAX_DESCRIPTORS_PER_CHANNEL] = a_PAN_DescriptorList[HAL_MAX_DESCRIPTORS_PER_CHANNEL];\
    msg.energyDetectedList[HAL_MAX_CHANNELS_PER_PAGE] = a_energyDetectedList[HAL_MAX_CHANNELS_PER_PAGE];\
    msg.resultListSize =                                                          a_resultListSize;\
    msg.unscannedChannels =                                                    a_unscannedChannels;\
    msg.channelPage =                                                                a_channelPage;\
    msg.scanType =                                                                      a_scanType;\
    msg.status =                                                                          a_status;\
                                                                                                   \
    MCM_ICM_CNF_Scan(&msgInfo);                                                                    \
}


#define ICM_REQ_MCM_ASSOCIATE(a_, a_, a_, a_, a_, a_, a_)                                          \
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


#define ICM_CNF_MCM_ASSOCIATE(a_, a_, a_)                                                          \
{                                                                                                  \
    ICM_Struct_CNF_MCM_Associate msgInfo;                                                          \
                                                                                                   \
    msg.securityContext =                                                        a_securityContext;\
    msg.status =                                                                          a_status;\
    msg.assocShortAddress =                                                    a_assocShortAddress;\
                                                                                                   \
    MCM_ICM_CNF_Associate(&msgInfo);                                                               \
}


#define ICM_REQ_MCM_SCAN(a_, a_, a_, a_, a_)                                                       \
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


