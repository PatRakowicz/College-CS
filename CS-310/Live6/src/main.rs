fn main() {
    let mut v: Vec<i32> = Vec::new();

    v.push(4);
    v.push(5);
    v.push(6);

    let v2 = vec![1, 2, 3, 4];

    // let first = v[0];
    println!("{}", v2[2]);

    let first = &v2[0];
    let second = v2.get(1);

    match second {
        Some(num) => println!("{num}"),
        None => print!("Element not found")
    }

    let first = &v[0];
    v.push(7);
    // println!("{first}");

    // iteration
    let mut v3 = vec![25, 40, 65];


    for i in &mut v3 {
        *i += 25;
    }
    for i in &v3 {
        println!("{i}");
    }

    let mut v5 = vec![1, 2, 3, 4];
    v5.retain(|value|*value < 100);

    for i in &v5 {
        println!("{i}");
    }

    let mut s1 = String::new();

    let s2 = "random text";

    let s1 = s2.to_string();
    let mut s1 = String::from(s2);
    s1.push(' ');
    s1.push_str("to print");
    let s1 = String::from("Hello, ");
    let s2 = String::from("it is me your looking for");

    // let s3 = s1 + &s2;

    // println!("{s3}");

    let s4 =  format!("{s1}{s2}");
    println!("{s4}");

    let s4 ="^&h";
    println!("{}", &s4[0..2]);
    for c in s4.chars() {
        print!("{c}");
    }
}