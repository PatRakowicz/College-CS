use std::io;

// Problem 1
fn main() {
    let name = get_name();
    // get_name returns a String, ownership of the String is transferred to "name"
    // "name" now has ownership of this data, which will be passed to the next function.

    let (length_of_word, second_word) = get_second_word_and_length(name);
    // ownership of "name" is transferred to the function "get_second_word_and_length", which returns a tuple
    // After this call, "name" is no longer valid. "get_second_word_and_length" returns a tuple,
    // giving ownership of "second_word" and its length to the variables in "main".

    println!("The second word '{}' is {} characters long.", second_word, length_of_word);
    // ownership of "second_word" is passed to "println!", which consumes it.
}

// Function to get the users name (or sentence in this case)
fn get_name() -> String {
    println!("Please input your name or a sentence:");

    let mut name = String::new(); // A new empty String is created on the heap and is owned by the variable "name".
    io::stdin()
        .read_line(&mut name)
        // The "read_line" function borrows "name" mutably to modify its content.
        // Ownership of "name" does not change here, as it is only borrowed temporarily.

        .expect("Failed to read line");

    name.trim().to_string()
    // "trim" borrows the String slice to remove whitespace, and then "to_string" creates a new owned String.
    // The new String is returned, transferring ownership to the calling function ("main").
}

// Function to extract the second word and return its length and the word
fn get_second_word_and_length(sentence: String) -> (usize, String) {
    // Ownership of "sentence" is transferred to this function. "sentence" is no longer valid in "main".

    let words: Vec<&str> = sentence.split_whitespace().collect();
    // The string is borrowed temporarily to split into words, creating a vector of borrowed string slices (&str).


    if words.len() > 1 {
        let second_word = words[1].to_string();
        // A new owned String is created from the second word, transferring ownership to "second_word".

        (second_word.len(), second_word)
        // Return a tuple of the length of the second word and the word itself, transferring ownership of "second_word"
        // The length of "second_word" is calculated and the tuple (length, word) is returned.
        // Ownership of "second_word" is transferred back to "main".
    } else {
        (0, String::from("No second word"))
        // Handle the case where there is no second word, returning a default value
        // If there is no second word, we return a default owned String.
    }
}

/*------------------------------------------------------------------------------------------------*/
// Problem 2
/*fn main() {
    let mut sentence = String::from("Why is this not working?");
    let one = first_word(&sentence); // Immutable borrow happens here
    println!("First word of sentence is {one}"); // Use the immutable borrow first

    let r3 = &mut sentence; // Mutable borrow happens after the immutable borrow is done
    let lowered = lower(r3); // Now we pass the mutable reference safely
    println!("Lowered sentence is '{lowered}'");
}*/
// by moving let r3 = &mut sentence; line after the println! statement,
// the scope of the immutable borrow ends before the mutable borrow begins

fn lower(s: &str) -> String {
    s.to_lowercase()
}

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i]; // Return the first word (immutable reference)
        }
    }
    &s[..] // Return the whole string if no spaces found (immutable reference)
}