<?php
get_details();
function get_details() 
{
 	$dbh = pg_connect("host=localhost port=5433 dbname=bheri user=postgres password=123456") or die("pg_not connect");

	if($dbh)
		print "connection success";
	else
		print "connection fail";
	
	$postData = $_REQUEST;

	$sid = isset($_REQUEST['sid'])?$_REQUEST['sid']:501;
      
	$sname = isset($_REQUEST['name'])?$_REQUEST['name']:'rama';
	
	$marks = isset($_REQUEST['marks'])?$_REQUEST['marks']:100;

	$cid = isset($_REQUEST['cid'])?$_REQUEST['cid']:1;

	echo $sql = "INSERT INTO student(sid, sname, marks,cid) VALUES ($sid,'$sname'::text,$marks,$cid)";

	$res = pg_query($dbh, $sql);
   	if(!$res)
	{
	      echo pg_last_error($dbh);
	}
	else
	{
      		echo "Records created successfully\n";
   	}
	pg_close($dbh);
}
?>
