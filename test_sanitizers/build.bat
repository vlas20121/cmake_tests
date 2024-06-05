mkdir %BUILD_DIR%
cd %BUILD_DIR%
::-DCMAKE_INSTALL_PREFIX="G:\MyProjects\c++\extra\tinynurbs\"
cmake .. -G %toolset% -DBUILD_TYPE=%BUILD_TYPE% .. > 1.log 2>&1
cmake --build . --config %BUILD_TYPE% > 2.log 2>&1
::setx bezier_DIR "G:\MyProjects\c++\extra\bezier\"
