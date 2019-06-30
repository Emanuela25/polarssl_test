# Install script for directory: /home/grace/Desktop/polarssl_test/mbedtls/crypto/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/memory_buffer_alloc.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/chacha20.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/pk_internal.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/platform_time.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/base64.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/camellia.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/cipher_internal.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/cmac.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ecdh.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/compat-1.3.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/dhm.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/rsa_internal.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/version.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ecjpake.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/aria.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/pkcs5.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/havege.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/error.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/md.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/pk.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ecp_internal.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/asn1.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/aes.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/nist_kw.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/bn_mul.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/padlock.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/certs.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/platform.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/xtea.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/check_config.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ccm.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/sha1.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/gcm.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ecp.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/sha512.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/oid.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/des.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/pkcs12.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/asn1write.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/timing.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/psa_util.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/entropy_poll.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/cipher.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/pem.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/md_internal.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/blowfish.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/aesni.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/md5.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/config.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ecdsa.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/md2.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/hkdf.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/entropy.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/hmac_drbg.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/md4.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/chachapoly.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/rsa.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/arc4.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/poly1305.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ctr_drbg.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/threading.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/sha256.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/platform_util.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/ripemd160.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/mbedtls/bignum.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_sizes.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_driver_common.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_platform.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_se_driver.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_accel_driver.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_types.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_values.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_extra.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_struct.h"
    "/home/grace/Desktop/polarssl_test/mbedtls/crypto/include/psa/crypto_entropy_driver.h"
    )
endif()

