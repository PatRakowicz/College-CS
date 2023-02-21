<!-- Display all 52 cards in a deck then print 5 random card from the array of 52 cards -->

<?php
    $suits = array('hearts','spades','clubs','diamonds');
    $ranks = array(2,3,4,5,6,7,8,9,10,'J','Q','K','A');

    $cards = array();

    foreach($suits as $suit) {
        foreach ($ranks as $rank) {
            $card = "{$rank} of {$suit}";
            $cards[] = $card;
        }
    }

    foreach ($cards as $card) {
        echo "$card<br>";
    }

    foreach ()
?>