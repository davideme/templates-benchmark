<?php
require 'benchmark.php';
require 'Mustache.php';

	function test_simple() {
		$story_tmp = 'story.tpl';
	    $story_view = array(
	        'name' => 'Mustache.js', 
	        'url' => 'http://github.com/janl/mustache.js',
	        'source' => 'git://github.com/janl/mustache.js.git'    	
	    );
	    
	    $m = new Mustache();
	    $m->render(file_get_contents($story_tmp), $story_view);
	}
	
	function loop_test() {
		$comment_tmp = 'comment.tpl';		
		$comment_view = array(
	        'header' => "My Post Comments",
	        'comments' => array(
	          array('name' => "Joe", 'body' => "Thanks for this post!"),
	          array('name' => "Sam", 'body' => "Thanks for this post!"),
	          array('name' => "Heather", 'body'=> "Thanks for this post!"),
	          array('name' => "Kathy", 'body' =>"Thanks for this post!"),
	          array('name' => "George", 'body'=>"Thanks for this post!"),	        	
	        )			
		);

		$m = new Mustache();
		$m->render(file_get_contents($comment_tmp), $comment_view);
	}
	echo 'Simple Test: ', benchmark(10, 5000, 'test_simple'), PHP_EOL;
	echo 'Loop Test: ', benchmark(10, 5000, 'loop_test'), PHP_EOL;