<?php
// based on methodology developed by PPK:
// http://www.quirksmode.org/blog/archives/2009/08/when_to_read_ou.html
function benchmark($times, $runner_times, $func) {
    $results = array();
    while ($times != 0){
      $results[] = runner($runner_times, $func);
      $times--;
    }
    $sum = array_sum($results);
    return $sum/count($results);
}

function runner($times, $func){
	$startTime = millitime();

    while ($times != 0){
      $func();
      $times--;
    }

	$endTime = millitime();
	return ($endTime - $startTime);	
}

function millitime() {
	return microtime(TRUE) * 1000;
}