<?php
header('Access-Control-Allow-Origin:*');
$com = new COM("ComATL.ATLSimpleObject") or die("无法调用ComTest");
echo $com->atlsum(1, 2);