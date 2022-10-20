let mainArray = [
    'Red.jpg',
    'Blue.jpg',
    'Green.jpg',
    'Yellow.jpg',
    'Purple.jpg',
    'Orange.jpg',];

let arr = [];
let imgArr = [];
let imgUseCount = [0, 0, 0, 0, 0, 0];
let randInt;
let done = false;
let h3Missed, h3Matched;

function setImg() {

    for (var i = 0; i < 12; i++) {
        arr[i] = document.getElementById(i);
    }

    h3Matched = document.getElementById("matched");
    h3Missed = document.getElementById("missed");


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
let missed = 0;

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
            matched += 1;
            h3Matched.textContent = "Matched: " + matched;
            card = [-1, -1]
            console.log(matched)
            setTimeout(endGame(matched, missed), 600)
            enabled = true;
            check = false;

        } else {
            console.log("Failed")
            missed += 1;
            h3Missed.textContent = "Missed: " + missed;
            console.log(missed)
            setTimeout(reset, 300);
            enabled = true;
            check = false;

        }
    }
}


function endGame(matched, missed) {
    if (matched == 6 && matched >= missed) {
        alert("Congrats You Won!")
    } else if(missed < matched) {
        alert("TO many Loss, Game End...")
    }
}

function reset() {
    arr[card[0]].src = "Default.jpg";
    arr[card[1]].src = "Default.jpg";
    card = [-1, -1]
}

window.onload = setImg;
