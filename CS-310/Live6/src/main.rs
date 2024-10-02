use std::collections::HashMap;

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
    v5.retain(|value| *value < 100);

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

    let s4 = format!("{s1}{s2}");
    println!("{s4}");

    let s4 = "^&h";
    println!("{}", &s4[0..2]);
    for c in s4.chars() {
        print!("{c}");
    }


    let mut scores = HashMap::new();
    scores.insert("democrats", 0.48);
    scores.insert("republican", 0.49);

    for (key, val) in &scores {
        println!("{key}");
    }

    let poll_score = scores.get("democrats").unwrap();
    println!("{poll_score}");

    let thrid = "third Party";
    let third_poll = 0.02;
    scores.insert(thrid, third_poll);

    let res = largest(&[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
    println!("{res}");

    let p = Point { x: 0, y: 0 };
    let p2 = Point { x: 40, y: 30 };
    let p3 = p.crossover(p2);
    println!({ p3: ? })
}

fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

#[derive(Debug)]
struct Point<T, U> {
    x: T,
    y: U,
}
impl<T, U> Point<T, U> {
    fn crossover<T2, U2>(self, p2: Point<T2, U2>) -> Point<T2, U2> {
        Point { x: self.x, y: p2.y }
    }
}