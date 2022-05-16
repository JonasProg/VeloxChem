set(CPACK_PACKAGE_NAME "veloxchem")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "veloxchem")
set(CPACK_PACKAGE_VENDOR "VeloxChem developers")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_SOURCE_DIR}/README.rst")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "VeloxChem: an electronic structure code")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_CHECKSUM SHA256)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

list(APPEND _to_ignore
  ${PROJECT_BINARY_DIR}
  "/\.git/"
  "\.gitignore"
  "/config/"
  "Makefile*"
  "/build*/"
  "/nix/"
  "shell.nix"
  "poetry.lock"
  "primitive_scf.py"
  "todo.org"
  "/\.ccls-cache/"
  "/\.pytest_cache/"
  "__pycache__"
  "[A-Za-z0-9_]*\.[ado]$"
  )
set(CPACK_SOURCE_IGNORE_FILES
  ${_to_ignore}
  )
set(CPACK_SOURCE_GENERATOR "TBZ2")
set(CPACK_GENERATOR "TBZ2")

include(CPack)
