
/*
 * Copyright (C) 2007-2012 Siemens AG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*******************************************************************
 *
 * @author Sebastian.Kaebisch.EXT@siemens.com
 * @version 0.6
 * @contact Joerg.Heuer@siemens.com
 *
 * <p>Code generated by EXISeGen</p>
 *
 ********************************************************************/



#ifdef __cplusplus
extern "C" {
#endif

#ifndef APPHANDDATATYPES_H
#define APPHANDDATATYPES_H

#include "EXITypes.h"


	

enum responseCodeType_appHand
{
	OK_SuccessfulNegotiation_responseCodeType, 
	OK_SuccessfulNegotiationWithMinorDeviation_responseCodeType, 
	Failed_NoNegotiation_responseCodeType

}; 




struct arraylen_protocolNamespaceType
{
	size_t data;


};

struct protocolNamespaceType
{
	uint32_t data[100];
	struct arraylen_protocolNamespaceType arraylen;

};

struct AppProtocolType
{
	struct protocolNamespaceType ProtocolNamespace;
	uint32_t VersionNumberMajor;
	uint32_t VersionNumberMinor;
	uint8_t SchemaID;
	uint8_t Priority;


};

struct arraylen_AnonType_supportedAppProtocolReq
{
	size_t AppProtocol;


};

struct AnonType_supportedAppProtocolReq
{
	struct AppProtocolType AppProtocol[5];
	struct arraylen_AnonType_supportedAppProtocolReq arraylen;

};

struct selection_EXIDocumentType
{
	unsigned int supportedAppProtocolReq:1;
	unsigned int supportedAppProtocolRes:1;


};

struct selection_AnonType_supportedAppProtocolRes
{
	unsigned int SchemaID:1;


};

struct AnonType_supportedAppProtocolRes
{
	enum responseCodeType_appHand ResponseCode;
	uint8_t SchemaID;
	struct selection_AnonType_supportedAppProtocolRes isused;

};

struct EXIDocumentType_appHand
{
	struct AnonType_supportedAppProtocolReq* supportedAppProtocolReq;
	struct AnonType_supportedAppProtocolRes* supportedAppProtocolRes;
	struct selection_EXIDocumentType isused;

};

void init_EXIDocumentType_appHand(struct EXIDocumentType_appHand* type);

#endif

#ifdef __cplusplus
}
#endif
