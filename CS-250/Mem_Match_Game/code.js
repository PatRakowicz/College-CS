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
    h3Matched = document.getElementById("matched");
    h3Missed = document.getElementById("missed");


    for (let i = 0; i < 12; i++) {
        arr[i] = document.getElementById(i);
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
let checked = [];

function select(item) {
    if (enabled) {
        item.setAttribute('src', imgArr[item.id]);
    }

    if (card[0] === -1) {
        card[0] = item.id;
    } else if (card[1] === -1 && card[0] !== item.id) {
        card[1] = item.id;
        enabled = false;
        check = true;
    }

    if (check) {
        if (imgArr[card[0]] === imgArr[card[1]]) {
            console.log("Passed")
            matched += 1;
            h3Matched.textContent = "Matched: " + matched;
            checked.push(imgArr[card[0]]);
            card = [-1, -1];
            if (matched === 6)
                setTimeout(gameWL, 300);
            enabled = true;
            check = false;

        } else {
            console.log("Failed")
            missed += 1;
            h3Missed.textContent = "Missed: " + missed;
            setTimeout(reset, 300);
            enabled = true;
            check = false;
        }
    }
}

function gameWL() {
    if (checked.length === 6 && missed < matched) {
        setTimeout(alert("Congrats You Won!"), 200)
    } else {
        setTimeout(alert("To many Loss, Game End.."), 200)
    }
}


function reset() {
    let leftCard = checked.includes(imgArr[card[0]]);
    let rightCard = checked.includes(imgArr[card[1]]);

    if (!leftCard) {
        arr[card[0]].src = "Default.jpg";
    } else {
        arr[card[0]].src = imgArr[card[0]];
    }

    if (!rightCard) {
        arr[card[1]].src = "Default.jpg";
    } else {
        arr[card[1]].src = imgArr[card[1]];
    }
    card = [-1, -1]
}

window.onload = setImg;
