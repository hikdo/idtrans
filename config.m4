dnl $Id$

PHP_ARG_ENABLE(idtrans, whether to enable idtrans support,
[  --enable-idtrans           Enable idtrans support])

if test "$PHP_idtrans" != "no"; then
  PHP_NEW_EXTENSION(idtrans, idtrans.c, $ext_shared)
fi
