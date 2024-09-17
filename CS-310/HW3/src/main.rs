use std::io;

// Problem 1
fn main() {
    let name = get_name();
    let (length_of_name, name) = get_length(name);
    println!("{name} is {length_of_name} characters long.")
}
fn get_name() -> String {
    println!("Please input your name.");
    let mut name: String = String::new();
    io::stdin()
        .read_line(&mut name)
        .expect("Failed to read line");
    name.trim().to_string()
}
// This function takes a String and returns one
fn get_length(string_name: String) -> (usize, String) {
    (string_name.len(), string_name)
}

// Problem 2
/*fn main() {
    let mut sentence = String::from("Why is this not working?");
    let one = first_word(&sentence);
    let r3 = &mut sentence;
    let lowered = lower(r3);
    println!("First word of sentence '{lowered}' is {one}");
}*/
fn lower(s: &str) -> String {
    s.to_lowercase()
}
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}