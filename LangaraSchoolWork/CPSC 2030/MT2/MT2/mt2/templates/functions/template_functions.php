<?php

function the_inventory() {
    global $posts;

    echo "<h2>Total number of cars </h2> " . COUNT($posts);
 
}

function the_stat() {
    $price = 0;
    foreach($posts as $post){
        $price .= $post[1];
    }

    echo "<h2>Average Price : $" . $price;
} 
?>