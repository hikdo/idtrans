--TEST--
Check for idtrans
--SKIPIF--
<?php if (!extension_loaded("idtrans")) print "skip"; ?>
--FILE--
<?php 
$result = true;
$max = pow(2, 31)-1;
for($i=0; $i<100; $i++) {
	$id = rand(1, $max);
	$en = idtrans_encode($id);
	$de = idtrans_decode($en);
	if ($de != $id) {
		$result = false;
		break;
	}
}
var_dump($result);
?>
--EXPECT--
bool(true)