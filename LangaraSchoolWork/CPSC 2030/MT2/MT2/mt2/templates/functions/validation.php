<?php

$valid = false;

// Validate plate number
function validate()
{
    global $valid;

    if ($_SERVER['REQUEST_METHOD'] == 'POST'){

        if(preg_match('#^[a-z][a-z][a-z][0-9][0-9][0-9]$#') || preg_match('#^[a-z][a-z][0-9][0-9][0-9][a-z]$#') || preg_match('#^[0-9][0-9][0-9][a-z][a-z][a-z]$#')){
            $valid = true;
        };
    }
}

function the_validation_message($type) 
{
    $valid;
    

}
 ?>
