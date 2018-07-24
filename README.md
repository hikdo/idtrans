## idtrans
[![Build Status](https://travis-ci.org/hikdo/idtrans.svg?branch=master)](https://travis-ci.org/hikdo/idtrans)

An implementation of Knuth's integer hash , build in php extension.

### Install
```
$ /path/to/phpize
$ ./configure --with-php-config=/path/to/php-config
$ make && make install
```

### Ini
```
extension = idtrans.so
```

### Functions
```
1. idtrans_encode($id)
2. idtrans_decode($id)
```
