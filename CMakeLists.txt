cmake_minimum_required(VERSION 3.9)
project(Encrypted_p2p)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        messageHandler.cpp
        messageHandler.h messageEncryption.h)


find_package(OpenSSL REQUIRED)
if (OPENSSL_FOUND)
    set(OPENSSL_USE_STATIC_LIBS TRUE)
endif ()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
