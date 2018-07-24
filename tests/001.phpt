--TEST--
Check for idtrans presence
--SKIPIF--
<?php if (!extension_loaded("idtrans")) print "skip"; ?>
--FILE--
<?php 
echo "idtrans extension is available";
?>
--EXPECT--
idtrans extension is available