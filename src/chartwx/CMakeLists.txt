
add_library(chartwx
  chart.cpp
  chartobject.cpp
  chartwindow.cpp
  scale.cpp
  style.cpp
  styledobject.cpp
  valueformatter.cpp
  data/dataset.cpp
  data/defaultdoubledataset.cpp
  data/range.cpp
  renderer/chartrenderer.cpp
  renderer/xychartrenderer.cpp
  axis/axis.cpp
  axis/numericaxis.cpp
  axis/tick.cpp
)

target_sources(chartwx
  PUBLIC FILE_SET HEADERS
  FILES
  enums.h
  chart.h
  chartobject.h
  chartwindow.h
  scale.h
  style.h
  styledobject.h
  valueformatter.h
  data/dataset.h
  data/defaultdoubledataset.h
  data/range.h
  renderer/chartrenderer.h
  renderer/xychartrenderer.h
  axis/axis.h
  axis/numericaxis.h
  axis/tick.h
)


install(TARGETS chartwx
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# # manually install files to maintain directory hierachy!
# # from cmake 3.23 on, this could be done using FILE_SETS in target_sources
# install(FILES
#   ${headers} imca.h
#   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/imcacore
# )

# pkg-config file
if (UNIX)
  configure_file(libchartwx.pc.in ${CMAKE_CURRENT_BINARY_DIR}/libchartwx.pc)
  install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/libchartwx.pc
    DESTINATION
      ${CMAKE_INSTALL_LIBDIR}/pkgconfig
    COMPONENT
      pkgconfig
  )
endif (UNIX)

