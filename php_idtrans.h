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

#ifndef PHP_IDTRANS_H
#define PHP_IDTRANS_H

#define PHP_IDTRANS_VERSION "1.0"
#define PHP_IDTRANS_AUTHOR "https://github.com/hikdo"

extern zend_module_entry idtrans_module_entry;
#define phpext_idtrans_ptr &idtrans_module_entry

#ifdef PHP_WIN32
#define PHP_IDTRANS_API __declspec(dllexport)
#else
#define PHP_IDTRANS_API
#endif

#ifdef ZTS
#include "TSRM.h"
#define IDTRANS_G(v) TSRMG(idtrans_globals_id, zend_idtrans_globals *, v)
#else
#define IDTRANS_G(v) (idtrans_globals.v)
#endif

typedef struct {
    uint32_t max;
    uint32_t prime;
    uint32_t inverse;
    uint32_t random;
} optimus_t;

ZEND_BEGIN_MODULE_GLOBALS(idtrans)
    optimus_t optimus;
ZEND_END_MODULE_GLOBALS(idtrans)

PHP_MINIT_FUNCTION(idtrans);
PHP_MSHUTDOWN_FUNCTION(idtrans);
PHP_MINFO_FUNCTION(idtrans);

PHP_FUNCTION(idtrans_encode);
PHP_FUNCTION(idtrans_decode);

#endif  /* PHP_IDTRANS_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: et sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
