/*
  +----------------------------------------------------------------------+
  | Idtrans                                                              |
  +----------------------------------------------------------------------+
  | Copyright (c) 2016 The PHP Group                                     |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: hikdo <hikdo7@gmail.com>                                      |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdint.h>

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_idtrans.h"

ZEND_DECLARE_MODULE_GLOBALS(idtrans)

/* {{{ DL support */
#ifdef COMPILE_DL_IDTRANS
ZEND_GET_MODULE(idtrans)
#endif
/* }}} */

/* {{{ idtrans_functions[] */
zend_function_entry idtrans_functions[] = {
    PHP_FE(idtrans_encode, NULL)
    PHP_FE(idtrans_decode, NULL)
    {NULL, NULL, NULL}
};
/* }}} */

/* {{{ idtrans_module_entry */
zend_module_entry idtrans_module_entry = {
    STANDARD_MODULE_HEADER,
    "idtrans",
    idtrans_functions,
    PHP_MINIT(idtrans),
    PHP_MSHUTDOWN(idtrans),
    NULL,
    NULL,
    PHP_MINFO(idtrans),
    PHP_IDTRANS_VERSION,
    PHP_MODULE_GLOBALS(idtrans),
    NULL,
    NULL,
    NULL,
    STANDARD_MODULE_PROPERTIES_EX
};
/* }}} */

/* {{{ php_idtrans_init_globals */
static void php_idtrans_init_globals(zend_idtrans_globals *idtrans_globals)
{
    idtrans_globals->optimus.max     = 2147483647;
    idtrans_globals->optimus.prime   = 511139911;
    idtrans_globals->optimus.inverse = 1484933495;
    idtrans_globals->optimus.random  = 300307970;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(idtrans)
{	
    ZEND_INIT_MODULE_GLOBALS(idtrans, php_idtrans_init_globals, NULL);
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(idtrans)
{   
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(idtrans)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "idtrans support", "enabled");
    php_info_print_table_row(2, "Version", PHP_IDTRANS_VERSION);
    php_info_print_table_row(2, "Author", PHP_IDTRANS_AUTHOR);
    php_info_print_table_end();
}
/* }}} */

/* {{{ proto int idtrans_encode(int) */
PHP_FUNCTION(idtrans_encode)
{	
    uint32_t v;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &v TSRMLS_CC) == FAILURE) {
        RETURN_NULL();
    }	
    RETURN_LONG(((v * IDTRANS_G(optimus).prime) & IDTRANS_G(optimus).max) ^ IDTRANS_G(optimus).random);
}
/* }}} */

/* {{{ proto int idtrans_decode(int) */
PHP_FUNCTION(idtrans_decode)
{	
    uint32_t v;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &v TSRMLS_CC) == FAILURE) {
        RETURN_NULL();
    }	
    RETURN_LONG(((v ^ IDTRANS_G(optimus).random) * IDTRANS_G(optimus).inverse) & IDTRANS_G(optimus).max);
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: et sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */