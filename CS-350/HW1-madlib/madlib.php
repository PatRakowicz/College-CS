<?php
    $noun = $_POST["noun"];
    $verb = $_POST["verb"];
    $adjective = $_POST["adjective"];

    if (empty($noun) || empty($verb) || empty($adjective)) {
        echo "Please fill out all fields before submitting the form.";
    } else {
        echo "The " . $adjective . " went " . $noun . " " . $verb . " through the streets.<br>";
        echo "The " . $noun . " was " . $verb . " by the " . $adjective . " child.<br>";
        echo $verb . "ing is my favorite " . $adjective . " while pooping " . $noun . " alone.<br>";
        echo "The " . $adjective . " " . $noun . " was too hard to " . $verb . ".<br>";
        echo "I like to " . $verb . " with my " . $adjective . " " . $noun . ".";
    }
?>