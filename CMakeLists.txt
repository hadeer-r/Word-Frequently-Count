cmake_minimum_required(VERSION 3.16)

project(Word_Frequently_Count VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appWord_Frequently_Count
    src/main.cpp
    src/BST/binary_search_tree.cpp src/BST/binary_search_tree.hpp
    src/manageText/upload_text.cpp src/manageText/upload_text.hpp
    src/manageWords/Words.cpp src/manageWords/Words.hpp
    src/manageWords/trie.cpp src/manageWords/trie.h
    src/manageWords/checker.cpp src/manageWords/checker.h
    src/manager/manager.cpp src/manager/manager.h

)
target_include_directories(appWord_Frequently_Count PUBLIC
    src/BST/
)
target_include_directories(appWord_Frequently_Count PUBLIC
    src/mangeText/
)
target_include_directories(appWord_Frequently_Count PUBLIC
    src/manageWords/
)
target_include_directories(appWord_Frequently_Count PUBLIC

    src/manageWords/
)
target_include_directories(appWord_Frequently_Count PUBLIC
    src/mangeText/
)
target_include_directories(appWord_Frequently_Count PUBLIC
    src/BST/
)
target_include_directories(appWord_Frequently_Count PUBLIC
    src/
)
if(QT_KNOWN_POLICY_QTP0001)
    qt_policy(SET QTP0001 OLD)
endif()

qt_add_qml_module(appWord_Frequently_Count
    URI Word_Frequently_Count
    VERSION 1.0
    QML_FILES qml/main.qml
    SOURCES src/backend.h src/backend.cpp
    RESOURCES
    qrc/SearchWord.png
    qrc/Path.png
    qrc/submit.png
    qrc/Vector.png
    qrc/right.png
    qrc/left.png
)
# configure_file(file.txt file.txt COPYONLY)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appWord_Frequently_Count PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appWord_Frequently_Count
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appWord_Frequently_Count
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appWord_Frequently_Count
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
