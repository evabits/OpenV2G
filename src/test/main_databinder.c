/*
 * Copyright (C) 2007-2014 Siemens AG
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
 * @author Daniel.Peintner.EXT@siemens.com
 * @version 0.9 
 * @contact Joerg.Heuer@siemens.com
 *
 * <p>Code generated by EXIdizer</p>
 * <p>Schema: V2G_CI_MsgDef.xsd</p>
 *
 *
 ********************************************************************/



/*******************************************************************
 *
 * <p>Sample program to illustrate how to read an EXI stream and
 *  directly write it again to an output</p>
 *
 *  <p>e.g., <executable> in.exi out.exi</p>
 ********************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* schema-dependent */
#include "v2gEXIDatatypes.h"
#include "v2gEXIDatatypesEncoder.h"
#include "v2gEXIDatatypesDecoder.h"


#include "ByteStream.h"

/** EXI Debug mode */
#define EXI_DEBUG 0

#define BUFFER_SIZE 4096
uint8_t bufferIn[BUFFER_SIZE];
uint8_t bufferOut[BUFFER_SIZE];


#if EXI_DEBUG == 1
# define DEBUG_PRINTF(x) printf x
#else
# define DEBUG_PRINTF(x) do {} while (0)
#endif


int main_databinder(int argc, char *argv[]) {

	struct v2gEXIDocument exiDoc;
	int errn = 0;

	bitstream_t iStream, oStream;

#if EXI_STREAM == BYTE_ARRAY
	uint16_t posDecode;
	uint16_t posEncode;
#endif /* EXI_STREAM == BYTE_ARRAY */


#if EXI_DEBUG == 1
	/* The Eclipse console has buffering problems on Windows e.g, Debug mode */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
#endif /*EXI_DEBUG*/

	if (argc != 3) {
		printf("Usage: %s exiInput exiOutput\n", argv[0]);
		return -1;
	}

#if EXI_STREAM == BYTE_ARRAY
	/* input pos */
	posDecode = 0;
	/* parse EXI stream to internal byte structures  */
	errn = readBytesFromFile(argv[1], bufferIn, BUFFER_SIZE, &posDecode);
	if (errn != 0) {
		printf("Problems while reading file into buffer, err==%d\n", errn);
		return errn;
	}
	posDecode = 0; /* reset position */
#endif /* EXI_STREAM == BYTE_ARRAY */

	/* setup input stream */
#if EXI_STREAM == BYTE_ARRAY
	iStream.size = BUFFER_SIZE;
	iStream.data = bufferIn;
	iStream.pos = &posDecode;
#endif /* EXI_STREAM == BYTE_ARRAY */

	iStream.buffer = 0;
	iStream.capacity = 0;


	printf("Start decoding EXI stream to databinding layer \n");
	errn = decode_v2gExiDocument(&iStream, &exiDoc);
	if (errn != 0) {
		printf("Problems while decoding EXI stream, err==%d\n", errn);
		return errn;
	}

#if EXI_STREAM == BYTE_ARRAY
	/* setup output stream */
	posEncode = 0;
	oStream.size = BUFFER_SIZE;
	oStream.data = bufferOut;
	oStream.pos = &posEncode;
#endif

	oStream.buffer = 0;
	oStream.capacity = 8;

	printf("Start encoding databinding layer to EXI \n");
	errn = encode_v2gExiDocument(&oStream, &exiDoc);
	if (errn != 0) {
		printf("Problems while encoding databinding layer, err==%d\n", errn);
		return errn;
	}

	printf("EXI roundtrip done with success\n");
#if EXI_STREAM == BYTE_ARRAY
	/* write to file */
	writeBytesToFile(oStream.data, posEncode, argv[2]);
#endif


	return errn;
}

