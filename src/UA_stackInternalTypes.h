/*
 * opcua_stackInternalTypes.h
 *
 *  Created on: Mar 24, 2014
 *      Author: opcua
 */


#ifndef OPCUA_STACKINTERNALTYPES_H_
#define OPCUA_STACKINTERNALTYPES_H_

#include "UA_config.h"
#include "opcua.h"
#include "UA_connection.h"


static const UA_Int32 SL_HEADER_LENGTH = 0;
/* Enums */
typedef enum
{
	UA_SECURITYTOKEN_ISSUE = 0,
	UA_SECURITYTOKEN_RENEW = 1
}SecurityTokenRequestType;

typedef enum
{
	UA_SECURITYMODE_INVALID = 0,
	UA_SECURITYMODE_SIGN = 1,
	UA_SECURITYMODE_SIGNANDENCRYPT = 2

} securityMode;
/* Structures */
typedef struct T_SL_Response
{
	UA_UInt32 serverProtocolVersion;
	SL_ChannelSecurityToken securityToken;
	UA_String serverNonce;
}UA_SL_Response;
UA_TYPE_METHOD_PROTOTYPES(UA_SL_Response)

/* MessageType */
typedef UA_Int32 UA_MessageType;
UA_Int32 UA_MessageType_calcSize(UA_MessageType const * ptr);
UA_Int32 UA_MessageType_encode(UA_MessageType const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_MessageType_decode(UA_Byte const * src, UA_Int32* pos, UA_MessageType* dst);
UA_Int32 UA_MessageType_delete(UA_MessageType* p);
UA_Int32 UA_MessageType_deleteMembers(UA_MessageType* p);


/*** UA_OPCUATcpMessageHeader ***/
/* TCP Header */
typedef struct T_UA_OPCUATcpMessageHeader {
	UA_MessageType messageType;
	UA_Byte isFinal;
	UA_UInt32 messageSize;
} UA_OPCUATcpMessageHeader;
UA_Int32 UA_OPCUATcpMessageHeader_calcSize(UA_OPCUATcpMessageHeader const * ptr);
UA_Int32 UA_OPCUATcpMessageHeader_encode(UA_OPCUATcpMessageHeader const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_OPCUATcpMessageHeader_decode(UA_Byte const * src, UA_Int32* pos, UA_OPCUATcpMessageHeader* dst);
UA_Int32 UA_OPCUATcpMessageHeader_delete(UA_OPCUATcpMessageHeader* p);
UA_Int32 UA_OPCUATcpMessageHeader_deleteMembers(UA_OPCUATcpMessageHeader* p);

/*** UA_OPCUATcpHelloMessage ***/
/* Hello Message */
typedef struct T_UA_OPCUATcpHelloMessage {
	UA_UInt32 protocolVersion;
	UA_UInt32 receiveBufferSize;
	UA_UInt32 sendBufferSize;
	UA_UInt32 maxMessageSize;
	UA_UInt32 maxChunkCount;
	UA_String endpointUrl;
} UA_OPCUATcpHelloMessage;
UA_Int32 UA_OPCUATcpHelloMessage_calcSize(UA_OPCUATcpHelloMessage const * ptr);
UA_Int32 UA_OPCUATcpHelloMessage_encode(UA_OPCUATcpHelloMessage const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_OPCUATcpHelloMessage_decode(UA_Byte const * src, UA_Int32* pos, UA_OPCUATcpHelloMessage* dst);
UA_Int32 UA_OPCUATcpHelloMessage_delete(UA_OPCUATcpHelloMessage* p);
UA_Int32 UA_OPCUATcpHelloMessage_deleteMembers(UA_OPCUATcpHelloMessage* p);

/*** UA_OPCUATcpAcknowledgeMessage ***/
/* Acknowledge Message */
typedef struct T_UA_OPCUATcpAcknowledgeMessage {
	UA_UInt32 protocolVersion;
	UA_UInt32 receiveBufferSize;
	UA_UInt32 sendBufferSize;
	UA_UInt32 maxMessageSize;
	UA_UInt32 maxChunkCount;
} UA_OPCUATcpAcknowledgeMessage;
UA_Int32 UA_OPCUATcpAcknowledgeMessage_calcSize(UA_OPCUATcpAcknowledgeMessage const * ptr);
UA_Int32 UA_OPCUATcpAcknowledgeMessage_encode(UA_OPCUATcpAcknowledgeMessage const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_OPCUATcpAcknowledgeMessage_decode(UA_Byte const * src, UA_Int32* pos, UA_OPCUATcpAcknowledgeMessage* dst);
UA_Int32 UA_OPCUATcpAcknowledgeMessage_delete(UA_OPCUATcpAcknowledgeMessage* p);
UA_Int32 UA_OPCUATcpAcknowledgeMessage_deleteMembers(UA_OPCUATcpAcknowledgeMessage* p);

/*** UA_SecureConversationMessageHeader ***/
/* Secure Layer Sequence Header */
typedef struct T_UA_SecureConversationMessageHeader {
	UA_OPCUATcpMessageHeader* tcpMessageHeader;
	UA_UInt32 secureChannelId;
} UA_SecureConversationMessageHeader;
UA_Int32 UA_SecureConversationMessageHeader_calcSize(UA_SecureConversationMessageHeader const * ptr);
UA_Int32 UA_SecureConversationMessageHeader_encode(UA_SecureConversationMessageHeader const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_SecureConversationMessageHeader_decode(UA_Byte const * src, UA_Int32* pos, UA_SecureConversationMessageHeader* dst);
UA_Int32 UA_SecureConversationMessageHeader_delete(UA_SecureConversationMessageHeader* p);
UA_Int32 UA_SecureConversationMessageHeader_deleteMembers(UA_SecureConversationMessageHeader* p);

/*** UA_AsymmetricAlgorithmSecurityHeader ***/
/* Security Header> */
typedef struct T_UA_AsymmetricAlgorithmSecurityHeader {
	UA_ByteString securityPolicyUri;
	UA_ByteString senderCertificate;
	UA_ByteString receiverCertificateThumbprint;
	// UA_UInt32 requestId;
} UA_AsymmetricAlgorithmSecurityHeader;
UA_Int32 UA_AsymmetricAlgorithmSecurityHeader_calcSize(UA_AsymmetricAlgorithmSecurityHeader const * ptr);
UA_Int32 UA_AsymmetricAlgorithmSecurityHeader_encode(UA_AsymmetricAlgorithmSecurityHeader const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_AsymmetricAlgorithmSecurityHeader_decode(UA_Byte const * src, UA_Int32* pos, UA_AsymmetricAlgorithmSecurityHeader* dst);
UA_Int32 UA_AsymmetricAlgorithmSecurityHeader_delete(UA_AsymmetricAlgorithmSecurityHeader* p);
UA_Int32 UA_AsymmetricAlgorithmSecurityHeader_deleteMembers(UA_AsymmetricAlgorithmSecurityHeader* p);

/*** UA_SymmetricAlgorithmSecurityHeader ***/
/* Secure Layer Symmetric Algorithm Header */
typedef struct T_UA_SymmetricAlgorithmSecurityHeader {
	UA_UInt32 tokenId;
} UA_SymmetricAlgorithmSecurityHeader;
UA_Int32 UA_SymmetricAlgorithmSecurityHeader_calcSize(UA_SymmetricAlgorithmSecurityHeader const * ptr);
UA_Int32 UA_SymmetricAlgorithmSecurityHeader_encode(UA_SymmetricAlgorithmSecurityHeader const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_SymmetricAlgorithmSecurityHeader_decode(UA_Byte const * src, UA_Int32* pos, UA_SymmetricAlgorithmSecurityHeader* dst);
UA_Int32 UA_SymmetricAlgorithmSecurityHeader_delete(UA_SymmetricAlgorithmSecurityHeader* p);
UA_Int32 UA_SymmetricAlgorithmSecurityHeader_deleteMembers(UA_SymmetricAlgorithmSecurityHeader* p);

/*** UA_SequenceHeader ***/
/* Secure Layer Sequence Header */
typedef struct T_UA_SequenceHeader {
	UA_UInt32 sequenceNumber;
	UA_UInt32 requestId;
} UA_SequenceHeader;
UA_Int32 UA_SequenceHeader_calcSize(UA_SequenceHeader const * ptr);
UA_Int32 UA_SequenceHeader_encode(UA_SequenceHeader const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_SequenceHeader_decode(UA_Byte const * src, UA_Int32* pos, UA_SequenceHeader* dst);
UA_Int32 UA_SequenceHeader_delete(UA_SequenceHeader* p);
UA_Int32 UA_SequenceHeader_deleteMembers(UA_SequenceHeader* p);

/*** UA_SecureConversationMessageFooter ***/
/* Secure Conversation Message Footer */
typedef struct T_UA_SecureConversationMessageFooter {
	UA_Int32 paddingSize;
	UA_Byte** padding;
	UA_Byte signature;
} UA_SecureConversationMessageFooter;
UA_Int32 UA_SecureConversationMessageFooter_calcSize(UA_SecureConversationMessageFooter const * ptr);
UA_Int32 UA_SecureConversationMessageFooter_encode(UA_SecureConversationMessageFooter const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_SecureConversationMessageFooter_decode(UA_Byte const * src, UA_Int32* pos, UA_SecureConversationMessageFooter* dst);
UA_Int32 UA_SecureConversationMessageFooter_delete(UA_SecureConversationMessageFooter* p);
UA_Int32 UA_SecureConversationMessageFooter_deleteMembers(UA_SecureConversationMessageFooter* p);

/*** UA_SecureConversationMessageAbortBody ***/
/* Secure Conversation Message Abort Body */
typedef struct T_UA_SecureConversationMessageAbortBody {
	UA_UInt32 error;
	UA_String reason;
} UA_SecureConversationMessageAbortBody;
UA_Int32 UA_SecureConversationMessageAbortBody_calcSize(UA_SecureConversationMessageAbortBody const * ptr);
UA_Int32 UA_SecureConversationMessageAbortBody_encode(UA_SecureConversationMessageAbortBody const * src, UA_Int32* pos, UA_Byte* dst);
UA_Int32 UA_SecureConversationMessageAbortBody_decode(UA_Byte const * src, UA_Int32* pos, UA_SecureConversationMessageAbortBody* dst);
UA_Int32 UA_SecureConversationMessageAbortBody_delete(UA_SecureConversationMessageAbortBody* p);
UA_Int32 UA_SecureConversationMessageAbortBody_deleteMembers(UA_SecureConversationMessageAbortBody* p);


#endif