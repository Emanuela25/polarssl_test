#line 2 "suites/main_test.function"
/*
 * *** THIS FILE HAS BEEN MACHINE GENERATED ***
 *
 * This file has been machine generated using the script:
 * generate_test_code.py
 *
 * Test file      : ./test_suite_ssl.c
 *
 * The following files were used to create this file.
 *
 *      Main code file      : /home/grace/Desktop/polarssl_test/mbedtls/tests/suites/main_test.function
 *      Platform code file  : /home/grace/Desktop/polarssl_test/mbedtls/tests/suites/host_test.function
 *      Helper file         : /home/grace/Desktop/polarssl_test/mbedtls/tests/suites/helpers.function
 *      Test suite file     : /home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function
 *      Test suite data     : /home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.data
 *
 *
 *  This file is part of Mbed TLS (https://tls.mbed.org)
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include <mbedtls/config.h>
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_USE_PSA_CRYPTO)
#include "psa/crypto.h"
#endif /* MBEDTLS_USE_PSA_CRYPTO */

/*----------------------------------------------------------------------------*/
/* Common helper code */

#line 2 "suites/helpers.function"
/*----------------------------------------------------------------------------*/
/* Headers */

#include <stdlib.h>

#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_fprintf    fprintf
#define mbedtls_snprintf   snprintf
#define mbedtls_calloc     calloc
#define mbedtls_free       free
#define mbedtls_exit       exit
#define mbedtls_time       time
#define mbedtls_time_t     time_t
#define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif

#if defined(MBEDTLS_CHECK_PARAMS)
#include "mbedtls/platform_util.h"
#include <setjmp.h>
#endif

#ifdef _MSC_VER
#include <basetsd.h>
typedef UINT8 uint8_t;
typedef INT32 int32_t;
typedef UINT32 uint32_t;
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#else
#include <stdint.h>
#endif

#include <string.h>

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#include <strings.h>
#endif

/* Type for Hex parameters */
typedef struct data_tag
{
    uint8_t *   x;
    uint32_t    len;
} data_t;

/*----------------------------------------------------------------------------*/
/* Status and error constants */

#define DEPENDENCY_SUPPORTED            0   /* Dependency supported by build */
#define KEY_VALUE_MAPPING_FOUND         0   /* Integer expression found */
#define DISPATCH_TEST_SUCCESS           0   /* Test dispatch successful */

#define KEY_VALUE_MAPPING_NOT_FOUND     -1  /* Integer expression not found */
#define DEPENDENCY_NOT_SUPPORTED        -2  /* Dependency not supported */
#define DISPATCH_TEST_FN_NOT_FOUND      -3  /* Test function not found */
#define DISPATCH_INVALID_TEST_DATA      -4  /* Invalid test parameter type.
                                               Only int, string, binary data
                                               and integer expressions are
                                               allowed */
#define DISPATCH_UNSUPPORTED_SUITE      -5  /* Test suite not supported by the
                                               build */

typedef enum
{
    PARAMFAIL_TESTSTATE_IDLE = 0,           /* No parameter failure call test */
    PARAMFAIL_TESTSTATE_PENDING,            /* Test call to the parameter failure
                                             * is pending */
    PARAMFAIL_TESTSTATE_CALLED              /* The test call to the parameter
                                             * failure function has been made */
} paramfail_test_state_t;


/*----------------------------------------------------------------------------*/
/* Macros */

/**
 * \brief   This macro tests the expression passed to it as a test step or
 *          individual test in a test case.
 *
 *          It allows a library function to return a value and return an error
 *          code that can be tested.
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), will be assumed to be a test
 *          failure.
 *
 *          This macro is not suitable for negative parameter validation tests,
 *          as it assumes the test step will not create an error.
 *
 *          Failing the test means:
 *          - Mark this test case as failed.
 *          - Print a message identifying the failure.
 *          - Jump to the \c exit label.
 *
 *          This macro expands to an instruction, not an expression.
 *          It may jump to the \c exit label.
 *
 * \param   TEST    The test expression to be tested.
 */
#define TEST_ASSERT( TEST )                                 \
    do {                                                    \
       if( ! (TEST) )                                       \
       {                                                    \
          test_fail( #TEST, __LINE__, __FILE__ );           \
          goto exit;                                        \
       }                                                    \
    } while( 0 )

#if defined(MBEDTLS_CHECK_PARAMS) && !defined(MBEDTLS_PARAM_FAILED_ALT)
/**
 * \brief   This macro tests the statement passed to it as a test step or
 *          individual test in a test case. The macro assumes the test will fail
 *          and will generate an error.
 *
 *          It allows a library function to return a value and tests the return
 *          code on return to confirm the given error code was returned.
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), are assumed to indicate the
 *          expected failure, and the test will pass.
 *
 *          This macro is intended for negative parameter validation tests,
 *          where the failing function may return an error value or call
 *          MBEDTLS_PARAM_FAILED() to indicate the error.
 *
 * \param   PARAM_ERROR_VALUE   The expected error code.
 *
 * \param   TEST                The test expression to be tested.
 */
#define TEST_INVALID_PARAM_RET( PARAM_ERR_VALUE, TEST )                     \
    do {                                                                    \
        test_info.paramfail_test_state = PARAMFAIL_TESTSTATE_PENDING;       \
        if( (TEST) != (PARAM_ERR_VALUE) ||                                  \
            test_info.paramfail_test_state != PARAMFAIL_TESTSTATE_CALLED )  \
        {                                                                   \
            test_fail( #TEST, __LINE__, __FILE__ );                         \
            goto exit;                                                      \
        }                                                                   \
   } while( 0 )

/**
 * \brief   This macro tests the statement passed to it as a test step or
 *          individual test in a test case. The macro assumes the test will fail
 *          and will generate an error.
 *
 *          It assumes the library function under test cannot return a value and
 *          assumes errors can only be indicated byt calls to
 *          MBEDTLS_PARAM_FAILED().
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), are assumed to indicate the
 *          expected failure. If MBEDTLS_CHECK_PARAMS is not enabled, no test
 *          can be made.
 *
 *          This macro is intended for negative parameter validation tests,
 *          where the failing function can only return an error by calling
 *          MBEDTLS_PARAM_FAILED() to indicate the error.
 *
 * \param   TEST                The test expression to be tested.
 */
#define TEST_INVALID_PARAM( TEST )                                          \
    do {                                                                    \
        memcpy(jmp_tmp, param_fail_jmp, sizeof(jmp_buf));                   \
        if( setjmp( param_fail_jmp ) == 0 )                                 \
        {                                                                   \
            TEST;                                                           \
            test_fail( #TEST, __LINE__, __FILE__ );                         \
            goto exit;                                                      \
        }                                                                   \
        memcpy(param_fail_jmp, jmp_tmp, sizeof(jmp_buf));                   \
    } while( 0 )
#endif /* MBEDTLS_CHECK_PARAMS && !MBEDTLS_PARAM_FAILED_ALT */

/**
 * \brief   This macro tests the statement passed to it as a test step or
 *          individual test in a test case. The macro assumes the test will not fail.
 *
 *          It assumes the library function under test cannot return a value and
 *          assumes errors can only be indicated by calls to
 *          MBEDTLS_PARAM_FAILED().
 *
 *          When MBEDTLS_CHECK_PARAMS is enabled, calls to the parameter failure
 *          callback, MBEDTLS_PARAM_FAILED(), are assumed to indicate the
 *          expected failure. If MBEDTLS_CHECK_PARAMS is not enabled, no test
 *          can be made.
 *
 *          This macro is intended to test that functions returning void
 *          accept all of the parameter values they're supposed to accept - eg
 *          that they don't call MBEDTLS_PARAM_FAILED() when a parameter
 *          that's allowed to be NULL happens to be NULL.
 *
 *          Note: for functions that return something other that void,
 *          checking that they accept all the parameters they're supposed to
 *          accept is best done by using TEST_ASSERT() and checking the return
 *          value as well.
 *
 *          Note: this macro is available even when #MBEDTLS_CHECK_PARAMS is
 *          disabled, as it makes sense to check that the functions accept all
 *          legal values even if this option is disabled - only in that case,
 *          the test is more about whether the function segfaults than about
 *          whether it invokes MBEDTLS_PARAM_FAILED().
 *
 * \param   TEST                The test expression to be tested.
 */
#define TEST_VALID_PARAM( TEST )                                    \
    TEST_ASSERT( ( TEST, 1 ) );

#define TEST_HELPER_ASSERT(a) if( !( a ) )                                      \
{                                                                   \
    mbedtls_fprintf( stderr, "Assertion Failed at %s:%d - %s\n",   \
                             __FILE__, __LINE__, #a );              \
    mbedtls_exit( 1 );                                             \
}

/*
 * 32-bit integer manipulation macros (big endian)
 */
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i)                            \
{                                                       \
    (n) = ( (uint32_t) (b)[(i)    ] << 24 )             \
        | ( (uint32_t) (b)[(i) + 1] << 16 )             \
        | ( (uint32_t) (b)[(i) + 2] <<  8 )             \
        | ( (uint32_t) (b)[(i) + 3]       );            \
}
#endif

#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i)                            \
{                                                       \
    (b)[(i)    ] = (unsigned char) ( (n) >> 24 );       \
    (b)[(i) + 1] = (unsigned char) ( (n) >> 16 );       \
    (b)[(i) + 2] = (unsigned char) ( (n) >>  8 );       \
    (b)[(i) + 3] = (unsigned char) ( (n)       );       \
}
#endif


/*----------------------------------------------------------------------------*/
/* Global variables */

static struct
{
    paramfail_test_state_t paramfail_test_state;
    int failed;
    const char *test;
    const char *filename;
    int line_no;
}
test_info;

#if defined(MBEDTLS_PLATFORM_C)
mbedtls_platform_context platform_ctx;
#endif

#if defined(MBEDTLS_CHECK_PARAMS)
jmp_buf param_fail_jmp;
jmp_buf jmp_tmp;
#endif

/*----------------------------------------------------------------------------*/
/* Helper flags for complex dependencies */

/* Indicates whether we expect mbedtls_entropy_init
 * to initialize some strong entropy source. */
#if defined(MBEDTLS_TEST_NULL_ENTROPY) ||             \
    ( !defined(MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES) && \
      ( !defined(MBEDTLS_NO_PLATFORM_ENTROPY)  ||     \
         defined(MBEDTLS_HAVEGE_C)             ||     \
         defined(MBEDTLS_ENTROPY_HARDWARE_ALT) ||     \
         defined(ENTROPY_NV_SEED) ) )
#define ENTROPY_HAVE_STRONG
#endif


/*----------------------------------------------------------------------------*/
/* Helper Functions */

void test_fail( const char *test, int line_no, const char* filename )
{
    test_info.failed = 1;
    test_info.test = test;
    test_info.line_no = line_no;
    test_info.filename = filename;
}

static int platform_setup()
{
    int ret = 0;
#if defined(MBEDTLS_PLATFORM_C)
    ret = mbedtls_platform_setup( &platform_ctx );
#endif /* MBEDTLS_PLATFORM_C */
    return( ret );
}

static void platform_teardown()
{
#if defined(MBEDTLS_PLATFORM_C)
    mbedtls_platform_teardown( &platform_ctx );
#endif /* MBEDTLS_PLATFORM_C */
}

#if defined(MBEDTLS_CHECK_PARAMS)
void mbedtls_param_failed( const char *failure_condition,
                           const char *file,
                           int line )
{
    /* If we are testing the callback function...  */
    if( test_info.paramfail_test_state == PARAMFAIL_TESTSTATE_PENDING )
    {
        test_info.paramfail_test_state = PARAMFAIL_TESTSTATE_CALLED;
    }
    else
    {
        /* ...else we treat this as an error */

        /* Record the location of the failure, but not as a failure yet, in case
         * it was part of the test */
        test_fail( failure_condition, line, file );
        test_info.failed = 0;

        longjmp( param_fail_jmp, 1 );
    }
}
#endif

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
static int redirect_output( FILE** out_stream, const char* path )
{
    int stdout_fd = dup( fileno( *out_stream ) );

    if( stdout_fd == -1 )
    {
        return -1;
    }

    fflush( *out_stream );
    fclose( *out_stream );
    *out_stream = fopen( path, "w" );

    if( *out_stream == NULL )
    {
        close( stdout_fd );
        return -1;
    }

    return stdout_fd;
}

static int restore_output( FILE** out_stream, int old_fd )
{
    fflush( *out_stream );
    fclose( *out_stream );

    *out_stream = fdopen( old_fd, "w" );
    if( *out_stream == NULL )
    {
        return -1;
    }

    return 0;
}

static void close_output( FILE* out_stream )
{
    fclose( out_stream );
}
#endif /* __unix__ || __APPLE__ __MACH__ */

int unhexify( unsigned char *obuf, const char *ibuf )
{
    unsigned char c, c2;
    int len = strlen( ibuf ) / 2;
    TEST_HELPER_ASSERT( strlen( ibuf ) % 2 == 0 ); /* must be even number of bytes */

    while( *ibuf != 0 )
    {
        c = *ibuf++;
        if( c >= '0' && c <= '9' )
            c -= '0';
        else if( c >= 'a' && c <= 'f' )
            c -= 'a' - 10;
        else if( c >= 'A' && c <= 'F' )
            c -= 'A' - 10;
        else
            TEST_HELPER_ASSERT( 0 );

        c2 = *ibuf++;
        if( c2 >= '0' && c2 <= '9' )
            c2 -= '0';
        else if( c2 >= 'a' && c2 <= 'f' )
            c2 -= 'a' - 10;
        else if( c2 >= 'A' && c2 <= 'F' )
            c2 -= 'A' - 10;
        else
            TEST_HELPER_ASSERT( 0 );

        *obuf++ = ( c << 4 ) | c2;
    }

    return len;
}

void hexify( unsigned char *obuf, const unsigned char *ibuf, int len )
{
    unsigned char l, h;

    while( len != 0 )
    {
        h = *ibuf / 16;
        l = *ibuf % 16;

        if( h < 10 )
            *obuf++ = '0' + h;
        else
            *obuf++ = 'a' + h - 10;

        if( l < 10 )
            *obuf++ = '0' + l;
        else
            *obuf++ = 'a' + l - 10;

        ++ibuf;
        len--;
    }
}

/**
 * Allocate and zeroize a buffer.
 *
 * If the size if zero, a pointer to a zeroized 1-byte buffer is returned.
 *
 * For convenience, dies if allocation fails.
 */
static unsigned char *zero_alloc( size_t len )
{
    void *p;
    size_t actual_len = ( len != 0 ) ? len : 1;

    p = mbedtls_calloc( 1, actual_len );
    TEST_HELPER_ASSERT( p != NULL );

    memset( p, 0x00, actual_len );

    return( p );
}

/**
 * Allocate and fill a buffer from hex data.
 *
 * The buffer is sized exactly as needed. This allows to detect buffer
 * overruns (including overreads) when running the test suite under valgrind.
 *
 * If the size if zero, a pointer to a zeroized 1-byte buffer is returned.
 *
 * For convenience, dies if allocation fails.
 */
unsigned char *unhexify_alloc( const char *ibuf, size_t *olen )
{
    unsigned char *obuf;

    *olen = strlen( ibuf ) / 2;

    if( *olen == 0 )
        return( zero_alloc( *olen ) );

    obuf = mbedtls_calloc( 1, *olen );
    TEST_HELPER_ASSERT( obuf != NULL );

    (void) unhexify( obuf, ibuf );

    return( obuf );
}

/**
 * This function just returns data from rand().
 * Although predictable and often similar on multiple
 * runs, this does not result in identical random on
 * each run. So do not use this if the results of a
 * test depend on the random data that is generated.
 *
 * rng_state shall be NULL.
 */
static int rnd_std_rand( void *rng_state, unsigned char *output, size_t len )
{
#if !defined(__OpenBSD__)
    size_t i;

    if( rng_state != NULL )
        rng_state  = NULL;

    for( i = 0; i < len; ++i )
        output[i] = rand();
#else
    if( rng_state != NULL )
        rng_state = NULL;

    arc4random_buf( output, len );
#endif /* !OpenBSD */

    return( 0 );
}

/**
 * This function only returns zeros
 *
 * rng_state shall be NULL.
 */
int rnd_zero_rand( void *rng_state, unsigned char *output, size_t len )
{
    if( rng_state != NULL )
        rng_state  = NULL;

    memset( output, 0, len );

    return( 0 );
}

typedef struct
{
    unsigned char *buf;
    size_t length;
} rnd_buf_info;

/**
 * This function returns random based on a buffer it receives.
 *
 * rng_state shall be a pointer to a rnd_buf_info structure.
 *
 * The number of bytes released from the buffer on each call to
 * the random function is specified by per_call. (Can be between
 * 1 and 4)
 *
 * After the buffer is empty it will return rand();
 */
int rnd_buffer_rand( void *rng_state, unsigned char *output, size_t len )
{
    rnd_buf_info *info = (rnd_buf_info *) rng_state;
    size_t use_len;

    if( rng_state == NULL )
        return( rnd_std_rand( NULL, output, len ) );

    use_len = len;
    if( len > info->length )
        use_len = info->length;

    if( use_len )
    {
        memcpy( output, info->buf, use_len );
        info->buf += use_len;
        info->length -= use_len;
    }

    if( len - use_len > 0 )
        return( rnd_std_rand( NULL, output + use_len, len - use_len ) );

    return( 0 );
}

/**
 * Info structure for the pseudo random function
 *
 * Key should be set at the start to a test-unique value.
 * Do not forget endianness!
 * State( v0, v1 ) should be set to zero.
 */
typedef struct
{
    uint32_t key[16];
    uint32_t v0, v1;
} rnd_pseudo_info;

/**
 * This function returns random based on a pseudo random function.
 * This means the results should be identical on all systems.
 * Pseudo random is based on the XTEA encryption algorithm to
 * generate pseudorandom.
 *
 * rng_state shall be a pointer to a rnd_pseudo_info structure.
 */
int rnd_pseudo_rand( void *rng_state, unsigned char *output, size_t len )
{
    rnd_pseudo_info *info = (rnd_pseudo_info *) rng_state;
    uint32_t i, *k, sum, delta=0x9E3779B9;
    unsigned char result[4], *out = output;

    if( rng_state == NULL )
        return( rnd_std_rand( NULL, output, len ) );

    k = info->key;

    while( len > 0 )
    {
        size_t use_len = ( len > 4 ) ? 4 : len;
        sum = 0;

        for( i = 0; i < 32; i++ )
        {
            info->v0 += ( ( ( info->v1 << 4 ) ^ ( info->v1 >> 5 ) )
                            + info->v1 ) ^ ( sum + k[sum & 3] );
            sum += delta;
            info->v1 += ( ( ( info->v0 << 4 ) ^ ( info->v0 >> 5 ) )
                            + info->v0 ) ^ ( sum + k[( sum>>11 ) & 3] );
        }

        PUT_UINT32_BE( info->v0, result, 0 );
        memcpy( out, result, use_len );
        len -= use_len;
        out += 4;
    }

    return( 0 );
}

int hexcmp( uint8_t * a, uint8_t * b, uint32_t a_len, uint32_t b_len )
{
    int ret = 0;
    uint32_t i = 0;

    if( a_len != b_len )
        return( -1 );

    for( i = 0; i < a_len; i++ )
    {
        if( a[i] != b[i] )
        {
            ret = -1;
            break;
        }
    }
    return ret;
}


#line 38 "suites/main_test.function"


/*----------------------------------------------------------------------------*/
/* Test Suite Code */


#define TEST_SUITE_ACTIVE

#if defined(MBEDTLS_SSL_TLS_C)
#line 2 "/home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function"
#include <mbedtls/ssl.h>
#include <mbedtls/ssl_internal.h>

/*
 * Helper function setting up inverse record transformations
 * using given cipher, hash, EtM mode, authentication tag length,
 * and version.
 */

#define CHK( x )                                \
    do                                          \
    {                                           \
        if( !( x ) )                            \
        {                                       \
            ret = -1;                           \
            goto cleanup;                       \
        }                                       \
    } while( 0 )

#if MBEDTLS_SSL_CID_OUT_LEN_MAX > MBEDTLS_SSL_CID_IN_LEN_MAX
#define SSL_CID_LEN_MIN MBEDTLS_SSL_CID_IN_LEN_MAX
#else
#define SSL_CID_LEN_MIN MBEDTLS_SSL_CID_OUT_LEN_MAX
#endif

static int build_transforms( mbedtls_ssl_transform *t_in,
                             mbedtls_ssl_transform *t_out,
                             int cipher_type, int hash_id,
                             int etm, int tag_mode, int ver,
                             size_t cid0_len,
                             size_t cid1_len )
{
    mbedtls_cipher_info_t const *cipher_info;
    int ret = 0;

    size_t keylen, maclen, ivlen;
    unsigned char *key0 = NULL, *key1 = NULL;
    unsigned char iv_enc[16], iv_dec[16];

#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
    unsigned char cid0[ SSL_CID_LEN_MIN ];
    unsigned char cid1[ SSL_CID_LEN_MIN ];

    rnd_std_rand( NULL, cid0, sizeof( cid0 ) );
    rnd_std_rand( NULL, cid1, sizeof( cid1 ) );
#else
    ((void) cid0_len);
    ((void) cid1_len);
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

    maclen = 0;

    /* Pick cipher */
    cipher_info = mbedtls_cipher_info_from_type( cipher_type );
    CHK( cipher_info != NULL );
    CHK( cipher_info->iv_size <= 16 );
    CHK( cipher_info->key_bitlen % 8 == 0 );

    /* Pick keys */
    keylen = cipher_info->key_bitlen / 8;
    /* Allocate `keylen + 1` bytes to ensure that we get
     * a non-NULL pointers from `mbedtls_calloc` even if
     * `keylen == 0` in the case of the NULL cipher. */
    CHK( ( key0 = mbedtls_calloc( 1, keylen + 1 ) ) != NULL );
    CHK( ( key1 = mbedtls_calloc( 1, keylen + 1 ) ) != NULL );
    memset( key0, 0x1, keylen );
    memset( key1, 0x2, keylen );

    /* Setup cipher contexts */
    CHK( mbedtls_cipher_setup( &t_in->cipher_ctx_enc,  cipher_info ) == 0 );
    CHK( mbedtls_cipher_setup( &t_in->cipher_ctx_dec,  cipher_info ) == 0 );
    CHK( mbedtls_cipher_setup( &t_out->cipher_ctx_enc, cipher_info ) == 0 );
    CHK( mbedtls_cipher_setup( &t_out->cipher_ctx_dec, cipher_info ) == 0 );

#if defined(MBEDTLS_CIPHER_MODE_CBC)
    if( cipher_info->mode == MBEDTLS_MODE_CBC )
    {
        CHK( mbedtls_cipher_set_padding_mode( &t_in->cipher_ctx_enc,
                                              MBEDTLS_PADDING_NONE ) == 0 );
        CHK( mbedtls_cipher_set_padding_mode( &t_in->cipher_ctx_dec,
                                              MBEDTLS_PADDING_NONE ) == 0 );
        CHK( mbedtls_cipher_set_padding_mode( &t_out->cipher_ctx_enc,
                                              MBEDTLS_PADDING_NONE ) == 0 );
        CHK( mbedtls_cipher_set_padding_mode( &t_out->cipher_ctx_dec,
                                              MBEDTLS_PADDING_NONE ) == 0 );
    }
#endif /* MBEDTLS_CIPHER_MODE_CBC */

    CHK( mbedtls_cipher_setkey( &t_in->cipher_ctx_enc, key0,
                                keylen << 3, MBEDTLS_ENCRYPT ) == 0 );
    CHK( mbedtls_cipher_setkey( &t_in->cipher_ctx_dec, key1,
                                keylen << 3, MBEDTLS_DECRYPT ) == 0 );
    CHK( mbedtls_cipher_setkey( &t_out->cipher_ctx_enc, key1,
                                keylen << 3, MBEDTLS_ENCRYPT ) == 0 );
    CHK( mbedtls_cipher_setkey( &t_out->cipher_ctx_dec, key0,
                                keylen << 3, MBEDTLS_DECRYPT ) == 0 );

    /* Setup MAC contexts */
#if defined(MBEDTLS_SSL_SOME_MODES_USE_MAC)
    if( cipher_info->mode == MBEDTLS_MODE_CBC ||
        cipher_info->mode == MBEDTLS_MODE_STREAM )
    {
        mbedtls_md_info_t const *md_info;
        unsigned char *md0, *md1;

        /* Pick hash */
        md_info = mbedtls_md_info_from_type( hash_id );
        CHK( md_info != NULL );

        /* Pick hash keys */
        maclen = mbedtls_md_get_size( md_info );
        CHK( ( md0 = mbedtls_calloc( 1, maclen ) ) != NULL );
        CHK( ( md1 = mbedtls_calloc( 1, maclen ) ) != NULL );
        memset( md0, 0x5, maclen );
        memset( md1, 0x6, maclen );

        CHK( mbedtls_md_setup( &t_out->md_ctx_enc, md_info, 1 ) == 0 );
        CHK( mbedtls_md_setup( &t_out->md_ctx_dec, md_info, 1 ) == 0 );
        CHK( mbedtls_md_setup( &t_in->md_ctx_enc,  md_info, 1 ) == 0 );
        CHK( mbedtls_md_setup( &t_in->md_ctx_dec,  md_info, 1 ) == 0 );

        if( ver > MBEDTLS_SSL_MINOR_VERSION_0 )
        {
            CHK( mbedtls_md_hmac_starts( &t_in->md_ctx_enc,
                                         md0, maclen ) == 0 );
            CHK( mbedtls_md_hmac_starts( &t_in->md_ctx_dec,
                                         md1, maclen ) == 0 );
            CHK( mbedtls_md_hmac_starts( &t_out->md_ctx_enc,
                                         md1, maclen ) == 0 );
            CHK( mbedtls_md_hmac_starts( &t_out->md_ctx_dec,
                                         md0, maclen ) == 0 );
        }
#if defined(MBEDTLS_SSL_PROTO_SSL3)
        else
        {
            memcpy( &t_in->mac_enc, md0, maclen );
            memcpy( &t_in->mac_dec, md1, maclen );
            memcpy( &t_out->mac_enc, md1, maclen );
            memcpy( &t_out->mac_dec, md0, maclen );
        }
#endif

        mbedtls_free( md0 );
        mbedtls_free( md1 );
    }
#else
    ((void) hash_id);
#endif /* MBEDTLS_SSL_SOME_MODES_USE_MAC */


    /* Pick IV's (regardless of whether they
     * are being used by the transform). */
    ivlen = cipher_info->iv_size;
    memset( iv_enc, 0x3, sizeof( iv_enc ) );
    memset( iv_dec, 0x4, sizeof( iv_dec ) );

    /*
     * Setup transforms
     */

#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC) && \
    defined(MBEDTLS_SSL_SOME_MODES_USE_MAC)
    t_out->encrypt_then_mac = etm;
    t_in->encrypt_then_mac = etm;
#else
    ((void) etm);
#endif

    t_out->minor_ver = ver;
    t_in->minor_ver = ver;
    t_out->ivlen = ivlen;
    t_in->ivlen = ivlen;

    switch( cipher_info->mode )
    {
        case MBEDTLS_MODE_GCM:
        case MBEDTLS_MODE_CCM:
            t_out->fixed_ivlen = 4;
            t_in->fixed_ivlen = 4;
            t_out->maclen = 0;
            t_in->maclen = 0;
            switch( tag_mode )
            {
                case 0: /* Full tag */
                    t_out->taglen = 16;
                    t_in->taglen = 16;
                    break;
                case 1: /* Partial tag */
                    t_out->taglen = 8;
                    t_in->taglen = 8;
                    break;
                default:
                    return( 1 );
            }
            break;

        case MBEDTLS_MODE_CHACHAPOLY:
            t_out->fixed_ivlen = 12;
            t_in->fixed_ivlen = 12;
            t_out->maclen = 0;
            t_in->maclen = 0;
            switch( tag_mode )
            {
                case 0: /* Full tag */
                    t_out->taglen = 16;
                    t_in->taglen = 16;
                    break;
                case 1: /* Partial tag */
                    t_out->taglen = 8;
                    t_in->taglen = 8;
                    break;
                default:
                    return( 1 );
            }
            break;

        case MBEDTLS_MODE_STREAM:
        case MBEDTLS_MODE_CBC:
            t_out->fixed_ivlen = 0; /* redundant, must be 0 */
            t_in->fixed_ivlen = 0;  /* redundant, must be 0 */
            t_out->taglen = 0;
            t_in->taglen = 0;
            switch( tag_mode )
            {
                case 0: /* Full tag */
                    t_out->maclen = maclen;
                    t_in->maclen = maclen;
                    break;
                case 1: /* Partial tag */
                    t_out->maclen = 10;
                    t_in->maclen = 10;
                    break;
                default:
                    return( 1 );
            }
            break;
        default:
            return( 1 );
            break;
    }

    /* Setup IV's */

    memcpy( &t_in->iv_dec, iv_dec, sizeof( iv_dec ) );
    memcpy( &t_in->iv_enc, iv_enc, sizeof( iv_enc ) );
    memcpy( &t_out->iv_dec, iv_enc, sizeof( iv_enc ) );
    memcpy( &t_out->iv_enc, iv_dec, sizeof( iv_dec ) );

#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
    /* Add CID */
    memcpy( &t_in->in_cid,  cid0, cid0_len );
    memcpy( &t_in->out_cid, cid1, cid1_len );
    t_in->in_cid_len = cid0_len;
    t_in->out_cid_len = cid1_len;
    memcpy( &t_out->in_cid,  cid1, cid1_len );
    memcpy( &t_out->out_cid, cid0, cid0_len );
    t_out->in_cid_len = cid1_len;
    t_out->out_cid_len = cid0_len;
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

cleanup:

    mbedtls_free( key0 );
    mbedtls_free( key1 );

    return( ret );
}

#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#line 278 "/home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_dtls_replay( data_t * prevs, data_t * new, int ret )
{
    uint32_t len = 0;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;

    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_config_init( &conf );

    TEST_ASSERT( mbedtls_ssl_config_defaults( &conf,
                 MBEDTLS_SSL_IS_CLIENT,
                 MBEDTLS_SSL_TRANSPORT_DATAGRAM,
                 MBEDTLS_SSL_PRESET_DEFAULT ) == 0 );
    TEST_ASSERT( mbedtls_ssl_setup( &ssl, &conf ) == 0 );

    /* Read previous record numbers */
    for( len = 0; len < prevs->len; len += 6 )
    {
        memcpy( ssl.in_ctr + 2, prevs->x + len, 6 );
        mbedtls_ssl_dtls_replay_update( &ssl );
    }

    /* Check new number */
    memcpy( ssl.in_ctr + 2, new->x, 6 );
    TEST_ASSERT( mbedtls_ssl_dtls_replay_check( &ssl ) == ret );

    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_config_free( &conf );
exit:
    ;
}

void test_ssl_dtls_replay_wrapper( void ** params )
{
    data_t data0 = {(uint8_t *) params[0], *( (uint32_t *) params[1] )};
    data_t data2 = {(uint8_t *) params[2], *( (uint32_t *) params[3] )};

    test_ssl_dtls_replay( &data0, &data2, *( (int *) params[4] ) );
}
#endif /* MBEDTLS_SSL_DTLS_ANTI_REPLAY */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#line 310 "/home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_set_hostname_twice( char *hostname0, char *hostname1 )
{
    mbedtls_ssl_context ssl;
    mbedtls_ssl_init( &ssl );

    TEST_ASSERT( mbedtls_ssl_set_hostname( &ssl, hostname0 ) == 0 );
    TEST_ASSERT( mbedtls_ssl_set_hostname( &ssl, hostname1 ) == 0 );

    mbedtls_ssl_free( &ssl );
exit:
    ;
}

void test_ssl_set_hostname_twice_wrapper( void ** params )
{

    test_ssl_set_hostname_twice( (char *) params[0], (char *) params[1] );
}
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#line 323 "/home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_crypt_record( int cipher_type, int hash_id,
                       int etm, int tag_mode, int ver,
                       int cid0_len, int cid1_len )
{
    /*
     * Test several record encryptions and decryptions
     * with plenty of space before and after the data
     * within the record buffer.
     */

    int ret;
    int num_records = 16;
    mbedtls_ssl_context ssl; /* ONLY for debugging */

    mbedtls_ssl_transform t0, t1;
    unsigned char *buf = NULL;
    size_t const buflen = 512;
    mbedtls_record rec, rec_backup;

    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_transform_init( &t0 );
    mbedtls_ssl_transform_init( &t1 );
    TEST_ASSERT( build_transforms( &t0, &t1, cipher_type, hash_id,
                                   etm, tag_mode, ver,
                                   (size_t) cid0_len,
                                   (size_t) cid1_len ) == 0 );

    TEST_ASSERT( ( buf = mbedtls_calloc( 1, buflen ) ) != NULL );

    while( num_records-- > 0 )
    {
        mbedtls_ssl_transform *t_dec, *t_enc;
        /* Take turns in who's sending and who's receiving. */
        if( num_records % 3 == 0 )
        {
            t_dec = &t0;
            t_enc = &t1;
        }
        else
        {
            t_dec = &t1;
            t_enc = &t0;
        }

        /*
         * The record header affects the transformation in two ways:
         * 1) It determines the AEAD additional data
         * 2) The record counter sometimes determines the IV.
         *
         * Apart from that, the fields don't have influence.
         * In particular, it is currently not the responsibility
         * of ssl_encrypt/decrypt_buf to check if the transform
         * version matches the record version, or that the
         * type is sensible.
         */

        memset( rec.ctr, num_records, sizeof( rec.ctr ) );
        rec.type    = 42;
        rec.ver[0]  = num_records;
        rec.ver[1]  = num_records;
#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
        rec.cid_len = 0;
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

        rec.buf     = buf;
        rec.buf_len = buflen;
        rec.data_offset = 16;
        /* Make sure to vary the length to exercise different
         * paddings. */
        rec.data_len = 1 + num_records;

        memset( rec.buf + rec.data_offset, 42, rec.data_len );

        /* Make a copy for later comparison */
        rec_backup = rec;

        /* Encrypt record */
        ret = mbedtls_ssl_encrypt_buf( &ssl, t_enc, &rec,
                                       rnd_std_rand, NULL );
        TEST_ASSERT( ret == 0 || ret == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
        if( ret != 0 )
        {
            continue;
        }

        /* Decrypt record with t_dec */
        ret = mbedtls_ssl_decrypt_buf( &ssl, t_dec, &rec );
        TEST_ASSERT( ret == 0 );

        /* Compare results */
        TEST_ASSERT( rec.type == rec_backup.type );
        TEST_ASSERT( memcmp( rec.ctr, rec_backup.ctr, 8 ) == 0 );
        TEST_ASSERT( rec.ver[0] == rec_backup.ver[0] );
        TEST_ASSERT( rec.ver[1] == rec_backup.ver[1] );
        TEST_ASSERT( rec.data_len == rec_backup.data_len );
        TEST_ASSERT( rec.data_offset == rec_backup.data_offset );
        TEST_ASSERT( memcmp( rec.buf + rec.data_offset,
                             rec_backup.buf + rec_backup.data_offset,
                             rec.data_len ) == 0 );
    }

exit:

    /* Cleanup */
    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_transform_free( &t0 );
    mbedtls_ssl_transform_free( &t1 );

    mbedtls_free( buf );
}

void test_ssl_crypt_record_wrapper( void ** params )
{

    test_ssl_crypt_record( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ) );
}
#line 436 "/home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_crypt_record_small( int cipher_type, int hash_id,
                             int etm, int tag_mode, int ver,
                             int cid0_len, int cid1_len )
{
    /*
     * Test pairs of encryption and decryption with an increasing
     * amount of space in the record buffer - in more detail:
     * 1) Try to encrypt with 0, 1, 2, ... bytes available
     *    in front of the plaintext, and expect the encryption
     *    to succeed starting from some offset. Always keep
     *    enough space in the end of the buffer.
     * 2) Try to encrypt with 0, 1, 2, ... bytes available
     *    at the end of the plaintext, and expect the encryption
     *    to succeed starting from some offset. Always keep
     *    enough space at the beginning of the buffer.
     * 3) Try to encrypt with 0, 1, 2, ... bytes available
     *    both at the front and end of the plaintext,
     *    and expect the encryption to succeed starting from
     *    some offset.
     *
     * If encryption succeeds, check that decryption succeeds
     * and yields the original record.
     */

    mbedtls_ssl_context ssl; /* ONLY for debugging */

    mbedtls_ssl_transform t0, t1;
    unsigned char *buf = NULL;
    size_t const buflen = 256;
    mbedtls_record rec, rec_backup;

    int ret;
    int mode;              /* Mode 1, 2 or 3 as explained above     */
    size_t offset;         /* Available space at beginning/end/both */
    size_t threshold = 96; /* Maximum offset to test against        */

    size_t default_pre_padding  = 64;  /* Pre-padding to use in mode 2  */
    size_t default_post_padding = 128; /* Post-padding to use in mode 1 */

    int seen_success; /* Indicates if in the current mode we've
                       * already seen a successful test. */

    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_transform_init( &t0 );
    mbedtls_ssl_transform_init( &t1 );
    TEST_ASSERT( build_transforms( &t0, &t1, cipher_type, hash_id,
                                   etm, tag_mode, ver,
                                   (size_t) cid0_len,
                                   (size_t) cid1_len ) == 0 );

    TEST_ASSERT( ( buf = mbedtls_calloc( 1, buflen ) ) != NULL );

    for( mode=1; mode <= 3; mode++ )
    {
        seen_success = 0;
        for( offset=0; offset <= threshold; offset++ )
        {
            mbedtls_ssl_transform *t_dec, *t_enc;
            t_dec = &t0;
            t_enc = &t1;

            memset( rec.ctr, offset, sizeof( rec.ctr ) );
            rec.type    = 42;
            rec.ver[0]  = offset;
            rec.ver[1]  = offset;
            rec.buf     = buf;
            rec.buf_len = buflen;
#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
            rec.cid_len = 0;
#endif /* MBEDTLS_SSL_DTLS_CONNECTION_ID */

            switch( mode )
            {
                case 1: /* Space in the beginning */
                    rec.data_offset = offset;
                    rec.data_len = buflen - offset - default_post_padding;
                    break;

                case 2: /* Space in the end */
                    rec.data_offset = default_pre_padding;
                    rec.data_len = buflen - default_pre_padding - offset;
                    break;

                case 3: /* Space in the beginning and end */
                    rec.data_offset = offset;
                    rec.data_len = buflen - 2 * offset;
                    break;

                default:
                    TEST_ASSERT( 0 );
                    break;
            }

            memset( rec.buf + rec.data_offset, 42, rec.data_len );

            /* Make a copy for later comparison */
            rec_backup = rec;

            /* Encrypt record */
            ret = mbedtls_ssl_encrypt_buf( &ssl, t_enc, &rec, rnd_std_rand, NULL );

            if( ( mode == 1 || mode == 2 ) && seen_success )
            {
                TEST_ASSERT( ret == 0 );
            }
            else
            {
                TEST_ASSERT( ret == 0 || ret == MBEDTLS_ERR_SSL_BUFFER_TOO_SMALL );
                if( ret == 0 )
                    seen_success = 1;
            }

            if( ret != 0 )
                continue;

            /* Decrypt record with t_dec */
            TEST_ASSERT( mbedtls_ssl_decrypt_buf( &ssl, t_dec, &rec ) == 0 );

            /* Compare results */
            TEST_ASSERT( rec.type == rec_backup.type );
            TEST_ASSERT( memcmp( rec.ctr, rec_backup.ctr, 8 ) == 0 );
            TEST_ASSERT( rec.ver[0] == rec_backup.ver[0] );
            TEST_ASSERT( rec.ver[1] == rec_backup.ver[1] );
            TEST_ASSERT( rec.data_len == rec_backup.data_len );
            TEST_ASSERT( rec.data_offset == rec_backup.data_offset );
            TEST_ASSERT( memcmp( rec.buf + rec.data_offset,
                                 rec_backup.buf + rec_backup.data_offset,
                                 rec.data_len ) == 0 );
        }

        TEST_ASSERT( seen_success == 1 );
    }

exit:

    /* Cleanup */
    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_transform_free( &t0 );
    mbedtls_ssl_transform_free( &t1 );

    mbedtls_free( buf );
}

void test_ssl_crypt_record_small_wrapper( void ** params )
{

    test_ssl_crypt_record_small( *( (int *) params[0] ), *( (int *) params[1] ), *( (int *) params[2] ), *( (int *) params[3] ), *( (int *) params[4] ), *( (int *) params[5] ), *( (int *) params[6] ) );
}
#line 581 "/home/grace/Desktop/polarssl_test/mbedtls/tests/suites/test_suite_ssl.function"
void test_ssl_tls_prf( int type, data_t * secret, data_t * random,
                  char *label, data_t *result_hex_str, int exp_ret )
{
    unsigned char *output;

    output = mbedtls_calloc( 1, result_hex_str->len );
    if( output == NULL )
        goto exit;

#if defined(MBEDTLS_USE_PSA_CRYPTO)
    TEST_ASSERT( psa_crypto_init() == 0 );
#endif

    TEST_ASSERT( mbedtls_ssl_tls_prf( type, secret->x, secret->len,
                                      label, random->x, random->len,
                                      output, result_hex_str->len ) == exp_ret );

    if( exp_ret == 0 )
    {
        TEST_ASSERT( hexcmp( output, result_hex_str->x,
                     result_hex_str->len, result_hex_str->len ) == 0 );
    }
exit:

    mbedtls_free( output );
}

void test_ssl_tls_prf_wrapper( void ** params )
{
    data_t data1 = {(uint8_t *) params[1], *( (uint32_t *) params[2] )};
    data_t data3 = {(uint8_t *) params[3], *( (uint32_t *) params[4] )};
    data_t data6 = {(uint8_t *) params[6], *( (uint32_t *) params[7] )};

    test_ssl_tls_prf( *( (int *) params[0] ), &data1, &data3, (char *) params[5], &data6, *( (int *) params[8] ) );
}
#endif /* MBEDTLS_SSL_TLS_C */


#line 49 "suites/main_test.function"


/*----------------------------------------------------------------------------*/
/* Test dispatch code */


/**
 * \brief       Evaluates an expression/macro into its literal integer value.
 *              For optimizing space for embedded targets each expression/macro
 *              is identified by a unique identifier instead of string literals.
 *              Identifiers and evaluation code is generated by script:
 *              generate_test_code.py
 *
 * \param exp_id    Expression identifier.
 * \param out_value Pointer to int to hold the integer.
 *
 * \return       0 if exp_id is found. 1 otherwise.
 */
int get_expression( int32_t exp_id, int32_t * out_value )
{
    int ret = KEY_VALUE_MAPPING_FOUND;

    (void) exp_id;
    (void) out_value;

    switch( exp_id )
    {

#if defined(MBEDTLS_SSL_TLS_C)

        case 0:
            {
                *out_value = -1;
            }
            break;
        case 1:
            {
                *out_value = MBEDTLS_CIPHER_AES_128_CBC;
            }
            break;
        case 2:
            {
                *out_value = MBEDTLS_MD_SHA384;
            }
            break;
        case 3:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_3;
            }
            break;
        case 4:
            {
                *out_value = MBEDTLS_MD_SHA256;
            }
            break;
        case 5:
            {
                *out_value = MBEDTLS_MD_SHA1;
            }
            break;
        case 6:
            {
                *out_value = MBEDTLS_MD_MD5;
            }
            break;
        case 7:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_2;
            }
            break;
        case 8:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_1;
            }
            break;
        case 9:
            {
                *out_value = MBEDTLS_SSL_MINOR_VERSION_0;
            }
            break;
        case 10:
            {
                *out_value = MBEDTLS_CIPHER_AES_192_CBC;
            }
            break;
        case 11:
            {
                *out_value = MBEDTLS_CIPHER_AES_256_CBC;
            }
            break;
        case 12:
            {
                *out_value = MBEDTLS_CIPHER_ARIA_128_CBC;
            }
            break;
        case 13:
            {
                *out_value = MBEDTLS_CIPHER_ARIA_192_CBC;
            }
            break;
        case 14:
            {
                *out_value = MBEDTLS_CIPHER_ARIA_256_CBC;
            }
            break;
        case 15:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_128_CBC;
            }
            break;
        case 16:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_192_CBC;
            }
            break;
        case 17:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_256_CBC;
            }
            break;
        case 18:
            {
                *out_value = MBEDTLS_CIPHER_BLOWFISH_CBC;
            }
            break;
        case 19:
            {
                *out_value = MBEDTLS_CIPHER_AES_128_GCM;
            }
            break;
        case 20:
            {
                *out_value = MBEDTLS_CIPHER_AES_192_GCM;
            }
            break;
        case 21:
            {
                *out_value = MBEDTLS_CIPHER_AES_256_GCM;
            }
            break;
        case 22:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_128_GCM;
            }
            break;
        case 23:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_192_GCM;
            }
            break;
        case 24:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_256_GCM;
            }
            break;
        case 25:
            {
                *out_value = MBEDTLS_CIPHER_AES_128_CCM;
            }
            break;
        case 26:
            {
                *out_value = MBEDTLS_CIPHER_AES_192_CCM;
            }
            break;
        case 27:
            {
                *out_value = MBEDTLS_CIPHER_AES_256_CCM;
            }
            break;
        case 28:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_128_CCM;
            }
            break;
        case 29:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_192_CCM;
            }
            break;
        case 30:
            {
                *out_value = MBEDTLS_CIPHER_CAMELLIA_256_CCM;
            }
            break;
        case 31:
            {
                *out_value = MBEDTLS_CIPHER_ARC4_128;
            }
            break;
        case 32:
            {
                *out_value = MBEDTLS_CIPHER_NULL;
            }
            break;
        case 33:
            {
                *out_value = MBEDTLS_CIPHER_CHACHA20_POLY1305;
            }
            break;
        case 34:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_NONE;
            }
            break;
        case 35:
            {
                *out_value = MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE;
            }
            break;
        case 36:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_SSL3;
            }
            break;
        case 37:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_TLS1;
            }
            break;
        case 38:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_SHA384;
            }
            break;
        case 39:
            {
                *out_value = MBEDTLS_SSL_TLS_PRF_SHA256;
            }
            break;
#endif

#line 78 "suites/main_test.function"
        default:
           {
                ret = KEY_VALUE_MAPPING_NOT_FOUND;
           }
           break;
    }
    return( ret );
}


/**
 * \brief       Checks if the dependency i.e. the compile flag is set.
 *              For optimizing space for embedded targets each dependency
 *              is identified by a unique identifier instead of string literals.
 *              Identifiers and check code is generated by script:
 *              generate_test_code.py
 *
 * \param exp_id    Dependency identifier.
 *
 * \return       DEPENDENCY_SUPPORTED if set else DEPENDENCY_NOT_SUPPORTED
 */
int dep_check( int dep_id )
{
    int ret = DEPENDENCY_NOT_SUPPORTED;

    (void) dep_id;

    switch( dep_id )
    {

#if defined(MBEDTLS_SSL_TLS_C)

        case 0:
            {
#if defined(MBEDTLS_CIPHER_MODE_CBC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 1:
            {
#if defined(MBEDTLS_AES_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 2:
            {
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 3:
            {
#if defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 4:
            {
#if defined(MBEDTLS_SSL_DTLS_CONNECTION_ID)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 5:
            {
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 6:
            {
#if defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 7:
            {
#if defined(MBEDTLS_SHA1_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 8:
            {
#if defined(MBEDTLS_MD5_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 9:
            {
#if defined(MBEDTLS_SSL_PROTO_TLS1_1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 10:
            {
#if defined(MBEDTLS_SSL_PROTO_TLS1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 11:
            {
#if defined(MBEDTLS_SSL_PROTO_SSL3)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 12:
            {
#if defined(MBEDTLS_ARIA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 13:
            {
#if defined(MBEDTLS_CAMELLIA_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 14:
            {
#if defined(MBEDTLS_BLOWFISH_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 15:
            {
#if defined(MBEDTLS_GCM_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 16:
            {
#if defined(MBEDTLS_CCM_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 17:
            {
#if defined(MBEDTLS_ARC4_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 18:
            {
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 19:
            {
#if defined(MBEDTLS_CHACHAPOLY_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 20:
            {
#if !defined(MBEDTLS_SSL_PROTO_SSL3)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 21:
            {
#if !defined(MBEDTLS_SSL_PROTO_TLS1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 22:
            {
#if !defined(MBEDTLS_SSL_PROTO_TLS1_1)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 23:
            {
#if !defined(MBEDTLS_SHA512_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
        case 24:
            {
#if !defined(MBEDTLS_SHA256_C)
                ret = DEPENDENCY_SUPPORTED;
#else
                ret = DEPENDENCY_NOT_SUPPORTED;
#endif
            }
            break;
#endif

#line 109 "suites/main_test.function"
        default:
            break;
    }
    return( ret );
}


/**
 * \brief       Function pointer type for test function wrappers.
 *
 *
 * \param void **   Pointer to void pointers. Represents an array of test
 *                  function parameters.
 *
 * \return       void
 */
typedef void (*TestWrapper_t)( void ** );


/**
 * \brief       Table of test function wrappers. Used by dispatch_test().
 *              This table is populated by script:
 *              generate_test_code.py
 *
 */
TestWrapper_t test_funcs[] =
{
/* Function Id: 0 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
    test_ssl_dtls_replay_wrapper,
#else
    NULL,
#endif
/* Function Id: 1 */

#if defined(MBEDTLS_SSL_TLS_C) && defined(MBEDTLS_X509_CRT_PARSE_C)
    test_ssl_set_hostname_twice_wrapper,
#else
    NULL,
#endif
/* Function Id: 2 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_crypt_record_wrapper,
#else
    NULL,
#endif
/* Function Id: 3 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_crypt_record_small_wrapper,
#else
    NULL,
#endif
/* Function Id: 4 */

#if defined(MBEDTLS_SSL_TLS_C)
    test_ssl_tls_prf_wrapper,
#else
    NULL,
#endif

#line 138 "suites/main_test.function"
};

/**
 * \brief        Execute the test function.
 *
 *               This is a wrapper function around the test function execution
 *               to allow the setjmp() call used to catch any calls to the
 *               parameter failure callback, to be used. Calls to setjmp()
 *               can invalidate the state of any local auto variables.
 *
 * \param fp     Function pointer to the test function
 * \param params Parameters to pass
 *
 */
void execute_function_ptr(TestWrapper_t fp, void **params)
{
#if defined(MBEDTLS_CHECK_PARAMS)
    if ( setjmp( param_fail_jmp ) == 0 )
    {
        fp( params );
    }
    else
    {
        /* Unexpected parameter validation error */
        test_info.failed = 1;
    }

    memset( param_fail_jmp, 0, sizeof(jmp_buf) );
#else
    fp( params );
#endif
}

/**
 * \brief        Dispatches test functions based on function index.
 *
 * \param exp_id    Test function index.
 *
 * \return       DISPATCH_TEST_SUCCESS if found
 *               DISPATCH_TEST_FN_NOT_FOUND if not found
 *               DISPATCH_UNSUPPORTED_SUITE if not compile time enabled.
 */
int dispatch_test( int func_idx, void ** params )
{
    int ret = DISPATCH_TEST_SUCCESS;
    TestWrapper_t fp = NULL;

    if ( func_idx < (int)( sizeof( test_funcs ) / sizeof( TestWrapper_t ) ) )
    {
        fp = test_funcs[func_idx];
        if ( fp )
            execute_function_ptr(fp, params);
        else
            ret = DISPATCH_UNSUPPORTED_SUITE;
    }
    else
    {
        ret = DISPATCH_TEST_FN_NOT_FOUND;
    }

    return( ret );
}


/**
 * \brief       Checks if test function is supported
 *
 * \param exp_id    Test function index.
 *
 * \return       DISPATCH_TEST_SUCCESS if found
 *               DISPATCH_TEST_FN_NOT_FOUND if not found
 *               DISPATCH_UNSUPPORTED_SUITE if not compile time enabled.
 */
int check_test( int func_idx )
{
    int ret = DISPATCH_TEST_SUCCESS;
    TestWrapper_t fp = NULL;

    if ( func_idx < (int)( sizeof(test_funcs)/sizeof( TestWrapper_t ) ) )
    {
        fp = test_funcs[func_idx];
        if ( fp == NULL )
            ret = DISPATCH_UNSUPPORTED_SUITE;
    }
    else
    {
        ret = DISPATCH_TEST_FN_NOT_FOUND;
    }

    return( ret );
}


#line 2 "suites/host_test.function"

/**
 * \brief       Verifies that string is in string parameter format i.e. "<str>"
 *              It also strips enclosing '"' from the input string.
 *
 * \param str   String parameter.
 *
 * \return      0 if success else 1
 */
int verify_string( char **str )
{
    if( ( *str )[0] != '"' ||
        ( *str )[strlen( *str ) - 1] != '"' )
    {
        mbedtls_fprintf( stderr,
            "Expected string (with \"\") for parameter and got: %s\n", *str );
        return( -1 );
    }

    ( *str )++;
    ( *str )[strlen( *str ) - 1] = '\0';

    return( 0 );
}

/**
 * \brief       Verifies that string is an integer. Also gives the converted
 *              integer value.
 *
 * \param str   Input string.
 * \param value Pointer to int for output value.
 *
 * \return      0 if success else 1
 */
int verify_int( char *str, int *value )
{
    size_t i;
    int minus = 0;
    int digits = 1;
    int hex = 0;

    for( i = 0; i < strlen( str ); i++ )
    {
        if( i == 0 && str[i] == '-' )
        {
            minus = 1;
            continue;
        }

        if( ( ( minus && i == 2 ) || ( !minus && i == 1 ) ) &&
            str[i - 1] == '0' && ( str[i] == 'x' || str[i] == 'X' ) )
        {
            hex = 1;
            continue;
        }

        if( ! ( ( str[i] >= '0' && str[i] <= '9' ) ||
                ( hex && ( ( str[i] >= 'a' && str[i] <= 'f' ) ||
                           ( str[i] >= 'A' && str[i] <= 'F' ) ) ) ) )
        {
            digits = 0;
            break;
        }
    }

    if( digits )
    {
        if( hex )
            *value = strtol( str, NULL, 16 );
        else
            *value = strtol( str, NULL, 10 );

        return( 0 );
    }

    mbedtls_fprintf( stderr,
                    "Expected integer for parameter and got: %s\n", str );
    return( KEY_VALUE_MAPPING_NOT_FOUND );
}


/**
 * \brief       Usage string.
 *
 */
#define USAGE \
    "Usage: %s [OPTIONS] files...\n\n" \
    "   Command line arguments:\n" \
    "     files...          One or more test data files. If no file is\n" \
    "                       specified the following default test case\n" \
    "                       file is used:\n" \
    "                           %s\n\n" \
    "   Options:\n" \
    "     -v | --verbose    Display full information about each test\n" \
    "     -h | --help       Display this information\n\n", \
    argv[0], \
    "TESTCASE_FILENAME"


/**
 * \brief       Read a line from the passed file pointer.
 *
 * \param f     FILE pointer
 * \param buf   Pointer to memory to hold read line.
 * \param len   Length of the buf.
 *
 * \return      0 if success else -1
 */
int get_line( FILE *f, char *buf, size_t len )
{
    char *ret;
    int i = 0, str_len = 0, has_string = 0;

    /* Read until we get a valid line */
    do
    {
        ret = fgets( buf, len, f );
        if( ret == NULL )
            return( -1 );

        str_len = strlen( buf );

        /* Skip empty line and comment */
        if ( str_len == 0 || buf[0] == '#' )
            continue;
        has_string = 0;
        for ( i = 0; i < str_len; i++ )
        {
            char c = buf[i];
            if ( c != ' ' && c != '\t' && c != '\n' &&
                 c != '\v' && c != '\f' && c != '\r' )
            {
                has_string = 1;
                break;
            }
        }
    } while( !has_string );

    /* Strip new line and carriage return */
    ret = buf + strlen( buf );
    if( ret-- > buf && *ret == '\n' )
        *ret = '\0';
    if( ret-- > buf && *ret == '\r' )
        *ret = '\0';

    return( 0 );
}

/**
 * \brief       Splits string delimited by ':'. Ignores '\:'.
 *
 * \param buf           Input string
 * \param len           Input string length
 * \param params        Out params found
 * \param params_len    Out params array len
 *
 * \return      Count of strings found.
 */
static int parse_arguments( char *buf, size_t len, char **params,
                            size_t params_len )
{
    size_t cnt = 0, i;
    char *cur = buf;
    char *p = buf, *q;

    params[cnt++] = cur;

    while( *p != '\0' && p < ( buf + len ) )
    {
        if( *p == '\\' )
        {
            p++;
            p++;
            continue;
        }
        if( *p == ':' )
        {
            if( p + 1 < buf + len )
            {
                cur = p + 1;
                TEST_HELPER_ASSERT( cnt < params_len );
                params[cnt++] = cur;
            }
            *p = '\0';
        }

        p++;
    }

    /* Replace newlines, question marks and colons in strings */
    for( i = 0; i < cnt; i++ )
    {
        p = params[i];
        q = params[i];

        while( *p != '\0' )
        {
            if( *p == '\\' && *( p + 1 ) == 'n' )
            {
                p += 2;
                *( q++ ) = '\n';
            }
            else if( *p == '\\' && *( p + 1 ) == ':' )
            {
                p += 2;
                *( q++ ) = ':';
            }
            else if( *p == '\\' && *( p + 1 ) == '?' )
            {
                p += 2;
                *( q++ ) = '?';
            }
            else
                *( q++ ) = *( p++ );
        }
        *q = '\0';
    }

    return( cnt );
}

/**
 * \brief       Converts parameters into test function consumable parameters.
 *              Example: Input:  {"int", "0", "char*", "Hello",
 *                                "hex", "abef", "exp", "1"}
 *                      Output:  {
 *                                0,                // Verified int
 *                                "Hello",          // Verified string
 *                                2, { 0xab, 0xef },// Converted len,hex pair
 *                                9600              // Evaluated expression
 *                               }
 *
 *
 * \param cnt               Parameter array count.
 * \param params            Out array of found parameters.
 * \param int_params_store  Memory for storing processed integer parameters.
 *
 * \return      0 for success else 1
 */
static int convert_params( size_t cnt , char ** params , int * int_params_store )
{
    char ** cur = params;
    char ** out = params;
    int ret = DISPATCH_TEST_SUCCESS;

    while ( cur < params + cnt )
    {
        char * type = *cur++;
        char * val = *cur++;

        if ( strcmp( type, "char*" ) == 0 )
        {
            if ( verify_string( &val ) == 0 )
            {
              *out++ = val;
            }
            else
            {
                ret = ( DISPATCH_INVALID_TEST_DATA );
                break;
            }
        }
        else if ( strcmp( type, "int" ) == 0 )
        {
            if ( verify_int( val, int_params_store ) == 0 )
            {
              *out++ = (char *) int_params_store++;
            }
            else
            {
                ret = ( DISPATCH_INVALID_TEST_DATA );
                break;
            }
        }
        else if ( strcmp( type, "hex" ) == 0 )
        {
            if ( verify_string( &val ) == 0 )
            {
                *int_params_store = unhexify( (unsigned char *) val, val );
                *out++ = val;
                *out++ = (char *)(int_params_store++);
            }
            else
            {
                ret = ( DISPATCH_INVALID_TEST_DATA );
                break;
            }
        }
        else if ( strcmp( type, "exp" ) == 0 )
        {
            int exp_id = strtol( val, NULL, 10 );
            if ( get_expression ( exp_id, int_params_store ) == 0 )
            {
              *out++ = (char *)int_params_store++;
            }
            else
            {
              ret = ( DISPATCH_INVALID_TEST_DATA );
              break;
            }
        }
        else
        {
          ret = ( DISPATCH_INVALID_TEST_DATA );
          break;
        }
    }
    return( ret );
}

/**
 * \brief       Tests snprintf implementation with test input.
 *
 * \note
 * At high optimization levels (e.g. gcc -O3), this function may be
 * inlined in run_test_snprintf. This can trigger a spurious warning about
 * potential misuse of snprintf from gcc -Wformat-truncation (observed with
 * gcc 7.2). This warning makes tests in run_test_snprintf redundant on gcc
 * only. They are still valid for other compilers. Avoid this warning by
 * forbidding inlining of this function by gcc.
 *
 * \param n         Buffer test length.
 * \param ref_buf   Expected buffer.
 * \param ref_ret   Expected snprintf return value.
 *
 * \return      0 for success else 1
 */
#if defined(__GNUC__)
__attribute__((__noinline__))
#endif
static int test_snprintf( size_t n, const char ref_buf[10], int ref_ret )
{
    int ret;
    char buf[10] = "xxxxxxxxx";
    const char ref[10] = "xxxxxxxxx";

    if( n >= sizeof( buf ) )
        return( -1 );
    ret = mbedtls_snprintf( buf, n, "%s", "123" );
    if( ret < 0 || (size_t) ret >= n )
        ret = -1;

    if( strncmp( ref_buf, buf, sizeof( buf ) ) != 0 ||
        ref_ret != ret ||
        memcmp( buf + n, ref + n, sizeof( buf ) - n ) != 0 )
    {
        return( 1 );
    }

    return( 0 );
}

/**
 * \brief       Tests snprintf implementation.
 *
 * \param none
 *
 * \return      0 for success else 1
 */
static int run_test_snprintf( void )
{
    return( test_snprintf( 0, "xxxxxxxxx",  -1 ) != 0 ||
            test_snprintf( 1, "",           -1 ) != 0 ||
            test_snprintf( 2, "1",          -1 ) != 0 ||
            test_snprintf( 3, "12",         -1 ) != 0 ||
            test_snprintf( 4, "123",         3 ) != 0 ||
            test_snprintf( 5, "123",         3 ) != 0 );
}


/**
 * \brief       Desktop implementation of execute_tests().
 *              Parses command line and executes tests from
 *              supplied or default data file.
 *
 * \param argc  Command line argument count.
 * \param argv  Argument array.
 *
 * \return      Program exit status.
 */
int execute_tests( int argc , const char ** argv )
{
    /* Local Configurations and options */
    const char *default_filename = "./test_suite_ssl.datax";
    const char *test_filename = NULL;
    const char **test_files = NULL;
    int testfile_count = 0;
    int option_verbose = 0;
    int function_id = 0;

    /* Other Local variables */
    int arg_index = 1;
    const char *next_arg;
    int testfile_index, ret, i, cnt;
    int total_errors = 0, total_tests = 0, total_skipped = 0;
    FILE *file;
    char buf[5000];
    char *params[50];
    /* Store for proccessed integer params. */
    int int_params[50];
    void *pointer;
#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
    int stdout_fd = -1;
#endif /* __unix__ || __APPLE__ __MACH__ */

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && \
    !defined(TEST_SUITE_MEMORY_BUFFER_ALLOC)
    unsigned char alloc_buf[1000000];
    mbedtls_memory_buffer_alloc_init( alloc_buf, sizeof( alloc_buf ) );
#endif

    /*
     * The C standard doesn't guarantee that all-bits-0 is the representation
     * of a NULL pointer. We do however use that in our code for initializing
     * structures, which should work on every modern platform. Let's be sure.
     */
    memset( &pointer, 0, sizeof( void * ) );
    if( pointer != NULL )
    {
        mbedtls_fprintf( stderr, "all-bits-zero is not a NULL pointer\n" );
        return( 1 );
    }

    /*
     * Make sure we have a snprintf that correctly zero-terminates
     */
    if( run_test_snprintf() != 0 )
    {
        mbedtls_fprintf( stderr, "the snprintf implementation is broken\n" );
        return( 1 );
    }

    while( arg_index < argc )
    {
        next_arg = argv[arg_index];

        if( strcmp( next_arg, "--verbose" ) == 0 ||
                 strcmp( next_arg, "-v" ) == 0 )
        {
            option_verbose = 1;
        }
        else if( strcmp(next_arg, "--help" ) == 0 ||
                 strcmp(next_arg, "-h" ) == 0 )
        {
            mbedtls_fprintf( stdout, USAGE );
            mbedtls_exit( EXIT_SUCCESS );
        }
        else
        {
            /* Not an option, therefore treat all further arguments as the file
             * list.
             */
            test_files = &argv[ arg_index ];
            testfile_count = argc - arg_index;
        }

        arg_index++;
    }

    /* If no files were specified, assume a default */
    if ( test_files == NULL || testfile_count == 0 )
    {
        test_files = &default_filename;
        testfile_count = 1;
    }

    /* Initialize the struct that holds information about the last test */
    memset( &test_info, 0, sizeof( test_info ) );

    /* Now begin to execute the tests in the testfiles */
    for ( testfile_index = 0;
          testfile_index < testfile_count;
          testfile_index++ )
    {
        int unmet_dep_count = 0;
        char *unmet_dependencies[20];

        test_filename = test_files[ testfile_index ];

        file = fopen( test_filename, "r" );
        if( file == NULL )
        {
            mbedtls_fprintf( stderr, "Failed to open test file: %s\n",
                             test_filename );
            return( 1 );
        }

        while( !feof( file ) )
        {
            if( unmet_dep_count > 0 )
            {
                mbedtls_fprintf( stderr,
                    "FATAL: Dep count larger than zero at start of loop\n" );
                mbedtls_exit( MBEDTLS_EXIT_FAILURE );
            }
            unmet_dep_count = 0;

            if( ( ret = get_line( file, buf, sizeof(buf) ) ) != 0 )
                break;
            mbedtls_fprintf( stdout, "%s%.66s", test_info.failed ? "\n" : "", buf );
            mbedtls_fprintf( stdout, " " );
            for( i = strlen( buf ) + 1; i < 67; i++ )
                mbedtls_fprintf( stdout, "." );
            mbedtls_fprintf( stdout, " " );
            fflush( stdout );

            total_tests++;

            if( ( ret = get_line( file, buf, sizeof( buf ) ) ) != 0 )
                break;
            cnt = parse_arguments( buf, strlen( buf ), params,
                                   sizeof( params ) / sizeof( params[0] ) );

            if( strcmp( params[0], "depends_on" ) == 0 )
            {
                for( i = 1; i < cnt; i++ )
                {
                    int dep_id = strtol( params[i], NULL, 10 );
                    if( dep_check( dep_id ) != DEPENDENCY_SUPPORTED )
                    {
                        if( 0 == option_verbose )
                        {
                            /* Only one count is needed if not verbose */
                            unmet_dep_count++;
                            break;
                        }

                        unmet_dependencies[ unmet_dep_count ] = strdup( params[i] );
                        if(  unmet_dependencies[ unmet_dep_count ] == NULL )
                        {
                            mbedtls_fprintf( stderr, "FATAL: Out of memory\n" );
                            mbedtls_exit( MBEDTLS_EXIT_FAILURE );
                        }
                        unmet_dep_count++;
                    }
                }

                if( ( ret = get_line( file, buf, sizeof( buf ) ) ) != 0 )
                    break;
                cnt = parse_arguments( buf, strlen( buf ), params,
                                       sizeof( params ) / sizeof( params[0] ) );
            }

            // If there are no unmet dependencies execute the test
            if( unmet_dep_count == 0 )
            {
                test_info.failed = 0;
                test_info.paramfail_test_state = PARAMFAIL_TESTSTATE_IDLE;

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
                /* Suppress all output from the library unless we're verbose
                 * mode
                 */
                if( !option_verbose )
                {
                    stdout_fd = redirect_output( &stdout, "/dev/null" );
                    if( stdout_fd == -1 )
                    {
                        /* Redirection has failed with no stdout so exit */
                        exit( 1 );
                    }
                }
#endif /* __unix__ || __APPLE__ __MACH__ */

                function_id = strtol( params[0], NULL, 10 );
                if ( (ret = check_test( function_id )) == DISPATCH_TEST_SUCCESS )
                {
                    ret = convert_params( cnt - 1, params + 1, int_params );
                    if ( DISPATCH_TEST_SUCCESS == ret )
                    {
                        ret = dispatch_test( function_id, (void **)( params + 1 ) );
                    }
                }

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
                if( !option_verbose && restore_output( &stdout, stdout_fd ) )
                {
                        /* Redirection has failed with no stdout so exit */
                        exit( 1 );
                }
#endif /* __unix__ || __APPLE__ __MACH__ */

            }

            if( unmet_dep_count > 0 || ret == DISPATCH_UNSUPPORTED_SUITE )
            {
                total_skipped++;
                mbedtls_fprintf( stdout, "----" );

                if( 1 == option_verbose && ret == DISPATCH_UNSUPPORTED_SUITE )
                {
                    mbedtls_fprintf( stdout, "\n   Test Suite not enabled" );
                }

                if( 1 == option_verbose && unmet_dep_count > 0 )
                {
                    mbedtls_fprintf( stdout, "\n   Unmet dependencies: " );
                    for( i = 0; i < unmet_dep_count; i++ )
                    {
                        mbedtls_fprintf( stdout, "%s  ",
                                        unmet_dependencies[i] );
                        free( unmet_dependencies[i] );
                    }
                }
                mbedtls_fprintf( stdout, "\n" );
                fflush( stdout );

                unmet_dep_count = 0;
            }
            else if( ret == DISPATCH_TEST_SUCCESS )
            {
                if( test_info.failed == 0 )
                {
                    mbedtls_fprintf( stdout, "PASS\n" );
                }
                else
                {
                    total_errors++;
                    mbedtls_fprintf( stdout, "FAILED\n" );
                    mbedtls_fprintf( stdout, "  %s\n  at line %d, %s\n",
                                     test_info.test, test_info.line_no,
                                     test_info.filename );
                }
                fflush( stdout );
            }
            else if( ret == DISPATCH_INVALID_TEST_DATA )
            {
                mbedtls_fprintf( stderr, "FAILED: FATAL PARSE ERROR\n" );
                fclose( file );
                mbedtls_exit( 2 );
            }
            else if( ret == DISPATCH_TEST_FN_NOT_FOUND )
            {
                mbedtls_fprintf( stderr, "FAILED: FATAL TEST FUNCTION NOT FUND\n" );
                fclose( file );
                mbedtls_exit( 2 );
            }
            else
                total_errors++;
        }
        fclose( file );

        /* In case we encounter early end of file */
        for( i = 0; i < unmet_dep_count; i++ )
            free( unmet_dependencies[i] );
    }

    mbedtls_fprintf( stdout, "\n----------------------------------------------------------------------------\n\n");
    if( total_errors == 0 )
        mbedtls_fprintf( stdout, "PASSED" );
    else
        mbedtls_fprintf( stdout, "FAILED" );

    mbedtls_fprintf( stdout, " (%d / %d tests (%d skipped))\n",
             total_tests - total_errors, total_tests, total_skipped );

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && \
    !defined(TEST_SUITE_MEMORY_BUFFER_ALLOC)
#if defined(MBEDTLS_MEMORY_DEBUG)
    mbedtls_memory_buffer_alloc_status();
#endif
    mbedtls_memory_buffer_alloc_free();
#endif

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
    if( stdout_fd != -1 )
        close_output( stdout );
#endif /* __unix__ || __APPLE__ __MACH__ */

    return( total_errors != 0 );
}


#line 234 "suites/main_test.function"

/*----------------------------------------------------------------------------*/
/* Main Test code */


/**
 * \brief       Program main. Invokes platform specific execute_tests().
 *
 * \param argc      Command line arguments count.
 * \param argv      Array of command line arguments.
 *
 * \return       Exit code.
 */
int main( int argc, const char *argv[] )
{
    int ret = platform_setup();
    if( ret != 0 )
    {
        mbedtls_fprintf( stderr,
                         "FATAL: Failed to initialize platform - error %d\n",
                         ret );
        return( -1 );
    }

    ret = execute_tests( argc, argv );
    platform_teardown();
    return( ret );
}
