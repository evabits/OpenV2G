set(APPHANDSHAKE_FILES 
    appHandshake/appHandEXIDatatypes.c
    appHandshake/appHandEXIDatatypesDecoder.c
    appHandshake/appHandEXIDatatypesEncoder.c)

set(CODEC_FILES
    codec/BitInputStream.c
    codec/BitOutputStream.c
    codec/ByteStream.c
    codec/DecoderChannel.c
    codec/EncoderChannel.c
    codec/EXIHeaderDecoder.c
    codec/EXIHeaderEncoder.c
    codec/MethodsBag.c
    )

set(DIN_FILES
    din/dinEXIDatatypes.c
    din/dinEXIDatatypesDecoder.c
    din/dinEXIDatatypesEncoder.c
    )

set(ISO1_FILES
    iso1/iso1EXIDatatypes.c
    iso1/iso1EXIDatatypesDecoder.c
    iso1/iso1EXIDatatypesEncoder.c
    )

set(ISO2_FILES
    iso2/iso2EXIDatatypes.c
    iso2/iso2EXIDatatypesDecoder.c
    iso2/iso2EXIDatatypesEncoder.c
    )

set(TEST_FILES 
    test/main.c
    test/main_databinder.c
    test/main_example.c)

set(TRANSPORT_FILES 
    transport/v2gtp.c)

set(XMLDSIG_FILES
    xmldsig/xmldsigEXIDatatypes.c
    xmldsig/xmldsigEXIDatatypesDecoder.c
    xmldsig/xmldsigEXIDatatypesEncoder.c
    )

add_executable(OpenV2G.exe ${APPHANDSHAKE_FILES} ${CODEC_FILES} ${TRANSPORT_FILES} ${DIN_FILES} ${ISO1_FILES} ${ISO2_FILES} ${XMLDSIG_FILES} ${TEST_FILES})
target_include_directories(OpenV2G.exe PUBLIC "${PROJECT_BINARY_DIR}" appHandshake codec din iso1 iso2 test transport xmldsig)