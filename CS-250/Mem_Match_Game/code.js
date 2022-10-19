let mainArray = [
    'Red.jpg',
    'Blue.jpg',
    'Green.jpg',
    'Yellow.jpg',
    'Purple.jpg',
    'Orange.jpg',];

let arr = [];
let imgArr = [];
let headerArr = [];
let imgUseCount = [0, 0, 0, 0, 0, 0];
let randInt;
let done = false;

function setImg() {

    for (var i = 0; i < 12; i++) {
        arr[i] = document.getElementById(i);
    }
    console.log(arr)
    headerArr = document.getElementsByTagName('h4');

    for (var i = 0; i < 12; i++) {
        while (done == false) {
            randInt = Math.floor(Math.random() * 6);
            if (imgUseCount[randInt] < 2) {
                imgArr[i] = mainArray[randInt];
                imgUseCount[randInt]++;
                done = true;
            }
        }
        done = false;
    }
}


let card = [-1, -1];
let enabled = true;
let check = false;
let matched = 0;
let misses = 0;

function select(item) {
    if (enabled) {
        item.setAttribute('src', imgArr[item.id]);
    }

    if (card[0] == -1) {
        card[0] = item.id;
        console.log(card[0])
    } else if (card[1] == -1) {
        card[1] = item.id;
        console.log(card[1])
        enabled = false;
        check = true;
    }
    if (check) {
        if (imgArr[card[0]] === imgArr[card[1]]) {
            console.log("Passed")
            console.log(card)
            matched++;
            // TODO - innerHTML
            //  Fix Auto Header broke on innerHTML
            // headerArr[0].innerHTML = "Matches: " + matched;
            card = [-1, -1]
            console.log(card)
            if (matched == 6) {
                endGame();
            }
            enabled = true;
            check = false;
        } else {
            console.log("Failed")
            console.log(card)
            misses++;
            // TODO - innerHTML
            //  Fix Auto Header Brok on innerHTML
            // headerArr[1].innerHTML = "Missed: " + misses;
            setTimeout(reset, 300);
            enabled = true;
            check = false;
        }
    }


    console.log()
}

// TODO
//  Fix endGame
//  Make output correct if won or lost if to many tries
function endGame() {
    if (matched >= misses) {
        alert("Congrats on Winning!");
    } else {
        alert("You Failed, Try again");
    }
}

function reset() {
    arr[card[0]].src = "Default.jpg";
    arr[card[1]].src = "Default.jpg";
    card = [-1, -1]
}

window.onload = setImg;
