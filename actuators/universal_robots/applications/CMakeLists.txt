ADD_EXECUTABLE( ur-arm-command ur-arm-command.cpp )
TARGET_LINK_LIBRARIES( ur-arm-command ${comma_ALL_LIBRARIES} ${snark_ALL_EXTERNAL_LIBRARIES} )
INSTALL( TARGETS ur-arm-command RUNTIME DESTINATION ${snark_INSTALL_BIN_DIR} COMPONENT Runtime )

ADD_EXECUTABLE( ur-arm-status ur-arm-status.cpp )
TARGET_LINK_LIBRARIES( ur-arm-status ${comma_ALL_LIBRARIES} ${snark_ALL_EXTERNAL_LIBRARIES} )
INSTALL( TARGETS ur-arm-status RUNTIME DESTINATION ${snark_INSTALL_BIN_DIR} COMPONENT Runtime )

INSTALL( PROGRAMS ur-arm ur-arm-statusd DESTINATION ${snark_INSTALL_BIN_DIR} COMPONENT Runtime )
